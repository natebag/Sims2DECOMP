/*
 * global_chunk_4.cpp - global.cpp functions (lines 138670-230640, ~489 functions)
 *
 * Fourth quarter of the global.cpp asm decomp conversion.
 * Contains: CARD memory card API, GX graphics API, VM virtual memory,
 * THP video decode, GD display list, save/restore register trampolines,
 * VMBASE virtual memory base layer, STL template instantiations
 * (sort/heap/find/partition), and game-specific serialization templates
 * (ReconLoadObject, ReconSaveObject, DoContainerStream, FindRes, etc.)
 *
 * SDK library functions use hardware-specific instructions (SDA access,
 * crypto LFSRs, register-level I/O) that cannot match with GCC, so they
 * remain as asm stubs with portable C signatures documented.
 *
 * STL and game template functions are converted to portable C++.
 */

#include "types.h"

/* Forward declarations */
struct CARDFileInfo;
struct GXFifoObj;
struct GXRenderModeObj;
struct GXLightObj;
struct GXTexObj;
struct GXTexRegion;
struct GXTlutObj;
struct GXTlutRegion;
typedef struct { u8 r, g, b, a; } GXColor;
typedef struct { s16 r, g, b, a; } GXColorS10;
typedef f32 Mtx[3][4];
typedef f32 Mtx44[4][4];
typedef f32 Vec[3];
struct OSThread;
struct OSAlarm;
struct OSContext;
struct DVDFileInfo;
struct DVDCommandBlock;
struct PADStatus;
struct DSPTask;
struct ARQRequest;
struct THPVideoInfo;

/* Game types */
class EStream;
class EFile;
class iResFile;
class ReconBuffer;
class ReconBuilder;
class ReconObject;
namespace Memory { struct HandleNode; }
class Neighbor;
class RelationsCmp;
class ObjSelector;
class FamilyImpl;
class Family;
class CasSimDescriptionS2C;
class ObjectSaveTypeTable;
class ObjectSaveTypeTable2;
class ObjectSaveTypeTable3;
class ObjectSaveIDTable;
class ObjectFolderImpl;
class ObjectModuleImpl;
class cSimulator;
class UserDataSaveLoad;
class ThumbnailLoader;
class OptionsRecon;
class HouseImpl;
class NeighborhoodImpl;
class FamilyImpl;
class CasCostumes;
class CasGenetics;
class SlotDescriptor;
class IFFResNode;
class IFFResList;
class IFFResMap;
class XRoute;
struct ObjectRecord;
struct MotiveInc;
struct ScoredInteraction;
struct FamilyMember;
struct RelInt;
class RelArray;
class CTilePt;
class EInstance;
class EFontCharacter;
class EFontPage;
class EFontSize;
template<class T> class TNodeList;
template<class K, class V> class THashTable;
template<class K, class V> class TRedBlackTree;
template<class T, class A> class TArray;
class TArrayDefaultAllocator;
class TArrayERCharacterAllocator;
class TArrayERModelAllocator;
struct BSplineVolume;
struct ENDummy;
struct ENCamera;
struct SimsLightInfo;
class EResourceManager;
class EAHeap;

/* Callback typedefs */
typedef void (*CARDCallback)(s32 chan, s32 result);
typedef void (*GXBreakPtCallback)(void);
typedef void (*GXDrawSyncCallback)(u16 token);
typedef void (*GXDrawDoneCallback)(void);

/* ======================================================================
 * CARD - Memory Card API (DolphinSDK)
 *
 * Functions 1-69: CARDCheckExAsync through __CARDSetStatusEx
 * These use SDA-relative globals, EXI hardware access, and crypto
 * operations that require asm. Kept as asm stubs.
 * ====================================================================== */

// 0x80381B10 (1424 bytes)
// CARDCheckExAsync - validates memory card directory/FAT integrity
// s32 CARDCheckExAsync(s32 chan, s32* xferBytes, CARDCallback callback);
// NON_MATCHING: SDA access, complex FAT/dir verification loop, hardware I/O
extern "C" void CARDCheckExAsync();

// 0x803820C8 (92 bytes)
// CARDCheckEx - synchronous wrapper for CARDCheckExAsync
// s32 CARDCheckEx(s32 chan, s32* xferBytes);
extern "C" void CARDCheckEx();

// 0x80382124 (84 bytes)
// CARDCheck - simplified check (no xferBytes output)
// s32 CARDCheck(s32 chan);
extern "C" void CARDCheck();

// 0x80382178 (204 bytes)
// IsCard - checks if EXI device ID identifies a memory card
// BOOL IsCard(u32 id);
extern "C" void IsCard();

// 0x80382244 (84 bytes)
// __CARDDisable - disables memory card hardware interrupts
// void __CARDDisable(s32 chan);
extern "C" void __CARDDisable();

// 0x803822D0 (380 bytes)
// CARDProbeEx - probes memory card slot, returns memory size and sector size
// s32 CARDProbeEx(s32 chan, s32* memSize, s32* sectorSize);
extern "C" void CARDProbeEx();

// 0x8038244C (1108 bytes)
// DoMount - internal mount implementation, reads card ID and header blocks
// s32 DoMount(s32 chan);
extern "C" void DoMount();

// 0x803828A0 (312 bytes)
// __CARDMountCallback - async callback for mount state machine
// void __CARDMountCallback(s32 chan, s32 result);
extern "C" void __CARDMountCallback();

// 0x803829D8 (416 bytes)
// CARDMountAsync - begins asynchronous memory card mount
// s32 CARDMountAsync(s32 chan, void* workArea, void* unusedArea,
//                     CARDCallback detachCallback, CARDCallback attachCallback);
extern "C" void CARDMountAsync();

// 0x80382B78 (72 bytes)
// CARDMount - synchronous mount
// s32 CARDMount(s32 chan, void* workArea, void* unusedArea, CARDCallback detachCb);
extern "C" void CARDMount();

// 0x80382BC0 (156 bytes)
// DoUnmount - internal unmount implementation
// void DoUnmount(s32 chan, s32 result);
extern "C" void DoUnmount();

// 0x80382C5C (172 bytes)
// CARDUnmount - unmounts a memory card
// s32 CARDUnmount(s32 chan);
extern "C" void CARDUnmount();

// 0x80382D08 (324 bytes)
// FormatCallback - callback for format state machine
// void FormatCallback(s32 chan, s32 result);
extern "C" void FormatCallback();

// 0x80382E4C (1624 bytes)
// __CARDFormatRegionAsync - formats card with region-specific encoding
// s32 __CARDFormatRegionAsync(s32 chan, u16 encode, CARDCallback callback);
extern "C" void __CARDFormatRegionAsync();

// 0x803834A4 (72 bytes)
// __CARDFormatRegion - synchronous format with region encoding
// s32 __CARDFormatRegion(s32 chan, u16 encode);
extern "C" void __CARDFormatRegion();

// 0x803834EC (72 bytes)
// CARDFormatAsync - async format using system font encoding
// s32 CARDFormatAsync(s32 chan, CARDCallback callback);
extern "C" void CARDFormatAsync();

// 0x80383534 (84 bytes)
// CARDFormat - synchronous format
// s32 CARDFormat(s32 chan);
extern "C" void CARDFormat();

// 0x80383588 (104 bytes)
// __CARDCompareFileName - compares card entry filename with target
// BOOL __CARDCompareFileName(void* dirEntry, const char* fileName);
extern "C" void __CARDCompareFileName();

// 0x803835F0 (148 bytes)
// __CARDAccess - checks file access permissions
// s32 __CARDAccess(void* card, void* dirEntry);
extern "C" void __CARDAccess();

// 0x80383684 (308 bytes)
// __CARDIsWritable - checks if file is writable by current game
// s32 __CARDIsWritable(void* card, void* dirEntry);
extern "C" void __CARDIsWritable();

// 0x803837B8 (244 bytes)
// __CARDIsReadable - checks if file is readable by current game
// s32 __CARDIsReadable(void* card, void* dirEntry);
extern "C" void __CARDIsReadable();

// 0x803838AC (336 bytes)
// __CARDGetFileNo - finds file number by filename
// s32 __CARDGetFileNo(void* card, const char* fileName, s32* fileNo);
extern "C" void __CARDGetFileNo();

// 0x803839FC (260 bytes)
// CARDFastOpen - opens file by file number (skips filename search)
// s32 CARDFastOpen(s32 chan, s32 fileNo, CARDFileInfo* fileInfo);
extern "C" void CARDFastOpen();

// 0x80383B00 (284 bytes)
// CARDOpen - opens file by filename
// s32 CARDOpen(s32 chan, const char* fileName, CARDFileInfo* fileInfo);
extern "C" void CARDOpen();

