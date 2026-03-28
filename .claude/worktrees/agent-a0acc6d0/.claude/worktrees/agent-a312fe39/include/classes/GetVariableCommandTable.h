#ifndef GETVARIABLECOMMANDTABLE_H
#define GETVARIABLECOMMANDTABLE_H

#include "types.h"

// GetVariableCommandTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (5 named), 23 methods

class GetVariableCommandTable {
public:
    // Constructors / Destructors
    GetVariableCommandTable(void)  // 0x8047E164
    ~GetVariableCommandTable(void);  // 0x8047E244

    // Methods
    void Instance(void);  // 0x8047FD70 (108B)
    void Shutdown(void);  // 0x8047FDDC (156B)
    void InstallCommand(char *, CBFunctor1wRet<char *, char *> &);  // 0x8047E524 (404B)
    void CountAndPrintCommands(void);  // 0x8047EA1C (116B)
    void UnInstallAllCommands(CBFunctor1wRet<char *, char *> &);  // 0x8047E7D0 (160B)
    void AddRecord(char *, CBFunctor1wRet<char *, char *> &);  // 0x8047E348 (208B)
    void RemoveRecord(GetVariableCommandTable::GetVariableCommandTableRecord *);  // 0x8047E418 (268B)
    void UnInstallCommand(char *);  // 0x8047E6B8 (280B)
    void ContainsCommand(char *);  // 0x8047E870 (136B)
    void ExecuteCommand(char *, char *);  // 0x8047E8F8 (292B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ContainsCommand, ExecuteCommand, ...)
    u32 m_variableCommandTable_004;  // 0x004 [R/W] (AddRecord, ExecuteCommand, GetVariableCommandTable, ...)
    u32 m_variableCommandTable_008;  // 0x008 [R/W] (AddRecord, GetVariableCommandTable, InstallCommand, ...)
    u32 m_variableCommandTable_00C;  // 0x00C [W] (GetVariableCommandTable, ~GetVariableCommandTable)
    u32 m_variableCommandTable_010;  // 0x010 [W] (GetVariableCommandTable)
};

#endif // GETVARIABLECOMMANDTABLE_H
