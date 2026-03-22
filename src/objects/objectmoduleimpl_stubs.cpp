// objectmoduleimpl_stubs.cpp - Stub implementations for ObjectModuleImpl class methods
// Auto-generated from symbols.json - 63 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.
//
// Class: ObjectModuleImpl

#include "types.h"

// Forward declarations
class CTilePt;
class HouseStats;
class Neighbor;
class ObjSelector;
class ReconBuffer;
class RoomManager;
class cXMTObject;
class cXObject;
class cXObjectImpl;
class cXPerson;
class cXPersonImpl;
class iResFile;

// ======================================================================
// ObjectModuleImpl
// ======================================================================

// 0x801963F8 | 272 bytes
ObjectModuleImpl::ObjectModuleImpl(void) {
}

// 0x80196508 | 520 bytes
ObjectModuleImpl::~ObjectModuleImpl(void) {
}

// 0x80196710 | 228 bytes
void ObjectModuleImpl::Save(iResFile *) {
}

// 0x801967F8 | 1668 bytes
void ObjectModuleImpl::Load(iResFile *) {
}

// 0x80196E7C | 916 bytes
void ObjectModuleImpl::killDemolishedObjects(iResFile *) {
}

// 0x80197210 | 128 bytes
void ObjectModuleImpl::PostLoad(iResFile *, int, bool) {
}

// 0x80197290 | 276 bytes
void ObjectModuleImpl::SelectPlayerSims(void) {
}

// 0x801973A4 | 212 bytes
void ObjectModuleImpl::DoReconObject(ReconBuffer *, cXObjectImpl **) {
}

// 0x80197478 | 236 bytes
void ObjectModuleImpl::DoReconPerson(ReconBuffer *, cXPersonImpl **) {
}

// 0x80197568 | 2624 bytes
void ObjectModuleImpl::DoStream(ReconBuffer *, int) {
}

// 0x80197FA8 | 116 bytes
void ObjectModuleImpl::Init(void) {
}

// 0x8019801C | 164 bytes
void ObjectModuleImpl::LoadGlobalRoutingSlots(void) {
}

// 0x801980C0 | 568 bytes
void ObjectModuleImpl::Destroy(void) {
}

// 0x801982F8 | 284 bytes
void ObjectModuleImpl::GetObjectByGUID(int) {
}

// 0x80198414 | 156 bytes
void ObjectModuleImpl::GetPersonByGUID(int) {
}

// 0x801984B0 | 356 bytes
void ObjectModuleImpl::ConstructObject(ObjSelector *, cXMTObject *) {
}

// 0x80198614 | 1700 bytes
void ObjectModuleImpl::MakeNewOutOfWorldObject(ObjSelector *, short *) {
}

// 0x80198CB8 | 1736 bytes
void ObjectModuleImpl::KillOutOfWorldObject(short, bool) {
}

// 0x80199380 | 572 bytes
void ObjectModuleImpl::KillObject(short) {
}

// 0x801995BC | 332 bytes
void ObjectModuleImpl::KillQueueFlush(void) {
}

// 0x80199708 | 228 bytes
void ObjectModuleImpl::PostSim(bool) {
}

// 0x801997EC | 120 bytes
void ObjectModuleImpl::DayChanged(void) {
}

// 0x80199864 | 704 bytes
void ObjectModuleImpl::UpdateRooms(int) {
}

// 0x80199B24 | 168 bytes
void ObjectModuleImpl::UpdateInteractionInfluences(void) {
}

// 0x80199BCC | 596 bytes
void ObjectModuleImpl::KillAllObjects(void) {
}

// 0x80199E20 | 528 bytes
void ObjectModuleImpl::KillObjectsOutsideBounds(int, int, int, int) {
}

// 0x8019A030 | 1016 bytes
void ObjectModuleImpl::UpdateSimObjects(void) {
}

// 0x8019A428 | 944 bytes
void ObjectModuleImpl::AddToKillQueue(short, bool) {
}

// 0x8019A7E4 | 248 bytes
void ObjectModuleImpl::IsFamilyMemberAwakeAndVisible(void) {
}