// 0x80383C1C (84 bytes)
// CARDClose - closes an open file
// s32 CARDClose(CARDFileInfo* fileInfo);
extern "C" void CARDClose();

// 0x80383C78 (304 bytes)
// CreateCallbackFat - callback for create state machine FAT update
// void CreateCallbackFat(s32 chan, s32 result);
extern "C" void CreateCallbackFat();

// 0x80383DA8 (544 bytes)
// CARDCreateAsync - async file creation
// s32 CARDCreateAsync(s32 chan, const char* fileName, u32 size,
//                      CARDFileInfo* fileInfo, CARDCallback callback);
extern "C" void CARDCreateAsync();

// 0x80383FC8 (72 bytes)
// CARDCreate - synchronous file creation
// s32 CARDCreate(s32 chan, const char* fileName, u32 size, CARDFileInfo* fileInfo);
extern "C" void CARDCreate();

// 0x80384010 (440 bytes)
// __CARDSeek - seeks to position within an open file
// s32 __CARDSeek(CARDFileInfo* fileInfo, s32 length, s32 offset, void** outAddr);
extern "C" void __CARDSeek();

// 0x803841C8 (304 bytes)
// ReadCallback - callback for async read state machine
// void ReadCallback(s32 chan, s32 result);
extern "C" void ReadCallback();

// 0x803842F8 (324 bytes)
// CARDReadAsync - async file read
// s32 CARDReadAsync(CARDFileInfo* fileInfo, void* buf, s32 length,
//                    s32 offset, CARDCallback callback);
extern "C" void CARDReadAsync();

// 0x8038443C (72 bytes)
// CARDRead - synchronous file read
// s32 CARDRead(CARDFileInfo* fileInfo, void* buf, s32 length, s32 offset);
extern "C" void CARDRead();

// 0x80384484 (140 bytes)
// CARDCancel - cancels pending async operation
// s32 CARDCancel(CARDFileInfo* fileInfo);
extern "C" void CARDCancel();

// 0x80384510 (368 bytes)
// WriteCallback - callback for async write state machine
// void WriteCallback(s32 chan, s32 result);
extern "C" void WriteCallback();

// 0x80384680 (176 bytes)
// EraseCallback - callback for async erase state machine
// void EraseCallback(s32 chan, s32 result);
extern "C" void EraseCallback();

// 0x80384730 (276 bytes)
// CARDWriteAsync - async file write
// s32 CARDWriteAsync(CARDFileInfo* fileInfo, const void* buf, s32 length,
//                     s32 offset, CARDCallback callback);
extern "C" void CARDWriteAsync();

// 0x80384844 (72 bytes)
// CARDWrite - synchronous file write
// s32 CARDWrite(CARDFileInfo* fileInfo, const void* buf, s32 length, s32 offset);
extern "C" void CARDWrite();

// 0x8038488C (164 bytes)
// DeleteCallback - callback for async delete state machine
// void DeleteCallback(s32 chan, s32 result);
extern "C" void DeleteCallback();

// 0x80384930 (300 bytes)
// CARDFastDeleteAsync - async delete by file number
// s32 CARDFastDeleteAsync(s32 chan, s32 fileNo, CARDCallback callback);
extern "C" void CARDFastDeleteAsync();

// 0x80384A5C (72 bytes)
// CARDFastDelete - synchronous delete by file number
// s32 CARDFastDelete(s32 chan, s32 fileNo);
extern "C" void CARDFastDelete();

// 0x80384AA4 (272 bytes)
// CARDDeleteAsync - async delete by filename
// s32 CARDDeleteAsync(s32 chan, const char* fileName, CARDCallback callback);
extern "C" void CARDDeleteAsync();

// 0x80384BB4 (72 bytes)
// CARDDelete - synchronous delete by filename
// s32 CARDDelete(s32 chan, const char* fileName);
extern "C" void CARDDelete();

// 0x80384BFC (504 bytes)
// UpdateIconOffsets - recalculates icon data offsets in card directory entry
// void UpdateIconOffsets(void* dirEntry);
extern "C" void UpdateIconOffsets();

// 0x80384DF4 (276 bytes)
// CARDGetStatus - reads file status (size, attributes, etc.)
// s32 CARDGetStatus(s32 chan, s32 fileNo, void* stat);
extern "C" void CARDGetStatus();

// 0x80384F08 (372 bytes)
// CARDSetStatusAsync - async status update
// s32 CARDSetStatusAsync(s32 chan, s32 fileNo, void* stat, CARDCallback callback);
extern "C" void CARDSetStatusAsync();

// 0x8038507C (72 bytes)
// CARDSetStatus - synchronous status update
// s32 CARDSetStatus(s32 chan, s32 fileNo, void* stat);
extern "C" void CARDSetStatus();

// 0x803850DC (196 bytes)
// CARDGetSerialNo - gets memory card serial number
// s32 CARDGetSerialNo(s32 chan, u64* serialNo);
extern "C" void CARDGetSerialNo();

// 0x803851A0 (148 bytes)
// CARDGetUniqueCode - gets unique code from SRAM
// s32 CARDGetUniqueCode(s32 chan, u8* code, s32 codeLen);
extern "C" void CARDGetUniqueCode();

// 0x80385274 (228 bytes)
// CARDSetAttributesAsync - async attribute set
// s32 CARDSetAttributesAsync(s32 chan, s32 fileNo, u8 attr, CARDCallback callback);
extern "C" void CARDSetAttributesAsync();

// 0x80385358 (72 bytes)
// CARDSetAttributes - synchronous attribute set
// s32 CARDSetAttributes(s32 chan, s32 fileNo, u8 attr);
extern "C" void CARDSetAttributes();

// 0x803853A0 (72 bytes)
// __CARDEnablePerm - enable/disable permanent file attribute
// BOOL __CARDEnablePerm(u8 mask, BOOL enable);
extern "C" void __CARDEnablePerm();

// 0x803853E8 (68 bytes)
// __CARDEnableGlobal - enable/disable global file access
// BOOL __CARDEnableGlobal(BOOL enable);
extern "C" void __CARDEnableGlobal();

// 0x8038542C (68 bytes)
// __CARDEnableCompany - enable/disable company-restricted access
// BOOL __CARDEnableCompany(BOOL enable);
extern "C" void __CARDEnableCompany();

// 0x8038549C (372 bytes)
// exnor_1st - first stage of EXNOR LFSR for card crypto
extern "C" void exnor_1st();

// 0x80385610 (372 bytes)
// exnor - EXNOR LFSR step for card crypto
extern "C" void exnor();

// 0x80385784 (364 bytes)
// bitrev - bit reversal for card crypto
extern "C" void bitrev();

// 0x803858F0 (324 bytes)
// ReadArrayUnlock - reads array data during card unlock sequence
extern "C" void ReadArrayUnlock();

// 0x80385A34 (84 bytes)
// GetInitVal - gets initial LFSR value from tick counter
extern "C" void GetInitVal();

// 0x80385A88 (196 bytes)
// DummyLen - generates pseudo-random length for unlock timing jitter
extern "C" void DummyLen();

// 0x80385B4C (2904 bytes)
// __CARDUnlock - performs memory card authentication/unlock sequence
// NON_MATCHING: LFSR crypto, bitrev, complex state machine
extern "C" void __CARDUnlock();

// 0x803866A4 (112 bytes)
// InitCallback - card block I/O initialization callback
extern "C" void InitCallback();

// 0x80386714 (804 bytes)
// DoneCallback - card block I/O completion callback
extern "C" void DoneCallback();

// 0x80386A38 (220 bytes)
// BlockReadCallback - low-level block read completion
extern "C" void BlockReadCallback();

// 0x80386B14 (100 bytes)
// __CARDRead - internal block read
extern "C" void __CARDRead();

// 0x80386B78 (232 bytes)
// BlockWriteCallback - low-level block write completion
extern "C" void BlockWriteCallback();

// 0x80386C60 (104 bytes)
// __CARDWrite - internal block write
extern "C" void __CARDWrite();

// 0x80386CE0 (164 bytes)
// __CARDGetStatusEx - reads extended file status
extern "C" void __CARDGetStatusEx();

// 0x80386D84 (668 bytes)
// __CARDSetStatusExAsync - async extended status write
extern "C" void __CARDSetStatusExAsync();

// 0x80387020 (72 bytes)
// __CARDSetStatusEx - synchronous extended status write
extern "C" void __CARDSetStatusEx();

/* ======================================================================
 * GX - Graphics Library (DolphinSDK)
 *
 * Functions 70-237: __GXDefaultTexRegionCallback through GXReadXfRasMetric
 * Hardware register access, FIFO manipulation, and pipeline state
 * that requires asm.
 * ====================================================================== */

// 0x803870E0 (252 bytes)
extern "C" void __GXDefaultTexRegionCallback();

