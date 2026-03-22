// global_game_data.cpp - Game data functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 34 functions
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

// GetMotiveConstantsClient(void)
// Address: 0x80153DA0, Size: 8
void GetMotiveConstantsClient() {
}

// ObjectsAtTile(FTilePt &, int)
// Address: 0x80159098, Size: 112
void ObjectsAtTile(FTilePt & p0, int p1) {
}

// GetNeighborhoodConstantsClient(void)
// Address: 0x80161C10, Size: 8
void GetNeighborhoodConstantsClient() {
}

// FamilyImpl ** __unguarded_partition<FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&))
// Address: 0x8016940C, Size: 164
FamilyImpl ** __unguarded_partition<FamilyImpl **, FamilyImpl *, bool(* p0) {
    return 0;
}

// Additional instantiation: void __introsort_loop<FamilyImpl **, FamilyImpl *, int, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, FamilyImpl * *, int, bool (*)(Family *&, Family *&))
// Address: 0x801694B0, Size: 340

// Additional instantiation: void __unguarded_linear_insert<FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&))
// Address: 0x80169604, Size: 100

// Additional instantiation: void __unguarded_insertion_sort_aux<FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, FamilyImpl * *, bool (*)(Family *&, Family *&))
// Address: 0x80169710, Size: 84

// Additional instantiation: int * __unguarded_partition<int *, int, bool (*)(int &, int &)>(int *, int *, int, bool (*)(int &, int &))
// Address: 0x80169C94, Size: 160

// Additional instantiation: void __introsort_loop<int *, int, int, bool (*)(int &, int &)>(int *, int *, int *, int, bool (*)(int &, int &))
// Address: 0x80169D34, Size: 340

// Additional instantiation: void __unguarded_linear_insert<int *, int, bool (*)(int &, int &)>(int *, int, bool (*)(int &, int &))
// Address: 0x80169E88, Size: 108

// Additional instantiation: void __unguarded_insertion_sort_aux<int *, int, bool (*)(int &, int &)>(int *, int *, int *, bool (*)(int &, int &))
// Address: 0x80169FA0, Size: 84

// SetSupportFlag(int, int, int, bool)
// Address: 0x8017AF3C, Size: 196
void SetSupportFlag(int p0, int p1, int p2, bool p3) {
}

// ApproxSqrt(float)
// Address: 0x8017CFF0, Size: 80
void ApproxSqrt(float p0) {
}

// StringToHash(char *)
// Address: 0x8018C410, Size: 312
void StringToHash(char * p0) {
}

// ConvertToBackslash(StringBuffer &)
// Address: 0x8018C5B0, Size: 108
void ConvertToBackslash(StringBuffer & p0) {
}

// IsPlayableCharacter(int, int &)
// Address: 0x8019031C, Size: 404
void IsPlayableCharacter(int p0, int & p1) {
}

// Additional instantiation: ObjSelector ** __unguarded_partition<ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x8019480C, Size: 156

// Additional instantiation: void __introsort_loop<ObjSelector **, ObjSelector *, int, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, ObjSelector * *, int, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x801948A8, Size: 344

// Additional instantiation: void __unguarded_linear_insert<ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194A00, Size: 96

// Additional instantiation: void __unguarded_insertion_sort_aux<ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, ObjSelector * *, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194B04, Size: 84

// TryFindSafeLocForSim(cXObject *, FTilePt &, int, cXObject *, int)
// Address: 0x801A440C, Size: 1108
void TryFindSafeLocForSim(cXObject * p0, FTilePt & p1, int p2, cXObject * p3, int p4) {
}

// MakeMoneyString(StringBuffer2 &, int)
// Address: 0x801A7070, Size: 100
void MakeMoneyString(StringBuffer2 & p0, int p1) {
}

// ParseOneString(BString2 &, BString2 &, int, int *, int *, int *)
// Address: 0x801A70D4, Size: 472
void ParseOneString(BString2 & p0, BString2 & p1, int p2, int * p3, int * p4, int * p5) {
}

// StartFireAtObjectLoc(cXObject *, ObjSelector *)
// Address: 0x801AA29C, Size: 620
void StartFireAtObjectLoc(cXObject * p0, ObjSelector * p1) {
}

// PresetHouseGameStatus(void)
// Address: 0x801B0750, Size: 104
void PresetHouseGameStatus() {
}

// fround(float)
// Address: 0x801B6F4C, Size: 76
void fround(float p0) {
}

// GetJobHUDControlName(short)
// Address: 0x801BB750, Size: 3136
void GetJobHUDControlName(short p0) {
}

// GetNpcShaderId(int, bool)
// Address: 0x801BF330, Size: 96
void GetNpcShaderId(int p0, bool p1) {
}

// SetReconDumpFile(char *)
// Address: 0x801F0534, Size: 96
void SetReconDumpFile(char * p0) {
}

// IsScoredStyle(WallStyle)
// Address: 0x801F6D9C, Size: 136
void IsScoredStyle(WallStyle p0) {
}

// GetLightRoomID(unsigned short)
// Address: 0x801F7BF4, Size: 96
void GetLightRoomID(unsigned short p0) {
}

// FindIntersectingRect(IRect *, vector<PenaltyRect, allocator<PenaltyRect> > *)
// Address: 0x801F8E18, Size: 136
void FindIntersectingRect(IRect * p0, vector<PenaltyRect, allocator<PenaltyRect> > * p1) {
}

// IsRectInside(IRect *, IRect *)
// Address: 0x801FA548, Size: 92
void IsRectInside(IRect * p0, IRect * p1) {
}

// TryCatExtension(StackString<260> &, SeqResFile::OpenSpec *)
// Address: 0x801FECEC, Size: 312
void TryCatExtension(StackString<260> & p0, SeqResFile::OpenSpec * p1) {
}
