// erlevel_stubs.cpp - Stub implementations for Erlevel
// Auto-generated from symbols.json - 76 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8039E918 | 1016 bytes
ERLevel::ERLevel(void) { }

// 0x8039ED10 | 404 bytes
ERLevel::~ERLevel(void) { }

// 0x8039EEA4 | 92 bytes
void ERLevel::GetSunLight(EVec3 &, EDirLight &) { }

// 0x8039EF00 | 672 bytes
void ERLevel::Write(EStream &) { }

// 0x8039F1A0 | 248 bytes
void ERLevel::AddInstancesFromList(TNodeList<EInstance *> &) { }

// 0x8039F298 | 240 bytes
void ERLevel::AddInstancesFromBoundTree(EStorable *) { }

// 0x8039FEBC | 3380 bytes
void ERLevel::Load(EFile &) { }

// 0x803A0BF0 | 464 bytes
void ERLevel::Refresh(EFile *) { }

// 0x803A0DC0 | 120 bytes
void ERLevel::AllocAndLoadLevel(EFile &) { }

// 0x803A0E38 | 68 bytes
void ERLevel::ClearJustReadByLevelFlags(void) { }

// 0x803A0E7C | 328 bytes
void ERLevel::DestroyInstancesWithoutJustReadByLevelFlags(void) { }

// 0x803A0FC4 | 124 bytes
void ERLevel::DestroyInstancesOriginallyReadByLevel(void) { }

// 0x803A1040 | 148 bytes
void ERLevel::Deallocate(void) { }

// 0x803A10D4 | 296 bytes
void ERLevel::DeallocateSub(void) { }

// 0x803A11FC | 60 bytes
void ERLevel::InsertInstance(EInstance *, EInstance *) { }

// 0x803A1250 | 156 bytes
void ERLevel::InsertWall(EInstance *, bool) { }

// 0x803A12EC | 88 bytes
void ERLevel::RemoveWall(EInstance *) { }

// 0x803A1344 | 196 bytes
void ERLevel::InsertLight(EILight *) { }

// 0x803A1408 | 152 bytes
void ERLevel::RemoveLight(EILight *) { }

// 0x803A15A0 | 376 bytes
void ERLevel::InsertSkydomeInstance(EInstance *) { }

// 0x803A1718 | 368 bytes
void ERLevel::AddInstanceToLevel(EInstance *) { }

// 0x803A1888 | 372 bytes
void ERLevel::AddInstanceToLevelHead(EInstance *) { }

// 0x803A19FC | 476 bytes
void ERLevel::AddWallInstanceToLevel(EInstance *) { }

// 0x803A1BDC | 80 bytes
void ERLevel::PrepareInstance(EInstance *) { }

// 0x803A1C2C | 164 bytes
void ERLevel::AddInstanceToRoom(EInstance *) { }

// 0x803A1CD0 | 408 bytes
void ERLevel::RemoveInstanceFromRoom(EInstance *) { }

// 0x803A1E68 | 120 bytes
void ERLevel::GetRoomIndex(EInstance *) const { }

// 0x803A1EE0 | 112 bytes
void ERLevel::NotifyInstanceMoved(EInstance *) { }

// 0x803A1F50 | 268 bytes
void ERLevel::FixInstances(void) { }

// 0x803A205C | 164 bytes
void ERLevel::FixInstanceList(TNodeList<EInstance *> &) { }

// 0x803A2100 | 60 bytes
void ERLevel::AddInstanceToIdMap(EInstance *) { }

// 0x803A213C | 120 bytes
void ERLevel::RemoveInstanceFromIdMap(EInstance *) { }

// 0x803A21B4 | 64 bytes
void ERLevel::FindInstance(char *) { }

// 0x803A2230 | 40 bytes
void ERLevel::FindFirstInstance(unsigned int, EInstance **) { }

// 0x803A2258 | 40 bytes
void ERLevel::FindNextInstance(HTIteratorPtrType *, EInstance **) { }

// 0x803A2530 | 108 bytes
void ERLevel::UnregisterFloorOTDs(EInstance *) { }

// 0x803A282C | 404 bytes
void ERLevel::SetBounds(EInstance *, EBound3 &) { }

// 0x803A29C0 | 784 bytes
void ERLevel::AddBounds(EBound3 &, EBound3 &, bool &) { }