// 0x80387200 (400 bytes)
extern "C" void __GXShutdown();

// 0x80387390 (420 bytes)
extern "C" void __GXInitRevisionBits();

// 0x80387534 (1536 bytes)
// GXInit - initializes the graphics subsystem
extern "C" void GXInit();

// 0x80387B34 (2360 bytes)
// __GXInitGX - sets default GX state
extern "C" void __GXInitGX();

// 0x8038846C (80 bytes)
extern "C" void GXOverflowHandler();

// 0x803884BC (68 bytes)
extern "C" void GXUnderflowHandler();

// 0x80388500 (128 bytes)
extern "C" void GXBreakPointHandler();

// 0x80388580 (308 bytes)
extern "C" void GXCPInterruptHandler();

// 0x803886B4 (108 bytes)
extern "C" void GXInitFifoBase();

// 0x80388720 (112 bytes)
extern "C" void GXInitFifoPtrs();

// 0x8038879C (296 bytes)
extern "C" void GXSetCPUFifo();

// 0x803888C4 (376 bytes)
extern "C" void GXSetGPFifo();

// 0x80388A70 (200 bytes)
extern "C" void __GXSaveCPUFifoAux();

// 0x80388B68 (80 bytes)
extern "C" void GXGetGPStatus();

// 0x80388BB8 (276 bytes)
extern "C" void GXGetFifoStatus();

// 0x80388CCC (152 bytes)
extern "C" void GXGetFifoPtrs();

// 0x80388D88 (68 bytes)
extern "C" void GXSetBreakPtCallback();

// 0x80388DCC (140 bytes)
extern "C" void GXEnableBreakPt();

// 0x80388E58 (84 bytes)
extern "C" void GXDisableBreakPt();

// 0x80388EAC (76 bytes)
extern "C" void __GXFifoInit();

// 0x80389004 (256 bytes)
extern "C" void __GXCleanGPFifo();

// 0x80389104 (76 bytes)
extern "C" void GXSetCurrentGXThread();

// 0x80389180 (264 bytes)
extern "C" void GXRedirectWriteGatherPipe();

// 0x80389288 (416 bytes)
extern "C" void GXRestoreWriteGatherPipe();

// 0x80389428 (140 bytes)
extern "C" void __GXXfVtxSpecs();

// 0x803894B4 (620 bytes)
extern "C" void GXSetVtxDesc();

// 0x80389720 (648 bytes)
extern "C" void GXSetVtxDescv();

// 0x803899A8 (188 bytes)
extern "C" void __GXSetVCD();

// 0x80389A64 (292 bytes)
extern "C" void __GXCalculateVLim();

// 0x80389B88 (436 bytes)
extern "C" void GXGetVtxDesc();

// 0x80389D3C (144 bytes)
extern "C" void GXGetVtxDescv();

// 0x80389E04 (604 bytes)
extern "C" void GXSetVtxAttrFmt();

// 0x8038A060 (640 bytes)
extern "C" void GXSetVtxAttrFmtv();

// 0x8038A2E0 (136 bytes)
extern "C" void __GXSetVAT();

// 0x8038A368 (640 bytes)
extern "C" void GXGetVtxAttrFmt();

// 0x8038A5E8 (116 bytes)
extern "C" void GXGetVtxAttrFmtv();

// 0x8038A65C (68 bytes)
extern "C" void GXSetArray();

// 0x8038A6B0 (640 bytes)
extern "C" void GXSetTexCoordGen2();

// 0x8038A96C (148 bytes)
extern "C" void GXSetMisc();

// 0x8038AA00 (92 bytes)
extern "C" void GXFlush();

// 0x8038AA90 (124 bytes)
extern "C" void __GXAbortWait();

// 0x8038AB0C (196 bytes)
extern "C" void __GXAbortWaitPECopyDone();

// 0x8038ABD0 (364 bytes)
extern "C" void __GXAbort();

// 0x8038AD3C (456 bytes)
extern "C" void GXAbortFrame();

// 0x8038AF04 (180 bytes)
extern "C" void GXSetDrawSync();

// 0x8038AFC4 (152 bytes)
extern "C" void GXSetDrawDone();

// 0x8038B05C (76 bytes)
extern "C" void GXWaitDrawDone();

// 0x8038B0A8 (128 bytes)
extern "C" void GXDrawDone();

// 0x8038B1BC (100 bytes)
extern "C" void GXPokeBlendMode();

// 0x8038B31C (68 bytes)
extern "C" void GXSetDrawSyncCallback();

// 0x8038B360 (136 bytes)
extern "C" void GXTokenInterruptHandler();

// 0x8038B3E8 (68 bytes)
extern "C" void GXSetDrawDoneCallback();

// 0x8038B42C (128 bytes)
extern "C" void GXFinishInterruptHandler();

// 0x8038B4AC (116 bytes)
extern "C" void __GXPEInit();

// 0x8038B520 (308 bytes)
extern "C" void GXCompressZ16();

// 0x8038B654 (284 bytes)
extern "C" void GXDecompressZ16();

// 0x8038B770 (128 bytes)
extern "C" void __GXSetDirtyState();

// 0x8038B7F0 (208 bytes)
extern "C" void GXBegin();

// 0x8038B8C0 (136 bytes)
extern "C" void __GXSendFlushPrim();

// 0x8038BA04 (72 bytes)
extern "C" void GXEnableTexOffsets();

// 0x8038BAE8 (324 bytes)
extern "C" void GXAdjustForOverscan();

// 0x8038BC2C (124 bytes)
extern "C" void GXSetDispCopySrc();

// 0x8038BCA8 (124 bytes)
extern "C" void GXSetTexCopySrc();

// 0x8038BD58 (304 bytes)
extern "C" void GXSetTexCopyDst();

// 0x8038BEAC (88 bytes)
extern "C" void GXSetCopyClamp();

// 0x8038BF04 (88 bytes)
extern "C" void __GXGetNumXfbLines();

// 0x8038BF5C (144 bytes)
extern "C" void GXGetNumXfbLines();

// 0x8038BFEC (568 bytes)
extern "C" void GXGetYScaleFactor();

// 0x8038C224 (204 bytes)
extern "C" void GXSetDispCopyYScale();

// 0x8038C2F0 (120 bytes)
extern "C" void GXSetCopyClear();

// 0x8038C368 (520 bytes)
extern "C" void GXSetCopyFilter();

// 0x8038C584 (360 bytes)
extern "C" void GXCopyDisp();

// 0x8038C6EC (396 bytes)
extern "C" void GXCopyTex();

// 0x8038C958 (400 bytes)
extern "C" void GXInitLightSpot();

// 0x8038CAE8 (208 bytes)
extern "C" void GXInitLightDistAttn();

// 0x8038CC28 (228 bytes)
extern "C" void GXInitSpecularDir();

// 0x8038CD50 (124 bytes)
extern "C" void GXLoadLightObjImm();

// 0x8038CDCC (72 bytes)
extern "C" void GXLoadLightObjIndx();

// 0x8038CE14 (232 bytes)
extern "C" void GXSetChanAmbColor();

// 0x8038CEFC (232 bytes)
extern "C" void GXSetChanMatColor();

// 0x8038D020 (176 bytes)
extern "C" void GXSetChanCtrl();

// 0x8038D0D0 (100 bytes)
extern "C" void __GXGetTexTileShift();

// 0x8038D134 (348 bytes)
extern "C" void GXGetTexBufferSize();

// 0x8038D290 (200 bytes)
extern "C" void __GetImageTileCount();

// 0x8038D358 (588 bytes)
extern "C" void GXInitTexObj();

// 0x8038D5A4 (72 bytes)
extern "C" void GXInitTexObjCI();

// 0x8038D5EC (356 bytes)
extern "C" void GXInitTexObjLOD();

// 0x8038D7BC (80 bytes)
extern "C" void GXInitTexObjMaxLOD();

// 0x8038D80C (80 bytes)
extern "C" void GXInitTexObjMinLOD();

// 0x8038D85C (84 bytes)
extern "C" void GXInitTexObjLODBias();

// 0x8038D908 (104 bytes)
extern "C" void GXGetTexObjAll();

// 0x8038D9D4 (228 bytes)
extern "C" void GXGetTexObjLODAll();

// 0x8038DBB4 (380 bytes)
extern "C" void GXLoadTexObjPreLoaded();

// 0x8038DD30 (84 bytes)
extern "C" void GXLoadTexObj();

// 0x8038DE00 (152 bytes)
extern "C" void GXLoadTlut();

// 0x8038DE98 (244 bytes)
extern "C" void GXInitTexCacheRegion();

// 0x8038DF8C (132 bytes)
extern "C" void GXInitTexPreLoadRegion();

