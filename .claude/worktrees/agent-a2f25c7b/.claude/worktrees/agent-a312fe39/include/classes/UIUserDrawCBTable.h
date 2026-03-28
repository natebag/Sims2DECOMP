#ifndef UIUSERDRAWCBTABLE_H
#define UIUSERDRAWCBTABLE_H

#include "types.h"

// UIUserDrawCBTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 23 methods

class UIUserDrawCBTable {
public:
    // Constructors / Destructors
    UIUserDrawCBTable(void)  // 0x8049A434
    ~UIUserDrawCBTable(void);  // 0x8049A514

    // Methods
    void Instance(void);  // 0x8049AD98 (108B)
    void ExecuteCallback(ERC *, char *);  // 0x8049AB80 (260B)
    void UnInstallAllName(char *);  // 0x8049AA38 (168B)
    void AddRecord(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *);  // 0x8049A628 (224B)
    void RemoveRecord(UIUserDrawCBTable::UserDrawCBTableRecord *);  // 0x8049A708 (312B)
    void InstallEntry(char *, CBFunctor2<ERC *, structDrawCBparams *> *, char *);  // 0x8049A840 (392B)
    void FindEntry(char *);  // 0x8049AAE0 (160B)
    void UnInstallEntry(char *);  // 0x8049A9C8 (112B)
    void CountAndPrintEntries(void);  // 0x8049AC84 (184B)
    void Shutdown(void);  // 0x8049AE04 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ExecuteCallback, FindEntry, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddRecord, ExecuteCallback, RemoveRecord, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddRecord, InstallEntry, RemoveRecord, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ExecuteCallback, UIUserDrawCBTable, ~UIUserDrawCBTable)
    u32 m_field_010;  // 0x010 [W] (UIUserDrawCBTable)
    u32 m_field_014;  // 0x014 [W] (UIUserDrawCBTable)
};

#endif // UIUSERDRAWCBTABLE_H