// 0x803A2CD0 | 264 bytes
void ERLevel::CalcBounds(void) { }

// 0x803A2DD8 | 56 bytes
void ERLevel::UpdateLightGrid(void) { }

// 0x803A2E10 | 760 bytes
void ERLevel::Update(void) { }

// 0x803A3108 | 120 bytes
void ERLevel::CalcRadiusFromViewParams(float, float, float) { }

// 0x803A31D8 | 644 bytes
void ERLevel::DrawObjectShadowsOutside(TNodeList<EInstance *> &) { }

// 0x803A345C | 1028 bytes
void ERLevel::DrawObjectShadowsInside(TNodeList<EInstance *> &) { }

// 0x803A3860 | 116 bytes
void ERLevel::DrawOrderTableSlot(EOrderTableData *) { }

// 0x803A38D4 | 256 bytes
void ERLevel::DrawOrderTableSlotFast(EOrderTableData *) { }

// 0x803A39D4 | 244 bytes
void ERLevel::DrawSortedOrderTable(EOrderTableData *) { }

// 0x803A5070 | 368 bytes
void ERLevel::ObjectShouldBeOccluded(EInstance *) { }

// 0x803A5224 | 992 bytes
void ERLevel::DrawSimShadow(int) { }

// 0x803A5604 | 80 bytes
void ERLevel::UpdatePerRoomData(void) { }

// 0x803A5654 | 188 bytes
void ERLevel::AllocAndCopyOTD(EOrderTableData &) { }

// 0x803A576C | 396 bytes
void ERLevel::RegisterFloor(EOrderTableData &) { }

// 0x803A58F8 | 376 bytes
void ERLevel::InsertInOrderTable(EOrderTableData &) { }

// 0x803A5A70 | 272 bytes
void ERLevel::InsertInDOFForegroundObjectList(EOrderTableData &) { }

// 0x803A5B80 | 40 bytes
void ERLevel::DrawDOFForegroundObjects(void) { }

// 0x803A5BA8 | 608 bytes
void ERLevel::DrawOrderTableEntry(EOrderTableData *, ERC *) { }

// 0x803A5E08 | 740 bytes
void ERLevel::DrawOrderTable(void) { }

// 0x803A60EC | 2052 bytes
void ERLevel::IntersectBoundBox(EBound3 &, EVec3 &, EVec3 &) { }

// 0x803A68F0 | 252 bytes
void ERLevel::DrawWireFrame(ERC *) { }

// 0x803A69EC | 568 bytes
void ERLevel::SetRoomCount(int) { }

// 0x803A6C24 | 240 bytes
void ERLevel::UpdateLightsIntensityScale(int, EVec3) { }

// 0x803A6D14 | 68 bytes
void ERLevel::IsRoomAt(EVec3 &, int) { }

// 0x803A6D58 | 36 bytes
void ERLevel::InitializeLightingGrid(void) { }

// 0x803A6D7C | 288 bytes
void ERLevel::ResetLightLocations(void) { }

// 0x803A7614 | 40 bytes
void ERLevel::OutsideLightsInit(float, LevelLightingEntry &) { }

// 0x803A763C | 364 bytes
void ERLevel::OutsideLightsUpdate(float, LevelLightingEntry &) { }

// 0x803A77A8 | 136 bytes
void ERLevel::UpdateFloorLighting(void) { }

// 0x803A7844 | 200 bytes
void ERLevel::GetLightsAtLocation(EVec3 &, int, ELights &) { }

// 0x803A9800 | 44 bytes
void ERLevel::New(void) { }

// 0x803A982C | 48 bytes
void ERLevel::Construct(ERLevel *) { }

// 0x803A9880 | 64 bytes
void ERLevel::SafeDelete(void) { }

// 0x803A9908 | 84 bytes
void ERLevel::RegisterType(unsigned short) { }

// 0x803A99B4 | 44 bytes
void ERLevel::operator delete(void *) { }

// 0x803A9A34 | 40 bytes
void ERLevel::SetIdMapTableSize(int) { }

// 0x803A9A7C | 48 bytes
void ERLevel::UpdateRooms(int) { }

// 0x803A9AC4 | 60 bytes
void ERLevel::RefreshRoomAssignment(EInstance *) { }
