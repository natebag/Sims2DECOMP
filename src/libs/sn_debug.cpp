// sn_debug.cpp - SN Systems debug/profiling
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 51 functions
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

// DBcallback
// Address: 0x803BB588, Size: 0
void DBcallback() {
}

// EnableMetroTRKInterrupts
// Address: 0x803BB678, Size: 0
void EnableMetroTRKInterrupts() {
}

// SNDebugInit
// Address: 0x803BB6DC, Size: 0
void SNDebugInit() {
}

// SNDebugBoot
// Address: 0x803BB92C, Size: 0
void SNDebugBoot() {
}

// cmdNop
// Address: 0x803BBA54, Size: 0
void cmdNop() {
}

// cmdRecvMem
// Address: 0x803BBB28, Size: 0
void cmdRecvMem() {
}

// cmdSendMem
// Address: 0x803BBBC4, Size: 0
void cmdSendMem() {
}

// cmdReset
// Address: 0x803BBEC4, Size: 0
void cmdReset() {
}

// cmdGo
// Address: 0x803BC094, Size: 0
void cmdGo() {
}

// proviewtty
// Address: 0x803BC248, Size: 0
void proviewtty() {
}

// snIsSNTDEV
// Address: 0x803BCF34, Size: 0
void snIsSNTDEV() {
}

// snFileserver
// Address: 0x803BD570, Size: 0
void snFileserver() {
}

// snInitFileserver
// Address: 0x803BD770, Size: 0
void snInitFileserver() {
}

// SNInitComm
// Address: 0x803BD8C0, Size: 0
void SNInitComm() {
}

// SNInitInterrupts
// Address: 0x803BDA14, Size: 0
void SNInitInterrupts() {
}

// SNQueryData
// Address: 0x803BDA5C, Size: 0
void SNQueryData() {
}

// SNRead
// Address: 0x803BDAE4, Size: 0
void SNRead() {
}

// SNWrite
// Address: 0x803BDCA0, Size: 0
void SNWrite() {
}

// SNOpen
// Address: 0x803BDE38, Size: 0
void SNOpen() {
}

// SNClose
// Address: 0x803BDE3C, Size: 0
void SNClose() {
}

// SNHandler
// Address: 0x803BDE40, Size: 0
void SNHandler() {
}

// SNSelect
// Address: 0x803BDE94, Size: 0
void SNSelect() {
}

// SNDeselect
// Address: 0x803BDEAC, Size: 0
void SNDeselect() {
}

// SNWiggleSelect
// Address: 0x803BDEC0, Size: 0
void SNWiggleSelect() {
}

// SNSync
// Address: 0x803BDEE8, Size: 0
void SNSync() {
}

// SNRead8
// Address: 0x803BDEFC, Size: 0
void SNRead8() {
}

// SNWrite8
// Address: 0x803BDF3C, Size: 0
void SNWrite8() {
}

// SNRead32
// Address: 0x803BDF70, Size: 0
void SNRead32() {
}

// SNWrite32
// Address: 0x803BDFAC, Size: 0
void SNWrite32() {
}

// SNDVDRead_init
// Address: 0x803BDFDC, Size: 0
void SNDVDRead_init() {
}

// SNDVDReadAsync_next
// Address: 0x803BE02C, Size: 0
void SNDVDReadAsync_next() {
}

// SNDVDReadSync_next
// Address: 0x803BE09C, Size: 0
void SNDVDReadSync_next() {
}

// SNDVDWrite_init
// Address: 0x803BE104, Size: 0
void SNDVDWrite_init() {
}

// SNDVDWriteAsync_next
// Address: 0x803BE168, Size: 0
void SNDVDWriteAsync_next() {
}

// SNDVDWriteSync_next
// Address: 0x803BE1D8, Size: 0
void SNDVDWriteSync_next() {
}

// SNDVDWriteNoDMA_next
// Address: 0x803BE240, Size: 0
void SNDVDWriteNoDMA_next() {
}

// SNInitEXI2TCHandler
// Address: 0x803BEC08, Size: 112
void SNInitEXI2TCHandler() {
}

// SNDVDEmuInit
// Address: 0x803BF164, Size: 32
void SNDVDEmuInit() {
}

// SNDVDEmuInitDSIHandler
// Address: 0x803BF184, Size: 124
void SNDVDEmuInitDSIHandler() {
}

// SNDVDEmuControl
// Address: 0x803BF200, Size: 188
void SNDVDEmuControl() {
}

// sn_floor
// Address: 0x803C5950, Size: 372
void sn_floor() {
}

// sn_fmod
// Address: 0x803C5AC4, Size: 860
void sn_fmod() {
}

// sn_log
// Address: 0x803C5E20, Size: 764
void sn_log() {
}

// sn_log10
// Address: 0x803C611C, Size: 328
void sn_log10() {
}

// snstd
// Address: 0x803C6B98, Size: 92
void snstd() {
}

// snProfInit
// Address: 0x80542BC0, Size: 0
void snProfInit() {
}

// snProfile
// Address: 0x80542CA4, Size: 0
void snProfile() {
}

// snProfSetRange
// Address: 0x80542D38, Size: 0
void snProfSetRange() {
}

// snProfSetFlagValue
// Address: 0x80542D50, Size: 0
void snProfSetFlagValue() {
}

// snProfSetFlags
// Address: 0x80542D60, Size: 0
void snProfSetFlags() {
}

// snProfClrFlags
// Address: 0x80542D78, Size: 0
void snProfClrFlags() {
}
