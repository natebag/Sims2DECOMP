// global_apt.cpp - APT UI system globals
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 70 functions
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

// AptAuxPCEorGL_VertexMatrixId(void)
// Address: 0x8000AF1C, Size: 40
void AptAuxPCEorGL_VertexMatrixId() {
}

// AptAuxPCEorGL_PlaySavedInputs(char *, unsigned int)
// Address: 0x8000D940, Size: 56
void AptAuxPCEorGL_PlaySavedInputs() {
}

// AptAuxPCEorGL_LoadAnimation(char *, AptSharedPtr<AptFile>)
// Address: 0x8000DC30, Size: 424
void AptAuxPCEorGL_LoadAnimation() {
}

// AptAuxPCEorGL_FinishAsyncLoads(void)
// Address: 0x8000DDD8, Size: 296
void AptAuxPCEorGL_FinishAsyncLoads() {
}

// AptAuxPCEorGL_FreeConstantTable(void *)
// Address: 0x8000DF00, Size: 4
void AptAuxPCEorGL_FreeConstantTable() {
}

// AptAuxPCEorGL_FreeAnimation(void *)
// Address: 0x8000DF04, Size: 304
void AptAuxPCEorGL_FreeAnimation() {
}

// AptAuxPCEorGL_TimerInit(void)
// Address: 0x8000E034, Size: 36
void AptAuxPCEorGL_TimerInit() {
}

// AptAuxPCEorGL_TimerStartFrame(void)
// Address: 0x8000E058, Size: 32
void AptAuxPCEorGL_TimerStartFrame() {
}

// AptAuxPCEorGL_TimerGetTicks(void)
// Address: 0x8000E078, Size: 32
void AptAuxPCEorGL_TimerGetTicks() {
}

// AptAuxPCEorGL_Initialize(int, int, AptAuxFontList *)
// Address: 0x8000E098, Size: 992
void AptAuxPCEorGL_Initialize() {
}

// AptAuxPCEorGL_Shutdown(void)
// Address: 0x8000E478, Size: 196
void AptAuxPCEorGL_Shutdown() {
}

// AptAuxPCEorGLDebug_VerifyUnresolve(bool)
// Address: 0x8000E53C, Size: 8
void AptAuxPCEorGLDebug_VerifyUnresolve() {
}

// AptAuxPCEorGL_SetRC(ERC *)
// Address: 0x8000F1FC, Size: 8
void AptAuxPCEorGL_SetRC() {
}

// AptAuxPCEorGL_SetUiObject(UIObjectBase *)
// Address: 0x8000F204, Size: 160
void AptAuxPCEorGL_SetUiObject() {
}

// AptAuxPCEorGL_RemoveUiObject(UIObjectBase *)
// Address: 0x8000F2A4, Size: 140
void AptAuxPCEorGL_RemoveUiObject() {
}

// AptAuxPCEorGL_WaitOn(char *)
// Address: 0x8000F330, Size: 68
void AptAuxPCEorGL_WaitOn() {
}

// AptAuxPCEorGL_LoadFile(char *)
// Address: 0x8000F374, Size: 232
void AptAuxPCEorGL_LoadFile() {
}

// AptDebuggerPrint(int, char *,...)
// Address: 0x803E711C, Size: 152
void AptDebuggerPrint() {
}

// AptAllocatorInitialize(unsigned int, unsigned int, unsigned int, unsigned int)
// Address: 0x803E7A08, Size: 180
void AptAllocatorInitialize() {
}

// AptAllocatorShutdown(void)
// Address: 0x803E7ABC, Size: 164
void AptAllocatorShutdown() {
}

// AptInitializeGC(void)
// Address: 0x803E7B60, Size: 32
void AptInitializeGC() {
}

// AptCompleteAnimationAsyncLoad(AptSharedPtr<AptFile>, void *, void *, void *)
// Address: 0x803E7BCC, Size: 132
void AptCompleteAnimationAsyncLoad() {
}

// AptGetAnimationSize(int *, int *)
// Address: 0x803E7DB0, Size: 220
void AptGetAnimationSize() {
}

// AptSetValidFocusButton(void)
// Address: 0x803E7E8C, Size: 36
void AptSetValidFocusButton() {
}

// AptLoadAnimation(char *, char *)
// Address: 0x803E7EB8, Size: 196
void AptLoadAnimation() {
}

// AptPreloadAnimation(char *)
// Address: 0x803E7F7C, Size: 120
void AptPreloadAnimation() {
}

// AptAddCustomSavedInput(void *, unsigned int)
// Address: 0x803E7FF4, Size: 128
void AptAddCustomSavedInput() {
}

// AptCancelPreloadedAnimation(char *)
// Address: 0x803E8074, Size: 112
void AptCancelPreloadedAnimation() {
}

// AptIsFileLoaded(AptSharedPtr<AptFile>)
// Address: 0x803E80E4, Size: 124
void AptIsFileLoaded() {
}

// AptUpdate(unsigned int)
// Address: 0x803E9578, Size: 32
void AptUpdate() {
}

// AptRender(void)
// Address: 0x803E9598, Size: 32
void AptRender() {
}

// AptSetMousePosition(int, int)
// Address: 0x803E95B8, Size: 4
void AptSetMousePosition() {
}

