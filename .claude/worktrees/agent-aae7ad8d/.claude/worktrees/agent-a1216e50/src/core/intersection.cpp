// intersection.cpp - Geometry intersection small functions
// From: intersection.obj
// Small functions (<=64 bytes) decompiled from this object

#include "core/intersection.h"

// ============================================================================
// GetCirclePointIX(EVec2 &, float, EVec2 &, EVec2 &, Intersection &)
// 0x800499F8 - 64 bytes
// Wrapper: calls GetCircleCircleIX with zero-radius second circle
// ============================================================================
// stwu r1,-16(r1); mflr r0; stw r0,20(r1)
// lis r9,0x803d; addi r11,r1,8
// lfs f0,0x2e9c(r9)     -- loads 0.0f constant
// mr r7,r6; mr r6,r11
// stfs f0,4(r11); fmr f2,f0; stfs f0,8(r1)
// bl GetCircleCircleIX
// lwz r0,20(r1); mtlr r0; addi r1,r1,16; blr
//
// This creates a zero-radius circle at origin as the second circle
// and delegates to the full circle-circle intersection.
// NON_MATCHING - float constant loaded from .sdata2 section
void GetCirclePointIX(EVec2& center, float radius, EVec2& point, EVec2& dir, Intersection& result) {
    EVec2 zeroCenter;
    zeroCenter.x = 0.0f;
    zeroCenter.y = 0.0f;
    float zeroRadius = 0.0f;
    GetCircleCircleIX(center, radius, point, zeroCenter, zeroRadius, dir, result);
}
