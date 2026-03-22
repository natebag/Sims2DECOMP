// os.cpp - OS system library
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 144 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class ERC;
class EMat4;
class EVec3;
class EVec4;
class EStorable;
class FastAllocPool;
struct ImageProcessingManager;
struct AptSysClock;
struct DVDFileInfo;
struct DVDCommandBlock;
struct DVDDiskID;
struct GXColor;
struct GXTexObj;
struct GXTlutObj;
struct OSThread;
struct OSAlarm;
struct OSContext;
struct OSMutex;
struct OSMessageQueue;
struct GXRenderModeObj;
struct GXFifoObj;
struct GXLightObj;
struct PADStatus;
struct CARDFileInfo;
struct DSPTask;
class BString;
class BString2;
class EAnimNodeDataPos;
class iResFile;
struct FrameEffectsManager;
struct EAnimNote;
struct AptGetBytesEnum;
struct ObjectSaveTypeTable2;
struct ObjectSaveTypeTable3;
struct ObjectSaveIDTable;
struct UserDataSaveLoad;
struct SpriteIdToResIdNode;
class cSimulator;
class Neighbor;
class CasSimDescriptionS2C;
struct AptValue;
struct AptObject;
struct CBFunctorBase;

// OSGetConsoleType
// Address: 0x803C9C7C, Size: 40
void OSGetConsoleType() {
}

// OSInit
// Address: 0x803C9E18, Size: 1248
void OSInit() {
}

// OSExceptionInit
// Address: 0x803CA2F8, Size: 640
void OSExceptionInit() {
}

// OSExceptionVector
// Address: 0x803CA5D0, Size: 156
void OSExceptionVector() {
}

// OSDefaultExceptionHandler
// Address: 0x803CA66C, Size: 88
void OSDefaultExceptionHandler() {
}

// OSRegisterVersion
// Address: 0x803CA72C, Size: 44
void OSRegisterVersion() {
}

// OSCheckAlarmQueue
// Address: 0x803CA758, Size: 320
void OSCheckAlarmQueue() {
}

// OSInitAlarm
// Address: 0x803CA930, Size: 88
void OSInitAlarm() {
}

// OSCreateAlarm
// Address: 0x803CA988, Size: 16
void OSCreateAlarm() {
}

// OSSetAlarm
// Address: 0x803CABE8, Size: 104
void OSSetAlarm() {
}

// OSSetAbsAlarm
// Address: 0x803CAC50, Size: 112
void OSSetAbsAlarm() {
}

// OSSetPeriodicAlarm
// Address: 0x803CACC0, Size: 124
void OSSetPeriodicAlarm() {
}

// OSCancelAlarm
// Address: 0x803CAD3C, Size: 284
void OSCancelAlarm() {
}

// OSSetAlarmTag
// Address: 0x803CB0D8, Size: 8
void OSSetAlarmTag() {
}

// OSCancelAlarms
// Address: 0x803CB0E0, Size: 176
void OSCancelAlarms() {
}

// OSGetArenaHi
// Address: 0x803CB230, Size: 8
void OSGetArenaHi() {
}

// OSGetArenaLo
// Address: 0x803CB238, Size: 8
void OSGetArenaLo() {
}

// OSSetArenaHi
// Address: 0x803CB240, Size: 8
void OSSetArenaHi() {
}

// OSSetArenaLo
// Address: 0x803CB248, Size: 8
void OSSetArenaLo() {
}

// OSAllocFromArenaLo
// Address: 0x803CB250, Size: 44
void OSAllocFromArenaLo() {
}

// OSAllocFromArenaHi
// Address: 0x803CB27C, Size: 32
void OSAllocFromArenaHi() {
}

// OSLoadFPUContext
// Address: 0x803CC258, Size: 8
void OSLoadFPUContext() {
}

// OSSaveFPUContext
// Address: 0x803CC260, Size: 8
void OSSaveFPUContext() {
}

// OSSetCurrentContext
// Address: 0x803CC268, Size: 92
void OSSetCurrentContext() {
}

// OSGetCurrentContext
// Address: 0x803CC2C4, Size: 12
void OSGetCurrentContext() {
}

// OSSaveContext
// Address: 0x803CC2D0, Size: 128
void OSSaveContext() {
}

// OSLoadContext
// Address: 0x803CC350, Size: 216
void OSLoadContext() {
}

