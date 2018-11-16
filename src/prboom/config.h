
#pragma once

#include <cstdint>
#include <cstdlib>

namespace prboom
{
typedef uint64_t uint_64_t;
typedef int64_t int_64_t;

#define PACKEDATTR
#define PUREFUNC
#define CONSTFUNC

typedef uint8_t byte;

typedef enum                /* Logical output levels */
{
	LO_INFO = 1,                /* One of these is used in each physical output    */
	LO_CONFIRM = 2,             /* call. Which are output, or echoed to console    */
	LO_WARN = 4,                /* if output redirected is determined by the       */
	LO_ERROR = 8,               /* global masks: cons_output_mask,cons_error_mask. */
	LO_FATAL = 16,
	LO_DEBUG = 32,
	LO_ALWAYS = 64,
} OutputLevels;

int M_CheckParm(const char *);
void I_vWarning(const char *message, va_list argList);
int doom_snprintf(char *buf, size_t max, const char *fmt, ...);
int lprintf(OutputLevels pri, const char *fmt, ...);
int strcasecmp(const char *, const char *);
void I_Error(const char *error, ...);

int W_LumpLength(int lump);
void W_UnlockLumpNum(int);

extern int myargc;
extern char **myargv;

}
