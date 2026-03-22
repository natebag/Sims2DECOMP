// global_game_logic.cpp - Game logic functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 55 functions
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

// GetHandleFromISimInstance(ISimInstance *)
// Address: 0x8008B53C, Size: 344
void GetHandleFromISimInstance(ISimInstance * p0) {
}

// GetObjectInstance(unsigned int)
// Address: 0x8008B694, Size: 116
void GetObjectInstance(unsigned int p0) {
}

// dummyTrace(char *,...)
// Address: 0x80098E80, Size: 76
void dummyTrace(char * p0, ... p1) {
}

// GetMotiveMag(float)
// Address: 0x800A7004, Size: 72
void GetMotiveMag(float p0) {
}

// Timer_Init(EClock *)
// Address: 0x800CBCB8, Size: 132
void Timer_Init(EClock * p0) {
}

// Timer_SetFrameDelta(float)
// Address: 0x800CBD3C, Size: 68
void Timer_SetFrameDelta(float p0) {
}

// RainSplashParticleBirthCB(pemitter *, PVector4 *, PVector4 *)
// Address: 0x800D31D0, Size: 192
void RainSplashParticleBirthCB(pemitter * p0, PVector4 * p1, PVector4 * p2) {
}

// RainSplashEmitterProcessCB(void *)
// Address: 0x800D3290, Size: 1000
void RainSplashEmitterProcessCB(void * p0) {
}

// CatWsABToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, unsigned int)
// Address: 0x800D50E8, Size: 136
void CatWsABToBuff(unsigned wchar_t * p0, unsigned wchar_t * p1, unsigned wchar_t * p2, unsigned int p3) {
}

// CatWsAToBuff(unsigned wchar_t *, unsigned wchar_t *, unsigned int)
// Address: 0x800D5170, Size: 128
void CatWsAToBuff(unsigned wchar_t * p0, unsigned wchar_t * p1, unsigned int p2) {
}

// FloatToWString(float, unsigned wchar_t *, unsigned int)
// Address: 0x800D51F0, Size: 116
void FloatToWString(float p0, unsigned wchar_t * p1, unsigned int p2) {
}

// IntToWString(int, unsigned wchar_t *, unsigned int, int)
// Address: 0x800D5264, Size: 160
void IntToWString(int p0, unsigned wchar_t * p1, unsigned int p2, int p3) {
}

// CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int)
// Address: 0x800D5304, Size: 80
void CopyCharStrToWString(char * p0, unsigned wchar_t * p1, unsigned int p2) {
}

// CopyWStringToCharStr(unsigned wchar_t *, char *, unsigned int)
// Address: 0x800D5354, Size: 80
void CopyWStringToCharStr(unsigned wchar_t * p0, char * p1, unsigned int p2) {
}

// SubstituteString(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, StackString2<256> &)
// Address: 0x800D53A4, Size: 552
void SubstituteString(unsigned wchar_t * p0, unsigned wchar_t * p1, unsigned wchar_t * p2, StackString2<256> & p3) {
}

// SubstituteStringAll(unsigned wchar_t *, unsigned wchar_t *, unsigned wchar_t *, StackString2<256> &)
// Address: 0x800D5674, Size: 172
void SubstituteStringAll(unsigned wchar_t * p0, unsigned wchar_t * p1, unsigned wchar_t * p2, StackString2<256> & p3) {
}

// GetTimeString(int, int, unsigned wchar_t *, StackString2<256> &)
// Address: 0x800D5918, Size: 696
void GetTimeString(int p0, int p1, unsigned wchar_t * p2, StackString2<256> & p3) {
}

// GetMoneyString(int, StackString2<256> &, bool)
// Address: 0x800D5BD0, Size: 676
void GetMoneyString(int p0, StackString2<256> & p1, bool p2) {
}

// ReplaceButtonPrompts(unsigned wchar_t *, StackString2<256> &)
// Address: 0x800D67E0, Size: 2416
void ReplaceButtonPrompts(unsigned wchar_t * p0, StackString2<256> & p1) {
}

// DlgReplaceButtonPrompts(unsigned wchar_t *, BString2 &)
// Address: 0x800D7150, Size: 452
void DlgReplaceButtonPrompts(unsigned wchar_t * p0, BString2 & p1) {
}

// QueryPerformanceCounter(long long *)
// Address: 0x800D8240, Size: 164
void QueryPerformanceCounter(long long * p0) {
}

// InitPerformanceCounter(void)
// Address: 0x800D82E4, Size: 84
void InitPerformanceCounter() {
}

// GetTimeDate(void)
// Address: 0x800D8338, Size: 108
void GetTimeDate() {
}

// timeGetTime(void)
// Address: 0x800D83A4, Size: 152
void timeGetTime() {
}

// LoadLevelGlobalData(void)
// Address: 0x800F45EC, Size: 228
void LoadLevelGlobalData() {
}

