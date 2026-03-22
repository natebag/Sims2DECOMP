// cfixedworldimpl_stubs.cpp - Stub implementations for Cfixedworldimpl
// Auto-generated from symbols.json - 29 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x80215314 | 228 bytes
cFixedWorldImpl::cFixedWorldImpl(int, int) { }

// 0x802153F8 | 112 bytes
cFixedWorldImpl::~cFixedWorldImpl(void) { }

// 0x80215468 | 1168 bytes
void cFixedWorldImpl::SetSize(int, int, bool) { }

// 0x802158F8 | 188 bytes
void cFixedWorldImpl::DeleteArrays(void) { }

// 0x802159B4 | 308 bytes
void cFixedWorldImpl::Save(iResFile *, int) { }

// 0x80215AE8 | 644 bytes
void cFixedWorldImpl::Load(iResFile *, int) { }

// 0x80215E44 | 936 bytes
void cFixedWorldImpl::GetWall(CTilePt &) { }

// 0x802161EC | 2556 bytes
void cFixedWorldImpl::SetWall(CTilePt &, TileWalls) { }

// 0x80216BE8 | 12476 bytes
void cFixedWorldImpl::ComputeRooms(int) { }

// 0x80219CA4 | 1316 bytes
void cFixedWorldImpl::ComputeArchValue(bool *) { }

// 0x8021A1C8 | 156 bytes
void cFixedWorldImpl::DoCommand(short, int) { }

// 0x8021A264 | 4044 bytes
void cFixedWorldImpl::OffsetWorld(CTilePt &) { }

// 0x8021B3F4 | 80 bytes
void cFixedWorldImpl::OutOfRoutableExtent(CTilePt &) const { }

// 0x8021B4B0 | 80 bytes
void cFixedWorldImpl::OutOfBounds(CTilePt &) const { }

// 0x8021B500 | 128 bytes
void cFixedWorldImpl::OutOfBuildingBounds(CTilePt &, bool) const { }

// 0x8021B580 | 72 bytes
void cFixedWorldImpl::OutOfGrid(CTilePt &) const { }

// 0x8021B6B8 | 80 bytes
void cFixedWorldImpl::GetFloor(CTilePt &) { }

// 0x8021B708 | 128 bytes
void cFixedWorldImpl::IsGrassAt(CTilePt &) { }

// 0x8021B788 | 140 bytes
void cFixedWorldImpl::SetFloor(CTilePt &, FloorPattern) { }

// 0x8021B814 | 188 bytes
void cFixedWorldImpl::GetRoom(CTilePt &) { }

// 0x8021B8D0 | 88 bytes
void cFixedWorldImpl::SetRoom(CTilePt &, unsigned short) { }

// 0x8021B928 | 80 bytes
void cFixedWorldImpl::GetFlags(CTilePt &) { }

// 0x8021B978 | 84 bytes
void cFixedWorldImpl::SetFlags(CTilePt &, unsigned char) { }

// 0x8021B9CC | 84 bytes
void cFixedWorldImpl::IsOutside(CTilePt &) { }

// 0x8021BA20 | 104 bytes
void cFixedWorldImpl::HasWalls(CTilePt &, TileWallsSegment) { }

// 0x8021BAF0 | 84 bytes
void cFixedWorldImpl::GetWallStorage(CTilePt &) { }

// 0x8021BB44 | 104 bytes
void cFixedWorldImpl::SetWallStorage(CTilePt &, TileWallStorage &) { }

// 0x8021BBAC | 112 bytes
void cFixedWorldImpl::MayEditTile(CTilePt &) const { }

// 0x8021BC1C | 492 bytes
void cFixedWorldImpl::GetRoomIdFromPoint(CTilePt &) { }
