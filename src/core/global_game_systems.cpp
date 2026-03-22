// global_game_systems.cpp - Game system functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 67 functions
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

// isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int)
// Address: 0x80034068, Size: 84
void isResInList(vector<unsigned int, allocator<unsigned int> > & p0, unsigned int p1) {
}

// collectResInfoForSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &)
// Address: 0x800340BC, Size: 708
void collectResInfoForSel(ObjSelector * p0, vector<unsigned int, allocator<unsigned int> > & p1) {
}

// collectResInfoForMultSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &, vector<ObjSelector *, allocator<ObjSelector *> > *)
// Address: 0x80034380, Size: 848
void collectResInfoForMultSel(ObjSelector * p0, vector<unsigned int, allocator<unsigned int> > & p1, vector<ObjSelector *, allocator<ObjSelector *> > * p2) {
}

// addRefList(vector<unsigned int, allocator<unsigned int> > &, unsigned int *)
// Address: 0x80034748, Size: 164
void addRefList(vector<unsigned int, allocator<unsigned int> > & p0, unsigned int * p1) {
}

// delRefList(vector<unsigned int, allocator<unsigned int> > &)
// Address: 0x800347EC, Size: 108
void delRefList(vector<unsigned int, allocator<unsigned int> > & p0) {
}

// unsigned int * __unguarded_partition<unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036AA0, Size: 160
unsigned int * __unguarded_partition<unsigned int *, unsigned int, bool(* p0) {
    return 0;
}

// Additional instantiation: void __introsort_loop<unsigned int *, unsigned int, int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, unsigned int *, int, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036B40, Size: 340

// Additional instantiation: void __unguarded_linear_insert<unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036C94, Size: 108

// Additional instantiation: void __unguarded_insertion_sort_aux<unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036DAC, Size: 84

// SetupInterestFade(void)
// Address: 0x80037DC0, Size: 1964
void SetupInterestFade() {
}

// GetIndex(int, NewLevelLightingLevel *)
// Address: 0x800389BC, Size: 148
void GetIndex(int p0, NewLevelLightingLevel * p1) {
}

// TimeIsInRange(int, int, int)
// Address: 0x80038B6C, Size: 76
void TimeIsInRange(int p0, int p1, int p2) {
}

// LightLocation(unsigned int, bool, short &, short &)
// Address: 0x80039500, Size: 104
void LightLocation(unsigned int p0, bool p1, short & p2, short & p3) {
}

// HasWallsNotFences(TileWalls &)
// Address: 0x8003CD68, Size: 164
void HasWallsNotFences(TileWalls & p0) {
}

// SplitWallBottomRight(TileWalls &, CTilePt &)
// Address: 0x8003EB54, Size: 148
void SplitWallBottomRight(TileWalls & p0, CTilePt & p1) {
}

// SplitWallTopLeft(TileWalls &, CTilePt &)
// Address: 0x8003EBE8, Size: 148
void SplitWallTopLeft(TileWalls & p0, CTilePt & p1) {
}

// SplitWallBottomLeft(TileWalls &, CTilePt &)
// Address: 0x8003EC7C, Size: 148
void SplitWallBottomLeft(TileWalls & p0, CTilePt & p1) {
}

// SplitWallTopRight(TileWalls &, CTilePt &)
// Address: 0x8003ED10, Size: 148
void SplitWallTopRight(TileWalls & p0, CTilePt & p1) {
}

// SplitWallHorizDiag(TileWalls &, CTilePt &)
// Address: 0x8003EDA4, Size: 444
void SplitWallHorizDiag(TileWalls & p0, CTilePt & p1) {
}

// SplitWallVertDiag(TileWalls &, CTilePt &)
// Address: 0x8003EF60, Size: 436
void SplitWallVertDiag(TileWalls & p0, CTilePt & p1) {
}

// WallLocation(unsigned int, bool, short &, short &)
// Address: 0x8003FB74, Size: 104
void WallLocation(unsigned int p0, bool p1, short & p2, short & p3) {
}

// LightVertex(EVec4 &, EVec4 &, float, unsigned int *, ELights &, EMat4 *)
// Address: 0x80040C38, Size: 1208
void LightVertex(EVec4 & p0, EVec4 & p1, float p2, unsigned int * p3, ELights & p4, EMat4 * p5) {
}

