#ifndef ARCFILEINFO_H
#define ARCFILEINFO_H

#include "types.h"

// ArcFileInfo - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 7 known fields (2 named), 26 methods

class ArcFileInfo {
public:
    // Constructors / Destructors
    ArcFileInfo(void)  // 0x80878290

    // Methods
    void Initialize(char *, char *);  // 0x808782E0 (80B)
    void OnValidated(void);  // 0x80878330 (304B)
    void Validate(void);  // 0x80878460 (1176B)
    void Reset(void);  // 0x808788F8 (384B)
    void CopyArcFile(void);  // 0x80878A78 (404B)
    bool IsUpToDate(void);  // 0x80878C0C (76B)
    bool IsOpen(void);  // 0x80878C58 (184B)
    bool IsUsingHDD(void);  // 0x80878D10 (184B)
    void CompareName(char *);  // 0x80878DC8 (124B)
    /* ? */ GetName(void);  // 0x80878E44 (44B)
    /* ? */ GetSourceLen(void);  // 0x80878E70 (44B)
    /* ? */ GetCopiedSize(void);  // 0x80878E9C (44B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_bIsUsingHDD;  // 0x000 [R] (CompareName, CopyArcFile, IsOpen, ...)
    u32 m_bIsUsingHDD_004;  // 0x004 [R] (CopyArcFile, IsOpen, IsUsingHDD, ...)
    u32 m_field_008;  // 0x008 [R/W] (CopyArcFile, Validate)
    u32 m_field_00C;  // 0x00C [W] (Reset, Validate)
    u32 m_field_010;  // 0x010 [R/W] (CopyArcFile, OnValidated, Reset, ...)
    u32 m_field_014;  // 0x014 [R] (Validate)
    u8 _pad_018[0x10];  // 0x018
    u32 m_field_028;  // 0x028 [R] (Reset)
};

#endif // ARCFILEINFO_H
