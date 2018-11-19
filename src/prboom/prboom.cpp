
#include "pr_config.h"
#include "pr_s_sound.h"
#include "pr_i_sound.h"
#include "pr_s_advsound.h"
#include "pr_lprintf.h"
#include "pr_r_main.h"
#include "pr_r_things.h"
#include "pr_r_sky.h"
#include "pr_r_draw.h"
#include "pr_r_demo.h"
#include "pr_r_fps.h"
#include "pr_e6y.h"
#include "pr_doomstat.h"
#include "pr_st_stuff.h"
#include "pr_hu_stuff.h"
#include "pr_hu_tracers.h"
#include "pr_sounds.h"
#include "pr_am_map.h"
#include "pr_wi_stuff.h"
#include "pr_f_finale.h"
#include "pr_d_main.h"
#include "pr_m_argv.h"
#include "pr_m_misc.h"
#include "pr_m_cheat.h"
#include "pr_i_system.h"

namespace prboom
{
	char *player_names[1];
	dboolean setsizeneeded;

	// m_argv.h
	int M_CheckParm(const char *check) { return 0; }
	int myargc;
	char **myargv;

	// sounds.h
	sfxinfo_t S_sfx[1];
	musicinfo_t S_music[1];

	// s_advsound.h
	void S_ParseMusInfo(const char *mapid) { }
	void MusInfoThinker(mobj_t *thing) { }
	void T_MAPMusic() { }
	musinfo_t musinfo;

	// s_sound.h
	void S_Start() { }
	void S_StartSound(void *origin, int sound_id) { }
	void S_StopSound(void* origin) { }
	void S_ChangeMusInfoMusic(int lumpnum, int looping) { }
	void S_PauseSound() { }
	void S_ResumeSound() { }
	void S_UpdateSounds(void* listener) { }
	int idmusnum;

	// i_sound.h
	int I_GetSfxLumpNum(sfxinfo_t *sfxinfo) { return 0; }

	// lprintf.h
	void I_Error(const char *error, ...) __attribute__((format(printf, 1, 2))) { }
	int doom_vsnprintf(char *buf, size_t max, const char *fmt, va_list va) { return 0; }
	int doom_snprintf(char *buf, size_t max, const char *fmt, ...) __attribute__((format(printf, 3, 4))) { return 0; }
	int lprintf(OutputLevels pri, const char *fmt, ...) __attribute__((format(printf, 2, 3))) { return 0; }

	// r_main.h
	void R_ExecuteSetViewSize() { }
	void R_InitTranslationTables() { }
	void R_FillBackScreen() { }
	int R_PointOnSide(fixed_t x, fixed_t y, const node_t *node) { return 0; }
	angle_t R_PointToAngle2(fixed_t x1, fixed_t y1, fixed_t x, fixed_t y) { return 0; }
	angle_t R_PointToAngleEx2(fixed_t x1, fixed_t y1, fixed_t x, fixed_t y) { return 0; }
	subsector_t *R_PointInSubsector(fixed_t x, fixed_t y) { return nullptr; }
	int validcount;

	// r_draw.h
	byte playernumtotrans[MAXPLAYERS];

	// r_data.h
	void R_PrecacheLevel() { }
	int R_FlatNumForName(const char* name) { return 0; }
	int R_TextureNumForName(const char *name) { return 0; }
	int R_SafeTextureNumForName(const char *name, int snum) { return 0; }
	int R_CheckTextureNumForName(const char *name) { return 0; }
	int R_ColormapNumForName(const char *name) { return 0; }

	// r_state.h
	fixed_t *textureheight;
	int numflats;
	int *flattranslation;
	int *texturetranslation;

	// r_things.h
	void R_InitSprites(const char * const * namelist) { }

	// r_sky.h
	void R_InitSkyMap() { }
	int skytexture;

	// r_demo.h
	void R_SmoothPlaying_Reset(player_t *player) { }
	void R_SmoothPlaying_Add(int delta) { }
	angle_t R_SmoothPlaying_Get(player_t *player) { return 0; }
	void R_ResetAfterTeleport(player_t *player) { }
	void G_WriteDemoFooter(FILE *file) { }
	void R_DemoEx_WriteMLook(angle_t pitch) { }
	angle_t R_DemoEx_ReadMLook() { return 0; }
	int LoadDemo(const char *name, const byte **buffer, int *length, int *lump) { return 0; }
	int demo_smoothturns;

	// r_fps.h
	void R_UpdateInterpolations() { }
	void R_StopAllInterpolations() { }
	void R_ActivateSectorInterpolations() { }
	void R_ActivateThinkerInterpolations(thinker_t *th) { }
	void R_StopInterpolationIfNeeded(thinker_t *th) { }
	int movement_smooth;

