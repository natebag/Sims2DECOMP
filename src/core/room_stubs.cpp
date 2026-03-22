// room_stubs.cpp - Stub implementations for Room
// Auto-generated from symbols.json - 16 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x801F6708 | 180 bytes
Room::Room(unsigned short, RoomManager *) { }

// 0x801F67BC | 372 bytes
Room::~Room(void) { }

// 0x801F6930 | 148 bytes
void Room::Clear(void) { }

// 0x801F69C4 | 88 bytes
void Room::GetPartition(void) { }

// 0x801F6A1C | 896 bytes
void Room::ComputeRoom(void) { }

// 0x801F6E24 | 612 bytes
void Room::CollectTileStats(CTilePt &) { }

// 0x801F7088 | 1048 bytes
void Room::CollectObjectStats(ObjectIterator) { }

// 0x801F74A0 | 164 bytes
void Room::PrintStats(void) { }

// 0x801F7544 | 88 bytes
void Room::GetObjectDensity(void) { }

// 0x801F75B0 | 168 bytes
void Room::AbsorbNewRoomList(vector<CTilePt, allocator<CTilePt> > &) { }

// 0x801F7658 | 108 bytes
void Room::IsTileInRoom(CTilePt &) { }

// 0x801F76C4 | 528 bytes
void Room::IsOutside(void) { }

// 0x801F78D4 | 128 bytes
void Room::SetOverheadLights(bool) { }

// 0x801F7954 | 208 bytes
void Room::GetPeopleCount(void) { }

// 0x801F7A24 | 80 bytes
void Room::GetAmbientLight(void) const { }

// 0x801F7AA4 | 328 bytes
void Room::GetAmbientLightMultiplier(void) { }