// 0x8038E010 (268 bytes)
extern "C" void GXGetTexRegionAll();

// 0x8038E174 (300 bytes)
extern "C" void GXInvalidateTexRegion();

// 0x8038E2A0 (72 bytes)
extern "C" void GXInvalidateTexAll();

// 0x8038E310 (612 bytes)
extern "C" void GXPreLoadEntireTexture();

// 0x8038E574 (124 bytes)
extern "C" void GXSetTexCoordScaleManually();

// 0x8038E5F0 (100 bytes)
extern "C" void GXSetTexCoordCylWrap();

// 0x8038E654 (100 bytes)
extern "C" void GXSetTexCoordBias();

// 0x8038E6B8 (160 bytes)
extern "C" void __SetSURegs();

// 0x8038E758 (380 bytes)
extern "C" void __GXSetSUTexRegs();

// 0x8038E904 (852 bytes)
extern "C" void __GXSetTmemConfig();

// 0x8038EC58 (108 bytes)
extern "C" void GXSetTevIndirect();

// 0x8038ECC4 (376 bytes)
extern "C" void GXSetIndTexMtx();

// 0x8038EE3C (324 bytes)
extern "C" void GXSetIndTexCoordScale();

// 0x8038EF80 (236 bytes)
extern "C" void GXSetIndTexOrder();

// 0x8038F090 (72 bytes)
extern "C" void GXSetTevDirect();

// 0x8038F0D8 (100 bytes)
extern "C" void GXSetTevIndWarp();

// 0x8038F13C (428 bytes)
extern "C" void GXSetTevIndTile();

// 0x8038F2E8 (268 bytes)
extern "C" void GXSetTevIndBumpST();

// 0x8038F3F4 (68 bytes)
extern "C" void GXSetTevIndBumpXYZ();

// 0x8038F438 (72 bytes)
extern "C" void GXSetTevIndRepeat();

// 0x8038F4D8 (140 bytes)
extern "C" void GXSetTevOp();

// 0x8038F564 (68 bytes)
extern "C" void GXSetTevColorIn();

// 0x8038F5A8 (68 bytes)
extern "C" void GXSetTevAlphaIn();

// 0x8038F5EC (104 bytes)
extern "C" void GXSetTevColorOp();

// 0x8038F654 (104 bytes)
extern "C" void GXSetTevAlphaOp();

// 0x8038F6BC (96 bytes)
extern "C" void GXSetTevColor();

// 0x8038F71C (100 bytes)
extern "C" void GXSetTevColorS10();

// 0x8038F780 (100 bytes)
extern "C" void GXSetTevKColor();

// 0x8038F7E4 (92 bytes)
extern "C" void GXSetTevKColorSel();

// 0x8038F840 (92 bytes)
extern "C" void GXSetTevKAlphaSel();

// 0x8038F89C (72 bytes)
extern "C" void GXSetTevSwapMode();

// 0x8038F8E4 (128 bytes)
extern "C" void GXSetTevSwapModeTable();

// 0x8038F968 (68 bytes)
extern "C" void GXSetAlphaCompare();

// 0x8038F9AC (140 bytes)
extern "C" void GXSetZTexture();

// 0x8038FA38 (412 bytes)
extern "C" void GXSetTevOrder();

// 0x8038FBFC (532 bytes)
extern "C" void GXSetFog();

// 0x8038FFF0 (292 bytes)
extern "C" void GXInitFogAdjTable();

// 0x8038FE40 (432 bytes)
extern "C" void GXInitFogAdjTable();

// 0x80390114 (84 bytes)
extern "C" void GXSetFogRangeAdj();

// 0x80390228 (212 bytes)
extern "C" void GXSetPixelFmt();

// 0x8039039C (120 bytes)
extern "C" void GXSetFieldMode();

// 0x80390414 (204 bytes)
extern "C" void GXBeginDisplayList();

// 0x803904E0 (196 bytes)
extern "C" void GXEndDisplayList();

// 0x803905A4 (112 bytes)
extern "C" void GXCallDisplayList();

// 0x80390614 (372 bytes)
extern "C" void GXProject();

// 0x803907C0 (72 bytes)
extern "C" void __GXSetProjection();

// 0x80390808 (164 bytes)
extern "C" void GXSetProjection();

// 0x803908AC (140 bytes)
extern "C" void GXSetProjectionv();

// 0x80390938 (72 bytes)
extern "C" void GXGetProjectionv();

// 0x80390A38 (80 bytes)
extern "C" void GXLoadPosMtxImm();

// 0x80390AB8 (80 bytes)
extern "C" void GXLoadNrmMtxImm();

// 0x80390B08 (72 bytes)
extern "C" void GXLoadNrmMtxImm3x3();

// 0x80390BB8 (180 bytes)
extern "C" void GXLoadTexMtxImm();

// 0x80390C6C (88 bytes)
extern "C" void GXLoadTexMtxIndx();

// 0x80390CC4 (144 bytes)
extern "C" void __GXSetViewport();

// 0x80390D54 (88 bytes)
extern "C" void GXSetViewportJitter();

// 0x80390DAC (72 bytes)
extern "C" void GXSetViewport();

// 0x80390E18 (108 bytes)
extern "C" void GXSetZScaleOffset();

// 0x80390E84 (120 bytes)
extern "C" void GXSetScissor();

// 0x80390EFC (72 bytes)
extern "C" void GXGetScissor();

// 0x80390FAC (132 bytes)
extern "C" void __GXSetMatrixIndex();

// 0x80391030 (2120 bytes)
extern "C" void GXSetGPMetric();

// 0x80391878 (424 bytes)
extern "C" void GXReadGPMetric();

// 0x80391A88 (532 bytes)
extern "C" void GXReadMemMetric();

// 0x80391C9C (168 bytes)
extern "C" void GXClearMemMetric();

// 0x80391D44 (312 bytes)
extern "C" void GXReadPixMetric();

// 0x80391EAC (68 bytes)
extern "C" void GXSetVCacheMetric();

// 0x80391EF0 (148 bytes)
extern "C" void GXReadVCacheMetric();

// 0x80391FA0 (68 bytes)
extern "C" void GXInitXfRasMetric();

// 0x80391FE4 (196 bytes)
extern "C" void GXReadXfRasMetric();

/* ======================================================================
 * VM - Virtual Memory Manager (DolphinSDK)
 *
 * Functions 238-252: VMInit through __VMAllocARAMToVirtualLUT
 * Page table management, ARAM DMA, exception handlers.
 * ====================================================================== */

// 0x80392108 (156 bytes)
extern "C" void VMInit();

// 0x803921AC (104 bytes)
extern "C" void VMQuit();

// 0x803922A4 (508 bytes)
extern "C" void __VMSwapPageIn();

// 0x803924A0 (180 bytes)
extern "C" void __VMSwapPageOut();

// 0x803925AC (116 bytes)
extern "C" void VMInvalidateRange();

// 0x80392620 (296 bytes)
extern "C" void VMStoreOnePage();

// 0x80392768 (68 bytes)
extern "C" void __VMGetPageToReplace();

// 0x803927AC (464 bytes)
extern "C" void __VMPageReplacementLRU();

// 0x8039297C (148 bytes)
extern "C" void __VMPageReplacementRandom();

// 0x80392A10 (108 bytes)
extern "C" void __VMPageReplacementFIFO();

// 0x80392A7C (256 bytes)
extern "C" void VMAlloc();

// 0x80392B7C (264 bytes)
extern "C" void VMFree();

// 0x80392C84 (272 bytes)
extern "C" void VMFreeAll();

// 0x80392E80 (168 bytes)
extern "C" void __VMAllocVirtualToARAMLUT();

// 0x80392F28 (160 bytes)
extern "C" void __VMAllocARAMToVirtualLUT();

/* ======================================================================
 * THP - Video Decoder (DolphinSDK)
 *
 * Functions 253-273: THPVideoDecode through __THPAudioGetNewSample
 * JPEG-like decompression, Huffman tables, DCT.
 * ====================================================================== */

// 0x80392FC8 (580 bytes)
extern "C" void THPVideoDecode();

// 0x8039320C (68 bytes)
extern "C" void __THPSetupBuffers();

// 0x80393250 (316 bytes)
extern "C" void __THPReadFrameHeader();

// 0x8039338C (284 bytes)
extern "C" void __THPReadScaneHeader();

// 0x803934A8 (956 bytes)
extern "C" void __THPReadQuantizationTable();

// 0x80393864 (480 bytes)
extern "C" void __THPReadHuffmanTableSpecification();

// 0x80393A44 (240 bytes)
extern "C" void __THPHuffGenerateSizeTable();

// 0x80393B34 (104 bytes)
extern "C" void __THPHuffGenerateCodeTable();

