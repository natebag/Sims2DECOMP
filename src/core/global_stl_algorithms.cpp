// global_stl_algorithms.cpp - STL algorithm template instantiations
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 49 functions
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

// void __adjust_heap<unsigned int *, int, unsigned int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, int, int, unsigned int, bool (*)(unsigned int &, unsigned int &))
// Address: 0x800367D0, Size: 284
void __adjust_heap<unsigned int *, int, unsigned int, bool(* p0) {
    return 0;
}

// Additional instantiation: void make_heap<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x800368EC, Size: 128

// Additional instantiation: void pop_heap<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x8003696C, Size: 64

// Additional instantiation: void __partial_sort<unsigned int *, unsigned int, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x800369AC, Size: 204

// Additional instantiation: void partial_sort<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036A78, Size: 40

// Additional instantiation: void __insertion_sort<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036D00, Size: 172

// Additional instantiation: void __final_insertion_sort<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036E00, Size: 108

// Additional instantiation: void sort<unsigned int *, bool (*)(unsigned int &, unsigned int &)>(unsigned int *, unsigned int *, bool (*)(unsigned int &, unsigned int &))
// Address: 0x80036E6C, Size: 132

// void __adjust_heap<Neighbor **, int, Neighbor *, RelationsCmp>(Neighbor **, int, int, Neighbor *, RelationsCmp)
// Address: 0x800719C4, Size: 280
// Template: __adjust_heap<Neighbor **, int, Neighbor *, RelationsCmp>
void __adjust_heap(Neighbor ** p0, int p1, int p2, Neighbor * p3, RelationsCmp p4) {
}

// void make_heap<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x80071ADC, Size: 140
// Template: make_heap<Neighbor **, RelationsCmp>
void make_heap(Neighbor ** p0, Neighbor ** p1, RelationsCmp p2) {
}

// void pop_heap<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x80071B68, Size: 80
// Template: pop_heap<Neighbor **, RelationsCmp>
void pop_heap(Neighbor ** p0, Neighbor ** p1, RelationsCmp p2) {
}

// void __partial_sort<Neighbor **, Neighbor *, RelationsCmp>(Neighbor **, Neighbor **, Neighbor **, Neighbor * *, RelationsCmp)
// Address: 0x80071BB8, Size: 240
// Template: __partial_sort<Neighbor **, Neighbor *, RelationsCmp>
void __partial_sort(Neighbor ** p0, Neighbor ** p1, Neighbor ** p2, Neighbor * * p3, RelationsCmp p4) {
}

// void partial_sort<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x80071CA8, Size: 48
// Template: partial_sort<Neighbor **, RelationsCmp>
void partial_sort(Neighbor ** p0, Neighbor ** p1, Neighbor ** p2, RelationsCmp p3) {
}

// void __insertion_sort<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x80071F44, Size: 180
// Template: __insertion_sort<Neighbor **, RelationsCmp>
void __insertion_sort(Neighbor ** p0, Neighbor ** p1, RelationsCmp p2) {
}

// void __final_insertion_sort<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x80072054, Size: 140
// Template: __final_insertion_sort<Neighbor **, RelationsCmp>
void __final_insertion_sort(Neighbor ** p0, Neighbor ** p1, RelationsCmp p2) {
}

// void sort<Neighbor **, RelationsCmp>(Neighbor **, Neighbor **, RelationsCmp)
// Address: 0x800720E0, Size: 148
// Template: sort<Neighbor **, RelationsCmp>
void sort(Neighbor ** p0, Neighbor ** p1, RelationsCmp p2) {
}

// Additional instantiation: void __adjust_heap<FamilyImpl **, int, FamilyImpl *, bool (*)(Family *&, Family *&)>(FamilyImpl **, int, int, FamilyImpl *, bool (*)(Family *&, Family *&))
// Address: 0x80169140, Size: 280

// Additional instantiation: void make_heap<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x80169258, Size: 128

// Additional instantiation: void pop_heap<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x801692D8, Size: 64

