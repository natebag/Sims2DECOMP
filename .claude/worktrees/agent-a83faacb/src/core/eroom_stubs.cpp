#if 0 // SKIP
// eroom_stubs.cpp - Stub implementations for Eroom
// Auto-generated from symbols.json - 25 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x800446CC | 276 bytes
ERoom::ERoom(void) { }

// 0x800447E0 | 2056 bytes
ERoom::~ERoom(void) { }

// 0x80044FE8 | 952 bytes
void ERoom::InitRoomLookupTab(void) { }

// 0x800454EC | 188 bytes
void ERoom::GetNumWalls(unsigned short) { }

// 0x800455A8 | 292 bytes
void ERoom::GetWallPaperCost(unsigned int, unsigned short) { }

// 0x800456CC | 240 bytes
void ERoom::DrawWallpaperPreview(ERC *, unsigned short, EVec2 &) { }

// 0x800457BC | 96 bytes
void ERoom::IsRoomWallsOpaque(int, int) { }

// 0x8004581C | 672 bytes
void ERoom::CalAllRoomOpaque(int) { }

// 0x80045ABC | 112 bytes
void ERoom::GetShortDistToCam(int, int) { }

// 0x80045B2C | 116 bytes
void ERoom::GetOccludeAlpha(int, int) { }

// 0x80045BA0 | 96 bytes
void ERoom::IsRoomRoofOpaque(int, int) { }

// 0x80045C00 | 2472 bytes
void ERoom::CalRoofOpaque(int) { }

// 0x800465A8 | 792 bytes
void ERoom::CalShortDistToCam(int) { }

// 0x80046964 | 148 bytes
void ERoom::SetWallState(EWallUpDownStateType) { }

// 0x80046C00 | 256 bytes
void ERoom::UpdateWallFade(int) { }

// 0x80046D00 | 448 bytes
void ERoom::Init(void) { }

// 0x80046EC0 | 744 bytes
void ERoom::ProcStandardWalls(bool, int &, int &, bool) { }

// 0x800471A8 | 864 bytes
void ERoom::ProcDiagonalWalls(int &, int &, bool) { }

// 0x80047508 | 712 bytes
void ERoom::ProcessCell(TNodeList<ERoomWall *> &, ERoomWallPtr &, CTilePt &, TileWallsSegment, DiagonalSideSelector, TileWalls &, int, int &, int &, bool) { }

// 0x800477D0 | 832 bytes
void ERoom::PreviewWallBuild(bool) { }

// 0x800480B4 | 192 bytes
void ERoom::FindWallContainingSegment(TNodeList<ERoomWall *> &, TileWallsSegment, CTilePt &, CTilePt &) { }

// 0x8004825C | 292 bytes
void ERoom::GetWallFromTileAndSegment(TileWallsSegment, CTilePt &) { }

// 0x80048380 | 224 bytes
void ERoom::DeleteERoomWallContainingSegment(TileWallsSegment, CTilePt &, CTilePt &) { }

// 0x80048460 | 376 bytes
void ERoom::DeleteWallAtTile(CTilePt &, TileWalls &, TileWallsSegment) { }

// 0x800485D8 | 532 bytes
void ERoom::KillArchitecturalObject(CTilePt &, TileWallsSegment, int &, bool) { }
#endif
