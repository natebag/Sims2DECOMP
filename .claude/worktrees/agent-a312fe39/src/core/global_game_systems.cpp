// global_game_systems.cpp - Game system functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 64 functions
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

// isResInList(vector<unsigned int, allocator<unsigned int> > &, unsigned int)
// Address: 0x80034068, Size: 84
void isResInList() {
}

// collectResInfoForSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &)
// Address: 0x800340BC, Size: 708
void collectResInfoForSel() {
}

// collectResInfoForMultSel(ObjSelector *, vector<unsigned int, allocator<unsigned int> > &, vector<ObjSelector *, allocator<ObjSelector *> > *)
// Address: 0x80034380, Size: 848
void collectResInfoForMultSel() {
}

// addRefList(vector<unsigned int, allocator<unsigned int> > &, unsigned int *)
// Address: 0x80034748, Size: 164
void addRefList() {
}

// delRefList(vector<unsigned int, allocator<unsigned int> > &)
// Address: 0x800347EC, Size: 108
void delRefList() {
}

// SetupInterestFade(void)
// Address: 0x80037DC0, Size: 1964
void SetupInterestFade() {
}

// GetIndex(int, NewLevelLightingLevel *)
// Address: 0x800389BC, Size: 148
void GetIndex() {
}

// TimeIsInRange(int, int, int)
// Address: 0x80038B6C, Size: 76
void TimeIsInRange() {
}

// LightLocation(unsigned int, bool, short &, short &)
// Address: 0x80039500, Size: 104
void LightLocation() {
}

// HasWallsNotFences(TileWalls &)
// Address: 0x8003CD68, Size: 164
void HasWallsNotFences() {
}

// SplitWallBottomRight(TileWalls &, CTilePt &)
// Address: 0x8003EB54, Size: 148
void SplitWallBottomRight() {
}

// SplitWallTopLeft(TileWalls &, CTilePt &)
// Address: 0x8003EBE8, Size: 148
void SplitWallTopLeft() {
}

// SplitWallBottomLeft(TileWalls &, CTilePt &)
// Address: 0x8003EC7C, Size: 148
void SplitWallBottomLeft() {
}

// SplitWallTopRight(TileWalls &, CTilePt &)
// Address: 0x8003ED10, Size: 148
void SplitWallTopRight() {
}

// SplitWallHorizDiag(TileWalls &, CTilePt &)
// Address: 0x8003EDA4, Size: 444
void SplitWallHorizDiag() {
}

// SplitWallVertDiag(TileWalls &, CTilePt &)
// Address: 0x8003EF60, Size: 436
void SplitWallVertDiag() {
}

// WallLocation(unsigned int, bool, short &, short &)
// Address: 0x8003FB74, Size: 104
void WallLocation() {
}

// LightVertex(EVec4 &, EVec4 &, float, unsigned int *, ELights &, EMat4 *)
// Address: 0x80040C38, Size: 1208
void LightVertex() {
}

// Light(bool, float, unsigned int *, ESMSStrip *, ELights &, EMat4 *)
// Address: 0x800410F0, Size: 620
void Light() {
}

// SetAllUpOrDownForList(bool, TNodeList<ERoomWall *> &)
// Address: 0x800468C0, Size: 164
void SetAllUpOrDownForList() {
}

// RemapWallId(TileWallsSegment)
// Address: 0x800563CC, Size: 152
void RemapWallId() {
}

// RemapWallpaperId(unsigned int)
// Address: 0x80056464, Size: 164
void RemapWallpaperId() {
}

// RemapFloorId(unsigned int)
// Address: 0x80056508, Size: 164
void RemapFloorId() {
}

// RemapWallShadowId(unsigned int)
// Address: 0x800565AC, Size: 164
void RemapWallShadowId() {
}

// InitZodiac(void)
// Address: 0x8005C9A8, Size: 520
void InitZodiac() {
}

// ComputeZodiacSignAux(float *)
// Address: 0x8005CBB0, Size: 372
void ComputeZodiacSignAux() {
}

// ComputeZodiacSign(short *)
// Address: 0x8005CD24, Size: 132
void ComputeZodiacSign() {
}

// ComputeZodiacSignFromSimDesc(signed char *)
// Address: 0x8005CDA8, Size: 244
void ComputeZodiacSignFromSimDesc() {
}

// SetZodiacSign(short *, short)
// Address: 0x8005D058, Size: 260
void SetZodiacSign() {
}

// GetZodiacName(short)
// Address: 0x8005D250, Size: 192
void GetZodiacName() {
}

// GetSignFromName(unsigned wchar_t *)
// Address: 0x8005D310, Size: 120
void GetSignFromName() {
}

// GetCompatibleSigns(short)
// Address: 0x8005D388, Size: 36
void GetCompatibleSigns() {
}

