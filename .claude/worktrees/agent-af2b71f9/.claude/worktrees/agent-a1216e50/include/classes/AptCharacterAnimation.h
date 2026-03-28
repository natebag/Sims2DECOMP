#ifndef APTCHARACTERANIMATION_H
#define APTCHARACTERANIMATION_H

#include "types.h"

// AptCharacterAnimation - struct layout extracted from assembly analysis
// Estimated minimum size: 0x50 (80 bytes)
// 13 known fields (3 named), 20 methods

class AptCharacterAnimation {
public:
    // Methods
    void Fixup(void *, AptConstFile *, void *);  // 0x806BE2BC (5500B)
    void Resolve(void *, AptConstFile *, void *);  // 0x806BF838 (276B)
    void UnmapCharacter(AptCharacter *);  // 0x806BF94C (220B)
    bool IsImport(int);  // 0x806BFA28 (144B)
    void Unresolve(void *);  // 0x806BFAB8 (4092B)
    void Link(AptCharacter *, void *);  // 0x806C0CA8 (1332B)
    /* ? */ GetIDFromImportFile(int);  // 0x806C2EA4 (264B)
    void ExecuteInitActions(AptCIH *, int);  // 0x806C2FAC (488B)
    void ExecuteInitAction(AptCIH *, int);  // 0x806C3194 (396B)
    void ExportClassDefinitionAssets(AptCIH *);  // 0x806C3320 (568B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_bIsImport;  // 0x000 [R] (Fixup, IsImport, UnmapCharacter, ...)
    u32 m_field_004;  // 0x004 [R] (ExecuteInitAction, ExportClassDefinitionAssets)
    u32 m_field_008;  // 0x008 [R/W] (Fixup, Unresolve)
    u32 m_field_00C;  // 0x00C [R] (Fixup, Link, UnmapCharacter, ...)
    u32 m_field_010;  // 0x010 [R/W] (ExecuteInitActions, Fixup, Link, ...)
    u8 _pad_014[4];  // 0x014
    u32 m_field_018;  // 0x018 [R] (Unresolve)
    u8 _pad_01C[4];  // 0x01C
    u32 m_bIsImport_020;  // 0x020 [R] (Fixup, IsImport, Link, ...)
    u32 m_iDFromImportFile;  // 0x024 [R/W] (ExecuteInitActions, Fixup, GetIDFromImportFile, ...)
    u32 m_field_028;  // 0x028 [R] (ExportClassDefinitionAssets, Fixup, Unresolve)
    u32 m_field_02C;  // 0x02C [R/W] (ExportClassDefinitionAssets, Fixup, Unresolve)
    u32 m_field_030;  // 0x030 [R/W] (Resolve, Unresolve)
    u32 m_field_034;  // 0x034 [R/W] (Fixup, Unresolve)
    u8 _pad_038[0x14];  // 0x038
    u32 m_field_04C;  // 0x04C [R] (ExecuteInitAction, ExportClassDefinitionAssets)
};

#endif // APTCHARACTERANIMATION_H
