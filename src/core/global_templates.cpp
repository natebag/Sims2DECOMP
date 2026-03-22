// global_templates.cpp - Template function instantiations
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 77 functions
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

// void {anonymous} InterpolateSmooth<EVec3>(EVec3 *, EVec3 &, float, float)
// Address: 0x8002DA9C, Size: 300
// Template: InterpolateSmooth<EVec3>
void InterpolateSmooth(EVec3 * p0, EVec3 & p1, float p2, float p3) {
}

// int ReconLoadObject<ObjectSaveTypeTable2>(ObjectSaveTypeTable2 *, iResFile *, int, short, int *)
// Address: 0x80036EF0, Size: 100
// Template: ReconLoadObject<ObjectSaveTypeTable2>
int ReconLoadObject(ObjectSaveTypeTable2 * p0, iResFile * p1, int p2, short p3, int * p4) {
    return 0;
}

// SpriteIdToResIdNode * FindRes<SpriteIdToResIdNode>(SpriteIdToResIdNode *, SpriteIdToResIdNode *, int)
// Address: 0x8006D74C, Size: 112
// Template: FindRes<SpriteIdToResIdNode>
SpriteIdToResIdNode * FindRes(SpriteIdToResIdNode * p0, SpriteIdToResIdNode * p1, int p2) {
    return 0;
}

// Additional instantiation: int ReconLoadObject<cSimulator>(cSimulator *, iResFile *, int, short, int *)
// Address: 0x80071764, Size: 100

// int ReconSaveObject<cSimulator>(cSimulator *, iResFile *, int, short, int)
// Address: 0x800717C8, Size: 108
// Template: ReconSaveObject<cSimulator>
int ReconSaveObject(cSimulator * p0, iResFile * p1, int p2, short p3, int p4) {
    return 0;
}

// Additional instantiation: void ReconLoadObject<UserDataSaveLoad>(UserDataSaveLoad *, Memory::HandleNode *, int, int *)
// Address: 0x80071834, Size: 88

// Additional instantiation: int ReconLoadObject<ReconStreamPtrVector<Neighbor> >(ReconStreamPtrVector<Neighbor> *, iResFile *, int, short, int *)
// Address: 0x8007188C, Size: 100

// int ReconLoadPtrVector<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, iResFile *, int, short, int *)
// Address: 0x800718F0, Size: 52
// Template: ReconLoadPtrVector<Neighbor>
int ReconLoadPtrVector(vector<Neighbor *, allocator<Neighbor *> > & p0, iResFile * p1, int p2, short p3, int * p4) {
    return 0;
}

// Additional instantiation: int ReconSaveObject<ReconStreamPtrVector<Neighbor> >(ReconStreamPtrVector<Neighbor> *, iResFile *, int, short, int)
// Address: 0x80071924, Size: 108

// int ReconSavePtrVector<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, iResFile *, int, short, int)
// Address: 0x80071990, Size: 52
// Template: ReconSavePtrVector<Neighbor>
int ReconSavePtrVector(vector<Neighbor *, allocator<Neighbor *> > & p0, iResFile * p1, int p2, short p3, int p4) {
    return 0;
}

// Neighbor ** __unguarded_partition<Neighbor **, Neighbor *, RelationsCmp>(Neighbor **, Neighbor **, Neighbor *, RelationsCmp)
// Address: 0x80071CD8, Size: 156
// Template: __unguarded_partition<Neighbor **, Neighbor *, RelationsCmp>
Neighbor ** __unguarded_partition(Neighbor ** p0, Neighbor ** p1, Neighbor * p2, RelationsCmp p3) {
    return 0;
}

// void __introsort_loop<Neighbor **, Neighbor *, int, RelationsCmp>(Neighbor **, Neighbor **, Neighbor * *, int, RelationsCmp)
// Address: 0x80071D74, Size: 368
// Template: __introsort_loop<Neighbor **, Neighbor *, int, RelationsCmp>
void __introsort_loop(Neighbor ** p0, Neighbor ** p1, Neighbor * * p2, int p3, RelationsCmp p4) {
}

// void __unguarded_linear_insert<Neighbor **, Neighbor *, RelationsCmp>(Neighbor **, Neighbor *, RelationsCmp)
// Address: 0x80071EE4, Size: 96
// Template: __unguarded_linear_insert<Neighbor **, Neighbor *, RelationsCmp>
void __unguarded_linear_insert(Neighbor ** p0, Neighbor * p1, RelationsCmp p2) {
}

// void __unguarded_insertion_sort_aux<Neighbor **, Neighbor *, RelationsCmp>(Neighbor **, Neighbor **, Neighbor * *, RelationsCmp)
// Address: 0x80071FF8, Size: 92
// Template: __unguarded_insertion_sort_aux<Neighbor **, Neighbor *, RelationsCmp>
void __unguarded_insertion_sort_aux(Neighbor ** p0, Neighbor ** p1, Neighbor * * p2, RelationsCmp p3) {
}