// GetIncompatibleSigns(short)
// Address: 0x8005D3AC, Size: 36
void GetIncompatibleSigns() {
}

// StripFormatting(BString2 &)
// Address: 0x8005D938, Size: 124
void StripFormatting() {
}

// ColorStringForFlash(BString2 &, Interaction::tColor)
// Address: 0x8005D9B4, Size: 540
void ColorStringForFlash() {
}

// ColorIsHigherPriority(Interaction::tColor, Interaction::tColor)
// Address: 0x8005DBD0, Size: 72
void ColorIsHigherPriority() {
}

// GetObjectMenuName(cXObject *)
// Address: 0x8005E8D8, Size: 200
void GetObjectMenuName() {
}

// GetShaderForObject(cXObject *, ERShader **)
// Address: 0x8005E9A0, Size: 528
void GetShaderForObject() {
}

// OrientObjectInstance(cXObject *)
// Address: 0x8006ADAC, Size: 188
void OrientObjectInstance() {
}

// GetObjectInstance(cXObject *)
// Address: 0x8006AE68, Size: 72
void GetObjectInstance() {
}

// GetResData(cXObject *)
// Address: 0x8006AEB0, Size: 228
void GetResData() {
}

// CollectInteractionsForObject(cXObject *, InteractionList &, int, int)
// Address: 0x8006B130, Size: 68
void CollectInteractionsForObject() {
}

// GetFireCodeValue(bool)
// Address: 0x8006BF30, Size: 116
void GetFireCodeValue() {
}

// GetSimFunds(unsigned int)
// Address: 0x8006BFA4, Size: 88
void GetSimFunds() {
}

// SetSimFunds(unsigned int, int)
// Address: 0x8006BFFC, Size: 92
void SetSimFunds() {
}

// SetUIStatusTextV(char *, __va_list_tag *)
// Address: 0x8006C058, Size: 80
void SetUIStatusTextV() {
}

// SetUIStatusText(char *,...)
// Address: 0x8006C0A8, Size: 172
void SetUIStatusText() {
}

// GetUIStatusText(void)
// Address: 0x8006C154, Size: 12
void GetUIStatusText() {
}

// GuidIsOk(int)
// Address: 0x8006DAD8, Size: 360
void GuidIsOk() {
}

// DeleteSelectorOnEvict(int)
// Address: 0x8006DC40, Size: 152
void DeleteSelectorOnEvict() {
}

// AddFamilyToPool(int, int)
// Address: 0x8006DCD8, Size: 280
void AddFamilyToPool() {
}

// ConvertRoomSideToWallSide(Room::Sides)
// Address: 0x800735F4, Size: 84
void ConvertRoomSideToWallSide() {
}

// BuildVertexSpans(TNodeList<EFloorStripInfo> &, EFloorVertexSpan *)
// Address: 0x80073648, Size: 628
void BuildVertexSpans() {
}

// EvaluateFloorLights(ELightGrid &, int, EVec3 &, EVec3 &)
// Address: 0x800741D8, Size: 384
void EvaluateFloorLights() {
}

// EvaluateFloorColors(EShader *, EVec3 &, EVec3 &, EVec3 &, EVec3 &)
// Address: 0x80074358, Size: 172
void EvaluateFloorColors() {
}

// EvaluateLightAtVertices(int, ELightGrid &, ELightGrid::LightData *, EFloorVertexSpan *, int, EVec3 *)
// Address: 0x80074404, Size: 676
void EvaluateLightAtVertices() {
}

// FloorRoom(unsigned int, bool, short &, short &)
// Address: 0x80076148, Size: 104
void FloorRoom() {
}

// SolveQuadratic(float, float, float, float *)
// Address: 0x80079D28, Size: 228
void SolveQuadratic() {
}

// GetCircleCircleIX(EVec2 &, float, EVec2 &, EVec2 &, float, EVec2 &, Intersection &)
// Address: 0x80079E0C, Size: 656
void GetCircleCircleIX() {
}

// GetCircleSegmentIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
// Address: 0x8007A09C, Size: 856
void GetCircleSegmentIX() {
}

// GetCircleSegmentClosedIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &, bool)
// Address: 0x8007A434, Size: 376
void GetCircleSegmentClosedIX() {
}

// GetCircleRectangleIX(EVec2 &, float, EVec2 &, EVec2 &, EVec2 &, Intersection &)
// Address: 0x8007A5AC, Size: 1196
void GetCircleRectangleIX() {
}

// get_ingredient_type_array(FoodResult *, short *)
// Address: 0x8007C45C, Size: 124
void get_ingredient_type_array() {
}

// make_ingredient_type_array(short, short, short, short, short *)
// Address: 0x8007C4D8, Size: 172
void make_ingredient_type_array() {
}
