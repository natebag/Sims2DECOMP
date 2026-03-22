// card.cpp - CARD memory card
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 49 functions
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

// CARDInit
// Address: 0x80559FF0, Size: 172
void CARDInit() {
}

// CARDGetDiskID
// Address: 0x8055A104, Size: 24
void CARDGetDiskID() {
}

// CARDSetDiskID
// Address: 0x8055A11C, Size: 120
void CARDSetDiskID() {
}

// CARDGetResultCode
// Address: 0x8055A2B0, Size: 48
void CARDGetResultCode() {
}

// CARDFreeBlocks
// Address: 0x8055A2E0, Size: 336
void CARDFreeBlocks() {
}

// CARDGetEncoding
// Address: 0x8055A430, Size: 136
void CARDGetEncoding() {
}

// CARDGetMemSize
// Address: 0x8055A4B8, Size: 132
void CARDGetMemSize() {
}

// CARDGetSectorSize
// Address: 0x8055A53C, Size: 132
void CARDGetSectorSize() {
}

// CARDSetFastMode
// Address: 0x8055A6A8, Size: 52
void CARDSetFastMode() {
}

// CARDGetFastMode
// Address: 0x8055A6DC, Size: 28
void CARDGetFastMode() {
}

// CARDGetCurrentMode
// Address: 0x8055A6F8, Size: 172
void CARDGetCurrentMode() {
}

// CARDCheckExAsync
// Address: 0x8055B790, Size: 1424
void CARDCheckExAsync() {
}

// CARDCheckAsync
// Address: 0x8055BD20, Size: 40
void CARDCheckAsync() {
}

// CARDCheckEx
// Address: 0x8055BD48, Size: 92
void CARDCheckEx() {
}

// CARDCheck
// Address: 0x8055BDA4, Size: 84
void CARDCheck() {
}

// CARDProbe
// Address: 0x8055BF18, Size: 56
void CARDProbe() {
}

// CARDProbeEx
// Address: 0x8055BF50, Size: 380
void CARDProbeEx() {
}

// CARDMountAsync
// Address: 0x8055C658, Size: 416
void CARDMountAsync() {
}

// CARDMount
// Address: 0x8055C7F8, Size: 72
void CARDMount() {
}

// CARDUnmount
// Address: 0x8055C8DC, Size: 172
void CARDUnmount() {
}

// CARDFormatAsync
// Address: 0x8055D16C, Size: 72
void CARDFormatAsync() {
}

// CARDFormat
// Address: 0x8055D1B4, Size: 84
void CARDFormat() {
}

// CARDFastOpen
// Address: 0x8055D67C, Size: 260
void CARDFastOpen() {
}

// CARDOpen
// Address: 0x8055D780, Size: 284
void CARDOpen() {
}

// CARDClose
// Address: 0x8055D89C, Size: 84
void CARDClose() {
}

// CARDCreateAsync
// Address: 0x8055DA28, Size: 544
void CARDCreateAsync() {
}

// CARDCreate
// Address: 0x8055DC48, Size: 72
void CARDCreate() {
}

// CARDReadAsync
// Address: 0x8055DF78, Size: 324
void CARDReadAsync() {
}

// CARDRead
// Address: 0x8055E0BC, Size: 72
void CARDRead() {
}

// CARDCancel
// Address: 0x8055E104, Size: 140
void CARDCancel() {
}

// CARDWriteAsync
// Address: 0x8055E3B0, Size: 276
void CARDWriteAsync() {
}

// CARDWrite
// Address: 0x8055E4C4, Size: 72
void CARDWrite() {
}

// CARDFastDeleteAsync
// Address: 0x8055E5B0, Size: 300
void CARDFastDeleteAsync() {
}

// CARDFastDelete
// Address: 0x8055E6DC, Size: 72
void CARDFastDelete() {
}

// CARDDeleteAsync
// Address: 0x8055E724, Size: 272
void CARDDeleteAsync() {
}

// CARDDelete
// Address: 0x8055E834, Size: 72
void CARDDelete() {
}

// CARDGetStatus
// Address: 0x8055EA74, Size: 276
void CARDGetStatus() {
}

// CARDSetStatusAsync
// Address: 0x8055EB88, Size: 372
void CARDSetStatusAsync() {
}

// CARDSetStatus
// Address: 0x8055ECFC, Size: 72
void CARDSetStatus() {
}

// CARDSetVendorID
// Address: 0x8055ED44, Size: 16
void CARDSetVendorID() {
}

// CARDGetVendorID
// Address: 0x8055ED54, Size: 8
void CARDGetVendorID() {
}

// CARDGetSerialNo
// Address: 0x8055ED5C, Size: 196
void CARDGetSerialNo() {
}

// CARDGetUniqueCode
// Address: 0x8055EE20, Size: 148
void CARDGetUniqueCode() {
}

// CARDGetAttributes
// Address: 0x8055EEB4, Size: 64
void CARDGetAttributes() {
}

// CARDSetAttributesAsync
// Address: 0x8055EEF4, Size: 228
void CARDSetAttributesAsync() {
}

// CARDSetAttributes
// Address: 0x8055EFD8, Size: 72
void CARDSetAttributes() {
}

// CARDRand
// Address: 0x8055F0F0, Size: 36
void CARDRand() {
}

// CARDSrand
// Address: 0x8055F114, Size: 8
void CARDSrand() {
}

// CARDGetXferredBytes
// Address: 0x80560948, Size: 24
void CARDGetXferredBytes() {
}