// void DoPtrVectorStream<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, ReconBuffer *, int)
// Address: 0x800723F4, Size: 536
// Template: DoPtrVectorStream<Neighbor>
void DoPtrVectorStream(vector<Neighbor *, allocator<Neighbor *> > & p0, ReconBuffer * p1, int p2) {
}

// Additional instantiation: int ReconLoadObject<ObjectSaveTypeTable3>(ObjectSaveTypeTable3 *, iResFile *, int, short, int *)
// Address: 0x80073038, Size: 100

// Additional instantiation: int ReconLoadObject<ObjectSaveIDTable>(ObjectSaveIDTable *, iResFile *, int, short, int *)
// Address: 0x8007309C, Size: 100

// Additional instantiation: void ReconLoadObject<OptionsRecon>(OptionsRecon *, Memory::HandleNode *, int, int *)
// Address: 0x8009871C, Size: 88

// Additional instantiation: AStringSet * FindRes<AStringSet>(AStringSet *, AStringSet *, int)
// Address: 0x801288D4, Size: 112

// Additional instantiation: WStringSet * FindRes<WStringSet>(WStringSet *, WStringSet *, int)
// Address: 0x80128944, Size: 112

// Additional instantiation: AnimRefTable * FindRes<AnimRefTable>(AnimRefTable *, AnimRefTable *, int)
// Address: 0x8012E5C0, Size: 96

// short * find<short *, short>(short *, short *, short &)
// Address: 0x801312A4, Size: 176
// Template: find<short *, short>
short * find(short * p0, short * p1, short & p2) {
    return 0;
}

// Additional instantiation: CatalogData * FindRes<CatalogData>(CatalogData *, CatalogData *, int)
// Address: 0x80139684, Size: 96

// void DoContainerStream<vector<FamilyMember, allocator<FamilyMember> >, FamilyMember>(vector<FamilyMember, allocator<FamilyMember> > &, FamilyMember *, ReconBuffer *, int)
// Address: 0x8013F5EC, Size: 224
// Template: DoContainerStream<vector<FamilyMember, allocator<FamilyMember> >, FamilyMember>
void DoContainerStream(vector<FamilyMember, allocator<FamilyMember> > & p0, FamilyMember * p1, ReconBuffer * p2, int p3) {
}

// Additional instantiation: int ReconLoadObject<FamilyImpl>(FamilyImpl *, iResFile *, int, short, int *)
// Address: 0x8013F6CC, Size: 100

// Additional instantiation: int ReconSaveObject<FamilyImpl>(FamilyImpl *, iResFile *, int, short, int)
// Address: 0x8013F730, Size: 108

// Additional instantiation: FloatConstantsData * FindRes<FloatConstantsData>(FloatConstantsData *, FloatConstantsData *, int)
// Address: 0x80140198, Size: 96

// Additional instantiation: int ReconLoadObject<HouseImpl>(HouseImpl *, iResFile *, int, short, int *)
// Address: 0x8014CA5C, Size: 100

// Additional instantiation: int ReconSaveObject<HouseImpl>(HouseImpl *, iResFile *, int, short, int)
// Address: 0x8014CB2C, Size: 108

// Additional instantiation: void DoContainerStream<vector<IFFResNode, allocator<IFFResNode> >, IFFResNode>(vector<IFFResNode, allocator<IFFResNode> > &, IFFResNode *, ReconBuffer *, int)
// Address: 0x80151C70, Size: 288

// Additional instantiation: void DoContainerStream<vector<IFFResList, allocator<IFFResList> >, IFFResList>(vector<IFFResList, allocator<IFFResList> > &, IFFResList *, ReconBuffer *, int)
// Address: 0x8015272C, Size: 444

// Additional instantiation: void ReconLoadObject<IFFResMap>(IFFResMap *, Memory::HandleNode *, int, int *)
// Address: 0x801528E8, Size: 88

// Additional instantiation: int ReconLoadObject<NeighborhoodImpl>(NeighborhoodImpl *, iResFile *, int, short, int *)
// Address: 0x80169044, Size: 100

// Additional instantiation: int ReconSaveObject<NeighborhoodImpl>(NeighborhoodImpl *, iResFile *, int, short, int)
// Address: 0x80169854, Size: 108

// Additional instantiation: int * find<int *, int>(int *, int *, int &)
// Address: 0x80194438, Size: 176

// Additional instantiation: int ReconSaveObject<UserDataSaveLoad>(UserDataSaveLoad *, iResFile *, int, short, int)
// Address: 0x80194C48, Size: 108

