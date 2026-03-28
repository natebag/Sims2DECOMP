// gx.cpp - GX graphics library
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 281 functions
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

// GXInit
// Address: 0x805621C4, Size: 1536
void GXInit() {
}

// GXOverflowHandler
// Address: 0x805630FC, Size: 80
void GXOverflowHandler() {
}

// GXUnderflowHandler
// Address: 0x8056314C, Size: 68
void GXUnderflowHandler() {
}

// GXBreakPointHandler
// Address: 0x80563190, Size: 128
void GXBreakPointHandler() {
}

// GXCPInterruptHandler
// Address: 0x80563210, Size: 308
void GXCPInterruptHandler() {
}

// GXInitFifoBase
// Address: 0x80563344, Size: 108
void GXInitFifoBase() {
}

// GXInitFifoPtrs
// Address: 0x805633B0, Size: 112
void GXInitFifoPtrs() {
}

// GXInitFifoLimits
// Address: 0x80563420, Size: 12
void GXInitFifoLimits() {
}

// GXSetCPUFifo
// Address: 0x8056342C, Size: 296
void GXSetCPUFifo() {
}

// GXSetGPFifo
// Address: 0x80563554, Size: 376
void GXSetGPFifo() {
}

// GXSaveCPUFifo
// Address: 0x805636CC, Size: 52
void GXSaveCPUFifo() {
}

// GXSaveGPFifo
// Address: 0x805637C8, Size: 48
void GXSaveGPFifo() {
}

// GXGetGPStatus
// Address: 0x805637F8, Size: 80
void GXGetGPStatus() {
}

// GXGetFifoStatus
// Address: 0x80563848, Size: 276
void GXGetFifoStatus() {
}

// GXGetFifoPtrs
// Address: 0x8056395C, Size: 152
void GXGetFifoPtrs() {
}

// GXGetFifoBase
// Address: 0x805639F4, Size: 8
void GXGetFifoBase() {
}

// GXGetFifoSize
// Address: 0x805639FC, Size: 8
void GXGetFifoSize() {
}

// GXGetFifoLimits
// Address: 0x80563A04, Size: 20
void GXGetFifoLimits() {
}

// GXSetBreakPtCallback
// Address: 0x80563A18, Size: 68
void GXSetBreakPtCallback() {
}

// GXEnableBreakPt
// Address: 0x80563A5C, Size: 140
void GXEnableBreakPt() {
}

// GXDisableBreakPt
// Address: 0x80563AE8, Size: 84
void GXDisableBreakPt() {
}

// GXSetCurrentGXThread
// Address: 0x80563D94, Size: 76
void GXSetCurrentGXThread() {
}

// GXGetCurrentGXThread
// Address: 0x80563DE0, Size: 8
void GXGetCurrentGXThread() {
}

// GXGetCPUFifo
// Address: 0x80563DE8, Size: 8
void GXGetCPUFifo() {
}

// GXGetGPFifo
// Address: 0x80563DF0, Size: 8
void GXGetGPFifo() {
}

// GXGetOverflowCount
// Address: 0x80563DF8, Size: 8
void GXGetOverflowCount() {
}

// GXResetOverflowCount
// Address: 0x80563E00, Size: 16
void GXResetOverflowCount() {
}

// GXRedirectWriteGatherPipe
// Address: 0x80563E10, Size: 264
void GXRedirectWriteGatherPipe() {
}

// GXRestoreWriteGatherPipe
// Address: 0x80563F18, Size: 416
void GXRestoreWriteGatherPipe() {
}

// GXSetVtxDesc
// Address: 0x80564144, Size: 620
void GXSetVtxDesc() {
}

// GXSetVtxDescv
// Address: 0x805643B0, Size: 648
void GXSetVtxDescv() {
}

// GXGetVtxDesc
// Address: 0x80564818, Size: 436
void GXGetVtxDesc() {
}

// GXGetVtxDescv
// Address: 0x805649CC, Size: 144
void GXGetVtxDescv() {
}

// GXClearVtxDesc
// Address: 0x80564A5C, Size: 56
void GXClearVtxDesc() {
}

// GXSetVtxAttrFmt
// Address: 0x80564A94, Size: 604
void GXSetVtxAttrFmt() {
}

