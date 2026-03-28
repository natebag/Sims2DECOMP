#ifndef ERENDERSURFACE_H
#define ERENDERSURFACE_H

#include "types.h"

// ERenderSurface - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (2 named), 18 methods

class ERenderSurface {
public:
    // Constructors / Destructors
    ERenderSurface(void)  // 0x8090CC50
    ~ERenderSurface(void);  // 0x8090CCAC

    // Methods
    void Create(ERenderSurfaceDef &);  // 0x8090CD08 (140B)
    /* ? */ GetOutputRect(TRect<float> &);  // 0x8090CE64 (172B)
    /* ? */ GetXSize(void);  // 0x8090CD94 (44B)
    /* ? */ GetYSize(void);  // 0x8090CDC0 (44B)
    void SetFlags(unsigned int);  // 0x8090CDEC (44B)
    /* ? */ GetFlags(void);  // 0x8090CFB0 (44B)
    void SetSize(int, int, int);  // 0x8090CE18 (76B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Create, GetOutputRect)
    u32 m_outputRect_004;  // 0x004 [R/W] (Create, GetOutputRect)
    u32 m_field_008;  // 0x008 [W] (Create)
    u32 m_field_00C;  // 0x00C [W] (Create)
    u32 m_field_010;  // 0x010 [W] (Create)
    u32 m_field_014;  // 0x014 [W] (Create)
};

#endif // ERENDERSURFACE_H
