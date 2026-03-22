// lib_misc.cpp - Miscellaneous library functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 377 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"
#include "stub_classes.h"

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

// GetSkuLine(void)
// Address: 0x803BB3D8, Size: 140
void GetSkuLine() {
}

// GetBuidVersionLine(void)
// Address: 0x803BB464, Size: 72
void GetBuidVersionLine() {
}

// GetSandboxLine(void)
// Address: 0x803BB4AC, Size: 72
void GetSandboxLine() {
}

// PCwriteAsyncInit
// Address: 0x803BE440, Size: 8
void PCwriteAsyncInit() {
}

// DoFSReadHeader
// Address: 0x803BE448, Size: 140
void DoFSReadHeader() {
}

// InitReadCounts
// Address: 0x803BE4D4, Size: 92
void InitReadCounts() {
}

// PCreadAsyncNext
// Address: 0x803BE530, Size: 140
void PCreadAsyncNext() {
}

// PCreadAsyncInit
// Address: 0x803BE5BC, Size: 164
void PCreadAsyncInit() {
}

// ReadSyncNext
// Address: 0x803BE660, Size: 160
void ReadSyncNext() {
}

// CompletePCreadAsync
// Address: 0x803BE700, Size: 388
void CompletePCreadAsync() {
}

// PCrwAsyncFSACK
// Address: 0x803BE884, Size: 168
void PCrwAsyncFSACK() {
}

// PCrwSyncFSACK
// Address: 0x803BE92C, Size: 216
void PCrwSyncFSACK() {
}

// CompleteAsync
// Address: 0x803BEA04, Size: 84
void CompleteAsync() {
}

// PCrwAsyncNextPh
// Address: 0x803BEA58, Size: 116
void PCrwAsyncNextPh() {
}

// PCgetLastError
// Address: 0x803BEC78, Size: 20
void PCgetLastError() {
}

// DisDvdBP
// Address: 0x803BEC8C, Size: 32
void DisDvdBP() {
}

// EnaDvdBP
// Address: 0x803BECAC, Size: 36
void EnaDvdBP() {
}

// ForceDvdTcIrq
// Address: 0x803BECD0, Size: 136
void ForceDvdTcIrq() {
}

// ForceDvdDeIrq
// Address: 0x803BED58, Size: 68
void ForceDvdDeIrq() {
}

// DvdCallback
// Address: 0x803BED9C, Size: 128
void DvdCallback() {
}

// CheckSeekOffset
// Address: 0x803BEE1C, Size: 32
void CheckSeekOffset() {
}

// DSIExcHandler
// Address: 0x803BEE3C, Size: 180
void DSIExcHandler() {
}

// DSIHandler
// Address: 0x803BEEF0, Size: 628
void DSIHandler() {
}

// acosf
// Address: 0x803BF2BC, Size: 588
void acosf() {
}

// atan2f
// Address: 0x803BF508, Size: 544
void atan2f() {
}

// fmodf
// Address: 0x803BF728, Size: 456
void fmodf() {
}

// sqrtf
// Address: 0x803BF8F0, Size: 248
void sqrtf() {
}

// atanf
// Address: 0x803BF9E8, Size: 528
void atanf() {
}

// ceilf
// Address: 0x803BFBF8, Size: 196
void ceilf() {
}

// cosf
// Address: 0x803BFCBC, Size: 220
void cosf() {
}

// fabsf
// Address: 0x803BFD98, Size: 36
void fabsf() {
}

// floorf
// Address: 0x803BFDBC, Size: 200
void floorf() {
}

// sinf
// Address: 0x803BFE84, Size: 220
void sinf() {
}

// tanf
// Address: 0x803BFF60, Size: 128
void tanf() {
}

// scalbnf
// Address: 0x803C0F60, Size: 284
void scalbnf() {
}

// copysignf
// Address: 0x803C107C, Size: 52
void copysignf() {
}

// puts
// Address: 0x803C11E0, Size: 40
void puts() {
}

// strcasecmp
// Address: 0x803C2098, Size: 148
void strcasecmp() {
}

// strncasecmp
// Address: 0x803C23F0, Size: 188
void strncasecmp() {
}

// strrchr
// Address: 0x803C2658, Size: 76
void strrchr() {
}

// strround
// Address: 0x803C270C, Size: 92
void strround() {
}

// strrev
// Address: 0x803C2768, Size: 76
void strrev() {
}

// itoa
// Address: 0x803C27B4, Size: 124
void itoa() {
}

// fftoa
// Address: 0x803C2830, Size: 1256
void fftoa() {
}

// vfprintf
// Address: 0x803C2E1C, Size: 216
void vfprintf() {
}

// vfiprintf
// Address: 0x803C440C, Size: 60
void vfiprintf() {
}

// setlocale
// Address: 0x803C58FC, Size: 48
void setlocale() {
}

// localeconv
// Address: 0x803C592C, Size: 36
void localeconv() {
}

// memchr
// Address: 0x803C69E4, Size: 192
void memchr() {
}

// fflush
// Address: 0x803C6AA4, Size: 244
void fflush() {
}

