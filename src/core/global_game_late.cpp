// global_game_late.cpp - Late-linked game functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 392 functions
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

// GetIndividualMemory(int, int)
// Address: 0x80201E08, Size: 124
void GetIndividualMemory(int p0, int p1) {
}

// SetIndividualMemory(int &, int, int)
// Address: 0x80201E84, Size: 212
void SetIndividualMemory(int & p0, int p1, int p2) {
}

// SetupMatrixAndKey(int, int, RelMatrix *&, int &)
// Address: 0x80201F58, Size: 468
void SetupMatrixAndKey(int p0, int p1, RelMatrix *& p2, int & p3) {
}

// ReconExpReport(ExpenseReport *, ReconBuffer *)
// Address: 0x80202898, Size: 148
void ReconExpReport(ExpenseReport * p0, ReconBuffer * p1) {
}

// ReportMissingAnimation(cXObject *, cXPerson *, AnimTable *, int)
// Address: 0x80204988, Size: 212
void ReportMissingAnimation(cXObject * p0, cXPerson * p1, AnimTable * p2, int p3) {
}

// InitSkillLookup(void)
// Address: 0x80204A5C, Size: 1188
void InitSkillLookup() {
}

// resolveSkillForPassiveInfluence(cXObject *, StackElem *, AnimateNewParam *, AnimRef *&)
// Address: 0x80204F38, Size: 348
void resolveSkillForPassiveInfluence(cXObject * p0, StackElem * p1, AnimateNewParam * p2, AnimRef *& p3) {
}

// GetStdAnimRef(cXPerson *, StdAnimIdx, AnimRef *&)
// Address: 0x80205094, Size: 536
void GetStdAnimRef(cXPerson * p0, StdAnimIdx p1, AnimRef *& p2) {
}

// GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&)
// Address: 0x802052AC, Size: 124
void GetReachAnimRef(cXPerson * p0, ReachAnimIdx p1, AnimRef *& p2) {
}

// GetMiscAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x80205328, Size: 140
void GetMiscAnimRef(cXPerson * p0, int p1, AnimRef *& p2) {
}

// GetObjectAnimRef(cXObject *, cXPerson *, int, bool, AnimRef *&)
// Address: 0x802053B4, Size: 524
void GetObjectAnimRef(cXObject * p0, cXPerson * p1, int p2, bool p3, AnimRef *& p4) {
}

// GetObjectAnimRefPassiveInfluence(cXObject *, int, AnimRef *&)
// Address: 0x802055C0, Size: 148
void GetObjectAnimRefPassiveInfluence(cXObject * p0, int p1, AnimRef *& p2) {
}

// GetPersonStockAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x80205654, Size: 140
void GetPersonStockAnimRef(cXPerson * p0, int p1, AnimRef *& p2) {
}

// GetGlobalAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x802056E0, Size: 140
void GetGlobalAnimRef(cXPerson * p0, int p1, AnimRef *& p2) {
}

// SectWall(FTileRect *, int)
// Address: 0x8020FE6C, Size: 588
void SectWall(FTileRect * p0, int p1) {
}

// ValidDoorLocation(int, int, int, int, int)
// Address: 0x802100B8, Size: 860
void ValidDoorLocation(int p0, int p1, int p2, int p3, int p4) {
}

// CheckWallFlags(FTilePt, int, int, int)
// Address: 0x802104B4, Size: 1004
void CheckWallFlags(FTilePt p0, int p1, int p2, int p3) {
}

// DestroyTheWorld(void)
// Address: 0x8021BE80, Size: 76
void DestroyTheWorld() {
}

// ValidateTheWorld(void)
// Address: 0x8021BECC, Size: 80
void ValidateTheWorld() {
}

// TransformToWorldCoords(FTilePt *, float, float, int, FTilePt *)
// Address: 0x8021D07C, Size: 672
void TransformToWorldCoords(FTilePt * p0, float p1, float p2, int p3, FTilePt * p4) {
}

// Stuck(vector<PenaltyRect, allocator<PenaltyRect> > *, IPoint *)
// Address: 0x80220460, Size: 136
void Stuck(vector<PenaltyRect, allocator<PenaltyRect> > * p0, IPoint * p1) {
}