// 0x80393B9C (444 bytes)
extern "C" void __THPHuffGenerateDecoderTables();

// 0x80393D58 (84 bytes)
extern "C" void __THPRestartDefinition();

// 0x80393DAC (588 bytes)
extern "C" void __THPPrepBitStream();

// 0x80393FF8 (268 bytes)
extern "C" void __THPDecompressYUV();

// 0x80394104 (6792 bytes)
extern "C" void __THPDecompressiMCURow512x448();

// 0x80395B8C (6796 bytes)
extern "C" void __THPDecompressiMCURow640x480();

// 0x80397618 (6828 bytes)
extern "C" void __THPDecompressiMCURowNxN();

// 0x803990C4 (1660 bytes)
extern "C" void __THPHuffDecodeDCTCompY();

// 0x80399740 (1704 bytes)
extern "C" void __THPHuffDecodeDCTCompU();

// 0x80399DE8 (1704 bytes)
extern "C" void __THPHuffDecodeDCTCompV();

// 0x8039A490 (160 bytes)
extern "C" void THPInit();

// 0x8039A530 (1124 bytes)
extern "C" void THPAudioDecode();

// 0x8039A994 (144 bytes)
extern "C" void __THPAudioGetNewSample();

/* ======================================================================
 * GD - Graphics Display List Utility
 * ====================================================================== */

// 0x8039AAA4 (248 bytes)
extern "C" void GDPadCurr32();

/* ======================================================================
 * Save/Restore Register Trampolines (SN Systems runtime)
 *
 * Functions 275-298: _savefpr_14 through _restgpr_19_x
 * These are compiler-generated register save/restore trampolines.
 * Must remain as asm - they use blr/b offsets that GCC generates differently.
 * ====================================================================== */

// 0x8039ABDC (76 bytes)
extern "C" void _savefpr_14();
// 0x8039ABE0 (72 bytes)
extern "C" void _savefpr_15();
// 0x8039ABE4 (68 bytes)
extern "C" void _savefpr_16();

// 0x8039AC28 (76 bytes)
extern "C" void _savegpr_14();
// 0x8039AC2C (72 bytes)
extern "C" void _savegpr_15();
// 0x8039AC30 (68 bytes)
extern "C" void _savegpr_16();

// 0x8039AC74 (76 bytes)
extern "C" void _restfpr_14();
// 0x8039AC78 (72 bytes)
extern "C" void _restfpr_15();
// 0x8039AC7C (68 bytes)
extern "C" void _restfpr_16();

// 0x8039ACC0 (76 bytes)
extern "C" void _restgpr_14();
// 0x8039ACC4 (72 bytes)
extern "C" void _restgpr_15();
// 0x8039ACC8 (68 bytes)
extern "C" void _restgpr_16();

// 0x8039AD0C (88 bytes)
extern "C" void _restfpr_14_x();
// 0x8039AD10 (84 bytes)
extern "C" void _restfpr_15_x();
// 0x8039AD14 (80 bytes)
extern "C" void _restfpr_16_x();
// 0x8039AD18 (76 bytes)
extern "C" void _restfpr_17_x();
// 0x8039AD1C (72 bytes)
extern "C" void _restfpr_18_x();
// 0x8039AD20 (68 bytes)
extern "C" void _restfpr_19_x();

// 0x8039AD64 (88 bytes)
extern "C" void _restgpr_14_x();
// 0x8039AD68 (84 bytes)
extern "C" void _restgpr_15_x();
// 0x8039AD6C (80 bytes)
extern "C" void _restgpr_16_x();
// 0x8039AD70 (76 bytes)
extern "C" void _restgpr_17_x();
// 0x8039AD74 (72 bytes)
extern "C" void _restgpr_18_x();
// 0x8039AD78 (68 bytes)
extern "C" void _restgpr_19_x();

/* ======================================================================
 * VMBASE - Virtual Memory Base Layer (DolphinSDK)
 *
 * Functions 299-320: VMBASEInit through __VMBASERestoreVMRegisters
 * Page table, TLB, DSI/ISI exception handlers.
 * ====================================================================== */

// 0x8039ADBC (204 bytes)
extern "C" void VMBASEInit();

// 0x8039AE88 (88 bytes)
extern "C" void VMBASEQuit();

// 0x8039AEE0 (148 bytes)
extern "C" void VMBASESetPageTableEntry();

// 0x8039AF74 (140 bytes)
extern "C" void VMBASEClearPageTableEntry();

// 0x8039B078 (144 bytes)
extern "C" void VMBASESetPageDirty();

// 0x8039B108 (144 bytes)
extern "C" void VMBASESetPageReferenced();

// 0x8039B2F4 (344 bytes)
extern "C" void __VMBASEInvalidatePageTable();

// 0x8039B44C (216 bytes)
extern "C" void __VMBASEInvalidateLockedPageTable();

// 0x8039B524 (120 bytes)
extern "C" void __VMBASEInvalidateReversePageTable();

// 0x8039B59C (172 bytes)
extern "C" void VMBASEStoreAllPages();

// 0x8039B67C (88 bytes)
extern "C" void __VMBASEInvalidateEntireTLB();

// 0x8039B714 (84 bytes)
extern "C" void __VMBASESetupVMRegisters();

// 0x8039B768 (72 bytes)
extern "C" void __VMBASESetupSDR1();

// 0x8039B7B0 (380 bytes)
extern "C" void __VMBASESetupExceptionHandlers();

// 0x8039BA20 (80 bytes)
extern "C" void __VMBASEDSIServiceExceptionPrep();

// 0x8039BA70 (100 bytes)
extern "C" void __VMBASEDSIServiceException();

// 0x8039B92C (244 bytes)
extern "C" void __VMBASEDSIExceptionHandler();

// 0x8039BAD4 (244 bytes)
extern "C" void __VMBASEISIExceptionHandler();

// 0x8039BBC8 (76 bytes)
extern "C" void __VMBASEISIServiceExceptionPrep();

// 0x8039BC14 (88 bytes)
extern "C" void __VMBASEISIServiceException();

// 0x8039BC6C (144 bytes)
extern "C" void __VMBASERestoreExceptionHandlers();

// 0x8039BCFC (68 bytes)
extern "C" void __VMBASERestoreVMRegisters();

/* ======================================================================
 * Game-Specific Template Instantiations and Streaming Functions
 *
 * Functions 321-489: EStream operators, STL sort/heap/find,
 * ReconLoadObject/ReconSaveObject, DoContainerStream, FindRes, etc.
 *
 * These are portable C++ template instantiations from the game code.
 * ====================================================================== */

/* --- EStream / TArray operators --- */

// 0x8039BD40 (191416 bytes)
// NOTE: This address/size in the map is suspicious (191KB for one function).
// It's likely a linker artifact covering a range of small inline functions.
// The actual EStream operator<< for TArray<int, TArrayERCharacterAllocator>
// is small. The rest are inlined sub-functions.
// EStream& operator<<(EStream& s, TArray<int, TArrayERCharacterAllocator>& arr);
extern "C" void _operator_shl_EStream_TArray_int_ERCharAllocator();

// 0x8039C354 (156 bytes)
// EStream& operator>>(EStream& s, TArray<int, TArrayERCharacterAllocator>& arr);
extern "C" void _operator_shr_EStream_TArray_int_ERCharAllocator();

/* --- Dummy/Trace printf stubs --- */

// 0x8039C588 (172 bytes)
void DummyPrintf(const char* fmt, ...) {
    // Intentionally empty - debug printf stripped in release
    (void)fmt;
}

// 0x803A0328 (88 bytes)
void dummyTrace(const char* fmt, ...) {
    (void)fmt;
}

// 0x803A0524 (76 bytes)
void LssDummyPrintf(const char* fmt, ...) {
    (void)fmt;
}

// 0x803B0884 (88 bytes)
void CasEventDummyPrintf(const char* fmt, ...) {
    (void)fmt;
}

// 0x803B2424 (164 bytes)
void G2DDummyPrintf(const char* fmt, ...) {
    (void)fmt;
}

/* --- InterpolateSmooth/InterpolateLinear --- */

struct EVec3 {
    f32 x, y, z;
};

// 0x8039D510 (76 bytes)
// void InterpolateSmooth<EVec3>(EVec3* out, EVec3& a, float t0, float t1)
// NON_MATCHING: Uses paired singles - requires asm on PPC
extern "C" void _InterpolateSmooth_EVec3();

// 0x803C6EF8 (144 bytes)
// float InterpolateLinear<float>(float a, float b, float t0, float t1, float t)
static f32 InterpolateLinear_float(f32 a, f32 b, f32 t0, f32 t1, f32 t) {
    if (t1 == t0) return a;
    f32 frac = (t - t0) / (t1 - t0);
    return a + (b - a) * frac;
}