// lflush
// Address: 0x803C748C, Size: 32
void lflush() {
}

// new_eh_context
// Address: 0x803C93CC, Size: 136
void new_eh_context() {
}

// eh_context_initialize
// Address: 0x803C94B0, Size: 52
void eh_context_initialize() {
}

// eh_context_static
// Address: 0x803C94E4, Size: 108
void eh_context_static() {
}

// PPCMfmsr
// Address: 0x803C9900, Size: 8
void PPCMfmsr() {
}

// PPCMtmsr
// Address: 0x803C9908, Size: 8
void PPCMtmsr() {
}

// PPCOrMsr
// Address: 0x803C9910, Size: 12
void PPCOrMsr() {
}

// PPCAndMsr
// Address: 0x803C991C, Size: 12
void PPCAndMsr() {
}

// PPCAndCMsr
// Address: 0x803C9928, Size: 12
void PPCAndCMsr() {
}

// PPCMfhid0
// Address: 0x803C9934, Size: 8
void PPCMfhid0() {
}

// PPCMthid0
// Address: 0x803C993C, Size: 8
void PPCMthid0() {
}

// PPCMfhid1
// Address: 0x803C9944, Size: 8
void PPCMfhid1() {
}

// PPCMfl2cr
// Address: 0x803C994C, Size: 8
void PPCMfl2cr() {
}

// PPCMtl2cr
// Address: 0x803C9954, Size: 8
void PPCMtl2cr() {
}

// PPCMtdec
// Address: 0x803C995C, Size: 8
void PPCMtdec() {
}

// PPCMfdec
// Address: 0x803C9964, Size: 8
void PPCMfdec() {
}

// PPCSync
// Address: 0x803C996C, Size: 8
void PPCSync() {
}

// PPCEieio
// Address: 0x803C9974, Size: 52
void PPCEieio() {
}

// PPCHalt
// Address: 0x803C99A8, Size: 20
void PPCHalt() {
}

// PPCMfmmcr0
// Address: 0x803C99BC, Size: 8
void PPCMfmmcr0() {
}

// PPCMtmmcr0
// Address: 0x803C99C4, Size: 8
void PPCMtmmcr0() {
}

// PPCMfmmcr1
// Address: 0x803C99CC, Size: 8
void PPCMfmmcr1() {
}

// PPCMtmmcr1
// Address: 0x803C99D4, Size: 8
void PPCMtmmcr1() {
}

// PPCMfpmc1
// Address: 0x803C99DC, Size: 8
void PPCMfpmc1() {
}

// PPCMtpmc1
// Address: 0x803C99E4, Size: 8
void PPCMtpmc1() {
}

// PPCMfpmc2
// Address: 0x803C99EC, Size: 8
void PPCMfpmc2() {
}

// PPCMtpmc2
// Address: 0x803C99F4, Size: 8
void PPCMtpmc2() {
}

// PPCMfpmc3
// Address: 0x803C99FC, Size: 8
void PPCMfpmc3() {
}

// PPCMtpmc3
// Address: 0x803C9A04, Size: 8
void PPCMtpmc3() {
}

// PPCMfpmc4
// Address: 0x803C9A0C, Size: 8
void PPCMfpmc4() {
}

// PPCMtpmc4
// Address: 0x803C9A14, Size: 8
void PPCMtpmc4() {
}

// PPCMfsia
// Address: 0x803C9A1C, Size: 8
void PPCMfsia() {
}

// PPCMtsia
// Address: 0x803C9A24, Size: 8
void PPCMtsia() {
}

// PPCMffpscr
// Address: 0x803C9A2C, Size: 32
void PPCMffpscr() {
}

// PPCMtfpscr
// Address: 0x803C9A4C, Size: 40
void PPCMtfpscr() {
}

// PPCMfhid2
// Address: 0x803C9A74, Size: 8
void PPCMfhid2() {
}

// PPCMthid2
// Address: 0x803C9A7C, Size: 8
void PPCMthid2() {
}

// PPCMfwpar
// Address: 0x803C9A84, Size: 12
void PPCMfwpar() {
}

// PPCMtwpar
// Address: 0x803C9A90, Size: 8
void PPCMtwpar() {
}

// PPCMfdmaU
// Address: 0x803C9A98, Size: 8
void PPCMfdmaU() {
}

// PPCMfdmaL
// Address: 0x803C9AA0, Size: 8
void PPCMfdmaL() {
}

// PPCMtdmaU
// Address: 0x803C9AA8, Size: 8
void PPCMtdmaU() {
}

// PPCMtdmaL
// Address: 0x803C9AB0, Size: 8
void PPCMtdmaL() {
}

// PPCMfpvr
// Address: 0x803C9AB8, Size: 8
void PPCMfpvr() {
}

// PPCEnableSpeculation
// Address: 0x803C9AC0, Size: 40
void PPCEnableSpeculation() {
}

// PPCDisableSpeculation
// Address: 0x803C9AE8, Size: 40
void PPCDisableSpeculation() {
}

