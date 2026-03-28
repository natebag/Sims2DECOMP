// global_game_core.cpp - Core game functions (low address)
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 52 functions
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

// GetGameFontID(void)
// Address: 0x80009BAC, Size: 40
void GetGameFontID() {
}

// command(char *, char *)
// Address: 0x80009EFC, Size: 4
void command() {
}

// setExternVariable(char *, char *)
// Address: 0x80009F00, Size: 528
void setExternVariable() {
}

// loadVariables(char *)
// Address: 0x8000A110, Size: 40
void loadVariables() {
}

// loadVariablesNULL(void)
// Address: 0x8000A138, Size: 40
void loadVariablesNULL() {
}

// sendVariables(char *, char *, char *, char *, int)
// Address: 0x8000A160, Size: 4
void sendVariables() {
}

// pointHitTest(float, float, void *)
// Address: 0x8000A164, Size: 8
void pointHitTest() {
}

// getRealTimeClock(AptSysClock *, bool)
// Address: 0x8000A16C, Size: 4
void getRealTimeClock() {
}

// getBytesTotal(char *, AptGetBytesEnum)
// Address: 0x8000A170, Size: 8
void getBytesTotal() {
}

// getBytesLoaded(char *, AptGetBytesEnum)
// Address: 0x8000A178, Size: 8
void getBytesLoaded() {
}

// getStageWidth(void)
// Address: 0x8000A180, Size: 12
void getStageWidth() {
}

// getStageHeight(void)
// Address: 0x8000A18C, Size: 12
void getStageHeight() {
}

// getExternVariable(char *)
// Address: 0x8000A198, Size: 900
void getExternVariable() {
}

// loadTexture(void *, int)
// Address: 0x8000A7E4, Size: 1092
void loadTexture() {
}

// freeTexture(void *)
// Address: 0x8000AC28, Size: 184
void freeTexture() {
}

// bindTexture(void *, int, void *)
// Address: 0x8000ACE0, Size: 484
void bindTexture() {
}

// setColourTransform(AptCXForm *)
// Address: 0x8000AEC4, Size: 88
void setColourTransform() {
}

// setVertexMatrix(AptMatrix *)
// Address: 0x8000AF44, Size: 60
void setVertexMatrix() {
}

// loadSound(void *, int, char *)
// Address: 0x8000AF80, Size: 100
void loadSound() {
}

// startSoundStream(void *, int)
// Address: 0x8000AFE4, Size: 96
void startSoundStream() {
}

// startSound(void *, char *)
// Address: 0x8000B044, Size: 96
void startSound() {
}

// freeSound(void *)
// Address: 0x8000B0A4, Size: 168
void freeSound() {
}

// setBackgroundColour(unsigned int)
// Address: 0x8000B14C, Size: 4
void setBackgroundColour() {
}

// myassert(char *, char *, unsigned int)
// Address: 0x8000B150, Size: 100
void myassert() {
}

// loadRenderingUnit(void *, int)
// Address: 0x8000B1B4, Size: 136
void loadRenderingUnit() {
}

// freeRenderingUnit(void *)
// Address: 0x8000B23C, Size: 96
void freeRenderingUnit() {
}

// drawRenderingUnit(void *, AptMaskRenderOperation)
// Address: 0x8000B29C, Size: 224
void drawRenderingUnit() {
}

// customControlRender(char *, char *, void *, char *)
// Address: 0x8000B37C, Size: 4952
void customControlRender() {
}

// allocateString(AptAllocateStringParameters *)
// Address: 0x8000C6D4, Size: 1340
void allocateString() {
}

// drawStringEor(void *, AptMaskRenderOperation)
// Address: 0x8000CE94, Size: 2580
void drawStringEor() {
}

// deallocateString(void *, unsigned int)
// Address: 0x8000D8A8, Size: 152
void deallocateString() {
}

// hardwareInit(float, float)
// Address: 0x8000D978, Size: 4
void hardwareInit() {
}

// LoadThreadProc(void *)
// Address: 0x8000D97C, Size: 692
void LoadThreadProc() {
}

// GetScaledVertexColor(unsigned int *, unsigned int)
// Address: 0x8000E544, Size: 656
void GetScaledVertexColor() {
}

// UCS2ToUTF8(unsigned wchar_t *, int, char *)
// Address: 0x8000F514, Size: 188
void UCS2ToUTF8() {
}

// UTF8ToUCS2(char *, int, unsigned wchar_t *)
// Address: 0x8000F5D0, Size: 448
void UTF8ToUCS2() {
}

// GetPixelXSize(void)
// Address: 0x80012A60, Size: 12
void GetPixelXSize() {
}

// CreateAptViewer(void)
// Address: 0x800155D4, Size: 64
void CreateAptViewer() {
}

// closeFunc(void)
// Address: 0x80015618, Size: 44
void closeFunc() {
}

// updateFunc(void)
// Address: 0x80015644, Size: 108
void updateFunc() {
}

// StartItAll(void)
// Address: 0x800156B0, Size: 232
void StartItAll() {
}

// DummyPrintf(char *,...)
// Address: 0x800190BC, Size: 76
void DummyPrintf() {
}

// BGCall_LoadDefaultNeighborhood(void)
// Address: 0x8001E114, Size: 144
void BGCall_LoadDefaultNeighborhood() {
}

// BGExec_LoadHouse(void)
// Address: 0x8001E1A4, Size: 156
void BGExec_LoadHouse() {
}

// BGCall_LoadHouse(void)
// Address: 0x8001E240, Size: 144
void BGCall_LoadHouse() {
}

// BGCall_CurHouseInit(void)
// Address: 0x8001E344, Size: 144
void BGCall_CurHouseInit() {
}

// BGCall_FlushResQueue(void)
// Address: 0x8001E464, Size: 144
void BGCall_FlushResQueue() {
}

// BGCall_SetCurHouse(void)
// Address: 0x8001E56C, Size: 144
void BGCall_SetCurHouse() {
}

// BGExec_CASTargetInit(void)
// Address: 0x8001E62C, Size: 184
void BGExec_CASTargetInit() {
}

// BGCall_CASTargetInit(bool)
// Address: 0x8001E6E4, Size: 152
void BGCall_CASTargetInit() {
}

// BGCall_ReloadObjectQuickdata(void)
// Address: 0x8001E7F0, Size: 144
void BGCall_ReloadObjectQuickdata() {
}

// BGCall_CASCGEGenerateStage(void)
// Address: 0x8001E91C, Size: 144
void BGCall_CASCGEGenerateStage() {
}
