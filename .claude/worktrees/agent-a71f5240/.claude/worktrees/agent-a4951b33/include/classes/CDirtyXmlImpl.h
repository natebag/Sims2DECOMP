#ifndef CDIRTYXMLIMPL_H
#define CDIRTYXMLIMPL_H

#include "types.h"

// CDirtyXmlImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 3 known fields (1 named), 3 methods

class CDirtyXmlImpl {
public:
    // Constructors / Destructors
    CDirtyXmlImpl(void)  // 0x8002964C

    // Methods
    void createNewAptXml(char *);  // 0x8065EA6C (228B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (createNewAptXml)
    u32 m_field_004;  // 0x004 [W] (createNewAptXml)
    u8 _pad_008[0x18];  // 0x008
    u32 m_field_020;  // 0x020 [W] (createNewAptXml)
};

#endif // CDIRTYXMLIMPL_H