// OSGetStackPointer
// Address: 0x803CC428, Size: 8
void OSGetStackPointer() {
}

// OSSwitchStack
// Address: 0x803CC430, Size: 16
void OSSwitchStack() {
}

// OSSwitchFiber
// Address: 0x803CC440, Size: 48
void OSSwitchFiber() {
}

// OSClearContext
// Address: 0x803CC470, Size: 36
void OSClearContext() {
}

// OSInitContext
// Address: 0x803CC494, Size: 188
void OSInitContext() {
}

// OSDumpContext
// Address: 0x803CC550, Size: 680
void OSDumpContext() {
}

// OSSwitchFPUContext
// Address: 0x803CC7F8, Size: 132
void OSSwitchFPUContext() {
}

// OSFillFPUContext
// Address: 0x803CC8C4, Size: 300
void OSFillFPUContext() {
}

// OSReport
// Address: 0x803CC9F0, Size: 128
void OSReport() {
}

// OSVReport
// Address: 0x803CCA70, Size: 32
void OSVReport() {
}

// OSPanic
// Address: 0x803CCA90, Size: 300
void OSPanic() {
}

// OSSetErrorHandler
// Address: 0x803CCBBC, Size: 536
void OSSetErrorHandler() {
}

// OSExecv
// Address: 0x803CDE4C, Size: 144
void OSExecv() {
}

// OSExecl
// Address: 0x803CDEDC, Size: 324
void OSExecl() {
}

// OSDisableInterrupts
// Address: 0x803CE020, Size: 20
void OSDisableInterrupts() {
}

// OSEnableInterrupts
// Address: 0x803CE034, Size: 20
void OSEnableInterrupts() {
}

// OSRestoreInterrupts
// Address: 0x803CE048, Size: 36
void OSRestoreInterrupts() {
}

// OSGetInterruptMask
// Address: 0x803CE3E8, Size: 12
void OSGetInterruptMask() {
}

// OSSetInterruptMask
// Address: 0x803CE3F4, Size: 144
void OSSetInterruptMask() {
}

// OSNotifyLink
// Address: 0x803CE928, Size: 4
void OSNotifyLink() {
}

// OSNotifyUnlink
// Address: 0x803CE92C, Size: 4
void OSNotifyUnlink() {
}

// OSSetStringTable
// Address: 0x803CE930, Size: 12
void OSSetStringTable() {
}

// OSLink
// Address: 0x803CEED8, Size: 36
void OSLink() {
}

// OSLinkFixed
// Address: 0x803CEEFC, Size: 60
void OSLinkFixed() {
}

// OSUnlink
// Address: 0x803CF170, Size: 468
void OSUnlink() {
}

// OSSearchModule
// Address: 0x803CF35C, Size: 160
void OSSearchModule() {
}

// OSGetPhysicalMemSize
// Address: 0x803CF3FC, Size: 12
void OSGetPhysicalMemSize() {
}

// OSGetConsoleSimulatedMemSize
// Address: 0x803CF408, Size: 12
void OSGetConsoleSimulatedMemSize() {
}

// OSProtectRange
// Address: 0x803CF4BC, Size: 196
void OSProtectRange() {
}

// OSSetSaveRegion
// Address: 0x803CF820, Size: 12
void OSSetSaveRegion() {
}

// OSGetSaveRegion
// Address: 0x803CF82C, Size: 20
void OSGetSaveRegion() {
}

// OSGetSavedRegion
// Address: 0x803CF840, Size: 28
void OSGetSavedRegion() {
}

// OSRegisterResetFunction
// Address: 0x803CF85C, Size: 132
void OSRegisterResetFunction() {
}

// OSUnregisterResetFunction
// Address: 0x803CF8E0, Size: 56
void OSUnregisterResetFunction() {
}

// OSResetSystem
// Address: 0x803CFC90, Size: 512
void OSResetSystem() {
}

// OSGetResetCode
// Address: 0x803CFE90, Size: 56
void OSGetResetCode() {
}

// OSSetBootDol
// Address: 0x803CFEC8, Size: 16
void OSSetBootDol() {
}

// OSSetResetCallback
// Address: 0x803CFFCC, Size: 116
void OSSetResetCallback() {
}

// OSGetResetButtonState
// Address: 0x803D0040, Size: 664
void OSGetResetButtonState() {
}

// OSGetResetSwitchState
// Address: 0x803D02D8, Size: 32
void OSGetResetSwitchState() {
}

