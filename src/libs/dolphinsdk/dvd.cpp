// dvd.cpp - DVD file system
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 79 functions
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

// DVDConvertPathToEntrynum
// Address: 0x803D9C40, Size: 756
void DVDConvertPathToEntrynum() {
}

// DVDFastOpen
// Address: 0x803D9F34, Size: 116
void DVDFastOpen() {
}

// DVDOpen
// Address: 0x803D9FA8, Size: 200
void DVDOpen() {
}

// DVDClose
// Address: 0x803DA070, Size: 36
void DVDClose() {
}

// DVDConvertEntrynumToPath
// Address: 0x803DA22C, Size: 340
void DVDConvertEntrynumToPath() {
}

// DVDGetCurrentDir
// Address: 0x803DA380, Size: 196
void DVDGetCurrentDir() {
}

// DVDChangeDir
// Address: 0x803DA444, Size: 96
void DVDChangeDir() {
}

// DVDReadAsyncPrio
// Address: 0x803DA4A4, Size: 192
void DVDReadAsyncPrio() {
}

// DVDReadPrio
// Address: 0x803DA594, Size: 280
void DVDReadPrio() {
}

// DVDSeekAsyncPrio
// Address: 0x803DA6D0, Size: 152
void DVDSeekAsyncPrio() {
}

// DVDSeekPrio
// Address: 0x803DA798, Size: 172
void DVDSeekPrio() {
}

// DVDGetFileInfoStatus
// Address: 0x803DA868, Size: 32
void DVDGetFileInfoStatus() {
}

// DVDFastOpenDir
// Address: 0x803DA888, Size: 104
void DVDFastOpenDir() {
}

// DVDOpenDir
// Address: 0x803DA8F0, Size: 192
void DVDOpenDir() {
}

// DVDReadDir
// Address: 0x803DA9B0, Size: 164
void DVDReadDir() {
}

// DVDCloseDir
// Address: 0x803DAA54, Size: 8
void DVDCloseDir() {
}

// DVDRewindDir
// Address: 0x803DAA5C, Size: 16
void DVDRewindDir() {
}

// DVDGetFSTLocation
// Address: 0x803DAA6C, Size: 12
void DVDGetFSTLocation() {
}

// DVDPrepareStreamAsync
// Address: 0x803DAA78, Size: 236
void DVDPrepareStreamAsync() {
}

// DVDPrepareStream
// Address: 0x803DAB94, Size: 324
void DVDPrepareStream() {
}

// DVDGetTransferredSize
// Address: 0x803DACFC, Size: 108
void DVDGetTransferredSize() {
}

// DVDInit
// Address: 0x803DAD74, Size: 216
void DVDInit() {
}

// DVDReadAbsAsyncPrio
// Address: 0x803DCC1C, Size: 220
void DVDReadAbsAsyncPrio() {
}

// DVDSeekAbsAsyncPrio
// Address: 0x803DCCF8, Size: 204
void DVDSeekAbsAsyncPrio() {
}

// DVDReadAbsAsyncForBS
// Address: 0x803DCDC4, Size: 208
void DVDReadAbsAsyncForBS() {
}

// DVDReadDiskID
// Address: 0x803DCE94, Size: 212
void DVDReadDiskID() {
}

// DVDPrepareStreamAbsAsync
// Address: 0x803DCF68, Size: 196
void DVDPrepareStreamAbsAsync() {
}

// DVDCancelStreamAsync
// Address: 0x803DD02C, Size: 188
void DVDCancelStreamAsync() {
}

// DVDCancelStream
// Address: 0x803DD0E8, Size: 160
void DVDCancelStream() {
}

// DVDStopStreamAtEndAsync
// Address: 0x803DD1B0, Size: 188
void DVDStopStreamAtEndAsync() {
}

// DVDStopStreamAtEnd
// Address: 0x803DD26C, Size: 160
void DVDStopStreamAtEnd() {
}

// DVDGetStreamErrorStatusAsync
// Address: 0x803DD334, Size: 188
void DVDGetStreamErrorStatusAsync() {
}

// DVDGetStreamErrorStatus
// Address: 0x803DD3F0, Size: 160
void DVDGetStreamErrorStatus() {
}

// DVDGetStreamPlayAddrAsync
// Address: 0x803DD4B8, Size: 188
void DVDGetStreamPlayAddrAsync() {
}

// DVDGetStreamPlayAddr
// Address: 0x803DD574, Size: 160
void DVDGetStreamPlayAddr() {
}

// DVDGetStreamStartAddrAsync
// Address: 0x803DD63C, Size: 188
void DVDGetStreamStartAddrAsync() {
}

// DVDGetStreamStartAddr
// Address: 0x803DD6F8, Size: 160
void DVDGetStreamStartAddr() {
}

// DVDGetStreamLengthAsync
// Address: 0x803DD7C0, Size: 188
void DVDGetStreamLengthAsync() {
}