// SetDirectionForGoalSearch(cXObject *, short, short, RoutingSlot *)
// Address: 0x80222CD8, Size: 256
void SetDirectionForGoalSearch(cXObject * p0, short p1, short p2, RoutingSlot * p3) {
}

// CollapsePenaltyRects(vector<PenaltyRect, allocator<PenaltyRect> > &)
// Address: 0x80224800, Size: 756
void CollapsePenaltyRects(vector<PenaltyRect, allocator<PenaltyRect> > & p0) {
}

// GetSmartDataFactory(void)
// Address: 0x80229394, Size: 132
void GetSmartDataFactory() {
}

// CasEventDummyPrintf(char *,...)
// Address: 0x8022F8E4, Size: 76
void CasEventDummyPrintf(char * p0, ... p1) {
}

// emptyTrace(char *,...)
// Address: 0x802357F8, Size: 76
void emptyTrace(char * p0, ... p1) {
}

// AutoTestingInitialize(char *)
// Address: 0x8023C3F8, Size: 68
void AutoTestingInitialize(char * p0) {
}

// AutoTestingUpdate(bool)
// Address: 0x8023C43C, Size: 504
void AutoTestingUpdate(bool p0) {
}

// AutoTestingExit(void)
// Address: 0x8023C634, Size: 48
void AutoTestingExit() {
}

// CasSimDescriptionS2C ** __unguarded_partition<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8024001C, Size: 156
CasSimDescriptionS2C ** __unguarded_partition<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool(* p0) {
    return 0;
}

// Additional instantiation: void __introsort_loop<CasSimDescriptionS2C **, CasSimDescriptionS2C *, int, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * *, int, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x802400B8, Size: 344

// Additional instantiation: void __unguarded_linear_insert<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x80240210, Size: 96

// Additional instantiation: void __unguarded_insertion_sort_aux<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x80240314, Size: 84

// Additional instantiation: CasSimDescriptionS2C ** __lower_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * &, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int *)
// Address: 0x80240458, Size: 128

// Additional instantiation: CasSimDescriptionS2C ** __upper_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * &, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int *)
// Address: 0x802404D8, Size: 128

// CBMemberTranslator1<int, HelpDialog, void (HelpDialog::*)(HelpDialog *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8026CC64, Size: 120
CBMemberTranslator1<int, HelpDialog, void(HelpDialog::* p0) {
    return 0;
}

// Additional instantiation: CBMemberTranslator0<HelpDialog, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8026CCDC, Size: 120

// Additional instantiation: CBMemberTranslator0<UI3D, void (UI3D::*)(UI3D *)>::thunk(CBFunctorBase &)
// Address: 0x8026E190, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, UIDBTarget, void (UIDBTarget::*)(UIDBTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80273604, Size: 120

// Additional instantiation: CBMemberTranslator0<UIDBTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802736F4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, UIDBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027376C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, FlowGotoTarget, void (FlowGotoTarget::*)(FlowGotoTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80274EFC, Size: 120

// Additional instantiation: CBMemberTranslator0<FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x80274FEC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80275064, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802774DC, Size: 120

// Additional instantiation: CBMemberTranslator0<UIQDTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802775CC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80277644, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, UIScreenManager, void (UIScreenManager::*)(UIScreenManager *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027B560, Size: 120

// Additional instantiation: CBMemberTranslator0<UIScreenManager, void (UIScreenManager::*)(UIScreenManager *)>::thunk(CBFunctorBase &)
// Address: 0x8027B650, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, UIScreenManager, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027B6C8, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, UIAUDIOTarget, void (UIAUDIOTarget::*)(UIAUDIOTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027D684, Size: 120

// Additional instantiation: CBMemberTranslator0<UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8027D774, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027D7EC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027D8DC, Size: 120

// Additional instantiation: CBMemberTranslator0<UIAnalog, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8027D9CC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027DA44, Size: 120

// GetActionMenu(unsigned int)
// Address: 0x8028102C, Size: 224
void GetActionMenu(unsigned int p0) {
}

// GetSelectedActionMenuItem(unsigned int)
// Address: 0x8028110C, Size: 32
void GetSelectedActionMenuItem(unsigned int p0) {
}