// OSGetSoundMode
// Address: 0x803D13C4, Size: 128
void OSGetSoundMode() {
}

// OSSetSoundMode
// Address: 0x803D1444, Size: 164
void OSSetSoundMode() {
}

// OSGetProgressiveMode
// Address: 0x803D14E8, Size: 112
void OSGetProgressiveMode() {
}

// OSSetProgressiveMode
// Address: 0x803D1558, Size: 164
void OSSetProgressiveMode() {
}

// OSGetVideoMode
// Address: 0x803D15FC, Size: 124
void OSGetVideoMode() {
}

// OSSetVideoMode
// Address: 0x803D1678, Size: 176
void OSSetVideoMode() {
}

// OSGetLanguage
// Address: 0x803D1728, Size: 108
void OSGetLanguage() {
}

// OSSetLanguage
// Address: 0x803D1794, Size: 148
void OSSetLanguage() {
}

// OSGetEuRgb60Mode
// Address: 0x803D1938, Size: 112
void OSGetEuRgb60Mode() {
}

// OSSetEuRgb60Mode
// Address: 0x803D19A8, Size: 164
void OSSetEuRgb60Mode() {
}

// OSGetWirelessID
// Address: 0x803D1A4C, Size: 132
void OSGetWirelessID() {
}

// OSSetWirelessID
// Address: 0x803D1AD0, Size: 172
void OSSetWirelessID() {
}

// OSGetGbsMode
// Address: 0x803D1B7C, Size: 112
void OSGetGbsMode() {
}

// OSSetGbsMode
// Address: 0x803D1BEC, Size: 184
void OSSetGbsMode() {
}

// OSSetSwitchThreadCallback
// Address: 0x803D1D2C, Size: 116
void OSSetSwitchThreadCallback() {
}

// OSInitThreadQueue
// Address: 0x803D1EF8, Size: 16
void OSInitThreadQueue() {
}

// OSGetCurrentThread
// Address: 0x803D1F08, Size: 12
void OSGetCurrentThread() {
}

// OSIsThreadSuspended
// Address: 0x803D1F70, Size: 28
void OSIsThreadSuspended() {
}

// OSIsThreadTerminated
// Address: 0x803D1F8C, Size: 52
void OSIsThreadTerminated() {
}

// OSDisableScheduler
// Address: 0x803D2004, Size: 64
void OSDisableScheduler() {
}

// OSEnableScheduler
// Address: 0x803D2044, Size: 64
void OSEnableScheduler() {
}

// OSYieldThread
// Address: 0x803D2674, Size: 60
void OSYieldThread() {
}

// OSCreateThread
// Address: 0x803D26B0, Size: 488
void OSCreateThread() {
}

// OSExitThread
// Address: 0x803D2898, Size: 228
void OSExitThread() {
}

// OSCancelThread
// Address: 0x803D297C, Size: 444
void OSCancelThread() {
}

// OSJoinThread
// Address: 0x803D2B38, Size: 320
void OSJoinThread() {
}

// OSDetachThread
// Address: 0x803D2C78, Size: 160
void OSDetachThread() {
}

// OSResumeThread
// Address: 0x803D2D18, Size: 648
void OSResumeThread() {
}

// OSSuspendThread
// Address: 0x803D2FA0, Size: 368
void OSSuspendThread() {
}

// OSSleepThread
// Address: 0x803D3110, Size: 236
void OSSleepThread() {
}

// OSWakeupThread
// Address: 0x803D31FC, Size: 260
void OSWakeupThread() {
}

// OSSetThreadPriority
// Address: 0x803D3300, Size: 192
void OSSetThreadPriority() {
}

// OSGetThreadPriority
// Address: 0x803D33C0, Size: 8
void OSGetThreadPriority() {
}

// OSSetIdleFunction
// Address: 0x803D33C8, Size: 144
void OSSetIdleFunction() {
}

// OSGetIdleFunction
// Address: 0x803D3458, Size: 28
void OSGetIdleFunction() {
}

// OSCheckActiveThreads
// Address: 0x803D353C, Size: 1872
void OSCheckActiveThreads() {
}

// OSClearStack
// Address: 0x803D3C8C, Size: 172
void OSClearStack() {
}

// OSSetThreadSpecific
// Address: 0x803D3D38, Size: 48
void OSSetThreadSpecific() {
}