// Additional instantiation: int ReconSaveObject<ThumbnailLoader>(ThumbnailLoader *, iResFile *, int, short, int)
// Address: 0x80194CB4, Size: 108

// Additional instantiation: int ReconLoadObject<ObjectSaveTypeTable>(ObjectSaveTypeTable *, iResFile *, int, short, int *)
// Address: 0x80194D20, Size: 100

// Additional instantiation: int ReconSaveObject<ObjectSaveTypeTable>(ObjectSaveTypeTable *, iResFile *, int, short, int)
// Address: 0x80194D84, Size: 108

// Additional instantiation: int ReconSaveObject<ObjectFolderImpl>(ObjectFolderImpl *, iResFile *, int, short, int)
// Address: 0x80194DF0, Size: 108

// Additional instantiation: int ReconLoadObject<ObjectFolderImpl>(ObjectFolderImpl *, iResFile *, int, short, int *)
// Address: 0x80194E5C, Size: 100

// Additional instantiation: int ReconSaveObject<ObjectModuleImpl>(ObjectModuleImpl *, iResFile *, int, short, int)
// Address: 0x8019F780, Size: 108

// Additional instantiation: int ReconLoadObject<ObjectModuleImpl>(ObjectModuleImpl *, iResFile *, int, short, int *)
// Address: 0x8019F7EC, Size: 100

// Additional instantiation: ObjFnData * FindRes<ObjFnData>(ObjFnData *, ObjFnData *, int)
// Address: 0x801BE718, Size: 112

// Additional instantiation: void ReconLoadObject<ThumbnailLoader>(ThumbnailLoader *, Memory::HandleNode *, int, int *)
// Address: 0x801C0B64, Size: 88

// Additional instantiation: void DoContainerStream<vector<XRoute, allocator<XRoute> >, XRoute>(vector<XRoute, allocator<XRoute> > &, XRoute *, ReconBuffer *, int)
// Address: 0x801E51C4, Size: 424

// Additional instantiation: void DoContainerStream<vector<ObjectRecord, allocator<ObjectRecord> >, ObjectRecord>(vector<ObjectRecord, allocator<ObjectRecord> > &, ObjectRecord *, ReconBuffer *, int)
// Address: 0x801E5724, Size: 264

// Additional instantiation: void DoContainerStream<vector<MotiveInc, allocator<MotiveInc> >, MotiveInc>(vector<MotiveInc, allocator<MotiveInc> > &, MotiveInc *, ReconBuffer *, int)
// Address: 0x801E5BE4, Size: 264

// void _S_merge<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >(list<ScoredInteraction, allocator<ScoredInteraction> > &, list<ScoredInteraction, allocator<ScoredInteraction> > &, less<ScoredInteraction>)
// Address: 0x801E6148, Size: 236
// Template: _S_merge<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >
void _S_merge(list<ScoredInteraction, allocator<ScoredInteraction> > & p0, list<ScoredInteraction, allocator<ScoredInteraction> > & p1, less<ScoredInteraction> p2) {
}

// Additional instantiation: PropRefTable * FindRes<PropRefTable>(PropRefTable *, PropRefTable *, int)
// Address: 0x801EF888, Size: 96

// Additional instantiation: void DoPtrVectorStream<RelArray>(vector<RelArray *, allocator<RelArray *> > &, ReconBuffer *, int)
// Address: 0x801F3F54, Size: 692

// Additional instantiation: void DoContainerStream<RelArray, RelInt>(RelArray &, RelInt *, ReconBuffer *, int)
// Address: 0x801F4208, Size: 224

// Additional instantiation: SlotDescList * FindRes<SlotDescList>(SlotDescList *, SlotDescList *, int)
// Address: 0x80208700, Size: 96

// Additional instantiation: int ReconLoadObject<ReconStreamVector<SlotDescriptor> >(ReconStreamVector<SlotDescriptor> *, iResFile *, int, short, int *)
// Address: 0x80208760, Size: 100

// int ReconLoadVector<SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, iResFile *, int, short, int *)
// Address: 0x802087C4, Size: 52
// Template: ReconLoadVector<SlotDescriptor>
int ReconLoadVector(vector<SlotDescriptor, allocator<SlotDescriptor> > & p0, iResFile * p1, int p2, short p3, int * p4) {
    return 0;
}

// Additional instantiation: int ReconSaveObject<ReconStreamVector<SlotDescriptor> >(ReconStreamVector<SlotDescriptor> *, iResFile *, int, short, int)
// Address: 0x802087F8, Size: 108

// int ReconSaveVector<SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, iResFile *, int, short, int)
// Address: 0x80208864, Size: 52
// Template: ReconSaveVector<SlotDescriptor>
int ReconSaveVector(vector<SlotDescriptor, allocator<SlotDescriptor> > & p0, iResFile * p1, int p2, short p3, int p4) {
    return 0;
}

