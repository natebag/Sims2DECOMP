#ifndef ENGCTEXTUREUTIL_H
#define ENGCTEXTUREUTIL_H

#include "types.h"

// ENgcTextureUtil - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 17 known fields (0 named), 14 methods

class ENgcTextureUtil {
public:
    // Methods
    void SwizzleToC8(unsigned char *, int, int, unsigned char *);  // 0x808E40A0 (428B)
    void SwizzleFromRGBA8(unsigned char *, int, int, unsigned char *);  // 0x808E4AF4 (1036B)
    void SwizzleToC4(unsigned char *, int, int, unsigned char *);  // 0x808E3EF4 (428B)
    void SwizzleFromC8(unsigned char *, int, int, unsigned char *);  // 0x808E4948 (428B)
    void SwizzleToRGB5A3(unsigned char *, int, int, unsigned char *);  // 0x808E3C04 (752B)
    void SwizzleFromRGB5A3(unsigned char *, int, int, unsigned char *);  // 0x808E4658 (752B)
    void SwizzleToRGBA8(unsigned char *, int, int, unsigned char *);  // 0x808E424C (1036B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_field_000;  // 0x000 [R] (SwizzleFromC8, SwizzleFromRGB5A3, SwizzleFromRGBA8, ...)
    u8 m_field_001;  // 0x001 [R] (SwizzleFromRGBA8)
    u8 m_field_002;  // 0x002 [R] (SwizzleFromRGBA8)
    u8 m_field_003;  // 0x003 [R] (SwizzleFromRGBA8)
    u8 m_field_004;  // 0x004 [R] (SwizzleFromC8, SwizzleFromRGB5A3, SwizzleFromRGBA8, ...)
    u8 m_field_005;  // 0x005 [R] (SwizzleFromRGBA8)
    u8 m_field_006;  // 0x006 [R] (SwizzleFromRGBA8)
    u8 m_field_007;  // 0x007 [R] (SwizzleFromRGBA8)
    u32 m_field_008;  // 0x008 [R] (SwizzleFromRGB5A3)
    u8 _pad_00C[0x14];  // 0x00C
    u8 m_field_020;  // 0x020 [R] (SwizzleFromRGBA8)
    u8 m_field_021;  // 0x021 [R] (SwizzleFromRGBA8)
    u8 m_field_022;  // 0x022 [R] (SwizzleFromRGBA8)
    u8 m_field_023;  // 0x023 [R] (SwizzleFromRGBA8)
    u8 m_field_024;  // 0x024 [R] (SwizzleFromRGBA8)
    u8 m_field_025;  // 0x025 [R] (SwizzleFromRGBA8)
    u8 m_field_026;  // 0x026 [R] (SwizzleFromRGBA8)
    u8 m_field_027;  // 0x027 [R] (SwizzleFromRGBA8)
};

#endif // ENGCTEXTUREUTIL_H
