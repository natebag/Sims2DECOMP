#ifndef UIUPDATETABLE_H
#define UIUPDATETABLE_H

#include "types.h"

// UIUpdateTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 25 methods

class UIUpdateTable {
public:
    // Constructors / Destructors
    UIUpdateTable(void)  // 0x8049986C
    ~UIUpdateTable(void);  // 0x8049994C

    // Methods
    void Instance(void);  // 0x8049A2D4 (108B)
    void ExecuteUpdatesPreFlash(void);  // 0x8049A078 (140B)
    void ExecuteUpdatesPostFlash(void);  // 0x8049A104 (124B)
    void Shutdown(void);  // 0x8049A340 (156B)
    void InstallEntry(UIUpdateTable::UpdateTablePriority, CBFunctor0 &, char *);  // 0x80499D30 (404B)
    void UnInstallEntry(CBFunctor0 &);  // 0x80499EC4 (148B)
    void AddRecord(UIUpdateTable::UpdateTablePriority, CBFunctor0 &, char *);  // 0x80499A60 (440B)
    void RemoveRecord(UIUpdateTable::UpdateTableRecord *);  // 0x80499C18 (280B)
    void UnInstallAllName(char *);  // 0x80499F58 (168B)
    void ContainsEntry(CBFunctor0 &);  // 0x8049A000 (120B)
    void CountAndPrintEntries(void);  // 0x8049A180 (176B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ExecuteUpdatesPostFlash, ExecuteUpdatesPreFlash, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddRecord, ExecuteUpdatesPostFlash, ExecuteUpdatesPreFlash, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddRecord, ExecuteUpdatesPostFlash, ExecuteUpdatesPreFlash, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ExecuteUpdatesPostFlash, ExecuteUpdatesPreFlash, UIUpdateTable, ...)
    u32 m_field_010;  // 0x010 [W] (UIUpdateTable)
    u32 m_field_014;  // 0x014 [W] (UIUpdateTable)
};

#endif // UIUPDATETABLE_H