// OSGetThreadSpecific
// Address: 0x803D3D68, Size: 56
void OSGetThreadSpecific() {
}

// OSGetTime
// Address: 0x803D3DA0, Size: 24
void OSGetTime() {
}

// OSGetTick
// Address: 0x803D3DB8, Size: 8
void OSGetTick() {
}

// OSTicksToCalendarTime
// Address: 0x803D4238, Size: 516
void OSTicksToCalendarTime() {
}

// OSCalendarTimeToTicks
// Address: 0x803D443C, Size: 736
void OSCalendarTimeToTicks() {
}

// OSInitMutex
// Address: 0x803D4878, Size: 56
void OSInitMutex() {
}

// OSLockMutex
// Address: 0x803D48B0, Size: 220
void OSLockMutex() {
}

// OSUnlockMutex
// Address: 0x803D498C, Size: 200
void OSUnlockMutex() {
}

// OSTryLockMutex
// Address: 0x803D4AC4, Size: 188
void OSTryLockMutex() {
}

// OSInitCond
// Address: 0x803D4B80, Size: 32
void OSInitCond() {
}

// OSWaitCond
// Address: 0x803D4BA0, Size: 212
void OSWaitCond() {
}

// OSSignalCond
// Address: 0x803D4C74, Size: 32
void OSSignalCond() {
}

// OSFatal
// Address: 0x80549380, Size: 472
void OSFatal() {
}

// OSGetFontEncode
// Address: 0x80549EEC, Size: 100
void OSGetFontEncode() {
}

// OSSetFontEncode
// Address: 0x80549F50, Size: 152
void OSSetFontEncode() {
}

// OSLoadFont
// Address: 0x8054A398, Size: 320
void OSLoadFont() {
}

// OSGetFontTexel
// Address: 0x8054A810, Size: 672
void OSGetFontTexel() {
}

// OSInitFont
// Address: 0x8054AE5C, Size: 524
void OSInitFont() {
}

// OSGetFontTexture
// Address: 0x8054B068, Size: 368
void OSGetFontTexture() {
}

// OSGetFontWidth
// Address: 0x8054B1D8, Size: 212
void OSGetFontWidth() {
}

// OSSetFontWidth
// Address: 0x8054B2AC, Size: 16
void OSSetFontWidth() {
}

// OSInitMessageQueue
// Address: 0x8054B2BC, Size: 96
void OSInitMessageQueue() {
}

// OSSendMessage
// Address: 0x8054B31C, Size: 200
void OSSendMessage() {
}

// OSReceiveMessage
// Address: 0x8054B3E4, Size: 220
void OSReceiveMessage() {
}

// OSJamMessage
// Address: 0x8054B4C0, Size: 212
void OSJamMessage() {
}

// OSInitSemaphore
// Address: 0x8054B594, Size: 88
void OSInitSemaphore() {
}

// OSWaitSemaphore
// Address: 0x8054B5EC, Size: 112
void OSWaitSemaphore() {
}

// OSTryWaitSemaphore
// Address: 0x8054B65C, Size: 84
void OSTryWaitSemaphore() {
}

// OSSignalSemaphore
// Address: 0x8054B6B0, Size: 96
void OSSignalSemaphore() {
}

// OSGetSemaphoreCount
// Address: 0x8054B710, Size: 8
void OSGetSemaphoreCount() {
}

// OSUTF8to32
// Address: 0x8054B718, Size: 276
void OSUTF8to32() {
}

// OSUTF32to8
// Address: 0x8054B82C, Size: 212
void OSUTF32to8() {
}

// OSUTF16to32
// Address: 0x8054B900, Size: 116
void OSUTF16to32() {
}

// OSUTF32to16
// Address: 0x8054B974, Size: 120
void OSUTF32to16() {
}

// OSUTF32toANSI
// Address: 0x8054B9EC, Size: 284
void OSUTF32toANSI() {
}

// OSANSItoUTF32
// Address: 0x8054BB08, Size: 52
void OSANSItoUTF32() {
}

// OSUTF32toSJIS
// Address: 0x8054BB3C, Size: 68
void OSUTF32toSJIS() {
}

// OSSJIStoUTF32
// Address: 0x8054BB80, Size: 52
void OSSJIStoUTF32() {
}

// OSExceptionTable
// Address: 0x8078FD5C, Size: 4
void OSExceptionTable() {
}
