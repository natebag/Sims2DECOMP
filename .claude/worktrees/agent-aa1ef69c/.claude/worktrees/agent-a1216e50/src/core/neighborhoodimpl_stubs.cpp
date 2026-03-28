// neighborhoodimpl_stubs.cpp - Stub implementations for Neighborhoodimpl
// Auto-generated from symbols.json - 34 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8016205C | 296 bytes
NeighborhoodImpl::~NeighborhoodImpl(void) { }

// 0x801622F0 | 300 bytes
void NeighborhoodImpl::Unload(void) { }

// 0x8016241C | 2244 bytes
void NeighborhoodImpl::Load(NghResFile *) { }

// 0x80162CE0 | 500 bytes
void NeighborhoodImpl::UpdateFamilyNumbers(void) { }

// 0x80162ED4 | 764 bytes
void NeighborhoodImpl::Save(NghResFile *, int) { }

// 0x801631D0 | 404 bytes
void NeighborhoodImpl::DoStream(ReconBuffer *, int) { }

// 0x801636F0 | 496 bytes
void NeighborhoodImpl::AddNewNeighbor(ObjSelector *) { }

// 0x801638E0 | 480 bytes
void NeighborhoodImpl::LoadPersistentData(cXPerson *) { }

// 0x80163C88 | 408 bytes
void NeighborhoodImpl::SavePersistentData(cXPerson *) { }

// 0x80163F2C | 880 bytes
void NeighborhoodImpl::GetNeighborData(short, short, short **) { }

// 0x80164598 | 796 bytes
void NeighborhoodImpl::BaseMakeNewFamily(bool, int) { }

// 0x801649D8 | 568 bytes
void NeighborhoodImpl::AddToFamily(Neighbor *, Family *) { }

// 0x80164C10 | 340 bytes
void NeighborhoodImpl::RemoveFromFamily(Neighbor *) { }

// 0x80164D64 | 444 bytes
void NeighborhoodImpl::AddAsPlayerRoommate(Neighbor *) { }

// 0x80164F20 | 544 bytes
void NeighborhoodImpl::RemovePlayerRoommate(void) { }

// 0x80165140 | 248 bytes
void NeighborhoodImpl::AddNewCharacter(Neighbor **) { }

// 0x80165238 | 564 bytes
void NeighborhoodImpl::DeleteCharacter(Neighbor *) { }

// 0x8016546C | 112 bytes
void NeighborhoodImpl::GetNumCharacters(void) { }

// 0x80165518 | 316 bytes
void NeighborhoodImpl::GetFamilyNetWorth(Family *) { }

// 0x80165794 | 1772 bytes
void NeighborhoodImpl::MoveOut(NghResFile *, int, bool) { }

// 0x80165E80 | 332 bytes
void NeighborhoodImpl::UpdateFamilyFriendsCount(Family *) { }

// 0x80165FCC | 268 bytes
void NeighborhoodImpl::PrepareAndTestLot(StringBuffer &) { }

// 0x801660D8 | 188 bytes
void NeighborhoodImpl::GetHousePrice(cSimulator *) { }

// 0x801662F4 | 216 bytes
void NeighborhoodImpl::GetHouseInfo(NghResFile *, int, HouseInfo *) { }

// 0x80166414 | 332 bytes
void NeighborhoodImpl::GetHouseFileInfo(NghResFile *, int *, bool *, bool *, bool *) { }

// 0x80166560 | 232 bytes
void NeighborhoodImpl::compareHouses(int &, int &) { }

// 0x80166648 | 3392 bytes
void NeighborhoodImpl::LoadHouse(NghResFile *, int, bool) { }

// 0x80167388 | 388 bytes
void NeighborhoodImpl::SaveHouse(NghResFile *) { }

// 0x801675A8 | 204 bytes
void NeighborhoodImpl::DumpState(void) { }

// 0x80167674 | 244 bytes
void NeighborhoodImpl::UpdateInstanceVisitorTypes(void) { }

// 0x80167768 | 152 bytes
void NeighborhoodImpl::NotifyAllNeighbors(int &, Neighbor *) { }

// 0x80167800 | 324 bytes
void NeighborhoodImpl::NotifyAllResidents(int &, Neighbor *) { }

// 0x80167944 | 380 bytes
void NeighborhoodImpl::NotifyAllPersons(int &, Neighbor *) { }

// 0x8016A7D4 | 72 bytes
void NeighborhoodImpl::GetPlayerVisitingAnotherHouse(void) const { }
