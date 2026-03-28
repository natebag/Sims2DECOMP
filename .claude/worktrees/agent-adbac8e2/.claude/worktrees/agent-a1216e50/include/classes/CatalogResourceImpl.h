#ifndef CATALOGRESOURCEIMPL_H
#define CATALOGRESOURCEIMPL_H

#include "types.h"

// CatalogResourceImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 3 known fields (0 named), 12 methods

class CatalogResourceImpl {
public:
    // Constructors / Destructors
    CatalogResourceImpl(void)  // 0x80228798
    ~CatalogResourceImpl(void);  // 0x80228758

    // Methods
    void Load(ObjSelector *, short, bool);  // 0x802284A0 (324B)
    /* ? */ GetName(void);  // 0x80228820 (52B)
    /* ? */ GetDescription(void);  // 0x80228854 (52B)
    /* ? */ GetShortName(void);  // 0x80228888 (52B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [W] (Load)
    u32 m_field_008;  // 0x008 [W] (Load)
    u32 m_field_00C;  // 0x00C [W] (Load)
};

#endif // CATALOGRESOURCEIMPL_H