// GXSetVtxAttrFmtv
// Address: 0x80564CF0, Size: 640
void GXSetVtxAttrFmtv() {
}

// GXGetVtxAttrFmt
// Address: 0x80564FF8, Size: 640
void GXGetVtxAttrFmt() {
}

// GXGetVtxAttrFmtv
// Address: 0x80565278, Size: 116
void GXGetVtxAttrFmtv() {
}

// GXSetArray
// Address: 0x805652EC, Size: 68
void GXSetArray() {
}

// GXInvalidateVtxCache
// Address: 0x80565330, Size: 16
void GXInvalidateVtxCache() {
}

// GXSetTexCoordGen2
// Address: 0x80565340, Size: 640
void GXSetTexCoordGen2() {
}

// GXSetMisc
// Address: 0x805655FC, Size: 148
void GXSetMisc() {
}

// GXFlush
// Address: 0x80565690, Size: 92
void GXFlush() {
}

// GXResetWriteGatherPipe
// Address: 0x805656EC, Size: 52
void GXResetWriteGatherPipe() {
}

// GXAbortFrame
// Address: 0x805659CC, Size: 456
void GXAbortFrame() {
}

// GXSetDrawSync
// Address: 0x80565B94, Size: 180
void GXSetDrawSync() {
}

// GXReadDrawSync
// Address: 0x80565C48, Size: 12
void GXReadDrawSync() {
}

// GXSetDrawDone
// Address: 0x80565C54, Size: 152
void GXSetDrawDone() {
}

// GXWaitDrawDone
// Address: 0x80565CEC, Size: 76
void GXWaitDrawDone() {
}

// GXDrawDone
// Address: 0x80565D38, Size: 128
void GXDrawDone() {
}

// GXPixModeSync
// Address: 0x80565DB8, Size: 36
void GXPixModeSync() {
}

// GXTexModeSync
// Address: 0x80565DDC, Size: 36
void GXTexModeSync() {
}

// GXPokeAlphaMode
// Address: 0x80565E00, Size: 20
void GXPokeAlphaMode() {
}

// GXPokeAlphaRead
// Address: 0x80565E14, Size: 32
void GXPokeAlphaRead() {
}

// GXPokeAlphaUpdate
// Address: 0x80565E34, Size: 24
void GXPokeAlphaUpdate() {
}

// GXPokeBlendMode
// Address: 0x80565E4C, Size: 100
void GXPokeBlendMode() {
}

// GXPokeColorUpdate
// Address: 0x80565EB0, Size: 24
void GXPokeColorUpdate() {
}

// GXPokeDstAlpha
// Address: 0x80565EC8, Size: 36
void GXPokeDstAlpha() {
}

// GXPokeDither
// Address: 0x80565EEC, Size: 24
void GXPokeDither() {
}

// GXPokeZMode
// Address: 0x80565F04, Size: 32
void GXPokeZMode() {
}

// GXPeekARGB
// Address: 0x80565F24, Size: 36
void GXPeekARGB() {
}

// GXPokeARGB
// Address: 0x80565F48, Size: 32
void GXPokeARGB() {
}

// GXPeekZ
// Address: 0x80565F68, Size: 36
void GXPeekZ() {
}

// GXPokeZ
// Address: 0x80565F8C, Size: 32
void GXPokeZ() {
}

// GXSetDrawSyncCallback
// Address: 0x80565FAC, Size: 68
void GXSetDrawSyncCallback() {
}

// GXTokenInterruptHandler
// Address: 0x80565FF0, Size: 136
void GXTokenInterruptHandler() {
}

// GXSetDrawDoneCallback
// Address: 0x80566078, Size: 68
void GXSetDrawDoneCallback() {
}

// GXFinishInterruptHandler
// Address: 0x805660BC, Size: 128
void GXFinishInterruptHandler() {
}

// GXCompressZ16
// Address: 0x805661B0, Size: 308
void GXCompressZ16() {
}

// GXDecompressZ16
// Address: 0x805662E4, Size: 284
void GXDecompressZ16() {
}

// GXBegin
// Address: 0x80566480, Size: 208
void GXBegin() {
}

