#ifndef CATALOGRESOURCE_H
#define CATALOGRESOURCE_H

#include "types.h"

// CatalogResource - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (1 named), 7 methods

class CatalogResource {
public:
    // Constructors / Destructors
    CatalogResource(void)  // 0x80228964
    ~CatalogResource(void);  // 0x80228998

    // Methods
    void CreateInstance(void);  // 0x802283D8 (80B)
    void DestroyInstance(CatalogResource *);  // 0x80228428 (120B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (CreateInstance)
    u32 m_field_004;  // 0x004 [W] (CreateInstance)
    u32 m_field_008;  // 0x008 [W] (CreateInstance)
    u32 m_field_00C;  // 0x00C [W] (CreateInstance)
};

#endif // CATALOGRESOURCE_H