// PPCSetFpIEEEMode
// Address: 0x803C9B10, Size: 8
void PPCSetFpIEEEMode() {
}

// PPCSetFpNonIEEEMode
// Address: 0x803C9B18, Size: 8
void PPCSetFpNonIEEEMode() {
}

// DisableWriteGatherPipe
// Address: 0x803C9C54, Size: 40
void DisableWriteGatherPipe() {
}

// ClearArena
// Address: 0x803C9CA4, Size: 312
void ClearArena() {
}

// InquiryCallback
// Address: 0x803C9DDC, Size: 60
void InquiryCallback() {
}

// SetTimer
// Address: 0x803CA898, Size: 152
void SetTimer() {
}

// InsertAlarm
// Address: 0x803CA998, Size: 592
void InsertAlarm() {
}

// DecrementerExceptionCallback
// Address: 0x803CAE58, Size: 560
void DecrementerExceptionCallback() {
}

// DecrementerExceptionHandler
// Address: 0x803CB088, Size: 80
void DecrementerExceptionHandler() {
}

// OnReset
// Address: 0x803CB190, Size: 160
void OnReset() {
}

// DCFlashInvalidate
// Address: 0x803CB530, Size: 16
void DCFlashInvalidate() {
}

// DCEnable
// Address: 0x803CB540, Size: 20
void DCEnable() {
}

// DCDisable
// Address: 0x803CB554, Size: 20
void DCDisable() {
}

// DCFreeze
// Address: 0x803CB568, Size: 20
void DCFreeze() {
}

// DCUnfreeze
// Address: 0x803CB57C, Size: 16
void DCUnfreeze() {
}

// DCTouchLoad
// Address: 0x803CB58C, Size: 8
void DCTouchLoad() {
}

// DCBlockZero
// Address: 0x803CB594, Size: 8
void DCBlockZero() {
}

// DCBlockStore
// Address: 0x803CB59C, Size: 8
void DCBlockStore() {
}

// DCBlockFlush
// Address: 0x803CB5A4, Size: 8
void DCBlockFlush() {
}

// DCBlockInvalidate
// Address: 0x803CB5AC, Size: 8
void DCBlockInvalidate() {
}

// DCInvalidateRange
// Address: 0x803CB5B4, Size: 44
void DCInvalidateRange() {
}

// DCFlushRange
// Address: 0x803CB5E0, Size: 48
void DCFlushRange() {
}

// DCStoreRange
// Address: 0x803CB610, Size: 48
void DCStoreRange() {
}

// DCFlushRangeNoSync
// Address: 0x803CB640, Size: 44
void DCFlushRangeNoSync() {
}

// DCStoreRangeNoSync
// Address: 0x803CB66C, Size: 44
void DCStoreRangeNoSync() {
}

// DCZeroRange
// Address: 0x803CB698, Size: 44
void DCZeroRange() {
}

// DCTouchRange
// Address: 0x803CB6C4, Size: 44
void DCTouchRange() {
}

// ICInvalidateRange
// Address: 0x803CB6F0, Size: 52
void ICInvalidateRange() {
}

// ICFlashInvalidate
// Address: 0x803CB724, Size: 16
void ICFlashInvalidate() {
}

// ICEnable
// Address: 0x803CB734, Size: 20
void ICEnable() {
}

// ICDisable
// Address: 0x803CB748, Size: 20
void ICDisable() {
}

// ICFreeze
// Address: 0x803CB75C, Size: 20
void ICFreeze() {
}

// ICUnfreeze
// Address: 0x803CB770, Size: 16
void ICUnfreeze() {
}

// ICBlockInvalidate
// Address: 0x803CB780, Size: 8
void ICBlockInvalidate() {
}

// ICSync
// Address: 0x803CB788, Size: 8
void ICSync() {
}

// LCEnable
// Address: 0x803CB85C, Size: 56
void LCEnable() {
}

// LCDisable
// Address: 0x803CB894, Size: 40
void LCDisable() {
}

// LCAllocOneTag
// Address: 0x803CB8BC, Size: 20
void LCAllocOneTag() {
}

// LCAllocTags
// Address: 0x803CB8D0, Size: 64
void LCAllocTags() {
}

// LCLoadBlocks
// Address: 0x803CB910, Size: 36
void LCLoadBlocks() {
}

// LCStoreBlocks
// Address: 0x803CB934, Size: 36
void LCStoreBlocks() {
}

// LCAlloc
// Address: 0x803CB958, Size: 112
void LCAlloc() {
}

// LCAllocNoInvalidate
// Address: 0x803CB9C8, Size: 112
void LCAllocNoInvalidate() {
}

// LCLoadData
// Address: 0x803CBA38, Size: 172
void LCLoadData() {
}

// LCStoreData
// Address: 0x803CBAE4, Size: 172
void LCStoreData() {
}

// LCQueueLength
// Address: 0x803CBB90, Size: 12
void LCQueueLength() {
}

// LCQueueWait
// Address: 0x803CBB9C, Size: 20
void LCQueueWait() {
}

