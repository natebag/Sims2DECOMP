#ifndef UIDRAWTABLE_H
#define UIDRAWTABLE_H

#include "types.h"

// UIDrawTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 6 known fields (1 named), 25 methods

class UIDrawTable {
public:
    // Constructors / Destructors
    UIDrawTable(void)  // 0x80486A00
    ~UIDrawTable(void);  // 0x80486AE0

    // Methods
    void Instance(void);  // 0x80487420 (108B)
    void ExecuteDrawsPreFlash(ERC *);  // 0x8048720C (132B)
    void ExecuteDrawsPostFlash(ERC *);  // 0x80487290 (132B)
    void Shutdown(void);  // 0x8048748C (156B)
    void UnInstallEntry(CBFunctor1<ERC *> &);  // 0x80487058 (148B)
    void InstallEntry(UIDrawTable::DrawTablePriority, CBFunctor1<ERC *> &, char *);  // 0x80486EC4 (404B)
    void AddRecord(UIDrawTable::DrawTablePriority, CBFunctor1<ERC *> &, char *);  // 0x80486BF4 (440B)
    void RemoveRecord(UIDrawTable::DrawTableRecord *);  // 0x80486DAC (280B)
    void UnInstallAllName(char *);  // 0x804870EC (168B)
    void ContainsEntry(CBFunctor1<ERC *> &);  // 0x80487194 (120B)
    void CountAndPrintEntries(void);  // 0x80487314 (176B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ExecuteDrawsPostFlash, ExecuteDrawsPreFlash, ...)
    u32 m_field_004;  // 0x004 [R/W] (AddRecord, ExecuteDrawsPostFlash, ExecuteDrawsPreFlash, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddRecord, ExecuteDrawsPostFlash, ExecuteDrawsPreFlash, ...)
    u32 m_field_00C;  // 0x00C [R/W] (ExecuteDrawsPostFlash, ExecuteDrawsPreFlash, UIDrawTable, ...)
    u32 m_field_010;  // 0x010 [W] (UIDrawTable)
    u32 m_field_014;  // 0x014 [W] (UIDrawTable)
};

#endif // UIDRAWTABLE_H