// CUCS2ToUTF8(unsigned wchar_t *, int, char *)
// Address: 0x8028540C, Size: 32
void CUCS2ToUTF8(unsigned wchar_t * p0, int p1, char * p2) {
}

// GetTutorialLocks(int)
// Address: 0x8028542C, Size: 32
void GetTutorialLocks(int p0) {
}

// Additional instantiation: CBMemberTranslator2<char *, char *, HUDTarget, void (HUDTarget::*)(HUDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8028D498, Size: 120

// Additional instantiation: CBMemberTranslator0<HUDTarget, void (HUDTarget::*)(HUDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8028D588, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, HUDTarget, void (HUDTarget::*)(HUDTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8028D600, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80291774, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802918DC, Size: 120

// Additional instantiation: CBMemberTranslator1<int, LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x80291954, Size: 120

// Additional instantiation: CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x802919CC, Size: 144

// Additional instantiation: CBMemberTranslator2<char *, char *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80295DCC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80295F34, Size: 120

// Additional instantiation: CBMemberTranslator1<int, SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x80295FAC, Size: 120

// Additional instantiation: CBMemberTranslator0<SaveGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x80296024, Size: 144

// SaveGame(bool, bool)
// Address: 0x80297694, Size: 1304
void SaveGame(bool p0, bool p1) {
}

// RefreshStats(void)
// Address: 0x80298694, Size: 4
void RefreshStats() {
}

// Additional instantiation: CBMemberTranslator2<char *, char *, CASTarget, void (CASTarget::*)(CASTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AE610, Size: 120

// Additional instantiation: CBMemberTranslator0<CASTarget, void (CASTarget::*)(CASTarget *)>::thunk(CBFunctorBase &)
// Address: 0x802AE700, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASTarget, void (CASTarget::*)(CASTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AE778, Size: 120

// Additional instantiation: CBMemberTranslator1<int, CASTarget, void (CASTarget::*)(CASTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x802AE7F0, Size: 120

// Additional instantiation: CBMemberTranslator0<UIDialog, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x802AE868, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASBodyTarget, void (CASBodyTarget::*)(CASBodyTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AE958, Size: 120

// Additional instantiation: CBMemberTranslator0<CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AEA48, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AEAC0, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AEBB0, Size: 120

// Additional instantiation: CBMemberTranslator0<CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *)>::thunk(CBFunctorBase &)
// Address: 0x802AECA0, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AED18, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASSelectionTarget, void (CASSelectionTarget::*)(CASSelectionTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AEE08, Size: 120

// Additional instantiation: CBMemberTranslator0<CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AEEF8, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AEF70, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASFashionTarget, void (CASFashionTarget::*)(CASFashionTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF060, Size: 120

// Additional instantiation: CBMemberTranslator0<CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF150, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF1C8, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASMiscTarget, void (CASMiscTarget::*)(CASMiscTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF2B8, Size: 120

// Additional instantiation: CBMemberTranslator0<CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF3A8, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF420, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASMorphTarget, void (CASMorphTarget::*)(CASMorphTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF510, Size: 120

// Additional instantiation: CBMemberTranslator0<CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF600, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF678, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASPersonalTarget, void (CASPersonalTarget::*)(CASPersonalTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF768, Size: 120

// Additional instantiation: CBMemberTranslator0<CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF858, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF8D0, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASTattooTarget, void (CASTattooTarget::*)(CASTattooTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AFA30, Size: 120

// Additional instantiation: CBMemberTranslator0<CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AFB20, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AFB98, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AFC88, Size: 120

// Additional instantiation: CBMemberTranslator0<CASRoommateTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AFD78, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AFDF0, Size: 120

// get_cooking_steps_csv(int, char *)
// Address: 0x8030552C, Size: 392
void get_cooking_steps_csv(int p0, char * p1) {
}

// DEBUG_DUMP_RECIPE(unsigned int, RCPTarget::Recipe &)
// Address: 0x803056B4, Size: 484
void DEBUG_DUMP_RECIPE(unsigned int p0, RCPTarget::Recipe & p1) {
}

