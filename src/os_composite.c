#include <stdlib.h>
#include "sqliteInt.h"

#if SQLITE_OS_COMPOSITE /* This file is used on composite only */

static int
compositeOpen(sqlite3_vfs *pVfs, const char *zPath, sqlite3_file *pFile, int flags, int *pOutFlags)
{
	assert(0);
	return 0;
}

static int
compositeDelete(sqlite3_vfs *NotUsed, const char *zPath, int dirSync)
{
	assert(0);
	return 0;
}

static int
compositeAccess(sqlite3_vfs *NotUsed, const char *zPath, int flags, int *pResOut)
{
	assert(0);
	return 0;
}

static int
compositeFullPathname(sqlite3_vfs *pVfs, const char *zPath, int nOut, char *zOut)
{
	assert(0);
	return 0;
}

static void *
compositeDlOpen(sqlite3_vfs *NotUsed, const char *zFilename)
{
	assert(0);
	return 0;
}

static void
compositeDlError(sqlite3_vfs *NotUsed, int nBuf, char *zBufOut)
{
	assert(0);
	return;
}

static void (*compositeDlSym(sqlite3_vfs *NotUsed, void *p, const char *zSym))(void)
{
	assert(0);
	return 0;
}

static void
compositeDlClose(sqlite3_vfs *NotUsed, void *pHandle)
{
	assert(0);
	return;
}

static int
compositeRandomness(sqlite3_vfs *NotUsed, int nBuf, char *zBuf)
{
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJK1234567890-=!@#$^&*()_+";

	for (size_t n = 0; n < nBuf; n++) {
		int key = rand() % (int)(sizeof(charset) - 1);
		zBuf[n] = charset[key];
	}

	return 0;
}

static int
compositeSleep(sqlite3_vfs *NotUsed, int microseconds)
{
	assert(0);
	return 0;
}

static int
compositeCurrentTime(sqlite3_vfs *NotUsed, double *prNow)
{
	assert(0);
	return 0;
}

static int
compositeGetLastError(sqlite3_vfs *NotUsed, int NotUsed2, char *NotUsed3)
{
	assert(0);
	return 0;
}

static int
compositeCurrentTimeInt64(sqlite3_vfs *NotUsed, sqlite3_int64 *piNow)
{
	assert(0);
	return 0;
}

static int
compositeSetSystemCall(sqlite3_vfs *pNotUsed, const char *zName, sqlite3_syscall_ptr pNewFunc)
{
	assert(0);
	return 0;
}

static sqlite3_syscall_ptr
compositeGetSystemCall(sqlite3_vfs *pNotUsed, const char *zName)
{
	assert(0);
	return 0;
}

static const char *
compositeNextSystemCall(sqlite3_vfs *p, const char *zName)
{
	assert(0);
	return 0;
}

SQLITE_API int
sqlite3_os_init(void)
{
	static sqlite3_vfs compositeVfs = {
	  3,                         /* iVersion */
	  0,                         /* szOsFile */
	  0,                         /* mxPathname */
	  0,                         /* pNext */
	  "composite",               /* zName */
	  0,                         /* pAppData */
	  compositeOpen,             /* xOpen */
	  compositeDelete,           /* xDelete */
	  compositeAccess,           /* xAccess */
	  compositeFullPathname,     /* xFullPathname */
	  compositeDlOpen,           /* xDlOpen */
	  compositeDlError,          /* xDlError */
	  compositeDlSym,            /* xDlSym */
	  compositeDlClose,          /* xDlClose */
	  compositeRandomness,       /* xRandomness */
	  compositeSleep,            /* xSleep */
	  compositeCurrentTime,      /* xCurrentTime */
	  compositeGetLastError,     /* xGetLastError */
	  compositeCurrentTimeInt64, /* xCurrentTimeInt64 */
	  compositeSetSystemCall,    /* xSetSystemCall */
	  compositeGetSystemCall,    /* xGetSystemCall */
	  compositeNextSystemCall,   /* xNextSystemCall */
	};

	sqlite3_vfs_register(&compositeVfs, 1);

	return SQLITE_OK;
}

SQLITE_API int
sqlite3_os_end(void)
{
	return SQLITE_OK;
}

#endif