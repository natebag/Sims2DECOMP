// bsplinevolume_stubs.cpp - Stub implementations for Bsplinevolume
// Auto-generated from symbols.json - 13 functions
// These are stub implementations to register progress.
// Each function needs proper decompilation to match the original binary.

#include "types.h"

// 0x804CF30C | 148 bytes
BSplineVolume::BSplineVolume(void) { }

// 0x804CF3A0 | 76 bytes
BSplineVolume::~BSplineVolume(void) { }

// 0x804CF3EC | 552 bytes
void BSplineVolume::Free(void) { }

// 0x804CFC5C | 4 bytes
void BSplineVolume::Write(EStream &) { }

// 0x804CFCF8 | 248 bytes
void BSplineVolume::AllocateControlPoints(int, int, int, int) { }

// 0x804CFDF0 | 1040 bytes
void BSplineVolume::ParameterizeControlPoints(void) { }

// 0x804D0200 | 660 bytes
void BSplineVolume::ParameterizeVert(EVec3, int &) { }

// 0x804D0494 | 348 bytes
void BSplineVolume::GenerateControlPointDeltas(void) { }

// 0x804D05F0 | 40 bytes
void BSplineVolume::GetNumVolumes(void) { }

// 0x804D0618 | 204 bytes
void BSplineVolume::SetVolumeWeights(int, float) { }

// 0x804D06E4 | 912 bytes
void BSplineVolume::BlendVolumes(void) { }

// 0x804D0C8C | 704 bytes
void BSplineVolume::GetPosition(EVec3 *, int) const { }

// 0x804D1BF4 | 8 bytes
void BSplineVolume::GetID(void) { }