// Additional instantiation: CBMemberTranslator2<char *, char *, ACTTarget, void (ACTTarget::*)(ACTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x803192D4, Size: 120

// Additional instantiation: CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x803193C4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031943C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, BBHTarget, void (BBHTarget::*)(BBHTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031952C, Size: 120

// Additional instantiation: CBMemberTranslator0<BBHTarget, void (BBHTarget::*)(BBHTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031961C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, BBHTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319694, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CRDTarget, void (CRDTarget::*)(CRDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80319B14, Size: 120

// Additional instantiation: CBMemberTranslator0<CRDTarget, void (CRDTarget::*)(CRDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80319C04, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319C7C, Size: 120

// Additional instantiation: CBMemberTranslator2<ERC *, structDrawCBparams *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x80319CF4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CSMTarget, void (CSMTarget::*)(CSMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80319DE4, Size: 120

// Additional instantiation: CBMemberTranslator0<CSMTarget, void (CSMTarget::*)(CSMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80319ED4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CSMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319F4C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, CSPTarget, void (CSPTarget::*)(CSPTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A03C, Size: 120

// Additional instantiation: CBMemberTranslator0<CSPTarget, void (CSPTarget::*)(CSPTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A12C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, CSPTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A1A4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, E2ETarget, void (E2ETarget::*)(E2ETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A2A4, Size: 120

// Additional instantiation: CBMemberTranslator0<E2ETarget, void (E2ETarget::*)(E2ETarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A394, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, E2ETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A40C, Size: 120

// Additional instantiation: CBMemberTranslator2<ERC *, structDrawCBparams *, E2ETarget, void (E2ETarget::*)(E2ETarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8031A484, Size: 120

// Additional instantiation: CBMemberTranslator1<int, E2ETarget, void (E2ETarget::*)(E2ETarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031A4FC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, FAMTarget, void (FAMTarget::*)(FAMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A788, Size: 120

// Additional instantiation: CBMemberTranslator0<FAMTarget, void (FAMTarget::*)(FAMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A878, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, FAMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A8F0, Size: 120

// Additional instantiation: CBMemberTranslator1<int, FAMTarget, void (FAMTarget::*)(FAMTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031A968, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, FCMTarget, void (FCMTarget::*)(FCMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031AA58, Size: 120

// Additional instantiation: CBMemberTranslator0<FCMTarget, void (FCMTarget::*)(FCMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031AB48, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, FCMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031ABC0, Size: 120

// G2DDummyPrintf(char *,...)
// Address: 0x8031AC38, Size: 76
void G2DDummyPrintf(char * p0, ... p1) {
}

// Additional instantiation: CBMemberTranslator2<char *, char *, G2DTarget, void (G2DTarget::*)(G2DTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031ACFC, Size: 120

// Additional instantiation: CBMemberTranslator0<G2DTarget, void (G2DTarget::*)(G2DTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031ADEC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, G2DTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031AE64, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, H2DTarget, void (H2DTarget::*)(H2DTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031AF54, Size: 120

// Additional instantiation: CBMemberTranslator0<H2DTarget, void (H2DTarget::*)(H2DTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B044, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, H2DTarget, void (H2DTarget::*)(H2DTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B0BC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, INGTarget, void (INGTarget::*)(INGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B1AC, Size: 120

// Additional instantiation: CBMemberTranslator0<INGTarget, void (INGTarget::*)(INGTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B29C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, INGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B314, Size: 120

// Additional instantiation: CBMemberTranslator1<int, INGTarget, void (INGTarget::*)(INGTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031B38C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, ITBTarget, void (ITBTarget::*)(ITBTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B4F4, Size: 120

// Additional instantiation: CBMemberTranslator0<ITBTarget, void (ITBTarget::*)(ITBTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B5E4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, ITBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B65C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, K2YTarget, void (K2YTarget::*)(K2YTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B76C, Size: 120

// Additional instantiation: CBMemberTranslator0<K2YTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031B85C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, K2YTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B8D4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, M2MTarget, void (M2MTarget::*)(M2MTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B9C4, Size: 120

// Additional instantiation: CBMemberTranslator0<M2MTarget, void (M2MTarget::*)(M2MTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BAB4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, M2MTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031BB2C, Size: 120

