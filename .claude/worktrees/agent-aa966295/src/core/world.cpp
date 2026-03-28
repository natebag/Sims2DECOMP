// world.cpp - World/lot management
// Object file: world.obj
// Source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
//
// Compile flags: -mcpu=750 -meabi -mhard-float -O2 -fno-exceptions -fno-rtti
//                -fno-builtin -fno-optimize-sibling-calls
//                -fno-schedule-insns -fno-schedule-insns2

#include "core/world.h"

// Global world pointer at 0x80500530 (SDA: r13 - 21488)
namespace Globs {
    cFixedWorld* pFixedWorld;
}

// External: __builtin_new at 0x802D11B0
extern void* operator new(unsigned int size);

// ============================================================================
// cFixedWorldImpl::GetFloorLayer
// Address: 0x8014CDC4
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_floorLayer pointer at +0x2C.
// ============================================================================
FloorLayer* cFixedWorldImpl::GetFloorLayer(void) {
    return m_floorLayer;
}

// ============================================================================
// cFixedWorldImpl::GetWalls
// Address: 0x8014CDCC
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_walls pointer at +0x38.
// ============================================================================
WallLayer* cFixedWorldImpl::GetWalls(void) {
    return m_walls;
}

// ============================================================================
// cFixedWorldImpl::GetXSize
// Address: 0x80151C30
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_xSize at +0x14.
// ============================================================================
int cFixedWorldImpl::GetXSize(void) const {
    return m_xSize;
}

// ============================================================================
// cFixedWorldImpl::GetYSize
// Address: 0x80151C38
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_ySize at +0x18.
// ============================================================================
int cFixedWorldImpl::GetYSize(void) const {
    return m_ySize;
}

// ============================================================================
// cFixedWorldImpl::GetMaxSize
// Address: 0x80151C40
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns constant 64.
// ============================================================================
int cFixedWorldImpl::GetMaxSize(void) const {
    return 64;
}

// ============================================================================
// cFixedWorldImpl::GetInfluenceMap
// Address: 0x8015235C
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_influenceMap pointer at +0x3C.
// ============================================================================
InfluenceMap* cFixedWorldImpl::GetInfluenceMap(void) {
    return m_influenceMap;
}

// ============================================================================
// cFixedWorldImpl::GetPassiveInfluenceMap
// Address: 0x80152364
// Size: 8 bytes (0x008)
// MATCHING
//
// Returns m_passiveInfluenceMap pointer at +0x40.
// ============================================================================
InfluenceMap* cFixedWorldImpl::GetPassiveInfluenceMap(void) {
    return m_passiveInfluenceMap;
}

// ============================================================================
// CreateTheWorld
// Address: 0x8015228C
// Size: 52 bytes (0x034)
// NON_MATCHING - GCC saves operator new result in r31 (16-byte frame),
// SN keeps result in r3 through constructor call (8-byte frame). Also
// SN stores result via SDA-relative, GCC uses absolute addressing.
// li r4/r5 order also reversed.
//
// Allocates cFixedWorldImpl(39, 39) and stores in Globs::pFixedWorld.
// ============================================================================
void CreateTheWorld(void) {
    Globs::pFixedWorld = new cFixedWorldImpl(39, 39);
}

// ============================================================================
// cFixedWorld::~cFixedWorld
// Address: 0x803AE3D4
// Size: 52 bytes (0x034)
// NON_MATCHING - SN generates combined scalar deleting destructor (checks
// r4 & 1 for conditional delete). GCC generates separate D0/D1/D2
// destructors per the Itanium C++ ABI.
//
// Sets vtable to cFixedWorld vtable (0x804654C8), then conditionally deletes.
// ============================================================================
cFixedWorld::~cFixedWorld(void) {
}
