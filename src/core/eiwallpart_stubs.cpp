#if 0 // SKIP
// eiwallpart_stubs.cpp - Stub implementations for Eiwallpart
// Auto-generated from symbols.json - 39 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8003CE0C | 252 bytes
void EIWallPart::GetWallType(unsigned char) { }

// 0x8003CF08 | 116 bytes
void EIWallPart::IsOpaque(void) { }

// 0x8003F5B4 | 144 bytes
void* EIWallPart::operator new(unsigned int) { }

// 0x8003F644 | 52 bytes
void EIWallPart::operator delete(void *) { }

// 0x8003FC7C | 196 bytes
void EIWallPart::GetShadowModel(void) { }

// 0x8003FD40 | 224 bytes
EIWallPart::EIWallPart(void) { }

// 0x8003FE20 | 368 bytes
void EIWallPart::OptimizeOrderTable(void) { }

// 0x800402BC | 308 bytes
void EIWallPart::SetOrient(EMat4 &) { }

// 0x800403F0 | 152 bytes
void EIWallPart::VisibilityTest(E3DWindow &) { }

// 0x800404A8 | 1936 bytes
void EIWallPart::Draw(ELevelDrawData &) { }

// 0x8004135C | 1028 bytes
void EIWallPart::WallOrderTableCallback(ELevelDrawData &, EOrderTableData *) { }

// 0x80041760 | 392 bytes
void EIWallPart::DrawShadow(ELevelDrawData &) { }

// 0x800418E8 | 860 bytes
void EIWallPart::DrawOutsideShadows(TNodeList<EInstance *> &, EVec3 &, ELevelDrawData &) { }

// 0x80041C44 | 8 bytes
void EIWallPart::GetAdjacentRoom(void) { }

// 0x80041C4C | 332 bytes
void EIWallPart::GetPoint(CTilePt &) { }

// 0x80041D98 | 532 bytes
void EIWallPart::GetPoints(CTilePt &, CTilePt &) { }

// 0x80041FAC | 164 bytes
EIWallPart::~EIWallPart(void) { }

// 0x80042050 | 2224 bytes
void EIWallPart::GetWallModelId(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector, float &) { }

// 0x80042900 | 276 bytes
void EIWallPart::ChangeWallpaper(unsigned int) { }

// 0x80042A14 | 320 bytes
void EIWallPart::GetWallpaperShader(void) { }

// 0x80042B54 | 108 bytes
void EIWallPart::SetVisible(bool) { }

// 0x80042BC0 | 48 bytes
void EIWallPart::GetVisible(int) { }

// 0x80042BF0 | 304 bytes
void EIWallPart::SetWallState(EWallUpDownStateType, bool) { }

// 0x800469F8 | 360 bytes
void EIWallPart::DoFadeCollisonWallList(TrapezoidFade &, EVec3 &, TNodeList<EIWallPart *> &) { }

// 0x80046B60 | 160 bytes
void EIWallPart::DoFadeCollisonForList(TrapezoidFade &, TNodeList<ERoomWall *> &) { }

// 0x8004A3E8 | 40 bytes
void EIWallPart::New(void) { }

// 0x8004A410 | 44 bytes
void EIWallPart::Construct(EIWallPart *) { }

// 0x8004A43C | 36 bytes
void EIWallPart::Destruct(EIWallPart *) { }

// 0x8004A460 | 64 bytes
void EIWallPart::SafeDelete(void) { }

// 0x8004A4AC | 12 bytes
void EIWallPart::GetTypeName(void) const { }

// 0x8004A4B8 | 12 bytes
void EIWallPart::GetTypeKey(void) const { }

// 0x8004A4C4 | 12 bytes
void EIWallPart::GetTypeVersion(void) const { }

// 0x8004A4DC | 12 bytes
void EIWallPart::GetReadVersion(void) { }

// 0x8004A4E8 | 84 bytes
void EIWallPart::RegisterType(unsigned short) { }

// 0x8004A53C | 32 bytes
void EIWallPart::CreateCopy(void) const { }

// 0x8004A564 | 24 bytes
void EIWallPart::IsDiagonal(void) { }

// 0x8004A57C | 24 bytes
void EIWallPart::isDiagonal(TileWallsSegment) { }

// 0x8004A594 | 8 bytes
void EIWallPart::SetForceFadeOff(bool) { }

// 0x8004A59C | 4 bytes
void EIWallPart::RealizeShaderTuning(void) { }
#endif