// Additional instantiation: CBMemberTranslator1<int, M2MTarget, void (M2MTarget::*)(M2MTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031BBA4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, MDITarget, void (MDITarget::*)(MDITarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031BC94, Size: 120

// Additional instantiation: CBMemberTranslator0<MDITarget, void (MDITarget::*)(MDITarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BD84, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, MDITarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031BDFC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, MMUTarget, void (MMUTarget::*)(MMUTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031BEEC, Size: 120

// Additional instantiation: CBMemberTranslator0<MMUTarget, void (MMUTarget::*)(MMUTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BFDC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, MMUTarget, void (MMUTarget::*)(MMUTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C054, Size: 120

// Additional instantiation: CBMemberTranslator1<int, MMUTarget, void (MMUTarget::*)(MMUTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031C0CC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, MODTarget, void (MODTarget::*)(MODTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C1BC, Size: 120

// Additional instantiation: CBMemberTranslator0<MODTarget, void (MODTarget::*)(MODTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031C2AC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, MODTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C324, Size: 120

// Additional instantiation: CBMemberTranslator2<ERC *, structDrawCBparams *, MODTarget, void (MODTarget::*)(MODTarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8031C39C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, MOTTarget, void (MOTTarget::*)(MOTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C48C, Size: 120

// Additional instantiation: CBMemberTranslator0<MOTTarget, void (MOTTarget::*)(MOTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031C57C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, MOTTarget, void (MOTTarget::*)(MOTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C5F4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, O2TTarget, void (O2TTarget::*)(O2TTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C6E4, Size: 120

// Additional instantiation: CBMemberTranslator0<O2TTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031C7D4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, O2TTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C84C, Size: 120

// Additional instantiation: CBMemberTranslator1<int, O2TTarget, void (O2TTarget::*)(O2TTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031C93C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, PAZTarget, void (PAZBase::*)(PAZBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031CABC, Size: 120

// Additional instantiation: CBMemberTranslator0<PAZTarget, void (PAZBase::*)(PAZBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031CBAC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PAZTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031CC24, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, PZ1Target, void (PAZBase::*)(PAZBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031CD14, Size: 120

// Additional instantiation: CBMemberTranslator0<PZ1Target, void (PAZBase::*)(PAZBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031CE04, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PZ1Target, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031CE7C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, PCTTarget, void (PCTTarget::*)(PCTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D070, Size: 120

// Additional instantiation: CBMemberTranslator0<PCTTarget, void (PCTTarget::*)(PCTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D160, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PCTTarget, void (PCTTarget::*)(PCTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D1D8, Size: 120

// Additional instantiation: CBMemberTranslator1<int, PCTTarget, void (PCTTarget::*)(PCTTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031D250, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, PRGTarget, void (PRGTarget::*)(PRGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D340, Size: 120

// Additional instantiation: CBMemberTranslator0<PRGTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031D430, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PRGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D4A8, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, R2LTarget, void (R2LTarget::*)(R2LTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D598, Size: 120

// Additional instantiation: CBMemberTranslator0<R2LTarget, void (R2LTarget::*)(R2LTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D688, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, R2LTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D700, Size: 120

// Additional instantiation: CBMemberTranslator1<int, R2LTarget, void (R2LTarget::*)(R2LTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031D778, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, RCPTarget, void (RCPTarget::*)(RCPTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D868, Size: 120

// Additional instantiation: CBMemberTranslator0<RCPTarget, void (RCPTarget::*)(RCPTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D958, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, RCPTarget, void (RCPTarget::*)(RCPTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D9D0, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, RMDTarget, void (RMDTarget::*)(RMDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DAC0, Size: 120

// Additional instantiation: CBMemberTranslator0<RMDTarget, void (RMDTarget::*)(RMDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031DBB0, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, RMDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031DC28, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, SKLTarget, void (SKLTarget::*)(SKLTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DD18, Size: 120

// Additional instantiation: CBMemberTranslator0<SKLTarget, void (SKLTarget::*)(SKLTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031DE08, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, SKLTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031DE80, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, WAFTarget, void (WAFTarget::*)(WAFTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DF70, Size: 120

