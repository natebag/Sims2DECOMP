// elightgrid_stubs.cpp - Stub implementations for Elightgrid
// Auto-generated from symbols.json - 21 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"
#include "stub_classes.h"

// 0x8039B6F4 | 136 bytes
ELightGrid::ELightGrid(void) { }

// 0x8039B77C | 208 bytes
void ELightGrid::Flush(void) { }

// 0x8039B84C | 80 bytes
void ELightGrid::RoomData::Flush(void) { }

// 0x8039B89C | 308 bytes
void ELightGrid::AddRoomToVertex(int, int, int) { }

// 0x8039B9D0 | 1008 bytes
void ELightGrid::Update(TNodeList<EILight *> &, EInstance **, int, int) { }

// 0x8039BDC0 | 696 bytes
void ELightGrid::ConnectPortalLights(int *) { }

// 0x8039C078 | 476 bytes
void ELightGrid::RoomData::FindClosestLights(EVec3 &, int, int, int *, int *, int) { }

// 0x8039C254 | 380 bytes
void ELightGrid::EvaluatePointLights(int, int) { }

// 0x8039C3D0 | 684 bytes
void ELightGrid::AddLightsToVertices(void) { }

// 0x8039C67C | 84 bytes
void ELightGrid::EvaluateLights(void) { }

// 0x8039C6D0 | 136 bytes
void ELightGrid::EvaluateOuterLotLights(void) { }

// 0x8039C758 | 88 bytes
void ELightGrid::EvaluateAmbientAndDirectionalLights(void) { }

// 0x8039C7B0 | 144 bytes
void ELightGrid::RoomData::EvaluateAmbientAndDirectionalLights(void) { }

// 0x8039C840 | 248 bytes
void ELightGrid::EvaluatePortalLights(int, int) { }

// 0x8039C938 | 768 bytes
void ELightGrid::EvaluatePortalLight(int *, int *) { }

// 0x8039CDA4 | 508 bytes
void ELightGrid::GetLightWeightsAtLocation(EVec3 &, int, int *) { }

// 0x8039CFA0 | 200 bytes
void ELightGrid::GetLightsAtLocation(EVec3 &, int) const { }

// 0x8039D068 | 156 bytes
void ELightGrid::IsRoomAtLocation(EVec3 &, int) { }

// 0x8039D104 | 112 bytes
void ELightGrid::LightData::Clear(void) { }

// 0x8039D174 | 68 bytes
void ELightGrid::EvaluateLamps(void) { }

// 0x8039D1B8 | 224 bytes
void ELightGrid::EvaluateLampsOn(void) { }