// 0x803C774C (88 bytes)
// EVec3 InterpolateLinear<EVec3>(EVec3 a, EVec3 b, float t0, float t1, float t)
// NON_MATCHING: paired singles
extern "C" void _InterpolateLinear_EVec3();

/* ======================================================================
 * STL sort/heap/find/partition template instantiations
 *
 * These follow the standard SGI STL patterns. Each type gets its own
 * set of: __adjust_heap, make_heap, pop_heap, __partial_sort,
 * __unguarded_partition, __introsort_loop, __unguarded_linear_insert,
 * __insertion_sort, __unguarded_insertion_sort_aux,
 * __final_insertion_sort, sort, find, __lower_bound, __upper_bound,
 * __equal_range
 *
 * Instantiated for: unsigned int*, int*, Neighbor**, FamilyImpl**,
 * ObjSelector**, CasSimDescriptionS2C**,
 * EResourceManager::ResourceIndexRecord*
 * ====================================================================== */

/* --- sort<unsigned int*> family --- */

// 0x8039D65C (300 bytes)
// void __adjust_heap<unsigned int*, int, unsigned int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _adjust_heap_uint();

// 0x8039DB20 (284 bytes)
// void make_heap<unsigned int*, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _make_heap_uint();

// 0x8039DC3C (128 bytes)
// void __partial_sort<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _partial_sort_uint();

// 0x8039DCFC (204 bytes)
// unsigned int* __unguarded_partition<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _unguarded_partition_uint();

// 0x8039DDF0 (160 bytes)
// void __introsort_loop<unsigned int*, unsigned int, int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _introsort_loop_uint();

// 0x8039DE90 (340 bytes)
// void __unguarded_linear_insert<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _unguarded_linear_insert_uint();

// 0x8039DFE4 (108 bytes)
// void __insertion_sort<unsigned int*, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _insertion_sort_uint();

// 0x8039E050 (172 bytes)
// void __unguarded_insertion_sort_aux<unsigned int*, unsigned int, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _unguarded_insertion_sort_aux_uint();

// 0x8039E0FC (84 bytes)
// void __final_insertion_sort<unsigned int*, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _final_insertion_sort_uint();

// 0x8039E150 (108 bytes)
// void sort<unsigned int*, bool (*)(unsigned int&, unsigned int&)>
extern "C" void _sort_uint();

/* --- sort<Neighbor**> family (using RelationsCmp) --- */

// 0x8039E72C (108 bytes)
// void __adjust_heap<Neighbor**, int, Neighbor*, RelationsCmp>
extern "C" void _adjust_heap_Neighbor_108();

// 0x8039E7CC (280 bytes)
extern "C" void _adjust_heap_Neighbor();

// 0x8039E8E4 (140 bytes)
extern "C" void _pop_heap_Neighbor();

// 0x8039E970 (80 bytes)
extern "C" void _partial_sort_Neighbor();

// 0x8039E9C0 (240 bytes)
extern "C" void _unguarded_partition_Neighbor();

// 0x8039EAE0 (156 bytes)
extern "C" void _introsort_loop_Neighbor();

// 0x8039EB7C (368 bytes)
extern "C" void _unguarded_linear_insert_Neighbor();

// 0x8039ECEC (96 bytes)
extern "C" void _insertion_sort_Neighbor();

// 0x8039ED4C (180 bytes)
extern "C" void _unguarded_insertion_sort_aux_Neighbor();

// 0x8039EE00 (92 bytes)
extern "C" void _final_insertion_sort_Neighbor();

// 0x8039EE5C (140 bytes)
extern "C" void _sort_Neighbor();

// 0x8039EEE8 (148 bytes)
// void DoPtrVectorStream<Neighbor>(vector<Neighbor*>&, ReconBuffer*, int)
extern "C" void _DoPtrVectorStream_Neighbor();

/* --- sort<int*> family --- */

// 0x803A5998 (108 bytes)
extern "C" void _adjust_heap_int();

// 0x803A5A04 (284 bytes)
extern "C" void _make_heap_int();

// 0x803A5B20 (128 bytes)
extern "C" void _partial_sort_int();

// 0x803A5BE0 (204 bytes)
extern "C" void _unguarded_partition_int();

// 0x803A5CD4 (160 bytes)
extern "C" void _introsort_loop_int();

// 0x803A5D74 (340 bytes)
extern "C" void _unguarded_linear_insert_int();

// 0x803A5EC8 (108 bytes)
extern "C" void _insertion_sort_int();

// 0x803A5F34 (172 bytes)
extern "C" void _unguarded_insertion_sort_aux_int();

// 0x803A5FE0 (84 bytes)
extern "C" void _final_insertion_sort_int();

// 0x803A6034 (108 bytes)
extern "C" void _sort_int();

// 0x803A60A0 (132 bytes)
// int* find<int*, int>(int*, int*, int&)
extern "C" void _find_int();

/* --- sort<ObjSelector**> family --- */

// 0x803A6A0C (176 bytes)
extern "C" void _adjust_heap_ObjSelector();

// 0x803A6ABC (280 bytes)
extern "C" void _make_heap_ObjSelector();

// 0x803A6BD4 (128 bytes)
extern "C" void _partial_sort_ObjSelector();

// 0x803A6C94 (204 bytes)
extern "C" void _unguarded_partition_ObjSelector();

// 0x803A6D88 (156 bytes)
extern "C" void _introsort_loop_ObjSelector();

// 0x803A6E24 (344 bytes)
extern "C" void _unguarded_linear_insert_ObjSelector();

// 0x803A6F7C (96 bytes)
extern "C" void _insertion_sort_ObjSelector();

// 0x803A6FDC (164 bytes)
extern "C" void _unguarded_insertion_sort_aux_ObjSelector();

// 0x803A7080 (84 bytes)
extern "C" void _final_insertion_sort_ObjSelector();

// 0x803A70D4 (108 bytes)
extern "C" void _sort_ObjSelector();

/* --- sort<FamilyImpl**> family (using bool (*)(Family*&, Family*&)) --- */

// 0x803A5220 (100 bytes)
extern "C" void _adjust_heap_FamilyImpl();

// 0x803A5284 (280 bytes)
extern "C" void _make_heap_FamilyImpl();

// 0x803A539C (128 bytes)
extern "C" void _partial_sort_FamilyImpl();

// 0x803A545C (204 bytes)
extern "C" void _unguarded_partition_FamilyImpl();

// 0x803A5550 (164 bytes)
extern "C" void _introsort_loop_FamilyImpl();

// 0x803A55F4 (340 bytes)
extern "C" void _unguarded_linear_insert_FamilyImpl();

// 0x803A5748 (100 bytes)
extern "C" void _insertion_sort_FamilyImpl();

// 0x803A57AC (168 bytes)
extern "C" void _unguarded_insertion_sort_aux_FamilyImpl();

// 0x803A5854 (84 bytes)
extern "C" void _final_insertion_sort_FamilyImpl();

// 0x803A58A8 (108 bytes)
extern "C" void _sort_FamilyImpl();

/* --- sort<CasSimDescriptionS2C**> family --- */

// 0x803AFADC (88 bytes)
extern "C" void _adjust_heap_CasSimDesc();

// 0x803AFCC4 (280 bytes)
extern "C" void _make_heap_CasSimDesc();

// 0x803AFDDC (128 bytes)
extern "C" void _partial_sort_CasSimDesc();

// 0x803AFE9C (204 bytes)
extern "C" void _unguarded_partition_CasSimDesc();

// 0x803AFF90 (156 bytes)
extern "C" void _introsort_loop_CasSimDesc();

// 0x803B002C (344 bytes)
extern "C" void _unguarded_linear_insert_CasSimDesc();

// 0x803B0184 (96 bytes)
extern "C" void _insertion_sort_CasSimDesc();

// 0x803B01E4 (164 bytes)
extern "C" void _unguarded_insertion_sort_aux_CasSimDesc();

// 0x803B0288 (84 bytes)
extern "C" void _final_insertion_sort_CasSimDesc();

// 0x803B02DC (108 bytes)
extern "C" void _sort_CasSimDesc();

// 0x803B0348 (132 bytes)
extern "C" void _lower_bound_CasSimDesc();

// 0x803B03CC (128 bytes)
extern "C" void _upper_bound_CasSimDesc();

// 0x803B044C (128 bytes)
extern "C" void _equal_range_CasSimDesc();

/* --- sort<EResourceManager::ResourceIndexRecord*> family --- */

// 0x803C5314 (160 bytes)
extern "C" void _adjust_heap_ResourceIndexRecord();

// 0x803C65FC (404 bytes)
extern "C" void _make_heap_ResourceIndexRecord();

// 0x803C6790 (164 bytes)
extern "C" void _pop_heap_ResourceIndexRecord();