// LCFlushQueue
// Address: 0x803CBBB0, Size: 72
void LCFlushQueue() {
}

// L2Init
// Address: 0x803CBBF8, Size: 76
void L2Init() {
}

// L2Enable
// Address: 0x803CBC44, Size: 44
void L2Enable() {
}

// L2Disable
// Address: 0x803CBC70, Size: 48
void L2Disable() {
}

// L2GlobalInvalidate
// Address: 0x803CBCA0, Size: 152
void L2GlobalInvalidate() {
}

// L2SetDataOnly
// Address: 0x803CBD38, Size: 64
void L2SetDataOnly() {
}

// L2SetWriteThrough
// Address: 0x803CBD78, Size: 64
void L2SetWriteThrough() {
}

// DMAErrorHandler
// Address: 0x803CBDB8, Size: 352
void DMAErrorHandler() {
}

// PackArgs
// Address: 0x803CD0BC, Size: 392
void PackArgs() {
}

// Run
// Address: 0x803CD244, Size: 60
void Run() {
}

// StartDol
// Address: 0x803CD280, Size: 104
void StartDol() {
}

// ReadDisc
// Address: 0x803CD2E8, Size: 108
void ReadDisc() {
}

// Callback
// Address: 0x803CD354, Size: 12
void Callback() {
}

// IsStreamEnabled
// Address: 0x803CD360, Size: 56
void IsStreamEnabled() {
}

// StopStreaming
// Address: 0x803CD41C, Size: 160
void StopStreaming() {
}

// GetApploaderPosition
// Address: 0x803CD4BC, Size: 196
void GetApploaderPosition() {
}

// LoadApploader
// Address: 0x803CD580, Size: 244
void LoadApploader() {
}

// LoadDol
// Address: 0x803CD674, Size: 272
void LoadDol() {
}

// IsNewApploader
// Address: 0x803CD784, Size: 64
void IsNewApploader() {
}

// ExecCommon
// Address: 0x803CDDE4, Size: 104
void ExecCommon() {
}

// SetInterruptMask
// Address: 0x803CE110, Size: 728
void SetInterruptMask() {
}

// ExternalInterruptHandler
// Address: 0x803CE8D8, Size: 80
void ExternalInterruptHandler() {
}

// Relocate
// Address: 0x803CE93C, Size: 700
void Relocate() {
}

// Link
// Address: 0x803CEBF8, Size: 736
void Link() {
}

// Undo
// Address: 0x803CEF38, Size: 568
void Undo() {
}

// MEMIntrruptHandler
// Address: 0x803CF450, Size: 108
void MEMIntrruptHandler() {
}

// Config24MB
// Address: 0x803CF580, Size: 128
void Config24MB() {
}

// Config48MB
// Address: 0x803CF600, Size: 128
void Config48MB() {
}

// RealMode
// Address: 0x803CF680, Size: 24
void RealMode() {
}

// Reset
// Address: 0x803CF9C0, Size: 112
void Reset() {
}

// KillThreads
// Address: 0x803CFA30, Size: 104
void KillThreads() {
}

// GetRTC
// Address: 0x803D0354, Size: 280
void GetRTC() {
}

// ReadSram
// Address: 0x803D07A0, Size: 284
void ReadSram() {
}

// WriteSramCallback
// Address: 0x803D08BC, Size: 96
void WriteSramCallback() {
}

// WriteSram
// Address: 0x803D091C, Size: 280
void WriteSram() {
}

// LockSram
// Address: 0x803D0B70, Size: 104
void LockSram() {
}

// UnlockSram
// Address: 0x803D0C90, Size: 828
void UnlockSram() {
}

// SystemCallVector
// Address: 0x803D1CA4, Size: 32
void SystemCallVector() {
}

// DefaultSwitchThreadCallback
// Address: 0x803D1D28, Size: 4
void DefaultSwitchThreadCallback() {
}

// SetRun
// Address: 0x803D2084, Size: 108
void SetRun() {
}

// UnsetRun
// Address: 0x803D20F0, Size: 104
void UnsetRun() {
}

// SetEffectivePriority
// Address: 0x803D2194, Size: 448
void SetEffectivePriority() {
}

// UpdatePriority
// Address: 0x803D2354, Size: 120
void UpdatePriority() {
}

// SelectThread
// Address: 0x803D241C, Size: 552
void SelectThread() {
}

// CheckThreadQueue
// Address: 0x803D3474, Size: 156
void CheckThreadQueue() {
}

// IsMember
// Address: 0x803D3510, Size: 44
void IsMember() {
}

// IsLeapYear
// Address: 0x803D3F1C, Size: 136
void IsLeapYear() {
}

// GetYearDays
// Address: 0x803D3FA4, Size: 168
void GetYearDays() {
}

// GetLeapDays
// Address: 0x803D404C, Size: 80
void GetLeapDays() {
}

// GetDates
// Address: 0x803D409C, Size: 412
void GetDates() {
}

// SetExiInterruptMask
// Address: 0x803D4E6C, Size: 244
void SetExiInterruptMask() {
}

