// global_templates.cpp - Template function instantiations
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 404 functions
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

// int ReconLoadObject<ObjectSaveTypeTable2>(ObjectSaveTypeTable2 *, iResFile *, int, short, int *)
// Address: 0x80036EF0, Size: 100
int ReconLoadObject<ObjectSaveTypeTable2>(void) {
    return 0;
}

// SpriteIdToResIdNode * FindRes<SpriteIdToResIdNode>(SpriteIdToResIdNode *, SpriteIdToResIdNode *, int)
// Address: 0x8006D74C, Size: 112
SpriteIdToResIdNode * FindRes<SpriteIdToResIdNode>(void) {
    return 0;
}

// int ReconLoadObject<cSimulator>(cSimulator *, iResFile *, int, short, int *)
// Address: 0x80071764, Size: 100
int ReconLoadObject<cSimulator>(void) {
    return 0;
}

// int ReconSaveObject<cSimulator>(cSimulator *, iResFile *, int, short, int)
// Address: 0x800717C8, Size: 108
int ReconSaveObject<cSimulator>(void) {
    return 0;
}

// void ReconLoadObject<UserDataSaveLoad>(UserDataSaveLoad *, Memory::HandleNode *, int, int *)
// Address: 0x80071834, Size: 88
void ReconLoadObject<UserDataSaveLoad>(void) {
}

// int ReconLoadObject<ReconStreamPtrVector<Neighbor> >(ReconStreamPtrVector<Neighbor> *, iResFile *, int, short, int *)
// Address: 0x8007188C, Size: 100
int ReconLoadObject<ReconStreamPtrVector<Neighbor> >(void) {
    return 0;
}

// int ReconLoadPtrVector<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, iResFile *, int, short, int *)
// Address: 0x800718F0, Size: 52
int ReconLoadPtrVector<Neighbor>(void) {
    return 0;
}

// int ReconSaveObject<ReconStreamPtrVector<Neighbor> >(ReconStreamPtrVector<Neighbor> *, iResFile *, int, short, int)
// Address: 0x80071924, Size: 108
int ReconSaveObject<ReconStreamPtrVector<Neighbor> >(void) {
    return 0;
}

// int ReconSavePtrVector<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, iResFile *, int, short, int)
// Address: 0x80071990, Size: 52
int ReconSavePtrVector<Neighbor>(void) {
    return 0;
}

// void DoPtrVectorStream<Neighbor>(vector<Neighbor *, allocator<Neighbor *> > &, ReconBuffer *, int)
// Address: 0x800723F4, Size: 536
void DoPtrVectorStream<Neighbor>(void) {
}

// int ReconLoadObject<ObjectSaveTypeTable3>(ObjectSaveTypeTable3 *, iResFile *, int, short, int *)
// Address: 0x80073038, Size: 100
int ReconLoadObject<ObjectSaveTypeTable3>(void) {
    return 0;
}

// int ReconLoadObject<ObjectSaveIDTable>(ObjectSaveIDTable *, iResFile *, int, short, int *)
// Address: 0x8007309C, Size: 100
int ReconLoadObject<ObjectSaveIDTable>(void) {
    return 0;
}

// void ReconLoadObject<OptionsRecon>(OptionsRecon *, Memory::HandleNode *, int, int *)
// Address: 0x8009871C, Size: 88
void ReconLoadObject<OptionsRecon>(void) {
}

// AStringSet * FindRes<AStringSet>(AStringSet *, AStringSet *, int)
// Address: 0x801288D4, Size: 112
AStringSet * FindRes<AStringSet>(void) {
    return 0;
}

// WStringSet * FindRes<WStringSet>(WStringSet *, WStringSet *, int)
// Address: 0x80128944, Size: 112
WStringSet * FindRes<WStringSet>(void) {
    return 0;
}

// AnimRefTable * FindRes<AnimRefTable>(AnimRefTable *, AnimRefTable *, int)
// Address: 0x8012E5C0, Size: 96
AnimRefTable * FindRes<AnimRefTable>(void) {
    return 0;
}

// short * find<short *, short>(short *, short *, short &)
// Address: 0x801312A4, Size: 176
short * find<short *, short>(void) {
    return 0;
}

// CatalogData * FindRes<CatalogData>(CatalogData *, CatalogData *, int)
// Address: 0x80139684, Size: 96
CatalogData * FindRes<CatalogData>(void) {
    return 0;
}

// CBMemberTranslator1<int, EdithDialogPrimitive, void (EdithDialogPrimitive::*)(EdithDialogPrimitive *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8013E628, Size: 120
void CBMemberTranslator1<int, EdithDialogPrimitive, void (EdithDialogPrimitive::*)(EdithDialogPrimitive *, int)>(void) {
}

// CBMemberTranslator0<EdithDialogPrimitive, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8013E6A0, Size: 120
void CBMemberTranslator0<EdithDialogPrimitive, void (UIDialog::*)(UIDialog *)>(void) {
}

// void DoContainerStream<vector<FamilyMember, allocator<FamilyMember> >, FamilyMember>(vector<FamilyMember, allocator<FamilyMember> > &, FamilyMember *, ReconBuffer *, int)
// Address: 0x8013F5EC, Size: 224
void DoContainerStream<vector<FamilyMember, allocator<FamilyMember> >, FamilyMember>(void) {
}

// int ReconLoadObject<FamilyImpl>(FamilyImpl *, iResFile *, int, short, int *)
// Address: 0x8013F6CC, Size: 100
int ReconLoadObject<FamilyImpl>(void) {
    return 0;
}

// int ReconSaveObject<FamilyImpl>(FamilyImpl *, iResFile *, int, short, int)
// Address: 0x8013F730, Size: 108
int ReconSaveObject<FamilyImpl>(void) {
    return 0;
}

// FloatConstantsData * FindRes<FloatConstantsData>(FloatConstantsData *, FloatConstantsData *, int)
// Address: 0x80140198, Size: 96
FloatConstantsData * FindRes<FloatConstantsData>(void) {
    return 0;
}

// int ReconLoadObject<HouseImpl>(HouseImpl *, iResFile *, int, short, int *)
// Address: 0x8014CA5C, Size: 100
int ReconLoadObject<HouseImpl>(void) {
    return 0;
}

// int ReconSaveObject<HouseImpl>(HouseImpl *, iResFile *, int, short, int)
// Address: 0x8014CB2C, Size: 108
int ReconSaveObject<HouseImpl>(void) {
    return 0;
}

// void DoContainerStream<vector<IFFResNode, allocator<IFFResNode> >, IFFResNode>(vector<IFFResNode, allocator<IFFResNode> > &, IFFResNode *, ReconBuffer *, int)
// Address: 0x80151C70, Size: 288
void DoContainerStream<vector<IFFResNode, allocator<IFFResNode> >, IFFResNode>(void) {
}

// void DoContainerStream<vector<IFFResList, allocator<IFFResList> >, IFFResList>(vector<IFFResList, allocator<IFFResList> > &, IFFResList *, ReconBuffer *, int)
// Address: 0x8015272C, Size: 444
void DoContainerStream<vector<IFFResList, allocator<IFFResList> >, IFFResList>(void) {
}

// void ReconLoadObject<IFFResMap>(IFFResMap *, Memory::HandleNode *, int, int *)
// Address: 0x801528E8, Size: 88
void ReconLoadObject<IFFResMap>(void) {
}

// int ReconLoadObject<NeighborhoodImpl>(NeighborhoodImpl *, iResFile *, int, short, int *)
// Address: 0x80169044, Size: 100
int ReconLoadObject<NeighborhoodImpl>(void) {
    return 0;
}

// int ReconSaveObject<NeighborhoodImpl>(NeighborhoodImpl *, iResFile *, int, short, int)
// Address: 0x80169854, Size: 108
int ReconSaveObject<NeighborhoodImpl>(void) {
    return 0;
}

// int * find<int *, int>(int *, int *, int &)
// Address: 0x80194438, Size: 176
int * find<int *, int>(void) {
    return 0;
}

// int ReconSaveObject<UserDataSaveLoad>(UserDataSaveLoad *, iResFile *, int, short, int)
// Address: 0x80194C48, Size: 108
int ReconSaveObject<UserDataSaveLoad>(void) {
    return 0;
}

// int ReconSaveObject<ThumbnailLoader>(ThumbnailLoader *, iResFile *, int, short, int)
// Address: 0x80194CB4, Size: 108
int ReconSaveObject<ThumbnailLoader>(void) {
    return 0;
}

// int ReconLoadObject<ObjectSaveTypeTable>(ObjectSaveTypeTable *, iResFile *, int, short, int *)
// Address: 0x80194D20, Size: 100
int ReconLoadObject<ObjectSaveTypeTable>(void) {
    return 0;
}

// int ReconSaveObject<ObjectSaveTypeTable>(ObjectSaveTypeTable *, iResFile *, int, short, int)
// Address: 0x80194D84, Size: 108
int ReconSaveObject<ObjectSaveTypeTable>(void) {
    return 0;
}

// int ReconSaveObject<ObjectFolderImpl>(ObjectFolderImpl *, iResFile *, int, short, int)
// Address: 0x80194DF0, Size: 108
int ReconSaveObject<ObjectFolderImpl>(void) {
    return 0;
}

// int ReconLoadObject<ObjectFolderImpl>(ObjectFolderImpl *, iResFile *, int, short, int *)
// Address: 0x80194E5C, Size: 100
int ReconLoadObject<ObjectFolderImpl>(void) {
    return 0;
}