// Light(bool, float, unsigned int *, ESMSStrip *, ELights &, EMat4 *)
// Address: 0x800410F0, Size: 620
void Light(bool p0, float p1, unsigned int * p2, ESMSStrip * p3, ELights & p4, EMat4 * p5) {
}

// SetAllUpOrDownForList(bool, TNodeList<ERoomWall *> &)
// Address: 0x800468C0, Size: 164
void SetAllUpOrDownForList(bool p0, TNodeList<ERoomWall *> & p1) {
}

// RemapWallId(TileWallsSegment)
// Address: 0x800563CC, Size: 152
void RemapWallId(TileWallsSegment p0) {
}

// RemapWallpaperId(unsigned int)
// Address: 0x80056464, Size: 164
void RemapWallpaperId(unsigned int p0) {
}

// RemapFloorId(unsigned int)
// Address: 0x80056508, Size: 164
void RemapFloorId(unsigned int p0) {
}

// RemapWallShadowId(unsigned int)
// Address: 0x800565AC, Size: 164
void RemapWallShadowId(unsigned int p0) {
}

// InitZodiac(void)
// Address: 0x8005C9A8, Size: 520
void InitZodiac() {
}

// ComputeZodiacSignAux(float *)
// Address: 0x8005CBB0, Size: 372
void ComputeZodiacSignAux(float * p0) {
}

// ComputeZodiacSign(short *)
// Address: 0x8005CD24, Size: 132
void ComputeZodiacSign(short * p0) {
}

// ComputeZodiacSignFromSimDesc(signed char *)
// Address: 0x8005CDA8, Size: 244
void ComputeZodiacSignFromSimDesc(signed char * p0) {
}

// SetZodiacSign(short *, short)
// Address: 0x8005D058, Size: 260
void SetZodiacSign(short * p0, short p1) {
}

// GetZodiacName(short)
// Address: 0x8005D250, Size: 192
void GetZodiacName(short p0) {
}

// GetSignFromName(unsigned wchar_t *)
// Address: 0x8005D310, Size: 120
void GetSignFromName(unsigned wchar_t * p0) {
}

// GetCompatibleSigns(short)
// Address: 0x8005D388, Size: 36
void GetCompatibleSigns(short p0) {
}

// GetIncompatibleSigns(short)
// Address: 0x8005D3AC, Size: 36
void GetIncompatibleSigns(short p0) {
}

// StripFormatting(BString2 &)
// Address: 0x8005D938, Size: 124
void StripFormatting(BString2 & p0) {
}

// ColorStringForFlash(BString2 &, Interaction::tColor)
// Address: 0x8005D9B4, Size: 540
void ColorStringForFlash(BString2 & p0, Interaction::tColor p1) {
}

// ColorIsHigherPriority(Interaction::tColor, Interaction::tColor)
// Address: 0x8005DBD0, Size: 72
void ColorIsHigherPriority(Interaction::tColor p0, Interaction::tColor p1) {
}

// GetObjectMenuName(cXObject *)
// Address: 0x8005E8D8, Size: 200
void GetObjectMenuName(cXObject * p0) {
}

// GetShaderForObject(cXObject *, ERShader **)
// Address: 0x8005E9A0, Size: 528
void GetShaderForObject(cXObject * p0, ERShader ** p1) {
}

// OrientObjectInstance(cXObject *)
// Address: 0x8006ADAC, Size: 188
void OrientObjectInstance(cXObject * p0) {
}

// GetResData(cXObject *)
// Address: 0x8006AEB0, Size: 228
void GetResData(cXObject * p0) {
}

// CollectInteractionsForObject(cXObject *, InteractionList &, cXPerson *, int)
// Address: 0x8006B174, Size: 920
void CollectInteractionsForObject(cXObject * p0, InteractionList & p1, cXPerson * p2, int p3) {
}

// GetFireCodeValue(bool)
// Address: 0x8006BF30, Size: 116
void GetFireCodeValue(bool p0) {
}

// GetSimFunds(unsigned int)
// Address: 0x8006BFA4, Size: 88
void GetSimFunds(unsigned int p0) {
}