// GXSetLineWidth
// Address: 0x805665D8, Size: 64
void GXSetLineWidth() {
}

// GXGetLineWidth
// Address: 0x80566618, Size: 28
void GXGetLineWidth() {
}

// GXSetPointSize
// Address: 0x80566634, Size: 64
void GXSetPointSize() {
}

// GXGetPointSize
// Address: 0x80566674, Size: 32
void GXGetPointSize() {
}

// GXEnableTexOffsets
// Address: 0x80566694, Size: 72
void GXEnableTexOffsets() {
}

// GXSetCullMode
// Address: 0x805666DC, Size: 40
void GXSetCullMode() {
}

// GXGetCullMode
// Address: 0x80566704, Size: 28
void GXGetCullMode() {
}

// GXSetCoPlanar
// Address: 0x80566720, Size: 52
void GXSetCoPlanar() {
}

// GXAdjustForOverscan
// Address: 0x80566778, Size: 324
void GXAdjustForOverscan() {
}

// GXSetDispCopySrc
// Address: 0x805668BC, Size: 124
void GXSetDispCopySrc() {
}

// GXSetTexCopySrc
// Address: 0x80566938, Size: 124
void GXSetTexCopySrc() {
}

// GXSetDispCopyDst
// Address: 0x805669B4, Size: 52
void GXSetDispCopyDst() {
}

// GXSetTexCopyDst
// Address: 0x805669E8, Size: 304
void GXSetTexCopyDst() {
}

// GXSetDispCopyFrame2Field
// Address: 0x80566B18, Size: 36
void GXSetDispCopyFrame2Field() {
}

// GXSetCopyClamp
// Address: 0x80566B3C, Size: 88
void GXSetCopyClamp() {
}

// GXGetNumXfbLines
// Address: 0x80566BEC, Size: 144
void GXGetNumXfbLines() {
}

// GXGetYScaleFactor
// Address: 0x80566C7C, Size: 568
void GXGetYScaleFactor() {
}

// GXSetDispCopyYScale
// Address: 0x80566EB4, Size: 204
void GXSetDispCopyYScale() {
}

// GXSetCopyClear
// Address: 0x80566F80, Size: 120
void GXSetCopyClear() {
}

// GXSetCopyFilter
// Address: 0x80566FF8, Size: 520
void GXSetCopyFilter() {
}

// GXSetDispCopyGamma
// Address: 0x80567200, Size: 20
void GXSetDispCopyGamma() {
}

// GXCopyDisp
// Address: 0x80567214, Size: 360
void GXCopyDisp() {
}

// GXCopyTex
// Address: 0x8056737C, Size: 396
void GXCopyTex() {
}

// GXClearBoundingBox
// Address: 0x80567508, Size: 56
void GXClearBoundingBox() {
}

// GXReadBoundingBox
// Address: 0x80567540, Size: 52
void GXReadBoundingBox() {
}

// GXInitLightAttn
// Address: 0x80567574, Size: 28
void GXInitLightAttn() {
}

// GXInitLightAttnA
// Address: 0x80567590, Size: 16
void GXInitLightAttnA() {
}

// GXGetLightAttnA
// Address: 0x805675A0, Size: 28
void GXGetLightAttnA() {
}

// GXInitLightAttnK
// Address: 0x805675BC, Size: 16
void GXInitLightAttnK() {
}

// GXGetLightAttnK
// Address: 0x805675CC, Size: 28
void GXGetLightAttnK() {
}

// GXInitLightSpot
// Address: 0x805675E8, Size: 400
void GXInitLightSpot() {
}

// GXInitLightDistAttn
// Address: 0x80567778, Size: 208
void GXInitLightDistAttn() {
}

// GXInitLightPos
// Address: 0x80567848, Size: 16
void GXInitLightPos() {
}

// GXGetLightPos
// Address: 0x80567858, Size: 28
void GXGetLightPos() {
}

// GXInitLightDir
// Address: 0x80567874, Size: 28
void GXInitLightDir() {
}

// GXGetLightDir
// Address: 0x80567890, Size: 40
void GXGetLightDir() {
}

// GXInitSpecularDir
// Address: 0x805678B8, Size: 228
void GXInitSpecularDir() {
}