// int ReconSaveObject<ObjectModuleImpl>(ObjectModuleImpl *, iResFile *, int, short, int)
// Address: 0x8019F780, Size: 108
int ReconSaveObject<ObjectModuleImpl>(void) {
    return 0;
}

// int ReconLoadObject<ObjectModuleImpl>(ObjectModuleImpl *, iResFile *, int, short, int *)
// Address: 0x8019F7EC, Size: 100
int ReconLoadObject<ObjectModuleImpl>(void) {
    return 0;
}

// ObjFnData * FindRes<ObjFnData>(ObjFnData *, ObjFnData *, int)
// Address: 0x801BE718, Size: 112
ObjFnData * FindRes<ObjFnData>(void) {
    return 0;
}

// void ReconLoadObject<ThumbnailLoader>(ThumbnailLoader *, Memory::HandleNode *, int, int *)
// Address: 0x801C0B64, Size: 88
void ReconLoadObject<ThumbnailLoader>(void) {
}

// void DoContainerStream<vector<XRoute, allocator<XRoute> >, XRoute>(vector<XRoute, allocator<XRoute> > &, XRoute *, ReconBuffer *, int)
// Address: 0x801E51C4, Size: 424
void DoContainerStream<vector<XRoute, allocator<XRoute> >, XRoute>(void) {
}

// void DoContainerStream<vector<ObjectRecord, allocator<ObjectRecord> >, ObjectRecord>(vector<ObjectRecord, allocator<ObjectRecord> > &, ObjectRecord *, ReconBuffer *, int)
// Address: 0x801E5724, Size: 264
void DoContainerStream<vector<ObjectRecord, allocator<ObjectRecord> >, ObjectRecord>(void) {
}

// void DoContainerStream<vector<MotiveInc, allocator<MotiveInc> >, MotiveInc>(vector<MotiveInc, allocator<MotiveInc> > &, MotiveInc *, ReconBuffer *, int)
// Address: 0x801E5BE4, Size: 264
void DoContainerStream<vector<MotiveInc, allocator<MotiveInc> >, MotiveInc>(void) {
}

// void _S_merge<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >(list<ScoredInteraction, allocator<ScoredInteraction> > &, list<ScoredInteraction, allocator<ScoredInteraction> 
// Address: 0x801E6148, Size: 236
void _S_merge<ScoredInteraction, allocator<ScoredInteraction>, less<ScoredInteraction> >(void) {
}

// PropRefTable * FindRes<PropRefTable>(PropRefTable *, PropRefTable *, int)
// Address: 0x801EF888, Size: 96
PropRefTable * FindRes<PropRefTable>(void) {
    return 0;
}

// void DoPtrVectorStream<RelArray>(vector<RelArray *, allocator<RelArray *> > &, ReconBuffer *, int)
// Address: 0x801F3F54, Size: 692
void DoPtrVectorStream<RelArray>(void) {
}

// void DoContainerStream<RelArray, RelInt>(RelArray &, RelInt *, ReconBuffer *, int)
// Address: 0x801F4208, Size: 224
void DoContainerStream<RelArray, RelInt>(void) {
}

// SlotDescList * FindRes<SlotDescList>(SlotDescList *, SlotDescList *, int)
// Address: 0x80208700, Size: 96
SlotDescList * FindRes<SlotDescList>(void) {
    return 0;
}

// int ReconLoadObject<ReconStreamVector<SlotDescriptor> >(ReconStreamVector<SlotDescriptor> *, iResFile *, int, short, int *)
// Address: 0x80208760, Size: 100
int ReconLoadObject<ReconStreamVector<SlotDescriptor> >(void) {
    return 0;
}

// int ReconLoadVector<SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, iResFile *, int, short, int *)
// Address: 0x802087C4, Size: 52
int ReconLoadVector<SlotDescriptor>(void) {
    return 0;
}

// int ReconSaveObject<ReconStreamVector<SlotDescriptor> >(ReconStreamVector<SlotDescriptor> *, iResFile *, int, short, int)
// Address: 0x802087F8, Size: 108
int ReconSaveObject<ReconStreamVector<SlotDescriptor> >(void) {
    return 0;
}

// int ReconSaveVector<SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, iResFile *, int, short, int)
// Address: 0x80208864, Size: 52
int ReconSaveVector<SlotDescriptor>(void) {
    return 0;
}

// void DoContainerStream<vector<SlotDescriptor, allocator<SlotDescriptor> >, SlotDescriptor>(vector<SlotDescriptor, allocator<SlotDescriptor> > &, SlotDescriptor *, ReconBuffer *, int)
// Address: 0x80208EC4, Size: 248
void DoContainerStream<vector<SlotDescriptor, allocator<SlotDescriptor> >, SlotDescriptor>(void) {
}

// SndInfo * FindRes<SndInfo>(SndInfo *, SndInfo *, int)
// Address: 0x8020987C, Size: 96
SndInfo * FindRes<SndInfo>(void) {
    return 0;
}

// TreeTableEntry * FindRes<TreeTableEntry>(TreeTableEntry *, TreeTableEntry *, int)
// Address: 0x8020F6F4, Size: 112
TreeTableEntry * FindRes<TreeTableEntry>(void) {
    return 0;
}

// BehaviorConstants * FindRes<BehaviorConstants>(BehaviorConstants *, BehaviorConstants *, int)
// Address: 0x80226258, Size: 96
BehaviorConstants * FindRes<BehaviorConstants>(void) {
    return 0;
}

// ObjDefinition * * FindResIndirect<ObjDefinition *>(ObjDefinition * *, ObjDefinition * *, int)
// Address: 0x8022931C, Size: 104
ObjDefinition * * FindResIndirect<ObjDefinition *>(void) {
    return 0;
}

// TreeTable * FindRes<TreeTable>(TreeTable *, TreeTable *, int)
// Address: 0x8022C344, Size: 112
TreeTable * FindRes<TreeTable>(void) {
    return 0;
}

// void ReconLoadObject<CasCostumes>(CasCostumes *, Memory::HandleNode *, int, int *)
// Address: 0x8023F928, Size: 88
void ReconLoadObject<CasCostumes>(void) {
}

// CasSimDescriptionS2C ** __lower_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, 
// Address: 0x80240458, Size: 128
CasSimDescriptionS2C ** __lower_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(void) {
    return 0;
}

// CasSimDescriptionS2C ** __upper_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2C **, CasSimDescriptionS2C **, 
// Address: 0x802404D8, Size: 128
CasSimDescriptionS2C ** __upper_bound<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(void) {
    return 0;
}

// pair<CasSimDescriptionS2C **, CasSimDescriptionS2C **> __equal_range<CasSimDescriptionS2C **, CasSimDescriptionS2C *, bool (*)(CasSimDescriptionS2C *, CasSimDescriptionS2C *), int>(CasSimDescriptionS2
// Address: 0x80240558, Size: 236
void pair<CasSimDescriptionS2C **, CasSimDescriptionS2C **>(void) {
}

// void ReconLoadObject<CasGenetics>(CasGenetics *, Memory::HandleNode *, int, int *)
// Address: 0x80249340, Size: 88
void ReconLoadObject<CasGenetics>(void) {
}

// CBMemberTranslator1<int, HelpDialog, void (HelpDialog::*)(HelpDialog *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8026CC64, Size: 120
void CBMemberTranslator1<int, HelpDialog, void (HelpDialog::*)(HelpDialog *, int)>(void) {
}

// CBMemberTranslator0<HelpDialog, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8026CCDC, Size: 120
void CBMemberTranslator0<HelpDialog, void (UIDialog::*)(UIDialog *)>(void) {
}

