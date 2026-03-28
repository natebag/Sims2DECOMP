#ifndef PROPTABLEIMPL_H
#define PROPTABLEIMPL_H

#include "types.h"

// PropTableImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 14 methods

class PropTableImpl {
public:
    // Constructors / Destructors
    PropTableImpl(void)  // 0x80390A9C
    ~PropTableImpl(void);  // 0x80390AF0

    // Methods
    void Load(unsigned int, short);  // 0x80390B3C (344B)
    /* ? */ GetEntry(int);  // 0x80390C94 (216B)
    /* ? */ GetID(void);  // 0x8039197C (52B)
    /* ? */ GetEntryName(int);  // 0x80391A3C (164B)
    void CountEntries(void);  // 0x803919F8 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [W] (Load)
    u32 m_field_008;  // 0x008 [R] (Load)
};

#endif // PROPTABLEIMPL_H
