
#include "config.h"
#include "r_state.h"
#include "r_main.h"
#include "r_fps.h"
#include "d_player.h"
#include "m_random.h"
#include "doomstat.h"
#include "e6y.h"
#include "g_game.h"

namespace prboom
{
	int M_CheckParm(const char *check) { return 0; }
	void I_vWarning(const char *message, va_list argList) { }
	int doom_snprintf(char *buf, size_t max, const char *fmt, ...) { return 0; }
	int lprintf(OutputLevels pri, const char *fmt, ...) { return 0; }
	void I_Error(const char *error, ...) { }
	int W_LumpLength(int lump) { return 0; }
	void W_UnlockLumpNum(int) { }
	int M_StrToInt(const char *s, int *l) { return 0; }
	void S_StartSound(void *, int) { }
	bool ProcessNoTagLines(struct line_s *, struct sector_t * *, int *) { return false; }
	int P_Random(pr_class_t DA(const char *, int)) { return 0; }

	angle_t R_PointToAngle2(fixed_t x1, fixed_t y1, fixed_t x, fixed_t y) { return 0; }
	subsector_t *R_PointInSubsector(fixed_t x, fixed_t y) { return nullptr; }

	void InitTracers() { }
	void CheckGivenDamageTracer(mobj_t *mobj, int damage) { }
	void CheckThingsPickupTracer(mobj_t *mobj) { }
	void CheckThingsHealthTracer(mobj_t *mobj) { }
	void CheckLinesCrossTracer(line_t *line) { }
	void ClearLinesCrossTracer(void) { }
	void TracerClearStarts(void) { }
	void TracerAddDeathmatchStart(int num, int index) { }
	void TracerAddPlayerStart(int num, int index) { }
	int TracerGetDeathmatchStart(int index) { return 0; }
	int TracerGetPlayerStart(int index) { return 0; }

	int myargc;
	char **myargv;

	prboom_comp_t prboom_comp[1];

	// d_items.h
	weaponinfo_t weaponinfo[NUMWEAPONS + 2];
	int ammopershot[NUMWEAPONS + 2];

	// tables.h
	fixed_t finesine[5 * FINEANGLES / 4];
	fixed_t finetangent[FINEANGLES / 2];
	angle_t tantoangle[SLOPERANGE + 1];

	// doomstat.h
	dboolean nomonsters; // checkparm of -nomonsters
	dboolean respawnparm;  // checkparm of -respawn
	dboolean fastparm; // checkparm of -fast
	dboolean devparm;  // DEBUG: launched with -devparm
	GameMode_t gamemode;
	GameMission_t  gamemission;
	const char *doomverstr;
	dboolean modifiedgame;
	complevel_t compatibility_level, default_compatibility_level;
	int pitched_sounds;        // killough
	int     default_translucency; // config file says           // phares
	dboolean general_translucency; // true if translucency is ok // phares
	int demo_insurance, default_demo_insurance;      // killough 4/5/98
	int comp[COMP_TOTAL], default_comp[COMP_TOTAL], default_comperr[COMPERR_NUM];
	Language_t   language;
	skill_t   startskill;
	int             startepisode;
	int   startmap;
	dboolean   autostart;
	skill_t         gameskill;
	int   gameepisode;
	int   gamemap;
	dboolean         respawnmonsters;
	dboolean netgame;
	dboolean deathmatch;
	int snd_SfxVolume;      // maximum volume for sound
	int snd_MusicVolume;    // maximum volume for music
	unsigned int desired_screenwidth, desired_screenheight;
	enum automapmode_e automapmode; // Mode that the automap is in
	enum menuactive_e menuactive; // Type of menu overlaid, if any
	dboolean paused;        // Game Pause?
	dboolean nodrawers;
	dboolean noblit;
	int viewangleoffset;
	int consoleplayer;
	int displayplayer;
	int totalkills, totallive;
	int totalitems;
	int totalsecret;
	int show_alive;
	int basetic;    /* killough 9/29/98: levelstarttic, adjusted */
	int leveltime;  // tics in game play for par
	dboolean usergame;
	dboolean demoplayback;
	dboolean demorecording;
	int demover;
	dboolean   singledemo;
	dboolean   timingdemo;
	dboolean   fastdemo;
	gamestate_t  gamestate;
	int   gametic;
	dboolean realframe;
	player_t  players[MAXPLAYERS];
	int       upmove;
	dboolean   playeringame[MAXPLAYERS];
	dboolean   realplayeringame[MAXPLAYERS];
	mapthing_t *deathmatchstarts;     // killough
	size_t     num_deathmatchstarts; // killough
	mapthing_t *deathmatch_p;
	mapthing_t playerstarts[1];
	wbstartstruct_t wminfo;
	FILE   *debugfile;
	dboolean precache;
	gamestate_t     wipegamestate;
	int             mouseSensitivity_horiz; // killough
	int             mouseSensitivity_vert;
	dboolean         singletics;
	int             bodyqueslot;
	int    skyflatnum;
	int        maketic;
	ticcmd_t   netcmds[1][BACKUPTICS];
	int        ticdup;
	int allow_pushers;         // MT_PUSH Things    // phares 3/10/98
	int default_allow_pushers;
	int variable_friction;  // ice & mud            // phares 3/10/98
	int default_variable_friction;
	int monsters_remember;                          // killough 3/1/98
	int default_monsters_remember;
	int weapon_recoil;          // weapon recoil    // phares
	int default_weapon_recoil;
	int player_bobbing;  // whether player bobs or not   // phares 2/25/98
	int default_player_bobbing;  // killough 3/1/98: make local to each game
	int distfriend, default_distfriend;
	int monster_backing, default_monster_backing;
	int monster_avoid_hazards, default_monster_avoid_hazards;
	int monster_friction, default_monster_friction;
	int help_friends, default_help_friends;
	int flashing_hom; // killough 10/98
	int doom_weapon_toggles;   // killough 10/98
	int monster_infighting, default_monster_infighting;
	int monkeys, default_monkeys;
	int HelperThing;          // type of thing to use for helper
	dboolean forceOldBsp;

