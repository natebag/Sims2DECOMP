#ifndef UIBUTTONIMAGES_H
#define UIBUTTONIMAGES_H

#include "types.h"

// UIButtonImages - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB0 (176 bytes)
// 16 known fields (1 named), 20 methods

class UIButtonImages {
public:
    // Constructors / Destructors
    UIButtonImages(void)  // 0x80496398
    ~UIButtonImages(void);  // 0x8049649C

    // Methods
    /* ? */ GetButtonShader(int);  // 0x80496AB4 (228B)
    /* ? */ GetButtonMinSize(int);  // 0x80496B98 (128B)
    void Startup(void);  // 0x8049627C (116B)
    void Shutdown(void);  // 0x804962F0 (168B)
    void DefineIDs(void);  // 0x804964F8 (1220B)
    void AddRefAll(void);  // 0x804969BC (124B)
    void DelRefAll(void);  // 0x80496A38 (124B)
    void LocalizeXBoxImages(void);  // 0x80496C18 (968B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (DefineIDs)
    u32 m_field_004;  // 0x004 [W] (DefineIDs)
    u32 m_field_008;  // 0x008 [W] (DefineIDs)
    u32 m_field_00C;  // 0x00C [W] (DefineIDs)
    u32 m_field_010;  // 0x010 [W] (DefineIDs)
    u32 m_field_014;  // 0x014 [W] (DefineIDs)
    u32 m_field_018;  // 0x018 [W] (DefineIDs)
    u32 m_field_01C;  // 0x01C [W] (DefineIDs)
    u32 m_field_020;  // 0x020 [W] (DefineIDs)
    u32 m_field_024;  // 0x024 [W] (DefineIDs)
    u32 m_field_028;  // 0x028 [W] (DefineIDs)
    u32 m_field_02C;  // 0x02C [W] (DefineIDs)
    u32 m_field_030;  // 0x030 [W] (DefineIDs)
    u32 m_field_034;  // 0x034 [W] (DefineIDs)
    u8 _pad_038[0x70];  // 0x038
    u32 m_field_0A8;  // 0x0A8 [W] (AddRefAll, DelRefAll)
    u32 m_field_0AC;  // 0x0AC [R] (DefineIDs)
};

#endif // UIBUTTONIMAGES_H
