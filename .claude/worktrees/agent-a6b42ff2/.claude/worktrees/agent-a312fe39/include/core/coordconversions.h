#ifndef COORDCONVERSIONS_H
#define COORDCONVERSIONS_H

#include "types.h"

// Coordinate conversion functions - from coordconversions.obj
// Convert between Alt (altitude), Iso (isometric), and World coordinate systems

// Converts altitude value to isometric (larger function, not decompiled here)
float AltToIso(float& val);
// Converts isometric value to altitude (larger function, not decompiled here)
float IsoToAlt(float& val);

// Converts altitude to world coordinates
// Calls AltToIso then multiplies by scale factor
float AltToWorld(float& val);

// Converts world to altitude coordinates
// Multiplies by inverse scale factor, stores to stack, calls IsoToAlt
float WorldToAlt(float& val);

#endif // COORDCONVERSIONS_H
