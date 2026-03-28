#ifndef STATEMACHINEMANAGER_H
#define STATEMACHINEMANAGER_H

#include "types.h"

// StateMachineManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 24 methods

class StateMachineManager {
public:
    // Constructors / Destructors
    StateMachineManager(void)  // 0x801DD324

    // Methods
    /* ? */ GetManager(void);  // 0x8000E174 (44B)
    void AddMachine(StateMachine *);  // 0x8000E048 (300B)
    void Shutdown(void);  // 0x801DB1E8 (164B)
    void Startup(void);  // 0x801DB134 (180B)
    void FindMachineById(int);  // 0x801DAFEC (168B)
    void UpdateMachines(float);  // 0x801DB340 (216B)
    void DrawMachines(ERC *);  // 0x801DB648 (184B)
    void DrawTopmostMachines(ERC *);  // 0x801DB700 (184B)
    void FindMachine(StateMachine *);  // 0x801DB094 (160B)
    void RemoveAllMachines(void);  // 0x801DD424 (144B)
    void UpdateMachine(float);  // 0x801DB28C (180B)
    void DrawMachine(ERC *);  // 0x801DB418 (280B)
    void DrawTopmostMachine(ERC *);  // 0x801DB530 (280B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_machine;  // 0x000 [R] (DrawMachine, DrawTopmostMachine, UpdateMachine)
    u32 m_machine_004;  // 0x004 [R] (DrawMachine, DrawTopmostMachine, UpdateMachine)
};

#endif // STATEMACHINEMANAGER_H