// GXInitSpecularDirHA
// Address: 0x8056799C, Size: 44
void GXInitSpecularDirHA() {
}

// GXInitLightColor
// Address: 0x805679C8, Size: 12
void GXInitLightColor() {
}

// GXGetLightColor
// Address: 0x805679D4, Size: 12
void GXGetLightColor() {
}

// GXLoadLightObjImm
// Address: 0x805679E0, Size: 124
void GXLoadLightObjImm() {
}

// GXLoadLightObjIndx
// Address: 0x80567A5C, Size: 72
void GXLoadLightObjIndx() {
}

// GXSetChanCtrl
// Address: 0x80567CB0, Size: 176
void GXSetChanCtrl() {
}

// GXGetTexBufferSize
// Address: 0x80567DC4, Size: 348
void GXGetTexBufferSize() {
}

// GXInitTexObj
// Address: 0x80567FE8, Size: 588
void GXInitTexObj() {
}

// GXInitTexObjCI
// Address: 0x80568234, Size: 72
void GXInitTexObjCI() {
}

// GXInitTexObjLOD
// Address: 0x8056827C, Size: 356
void GXInitTexObjLOD() {
}

// GXInitTexObjData
// Address: 0x805683E0, Size: 16
void GXInitTexObjData() {
}

// GXInitTexObjWrapMode
// Address: 0x805683F0, Size: 28
void GXInitTexObjWrapMode() {
}

// GXInitTexObjTlut
// Address: 0x8056840C, Size: 8
void GXInitTexObjTlut() {
}

// GXInitTexObjFilter
// Address: 0x80568414, Size: 56
void GXInitTexObjFilter() {
}

// GXInitTexObjMaxLOD
// Address: 0x8056844C, Size: 80
void GXInitTexObjMaxLOD() {
}

// GXInitTexObjMinLOD
// Address: 0x8056849C, Size: 80
void GXInitTexObjMinLOD() {
}

// GXInitTexObjLODBias
// Address: 0x805684EC, Size: 84
void GXInitTexObjLODBias() {
}

// GXInitTexObjBiasClamp
// Address: 0x80568540, Size: 20
void GXInitTexObjBiasClamp() {
}

// GXInitTexObjEdgeLOD
// Address: 0x80568554, Size: 36
void GXInitTexObjEdgeLOD() {
}

// GXInitTexObjMaxAniso
// Address: 0x80568578, Size: 16
void GXInitTexObjMaxAniso() {
}

// GXInitTexObjUserData
// Address: 0x80568588, Size: 8
void GXInitTexObjUserData() {
}

// GXGetTexObjUserData
// Address: 0x80568590, Size: 8
void GXGetTexObjUserData() {
}

// GXGetTexObjAll
// Address: 0x80568598, Size: 104
void GXGetTexObjAll() {
}

// GXGetTexObjData
// Address: 0x80568600, Size: 12
void GXGetTexObjData() {
}

// GXGetTexObjWidth
// Address: 0x8056860C, Size: 16
void GXGetTexObjWidth() {
}

// GXGetTexObjHeight
// Address: 0x8056861C, Size: 16
void GXGetTexObjHeight() {
}

// GXGetTexObjFmt
// Address: 0x8056862C, Size: 8
void GXGetTexObjFmt() {
}

// GXGetTexObjWrapS
// Address: 0x80568634, Size: 12
void GXGetTexObjWrapS() {
}

// GXGetTexObjWrapT
// Address: 0x80568640, Size: 12
void GXGetTexObjWrapT() {
}

// GXGetTexObjMipMap
// Address: 0x8056864C, Size: 24
void GXGetTexObjMipMap() {
}

// GXGetTexObjLODAll
// Address: 0x80568664, Size: 228
void GXGetTexObjLODAll() {
}

// GXGetTexObjMinFilt
// Address: 0x80568748, Size: 20
void GXGetTexObjMinFilt() {
}

// GXGetTexObjMagFilt
// Address: 0x8056875C, Size: 12
void GXGetTexObjMagFilt() {
}

// GXGetTexObjMinLOD
// Address: 0x80568768, Size: 52
void GXGetTexObjMinLOD() {
}

// GXGetTexObjMaxLOD
// Address: 0x8056879C, Size: 52
void GXGetTexObjMaxLOD() {
}