// 0x803C6834 (144 bytes)
extern "C" void _partial_sort_ResourceIndexRecord();

// 0x803C68C4 (312 bytes)
extern "C" void _introsort_loop_ResourceIndexRecord();

// 0x803C6AEC (400 bytes)
extern "C" void _unguarded_linear_insert_ResourceIndexRecord();

// 0x803C6C7C (132 bytes)
extern "C" void _insertion_sort_ResourceIndexRecord();

// 0x803C6D00 (272 bytes)
extern "C" void _unguarded_insertion_sort_aux_ResourceIndexRecord();

// 0x803C6E10 (112 bytes)
extern "C" void _final_insertion_sort_ResourceIndexRecord();

// 0x803C6E80 (120 bytes)
extern "C" void _sort_ResourceIndexRecord();

/* --- std::list sort (merge sort) for ScoredInteraction --- */

// 0x803AAF40 (264 bytes)
// void _S_merge<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction>>
extern "C" void _S_merge_ScoredInteraction();

// 0x803AB0F0 (236 bytes)
// void _S_sort<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction>>
extern "C" void _S_sort_ScoredInteraction();

/* --- find instantiations --- */

// 0x8039E240 (100 bytes)
// SpriteIdToResIdNode* FindRes<SpriteIdToResIdNode>(SpriteIdToResIdNode*, SpriteIdToResIdNode*, int)
extern "C" void _FindRes_SpriteIdToResIdNode();

// 0x803A2AE0 (176 bytes)
// CatalogData* FindRes<CatalogData>(CatalogData*, CatalogData*, int)
extern "C" void _FindRes_CatalogData();

// 0x803A0D0C (76 bytes)
// AStringSet* FindRes<AStringSet>(AStringSet*, AStringSet*, int)
extern "C" void _FindRes_AStringSet();

// 0x803A22D4 (112 bytes)
// WStringSet* FindRes<WStringSet>(WStringSet*, WStringSet*, int)
extern "C" void _FindRes_WStringSet();

// 0x803A2344 (112 bytes)
// AnimRefTable* FindRes<AnimRefTable>(AnimRefTable*, AnimRefTable*, int)
extern "C" void _FindRes_AnimRefTable();

// 0x803A3544 (108 bytes)
// FloatConstantsData* FindRes<FloatConstantsData>(FloatConstantsData*, FloatConstantsData*, int)
extern "C" void _FindRes_FloatConstantsData();

// 0x803A8324 (100 bytes)
// ObjFnData* FindRes<ObjFnData>(ObjFnData*, ObjFnData*, int)
extern "C" void _FindRes_ObjFnData();

// 0x803AB1DC (664 bytes)
// PropRefTable* FindRes<PropRefTable>(PropRefTable*, PropRefTable*, int)
extern "C" void _FindRes_PropRefTable();

// 0x803AC3D0 (224 bytes)
// SlotDescList* FindRes<SlotDescList>(SlotDescList*, SlotDescList*, int)
extern "C" void _FindRes_SlotDescList();

// 0x803ADE14 (248 bytes)
// SndInfo* FindRes<SndInfo>(SndInfo*, SndInfo*, int)
extern "C" void _FindRes_SndInfo();

// 0x803ADF68 (96 bytes)
// TreeTableEntry* FindRes<TreeTableEntry>(TreeTableEntry*, TreeTableEntry*, int)
extern "C" void _FindRes_TreeTableEntry();

// 0x803AE1F0 (112 bytes)
// BehaviorConstants* FindRes<BehaviorConstants>(BehaviorConstants*, BehaviorConstants*, int)
extern "C" void _FindRes_BehaviorConstants();

// 0x803AE820 (96 bytes)
// ObjDefinition** FindResIndirect<ObjDefinition*>(ObjDefinition**, ObjDefinition**, int)
extern "C" void _FindResIndirect_ObjDefinition();

// 0x803AE8FC (104 bytes)
// TreeTable* FindRes<TreeTable>(TreeTable*, TreeTable*, int)
extern "C" void _FindRes_TreeTable();

// 0x803A2A4C (96 bytes)
// short* find<short*, short>(short*, short*, short&)
extern "C" void _find_short();

// 0x803B73A0 (76 bytes)
// unsigned int* find<unsigned int*, unsigned int>(unsigned int*, unsigned int*, unsigned int&)
extern "C" void _find_uint();

// 0x803BF2D4 (176 bytes)
// CTilePt* find<CTilePt*, CTilePt>(CTilePt*, CTilePt*, CTilePt&)
extern "C" void _find_CTilePt();

// 0x803C16A0 (176 bytes)
// EInstance** find<EInstance**, EInstance*>(EInstance**, EInstance**, EInstance*&)
extern "C" void _find_EInstance();

/* ======================================================================
 * ReconLoadObject / ReconSaveObject template instantiations
 *
 * These are all nearly identical: construct a ReconObject on the stack,
 * call ReconBuilder::Reconstitute or ReconBuilder::Compact, then
 * destroy the ReconObject. The vtable pointer differs per type.
 * ====================================================================== */

// 0x8039E4FC (112 bytes)
// int ReconLoadObject<cSimulator>(cSimulator*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_cSimulator();

// 0x8039E56C (100 bytes)
// int ReconSaveObject<cSimulator>(cSimulator*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_cSimulator();

// 0x8039E5D0 (108 bytes)
// void ReconLoadObject<UserDataSaveLoad>(UserDataSaveLoad*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_UserDataSaveLoad_mem();

// 0x8039E63C (88 bytes)
// int ReconLoadObject<ReconStreamPtrVector<Neighbor>>(...)
extern "C" void _ReconLoadObject_ReconStreamPtrVector_Neighbor();

// 0x8039E694 (100 bytes)
// int ReconSaveObject<ReconStreamPtrVector<Neighbor>>(...)
extern "C" void _ReconSaveObject_ReconStreamPtrVector_Neighbor();

// 0x8039E1BC (132 bytes)
// int ReconLoadObject<ObjectSaveTypeTable2>(ObjectSaveTypeTable2*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectSaveTypeTable2();

// 0x8039F1FC (444 bytes)
// int ReconLoadObject<ObjectSaveTypeTable3>(ObjectSaveTypeTable3*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectSaveTypeTable3();

// 0x8039F4B4 (100 bytes)
// int ReconLoadObject<ObjectSaveIDTable>(ObjectSaveIDTable*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectSaveIDTable();

// 0x8039F518 (100 bytes)
// void ReconLoadObject<OptionsRecon>(OptionsRecon*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_OptionsRecon();

// 0x803A3400 (224 bytes)
// int ReconLoadObject<FamilyImpl>(FamilyImpl*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_FamilyImpl();

// 0x803A34E0 (100 bytes)
// int ReconSaveObject<FamilyImpl>(FamilyImpl*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_FamilyImpl();

// 0x803A3610 (96 bytes)
// int ReconLoadObject<HouseImpl>(HouseImpl*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_HouseImpl();

// 0x803A3710 (100 bytes)
// int ReconSaveObject<HouseImpl>(HouseImpl*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_HouseImpl();

// 0x803A48B8 (88 bytes)
// int ReconLoadObject<NeighborhoodImpl>(NeighborhoodImpl*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_NeighborhoodImpl();

// 0x803A5914 (132 bytes)
// int ReconSaveObject<NeighborhoodImpl>(NeighborhoodImpl*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_NeighborhoodImpl();

// 0x803A7140 (132 bytes)
// int ReconSaveObject<UserDataSaveLoad>(UserDataSaveLoad*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_UserDataSaveLoad();

// 0x803A71C4 (108 bytes)
// int ReconSaveObject<ThumbnailLoader>(ThumbnailLoader*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_ThumbnailLoader();

// 0x803A7230 (108 bytes)
// int ReconLoadObject<ObjectSaveTypeTable>(ObjectSaveTypeTable*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectSaveTypeTable();

// 0x803A729C (100 bytes)
// int ReconSaveObject<ObjectSaveTypeTable>(ObjectSaveTypeTable*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_ObjectSaveTypeTable();

// 0x803A7300 (108 bytes)
// int ReconSaveObject<ObjectFolderImpl>(ObjectFolderImpl*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_ObjectFolderImpl();

// 0x803A736C (108 bytes)
// int ReconLoadObject<ObjectFolderImpl>(ObjectFolderImpl*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectFolderImpl();

// 0x803A73D8 (100 bytes)
// int ReconSaveObject<ObjectModuleImpl>(ObjectModuleImpl*, iResFile*, int, short, int)
extern "C" void _ReconSaveObject_ObjectModuleImpl();