// CBMemberTranslator0<UI3D, void (UI3D::*)(UI3D *)>::thunk(CBFunctorBase &)
// Address: 0x8026E190, Size: 120
void CBMemberTranslator0<UI3D, void (UI3D::*)(UI3D *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, UIDBTarget, char *(UIDBTarget::*)(UIDBTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027358C, Size: 120
void CBMemberTranslator1wRet<char *, char *, UIDBTarget, char *(UIDBTarget::*)(UIDBTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, UIDBTarget, void (UIDBTarget::*)(UIDBTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80273604, Size: 120
void CBMemberTranslator2<char *, char *, UIDBTarget, void (UIDBTarget::*)(UIDBTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIDBTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027367C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIDBTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<UIDBTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802736F4, Size: 120
void CBMemberTranslator0<UIDBTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, UIDBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027376C, Size: 120
void CBMemberTranslator1<ERC *, UIDBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, FlowGotoTarget, char *(FlowGotoTarget::*)(FlowGotoTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80274E84, Size: 120
void CBMemberTranslator1wRet<char *, char *, FlowGotoTarget, char *(FlowGotoTarget::*)(FlowGotoTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, FlowGotoTarget, void (FlowGotoTarget::*)(FlowGotoTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80274EFC, Size: 120
void CBMemberTranslator2<char *, char *, FlowGotoTarget, void (FlowGotoTarget::*)(FlowGotoTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, FlowGotoTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80274F74, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, FlowGotoTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x80274FEC, Size: 120
void CBMemberTranslator0<FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80275064, Size: 120
void CBMemberTranslator1<ERC *, FlowGotoTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, UIQDTarget, char *(UIQDTarget::*)(UIQDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80277464, Size: 120
void CBMemberTranslator1wRet<char *, char *, UIQDTarget, char *(UIQDTarget::*)(UIQDTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802774DC, Size: 120
void CBMemberTranslator2<char *, char *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIQDTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80277554, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIQDTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<UIQDTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802775CC, Size: 120
void CBMemberTranslator0<UIQDTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80277644, Size: 120
void CBMemberTranslator1<ERC *, UIQDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, UIScreenManager, char *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027B4E8, Size: 120
void CBMemberTranslator1wRet<char *, char *, UIScreenManager, char *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, UIScreenManager, void (UIScreenManager::*)(UIScreenManager *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027B560, Size: 120
void CBMemberTranslator2<char *, char *, UIScreenManager, void (UIScreenManager::*)(UIScreenManager *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIScreenManager, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027B5D8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIScreenManager, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<UIScreenManager, void (UIScreenManager::*)(UIScreenManager *)>::thunk(CBFunctorBase &)
// Address: 0x8027B650, Size: 120
void CBMemberTranslator0<UIScreenManager, void (UIScreenManager::*)(UIScreenManager *)>(void) {
}

// CBMemberTranslator1<ERC *, UIScreenManager, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027B6C8, Size: 120
void CBMemberTranslator1<ERC *, UIScreenManager, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, UIAUDIOTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027D60C, Size: 120
void CBMemberTranslator1wRet<char *, char *, UIAUDIOTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, UIAUDIOTarget, void (UIAUDIOTarget::*)(UIAUDIOTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027D684, Size: 120
void CBMemberTranslator2<char *, char *, UIAUDIOTarget, void (UIAUDIOTarget::*)(UIAUDIOTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIAUDIOTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027D6FC, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIAUDIOTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8027D774, Size: 120
void CBMemberTranslator0<UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027D7EC, Size: 120
void CBMemberTranslator1<ERC *, UIAUDIOTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, UIAnalog, char *(UIAnalog::*)(UIAnalog *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027D864, Size: 120
void CBMemberTranslator1wRet<char *, char *, UIAnalog, char *(UIAnalog::*)(UIAnalog *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8027D8DC, Size: 120
void CBMemberTranslator2<char *, char *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIAnalog, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8027D954, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, UIAnalog, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<UIAnalog, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8027D9CC, Size: 120
void CBMemberTranslator0<UIAnalog, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8027DA44, Size: 120
void CBMemberTranslator1<ERC *, UIAnalog, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, HUDTarget, char *(HUDTarget::*)(HUDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8028D420, Size: 120
void CBMemberTranslator1wRet<char *, char *, HUDTarget, char *(HUDTarget::*)(HUDTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, HUDTarget, void (HUDTarget::*)(HUDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8028D498, Size: 120
void CBMemberTranslator2<char *, char *, HUDTarget, void (HUDTarget::*)(HUDTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, HUDTarget, unsigned wchar_t *(HUDTarget::*)(HUDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8028D510, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, HUDTarget, unsigned wchar_t *(HUDTarget::*)(HUDTarget *, char *)>(void) {
}

// CBMemberTranslator0<HUDTarget, void (HUDTarget::*)(HUDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8028D588, Size: 120
void CBMemberTranslator0<HUDTarget, void (HUDTarget::*)(HUDTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, HUDTarget, void (HUDTarget::*)(HUDTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8028D600, Size: 120
void CBMemberTranslator1<ERC *, HUDTarget, void (HUDTarget::*)(HUDTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, LoadGameTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802916FC, Size: 120
void CBMemberTranslator1wRet<char *, char *, LoadGameTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80291774, Size: 120
void CBMemberTranslator2<char *, char *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, LoadGameTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802917EC, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, LoadGameTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80291864, Size: 120
void CBMemberTranslator0<LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802918DC, Size: 120
void CBMemberTranslator1<ERC *, LoadGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x80291954, Size: 120
void CBMemberTranslator1<int, LoadGameTarget, void (LoadGameTarget::*)(LoadGameTarget *, int)>(void) {
}

// CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x802919CC, Size: 144
void CBMemberTranslator0<LoadGameTarget, void (UIDialog::*)(UIDialog *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, SaveGameTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80295D54, Size: 120
void CBMemberTranslator1wRet<char *, char *, SaveGameTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80295DCC, Size: 120
void CBMemberTranslator2<char *, char *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, SaveGameTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80295E44, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, SaveGameTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80295EBC, Size: 120
void CBMemberTranslator0<SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80295F34, Size: 120
void CBMemberTranslator1<ERC *, SaveGameTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x80295FAC, Size: 120
void CBMemberTranslator1<int, SaveGameTarget, void (SaveGameTarget::*)(SaveGameTarget *, int)>(void) {
}

// CBMemberTranslator0<SaveGameTarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x80296024, Size: 144
void CBMemberTranslator0<SaveGameTarget, void (UIDialog::*)(UIDialog *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASTarget, char *(CASTarget::*)(CASTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AE598, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASTarget, char *(CASTarget::*)(CASTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASTarget, void (CASTarget::*)(CASTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AE610, Size: 120
void CBMemberTranslator2<char *, char *, CASTarget, void (CASTarget::*)(CASTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASTarget, unsigned wchar_t *(CASTarget::*)(CASTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AE688, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASTarget, unsigned wchar_t *(CASTarget::*)(CASTarget *, char *)>(void) {
}

// CBMemberTranslator0<CASTarget, void (CASTarget::*)(CASTarget *)>::thunk(CBFunctorBase &)
// Address: 0x802AE700, Size: 120
void CBMemberTranslator0<CASTarget, void (CASTarget::*)(CASTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, CASTarget, void (CASTarget::*)(CASTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AE778, Size: 120
void CBMemberTranslator1<ERC *, CASTarget, void (CASTarget::*)(CASTarget *, ERC *)>(void) {
}

// CBMemberTranslator1<int, CASTarget, void (CASTarget::*)(CASTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x802AE7F0, Size: 120
void CBMemberTranslator1<int, CASTarget, void (CASTarget::*)(CASTarget *, int)>(void) {
}

// CBMemberTranslator0<UIDialog, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x802AE868, Size: 120
void CBMemberTranslator0<UIDialog, void (UIDialog::*)(UIDialog *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASBodyTarget, char *(CASBodyTarget::*)(CASBodyTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AE8E0, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASBodyTarget, char *(CASBodyTarget::*)(CASBodyTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASBodyTarget, void (CASBodyTarget::*)(CASBodyTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AE958, Size: 120
void CBMemberTranslator2<char *, char *, CASBodyTarget, void (CASBodyTarget::*)(CASBodyTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASBodyTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AE9D0, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASBodyTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AEA48, Size: 120
void CBMemberTranslator0<CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AEAC0, Size: 120
void CBMemberTranslator1<ERC *, CASBodyTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASGeneticsTarget, char *(CASGeneticsTarget::*)(CASGeneticsTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AEB38, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASGeneticsTarget, char *(CASGeneticsTarget::*)(CASGeneticsTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AEBB0, Size: 120
void CBMemberTranslator2<char *, char *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASGeneticsTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AEC28, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASGeneticsTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *)>::thunk(CBFunctorBase &)
// Address: 0x802AECA0, Size: 120
void CBMemberTranslator0<CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AED18, Size: 120
void CBMemberTranslator1<ERC *, CASGeneticsTarget, void (CASGeneticsTarget::*)(CASGeneticsTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASSelectionTarget, char *(CASSelectionTarget::*)(CASSelectionTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AED90, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASSelectionTarget, char *(CASSelectionTarget::*)(CASSelectionTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASSelectionTarget, void (CASSelectionTarget::*)(CASSelectionTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AEE08, Size: 120
void CBMemberTranslator2<char *, char *, CASSelectionTarget, void (CASSelectionTarget::*)(CASSelectionTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASSelectionTarget, unsigned wchar_t *(CASSelectionTarget::*)(CASSelectionTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AEE80, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASSelectionTarget, unsigned wchar_t *(CASSelectionTarget::*)(CASSelectionTarget *, char *)>(void) {
}

// CBMemberTranslator0<CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AEEF8, Size: 120
void CBMemberTranslator0<CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AEF70, Size: 120
void CBMemberTranslator1<ERC *, CASSelectionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASFashionTarget, char *(CASFashionTarget::*)(CASFashionTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AEFE8, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASFashionTarget, char *(CASFashionTarget::*)(CASFashionTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASFashionTarget, void (CASFashionTarget::*)(CASFashionTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF060, Size: 120
void CBMemberTranslator2<char *, char *, CASFashionTarget, void (CASFashionTarget::*)(CASFashionTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASFashionTarget, unsigned wchar_t *(CASFashionTarget::*)(CASFashionTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF0D8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASFashionTarget, unsigned wchar_t *(CASFashionTarget::*)(CASFashionTarget *, char *)>(void) {
}

// CBMemberTranslator0<CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF150, Size: 120
void CBMemberTranslator0<CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF1C8, Size: 120
void CBMemberTranslator1<ERC *, CASFashionTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASMiscTarget, char *(CASMiscTarget::*)(CASMiscTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF240, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASMiscTarget, char *(CASMiscTarget::*)(CASMiscTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASMiscTarget, void (CASMiscTarget::*)(CASMiscTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF2B8, Size: 120
void CBMemberTranslator2<char *, char *, CASMiscTarget, void (CASMiscTarget::*)(CASMiscTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASMiscTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF330, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASMiscTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF3A8, Size: 120
void CBMemberTranslator0<CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF420, Size: 120
void CBMemberTranslator1<ERC *, CASMiscTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASMorphTarget, char *(CASMorphTarget::*)(CASMorphTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF498, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASMorphTarget, char *(CASMorphTarget::*)(CASMorphTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASMorphTarget, void (CASMorphTarget::*)(CASMorphTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF510, Size: 120
void CBMemberTranslator2<char *, char *, CASMorphTarget, void (CASMorphTarget::*)(CASMorphTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASMorphTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF588, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASMorphTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF600, Size: 120
void CBMemberTranslator0<CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF678, Size: 120
void CBMemberTranslator1<ERC *, CASMorphTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASPersonalTarget, char *(CASPersonalTarget::*)(CASPersonalTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF6F0, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASPersonalTarget, char *(CASPersonalTarget::*)(CASPersonalTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASPersonalTarget, void (CASPersonalTarget::*)(CASPersonalTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AF768, Size: 120
void CBMemberTranslator2<char *, char *, CASPersonalTarget, void (CASPersonalTarget::*)(CASPersonalTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASPersonalTarget, unsigned wchar_t *(CASPersonalTarget::*)(CASPersonalTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF7E0, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASPersonalTarget, unsigned wchar_t *(CASPersonalTarget::*)(CASPersonalTarget *, char *)>(void) {
}

// CBMemberTranslator0<CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AF858, Size: 120
void CBMemberTranslator0<CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AF8D0, Size: 120
void CBMemberTranslator1<ERC *, CASPersonalTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASTattooTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AF9B8, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASTattooTarget, char *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASTattooTarget, void (CASTattooTarget::*)(CASTattooTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AFA30, Size: 120
void CBMemberTranslator2<char *, char *, CASTattooTarget, void (CASTattooTarget::*)(CASTattooTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASTattooTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AFAA8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASTattooTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AFB20, Size: 120
void CBMemberTranslator0<CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AFB98, Size: 120
void CBMemberTranslator1<ERC *, CASTattooTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CASRoommateTarget, char *(CASRoommateTarget::*)(CASRoommateTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AFC10, Size: 120
void CBMemberTranslator1wRet<char *, char *, CASRoommateTarget, char *(CASRoommateTarget::*)(CASRoommateTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x802AFC88, Size: 120
void CBMemberTranslator2<char *, char *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASRoommateTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x802AFD00, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CASRoommateTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<CASRoommateTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x802AFD78, Size: 120
void CBMemberTranslator0<CASRoommateTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x802AFDF0, Size: 120
void CBMemberTranslator1<ERC *, CASRoommateTarget, void (CASRoommateTarget::*)(CASRoommateTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, ACTTarget, char *(ACTTarget::*)(ACTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031925C, Size: 120
void CBMemberTranslator1wRet<char *, char *, ACTTarget, char *(ACTTarget::*)(ACTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, ACTTarget, void (ACTTarget::*)(ACTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x803192D4, Size: 120
void CBMemberTranslator2<char *, char *, ACTTarget, void (ACTTarget::*)(ACTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, ACTTarget, unsigned wchar_t *(ACTTarget::*)(ACTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031934C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, ACTTarget, unsigned wchar_t *(ACTTarget::*)(ACTTarget *, char *)>(void) {
}

// CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x803193C4, Size: 120
void CBMemberTranslator0<ACTTarget, void (ACTTarget::*)(ACTTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031943C, Size: 120
void CBMemberTranslator1<ERC *, ACTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, BBHTarget, char *(BBHTarget::*)(BBHTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x803194B4, Size: 120
void CBMemberTranslator1wRet<char *, char *, BBHTarget, char *(BBHTarget::*)(BBHTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, BBHTarget, void (BBHTarget::*)(BBHTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031952C, Size: 120
void CBMemberTranslator2<char *, char *, BBHTarget, void (BBHTarget::*)(BBHTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, BBHTarget, unsigned wchar_t *(BBHTarget::*)(BBHTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x803195A4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, BBHTarget, unsigned wchar_t *(BBHTarget::*)(BBHTarget *, char *)>(void) {
}

// CBMemberTranslator0<BBHTarget, void (BBHTarget::*)(BBHTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031961C, Size: 120
void CBMemberTranslator0<BBHTarget, void (BBHTarget::*)(BBHTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, BBHTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319694, Size: 120
void CBMemberTranslator1<ERC *, BBHTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CRDTarget, char *(CRDTarget::*)(CRDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80319A9C, Size: 120
void CBMemberTranslator1wRet<char *, char *, CRDTarget, char *(CRDTarget::*)(CRDTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CRDTarget, void (CRDTarget::*)(CRDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80319B14, Size: 120
void CBMemberTranslator2<char *, char *, CRDTarget, void (CRDTarget::*)(CRDTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CRDTarget, unsigned wchar_t *(CRDTarget::*)(CRDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80319B8C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CRDTarget, unsigned wchar_t *(CRDTarget::*)(CRDTarget *, char *)>(void) {
}

// CBMemberTranslator0<CRDTarget, void (CRDTarget::*)(CRDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80319C04, Size: 120
void CBMemberTranslator0<CRDTarget, void (CRDTarget::*)(CRDTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319C7C, Size: 120
void CBMemberTranslator1<ERC *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *)>(void) {
}

// CBMemberTranslator2<ERC *, structDrawCBparams *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x80319CF4, Size: 120
void CBMemberTranslator2<ERC *, structDrawCBparams *, CRDTarget, void (CRDTarget::*)(CRDTarget *, ERC *, structDrawCBparams *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CSMTarget, char *(CSMTarget::*)(CSMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80319D6C, Size: 120
void CBMemberTranslator1wRet<char *, char *, CSMTarget, char *(CSMTarget::*)(CSMTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CSMTarget, void (CSMTarget::*)(CSMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x80319DE4, Size: 120
void CBMemberTranslator2<char *, char *, CSMTarget, void (CSMTarget::*)(CSMTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CSMTarget, unsigned wchar_t *(CSMTarget::*)(CSMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80319E5C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CSMTarget, unsigned wchar_t *(CSMTarget::*)(CSMTarget *, char *)>(void) {
}

// CBMemberTranslator0<CSMTarget, void (CSMTarget::*)(CSMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x80319ED4, Size: 120
void CBMemberTranslator0<CSMTarget, void (CSMTarget::*)(CSMTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, CSMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x80319F4C, Size: 120
void CBMemberTranslator1<ERC *, CSMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, CSPTarget, char *(CSPTarget::*)(CSPTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x80319FC4, Size: 120
void CBMemberTranslator1wRet<char *, char *, CSPTarget, char *(CSPTarget::*)(CSPTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, CSPTarget, void (CSPTarget::*)(CSPTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A03C, Size: 120
void CBMemberTranslator2<char *, char *, CSPTarget, void (CSPTarget::*)(CSPTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, CSPTarget, unsigned wchar_t *(CSPTarget::*)(CSPTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A0B4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, CSPTarget, unsigned wchar_t *(CSPTarget::*)(CSPTarget *, char *)>(void) {
}

// CBMemberTranslator0<CSPTarget, void (CSPTarget::*)(CSPTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A12C, Size: 120
void CBMemberTranslator0<CSPTarget, void (CSPTarget::*)(CSPTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, CSPTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A1A4, Size: 120
void CBMemberTranslator1<ERC *, CSPTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, E2ETarget, char *(E2ETarget::*)(E2ETarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A22C, Size: 120
void CBMemberTranslator1wRet<char *, char *, E2ETarget, char *(E2ETarget::*)(E2ETarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, E2ETarget, void (E2ETarget::*)(E2ETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A2A4, Size: 120
void CBMemberTranslator2<char *, char *, E2ETarget, void (E2ETarget::*)(E2ETarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, E2ETarget, unsigned wchar_t *(E2ETarget::*)(E2ETarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A31C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, E2ETarget, unsigned wchar_t *(E2ETarget::*)(E2ETarget *, char *)>(void) {
}

// CBMemberTranslator0<E2ETarget, void (E2ETarget::*)(E2ETarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A394, Size: 120
void CBMemberTranslator0<E2ETarget, void (E2ETarget::*)(E2ETarget *)>(void) {
}

// CBMemberTranslator1<ERC *, E2ETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A40C, Size: 120
void CBMemberTranslator1<ERC *, E2ETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator2<ERC *, structDrawCBparams *, E2ETarget, void (E2ETarget::*)(E2ETarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8031A484, Size: 120
void CBMemberTranslator2<ERC *, structDrawCBparams *, E2ETarget, void (E2ETarget::*)(E2ETarget *, ERC *, structDrawCBparams *)>(void) {
}

// CBMemberTranslator1<int, E2ETarget, void (E2ETarget::*)(E2ETarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031A4FC, Size: 120
void CBMemberTranslator1<int, E2ETarget, void (E2ETarget::*)(E2ETarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, FAMTarget, char *(FAMTarget::*)(FAMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A710, Size: 120
void CBMemberTranslator1wRet<char *, char *, FAMTarget, char *(FAMTarget::*)(FAMTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, FAMTarget, void (FAMTarget::*)(FAMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031A788, Size: 120
void CBMemberTranslator2<char *, char *, FAMTarget, void (FAMTarget::*)(FAMTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, FAMTarget, unsigned wchar_t *(FAMTarget::*)(FAMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A800, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, FAMTarget, unsigned wchar_t *(FAMTarget::*)(FAMTarget *, char *)>(void) {
}

// CBMemberTranslator0<FAMTarget, void (FAMTarget::*)(FAMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031A878, Size: 120
void CBMemberTranslator0<FAMTarget, void (FAMTarget::*)(FAMTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, FAMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031A8F0, Size: 120
void CBMemberTranslator1<ERC *, FAMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, FAMTarget, void (FAMTarget::*)(FAMTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031A968, Size: 120
void CBMemberTranslator1<int, FAMTarget, void (FAMTarget::*)(FAMTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, FCMTarget, char *(FCMTarget::*)(FCMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031A9E0, Size: 120
void CBMemberTranslator1wRet<char *, char *, FCMTarget, char *(FCMTarget::*)(FCMTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, FCMTarget, void (FCMTarget::*)(FCMTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031AA58, Size: 120
void CBMemberTranslator2<char *, char *, FCMTarget, void (FCMTarget::*)(FCMTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, FCMTarget, unsigned wchar_t *(FCMTarget::*)(FCMTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031AAD0, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, FCMTarget, unsigned wchar_t *(FCMTarget::*)(FCMTarget *, char *)>(void) {
}

// CBMemberTranslator0<FCMTarget, void (FCMTarget::*)(FCMTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031AB48, Size: 120
void CBMemberTranslator0<FCMTarget, void (FCMTarget::*)(FCMTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, FCMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031ABC0, Size: 120
void CBMemberTranslator1<ERC *, FCMTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, G2DTarget, char *(G2DTarget::*)(G2DTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031AC84, Size: 120
void CBMemberTranslator1wRet<char *, char *, G2DTarget, char *(G2DTarget::*)(G2DTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, G2DTarget, void (G2DTarget::*)(G2DTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031ACFC, Size: 120
void CBMemberTranslator2<char *, char *, G2DTarget, void (G2DTarget::*)(G2DTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, G2DTarget, unsigned wchar_t *(G2DTarget::*)(G2DTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031AD74, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, G2DTarget, unsigned wchar_t *(G2DTarget::*)(G2DTarget *, char *)>(void) {
}

// CBMemberTranslator0<G2DTarget, void (G2DTarget::*)(G2DTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031ADEC, Size: 120
void CBMemberTranslator0<G2DTarget, void (G2DTarget::*)(G2DTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, G2DTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031AE64, Size: 120
void CBMemberTranslator1<ERC *, G2DTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, H2DTarget, char *(H2DTarget::*)(H2DTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031AEDC, Size: 120
void CBMemberTranslator1wRet<char *, char *, H2DTarget, char *(H2DTarget::*)(H2DTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, H2DTarget, void (H2DTarget::*)(H2DTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031AF54, Size: 120
void CBMemberTranslator2<char *, char *, H2DTarget, void (H2DTarget::*)(H2DTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, H2DTarget, unsigned wchar_t *(H2DTarget::*)(H2DTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031AFCC, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, H2DTarget, unsigned wchar_t *(H2DTarget::*)(H2DTarget *, char *)>(void) {
}

// CBMemberTranslator0<H2DTarget, void (H2DTarget::*)(H2DTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B044, Size: 120
void CBMemberTranslator0<H2DTarget, void (H2DTarget::*)(H2DTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, H2DTarget, void (H2DTarget::*)(H2DTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B0BC, Size: 120
void CBMemberTranslator1<ERC *, H2DTarget, void (H2DTarget::*)(H2DTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, INGTarget, char *(INGTarget::*)(INGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B134, Size: 120
void CBMemberTranslator1wRet<char *, char *, INGTarget, char *(INGTarget::*)(INGTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, INGTarget, void (INGTarget::*)(INGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B1AC, Size: 120
void CBMemberTranslator2<char *, char *, INGTarget, void (INGTarget::*)(INGTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, INGTarget, unsigned wchar_t *(INGTarget::*)(INGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B224, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, INGTarget, unsigned wchar_t *(INGTarget::*)(INGTarget *, char *)>(void) {
}

// CBMemberTranslator0<INGTarget, void (INGTarget::*)(INGTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B29C, Size: 120
void CBMemberTranslator0<INGTarget, void (INGTarget::*)(INGTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, INGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B314, Size: 120
void CBMemberTranslator1<ERC *, INGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, INGTarget, void (INGTarget::*)(INGTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031B38C, Size: 120
void CBMemberTranslator1<int, INGTarget, void (INGTarget::*)(INGTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, ITBTarget, char *(ITBTarget::*)(ITBTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B47C, Size: 120
void CBMemberTranslator1wRet<char *, char *, ITBTarget, char *(ITBTarget::*)(ITBTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, ITBTarget, void (ITBTarget::*)(ITBTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B4F4, Size: 120
void CBMemberTranslator2<char *, char *, ITBTarget, void (ITBTarget::*)(ITBTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, ITBTarget, unsigned wchar_t *(ITBTarget::*)(ITBTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B56C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, ITBTarget, unsigned wchar_t *(ITBTarget::*)(ITBTarget *, char *)>(void) {
}

// CBMemberTranslator0<ITBTarget, void (ITBTarget::*)(ITBTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031B5E4, Size: 120
void CBMemberTranslator0<ITBTarget, void (ITBTarget::*)(ITBTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, ITBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B65C, Size: 120
void CBMemberTranslator1<ERC *, ITBTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, K2YTarget, char *(K2YTarget::*)(K2YTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B6F4, Size: 120
void CBMemberTranslator1wRet<char *, char *, K2YTarget, char *(K2YTarget::*)(K2YTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, K2YTarget, void (K2YTarget::*)(K2YTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B76C, Size: 120
void CBMemberTranslator2<char *, char *, K2YTarget, void (K2YTarget::*)(K2YTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, K2YTarget, unsigned wchar_t *(K2YTarget::*)(K2YTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B7E4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, K2YTarget, unsigned wchar_t *(K2YTarget::*)(K2YTarget *, char *)>(void) {
}

// CBMemberTranslator0<K2YTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031B85C, Size: 120
void CBMemberTranslator0<K2YTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, K2YTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031B8D4, Size: 120
void CBMemberTranslator1<ERC *, K2YTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, M2MTarget, char *(M2MTarget::*)(M2MTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031B94C, Size: 120
void CBMemberTranslator1wRet<char *, char *, M2MTarget, char *(M2MTarget::*)(M2MTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, M2MTarget, void (M2MTarget::*)(M2MTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031B9C4, Size: 120
void CBMemberTranslator2<char *, char *, M2MTarget, void (M2MTarget::*)(M2MTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, M2MTarget, unsigned wchar_t *(M2MTarget::*)(M2MTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031BA3C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, M2MTarget, unsigned wchar_t *(M2MTarget::*)(M2MTarget *, char *)>(void) {
}

// CBMemberTranslator0<M2MTarget, void (M2MTarget::*)(M2MTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BAB4, Size: 120
void CBMemberTranslator0<M2MTarget, void (M2MTarget::*)(M2MTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, M2MTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031BB2C, Size: 120
void CBMemberTranslator1<ERC *, M2MTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, M2MTarget, void (M2MTarget::*)(M2MTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031BBA4, Size: 120
void CBMemberTranslator1<int, M2MTarget, void (M2MTarget::*)(M2MTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, MDITarget, char *(MDITarget::*)(MDITarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031BC1C, Size: 120
void CBMemberTranslator1wRet<char *, char *, MDITarget, char *(MDITarget::*)(MDITarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, MDITarget, void (MDITarget::*)(MDITarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031BC94, Size: 120
void CBMemberTranslator2<char *, char *, MDITarget, void (MDITarget::*)(MDITarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, MDITarget, unsigned wchar_t *(MDITarget::*)(MDITarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031BD0C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, MDITarget, unsigned wchar_t *(MDITarget::*)(MDITarget *, char *)>(void) {
}

// CBMemberTranslator0<MDITarget, void (MDITarget::*)(MDITarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BD84, Size: 120
void CBMemberTranslator0<MDITarget, void (MDITarget::*)(MDITarget *)>(void) {
}

// CBMemberTranslator1<ERC *, MDITarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031BDFC, Size: 120
void CBMemberTranslator1<ERC *, MDITarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, MMUTarget, char *(MMUTarget::*)(MMUTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031BE74, Size: 120
void CBMemberTranslator1wRet<char *, char *, MMUTarget, char *(MMUTarget::*)(MMUTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, MMUTarget, void (MMUTarget::*)(MMUTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031BEEC, Size: 120
void CBMemberTranslator2<char *, char *, MMUTarget, void (MMUTarget::*)(MMUTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, MMUTarget, unsigned wchar_t *(MMUTarget::*)(MMUTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031BF64, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, MMUTarget, unsigned wchar_t *(MMUTarget::*)(MMUTarget *, char *)>(void) {
}

// CBMemberTranslator0<MMUTarget, void (MMUTarget::*)(MMUTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031BFDC, Size: 120
void CBMemberTranslator0<MMUTarget, void (MMUTarget::*)(MMUTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, MMUTarget, void (MMUTarget::*)(MMUTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C054, Size: 120
void CBMemberTranslator1<ERC *, MMUTarget, void (MMUTarget::*)(MMUTarget *, ERC *)>(void) {
}

// CBMemberTranslator1<int, MMUTarget, void (MMUTarget::*)(MMUTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031C0CC, Size: 120
void CBMemberTranslator1<int, MMUTarget, void (MMUTarget::*)(MMUTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, MODTarget, char *(MODTarget::*)(MODTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C144, Size: 120
void CBMemberTranslator1wRet<char *, char *, MODTarget, char *(MODTarget::*)(MODTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, MODTarget, void (MODTarget::*)(MODTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C1BC, Size: 120
void CBMemberTranslator2<char *, char *, MODTarget, void (MODTarget::*)(MODTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, MODTarget, unsigned wchar_t *(MODTarget::*)(MODTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C234, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, MODTarget, unsigned wchar_t *(MODTarget::*)(MODTarget *, char *)>(void) {
}

// CBMemberTranslator0<MODTarget, void (MODTarget::*)(MODTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031C2AC, Size: 120
void CBMemberTranslator0<MODTarget, void (MODTarget::*)(MODTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, MODTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C324, Size: 120
void CBMemberTranslator1<ERC *, MODTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator2<ERC *, structDrawCBparams *, MODTarget, void (MODTarget::*)(MODTarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8031C39C, Size: 120
void CBMemberTranslator2<ERC *, structDrawCBparams *, MODTarget, void (MODTarget::*)(MODTarget *, ERC *, structDrawCBparams *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, MOTTarget, char *(MOTTarget::*)(MOTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C414, Size: 120
void CBMemberTranslator1wRet<char *, char *, MOTTarget, char *(MOTTarget::*)(MOTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, MOTTarget, void (MOTTarget::*)(MOTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C48C, Size: 120
void CBMemberTranslator2<char *, char *, MOTTarget, void (MOTTarget::*)(MOTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, MOTTarget, unsigned wchar_t *(MOTTarget::*)(MOTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C504, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, MOTTarget, unsigned wchar_t *(MOTTarget::*)(MOTTarget *, char *)>(void) {
}

// CBMemberTranslator0<MOTTarget, void (MOTTarget::*)(MOTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031C57C, Size: 120
void CBMemberTranslator0<MOTTarget, void (MOTTarget::*)(MOTTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, MOTTarget, void (MOTTarget::*)(MOTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C5F4, Size: 120
void CBMemberTranslator1<ERC *, MOTTarget, void (MOTTarget::*)(MOTTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, O2TTarget, char *(O2TTarget::*)(O2TTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C66C, Size: 120
void CBMemberTranslator1wRet<char *, char *, O2TTarget, char *(O2TTarget::*)(O2TTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, O2TTarget, void (O2TTarget::*)(O2TTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031C6E4, Size: 120
void CBMemberTranslator2<char *, char *, O2TTarget, void (O2TTarget::*)(O2TTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, O2TTarget, unsigned wchar_t *(O2TTarget::*)(O2TTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031C75C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, O2TTarget, unsigned wchar_t *(O2TTarget::*)(O2TTarget *, char *)>(void) {
}

// CBMemberTranslator0<O2TTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031C7D4, Size: 120
void CBMemberTranslator0<O2TTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, O2TTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031C84C, Size: 120
void CBMemberTranslator1<ERC *, O2TTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, HelpDialog, void (UIDialog::*)(UIDialog *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031C8C4, Size: 120
void CBMemberTranslator1<int, HelpDialog, void (UIDialog::*)(UIDialog *, int)>(void) {
}

// CBMemberTranslator1<int, O2TTarget, void (O2TTarget::*)(O2TTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031C93C, Size: 120
void CBMemberTranslator1<int, O2TTarget, void (O2TTarget::*)(O2TTarget *, int)>(void) {
}

// CBMemberTranslator0<O2TTarget, void (O2TTarget::*)(O2TTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031C9B4, Size: 120
void CBMemberTranslator0<O2TTarget, void (O2TTarget::*)(O2TTarget *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PAZTarget, char *(PAZBase::*)(PAZBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031CA44, Size: 120
void CBMemberTranslator1wRet<char *, char *, PAZTarget, char *(PAZBase::*)(PAZBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PAZTarget, void (PAZBase::*)(PAZBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031CABC, Size: 120
void CBMemberTranslator2<char *, char *, PAZTarget, void (PAZBase::*)(PAZBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PAZTarget, unsigned wchar_t *(PAZBase::*)(PAZBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031CB34, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PAZTarget, unsigned wchar_t *(PAZBase::*)(PAZBase *, char *)>(void) {
}

// CBMemberTranslator0<PAZTarget, void (PAZBase::*)(PAZBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031CBAC, Size: 120
void CBMemberTranslator0<PAZTarget, void (PAZBase::*)(PAZBase *)>(void) {
}

// CBMemberTranslator1<ERC *, PAZTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031CC24, Size: 120
void CBMemberTranslator1<ERC *, PAZTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PZ1Target, char *(PAZBase::*)(PAZBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031CC9C, Size: 120
void CBMemberTranslator1wRet<char *, char *, PZ1Target, char *(PAZBase::*)(PAZBase *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PZ1Target, void (PAZBase::*)(PAZBase *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031CD14, Size: 120
void CBMemberTranslator2<char *, char *, PZ1Target, void (PAZBase::*)(PAZBase *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PZ1Target, unsigned wchar_t *(PAZBase::*)(PAZBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031CD8C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PZ1Target, unsigned wchar_t *(PAZBase::*)(PAZBase *, char *)>(void) {
}

// CBMemberTranslator0<PZ1Target, void (PAZBase::*)(PAZBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031CE04, Size: 120
void CBMemberTranslator0<PZ1Target, void (PAZBase::*)(PAZBase *)>(void) {
}

// CBMemberTranslator1<ERC *, PZ1Target, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031CE7C, Size: 120
void CBMemberTranslator1<ERC *, PZ1Target, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PCTTarget, char *(PCTTarget::*)(PCTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031CFF8, Size: 120
void CBMemberTranslator1wRet<char *, char *, PCTTarget, char *(PCTTarget::*)(PCTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PCTTarget, void (PCTTarget::*)(PCTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D070, Size: 120
void CBMemberTranslator2<char *, char *, PCTTarget, void (PCTTarget::*)(PCTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PCTTarget, unsigned wchar_t *(PCTTarget::*)(PCTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D0E8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PCTTarget, unsigned wchar_t *(PCTTarget::*)(PCTTarget *, char *)>(void) {
}

// CBMemberTranslator0<PCTTarget, void (PCTTarget::*)(PCTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D160, Size: 120
void CBMemberTranslator0<PCTTarget, void (PCTTarget::*)(PCTTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, PCTTarget, void (PCTTarget::*)(PCTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D1D8, Size: 120
void CBMemberTranslator1<ERC *, PCTTarget, void (PCTTarget::*)(PCTTarget *, ERC *)>(void) {
}

// CBMemberTranslator1<int, PCTTarget, void (PCTTarget::*)(PCTTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031D250, Size: 120
void CBMemberTranslator1<int, PCTTarget, void (PCTTarget::*)(PCTTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PRGTarget, char *(PRGTarget::*)(PRGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D2C8, Size: 120
void CBMemberTranslator1wRet<char *, char *, PRGTarget, char *(PRGTarget::*)(PRGTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PRGTarget, void (PRGTarget::*)(PRGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D340, Size: 120
void CBMemberTranslator2<char *, char *, PRGTarget, void (PRGTarget::*)(PRGTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PRGTarget, unsigned wchar_t *(PRGTarget::*)(PRGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D3B8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PRGTarget, unsigned wchar_t *(PRGTarget::*)(PRGTarget *, char *)>(void) {
}

// CBMemberTranslator0<PRGTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8031D430, Size: 120
void CBMemberTranslator0<PRGTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, PRGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D4A8, Size: 120
void CBMemberTranslator1<ERC *, PRGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, R2LTarget, char *(R2LTarget::*)(R2LTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D520, Size: 120
void CBMemberTranslator1wRet<char *, char *, R2LTarget, char *(R2LTarget::*)(R2LTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, R2LTarget, void (R2LTarget::*)(R2LTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D598, Size: 120
void CBMemberTranslator2<char *, char *, R2LTarget, void (R2LTarget::*)(R2LTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, R2LTarget, unsigned wchar_t *(R2LTarget::*)(R2LTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D610, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, R2LTarget, unsigned wchar_t *(R2LTarget::*)(R2LTarget *, char *)>(void) {
}

// CBMemberTranslator0<R2LTarget, void (R2LTarget::*)(R2LTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D688, Size: 120
void CBMemberTranslator0<R2LTarget, void (R2LTarget::*)(R2LTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, R2LTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D700, Size: 120
void CBMemberTranslator1<ERC *, R2LTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1<int, R2LTarget, void (R2LTarget::*)(R2LTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8031D778, Size: 120
void CBMemberTranslator1<int, R2LTarget, void (R2LTarget::*)(R2LTarget *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, RCPTarget, char *(RCPTarget::*)(RCPTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D7F0, Size: 120
void CBMemberTranslator1wRet<char *, char *, RCPTarget, char *(RCPTarget::*)(RCPTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, RCPTarget, void (RCPTarget::*)(RCPTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031D868, Size: 120
void CBMemberTranslator2<char *, char *, RCPTarget, void (RCPTarget::*)(RCPTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, RCPTarget, unsigned wchar_t *(RCPTarget::*)(RCPTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031D8E0, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, RCPTarget, unsigned wchar_t *(RCPTarget::*)(RCPTarget *, char *)>(void) {
}

// CBMemberTranslator0<RCPTarget, void (RCPTarget::*)(RCPTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031D958, Size: 120
void CBMemberTranslator0<RCPTarget, void (RCPTarget::*)(RCPTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, RCPTarget, void (RCPTarget::*)(RCPTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031D9D0, Size: 120
void CBMemberTranslator1<ERC *, RCPTarget, void (RCPTarget::*)(RCPTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, RMDTarget, char *(RMDTarget::*)(RMDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DA48, Size: 120
void CBMemberTranslator1wRet<char *, char *, RMDTarget, char *(RMDTarget::*)(RMDTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, RMDTarget, void (RMDTarget::*)(RMDTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DAC0, Size: 120
void CBMemberTranslator2<char *, char *, RMDTarget, void (RMDTarget::*)(RMDTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, RMDTarget, unsigned wchar_t *(RMDTarget::*)(RMDTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DB38, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, RMDTarget, unsigned wchar_t *(RMDTarget::*)(RMDTarget *, char *)>(void) {
}

// CBMemberTranslator0<RMDTarget, void (RMDTarget::*)(RMDTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031DBB0, Size: 120
void CBMemberTranslator0<RMDTarget, void (RMDTarget::*)(RMDTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, RMDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031DC28, Size: 120
void CBMemberTranslator1<ERC *, RMDTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, SKLTarget, char *(SKLTarget::*)(SKLTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DCA0, Size: 120
void CBMemberTranslator1wRet<char *, char *, SKLTarget, char *(SKLTarget::*)(SKLTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, SKLTarget, void (SKLTarget::*)(SKLTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DD18, Size: 120
void CBMemberTranslator2<char *, char *, SKLTarget, void (SKLTarget::*)(SKLTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, SKLTarget, unsigned wchar_t *(SKLTarget::*)(SKLTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DD90, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, SKLTarget, unsigned wchar_t *(SKLTarget::*)(SKLTarget *, char *)>(void) {
}

// CBMemberTranslator0<SKLTarget, void (SKLTarget::*)(SKLTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031DE08, Size: 120
void CBMemberTranslator0<SKLTarget, void (SKLTarget::*)(SKLTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, SKLTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031DE80, Size: 120
void CBMemberTranslator1<ERC *, SKLTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, WAFTarget, char *(WAFTarget::*)(WAFTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DEF8, Size: 120
void CBMemberTranslator1wRet<char *, char *, WAFTarget, char *(WAFTarget::*)(WAFTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, WAFTarget, void (WAFTarget::*)(WAFTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031DF70, Size: 120
void CBMemberTranslator2<char *, char *, WAFTarget, void (WAFTarget::*)(WAFTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, WAFTarget, unsigned wchar_t *(WAFTarget::*)(WAFTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031DFE8, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, WAFTarget, unsigned wchar_t *(WAFTarget::*)(WAFTarget *, char *)>(void) {
}

// CBMemberTranslator0<WAFTarget, void (WAFTarget::*)(WAFTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031E060, Size: 120
void CBMemberTranslator0<WAFTarget, void (WAFTarget::*)(WAFTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, WAFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031E0D8, Size: 120
void CBMemberTranslator1<ERC *, WAFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, WXFTarget, char *(WXFTarget::*)(WXFTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031E150, Size: 120
void CBMemberTranslator1wRet<char *, char *, WXFTarget, char *(WXFTarget::*)(WXFTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, WXFTarget, void (WXFTarget::*)(WXFTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8031E1C8, Size: 120
void CBMemberTranslator2<char *, char *, WXFTarget, void (WXFTarget::*)(WXFTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, WXFTarget, unsigned wchar_t *(WXFTarget::*)(WXFTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8031E240, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, WXFTarget, unsigned wchar_t *(WXFTarget::*)(WXFTarget *, char *)>(void) {
}

// CBMemberTranslator0<WXFTarget, void (WXFTarget::*)(WXFTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8031E2B8, Size: 120
void CBMemberTranslator0<WXFTarget, void (WXFTarget::*)(WXFTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, WXFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8031E330, Size: 120
void CBMemberTranslator1<ERC *, WXFTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, EYETarget, char *(EYETarget::*)(EYETarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C334, Size: 120
void CBMemberTranslator1wRet<char *, char *, EYETarget, char *(EYETarget::*)(EYETarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, EYETarget, void (EYETarget::*)(EYETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C3AC, Size: 120
void CBMemberTranslator2<char *, char *, EYETarget, void (EYETarget::*)(EYETarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, EYETarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C424, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, EYETarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<EYETarget, void (EYETarget::*)(EYETarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034C49C, Size: 120
void CBMemberTranslator0<EYETarget, void (EYETarget::*)(EYETarget *)>(void) {
}

// CBMemberTranslator1<ERC *, EYETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034C514, Size: 120
void CBMemberTranslator1<ERC *, EYETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator2<ERC *, structDrawCBparams *, EYETarget, void (EYETarget::*)(EYETarget *, ERC *, structDrawCBparams *)>::thunk(CBFunctorBase &, ERC *, structDrawCBparams *)
// Address: 0x8034C58C, Size: 120
void CBMemberTranslator2<ERC *, structDrawCBparams *, EYETarget, void (EYETarget::*)(EYETarget *, ERC *, structDrawCBparams *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, FONTarget, char *(FONTarget::*)(FONTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C604, Size: 120
void CBMemberTranslator1wRet<char *, char *, FONTarget, char *(FONTarget::*)(FONTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, FONTarget, void (FONTarget::*)(FONTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C67C, Size: 120
void CBMemberTranslator2<char *, char *, FONTarget, void (FONTarget::*)(FONTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, FONTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C6F4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, FONTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<FONTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034C76C, Size: 120
void CBMemberTranslator0<FONTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, FONTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034C7E4, Size: 120
void CBMemberTranslator1<ERC *, FONTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, GOLTarget, char *(GOLTarget::*)(GOLTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C85C, Size: 120
void CBMemberTranslator1wRet<char *, char *, GOLTarget, char *(GOLTarget::*)(GOLTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, GOLTarget, void (GOLTarget::*)(GOLTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034C8D4, Size: 120
void CBMemberTranslator2<char *, char *, GOLTarget, void (GOLTarget::*)(GOLTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, GOLTarget, unsigned wchar_t *(GOLTarget::*)(GOLTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034C94C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, GOLTarget, unsigned wchar_t *(GOLTarget::*)(GOLTarget *, char *)>(void) {
}

// CBMemberTranslator0<GOLTarget, void (GOLTarget::*)(GOLTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034C9C4, Size: 120
void CBMemberTranslator0<GOLTarget, void (GOLTarget::*)(GOLTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, GOLTarget, void (GOLTarget::*)(GOLTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034CA3C, Size: 120
void CBMemberTranslator1<ERC *, GOLTarget, void (GOLTarget::*)(GOLTarget *, ERC *)>(void) {
}

// CBMemberTranslator1<int, INVTarget, void (INVTarget::*)(INVTarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034CBEC, Size: 120
void CBMemberTranslator1<int, INVTarget, void (INVTarget::*)(INVTarget *, int)>(void) {
}

// CBMemberTranslator0<INVTarget, void (INVTarget::*)(INVTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034CC64, Size: 120
void CBMemberTranslator0<INVTarget, void (INVTarget::*)(INVTarget *)>(void) {
}

// CBMemberTranslator1<int, UIDialog, void (UIDialog::*)(UIDialog *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034CD54, Size: 120
void CBMemberTranslator1<int, UIDialog, void (UIDialog::*)(UIDialog *, int)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, INVTarget, char *(INVTarget::*)(INVTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034CDCC, Size: 120
void CBMemberTranslator1wRet<char *, char *, INVTarget, char *(INVTarget::*)(INVTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, INVTarget, void (INVTarget::*)(INVTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034CE44, Size: 120
void CBMemberTranslator2<char *, char *, INVTarget, void (INVTarget::*)(INVTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, INVTarget, unsigned wchar_t *(INVTarget::*)(INVTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034CEBC, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, INVTarget, unsigned wchar_t *(INVTarget::*)(INVTarget *, char *)>(void) {
}

// CBMemberTranslator1<ERC *, INVTarget, void (INVTarget::*)(INVTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034CF34, Size: 120
void CBMemberTranslator1<ERC *, INVTarget, void (INVTarget::*)(INVTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, INTTarget, char *(INTTarget::*)(INTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034CFEC, Size: 120
void CBMemberTranslator1wRet<char *, char *, INTTarget, char *(INTTarget::*)(INTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, INTTarget, void (INTTarget::*)(INTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D064, Size: 120
void CBMemberTranslator2<char *, char *, INTTarget, void (INTTarget::*)(INTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, INTTarget, unsigned wchar_t *(INTTarget::*)(INTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D0DC, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, INTTarget, unsigned wchar_t *(INTTarget::*)(INTTarget *, char *)>(void) {
}

// CBMemberTranslator0<INTTarget, void (INTTarget::*)(INTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034D154, Size: 120
void CBMemberTranslator0<INTTarget, void (INTTarget::*)(INTTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, INTTarget, void (INTTarget::*)(INTTarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D1CC, Size: 120
void CBMemberTranslator1<ERC *, INTTarget, void (INTTarget::*)(INTTarget *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, KEYTarget, char *(KEYTarget::*)(KEYTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D244, Size: 120
void CBMemberTranslator1wRet<char *, char *, KEYTarget, char *(KEYTarget::*)(KEYTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, KEYTarget, void (KEYTarget::*)(KEYTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D2BC, Size: 120
void CBMemberTranslator2<char *, char *, KEYTarget, void (KEYTarget::*)(KEYTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, KEYTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D334, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, KEYTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<KEYTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034D3AC, Size: 120
void CBMemberTranslator0<KEYTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, KEYTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D424, Size: 120
void CBMemberTranslator1<ERC *, KEYTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, MSGTarget, char *(MSGTarget::*)(MSGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D49C, Size: 120
void CBMemberTranslator1wRet<char *, char *, MSGTarget, char *(MSGTarget::*)(MSGTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, MSGTarget, void (MSGTarget::*)(MSGTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D514, Size: 120
void CBMemberTranslator2<char *, char *, MSGTarget, void (MSGTarget::*)(MSGTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, MSGTarget, unsigned wchar_t *(MSGTarget::*)(MSGTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D58C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, MSGTarget, unsigned wchar_t *(MSGTarget::*)(MSGTarget *, char *)>(void) {
}

// CBMemberTranslator0<MSGTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034D604, Size: 120
void CBMemberTranslator0<MSGTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, MSGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D67C, Size: 120
void CBMemberTranslator1<ERC *, MSGTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, OPTTarget, char *(OPTTarget::*)(OPTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D6F4, Size: 120
void CBMemberTranslator1wRet<char *, char *, OPTTarget, char *(OPTTarget::*)(OPTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, OPTTarget, void (OPTTarget::*)(OPTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D76C, Size: 120
void CBMemberTranslator2<char *, char *, OPTTarget, void (OPTTarget::*)(OPTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, OPTTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D7E4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, OPTTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<OPTTarget, void (OPTTarget::*)(OPTTarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034D85C, Size: 120
void CBMemberTranslator0<OPTTarget, void (OPTTarget::*)(OPTTarget *)>(void) {
}

// CBMemberTranslator1<ERC *, OPTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034D8D4, Size: 120
void CBMemberTranslator1<ERC *, OPTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PDATarget, char *(PDATarget::*)(PDATarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034D94C, Size: 120
void CBMemberTranslator1wRet<char *, char *, PDATarget, char *(PDATarget::*)(PDATarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PDATarget, void (PDATarget::*)(PDATarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034D9C4, Size: 120
void CBMemberTranslator2<char *, char *, PDATarget, void (PDATarget::*)(PDATarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PDATarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034DA3C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PDATarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<PDATarget, void (PDATarget::*)(PDATarget *)>::thunk(CBFunctorBase &)
// Address: 0x8034DAB4, Size: 120
void CBMemberTranslator0<PDATarget, void (PDATarget::*)(PDATarget *)>(void) {
}

// CBMemberTranslator1<ERC *, PDATarget, void (PDATarget::*)(PDATarget *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034DB2C, Size: 120
void CBMemberTranslator1<ERC *, PDATarget, void (PDATarget::*)(PDATarget *, ERC *)>(void) {
}

// CBMemberTranslator1<int, PDATarget, void (PDATarget::*)(PDATarget *, int)>::thunk(CBFunctorBase &, int)
// Address: 0x8034DBA4, Size: 120
void CBMemberTranslator1<int, PDATarget, void (PDATarget::*)(PDATarget *, int)>(void) {
}

// CBMemberTranslator0<PDATarget, void (UIDialog::*)(UIDialog *)>::thunk(CBFunctorBase &)
// Address: 0x8034DC1C, Size: 144
void CBMemberTranslator0<PDATarget, void (UIDialog::*)(UIDialog *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, PSETarget, char *(PSETarget::*)(PSETarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034DCAC, Size: 120
void CBMemberTranslator1wRet<char *, char *, PSETarget, char *(PSETarget::*)(PSETarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, PSETarget, void (PSETarget::*)(PSETarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034DD24, Size: 120
void CBMemberTranslator2<char *, char *, PSETarget, void (PSETarget::*)(PSETarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, PSETarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034DD9C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, PSETarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<PSETarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034DE14, Size: 120
void CBMemberTranslator0<PSETarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, PSETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034DE8C, Size: 120
void CBMemberTranslator1<ERC *, PSETarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, RELTarget, char *(RELTarget::*)(RELTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034DF04, Size: 120
void CBMemberTranslator1wRet<char *, char *, RELTarget, char *(RELTarget::*)(RELTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, RELTarget, void (RELTarget::*)(RELTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034DF7C, Size: 120
void CBMemberTranslator2<char *, char *, RELTarget, void (RELTarget::*)(RELTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, RELTarget, unsigned wchar_t *(RELTarget::*)(RELTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034DFF4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, RELTarget, unsigned wchar_t *(RELTarget::*)(RELTarget *, char *)>(void) {
}

// CBMemberTranslator0<RELTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E06C, Size: 120
void CBMemberTranslator0<RELTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, RELTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E0E4, Size: 120
void CBMemberTranslator1<ERC *, RELTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, RGTTarget, char *(RGTTarget::*)(RGTTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034E15C, Size: 120
void CBMemberTranslator1wRet<char *, char *, RGTTarget, char *(RGTTarget::*)(RGTTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, RGTTarget, void (RGTTarget::*)(RGTTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034E1D4, Size: 120
void CBMemberTranslator2<char *, char *, RGTTarget, void (RGTTarget::*)(RGTTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, RGTTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034E24C, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, RGTTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<RGTTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E2C4, Size: 120
void CBMemberTranslator0<RGTTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, RGTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E33C, Size: 120
void CBMemberTranslator1<ERC *, RGTTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// CBMemberTranslator1wRet<char *, char *, SKNTarget, char *(SKNTarget::*)(SKNTarget *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034E3B4, Size: 120
void CBMemberTranslator1wRet<char *, char *, SKNTarget, char *(SKNTarget::*)(SKNTarget *, char *)>(void) {
}

// CBMemberTranslator2<char *, char *, SKNTarget, void (SKNTarget::*)(SKNTarget *, char *, char *)>::thunk(CBFunctorBase &, char *, char *)
// Address: 0x8034E42C, Size: 120
void CBMemberTranslator2<char *, char *, SKNTarget, void (SKNTarget::*)(SKNTarget *, char *, char *)>(void) {
}

// CBMemberTranslator1wRet<char *, unsigned wchar_t *, SKNTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>::thunk(CBFunctorBase &, char *)
// Address: 0x8034E4A4, Size: 120
void CBMemberTranslator1wRet<char *, unsigned wchar_t *, SKNTarget, unsigned wchar_t *(UIObjectBase::*)(UIObjectBase *, char *)>(void) {
}

// CBMemberTranslator0<SKNTarget, void (UIObjectBase::*)(UIObjectBase *)>::thunk(CBFunctorBase &)
// Address: 0x8034E51C, Size: 120
void CBMemberTranslator0<SKNTarget, void (UIObjectBase::*)(UIObjectBase *)>(void) {
}

// CBMemberTranslator1<ERC *, SKNTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>::thunk(CBFunctorBase &, ERC *)
// Address: 0x8034E594, Size: 120
void CBMemberTranslator1<ERC *, SKNTarget, void (UIObjectBase::*)(UIObjectBase *, ERC *)>(void) {
}

// unsigned int * find<unsigned int *, unsigned int>(unsigned int *, unsigned int *, unsigned int &)
// Address: 0x80362FDC, Size: 176
unsigned int * find<unsigned int *, unsigned int>(void) {
    return 0;
}

// CTilePt * find<CTilePt *, CTilePt>(CTilePt *, CTilePt *, CTilePt &)
// Address: 0x803878C8, Size: 300
CTilePt * find<CTilePt *, CTilePt>(void) {
    return 0;
}

// EInstance ** find<EInstance **, EInstance *>(EInstance **, EInstance **, EInstance * &)
// Address: 0x803A9588, Size: 176
EInstance ** find<EInstance **, EInstance *>(void) {
    return 0;
}

// unsigned int CopyTArray<BSplineVolume, TArrayERModelAllocator>(TArray<BSplineVolume, TArrayERModelAllocator> &, char *)
// Address: 0x804E64A8, Size: 180
unsigned int CopyTArray<BSplineVolume, TArrayERModelAllocator>(void) {
    return 0;
}

// unsigned int CopyTArray<ENDummy, TArrayERModelAllocator>(TArray<ENDummy, TArrayERModelAllocator> &, char *)
// Address: 0x804E67AC, Size: 180
unsigned int CopyTArray<ENDummy, TArrayERModelAllocator>(void) {
    return 0;
}

// unsigned int CopyTArray<ENCamera, TArrayERModelAllocator>(TArray<ENCamera, TArrayERModelAllocator> &, char *)
// Address: 0x804E6AB0, Size: 180
unsigned int CopyTArray<ENCamera, TArrayERModelAllocator>(void) {
    return 0;
}

// unsigned int CopyTArray<SimsLightInfo, TArrayERModelAllocator>(TArray<SimsLightInfo, TArrayERModelAllocator> &, char *)
// Address: 0x804E6CFC, Size: 160
unsigned int CopyTArray<SimsLightInfo, TArrayERModelAllocator>(void) {
    return 0;
}