// GXGetTexObjLODBias
// Address: 0x805687D0, Size: 64
void GXGetTexObjLODBias() {
}

// GXGetTexObjBiasClamp
// Address: 0x80568810, Size: 12
void GXGetTexObjBiasClamp() {
}

// GXGetTexObjEdgeLOD
// Address: 0x8056881C, Size: 20
void GXGetTexObjEdgeLOD() {
}

// GXGetTexObjMaxAniso
// Address: 0x80568830, Size: 12
void GXGetTexObjMaxAniso() {
}

// GXGetTexObjTlut
// Address: 0x8056883C, Size: 8
void GXGetTexObjTlut() {
}

// GXLoadTexObjPreLoaded
// Address: 0x80568844, Size: 380
void GXLoadTexObjPreLoaded() {
}

// GXLoadTexObj
// Address: 0x805689C0, Size: 84
void GXLoadTexObj() {
}

// GXInitTlutObj
// Address: 0x80568A14, Size: 56
void GXInitTlutObj() {
}

// GXGetTlutObjAll
// Address: 0x80568A4C, Size: 36
void GXGetTlutObjAll() {
}

// GXGetTlutObjData
// Address: 0x80568A70, Size: 12
void GXGetTlutObjData() {
}

// GXGetTlutObjFmt
// Address: 0x80568A7C, Size: 12
void GXGetTlutObjFmt() {
}

// GXGetTlutObjNumEntries
// Address: 0x80568A88, Size: 8
void GXGetTlutObjNumEntries() {
}

// GXLoadTlut
// Address: 0x80568A90, Size: 152
void GXLoadTlut() {
}

// GXInitTexCacheRegion
// Address: 0x80568B28, Size: 244
void GXInitTexCacheRegion() {
}

// GXInitTexPreLoadRegion
// Address: 0x80568C1C, Size: 132
void GXInitTexPreLoadRegion() {
}

// GXGetTexRegionAll
// Address: 0x80568CA0, Size: 268
void GXGetTexRegionAll() {
}

// GXInitTlutRegion
// Address: 0x80568DAC, Size: 56
void GXInitTlutRegion() {
}

// GXGetTlutRegionAll
// Address: 0x80568DE4, Size: 32
void GXGetTlutRegionAll() {
}

// GXInvalidateTexRegion
// Address: 0x80568E04, Size: 300
void GXInvalidateTexRegion() {
}

// GXInvalidateTexAll
// Address: 0x80568F30, Size: 72
void GXInvalidateTexAll() {
}

// GXSetTexRegionCallback
// Address: 0x80568F78, Size: 20
void GXSetTexRegionCallback() {
}

// GXSetTlutRegionCallback
// Address: 0x80568F8C, Size: 20
void GXSetTlutRegionCallback() {
}

// GXPreLoadEntireTexture
// Address: 0x80568FA0, Size: 612
void GXPreLoadEntireTexture() {
}

// GXSetTexCoordScaleManually
// Address: 0x80569204, Size: 124
void GXSetTexCoordScaleManually() {
}

// GXSetTexCoordCylWrap
// Address: 0x80569280, Size: 100
void GXSetTexCoordCylWrap() {
}

// GXSetTexCoordBias
// Address: 0x805692E4, Size: 100
void GXSetTexCoordBias() {
}

// GXSetTevIndirect
// Address: 0x805698E8, Size: 108
void GXSetTevIndirect() {
}

// GXSetIndTexMtx
// Address: 0x80569954, Size: 376
void GXSetIndTexMtx() {
}

// GXSetIndTexCoordScale
// Address: 0x80569ACC, Size: 324
void GXSetIndTexCoordScale() {
}

// GXSetIndTexOrder
// Address: 0x80569C10, Size: 236
void GXSetIndTexOrder() {
}

// GXSetNumIndStages
// Address: 0x80569CFC, Size: 36
void GXSetNumIndStages() {
}

// GXSetTevDirect
// Address: 0x80569D20, Size: 72
void GXSetTevDirect() {
}

// GXSetTevIndWarp
// Address: 0x80569D68, Size: 100
void GXSetTevIndWarp() {
}