// CompleteTransfer
// Address: 0x803D4F60, Size: 340
void CompleteTransfer() {
}

// TCIntrruptHandler
// Address: 0x803D6194, Size: 536
void TCIntrruptHandler() {
}

// UnlockedHandler
// Address: 0x803D6838, Size: 40
void UnlockedHandler() {
}

// ProbeBarnacle
// Address: 0x803D6F5C, Size: 396
void ProbeBarnacle() {
}

// InitializeUART
// Address: 0x803D72A4, Size: 112
void InitializeUART() {
}

// ReadUARTN
// Address: 0x803D7314, Size: 8
void ReadUARTN() {
}

// QueueLength
// Address: 0x803D731C, Size: 152
void QueueLength() {
}

// WriteUARTN
// Address: 0x803D73B4, Size: 512
void WriteUARTN() {
}

// AlarmHandler
// Address: 0x803D873C, Size: 140
void AlarmHandler() {
}

// CallTypeAndStatusCallback
// Address: 0x803D8934, Size: 120
void CallTypeAndStatusCallback() {
}

// GetTypeCallback
// Address: 0x803D89AC, Size: 664
void GetTypeCallback() {
}

// DBInit
// Address: 0x803D9314, Size: 40
void DBInit() {
}

// DBIsDebuggerPresent
// Address: 0x803D933C, Size: 28
void DBIsDebuggerPresent() {
}

// DBPrintf
// Address: 0x803D941C, Size: 80
void DBPrintf() {
}

// C_VECAdd
// Address: 0x803D946C, Size: 52
void C_VECAdd() {
}

// PSVECAdd
// Address: 0x803D94A0, Size: 36
void PSVECAdd() {
}

// C_VECSubtract
// Address: 0x803D94C4, Size: 52
void C_VECSubtract() {
}

// PSVECSubtract
// Address: 0x803D94F8, Size: 36
void PSVECSubtract() {
}

// C_VECScale
// Address: 0x803D951C, Size: 40
void C_VECScale() {
}

// PSVECScale
// Address: 0x803D9544, Size: 28
void PSVECScale() {
}

// C_VECNormalize
// Address: 0x803D9560, Size: 200
void C_VECNormalize() {
}

// PSVECNormalize
// Address: 0x803D9628, Size: 68
void PSVECNormalize() {
}

// C_VECSquareMag
// Address: 0x803D966C, Size: 36
void C_VECSquareMag() {
}

// PSVECSquareMag
// Address: 0x803D9690, Size: 24
void PSVECSquareMag() {
}

// C_VECMag
// Address: 0x803D96A8, Size: 148
void C_VECMag() {
}

// PSVECMag
// Address: 0x803D973C, Size: 68
void PSVECMag() {
}

// C_VECDotProduct
// Address: 0x803D9780, Size: 48
void C_VECDotProduct() {
}

// PSVECDotProduct
// Address: 0x803D97B0, Size: 32
void PSVECDotProduct() {
}

// C_VECCrossProduct
// Address: 0x803D97D0, Size: 76
void C_VECCrossProduct() {
}

// PSVECCrossProduct
// Address: 0x803D981C, Size: 60
void PSVECCrossProduct() {
}

// C_VECHalfAngle
// Address: 0x803D9858, Size: 216
void C_VECHalfAngle() {
}

// C_VECReflect
// Address: 0x803D9930, Size: 212
void C_VECReflect() {
}

// C_VECSquareDistance
// Address: 0x803D9A04, Size: 60
void C_VECSquareDistance() {
}

// PSVECSquareDistance
// Address: 0x803D9A40, Size: 40
void PSVECSquareDistance() {
}

// C_VECDistance
// Address: 0x803D9A68, Size: 172
void C_VECDistance() {
}

// PSVECDistance
// Address: 0x803D9B14, Size: 84
void PSVECDistance() {
}

// isSame
// Address: 0x803D9BA0, Size: 160
void isSame() {
}

// myStrncpy
// Address: 0x803DA094, Size: 56
void myStrncpy() {
}

// entryToPath
// Address: 0x803DA0CC, Size: 352
void entryToPath() {
}

// cbForReadAsync
// Address: 0x803DA564, Size: 48
void cbForReadAsync() {
}

// cbForReadSync
// Address: 0x803DA6AC, Size: 36
void cbForReadSync() {
}

// cbForSeekAsync
// Address: 0x803DA768, Size: 48
void cbForSeekAsync() {
}

// cbForSeekSync
// Address: 0x803DA844, Size: 36
void cbForSeekSync() {
}

// cbForPrepareStreamAsync
// Address: 0x803DAB64, Size: 48
void cbForPrepareStreamAsync() {
}

// cbForPrepareStreamSync
// Address: 0x803DACD8, Size: 36
void cbForPrepareStreamSync() {
}

// defaultOptionalCommandChecker
// Address: 0x803DAD68, Size: 4
void defaultOptionalCommandChecker() {
}

// stateReadingFST
// Address: 0x803DAE4C, Size: 148
void stateReadingFST() {
}