// Additional instantiation: void DoContainerStream<vector<SlotDescriptor, allocator<SlotDescriptor> >, SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, SlotDescriptor *, ReconBuffer *, int)
// Address: 0x80208EC4, Size: 248

// Additional instantiation: SndInfo * FindRes<SndInfo>(SndInfo *, SndInfo *, int)
// Address: 0x8020987C, Size: 96

// Additional instantiation: TreeTableEntry * FindRes<TreeTableEntry>(TreeTableEntry *, TreeTableEntry *, int)
// Address: 0x8020F6F4, Size: 112

// Additional instantiation: BehaviorConstants * FindRes<BehaviorConstants>(BehaviorConstants *, BehaviorConstants *, int)
// Address: 0x80226258, Size: 96

// ObjDefinition * * FindResIndirect<ObjDefinition *>(ObjDefinition * *, ObjDefinition * *, int)
// Address: 0x8022931C, Size: 104
// Template: FindResIndirect<ObjDefinition *>
ObjDefinition * * FindResIndirect(ObjDefinition * * p0, ObjDefinition * * p1, int p2) {
    return 0;
}

// Additional instantiation: TreeTable * FindRes<TreeTable>(TreeTable *, TreeTable *, int)
// Address: 0x8022C344, Size: 112

// Additional instantiation: void ReconLoadObject<CasCostumes>(CasCostumes *, Memory::HandleNode *, int, int *)
// Address: 0x8023F928, Size: 88

// pair<CasSimDescriptionS2C **, CasSimDescriptionS2C **> __equal_range<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, CasSimDescriptionS2C * &, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int *)
// Address: 0x80240558, Size: 236
pair<CasSimDescriptionS2C **, CasSimDescriptionS2C **> __equal_range<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool(* p0) {
    return 0;
}

// Additional instantiation: void ReconLoadObject<CasGenetics>(CasGenetics *, Memory::HandleNode *, int, int *)
// Address: 0x80249340, Size: 88

// void arrayRemove<unsigned int>(unsigned int *, unsigned int, unsigned int, unsigned int)
// Address: 0x80284E94, Size: 368
// Template: arrayRemove<unsigned int>
void arrayRemove(unsigned int * p0, unsigned int p1, unsigned int p2, unsigned int p3) {
}

// void arrayInsert<AptCIH *>(AptCIH * *, unsigned int, AptCIH * &, unsigned int)
// Address: 0x80285104, Size: 200
// Template: arrayInsert<AptCIH *>
void arrayInsert(AptCIH * * p0, unsigned int p1, AptCIH * & p2, unsigned int p3) {
}

// Additional instantiation: void arrayRemove<AptCIH *>(AptCIH * *, unsigned int, unsigned int, unsigned int)
// Address: 0x802851CC, Size: 368

// Additional instantiation: unsigned int * find<unsigned int *, unsigned int>(unsigned int *, unsigned int *, unsigned int &)
// Address: 0x80362FDC, Size: 176

// Additional instantiation: CTilePt * find<CTilePt *, CTilePt>(CTilePt *, CTilePt *, CTilePt &)
// Address: 0x803878C8, Size: 300

// Additional instantiation: EInstance ** find<EInstance **, EInstance *>(EInstance **, EInstance **, EInstance * &)
// Address: 0x803A9588, Size: 176

// unsigned int CopyTArray<BSplineVolume, TArrayERModelAllocator>(TArray<BSplineVolume, TArrayERModelAllocator> &, char *)
// Address: 0x804E64A8, Size: 180
// Template: CopyTArray<BSplineVolume, TArrayERModelAllocator>
unsigned int CopyTArray(TArray<BSplineVolume, TArrayERModelAllocator> & p0, char * p1) {
    return 0;
}

// Additional instantiation: unsigned int CopyTArray<ENDummy, TArrayERModelAllocator>(TArray<ENDummy, TArrayERModelAllocator> &, char *)
// Address: 0x804E67AC, Size: 180

// Additional instantiation: unsigned int CopyTArray<ENCamera, TArrayERModelAllocator>(TArray<ENCamera, TArrayERModelAllocator> &, char *)
// Address: 0x804E6AB0, Size: 180

// Additional instantiation: unsigned int CopyTArray<SimsLightInfo, TArrayERModelAllocator>(TArray<SimsLightInfo, TArrayERModelAllocator> &, char *)
// Address: 0x804E6CFC, Size: 160

// EVec3 {anonymous} InterpolateLinear<EVec3>(EVec3, EVec3, float, float, float)
// Address: 0x80533910, Size: 264
// Template: InterpolateLinear<EVec3>
EVec3 InterpolateLinear(EVec3 p0, EVec3 p1, float p2, float p3, float p4) {
    return 0;
}