// GXSetTevIndTile
// Address: 0x80569DCC, Size: 428
void GXSetTevIndTile() {
}

// GXSetTevIndBumpST
// Address: 0x80569F78, Size: 268
void GXSetTevIndBumpST() {
}

// GXSetTevIndBumpXYZ
// Address: 0x8056A084, Size: 68
void GXSetTevIndBumpXYZ() {
}

// GXSetTevIndRepeat
// Address: 0x8056A0C8, Size: 72
void GXSetTevIndRepeat() {
}

// GXSetTevOp
// Address: 0x8056A168, Size: 140
void GXSetTevOp() {
}

// GXSetTevColorIn
// Address: 0x8056A1F4, Size: 68
void GXSetTevColorIn() {
}

// GXSetTevAlphaIn
// Address: 0x8056A238, Size: 68
void GXSetTevAlphaIn() {
}

// GXSetTevColorOp
// Address: 0x8056A27C, Size: 104
void GXSetTevColorOp() {
}

// GXSetTevAlphaOp
// Address: 0x8056A2E4, Size: 104
void GXSetTevAlphaOp() {
}

// GXSetTevColor
// Address: 0x8056A34C, Size: 96
void GXSetTevColor() {
}

// GXSetTevColorS10
// Address: 0x8056A3AC, Size: 100
void GXSetTevColorS10() {
}

// GXSetTevKColor
// Address: 0x8056A410, Size: 100
void GXSetTevKColor() {
}

// GXSetTevKColorSel
// Address: 0x8056A474, Size: 92
void GXSetTevKColorSel() {
}

// GXSetTevKAlphaSel
// Address: 0x8056A4D0, Size: 92
void GXSetTevKAlphaSel() {
}

// GXSetTevSwapMode
// Address: 0x8056A52C, Size: 72
void GXSetTevSwapMode() {
}

// GXSetTevSwapModeTable
// Address: 0x8056A574, Size: 128
void GXSetTevSwapModeTable() {
}

// GXSetTevClampMode
// Address: 0x8056A5F4, Size: 4
void GXSetTevClampMode() {
}

// GXSetZTexture
// Address: 0x8056A63C, Size: 140
void GXSetZTexture() {
}

// GXSetFog
// Address: 0x8056A88C, Size: 532
void GXSetFog() {
}

// GXSetFogColor
// Address: 0x8056AAA0, Size: 48
void GXSetFogColor() {
}

// GXInitFogAdjTable
// Address: 0x8056AAD0, Size: 432
void GXInitFogAdjTable() {
}

// GXSetFogRangeAdj
// Address: 0x8056AC80, Size: 292
void GXSetFogRangeAdj() {
}

// GXSetBlendMode
// Address: 0x8056ADA4, Size: 84
void GXSetBlendMode() {
}

// GXSetColorUpdate
// Address: 0x8056ADF8, Size: 44
void GXSetColorUpdate() {
}

// GXSetAlphaUpdate
// Address: 0x8056AE24, Size: 44
void GXSetAlphaUpdate() {
}

// GXSetZCompLoc
// Address: 0x8056AE84, Size: 52
void GXSetZCompLoc() {
}

// GXSetPixelFmt
// Address: 0x8056AEB8, Size: 212
void GXSetPixelFmt() {
}

// GXSetDither
// Address: 0x8056AF8C, Size: 44
void GXSetDither() {
}

// GXSetDstAlpha
// Address: 0x8056AFB8, Size: 60
void GXSetDstAlpha() {
}

// GXSetFieldMask
// Address: 0x8056AFF4, Size: 56
void GXSetFieldMask() {
}

// GXSetFieldMode
// Address: 0x8056B02C, Size: 120
void GXSetFieldMode() {
}

// GXProject
// Address: 0x8056B2A4, Size: 372
void GXProject() {
}

// GXSetProjectionv
// Address: 0x8056B53C, Size: 140
void GXSetProjectionv() {
}

// GXGetProjectionv
// Address: 0x8056B5C8, Size: 72
void GXGetProjectionv() {
}

// GXLoadPosMtxIndx
// Address: 0x8056B718, Size: 48
void GXLoadPosMtxIndx() {
}

// GXLoadNrmMtxImm3x3
// Address: 0x8056B798, Size: 72
void GXLoadNrmMtxImm3x3() {
}