// cbForStateReadingFST
// Address: 0x803DAEE0, Size: 128
void cbForStateReadingFST() {
}

// cbForStateError
// Address: 0x803DAF60, Size: 172
void cbForStateError() {
}

// stateError
// Address: 0x803DB00C, Size: 44
void stateError() {
}

// stateTimeout
// Address: 0x803DB038, Size: 52
void stateTimeout() {
}

// stateGettingError
// Address: 0x803DB06C, Size: 40
void stateGettingError() {
}

// CategorizeError
// Address: 0x803DB094, Size: 180
void CategorizeError() {
}

// CheckCancel
// Address: 0x803DB148, Size: 156
void CheckCancel() {
}

// cbForStateGettingError
// Address: 0x803DB1E4, Size: 612
void cbForStateGettingError() {
}

// cbForUnrecoveredError
// Address: 0x803DB448, Size: 92
void cbForUnrecoveredError() {
}

// cbForUnrecoveredErrorRetry
// Address: 0x803DB4A4, Size: 128
void cbForUnrecoveredErrorRetry() {
}

// stateGoToRetry
// Address: 0x803DB524, Size: 40
void stateGoToRetry() {
}

// cbForStateGoToRetry
// Address: 0x803DB54C, Size: 320
void cbForStateGoToRetry() {
}

// stateCheckID
// Address: 0x803DB68C, Size: 224
void stateCheckID() {
}

// stateCheckID3
// Address: 0x803DB76C, Size: 52
void stateCheckID3() {
}

// stateCheckID2a
// Address: 0x803DB7A0, Size: 52
void stateCheckID2a() {
}

// cbForStateCheckID2a
// Address: 0x803DB7D4, Size: 104
void cbForStateCheckID2a() {
}

// stateCheckID2
// Address: 0x803DB83C, Size: 56
void stateCheckID2() {
}

// cbForStateCheckID1
// Address: 0x803DB874, Size: 252
void cbForStateCheckID1() {
}

// cbForStateCheckID2
// Address: 0x803DB970, Size: 216
void cbForStateCheckID2() {
}

// cbForStateCheckID3
// Address: 0x803DBA48, Size: 240
void cbForStateCheckID3() {
}

// stateCoverClosed
// Address: 0x803DBB7C, Size: 212
void stateCoverClosed() {
}

// stateCoverClosed_CMD
// Address: 0x803DBC50, Size: 48
void stateCoverClosed_CMD() {
}

// cbForStateCoverClosed
// Address: 0x803DBC80, Size: 100
void cbForStateCoverClosed() {
}

// stateMotorStopped
// Address: 0x803DBCE4, Size: 40
void stateMotorStopped() {
}

// cbForStateMotorStopped
// Address: 0x803DBD0C, Size: 236
void cbForStateMotorStopped() {
}

// stateReady
// Address: 0x803DBDF8, Size: 744
void stateReady() {
}

// stateBusy
// Address: 0x803DC0E0, Size: 832
void stateBusy() {
}

// IsImmCommandWithResult
// Address: 0x803DC460, Size: 92
void IsImmCommandWithResult() {
}

// IsDmaCommand
// Address: 0x803DC4BC, Size: 64
void IsDmaCommand() {
}

// cbForStateBusy
// Address: 0x803DC4FC, Size: 1624
void cbForStateBusy() {
}

// issueCommand
// Address: 0x803DCB60, Size: 188
void issueCommand() {
}

// cbForCancelStreamSync
// Address: 0x803DD188, Size: 40
void cbForCancelStreamSync() {
}

// cbForStopStreamAtEndSync
// Address: 0x803DD30C, Size: 40
void cbForStopStreamAtEndSync() {
}

// cbForGetStreamErrorStatusSync
// Address: 0x803DD490, Size: 40
void cbForGetStreamErrorStatusSync() {
}

// cbForGetStreamPlayAddrSync
// Address: 0x803DD614, Size: 40
void cbForGetStreamPlayAddrSync() {
}

// cbForGetStreamStartAddrSync
// Address: 0x803DD798, Size: 40
void cbForGetStreamStartAddrSync() {
}

// cbForGetStreamLengthSync
// Address: 0x803DD91C, Size: 40
void cbForGetStreamLengthSync() {
}

// cbForChangeDiskSync
// Address: 0x803DDCD0, Size: 36
void cbForChangeDiskSync() {
}

// cbForStopMotorSync
// Address: 0x803DDE64, Size: 36
void cbForStopMotorSync() {
}

// cbForInquirySync
// Address: 0x803DE020, Size: 36
void cbForInquirySync() {
}

// cbForCancelSync
// Address: 0x803DE54C, Size: 36
void cbForCancelSync() {
}

// cbForCancelAllSync
// Address: 0x803DE794, Size: 44
void cbForCancelAllSync() {
}

// PopWaitingQueuePrio
// Address: 0x803DEAB4, Size: 100
void PopWaitingQueuePrio() {
}

// ErrorCode2Num
// Address: 0x803DEE48, Size: 284
void ErrorCode2Num() {
}

// Convert
// Address: 0x803DEF64, Size: 352
void Convert() {
}