// LoadHousePreloadDataset(char *)
// Address: 0x800F47F0, Size: 84
void LoadHousePreloadDataset(char * p0) {
}

// LssDummyPrintf(char *,...)
// Address: 0x801001FC, Size: 76
void LssDummyPrintf(char * p0, ... p1) {
}

// THREADEXEC_MU_SaveNewGame(void)
// Address: 0x80100698, Size: 64
void THREADEXEC_MU_SaveNewGame() {
}

// BGCall_SetDefaults(void)
// Address: 0x801135EC, Size: 144
void BGCall_SetDefaults() {
}

// localConvertFromWide(char *, unsigned wchar_t *)
// Address: 0x8011BDDC, Size: 48
void localConvertFromWide(char * p0, unsigned wchar_t * p1) {
}

// localConvertToWide(unsigned wchar_t *, char *)
// Address: 0x8011FFDC, Size: 44
void localConvertToWide(unsigned wchar_t * p0, char * p1) {
}

// AltToIso(float &)
// Address: 0x801249A8, Size: 108
void AltToIso(float & p0) {
}

// IsoToAlt(float &)
// Address: 0x80124A14, Size: 96
void IsoToAlt(float & p0) {
}

// IsoFracsToWorld(float &, float &, float &)
// Address: 0x80124B44, Size: 108
void IsoFracsToWorld(float & p0, float & p1, float & p2) {
}

// IsoToWorld(FTilePt &, float &)
// Address: 0x80124BB0, Size: 176
void IsoToWorld(FTilePt & p0, float & p1) {
}

// WorldToIso(EVec3 &)
// Address: 0x80124C60, Size: 268
void WorldToIso(EVec3 & p0) {
}

// ObjectRotationTf(int)
// Address: 0x80124D6C, Size: 124
void ObjectRotationTf(int p0) {
}

// RotationTf(RotationAxis, float &)
// Address: 0x80124DE8, Size: 880
void RotationTf(RotationAxis p0, float & p1) {
}

// ExtractDirectory(StringBuffer &, StringBuffer &)
// Address: 0x80126830, Size: 100
void ExtractDirectory(StringBuffer & p0, StringBuffer & p1) {
}

// ExtractFileName(StringBuffer &, StringBuffer &)
// Address: 0x80126894, Size: 116
void ExtractFileName(StringBuffer & p0, StringBuffer & p1) {
}

// ExtractExtension(StringBuffer &, StringBuffer &, StringBuffer &)
// Address: 0x80126908, Size: 136
void ExtractExtension(StringBuffer & p0, StringBuffer & p1, StringBuffer & p2) {
}

// WriteHandleToFile(Memory::HandleNode *, char *)
// Address: 0x80126990, Size: 224
void WriteHandleToFile(Memory::HandleNode * p0, char * p1) {
}

// GetNextRandomNumber(void)
// Address: 0x80127518, Size: 76
void GetNextRandomNumber() {
}

// Swizzle8(void *)
// Address: 0x801294C8, Size: 88
void Swizzle8(void * p0) {
}

// Swizzle4(void *)
// Address: 0x80129520, Size: 88
void Swizzle4(void * p0) {
}

// castSkillToString(AnimRef *)
// Address: 0x8012DFF0, Size: 68
void castSkillToString(AnimRef * p0) {
}

// WaitForControllerButton(bool)
// Address: 0x80131534, Size: 584
void WaitForControllerButton(bool p0) {
}

// FindStringSet(VECTOR<WStringSet> &, short, int)
// Address: 0x80138B2C, Size: 96
void FindStringSet(VECTOR<WStringSet> & p0, short p1, int p2) {
}

// GetComeSeeMe(cXObject *)
// Address: 0x8013BC10, Size: 344
void GetComeSeeMe(cXObject * p0) {
}

// RemoveComeSeeMeObjects(void)
// Address: 0x8013BD68, Size: 196
void RemoveComeSeeMeObjects() {
}

// UpdateComeSeeMeObjects(void)
// Address: 0x8013BE2C, Size: 772
void UpdateComeSeeMeObjects() {
}

// GlobalDispatch(short, int)
// Address: 0x8013C260, Size: 120
void GlobalDispatch(short p0, int p1) {
}

// TypedDispatch(int, short, int, bool)
// Address: 0x8013C2D8, Size: 168
void TypedDispatch(int p0, short p1, int p2, bool p3) {
}

// CBMemberTranslator1<int, EdithDialogPrimitive, void (EdithDialogPrimitive::*)(EdithDialogPrimitive *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8013E628, Size: 120
CBMemberTranslator1<int, EdithDialogPrimitive, void(EdithDialogPrimitive::* p0) {
    return 0;
}

// Additional instantiation: CBMemberTranslator0<EdithDialogPrimitive, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8013E6A0, Size: 120