// AptAddToInputQueue(AptInputType, AptInputState, AptInputController)
// Address: 0x803E95BC, Size: 92
void AptAddToInputQueue() {
}

// AptAddToInputAnalogQueue(AptAnalogStickInfo)
// Address: 0x803E9618, Size: 116
void AptAddToInputAnalogQueue() {
}

// AptGetInternalVariable(char *, char *)
// Address: 0x803E982C, Size: 240
void AptGetInternalVariable() {
}

// AptDebugGetCurrentFrame(int)
// Address: 0x803EA150, Size: 64
void AptDebugGetCurrentFrame() {
}

// AptDebugGetNumFrames(int)
// Address: 0x803EA190, Size: 60
void AptDebugGetNumFrames() {
}

// AptDebugIsPlaying(int)
// Address: 0x803EA1CC, Size: 112
void AptDebugIsPlaying() {
}

// AptDebugEnableSavedInputs(int)
// Address: 0x803EA23C, Size: 16
void AptDebugEnableSavedInputs() {
}

// AptDebugPlaySavedInputs(AptSavedInputRecord *, int)
// Address: 0x803EA24C, Size: 32
void AptDebugPlaySavedInputs() {
}

// AptDebugEnableInputGremlins(int)
// Address: 0x803EA26C, Size: 8
void AptDebugEnableInputGremlins() {
}

// Apt_atoff(char *)
// Address: 0x803EA274, Size: 36
void Apt_atoff() {
}

// AptDeallocateAllStrings(void)
// Address: 0x803EA298, Size: 48
void AptDeallocateAllStrings() {
}

// AptSetXMLImplementor(IAptXmlImpl *)
// Address: 0x803EA2C8, Size: 16
void AptSetXMLImplementor() {
}

// AptFlushInputQueue(void)
// Address: 0x803EA2D8, Size: 36
void AptFlushInputQueue() {
}

// AptIsMouseOverButton(void)
// Address: 0x803EA2FC, Size: 8
void AptIsMouseOverButton() {
}

// AptRegisterExtension(AptExtObject *)
// Address: 0x803EA304, Size: 168
void AptRegisterExtension() {
}

// AptUnRegisterExtension(AptExtObject *)
// Address: 0x803EA3AC, Size: 220
void AptUnRegisterExtension() {
}

// AptBreakAfterAssert(int)
// Address: 0x803EA55C, Size: 8
void AptBreakAfterAssert() {
}

// AptPartialGarbageCollection(void)
// Address: 0x803EA564, Size: 12
void AptPartialGarbageCollection() {
}

// AptSetSwfVersion(int)
// Address: 0x803EA570, Size: 8
void AptSetSwfVersion() {
}

// AptGetSwfVersion(void)
// Address: 0x803EA578, Size: 8
void AptGetSwfVersion() {
}

// AptDebugPrintZombieVector(void)
// Address: 0x803EA580, Size: 4
void AptDebugPrintZombieVector() {
}

// AptGetMouseOverSpriteName(char *)
// Address: 0x803EA76C, Size: 16
void AptGetMouseOverSpriteName() {
}

// AptRegisterGlobalReferences(void)
// Address: 0x803EA77C, Size: 56
void AptRegisterGlobalReferences() {
}

// AptGetMovieclipInfo(AptMovieclipInformation *)
// Address: 0x803EA7B4, Size: 60
void AptGetMovieclipInfo() {
}

// AptHasRenderData(void)
// Address: 0x803EA7F0, Size: 44
void AptHasRenderData() {
}

// AptGetTotalMemoryAllocations(AptMemoryAllocationsT *)
// Address: 0x803EA81C, Size: 32
void AptGetTotalMemoryAllocations() {
}

// AptGetMemoryAllocationsInLastUpdate(AptMemoryAllocationsT *)
// Address: 0x803EA83C, Size: 32
void AptGetMemoryAllocationsInLastUpdate() {
}

// AptGetTypeOfAptValue(AptValue *)
// Address: 0x803EA85C, Size: 60
void AptGetTypeOfAptValue() {
}

// AptGetSizeOfAptValue(AptValue *)
// Address: 0x803EA898, Size: 40
void AptGetSizeOfAptValue() {
}

// AptFileNameCompare(char *, char *)
// Address: 0x8041CD40, Size: 240
void AptFileNameCompare() {
}

// AptSharedPtrDelete(AptFile *)
// Address: 0x8041FAE0, Size: 132
void AptSharedPtrDelete() {
}

// AptRand(void)
// Address: 0x80429B9C, Size: 124
void AptRand() {
}

// AptValueInitialize(void)
// Address: 0x80431098, Size: 2000
void AptValueInitialize() {
}

// AptValueShutdown(int)
// Address: 0x80431868, Size: 1116
void AptValueShutdown() {
}

// AptHeap(void)
// Address: 0x804680C4, Size: 116
void AptHeap() {
}

// AptHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD430, Size: 40
void AptHeapFreeMemory() {
}

// AptValueSizesByVType
// Address: 0x80673CEC, Size: 47
void AptValueSizesByVType() {
}

// apt
// Address: 0x8073CAB0, Size: 76
void apt() {
}