	// e6y.h
	dboolean ProcessNoTagLines(line_t* line, sector_t **sec, int *secnum) { return 0; }
	void I_vWarning(const char *message, va_list argList) { }
	void e6y_G_DoCompleted() { }
	void e6y_G_DoWorldDone() { }
	int AccelerateMouse(int val) { return 0; }
	void e6y_G_Compatibility() { }
	void G_SkipDemoStop() { }
	void G_SkipDemoCheck() { }
	dboolean GetMouseLook() { return 0; }
	void CheckPitch(signed int *pitch) { }
	dboolean zerotag_manual;
	prboom_comp_t prboom_comp[1];
	int hudadd_secretarea;
	int movement_strafe50;
	int movement_strafe50onturns;
	int movement_mouseinvert;
	int mouse_doubleclick_as_use;
	int demo_overwriteexisting;
	int demo_tics_count;
	int demo_curr_tic;
	int demo_playerscount;
	char demo_len_st[80];
	dboolean doSkip;
	dboolean demo_stoponnext;
	dboolean demo_stoponend;
	int key_demo_jointogame;
	int mouseSensitivity_mlook;
	camera_t walkcamera;
	int levelstarttic;
	int mlooky;
	dboolean transparentpresent;
	int palette_onpowers;

	// doomdef.h
	dboolean bfgedition;

	// doomstat.h
	dboolean nomonsters;
	dboolean respawnparm;
	dboolean fastparm;
	skill_t startskill;
	dboolean autostart;
	enum automapmode_e automapmode;
	enum menuactive_e menuactive;
	int viewangleoffset;
	dboolean precache;
	gamestate_t wipegamestate;
	int mouseSensitivity_horiz;
	int mouseSensitivity_vert;
	int skyflatnum;
	int maketic;
	ticcmd_t netcmds[][BACKUPTICS];
	int ticdup;

	// st_stuff.h
	void ST_Ticker() { }
	void ST_Start() { }

	// hu_tracers.h
	void CheckGivenDamageTracer(mobj_t *mobj, int damage) { }
	void CheckThingsPickupTracer(mobj_t *mobj) { }
	void CheckThingsHealthTracer(mobj_t *mobj) { }
	void CheckLinesCrossTracer(line_t *line) { }
	void ClearLinesCrossTracer() { }
	void TracerClearStarts() { }
	void TracerAddDeathmatchStart(int num, int index) { }
	void TracerAddPlayerStart(int num, int index) { }
	int TracerGetDeathmatchStart(int index) { return 0; }
	int TracerGetPlayerStart(int index) { return 0; }

	// hu_stuff.h
	void HU_Start() { }
	void HU_Ticker() { }
	char HU_dequeueChatChar() { return 0; }
	int SetCustomMessage(int plr, const char *msg, int delay, int ticks, int cm, int sfx) { return 0; }

	// w_wad.h
	#undef W_FindNumFromName
	int W_FindNumFromName(const char *name, int ns, int lump) { return 0; }
	int W_GetNumForName(const char* name) { return 0; }
	const lumpinfo_t* W_GetLumpInfoByNum(int lump) { return nullptr; }
	int W_LumpLength(int lump) { return 0; }
	void W_ReadLump(int lump, void *dest) { }
	const void* W_CacheLumpNum(int lump) { return nullptr; }
	void W_UnlockLumpNum(int lump) { }
	char *AddDefaultExtension(char *, const char *) { return nullptr; }
	wadfile_info_t *wadfiles;
	size_t numwadfiles;
	lumpinfo_t *lumpinfo;
	int numlumps;

	// am_map.h
	void AM_Ticker() { }
	void AM_Stop() { }
	void AM_Start() { }
	void AM_clearMarks() { }
	void AM_setMarkParams(int num) { }
	markpoint_t *markpoints;
	int markpointnum, markpointnum_max;
	int mapcolor_plyr[4];
	int mapcolor_me;

	// wi_stuff.h
	void WI_Ticker() { }
	void WI_Start(wbstartstruct_t *wbstartstruct) { }
	void WI_End() { }

	// f_finale.h
	dboolean F_Responder(event_t* ev) { return 0; }
	void F_Ticker() { }
	void F_StartFinale() { }

	// d_main.h
	void D_AdvanceDemo() { }
	void D_PageTicker() { }
	void D_StartTitle() { }
	char *basesavegame;
	dboolean clnomonsters;
	dboolean clrespawnparm;
	dboolean clfastparm;

	// d_net.h
	ticcmd_t netcmds[MAXPLAYERS][BACKUPTICS];

	// m_misc.h
	dboolean M_WriteFile(char const* name, const void* source, size_t length) { return 0; }
	int M_ReadFile(char const* name, byte** buffer) { return 0; }
	void M_ScreenShot(void) { }
	void M_SaveDefaults(void) { }
	int M_StrToInt(const char *s, int *l) { return 0; }
	char* M_Strlwr(char* str) { return nullptr; }

	// m_menu.h
	void M_ForcedLoadGame(const char *msg) { }

	// m_cheat.h
	cheatseq_t cheat[1];

	// i_system.h
	int I_GetTime_RealTime() { return 0; }
	unsigned long I_GetRandomTimeSeed() { return 0; }
}