// GXLoadNrmMtxIndx3x3
// Address: 0x8056B7E0, Size: 52
void GXLoadNrmMtxIndx3x3() {
}

// GXLoadTexMtxImm
// Address: 0x8056B848, Size: 180
void GXLoadTexMtxImm() {
}

// GXLoadTexMtxIndx
// Address: 0x8056B8FC, Size: 88
void GXLoadTexMtxIndx() {
}

// GXSetViewportJitter
// Address: 0x8056B9E4, Size: 88
void GXSetViewportJitter() {
}

// GXGetViewportv
// Address: 0x8056BA84, Size: 36
void GXGetViewportv() {
}

// GXSetZScaleOffset
// Address: 0x8056BAA8, Size: 108
void GXSetZScaleOffset() {
}

// GXGetScissor
// Address: 0x8056BB8C, Size: 72
void GXGetScissor() {
}

// GXSetScissorBoxOffset
// Address: 0x8056BBD4, Size: 64
void GXSetScissorBoxOffset() {
}

// GXSetClipMode
// Address: 0x8056BC14, Size: 40
void GXSetClipMode() {
}

// GXSetGPMetric
// Address: 0x8056BCC0, Size: 2120
void GXSetGPMetric() {
}

// GXReadGPMetric
// Address: 0x8056C508, Size: 424
void GXReadGPMetric() {
}

// GXClearGPMetric
// Address: 0x8056C6B0, Size: 16
void GXClearGPMetric() {
}

// GXReadGP0Metric
// Address: 0x8056C6C0, Size: 44
void GXReadGP0Metric() {
}

// GXReadGP1Metric
// Address: 0x8056C6EC, Size: 44
void GXReadGP1Metric() {
}

// GXReadMemMetric
// Address: 0x8056C718, Size: 532
void GXReadMemMetric() {
}

// GXClearMemMetric
// Address: 0x8056C92C, Size: 168
void GXClearMemMetric() {
}

// GXReadPixMetric
// Address: 0x8056C9D4, Size: 312
void GXReadPixMetric() {
}

// GXClearPixMetric
// Address: 0x8056CB0C, Size: 48
void GXClearPixMetric() {
}

// GXSetVCacheMetric
// Address: 0x8056CB3C, Size: 68
void GXSetVCacheMetric() {
}

// GXReadVCacheMetric
// Address: 0x8056CB80, Size: 148
void GXReadVCacheMetric() {
}

// GXClearVCacheMetric
// Address: 0x8056CC14, Size: 28
void GXClearVCacheMetric() {
}

// GXInitXfRasMetric
// Address: 0x8056CC30, Size: 68
void GXInitXfRasMetric() {
}

// GXReadXfRasMetric
// Address: 0x8056CC74, Size: 196
void GXReadXfRasMetric() {
}

// GXReadClksPerVtx
// Address: 0x8056CD38, Size: 64
void GXReadClksPerVtx() {
}

// GXDefaultVATList
// Address: 0x806E3540, Size: 208
void GXDefaultVATList() {
}

// GXDefaultProjData
// Address: 0x806E3610, Size: 28
void GXDefaultProjData() {
}

// GXTexRegionAddrTable
// Address: 0x806E362C, Size: 192
void GXTexRegionAddrTable() {
}

// GXResetFuncInfo
// Address: 0x806E36EC, Size: 16
void GXResetFuncInfo() {
}

// GXNtsc240Ds
// Address: 0x806E39D0, Size: 60
void GXNtsc240Ds() {
}

// GXNtsc240DsAa
// Address: 0x806E3A0C, Size: 60
void GXNtsc240DsAa() {
}

// GXNtsc240Int
// Address: 0x806E3A48, Size: 60
void GXNtsc240Int() {
}

// GXNtsc240IntAa
// Address: 0x806E3A84, Size: 60
void GXNtsc240IntAa() {
}

// GXNtsc480IntDf
// Address: 0x806E3AC0, Size: 60
void GXNtsc480IntDf() {
}

// GXNtsc480Int
// Address: 0x806E3AFC, Size: 60
void GXNtsc480Int() {
}