// 0x803A82B8 (108 bytes)
// int ReconLoadObject<ObjectModuleImpl>(ObjectModuleImpl*, iResFile*, int, short, int*)
extern "C" void _ReconLoadObject_ObjectModuleImpl();

// 0x803A869C (112 bytes)
// void ReconLoadObject<ThumbnailLoader>(ThumbnailLoader*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_ThumbnailLoader_mem();

// 0x803AD650 (96 bytes)
// int ReconLoadObject<ReconStreamVector<SlotDescriptor>>(...)
extern "C" void _ReconLoadObject_ReconStreamVector_SlotDescriptor();

// 0x803AD6B0 (100 bytes)
// int ReconSaveObject<ReconStreamVector<SlotDescriptor>>(...)
extern "C" void _ReconSaveObject_ReconStreamVector_SlotDescriptor();

// 0x803AF234 (112 bytes)
// void ReconLoadObject<CasCostumes>(CasCostumes*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_CasCostumes();

// 0x803B04CC (236 bytes)
// void ReconLoadObject<CasGenetics>(CasGenetics*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_CasGenetics();

// 0x803A46FC (444 bytes)
// void ReconLoadObject<IFFResMap>(IFFResMap*, Memory::HandleNode*, int, int*)
extern "C" void _ReconLoadObject_IFFResMap();

/* ======================================================================
 * DoContainerStream / DoPtrVectorStream template instantiations
 * ====================================================================== */

// 0x803A2DB4 (96 bytes)
// void DoContainerStream<vector<FamilyMember>, FamilyMember>(...)
extern "C" void _DoContainerStream_FamilyMember();

// 0x803A3774 (108 bytes)
// void DoContainerStream<vector<IFFResNode>, IFFResNode>(...)
extern "C" void _DoContainerStream_IFFResNode();

// 0x803A3E80 (288 bytes)
// void DoContainerStream<vector<IFFResList>, IFFResList>(...)
extern "C" void _DoContainerStream_IFFResList();

// 0x803A8740 (88 bytes)
// void DoContainerStream<vector<XRoute>, XRoute>(...)
extern "C" void _DoContainerStream_XRoute();

// 0x803AA520 (424 bytes)
// void DoContainerStream<vector<ObjectRecord>, ObjectRecord>(...)
extern "C" void _DoContainerStream_ObjectRecord();

// 0x803AAA80 (264 bytes)
// void DoContainerStream<vector<MotiveInc>, MotiveInc>(...)
extern "C" void _DoContainerStream_MotiveInc();

// 0x803ABB7C (96 bytes)
// void DoPtrVectorStream<RelArray>(vector<RelArray*>&, ReconBuffer*, int)
extern "C" void _DoPtrVectorStream_RelArray();

// 0x803AC178 (600 bytes)
// void DoContainerStream<RelArray, RelInt>(RelArray&, RelInt*, ReconBuffer*, int)
extern "C" void _DoContainerStream_RelArray_RelInt();

// 0x803AD748 (108 bytes)
// void DoContainerStream<vector<SlotDescriptor>, SlotDescriptor>(...)
extern "C" void _DoContainerStream_SlotDescriptor();

/* ======================================================================
 * arrayRemove / arrayInsert template instantiations
 * ====================================================================== */

// 0x803B0D98 (76 bytes)
// void arrayRemove<ActionQueueHUD::ActionQueueItem>(ActionQueueHUD::ActionQueueItem*, u32, u32, u32)
extern "C" void _arrayRemove_ActionQueueItem();

// 0x803B2180 (184 bytes)
// void arrayRemove<unsigned int>(unsigned int*, u32, u32, u32)
extern "C" void _arrayRemove_uint();

// 0x803B2238 (164 bytes)
// void arrayInsert<ActionQueueHUD::ActionQueueItem>(ActionQueueHUD::ActionQueueItem*, u32, ActionQueueHUD::ActionQueueItem&, u32)
extern "C" void _arrayInsert_ActionQueueItem();

// 0x803B22DC (192 bytes)
// void arrayInsert<AptCIH*>(AptCIH**, u32, AptCIH*&, u32)
extern "C" void _arrayInsert_AptCIH();

// 0x803B239C (136 bytes)
// void arrayRemove<AptCIH*>(AptCIH**, u32, u32, u32)
extern "C" void _arrayRemove_AptCIH();

/* ======================================================================
 * EStream / EFile operator<< and operator>> for THashTable, TRedBlackTree,
 * TArray, TNodeList template instantiations
 * ====================================================================== */

// 0x803C0FA0 (300 bytes)
// EStream& operator<<(EStream&, TRedBlackTree<unsigned int, EInstance*>&)
extern "C" void _op_shl_EStream_TRedBlackTree_uint_EInstance();

// 0x803C1564 (180 bytes)
// EStream& operator>>(EStream&, TNodeList<EInstance*>&)
extern "C" void _op_shr_EStream_TNodeList_EInstance();

// 0x803C1618 (136 bytes)
// EStream& operator>>(EStream&, TRedBlackTree<unsigned int, EInstance*>&)
extern "C" void _op_shr_EStream_TRedBlackTree_uint_EInstance();

// 0x803C1750 (176 bytes)
// EStream& operator<<(EStream&, TArray<unsigned int, TArrayDefaultAllocator>&)
extern "C" void _op_shl_EStream_TArray_uint();

// 0x803C3F5C (156 bytes)
// EStream& operator>>(EStream&, TArray<unsigned int, TArrayDefaultAllocator>&)
extern "C" void _op_shr_EStream_TArray_uint();

/* --- CopyTArray instantiations --- */

// 0x803C3FF8 (172 bytes)
// unsigned int CopyTArray<BSplineVolume, TArrayERModelAllocator>(TArray<BSplineVolume, TArrayERModelAllocator>&, char*)
extern "C" void _CopyTArray_BSplineVolume();

// 0x803C4AC0 (180 bytes)
// unsigned int CopyTArray<ENDummy, TArrayERModelAllocator>(TArray<ENDummy, TArrayERModelAllocator>&, char*)
extern "C" void _CopyTArray_ENDummy();

// 0x803C4DC4 (180 bytes)
// unsigned int CopyTArray<ENCamera, TArrayERModelAllocator>(TArray<ENCamera, TArrayERModelAllocator>&, char*)
extern "C" void _CopyTArray_ENCamera();

// 0x803C50C8 (180 bytes)
// unsigned int CopyTArray<SimsLightInfo, TArrayERModelAllocator>(TArray<SimsLightInfo, TArrayERModelAllocator>&, char*)
extern "C" void _CopyTArray_SimsLightInfo();

/* --- EStream/EFile operators for EFontCharacter/EFontPage/EFontSize --- */

// 0x803C77A4 (264 bytes)
// EStream& operator<<(EStream&, THashTable<unsigned int, EFontCharacter*>&)
extern "C" void _op_shl_EStream_THashTable_uint_EFontChar();

// 0x803C7CD4 (220 bytes)
// EStream& operator<<(EStream&, TArray<EFontPage*, TArrayDefaultAllocator>&)
extern "C" void _op_shl_EStream_TArray_EFontPage();

// 0x803C7DB0 (128 bytes)
// EStream& operator>>(EStream&, THashTable<unsigned int, EFontCharacter*>&)
extern "C" void _op_shr_EStream_THashTable_uint_EFontChar();

// 0x803C7E30 (220 bytes)
// EStream& operator>>(EStream&, TArray<EFontPage*, TArrayDefaultAllocator>&)
extern "C" void _op_shr_EStream_TArray_EFontPage();

// 0x803C8078 (152 bytes)
// EFile& operator>>(EFile&, THashTable<unsigned int, EFontCharacter*>&)
extern "C" void _op_shr_EFile_THashTable_uint_EFontChar();

// 0x803C8110 (220 bytes)
// EStream& operator<<(EStream&, TNodeList<EFontSize*>&)
extern "C" void _op_shl_EStream_TNodeList_EFontSize();

// 0x803C81EC (140 bytes)
// EStream& operator<<(EStream&, THashTable<unsigned int, int>&)
extern "C" void _op_shl_EStream_THashTable_uint_int();

// 0x803C8278 (248 bytes)
// EStream& operator>>(EStream&, TNodeList<EFontSize*>&)
extern "C" void _op_shr_EStream_TNodeList_EFontSize();

// 0x803C8370 (136 bytes)
// EStream& operator>>(EStream&, THashTable<unsigned int, int>&)
extern "C" void _op_shr_EStream_THashTable_uint_int();

// 0x803C83F8 (240 bytes)
// EFile& operator>>(EFile&, THashTable<unsigned int, int>&)
extern "C" void _op_shr_EFile_THashTable_uint_int();

// 0x803C84E8 (240 bytes)
// Last function in Q4 range (likely another EFile/EStream operator)
extern "C" void _op_last_q4();
