/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "IwDebug.h"
#include "s3eApsalar_autodefs.h"
#include "s3eEdk.h"
#include "s3eApsalar.h"
//Declarations of Init and Term functions
extern s3eResult s3eApsalarInit();
extern void s3eApsalarTerminate();


// On platforms that use a seperate UI/OS thread we can autowrap functions
// here.   Note that we can't use the S3E_USE_OS_THREAD define since this
// code is oftern build standalone, outside the main loader build.
#if defined I3D_OS_IPHONE || defined I3D_OS_OSX || defined I3D_OS_LINUX || defined I3D_OS_WINDOWS

static bool s3eApStarted_wrap()
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar func on main thread: s3eApStarted"));
    return (bool)(intptr_t)s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eApStarted, 0);
}

static void s3eApEnd_wrap()
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar func on main thread: s3eApEnd"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eApEnd, 0);
}

static void s3eApLogEvent_wrap(const char* name)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar func on main thread: s3eApLogEvent"));
    s3eEdkThreadRunOnOS((s3eEdkThreadFunc)s3eApLogEvent, 1, name);
}

#define s3eApStarted s3eApStarted_wrap
#define s3eApEnd s3eApEnd_wrap
#define s3eApLogEvent s3eApLogEvent_wrap

#endif

void s3eApsalarRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[5];
    funcPtrs[0] = (void*)s3eApStart;
    funcPtrs[1] = (void*)s3eApRestart;
    funcPtrs[2] = (void*)s3eApStarted;
    funcPtrs[3] = (void*)s3eApEnd;
    funcPtrs[4] = (void*)s3eApLogEvent;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[5] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("s3eApsalar", funcPtrs, sizeof(funcPtrs), flags, s3eApsalarInit, s3eApsalarTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int s3eApsalarStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&s3eApsalarRegisterExt;
    return 0;
}

int g_s3eApsalarVal = s3eApsalarStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    s3eApsalarRegisterExt();
}
#endif

#endif