// 0x8019A8DC | 404 bytes
void ObjectModuleImpl::DoCommand(short, int) {
}

// 0x8019AA70 | 404 bytes
void ObjectModuleImpl::PreviewAnimation(short, short, short, bool) {
}

// 0x8019AC04 | 116 bytes
void ObjectModuleImpl::ForceAllLocations(void) {
}

// 0x8019AC78 | 916 bytes
void ObjectModuleImpl::GetAnObjectID(short) {
}

// 0x8019BA1C | 876 bytes
void ObjectModuleImpl::RemoveObject(cXObject *) {
}

// 0x8019BD88 | 456 bytes
void ObjectModuleImpl::DisableBuyAndBuild(cXObject *) {
}

// 0x8019BF50 | 244 bytes
void ObjectModuleImpl::EnableBuyAndBuild(cXObject *) {
}

// 0x8019C044 | 592 bytes
void ObjectModuleImpl::CheckIntegrity(void) {
}

// 0x8019C294 | 156 bytes
void ObjectModuleImpl::ClearAwarenessOfObject(cXObject *) {
}

// 0x8019C330 | 172 bytes
void ObjectModuleImpl::CleanupPeople(cXObject *) {
}

// 0x8019C3E4 | 180 bytes
void ObjectModuleImpl::BroadcastMessage(char *, int) {
}

// 0x8019C498 | 200 bytes
void ObjectModuleImpl::SendMessage(cXObject *, char *, int) {
}

// 0x8019C560 | 148 bytes
void ObjectModuleImpl::UpdateWallAdjacencies(void) {
}

// 0x8019C5F4 | 120 bytes
void ObjectModuleImpl::InvalidateAllRoutes(void) {
}

// 0x8019C6F4 | 288 bytes
void ObjectModuleImpl::OffsetObjectMap(CTilePt &) {
}

// 0x8019C814 | 1568 bytes
void ObjectModuleImpl::OffsetWorld(CTilePt &) {
}

// 0x8019CE4C | 140 bytes
void ObjectModuleImpl::SetTutorialObject(cXObject *) {
}

// 0x8019CED8 | 76 bytes
void ObjectModuleImpl::ShowTutorialInfo(void) {
}

// 0x8019CF24 | 932 bytes
void ObjectModuleImpl::ComputeStats(int *, int *, bool *, bool *, bool *) {
}

// 0x8019D2C8 | 424 bytes
void ObjectModuleImpl::FillInObjectStats(RoomManager *, HouseStats &) {
}

// 0x8019D470 | 128 bytes
void ObjectModuleImpl::IsSelectionSwitchingAllowed(void) {
}

// 0x8019D4F0 | 116 bytes
void ObjectModuleImpl::IsValidObject(cXObject *) {
}

// 0x8019D564 | 176 bytes
void ObjectModuleImpl::IsValidPerson(cXPerson *) {
}

// 0x8019D660 | 248 bytes
void ObjectModuleImpl::ClearIdleStatus(int) {
}

// 0x8019D800 | 72 bytes
void ObjectModuleImpl::GetObjectFromID(int) {
}

// 0x8019D848 | 1012 bytes
void ObjectModuleImpl::Dump(void) {
}

// 0x8019DC3C | 220 bytes
void ObjectModuleImpl::GetTileObjectID(CTilePt &) {
}

// 0x8019DD18 | 280 bytes
void ObjectModuleImpl::SetTileObjectID(CTilePt &, short) {
}

// 0x8019DE30 | 220 bytes
void ObjectModuleImpl::CreateNeighbor(Neighbor *) {
}

// 0x8019DF0C | 188 bytes
void ObjectModuleImpl::GetObject(int) {
}

// 0x8019E008 | 200 bytes
void ObjectModuleImpl::GetNextPerson(unsigned short) {
}

// 0x802022F0 | 116 bytes
void ObjectModuleImpl::GetSimMemory(int, int, int) {
}

// 0x80202364 | 284 bytes
void ObjectModuleImpl::SetSimMemory(int, int, int, int) {
}

// 0x80202480 | 160 bytes
void ObjectModuleImpl::GetDominantMemory(int, int, int) {
}
