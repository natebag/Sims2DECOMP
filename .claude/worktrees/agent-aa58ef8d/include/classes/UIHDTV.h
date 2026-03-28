#ifndef UIHDTV_H
#define UIHDTV_H

#include "types.h"

// UIHDTV - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 2 known fields (0 named), 28 methods

class UIHDTV {
public:
    // Constructors / Destructors
    UIHDTV(void)  // 0x80489608
    ~UIHDTV(void);  // 0x80489630

    // Methods
    void ConvertXMLToHDTV(char **);  // 0x80489680 (912B)
    bool IsNumber(char);  // 0x80489D44 (100B)
    /* ? */ GetPreceedingXMLTag(char *, int);  // 0x80489B38 (524B)
    /* ? */ GetNumericValue(char *, int, int &);  // 0x80489A10 (296B)
    bool IsFoundNumberNegative(char *, int);  // 0x80489F84 (88B)
    /* ? */ GetNewXPosition(int);  // 0x80489EC4 (48B)
    /* ? */ GetNewYPosition(int);  // 0x80489EF4 (48B)
    /* ? */ GetNewWidth(int);  // 0x80489F24 (48B)
    /* ? */ GetNewHeight(int);  // 0x80489F54 (48B)
    void UsingHDTV(void);  // 0x80489DA8 (140B)
    /* ? */ GetScreenWidth(void);  // 0x80489E7C (72B)
    /* ? */ GetScreenHeight(void);  // 0x80489E34 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (ConvertXMLToHDTV)
    u8 _pad_008[4];  // 0x008
    u32 m_field_00C;  // 0x00C [R] (ConvertXMLToHDTV)
};

#endif // UIHDTV_H