	// r_state.h
	fixed_t *textureheight;
	int scaledviewwidth;
	int firstflat, numflats;
	int *flattranslation;
	int *texturetranslation;
	int firstspritelump;
	int lastspritelump;
	int numspritelumps;
	int              numsprites;
	spritedef_t      *sprites;
	int              numvertexes;
	vertex_t         *vertexes;
	int              numsegs;
	seg_t            *segs;
	int              numsectors;
	//sector_t         *sectors;
	int              numsubsectors;
	subsector_t      *subsectors;
	int              numnodes;
	node_t           *nodes;
	int              numlines;
	line_t           *lines;
	int              numsides;
	side_t           *sides;
	int              *sslines_indexes;
	ssline_t         *sslines;
	byte             *map_subsectors;
	fixed_t          viewx;
	fixed_t          viewy;
	fixed_t          viewz;
	angle_t          viewangle;
	player_t         *viewplayer;
	angle_t          clipangle;
	int              viewangletox[FINEANGLES / 2];
	angle_t          *xtoviewangle;  // killough 2/8/98
	int              FieldOfView;
	fixed_t          rw_distance;
	angle_t          rw_normalangle;
	int              rw_angle1;
	visplane_t       *floorplane;
	visplane_t       *ceilingplane;

	// g_game.h
	dboolean democontinue;
	char democontinuename[];
	int  key_right;
	int  key_left;
	int  key_up;
	int  key_down;
	int  key_mlook;
	int  key_menu_right;                                  // phares 3/7/98
	int  key_menu_left;                                   //     |
	int  key_menu_up;                                     //     V
	int  key_menu_down;
	int  key_menu_backspace;                              //     ^
	int  key_menu_escape;                                 //     |
	int  key_menu_enter;                                  // phares 3/7/98
	int  key_strafeleft;
	int  key_straferight;
	int  key_flyup;
	int  key_flydown;
	int  key_fire;
	int  key_use;
	int  key_strafe;
	int  key_speed;
	int  key_escape;                                             // phares
	int  key_savegame;                                           //    |
	int  key_loadgame;                                           //    V
	int  key_autorun;
	int  key_reverse;
	int  key_zoomin;
	int  key_zoomout;
	int  key_chat;
	int  key_backspace;
	int  key_enter;
	int  key_help;
	int  key_soundvolume;
	int  key_hud;
	int  key_quicksave;
	int  key_endgame;
	int  key_messages;
	int  key_quickload;
	int  key_quit;
	int  key_gamma;
	int  key_spy;
	int  key_pause;
	int  key_setup;
	int  key_forward;
	int  key_leftturn;
	int  key_rightturn;
	int  key_backward;
	int  key_weapontoggle;
	int  key_weapon1;
	int  key_weapon2;
	int  key_weapon3;
	int  key_weapon4;
	int  key_weapon5;
	int  key_weapon6;
	int  key_weapon7;
	int  key_weapon8;
	int  key_weapon9;
	int  key_nextweapon;
	int  key_prevweapon;
	int  destination_keys[MAXPLAYERS];
	int  key_map_right;
	int  key_map_left;
	int  key_map_up;
	int  key_map_down;
	int  key_map_zoomin;
	int  key_map_zoomout;
	int  key_map;
	int  key_map_gobig;
	int  key_map_follow;
	int  key_map_mark;                                           //    ^
	int  key_map_clear;                                          //    |
	int  key_map_grid;                                           // phares
	int  key_map_rotate; // cph - map rotation
	int  key_map_overlay;// cph - map overlay
	int  key_map_textured;  //e6y: textured automap
	int  key_screenshot;    // killough 2/22/98 -- add key for screenshot
	int  autorun;           // always running?                   // phares
	int  mousebfire;
	int  mousebstrafe;
	int  mousebforward;
	int  mousebbackward;
	int  mousebuse;
	int  joybfire;
	int  joybstrafe;
	int  joybstrafeleft;
	int  joybstraferight;
	int  joybuse;
	int  joybspeed;
	int  defaultskill;      //jff 3/24/98 default skill
	dboolean haswolflevels;  //jff 4/18/98 wolf levels present
	int  bodyquesize;       // killough 2/8/98: adustable corpse limit
	int pars[5][10];  // hardcoded array size
	int cpars[];      // hardcoded array size
	char savedescription[SAVEDESCLEN];  // Description to save in savegame
	const char * comp_lev_str[];
	int shorttics;
	int longtics;
	int bytes_per_tic;

