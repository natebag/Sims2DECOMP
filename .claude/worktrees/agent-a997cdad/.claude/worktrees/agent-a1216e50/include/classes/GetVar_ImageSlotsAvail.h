#ifndef GETVAR_IMAGESLOTSAVAIL_H
#define GETVAR_IMAGESLOTSAVAIL_H

#include "types.h"

// GetVar_ImageSlotsAvail - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 3 known fields (3 named), 6 methods

class GetVar_ImageSlotsAvail {
public:
    // Constructors / Destructors
    GetVar_ImageSlotsAvail(char *)  // 0x80593F90
    ~GetVar_ImageSlotsAvail(void);  // 0x80591EB4

    // Methods
    void Handler(char *);  // 0x805696B4 (116B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (GetVar_ImageSlotsAvail)
    u32 m_var_ImageSlotsAvail_004;  // 0x004 [W] (GetVar_ImageSlotsAvail)
    u32 m_var_ImageSlotsAvail_008;  // 0x008 [W] (GetVar_ImageSlotsAvail)
};

#endif // GETVAR_IMAGESLOTSAVAIL_H
