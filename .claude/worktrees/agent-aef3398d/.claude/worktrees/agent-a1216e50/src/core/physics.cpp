// physics.cpp - Physics simulation
// Object file: physics.obj
// Source: c:\BuildAgent\cm3-build22-NGC\CMBuild\
//
// Compile flags: -mcpu=750 -meabi -mhard-float -O2 -fno-exceptions -fno-rtti
//                -fno-builtin -fno-optimize-sibling-calls
//                -fno-schedule-insns -fno-schedule-insns2

#include "core/physics.h"

// ============================================================================
// Physics::~Physics
// Address: 0x80058FD4
// Size: 40 bytes (0x28)
// NON_MATCHING - SN Systems generates combined scalar deleting destructor
// (checks r4 & 1 for conditional delete). devkitPPC generates separate
// D0/D1/D2 destructors per the Itanium C++ ABI.
// ============================================================================
Physics::~Physics(void) {
}
