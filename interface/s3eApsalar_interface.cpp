/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eApsalar.h"

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       void(*s3eApStart_t)(const char* apiKey, const char* apiSecret);
typedef       void(*s3eApRestart_t)(const char* apiKey, const char* apiSecret);
typedef       bool(*s3eApStarted_t)();
typedef       void(*s3eApEnd_t)();
typedef       void(*s3eApLogEvent_t)(const char* name);
typedef s3eApDict*(*s3eApDictCreate_t)();
typedef       void(*s3eApDictAddString_t)(s3eApDict* dict, const char* key, const char* value);
typedef       void(*s3eApDictAddInt_t)(s3eApDict* dict, const char* key, int value);
typedef       void(*s3eApDictAddFloat_t)(s3eApDict* dict, const char* key, float value);
typedef       void(*s3eApDictAddDict_t)(s3eApDict* dict, const char* key, s3eApDict* value);
typedef       void(*s3eApLogEventWithArgs_t)(const char* name, s3eApDict* dict);

/**
 * struct that gets filled in by s3eApsalarRegister
 */
typedef struct s3eApsalarFuncs
{
    s3eApStart_t m_s3eApStart;
    s3eApRestart_t m_s3eApRestart;
    s3eApStarted_t m_s3eApStarted;
    s3eApEnd_t m_s3eApEnd;
    s3eApLogEvent_t m_s3eApLogEvent;
    s3eApDictCreate_t m_s3eApDictCreate;
    s3eApDictAddString_t m_s3eApDictAddString;
    s3eApDictAddInt_t m_s3eApDictAddInt;
    s3eApDictAddFloat_t m_s3eApDictAddFloat;
    s3eApDictAddDict_t m_s3eApDictAddDict;
    s3eApLogEventWithArgs_t m_s3eApLogEventWithArgs;
} s3eApsalarFuncs;

static s3eApsalarFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xa99b67b4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eApsalar");
            
        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xa99b67b4, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eApsalarAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

void s3eApStart(const char* apiKey, const char* apiSecret)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[0] func: s3eApStart"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApStart(apiKey, apiSecret);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApRestart(const char* apiKey, const char* apiSecret)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[1] func: s3eApRestart"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApRestart(apiKey, apiSecret);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

bool s3eApStarted()
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[2] func: s3eApStarted"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eApStarted();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void s3eApEnd()
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[3] func: s3eApEnd"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApEnd();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApLogEvent(const char* name)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[4] func: s3eApLogEvent"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApLogEvent(name);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

s3eApDict* s3eApDictCreate()
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[5] func: s3eApDictCreate"));

    if (!_extLoad())
        return NULL;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eApDict* ret = g_Ext.m_s3eApDictCreate();

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

void s3eApDictAddString(s3eApDict* dict, const char* key, const char* value)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[6] func: s3eApDictAddString"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApDictAddString(dict, key, value);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApDictAddInt(s3eApDict* dict, const char* key, int value)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[7] func: s3eApDictAddInt"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApDictAddInt(dict, key, value);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApDictAddFloat(s3eApDict* dict, const char* key, float value)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[8] func: s3eApDictAddFloat"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApDictAddFloat(dict, key, value);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApDictAddDict(s3eApDict* dict, const char* key, s3eApDict* value)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[9] func: s3eApDictAddDict"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApDictAddDict(dict, key, value);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}

void s3eApLogEventWithArgs(const char* name, s3eApDict* dict)
{
    IwTrace(APSALAR_VERBOSE, ("calling s3eApsalar[10] func: s3eApLogEventWithArgs"));

    if (!_extLoad())
        return;

#ifdef __mips
    // For MIPs platform we do not have asm code for stack switching 
    // implemented. So we make LoaderCallStart call manually to set GlobalLock
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    g_Ext.m_s3eApLogEventWithArgs(name, dict);

#ifdef __mips
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return;
}
