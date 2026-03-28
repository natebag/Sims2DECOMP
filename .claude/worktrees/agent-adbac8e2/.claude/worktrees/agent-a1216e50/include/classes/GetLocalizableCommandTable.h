#ifndef GETLOCALIZABLECOMMANDTABLE_H
#define GETLOCALIZABLECOMMANDTABLE_H

#include "types.h"

// GetLocalizableCommandTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (5 named), 23 methods

class GetLocalizableCommandTable {
public:
    // Constructors / Destructors
    GetLocalizableCommandTable(void)  // 0x8047F3B4
    ~GetLocalizableCommandTable(void);  // 0x8047F494

    // Methods
    void Instance(void);  // 0x80480028 (108B)
    void ExecuteCommand(char *, char *);  // 0x8047FB48 (292B)
    void UnInstallAllCommands(CBFunctor1wRet<char *, unsigned wchar_t *> &);  // 0x8047FA20 (160B)
    void AddRecord(char *, CBFunctor1wRet<char *, unsigned wchar_t *> &);  // 0x8047F598 (208B)
    void RemoveRecord(GetLocalizableCommandTable::GetLocalizableCommandTableRecord *);  // 0x8047F668 (268B)
    void InstallCommand(char *, CBFunctor1wRet<char *, unsigned wchar_t *> &);  // 0x8047F774 (404B)
    void UnInstallCommand(char *);  // 0x8047F908 (280B)
    void ContainsCommand(char *);  // 0x8047FAC0 (136B)
    void CountAndPrintCommands(void);  // 0x8047FC6C (176B)
    void Shutdown(void);  // 0x80480094 (156B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ContainsCommand, ExecuteCommand, ...)
    u32 m_localizableCommandTable_004;  // 0x004 [R/W] (AddRecord, ExecuteCommand, GetLocalizableCommandTable, ...)
    u32 m_localizableCommandTable_008;  // 0x008 [R/W] (AddRecord, GetLocalizableCommandTable, InstallCommand, ...)
    u32 m_localizableCommandTable_00C;  // 0x00C [W] (GetLocalizableCommandTable, ~GetLocalizableCommandTable)
    u32 m_localizableCommandTable_010;  // 0x010 [W] (GetLocalizableCommandTable)
};

#endif // GETLOCALIZABLECOMMANDTABLE_H