// Additional instantiation: void __partial_sort<FamilyImpl **, FamilyImpl *, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, FamilyImpl **, FamilyImpl * *, bool (*)(Family *&, Family *&))
// Address: 0x80169318, Size: 204

// Additional instantiation: void partial_sort<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x801693E4, Size: 40

// Additional instantiation: void __insertion_sort<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x80169668, Size: 168

// Additional instantiation: void __final_insertion_sort<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x80169764, Size: 108

// Additional instantiation: void sort<FamilyImpl **, bool (*)(Family *&, Family *&)>(FamilyImpl **, FamilyImpl **, bool (*)(Family *&, Family *&))
// Address: 0x801697D0, Size: 132

// Additional instantiation: void __adjust_heap<int *, int, int, bool (*)(int &, int &)>(int *, int, int, int, bool (*)(int &, int &))
// Address: 0x801699C4, Size: 284

// Additional instantiation: void make_heap<int *, bool (*)(int &, int &)>(int *, int *, bool (*)(int &, int &))
// Address: 0x80169AE0, Size: 128

// Additional instantiation: void pop_heap<int *, bool (*)(int &, int &)>(int *, int *, bool (*)(int &, int &))
// Address: 0x80169B60, Size: 64

// Additional instantiation: void __partial_sort<int *, int, bool (*)(int &, int &)>(int *, int *, int *, int *, bool (*)(int &, int &))
// Address: 0x80169BA0, Size: 204

// Additional instantiation: void partial_sort<int *, bool (*)(int &, int &)>(int *, int *, int *, bool (*)(int &, int &))
// Address: 0x80169C6C, Size: 40

// Additional instantiation: void __insertion_sort<int *, bool (*)(int &, int &)>(int *, int *, bool (*)(int &, int &))
// Address: 0x80169EF4, Size: 172

// Additional instantiation: void __final_insertion_sort<int *, bool (*)(int &, int &)>(int *, int *, bool (*)(int &, int &))
// Address: 0x80169FF4, Size: 108

// Additional instantiation: void sort<int *, bool (*)(int &, int &)>(int *, int *, bool (*)(int &, int &))
// Address: 0x8016A060, Size: 132

// Additional instantiation: void __adjust_heap<ObjSelector **, int, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, int, int, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194540, Size: 280

// Additional instantiation: void make_heap<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194658, Size: 128

// Additional instantiation: void pop_heap<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x801946D8, Size: 64

// Additional instantiation: void __partial_sort<ObjSelector **, ObjSelector *, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, ObjSelector **, ObjSelector * *, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194718, Size: 204

// Additional instantiation: void partial_sort<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x801947E4, Size: 40

// Additional instantiation: void __insertion_sort<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194A60, Size: 164

// Additional instantiation: void __final_insertion_sort<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194B58, Size: 108

// Additional instantiation: void sort<ObjSelector **, bool (*)(ObjSelector *, ObjSelector *)>(ObjSelector **, ObjSelector **, bool (*)(ObjSelector *, ObjSelector *))
// Address: 0x80194BC4, Size: 132

// void _S_sort<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >(list<ScoredInteraction, allocator<ScoredInteraction> > &, less<ScoredInteraction>)
// Address: 0x801E6234, Size: 664
// Template: _S_sort<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >
void _S_sort(list<ScoredInteraction, allocator<ScoredInteraction> > & p0, less<ScoredInteraction> p1) {
}

// Additional instantiation: void __adjust_heap<CasSimDescriptionS2C **, int, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, int, int, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8023FD50, Size: 280

// Additional instantiation: void make_heap<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8023FE68, Size: 128

// Additional instantiation: void pop_heap<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8023FEE8, Size: 64

// Additional instantiation: void __partial_sort<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8023FF28, Size: 204

// Additional instantiation: void partial_sort<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x8023FFF4, Size: 40

// Additional instantiation: void __insertion_sort<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x80240270, Size: 164

// Additional instantiation: void __final_insertion_sort<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x80240368, Size: 108

// Additional instantiation: void sort<CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *)>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *))
// Address: 0x802403D4, Size: 132
