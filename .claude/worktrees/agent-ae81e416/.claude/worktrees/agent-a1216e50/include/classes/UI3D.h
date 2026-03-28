#ifndef UI3D_H
#define UI3D_H

#include "types.h"

// UI3D - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 10 known fields (1 named), 27 methods

class UI3D {
public:
    // Constructors / Destructors
    UI3D(void)  // 0x80479954
    ~UI3D(void);  // 0x80479AC4

    // Methods
    void Instance(void);  // 0x8047A768 (108B)
    /* ? */ GetDisplayObject(char *);  // 0x8047A53C (108B)
    void Update3D(void);  // 0x8047A4D8 (100B)
    void AddEntry(char *, unsigned int, unsigned int, unsigned int, int, char *);  // 0x80479BF0 (704B)
    void RemoveEntry(UI3D::UI3DRecord *);  // 0x80479EB0 (432B)
    void InstallEntry(char *, unsigned int, unsigned int, unsigned int, char *, int);  // 0x8047A060 (368B)
    void FindEntry(char *);  // 0x8047A1D0 (304B)
    void UnInstallEntry(char *);  // 0x8047A300 (220B)
    void UnInstallAllEntries(char *);  // 0x8047A3DC (160B)
    void ContainsEntry(char *);  // 0x8047A47C (92B)
    void CountAndPrintEntries(void);  // 0x8047A5A8 (192B)
    void Shutdown(void);  // 0x8047A7D4 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddEntry, FindEntry, RemoveEntry, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddEntry, FindEntry, RemoveEntry, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddEntry, InstallEntry, RemoveEntry, ...)
    u32 m_field_00C;  // 0x00C [R/W] (InstallEntry, UI3D)
    u32 m_field_010;  // 0x010 [R/W] (InstallEntry, UI3D)
    u32 m_field_014;  // 0x014 [R/W] (InstallEntry, UI3D)
    u32 m_field_018;  // 0x018 [W] (UI3D)
    u32 m_field_01C;  // 0x01C [R/W] (InstallEntry, UI3D, ~UI3D)
    u32 m_field_020;  // 0x020 [W] (UI3D)
    u32 m_field_024;  // 0x024 [W] (UI3D)
};

#endif // UI3D_H
