#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "types.h"
#include "core/e_vec3.h"

// Intersection result structure
struct Intersection {
    // intersection data fields
};

// Get intersection between a circle and a point/line
// From: intersection.obj
// Wrapper that calls GetCircleCircleIX with zero-radius second circle
void GetCirclePointIX(EVec2& center, float radius, EVec2& point, EVec2& dir, Intersection& result);

// Full circle-circle intersection (larger function, not decompiled here)
void GetCircleCircleIX(EVec2& c1, float r1, EVec2& c2, EVec2& d2, float r2, EVec2& d2b, Intersection& result);

#endif // INTERSECTION_H
