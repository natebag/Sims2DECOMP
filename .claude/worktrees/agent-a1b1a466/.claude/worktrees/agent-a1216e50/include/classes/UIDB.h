#ifndef UIDB_H
#define UIDB_H

#include "types.h"

// UIDB - struct layout extracted from assembly analysis
// Estimated minimum size: 0xC (12 bytes)
// 2 known fields (0 named), 18 methods

class UIDB {
public:
    // Methods
    void UIDBGetString(char *);  // 0x80481FBC (356B)
    void UIDBGetInt(char *);  // 0x80481CEC (356B)
    void UIDBSetInt(char *, int);  // 0x80482120 (364B)
    void UIDBInit(void);  // 0x80480348 (6364B)
    void UIDBShutdown(void);  // 0x80481C24 (200B)
    void UIDBSetString(char *, unsigned wchar_t *);  // 0x804823F8 (440B)
    void UIDBFindRecord(char *, UIDBData::eUIDBDataType);  // 0x804825B0 (360B)
    void UIDBGetFloat(char *);  // 0x80481E50 (364B)
    void UIDBSetFloat(char *, float);  // 0x8048228C (364B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_field_000;  // 0x000 [W] (UIDBInit)
    u8 _pad_002[6];  // 0x002
    f32 m_field_008;  // 0x008 [R/W] (UIDBGetFloat, UIDBGetInt, UIDBGetString, ...)
};

#endif // UIDB_H
