// objectfolderimpl_stubs.cpp - Stub implementations for Objectfolderimpl
// Auto-generated from symbols.json - 56 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x8018CCD0 | 456 bytes
ObjectFolderImpl::ObjectFolderImpl(void) { }

// 0x8018CE98 | 592 bytes
ObjectFolderImpl::~ObjectFolderImpl(void) { }

// 0x8018D0E8 | 72 bytes
void ObjectFolderImpl::CountSelectors(void) { }

// 0x8018D130 | 136 bytes
void ObjectFolderImpl::GetSelectorByGUID(int) { }

// 0x8018D1B8 | 460 bytes
void ObjectFolderImpl::GetNextSelector(ObjSelector *) { }

// 0x8018D384 | 208 bytes
void ObjectFolderImpl::GetSubTileSelector(ObjSelector *, int, int, int) { }

// 0x8018D454 | 208 bytes
void ObjectFolderImpl::GetLeadSelector(ObjSelector *) { }

// 0x8018D524 | 204 bytes
void ObjectFolderImpl::GetNthSubSelector(ObjSelector *, int) { }

// 0x8018D5F0 | 132 bytes
void ObjectFolderImpl::GetQueueShaderByGUID(int) { }

// 0x8018D674 | 256 bytes
void ObjectFolderImpl::GetMasterSelector(ObjSelector *) { }

// 0x8018D774 | 288 bytes
void ObjectFolderImpl::Init(char *, bool) { }

// 0x8018D894 | 1344 bytes
void ObjectFolderImpl::Destroy(void) { }

// 0x8018DDD4 | 676 bytes
void ObjectFolderImpl::DestroySelector(ObjSelector *) { }

// 0x8018E078 | 924 bytes
void ObjectFolderImpl::AddUserSelector(int, short) { }

// 0x8018E414 | 248 bytes
void ObjectFolderImpl::GetSemiGlobalID(unsigned int) { }

// 0x8018E50C | 1140 bytes
void ObjectFolderImpl::AddSelector(ObjDefinition *, char *, char *, ResFile *, short, Sim::NPC *) { }

// 0x8018E980 | 472 bytes
void ObjectFolderImpl::OpenResFile(ObjSelector *) { }

// 0x8018EB58 | 164 bytes
void ObjectFolderImpl::CloseResFile(ObjSelector *) { }

// 0x8018EC00 | 2788 bytes
void ObjectFolderImpl::LoadDatabase(void) { }

// 0x8018F6E4 | 520 bytes
void ObjectFolderImpl::ReconSelector(ObjSelector **, ReconBuffer *, bool, int) { }

// 0x8018F8EC | 460 bytes
void ObjectFolderImpl::GetSelectorByBehavior(Behavior *) { }

// 0x8018FAB8 | 596 bytes
void ObjectFolderImpl::ReconBehavior(Behavior **, ReconBuffer *, int) { }

// 0x8018FD0C | 492 bytes
void ObjectFolderImpl::GetPersonGlobNamespaceID(void) { }

// 0x8018FEF8 | 456 bytes
void ObjectFolderImpl::GetFileByID(unsigned int) { }

// 0x801900C0 | 604 bytes
void ObjectFolderImpl::LoadUserData(iResFile *) { }

// 0x801904B0 | 1344 bytes
void ObjectFolderImpl::SaveUserData(iResFile *) { }

// 0x801909F0 | 96 bytes
void ObjectFolderImpl::CreateNewUserSelector(void) { }

// 0x80190A50 | 472 bytes
void ObjectFolderImpl::RemoveSelector(ObjSelector *) { }

// 0x80190C28 | 300 bytes
void ObjectFolderImpl::ForceDataPreload(ObjSelector *, bool) { }

// 0x80190D54 | 180 bytes
void ObjectFolderImpl::forceDataPreload(ObjSelector *, bool) { }

// 0x80190E08 | 112 bytes
void ObjectFolderImpl::CreatingInstance(ObjSelector *) { }

// 0x80190F10 | 1560 bytes
void ObjectFolderImpl::PrepareForModuleLoad(iResFile *) { }

// 0x80191528 | 1184 bytes
void ObjectFolderImpl::PrepareForModuleSave(iResFile *) { }

// 0x80191A04 | 680 bytes
void ObjectFolderImpl::FreeUnusedData(void) { }

// 0x80191CAC | 1132 bytes
void ObjectFolderImpl::DeleteUserSelectors(void) { }

// 0x80192118 | 488 bytes
void ObjectFolderImpl::DeleteSelectorAnimLists(void) { }

// 0x80192300 | 328 bytes
void ObjectFolderImpl::UnloadData(ObjSelector *) { }

// 0x801924E0 | 684 bytes
void ObjectFolderImpl::DoStream(ReconBuffer *, int) { }

// 0x8019278C | 168 bytes
void ObjectFolderImpl::GetRumbleByName(char *) { }

// 0x80192834 | 168 bytes
void ObjectFolderImpl::GetCameraBloomByName(char *) { }

// 0x801928DC | 168 bytes
void ObjectFolderImpl::GetCameraBlurByName(char *) { }

// 0x80192A28 | 316 bytes
void ObjectFolderImpl::GetAnimPreloadList(ChecksumList &) { }

// 0x80192B74 | 872 bytes
void ObjectFolderImpl::GetTreeTable(ObjSelector *) { }

// 0x80192EDC | 340 bytes
void ObjectFolderImpl::LoadResourceByIndex(unsigned int, short, ObjectDataInterface &, unsigned int, unsigned int) { }

// 0x80193030 | 104 bytes
void ObjectFolderImpl::LoadResourceByID(unsigned int, short, ObjectDataInterface &, unsigned int) { }

// 0x80193098 | 68 bytes
void ObjectFolderImpl::SaveResource(unsigned int, short, StringBuffer &, ObjectDataInterface &) { }

// 0x801930DC | 116 bytes
void ObjectFolderImpl::GetResourceCount(unsigned int, unsigned int, unsigned int) { }

// 0x80193150 | 356 bytes
void ObjectFolderImpl::RemoveResourceByID(unsigned int, short, unsigned int) { }

// 0x801932B4 | 368 bytes
void ObjectFolderImpl::ChangeResourceID(unsigned int, short, short, unsigned int) { }

// 0x80193424 | 132 bytes
void ObjectFolderImpl::GetNamespaceName(unsigned int, StringBuffer &) { }

// 0x801934A8 | 132 bytes
void ObjectFolderImpl::FindUniqueResourceName(unsigned int, unsigned int, StringBuffer &) { }

// 0x8019352C | 132 bytes
void ObjectFolderImpl::FindUniqueResourceID(unsigned int, unsigned int, short &) { }

// 0x801935C0 | 212 bytes
void ObjectFolderImpl::GetStringFromNamespaceID(unsigned int, StringBuffer &, short, short) { }

// 0x80193694 | 580 bytes
void ObjectFolderImpl::ClearAllCaches(void) { }

// 0x801939BC | 1248 bytes
void ObjectFolderImpl::GetNamespaceSelector(unsigned int) { }

// 0x80193E9C | 100 bytes
void ObjectFolderImpl::FlushNamespaceCaches(void) { }
