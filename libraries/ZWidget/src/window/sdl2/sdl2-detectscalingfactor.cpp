#include <iostream>
#include <cstdlib>
#include <string>

#ifdef __has_include
	#if __has_include(<gtk/gtk.h>)
		#include <gtk/gtk.h>
		#define HAS_GTK 1
	#endif
	#if __has_include(<QApplication>)
		#include <QApplication>
		#include <QScreen>
		#define HAS_QT 1
	#endif
#endif

double get_scaling_factor()
{
	const char* desktop_session = std::getenv("DESKTOP_SESSION");
	const char* xdg_session_type = std::getenv("XDG_SESSION_TYPE");

	// Check if we're in a Wayland session
	bool is_wayland = (xdg_session_type && std::string(xdg_session_type) == "wayland");

	#ifdef HAS_GTK
	if (desktop_session && (
		std::string(desktop_session).find("gnome") != std::string::npos ||
		std::string(desktop_session).find("unity") != std::string::npos ||
		std::string(desktop_session).find("cinnamon") != std::string::npos ||
		std::string(desktop_session).find("mate") != std::string::npos
	))
	{
		gtk_init(nullptr, nullptr);
		GtkSettings* settings = gtk_settings_get_default();
		int dpi;
		g_object_get(settings, "gtk-xft-dpi", &dpi, NULL);
		return dpi / 96.0 / 1024.0;  // GTK stores DPI * 1024
	}
	#endif

	#ifdef HAS_QT
	if (desktop_session && (
		std::string(desktop_session).find("kde") != std::string::npos ||
		std::string(desktop_session).find("lxqt") != std::string::npos
	))
	{
		int argc = 0;
		char** argv = nullptr;
		QApplication app(argc, argv);
		QScreen* screen = QGuiApplication::primaryScreen();
		return screen->logicalDotsPerInch() / 96.0;
	}
	#endif

	// Fallback method for other environments or if libraries are not available
	if (is_wayland)
	{
		// Wayland often uses integer scaling
		const char* scale = std::getenv("SCALE");
		if (scale)
		{
			return std::stod(scale);
		}
	}

	// Check for X11 scaling
	const char* scale_factor = std::getenv("GDK_SCALE");
	if (scale_factor)
	{
		return std::stod(scale_factor);
	}

	// Default to no scaling if we couldn't detect anything
	return 1.0;
}