// DVDGetStreamLength
// Address: 0x803DD87C, Size: 160
void DVDGetStreamLength() {
}

// DVDChangeDiskAsyncForBS
// Address: 0x803DDA00, Size: 188
void DVDChangeDiskAsyncForBS() {
}

// DVDChangeDiskAsync
// Address: 0x803DDABC, Size: 272
void DVDChangeDiskAsync() {
}

// DVDChangeDisk
// Address: 0x803DDBCC, Size: 260
void DVDChangeDisk() {
}

// DVDStopMotorAsync
// Address: 0x803DDCF4, Size: 188
void DVDStopMotorAsync() {
}

// DVDStopMotor
// Address: 0x803DDDB0, Size: 180
void DVDStopMotor() {
}

// DVDInquiryAsync
// Address: 0x803DDE88, Size: 208
void DVDInquiryAsync() {
}

// DVDInquiry
// Address: 0x803DDF58, Size: 200
void DVDInquiry() {
}

// DVDReset
// Address: 0x803DE044, Size: 68
void DVDReset() {
}

// DVDResetRequired
// Address: 0x803DE088, Size: 8
void DVDResetRequired() {
}

// DVDGetCommandBlockStatus
// Address: 0x803DE090, Size: 76
void DVDGetCommandBlockStatus() {
}

// DVDGetDriveStatus
// Address: 0x803DE0DC, Size: 172
void DVDGetDriveStatus() {
}

// DVDSetAutoInvalidation
// Address: 0x803DE188, Size: 16
void DVDSetAutoInvalidation() {
}

// DVDPause
// Address: 0x803DE198, Size: 60
void DVDPause() {
}

// DVDResume
// Address: 0x803DE1D4, Size: 80
void DVDResume() {
}

// DVDCancelAsync
// Address: 0x803DE224, Size: 636
void DVDCancelAsync() {
}

// DVDCancel
// Address: 0x803DE4A0, Size: 172
void DVDCancel() {
}

// DVDCancelAllAsync
// Address: 0x803DE570, Size: 236
void DVDCancelAllAsync() {
}

// DVDCancelAll
// Address: 0x803DE65C, Size: 312
void DVDCancelAll() {
}

// DVDGetCurrentDiskID
// Address: 0x803DE7C0, Size: 8
void DVDGetCurrentDiskID() {
}

// DVDCheckDisk
// Address: 0x803DE7C8, Size: 248
void DVDCheckDisk() {
}

// DVDDumpWaitingQueue
// Address: 0x803DED3C, Size: 268
void DVDDumpWaitingQueue() {
}

// DVDCompareDiskID
// Address: 0x803DF178, Size: 248
void DVDCompareDiskID() {
}

// DVDGenerateDiskID
// Address: 0x803DF270, Size: 128
void DVDGenerateDiskID() {
}

// DVDSetAutoFatalMessaging
// Address: 0x803DF37C, Size: 112
void DVDSetAutoFatalMessaging() {
}

// DVDLowRead
// Address: 0x803DFE90, Size: 664
void DVDLowRead() {
}

// DVDLowSeek
// Address: 0x803E0128, Size: 148
void DVDLowSeek() {
}

// DVDLowWaitCoverClose
// Address: 0x803E01BC, Size: 44
void DVDLowWaitCoverClose() {
}

// DVDLowReadDiskID
// Address: 0x803E01E8, Size: 164
void DVDLowReadDiskID() {
}

// DVDLowStopMotor
// Address: 0x803E028C, Size: 140
void DVDLowStopMotor() {
}

// DVDLowRequestError
// Address: 0x803E0318, Size: 140
void DVDLowRequestError() {
}

// DVDLowInquiry
// Address: 0x803E03A4, Size: 156
void DVDLowInquiry() {
}

// DVDLowAudioStream
// Address: 0x803E0440, Size: 152
void DVDLowAudioStream() {
}

// DVDLowRequestAudioStatus
// Address: 0x803E04D8, Size: 140
void DVDLowRequestAudioStatus() {
}

// DVDLowAudioBufferConfig
// Address: 0x803E0564, Size: 156
void DVDLowAudioBufferConfig() {
}

// DVDLowReset
// Address: 0x803E0600, Size: 188
void DVDLowReset() {
}

// DVDLowSetResetCoverCallback
// Address: 0x803E06BC, Size: 68
void DVDLowSetResetCoverCallback() {
}

// DVDLowBreak
// Address: 0x803E07F4, Size: 20
void DVDLowBreak() {
}

// DVDLowClearCallback
// Address: 0x803E0808, Size: 28
void DVDLowClearCallback() {
}

// DVDLowGetCoverStatus
// Address: 0x803E0824, Size: 148
void DVDLowGetCoverStatus() {
}

// DVDInitialized
// Address: 0x8078FE8C, Size: 4
void DVDInitialized() {
}
