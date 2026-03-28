#ifndef SETVARIABLECOMMANDTABLE_H
#define SETVARIABLECOMMANDTABLE_H

#include "types.h"

// SetVariableCommandTable - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (5 named), 23 methods

class SetVariableCommandTable {
public:
    // Constructors / Destructors
    SetVariableCommandTable(void)  // 0x8047EA90
    ~SetVariableCommandTable(void);  // 0x8047EB70

    // Methods
    void Instance(void);  // 0x8047FECC (108B)
    void Shutdown(void);  // 0x8047FF38 (156B)
    void InstallCommand(char *, CBFunctor2<char *, char *> &);  // 0x8047EE50 (404B)
    void CountAndPrintCommands(void);  // 0x8047F340 (116B)
    void UnInstallAllCommands(CBFunctor2<char *, char *> &);  // 0x8047F0FC (160B)
    void AddRecord(char *, CBFunctor2<char *, char *> &);  // 0x8047EC74 (208B)
    void RemoveRecord(SetVariableCommandTable::SetVariableCommandTableRecord *);  // 0x8047ED44 (268B)
    void UnInstallCommand(char *);  // 0x8047EFE4 (280B)
    void ContainsCommand(char *);  // 0x8047F19C (136B)
    void ExecuteCommand(char *, char *, char *);  // 0x8047F224 (284B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddRecord, ContainsCommand, ExecuteCommand, ...)
    u32 m_variableCommandTable_004;  // 0x004 [R/W] (AddRecord, ExecuteCommand, RemoveRecord, ...)
    u32 m_variableCommandTable_008;  // 0x008 [R/W] (AddRecord, InstallCommand, RemoveRecord, ...)
    u32 m_variableCommandTable_00C;  // 0x00C [W] (SetVariableCommandTable, ~SetVariableCommandTable)
    u32 m_variableCommandTable_010;  // 0x010 [W] (SetVariableCommandTable)
};

#endif // SETVARIABLECOMMANDTABLE_H
