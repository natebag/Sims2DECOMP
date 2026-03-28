#if 0 // SKIP
// eroomwall_stubs.cpp - Stub implementations for Eroomwall
// Auto-generated from symbols.json - 23 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8003F154 | 480 bytes
void ERoomWall::GetWallMeterValue(int &) { }

// 0x8003F360 | 16 bytes
void ERoomWall::IsWallsOpaque(int) { }

// 0x8003F370 | 228 bytes
void ERoomWall::CalWallsOpaque(int) { }

// 0x8003F454 | 352 bytes
void ERoomWall::CalShortDistToCam(int) { }

// 0x80042E30 | 76 bytes
void* ERoomWall::operator new(unsigned int) { }

// 0x80042E7C | 52 bytes
void ERoomWall::operator delete(void *) { }

// 0x80042EB0 | 1020 bytes
ERoomWall::ERoomWall(TileWallsSegment, DiagonalSideSelector, CTilePt &, bool) { }

// 0x800432AC | 244 bytes
ERoomWall::~ERoomWall(void) { }

// 0x800433A0 | 1392 bytes
void ERoomWall::GetWallDims(TileWallsSegment, DiagonalSideSelector, EVec3 &, EVec3 &) { }

// 0x80043910 | 160 bytes
void ERoomWall::SetWallUpDownMode(EWallUpDownStateType, bool) { }

// 0x800439B0 | 264 bytes
void ERoomWall::AddTile(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector, bool) { }

// 0x80043AB8 | 1288 bytes
void ERoomWall::DrawWall(ERC *) { }

// 0x80043FC0 | 536 bytes
void ERoomWall::getRoomIdFromPoint(CTilePt &) { }

// 0x800441D8 | 184 bytes
void ERoomWall::getWallNormalOnSideOfCursor(EVec3 &, EVec3 &, EVec2 &, EVec2 &) { }

// 0x80044290 | 1084 bytes
void ERoomWall::DrawWallpaperPreview(ERC *, EVec2 &) { }

// 0x800453A0 | 332 bytes
void ERoomWall::GetWallPaperCost(int, unsigned short) { }

// 0x80047B10 | 160 bytes
void ERoomWall::CountWalls(void) { }

// 0x80047BB0 | 488 bytes
void ERoomWall::HasSegment(TileWallsSegment, CTilePt &, CTilePt &) { }

// 0x80047D98 | 512 bytes
void ERoomWall::DeleteWallAtTile(CTilePt &) { }

// 0x80047F98 | 284 bytes
void ERoomWall::RemoveWallsFromWorld(void) { }

// 0x80048174 | 232 bytes
void ERoomWall::GetWallAtTile(CTilePt &) { }

// 0x8004A854 | 64 bytes
void ERoomWall::SafeDelete(void) { }

// 0x8004A894 | 16 bytes
void ERoomWall::GetShortDistToCam(int) { }
#endif