// GXNtsc480IntAa
// Address: 0x806E3B38, Size: 60
void GXNtsc480IntAa() {
}

// GXNtsc480Prog
// Address: 0x806E3B74, Size: 60
void GXNtsc480Prog() {
}

// GXNtsc480ProgSoft
// Address: 0x806E3BB0, Size: 60
void GXNtsc480ProgSoft() {
}

// GXNtsc480ProgAa
// Address: 0x806E3BEC, Size: 60
void GXNtsc480ProgAa() {
}

// GXMpal240Ds
// Address: 0x806E3C28, Size: 60
void GXMpal240Ds() {
}

// GXMpal240DsAa
// Address: 0x806E3C64, Size: 60
void GXMpal240DsAa() {
}

// GXMpal240Int
// Address: 0x806E3CA0, Size: 60
void GXMpal240Int() {
}

// GXMpal240IntAa
// Address: 0x806E3CDC, Size: 60
void GXMpal240IntAa() {
}

// GXMpal480IntDf
// Address: 0x806E3D18, Size: 60
void GXMpal480IntDf() {
}

// GXMpal480Int
// Address: 0x806E3D54, Size: 60
void GXMpal480Int() {
}

// GXMpal480IntAa
// Address: 0x806E3D90, Size: 60
void GXMpal480IntAa() {
}

// GXPal264Ds
// Address: 0x806E3DCC, Size: 60
void GXPal264Ds() {
}

// GXPal264DsAa
// Address: 0x806E3E08, Size: 60
void GXPal264DsAa() {
}

// GXPal264Int
// Address: 0x806E3E44, Size: 60
void GXPal264Int() {
}

// GXPal264IntAa
// Address: 0x806E3E80, Size: 60
void GXPal264IntAa() {
}

// GXPal528IntDf
// Address: 0x806E3EBC, Size: 60
void GXPal528IntDf() {
}

// GXPal528Int
// Address: 0x806E3EF8, Size: 60
void GXPal528Int() {
}

// GXPal524IntAa
// Address: 0x806E3F34, Size: 60
void GXPal524IntAa() {
}

// GXEurgb60Hz240Ds
// Address: 0x806E3F70, Size: 60
void GXEurgb60Hz240Ds() {
}

// GXEurgb60Hz240DsAa
// Address: 0x806E3FAC, Size: 60
void GXEurgb60Hz240DsAa() {
}

// GXEurgb60Hz240Int
// Address: 0x806E3FE8, Size: 60
void GXEurgb60Hz240Int() {
}

// GXEurgb60Hz240IntAa
// Address: 0x806E4024, Size: 60
void GXEurgb60Hz240IntAa() {
}

// GXEurgb60Hz480IntDf
// Address: 0x806E4060, Size: 60
void GXEurgb60Hz480IntDf() {
}

// GXEurgb60Hz480Int
// Address: 0x806E409C, Size: 60
void GXEurgb60Hz480Int() {
}

// GXEurgb60Hz480IntAa
// Address: 0x806E40D8, Size: 60
void GXEurgb60Hz480IntAa() {
}

// GXRmHW
// Address: 0x806E4114, Size: 60
void GXRmHW() {
}

// GXTexMode0Ids
// Address: 0x8078F688, Size: 8
void GXTexMode0Ids() {
}

// GXTexMode1Ids
// Address: 0x8078F690, Size: 8
void GXTexMode1Ids() {
}

// GXTexImage0Ids
// Address: 0x8078F698, Size: 8
void GXTexImage0Ids() {
}

// GXTexImage1Ids
// Address: 0x8078F6A0, Size: 8
void GXTexImage1Ids() {
}

// GXTexImage2Ids
// Address: 0x8078F6A8, Size: 8
void GXTexImage2Ids() {
}

// GXTexImage3Ids
// Address: 0x8078F6B0, Size: 8
void GXTexImage3Ids() {
}

// GXTexTlutIds
// Address: 0x8078F6B8, Size: 8
void GXTexTlutIds() {
}

// GX2HWFiltConv
// Address: 0x8078F6C0, Size: 6
void GX2HWFiltConv() {
}

// GXOverflowSuspendInProgress
// Address: 0x807904F0, Size: 4
void GXOverflowSuspendInProgress() {
}