// SetSimFunds(unsigned int, int)
// Address: 0x8006BFFC, Size: 92
void SetSimFunds(unsigned int p0, int p1) {
}

// SetUIStatusTextV(char *, __va_list_tag *)
// Address: 0x8006C058, Size: 80
void SetUIStatusTextV(char * p0, __va_list_tag * p1) {
}

// SetUIStatusText(char *,...)
// Address: 0x8006C0A8, Size: 172
void SetUIStatusText(char * p0, ... p1) {
}

// GetUIStatusText(void)
// Address: 0x8006C154, Size: 12
void GetUIStatusText() {
}

// GuidIsOk(int)
// Address: 0x8006DAD8, Size: 360
void GuidIsOk(int p0) {
}

// DeleteSelectorOnEvict(int)
// Address: 0x8006DC40, Size: 152
void DeleteSelectorOnEvict(int p0) {
}

// AddFamilyToPool(int, int)
// Address: 0x8006DCD8, Size: 280
void AddFamilyToPool(int p0, int p1) {
}

// ConvertRoomSideToWallSide(Room::Sides)
// Address: 0x800735F4, Size: 84
void ConvertRoomSideToWallSide(Room::Sides p0) {
}

// BuildVertexSpans(TNodeList<EFloorStripInfo> &, EFloorVertexSpan *)
// Address: 0x80073648, Size: 628
void BuildVertexSpans(TNodeList<EFloorStripInfo> & p0, EFloorVertexSpan * p1) {
}

// EvaluateFloorLights(ELightGrid &, int, EVec3 &, EVec3 &)
// Address: 0x800741D8, Size: 384
void EvaluateFloorLights(ELightGrid & p0, int p1, EVec3 & p2, EVec3 & p3) {
}

// EvaluateFloorColors(EShader *, EVec3 &, EVec3 &, EVec3 &, EVec3 &)
// Address: 0x80074358, Size: 172
void EvaluateFloorColors(EShader * p0, EVec3 & p1, EVec3 & p2, EVec3 & p3, EVec3 & p4) {
}

// EvaluateLightAtVertices(int, ELightGrid &, ELightGrid::LightData *, EFloorVertexSpan *, int, EVec3 *)
// Address: 0x80074404, Size: 676
void EvaluateLightAtVertices(int p0, ELightGrid & p1, ELightGrid::LightData * p2, EFloorVertexSpan * p3, int p4, EVec3 * p5) {
}

// FloorRoom(unsigned int, bool, short &, short &)
// Address: 0x80076148, Size: 104
void FloorRoom(unsigned int p0, bool p1, short & p2, short & p3) {
}

// SolveQuadratic(float, float, float, float *)
// Address: 0x80079D28, Size: 228
void SolveQuadratic(float p0, float p1, float p2, float * p3) {
}

// GetCircleCircleIX(EVec2 &, float, EVec2 &, EVec2 &, float, EVec2 &, Intersection &)
// Address: 0x80079E0C, Size: 656
void GetCircleCircleIX(EVec2 & p0, float p1, EVec2 & p2, EVec2 & p3, float p4, EVec2 & p5, Intersection & p6) {
}

// GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
// Address: 0x8007A09C, Size: 856
void GetCircleSegmentIX(EVec2 & p0, float p1, EVec2 & p2, EVec2 & p3, EVec2 & p4, Intersection & p5, bool p6) {
}

// GetCircleSegmentClosedIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
// Address: 0x8007A434, Size: 376
void GetCircleSegmentClosedIX(EVec2 & p0, float p1, EVec2 & p2, EVec2 & p3, EVec2 & p4, Intersection & p5, bool p6) {
}

// GetCircleRectangleIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &)
// Address: 0x8007A5AC, Size: 1196
void GetCircleRectangleIX(EVec2 & p0, float p1, EVec2 & p2, EVec2 & p3, EVec2 & p4, Intersection & p5) {
}

// get_ingredient_type_array(FoodResult *, short *)
// Address: 0x8007C45C, Size: 124
void get_ingredient_type_array(FoodResult * p0, short * p1) {
}

// make_ingredient_type_array(short, short, short, short, short *)
// Address: 0x8007C4D8, Size: 172
void make_ingredient_type_array(short p0, short p1, short p2, short p3, short * p4) {
}
