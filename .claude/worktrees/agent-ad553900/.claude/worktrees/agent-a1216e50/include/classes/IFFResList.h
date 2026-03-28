#ifndef IFFRESLIST_H
#define IFFRESLIST_H

#include "types.h"

// IFFResList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 7 known fields (1 named), 8 methods

class IFFResList {
public:
    // Constructors / Destructors
    IFFResList(unsigned int)  // 0x80258D60
    IFFResList(IFFResList &)  // 0x80258C68
    IFFResList(void)  // 0x80258DCC
    ~IFFResList(void);  // 0x80258C28

    // Methods
    void DoStream(ReconBuffer *, int);  // 0x802503C8 (132B)
    void operator=(IFFResList &);  // 0x80258CC0 (92B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoStream, IFFResList)
    u32 m_field_004;  // 0x004 [W] (IFFResList)
    u16 m_field_008;  // 0x008 [W] (IFFResList)
    u16 m_field_00A;  // 0x00A [W] (IFFResList)
    u32 m_field_00C;  // 0x00C [W] (IFFResList)
    u32 m_field_010;  // 0x010 [R/W] (DoStream, IFFResList)
    u32 m_field_014;  // 0x014 [W] (IFFResList)
};

#endif // IFFRESLIST_H
