// global_game_late.cpp - Late-linked game functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 60 functions
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

// GetIndividualMemory(int, int)
// Address: 0x80201E08, Size: 124
void GetIndividualMemory() {
}

// SetIndividualMemory(int &, int, int)
// Address: 0x80201E84, Size: 212
void SetIndividualMemory() {
}

// SetupMatrixAndKey(int, int, RelMatrix *&, int &)
// Address: 0x80201F58, Size: 468
void SetupMatrixAndKey() {
}

// ReconExpReport(ExpenseReport *, ReconBuffer *)
// Address: 0x80202898, Size: 148
void ReconExpReport() {
}

// ReportMissingAnimation(cXPerson *, char *, int)
// Address: 0x8020491C, Size: 108
void ReportMissingAnimation() {
}

// InitSkillLookup(void)
// Address: 0x80204A5C, Size: 1188
void InitSkillLookup() {
}

// resolveSkillForPassiveInfluence(cXObject *, StackElem *, AnimateNewParam *, AnimRef *&)
// Address: 0x80204F38, Size: 348
void resolveSkillForPassiveInfluence() {
}

// GetStdAnimRef(cXPerson *, StdAnimIdx, AnimRef *&)
// Address: 0x80205094, Size: 536
void GetStdAnimRef() {
}

// GetReachAnimRef(cXPerson *, ReachAnimIdx, AnimRef *&)
// Address: 0x802052AC, Size: 124
void GetReachAnimRef() {
}

// GetMiscAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x80205328, Size: 140
void GetMiscAnimRef() {
}

// GetObjectAnimRef(cXObject *, cXPerson *, int, bool, AnimRef *&)
// Address: 0x802053B4, Size: 524
void GetObjectAnimRef() {
}

// GetObjectAnimRefPassiveInfluence(cXObject *, int, AnimRef *&)
// Address: 0x802055C0, Size: 148
void GetObjectAnimRefPassiveInfluence() {
}

// GetPersonStockAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x80205654, Size: 140
void GetPersonStockAnimRef() {
}

// GetGlobalAnimRef(cXPerson *, int, AnimRef *&)
// Address: 0x802056E0, Size: 140
void GetGlobalAnimRef() {
}

// SectWall(FTileRect *, int)
// Address: 0x8020FE6C, Size: 588
void SectWall() {
}

// ValidDoorLocation(int, int, int, int, int)
// Address: 0x802100B8, Size: 860
void ValidDoorLocation() {
}

