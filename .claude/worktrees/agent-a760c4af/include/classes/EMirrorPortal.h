#ifndef EMIRRORPORTAL_H
#define EMIRRORPORTAL_H

#include "types.h"

// EMirrorPortal - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF4 (244 bytes)
// 12 known fields (1 named), 28 methods

class EMirrorPortal {
public:
    // Constructors / Destructors
    EMirrorPortal(void)  // 0x807C23F8
    ~EMirrorPortal(void);  // 0x807C24F4

    // Methods
    void SetNumCorners(int);  // 0x807C2584 (172B)
    void SetMirrorShader(unsigned int);  // 0x807C27C0 (112B)
    void SetCorner(int, EVec3 &);  // 0x807C26F4 (204B)
    void SetFieldOfView(float);  // 0x807C2830 (44B)
    void StartRendering(E3DWindow &, ERC *);  // 0x807C285C (820B)
    void StopRendering(E3DWindow &, ERC *);  // 0x807C2B90 (556B)
    /* ? */ GetCorner(int);  // 0x807C2630 (196B)
    void CalcMirrorMatrix(void);  // 0x807C2DBC (640B)
    void BuildPortalGeometry(void);  // 0x807C32EC (736B)
    void PushPortal(E3DWindow &);  // 0x807C3238 (116B)
    void InitRC(ERC *);  // 0x807C303C (508B)
    void PopPortal(E3DWindow &);  // 0x807C32AC (64B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (EMirrorPortal, StartRendering)
    f32 m_field_004;  // 0x004 [R] (CalcMirrorMatrix)
    f32 m_field_008;  // 0x008 [R] (CalcMirrorMatrix)
    u8 _pad_00C[4];  // 0x00C
    f32 m_field_010;  // 0x010 [R] (CalcMirrorMatrix)
    u8 _pad_014[8];  // 0x014
    f32 m_field_01C;  // 0x01C [R] (CalcMirrorMatrix)
    u8 _pad_020[0x14];  // 0x020
    u32 m_field_034;  // 0x034 [R/W] (BuildPortalGeometry, EMirrorPortal, StartRendering, ...)
    u32 m_field_038;  // 0x038 [R] (BuildPortalGeometry)
    u32 m_field_03C;  // 0x03C [R/W] (EMirrorPortal, PushPortal, ~EMirrorPortal)
    u32 m_field_040;  // 0x040 [R/W] (CalcMirrorMatrix, EMirrorPortal, PushPortal, ...)
    u32 m_mirrorShader;  // 0x044 [R/W] (EMirrorPortal, SetMirrorShader, StopRendering, ...)
    u32 m_field_048;  // 0x048 [R/W] (EMirrorPortal, StartRendering, StopRendering)
    u8 _pad_04C[0xA4];  // 0x04C
    u32 m_field_0F0;  // 0x0F0 [R] (StopRendering)
};

#endif // EMIRRORPORTAL_H
