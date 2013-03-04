/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_APSALAR_H
#define S3E_EXT_APSALAR_H

#include "s3eTypes.h"

typedef enum {
    s3eApTriggerResultSuccess,        // An overlay was loaded
    s3eApTriggerResultNotShown,       // Overlay not shown, unknown reason
    s3eApTriggerResultNotReady,       // Apsalar session not started
    s3eApTriggerResultNoConnectivity, // No connectivity needed to do overlay
    s3eApTriggerResultNoRule,         // No rules connected to this trigger 
    s3eApTriggerResultUnknown,        // New trigger, not yet registered
    s3eApTriggerResultCurrentlyActive // A trigger is already active
} s3eApTriggerResult;
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the Apsalar extension is available.
 */
s3eBool s3eApsalarAvailable();

/**
 * Start an apsalar session using apiKey and apiSecret
 */
void s3eApStart(const char *apiKey, const char *apiSecret);

void s3eApRestart(const char *apiKey, const char *apiSecret);

bool s3eApStarted();

void s3eApEnd();

void s3eApLogEvent(const char *name);

S3E_END_C_DECL

#endif /* !S3E_EXT_APSALAR_H */
