#ifndef UI2D_H
#define UI2D_H

#include "types.h"

// UI2D - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5C (92 bytes)
// 14 known fields (3 named), 28 methods

class UI2D {
public:
    // Constructors / Destructors
    UI2D(void)  // 0x80478708
    ~UI2D(void);  // 0x804787E8

    // Methods
    void Instance(void);  // 0x804797F4 (108B)
    /* ? */ GetShader(char *);  // 0x80479398 (784B)
    void InstallEntry(char *, unsigned int, char *, int);  // 0x80478E34 (268B)
    void AddEntry(char *, unsigned int, ERShader *, char *, int);  // 0x804788FC (724B)
    void RemoveEntry(UI2D::UI2DRecord *);  // 0x80478BD0 (612B)
    void FindEntry(char *);  // 0x80479078 (304B)
    void InstallEntry(char *, ERShader *, char *, int);  // 0x80478F40 (312B)
    void UnInstallEntry(char *);  // 0x804791A8 (244B)
    void CountAndPrintEntries(void);  // 0x804796A8 (192B)
    void UnInstallAllEntries(char *);  // 0x8047929C (160B)
    void ContainsEntry(char *);  // 0x8047933C (92B)
    void Shutdown(void);  // 0x80479860 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddEntry, FindEntry, RemoveEntry, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddEntry, FindEntry, RemoveEntry, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddEntry, InstallEntry, RemoveEntry, ...)
    u32 m_field_00C;  // 0x00C [W] (UI2D, ~UI2D)
    u32 m_field_010;  // 0x010 [W] (UI2D)
    u32 m_field_014;  // 0x014 [W] (UI2D)
    u32 m_field_018;  // 0x018 [W] (UI2D)
    u32 m_field_01C;  // 0x01C [W] (UI2D)
    u32 m_field_020;  // 0x020 [W] (UI2D)
    u32 m_field_024;  // 0x024 [W] (UI2D)
    u32 m_field_028;  // 0x028 [W] (UI2D)
    u32 m_field_02C;  // 0x02C [W] (UI2D)
    u8 _pad_030[0xC];  // 0x030
    u32 m_shader;  // 0x03C [R] (AddEntry, GetShader)
    u8 _pad_040[0x18];  // 0x040
    u32 m_shader_058;  // 0x058 [R] (AddEntry, GetShader)
};

#endif // UI2D_H