// Additional instantiation: CBMemberTranslator0<WAFTarget, void (WAFTarget::*)(WAFTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031E060, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, WAFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031E0D8, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, WXFTarget, void (WXFTarget::*)(WXFTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031E1C8, Size: 120

// Additional instantiation: CBMemberTranslator0<WXFTarget, void (WXFTarget::*)(WXFTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031E2B8, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, WXFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031E330, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, EYETarget, void (EYETarget::*)(EYETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C3AC, Size: 120

// Additional instantiation: CBMemberTranslator0<EYETarget, void (EYETarget::*)(EYETarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034C49C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, EYETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034C514, Size: 120

// Additional instantiation: CBMemberTranslator2<ERC *, structDrawCBparams *, EYETarget, void (EYETarget::*)(EYETarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8034C58C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, FONTarget, void (FONTarget::*)(FONTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C67C, Size: 120

// Additional instantiation: CBMemberTranslator0<FONTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034C76C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, FONTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034C7E4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, GOLTarget, void (GOLTarget::*)(GOLTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C8D4, Size: 120

// Additional instantiation: CBMemberTranslator0<GOLTarget, void (GOLTarget::*)(GOLTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034C9C4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, GOLTarget, void (GOLTarget::*)(GOLTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034CA3C, Size: 120

// Additional instantiation: CBMemberTranslator1<int, INVTarget, void (INVTarget::*)(INVTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034CBEC, Size: 120

// Additional instantiation: CBMemberTranslator0<INVTarget, void (INVTarget::*)(INVTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034CC64, Size: 120

// Additional instantiation: CBMemberTranslator1<int, UIDialog, void (UIDialog::*)(UIDialog *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034CD54, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, INVTarget, void (INVTarget::*)(INVTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034CE44, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, INVTarget, void (INVTarget::*)(INVTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034CF34, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, INTTarget, void (INTTarget::*)(INTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D064, Size: 120

// Additional instantiation: CBMemberTranslator0<INTTarget, void (INTTarget::*)(INTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034D154, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, INTTarget, void (INTTarget::*)(INTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D1CC, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, KEYTarget, void (KEYTarget::*)(KEYTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D2BC, Size: 120

// Additional instantiation: CBMemberTranslator0<KEYTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034D3AC, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, KEYTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D424, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, MSGTarget, void (MSGTarget::*)(MSGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D514, Size: 120

// Additional instantiation: CBMemberTranslator0<MSGTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034D604, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, MSGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D67C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, OPTTarget, void (OPTTarget::*)(OPTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D76C, Size: 120

// Additional instantiation: CBMemberTranslator0<OPTTarget, void (OPTTarget::*)(OPTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034D85C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, OPTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D8D4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, PDATarget, void (PDATarget::*)(PDATarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D9C4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PDATarget, void (PDATarget::*)(PDATarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034DB2C, Size: 120

// Additional instantiation: CBMemberTranslator1<int, PDATarget, void (PDATarget::*)(PDATarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034DBA4, Size: 120

// Additional instantiation: CBMemberTranslator0<PDATarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8034DC1C, Size: 144

// Additional instantiation: CBMemberTranslator2<char *, char *, PSETarget, void (PSETarget::*)(PSETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034DD24, Size: 120

// Additional instantiation: CBMemberTranslator0<PSETarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034DE14, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, PSETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034DE8C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, RELTarget, void (RELTarget::*)(RELTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034DF7C, Size: 120

// Additional instantiation: CBMemberTranslator0<RELTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E06C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, RELTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E0E4, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, RGTTarget, void (RGTTarget::*)(RGTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034E1D4, Size: 120

// Additional instantiation: CBMemberTranslator0<RGTTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E2C4, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, RGTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E33C, Size: 120

// Additional instantiation: CBMemberTranslator2<char *, char *, SKNTarget, void (SKNTarget::*)(SKNTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034E42C, Size: 120

// Additional instantiation: CBMemberTranslator0<SKNTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E51C, Size: 120

// Additional instantiation: CBMemberTranslator1<ERC *, SKNTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E594, Size: 120