	// r_main.h
	int r_frame_count;
	fixed_t  viewcos;
	fixed_t  viewsin;
	int      viewwidth;
	int      viewheight;
	int      viewwindowx;
	int      viewwindowy;
	int      centerx;
	int      centery;
	fixed_t  centerxfrac;
	fixed_t  centeryfrac;
	fixed_t  yaspectmul;
	fixed_t  viewheightfrac; //e6y: for correct cliping of things
	fixed_t  projection;
	fixed_t  skyiscale;
	int wide_centerx;
	int wide_offsetx;
	int wide_offset2x;
	int wide_offsety;
	int wide_offset2y;
	fixed_t  projectiony;
	int      validcount;
	fixed_t viewfocratio;
	int rendered_visplanes, rendered_segs, rendered_vissprites;
	dboolean rendering_stats;
	int LIGHTSEGSHIFT;
	int LIGHTBRIGHT;
	int LIGHTLEVELS;
	int render_doom_lightmaps;
	int fake_contrast;
	const lighttable_t *(*scalelight)[MAXLIGHTSCALE];
	const lighttable_t *(*c_zlight)[LIGHTLEVELS_MAX][MAXLIGHTZ];
	const lighttable_t *(*zlight)[MAXLIGHTZ];
	const lighttable_t *fullcolormap;
	int numcolormaps;    // killough 4/4/98: dynamic number of maps
	const lighttable_t **colormaps;
	dboolean use_boom_cm;
	int boom_cm;         // current colormap
	int frame_fixedcolormap;
	int          extralight;
	const lighttable_t *fixedcolormap;

	// r_demo.h
	int demo_smoothturns;
	int demo_smoothturnsfactor;
	int demo_extendedformat;
	int demo_extendedformat_default;
	const char *demo_demoex_filename;
	int demo_patterns_count;
	const char *demo_patterns_mask;
	char **demo_patterns_list;
	const char *demo_patterns_list_def[1];
	const char *getwad_cmdline;

	// r_fps.h
	int movement_smooth_default;
	int movement_smooth;
	int interpolation_maxobjects;
	tic_vars_t tic_vars;
	dboolean WasRenderedInTryRunTics;

	// e6y.h
	int mlooky;
	int palette_ondamage;
	int palette_onbonus;
	int palette_onpowers;

	// p_setup.h
	const byte *rejectmatrix;   /* for fast sight rejection -  cph - const* */
	int      *blockmaplump;   /* offsets in blockmap are from here */
	int      *blockmap;
	int      bmapwidth;
	int      bmapheight;      /* in mapblocks */
	fixed_t  bmaporgx;
	fixed_t  bmaporgy;        /* origin of block map */
	mobj_t   **blocklinks;    /* for thing chains */
	int blockmapxneg;
	int blockmapyneg;


	int viewpitchoffset;

	state_t states[NUMSTATES];
	const char *sprnames[1];

	dboolean zerotag_manual;
}