// CheckWallFlags(FTilePt, int, int, int)
// Address: 0x802104B4, Size: 1004
void CheckWallFlags() {
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
void TransformToWorldCoords() {
}

// BuildRoomPartition(unsigned short, vector<PenaltyRect, allocator<PenaltyRect> > *, bool)
// Address: 0x8021DCFC, Size: 10048
void BuildRoomPartition() {
}

// Stuck(vector<PenaltyRect, allocator<PenaltyRect> > *, IPoint *)
// Address: 0x80220460, Size: 136
void Stuck() {
}

// SetDirectionForGoalSearch(cXObject *, short, short, RoutingSlot *)
// Address: 0x80222CD8, Size: 256
void SetDirectionForGoalSearch() {
}

// CollapsePenaltyRects(vector<PenaltyRect, allocator<PenaltyRect> > &)
// Address: 0x80224800, Size: 756
void CollapsePenaltyRects() {
}

// GetSmartDataFactory(void)
// Address: 0x80229394, Size: 132
void GetSmartDataFactory() {
}

// CasEventDummyPrintf(char *,...)
// Address: 0x8022F8E4, Size: 76
void CasEventDummyPrintf() {
}

// emptyTrace(char *,...)
// Address: 0x802357F8, Size: 76
void emptyTrace() {
}

// AutoTestingInitialize(char *)
// Address: 0x8023C3F8, Size: 68
void AutoTestingInitialize() {
}

// AutoTestingUpdate(bool)
// Address: 0x8023C43C, Size: 504
void AutoTestingUpdate() {
}

// AutoTestingExit(void)
// Address: 0x8023C634, Size: 48
void AutoTestingExit() {
}

// GetActionMenu(unsigned int)
// Address: 0x8028102C, Size: 224
void GetActionMenu() {
}

// GetSelectedActionMenuItem(unsigned int)
// Address: 0x8028110C, Size: 32
void GetSelectedActionMenuItem() {
}

// CUCS2ToUTF8(unsigned wchar_t *, int, char *)
// Address: 0x8028540C, Size: 32
void CUCS2ToUTF8() {
}

// GetTutorialLocks(int)
// Address: 0x8028542C, Size: 32
void GetTutorialLocks() {
}

// SaveGame(bool, bool)
// Address: 0x80297694, Size: 1304
void SaveGame() {
}

// RefreshStats(void)
// Address: 0x80298694, Size: 4
void RefreshStats() {
}

// get_cooking_steps_csv(int, char *)
// Address: 0x8030552C, Size: 392
void get_cooking_steps_csv() {
}

// DEBUG_DUMP_RECIPE(unsigned int, RCPTarget::Recipe &)
// Address: 0x803056B4, Size: 484
void DEBUG_DUMP_RECIPE() {
}

// G2DDummyPrintf(char *,...)
// Address: 0x8031AC38, Size: 76
void G2DDummyPrintf() {
}

// TruncateLightDirection(EVec3 &)
// Address: 0x8038B1CC, Size: 144
void TruncateLightDirection() {
}

// CompareIntensity(void *, void *)
// Address: 0x8038B8C0, Size: 76
void CompareIntensity() {
}

// CalculateFacerMatrix(EVec3 &, EVec3 &, EMat4 &, bool)
// Address: 0x80398618, Size: 288
void CalculateFacerMatrix() {
}

// MergeLightWeights(int, ELightGrid::VertexData *, float, ELightGrid::LightWeight *, int &)
// Address: 0x8039CC38, Size: 364
void MergeLightWeights() {
}

// AllocOTD(void)
// Address: 0x8039E3E8, Size: 568
void AllocOTD() {
}

// FreeOTDList(EOrderTableData *&)
// Address: 0x8039E620, Size: 476
void FreeOTDList() {
}

// Outside(unsigned int, bool, short &, short &)
// Address: 0x8039E810, Size: 104
void Outside() {
}

// UnregisterFloorOTDsFromList(EOrderTableData **, EInstance *)
// Address: 0x803A2340, Size: 496
void UnregisterFloorOTDsFromList() {
}

// OrderTableSortReferenceCompare(void *, void *)
// Address: 0x803A3180, Size: 88
void OrderTableSortReferenceCompare() {
}

// FindOTD(EOrderTableData *, EOrderTableData &)
// Address: 0x803A5710, Size: 92
void FindOTD() {
}

// CalcSkyLights(SkyLights &, EVec3 &, ELights &)
// Address: 0x803A6E9C, Size: 204
void CalcSkyLights() {
}

// InterpolateToGraySky(float, LevelLightingEntry &)
// Address: 0x803A6F68, Size: 416
void InterpolateToGraySky() {
}

// ApplyWeatherEffects(levelraininfo *, float, LevelLightingEntry &)
// Address: 0x803A7108, Size: 216
void ApplyWeatherEffects() {
}

// InterpolateSkyLights(float, SkyLights &, SkyLights &, SkyLights &)
// Address: 0x803A71E0, Size: 320
void InterpolateSkyLights() {
}

// InterpolateLevelLighting(LevelLighting *, float, LevelLightingEntry &)
// Address: 0x803A7320, Size: 756
void InterpolateLevelLighting() {
}

// EmitterSpr3dPreProcessCB(void *)
// Address: 0x803AD64C, Size: 1272
void EmitterSpr3dPreProcessCB() {
}

// EmitterSpr3dSubmitCB(particle *, PVector4 *, float, float, PVector4 *, void *)
// Address: 0x803ADB44, Size: 2096
void EmitterSpr3dSubmitCB() {
}

// EmitterSpr3dProcessCB(void *)
// Address: 0x803AE374, Size: 164
void EmitterSpr3dProcessCB() {
}

// EmitterSpr3dCameraXYZProcessCB(void *)
// Address: 0x803AE418, Size: 76
void EmitterSpr3dCameraXYZProcessCB() {
}

// EmitterSpr3dCamaraXYProcessCB(void *)
// Address: 0x803AE464, Size: 116
void EmitterSpr3dCamaraXYProcessCB() {
}

// EmitterGeomdPreProcessCB(void *)
// Address: 0x803AE73C, Size: 232
void EmitterGeomdPreProcessCB() {
}