// strnlen
// Address: 0x803DF140, Size: 56
void strnlen() {
}

// ShowMessage
// Address: 0x803DF2F0, Size: 140
void ShowMessage() {
}

// cb
// Address: 0x803DF41C, Size: 216
void cb() {
}

// ProcessNextCommand
// Address: 0x803DF69C, Size: 148
void ProcessNextCommand() {
}

// AlarmHandlerForTimeout
// Address: 0x803DFA94, Size: 112
void AlarmHandlerForTimeout() {
}

// SetTimeoutAlarm
// Address: 0x803DFB04, Size: 100
void SetTimeoutAlarm() {
}

// Read
// Address: 0x803DFB68, Size: 272
void Read() {
}

// AudioBufferOn
// Address: 0x803DFC78, Size: 56
void AudioBufferOn() {
}

// HitCache
// Address: 0x803DFCB0, Size: 160
void HitCache() {
}

// DoJustRead
// Address: 0x803DFD50, Size: 52
void DoJustRead() {
}

// SeekTwiceBeforeRead
// Address: 0x803DFD84, Size: 128
void SeekTwiceBeforeRead() {
}

// WaitBeforeRead
// Address: 0x803DFE04, Size: 140
void WaitBeforeRead() {
}

// DoBreak
// Address: 0x803E0700, Size: 28
void DoBreak() {
}

// AlarmHandlerForBreak
// Address: 0x803E071C, Size: 116
void AlarmHandlerForBreak() {
}

// SetBreakAlarm
// Address: 0x803E0790, Size: 100
void SetBreakAlarm() {
}

// getEncoderType
// Address: 0x803E0934, Size: 8
void getEncoderType() {
}

// cntlzd
// Address: 0x803E093C, Size: 92
void cntlzd() {
}

// getTiming
// Address: 0x803E0DC4, Size: 168
void getTiming() {
}

// AdjustPosition
// Address: 0x803E1070, Size: 352
void AdjustPosition() {
}

// ImportAdjustingValues
// Address: 0x803E11D0, Size: 60
void ImportAdjustingValues() {
}

// setInterruptRegs
// Address: 0x803E1710, Size: 124
void setInterruptRegs() {
}

// setPicConfig
// Address: 0x803E178C, Size: 152
void setPicConfig() {
}

// setBBIntervalRegs
// Address: 0x803E1824, Size: 188
void setBBIntervalRegs() {
}

// setScalingRegs
// Address: 0x803E18E0, Size: 156
void setScalingRegs() {
}

// calcFbbs
// Address: 0x803E197C, Size: 128
void calcFbbs() {
}

// setFbbRegs
// Address: 0x803E19FC, Size: 724
void setFbbRegs() {
}

// setHorizontalRegs
// Address: 0x803E1CD0, Size: 204
void setHorizontalRegs() {
}

// setVerticalRegs
// Address: 0x803E1D9C, Size: 416
void setVerticalRegs() {
}

// PrintDebugPalCaution
// Address: 0x803E1F3C, Size: 148
void PrintDebugPalCaution() {
}

// GetCurrentDisplayPosition
// Address: 0x803E2F08, Size: 60
void GetCurrentDisplayPosition() {
}

// getCurrentHalfLine
// Address: 0x803E2F44, Size: 80
void getCurrentHalfLine() {
}

// getCurrentFieldEvenOdd
// Address: 0x803E2F94, Size: 104
void getCurrentFieldEvenOdd() {
}

// DoReset
// Address: 0x803E3BF0, Size: 112
void DoReset() {
}

// UpdateOrigin
// Address: 0x803E3C60, Size: 420
void UpdateOrigin() {
}

// SPEC0_MakeStatus
// Address: 0x803E4D58, Size: 372
void SPEC0_MakeStatus() {
}

// SPEC1_MakeStatus
// Address: 0x803E4ECC, Size: 372
void SPEC1_MakeStatus() {
}

// ClampS8
// Address: 0x803E5040, Size: 84
void ClampS8() {
}

// ClampU8
// Address: 0x803E5094, Size: 28
void ClampU8() {
}

// SPEC2_MakeStatus
// Address: 0x803E50B0, Size: 1136
void SPEC2_MakeStatus() {
}

// SamplingHandler
// Address: 0x803E5734, Size: 96
void SamplingHandler() {
}

// AIRegisterDMACallback
// Address: 0x803E591C, Size: 68
void AIRegisterDMACallback() {
}

// AIInitDMA
// Address: 0x803E5960, Size: 136
void AIInitDMA() {
}

// AIGetDMAEnableFlag
// Address: 0x803E59E8, Size: 16
void AIGetDMAEnableFlag() {
}

// AIStartDMA
// Address: 0x803E59F8, Size: 24
void AIStartDMA() {
}

// AIStopDMA
// Address: 0x803E5A10, Size: 24
void AIStopDMA() {
}

// AIGetDMABytesLeft
// Address: 0x803E5A28, Size: 16
void AIGetDMABytesLeft() {
}