// TruncateLightDirection(EVec3 &)
// Address: 0x8038B1CC, Size: 144
void TruncateLightDirection(EVec3 & p0) {
}

// CompareIntensity(void *, void *)
// Address: 0x8038B8C0, Size: 76
void CompareIntensity(void * p0, void * p1) {
}

// CalculateFacerMatrix(EVec3 &, EVec3 &, EMat4 &, bool)
// Address: 0x80398618, Size: 288
void CalculateFacerMatrix(EVec3 & p0, EVec3 & p1, EMat4 & p2, bool p3) {
}

// MergeLightWeights(int, ELightGrid::VertexData *, float, ELightGrid::LightWeight *, int &)
// Address: 0x8039CC38, Size: 364
void MergeLightWeights(int p0, ELightGrid::VertexData * p1, float p2, ELightGrid::LightWeight * p3, int & p4) {
}

// AllocOTD(void)
// Address: 0x8039E3E8, Size: 568
void AllocOTD() {
}

// FreeOTDList(EOrderTableData *&)
// Address: 0x8039E620, Size: 476
void FreeOTDList(EOrderTableData *& p0) {
}

// Outside(unsigned int, bool, short &, short &)
// Address: 0x8039E810, Size: 104
void Outside(unsigned int p0, bool p1, short & p2, short & p3) {
}

// UnregisterFloorOTDsFromList(EOrderTableData **, EInstance *)
// Address: 0x803A2340, Size: 496
void UnregisterFloorOTDsFromList(EOrderTableData ** p0, EInstance * p1) {
}

// OrderTableSortReferenceCompare(void *, void *)
// Address: 0x803A3180, Size: 88
void OrderTableSortReferenceCompare(void * p0, void * p1) {
}

// FindOTD(EOrderTableData *, EOrderTableData &)
// Address: 0x803A5710, Size: 92
void FindOTD(EOrderTableData * p0, EOrderTableData & p1) {
}

// CalcSkyLights(SkyLights &, EVec3 &, ELights &)
// Address: 0x803A6E9C, Size: 204
void CalcSkyLights(SkyLights & p0, EVec3 & p1, ELights & p2) {
}

// InterpolateToGraySky(float, LevelLightingEntry &)
// Address: 0x803A6F68, Size: 416
void InterpolateToGraySky(float p0, LevelLightingEntry & p1) {
}

// ApplyWeatherEffects(levelraininfo *, float, LevelLightingEntry &)
// Address: 0x803A7108, Size: 216
void ApplyWeatherEffects(levelraininfo * p0, float p1, LevelLightingEntry & p2) {
}

// InterpolateSkyLights(float, SkyLights &, SkyLights &, SkyLights &)
// Address: 0x803A71E0, Size: 320
void InterpolateSkyLights(float p0, SkyLights & p1, SkyLights & p2, SkyLights & p3) {
}

// InterpolateLevelLighting(LevelLighting *, float, LevelLightingEntry &)
// Address: 0x803A7320, Size: 756
void InterpolateLevelLighting(LevelLighting * p0, float p1, LevelLightingEntry & p2) {
}

// EmitterSpr3dPreProcessCB(void *)
// Address: 0x803AD64C, Size: 1272
void EmitterSpr3dPreProcessCB(void * p0) {
}

// EmitterSpr3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *)
// Address: 0x803ADB44, Size: 2096
void EmitterSpr3dSubmitCB(particle * p0, PVector4 * p1, float p2, float p3, PVector4 * p4, void * p5) {
}

// EmitterSpr3dProcessCB(void *)
// Address: 0x803AE374, Size: 164
void EmitterSpr3dProcessCB(void * p0) {
}

// EmitterSpr3dCameraXYZProcessCB(void *)
// Address: 0x803AE418, Size: 76
void EmitterSpr3dCameraXYZProcessCB(void * p0) {
}

// EmitterSpr3dCamaraXYProcessCB(void *)
// Address: 0x803AE464, Size: 116
void EmitterSpr3dCamaraXYProcessCB(void * p0) {
}

// EmitterGeomdPreProcessCB(void *)
// Address: 0x803AE73C, Size: 232
void EmitterGeomdPreProcessCB(void * p0) {
}
