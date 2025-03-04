#ifndef INCLUDE_PLINFO_H
#define INCLUDE_PLINFO_H

// Flags for plugin to indicate when it can be be loaded/unloaded.
// NOTE: order is crucial, as greater/less comparisons are made.
typedef enum
{
	PT_NEVER = 0,
	PT_STARTUP,			// should only be loaded/unloaded at initial hlds execution
	PT_CHANGELEVEL,		// can be loaded/unloaded between maps
	PT_ANYTIME,			// can be loaded/unloaded at any time
	PT_ANYPAUSE,		// can be loaded/unloaded at any time, and can be "paused" during a map
} PLUG_LOADTIME;

// Flags to indicate why the plugin is being unloaded.
typedef enum {
	PNL_NULL = 0,
	PNL_INI_DELETED,		// was deleted from plugins.ini
	PNL_FILE_NEWER,			// file on disk is newer than last load
	PNL_COMMAND,			// requested by server/console command
	PNL_CMD_FORCED,			// forced by server/console command
	PNL_DELAYED,			// delayed from previous request; can't tell origin
//only used for 'real_reason' on MPlugin::unload()
	PNL_PLUGIN,			// requested by plugin function call
	PNL_PLG_FORCED,			// forced by plugin function call
//only used internally for 'meta reload'
	PNL_RELOAD,			// forced unload by reload()
} PL_UNLOAD_REASON;

// Information plugin provides about itself.
typedef struct {
	const char *ifvers;			// meta_interface version
	const char *name;			// full name of plugin
	const char *version;		// version
	const char *date;			// date
	const char *author;			// author name/email
	const char *url;			// URL
	const char *logtag;			// log message prefix (unused right now)
	PLUG_LOADTIME loadable;		// when loadable
	PLUG_LOADTIME unloadable;	// when unloadable
} plugin_info_t;

typedef plugin_info_t* plid_t;

#endif