// AIGetDMAStartAddr
// Address: 0x803E5A38, Size: 28
void AIGetDMAStartAddr() {
}

// AIGetDMALength
// Address: 0x803E5A54, Size: 16
void AIGetDMALength() {
}

// AICheckInit
// Address: 0x803E5A64, Size: 8
void AICheckInit() {
}

// AIRegisterStreamCallback
// Address: 0x803E5A6C, Size: 68
void AIRegisterStreamCallback() {
}

// AIGetStreamSampleCount
// Address: 0x803E5AB0, Size: 16
void AIGetStreamSampleCount() {
}

// AIResetStreamSampleCount
// Address: 0x803E5AC0, Size: 24
void AIResetStreamSampleCount() {
}

// AISetStreamTrigger
// Address: 0x803E5AD8, Size: 12
void AISetStreamTrigger() {
}

// AIGetStreamTrigger
// Address: 0x803E5AE4, Size: 16
void AIGetStreamTrigger() {
}

// AISetStreamPlayState
// Address: 0x803E5AF4, Size: 216
void AISetStreamPlayState() {
}

// AIGetStreamPlayState
// Address: 0x803E5BCC, Size: 16
void AIGetStreamPlayState() {
}

// AISetDSPSampleRate
// Address: 0x803E5BDC, Size: 224
void AISetDSPSampleRate() {
}

// AIGetDSPSampleRate
// Address: 0x803E5CBC, Size: 20
void AIGetDSPSampleRate() {
}

// AISetStreamSampleRate
// Address: 0x803E5CD0, Size: 40
void AISetStreamSampleRate() {
}

// AIGetStreamSampleRate
// Address: 0x803E5DEC, Size: 16
void AIGetStreamSampleRate() {
}

// AISetStreamVolLeft
// Address: 0x803E5DFC, Size: 28
void AISetStreamVolLeft() {
}

// AIGetStreamVolLeft
// Address: 0x803E5E18, Size: 16
void AIGetStreamVolLeft() {
}

// AISetStreamVolRight
// Address: 0x803E5E28, Size: 28
void AISetStreamVolRight() {
}

// AIGetStreamVolRight
// Address: 0x803E5E44, Size: 16
void AIGetStreamVolRight() {
}

// AIInit
// Address: 0x803E5E54, Size: 364
void AIInit() {
}

// AIReset
// Address: 0x803E5FC0, Size: 12
void AIReset() {
}

// AMC_IsStub
// Address: 0x803E6360, Size: 8
void AMC_IsStub() {
}

// DBClose
// Address: 0x803E6368, Size: 4
void DBClose() {
}

// DBOpen
// Address: 0x803E636C, Size: 4
void DBOpen() {
}

// DBWrite
// Address: 0x803E6370, Size: 608
void DBWrite() {
}

// DBRead
// Address: 0x803E65D0, Size: 140
void DBRead() {
}

// DBQueryData
// Address: 0x803E665C, Size: 156
void DBQueryData() {
}

// CheckMailBox
// Address: 0x803E66F8, Size: 336
void CheckMailBox() {
}

// DBInitInterrupts
// Address: 0x803E6848, Size: 84
void DBInitInterrupts() {
}

// DBInitComm
// Address: 0x803E689C, Size: 120
void DBInitComm() {
}

// DBGHandler
// Address: 0x803E6914, Size: 64
void DBGHandler() {
}

// MWCallback
// Address: 0x803E6954, Size: 60
void MWCallback() {
}

// DBGReadStatus
// Address: 0x803E6990, Size: 172
void DBGReadStatus() {
}

// DBGWrite
// Address: 0x803E6A3C, Size: 220
void DBGWrite() {
}

// DBGRead
// Address: 0x803E6B18, Size: 220
void DBGRead() {
}

// DBGReadMailbox
// Address: 0x803E6BF4, Size: 172
void DBGReadMailbox() {
}

// DBGWriteMailbox
// Address: 0x803E6CA0, Size: 140
void DBGWriteMailbox() {
}

// DBGCheckID
// Address: 0x803E6D2C, Size: 172
void DBGCheckID() {
}

// DBGEXIClearInterrupts
// Address: 0x803E6DD8, Size: 24
void DBGEXIClearInterrupts() {
}

// DBGEXIImm
// Address: 0x803E6DF0, Size: 664
void DBGEXIImm() {
}

// DBGEXISync
// Address: 0x803E7088, Size: 28
void DBGEXISync() {
}

// DBGEXIDeselect
// Address: 0x803E70A4, Size: 28
void DBGEXIDeselect() {
}

// DBGEXISelect
// Address: 0x803E70C0, Size: 40
void DBGEXISelect() {
}

// DBGEXIInit
// Address: 0x803E70E8, Size: 52
void DBGEXIInit() {
}

// CleanAllNativeFunctions(void)
// Address: 0x803E7B80, Size: 76
void CleanAllNativeFunctions() {
}

// GlobalNotificationFunction(AptSharedPtr<AptFile>)
// Address: 0x8041FBE8, Size: 1752
void GlobalNotificationFunction() {
}
