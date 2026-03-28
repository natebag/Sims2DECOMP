#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "types.h"

// Forward declarations
class ERC;
class StateMachine;
class StateMachineState;
class StateMachineManager;

// ============================================================================
// StateMachineState
// Base class for individual states in a state machine.
// Size: at least 0x20 bytes
// Offset 0x00: m_stateId (int)
// Offset 0x04: m_prevStateId (int)
// Offset 0x08: m_pOwner (StateMachine*)
// Offset 0x0C: m_stage (int)
// Offset 0x10: m_unused10 (int)
// Offset 0x14: m_active (int) - 1 = active
// Offset 0x18: m_pVtable (void*) - vtable pointer for virtual dispatch
// Offset 0x1C: m_datasetRef (void*)
// ============================================================================
class StateMachineState {
public:
    int m_stateId;          // 0x00
    int m_prevStateId;      // 0x04
    int m_unused08;         // 0x08
    int m_stage;            // 0x0C
    int m_unused10;         // 0x10
    int m_active;           // 0x14
    void* m_pVtable;        // 0x18 - derived vtable
    int m_data1C;           // 0x1C

    void OwnerSetNextState(int stateId, float delay);
    void OwnerCallState(int stateId);
    void OwnerReturnFromState(int returnVal);
    int OwnerGetReturnVal(void);
    void OwnerResetReturnVal(void);
    void ValidateHeap(bool validate);

    // Virtual functions from vtable at offset 0x18
    // Offset 0x28 in vtable: Update(float)
    // Offset 0x30 in vtable: Draw(ERC*)
    // Offset 0x38 in vtable: DrawTopmost(ERC*)

    StateMachine* GetOwner(void) const { return (StateMachine*)m_unused08; }
};

// ============================================================================
// StateMachineStatus
// Tracks current state and timing info for a state machine.
// Size: 0x18 bytes (embedded at StateMachine offset 0x3C)
// Offset 0x00: m_pCurState (StateMachineState*)
// Offset 0x04: m_pLastState (StateMachineState*)
// Offset 0x08: m_pCallingState (StateMachineState*)
// Offset 0x0C: m_stageFlags (int)
// Offset 0x10: m_secondsBeforeNextState (float)
// Offset 0x14: m_secondsInCurState (float)
// ============================================================================
class StateMachineStatus {
public:
    StateMachineState* m_pCurState;            // 0x00
    StateMachineState* m_pLastState;           // 0x04
    StateMachineState* m_pCallingState;        // 0x08
    int m_stageFlags;                          // 0x0C
    float m_secondsBeforeNextState;            // 0x10
    float m_secondsInCurState;                 // 0x14

    void StatusReset(void);
    void SetState(StateMachineState* pState);
    void ShutdownCurState(void);
    void AddToSecondsBeforeNextState(float dt);
    void AddToSecondsInCurState(float dt);
    void UpdateCurState(float dt);
    void DrawCurState(ERC* pRC);
    void DrawTopmostCurState(ERC* pRC);
};

// ============================================================================
// StateMachine
// A state machine that manages a collection of states.
// Size: 0x98 bytes
// Offset 0x1C: m_machineId (int)
// Offset 0x20: m_pManager (StateMachineManager*)
// Offset 0x24: m_pauseUpdate (int)
// Offset 0x28: m_frameDeltaTime (float)
// Offset 0x2C: m_pStatesBegin (StateMachineState**) - vector begin
// Offset 0x30: m_pStatesEnd (StateMachineState**) - vector end
// Offset 0x34-0x38: vector capacity
// Offset 0x3C: m_status (StateMachineStatus) - 0x18 bytes
// Offset 0x54-0x7C: m_statusStack (StateMachineStatus[2])
// Offset 0x84: m_pCallState (StateMachineState*)
// Offset 0x88: m_returnFlag (int)
// Offset 0x8C: m_returnStateId (int)
// Offset 0x90: m_returnVal (int)
// Offset 0x94: m_enabled (int)
// ============================================================================
class StateMachine {
public:
    char _pad00[0x1C];                         // 0x00
    int m_machineId;                           // 0x1C
    StateMachineManager* m_pManager;           // 0x20
    int m_pauseUpdate;                         // 0x24
    float m_frameDeltaTime;                    // 0x28
    StateMachineState** m_pStatesBegin;        // 0x2C
    StateMachineState** m_pStatesEnd;          // 0x30
    char _pad34[0x08];                         // 0x34 - vector capacity/etc
    StateMachineStatus m_status;               // 0x3C (0x18 bytes)
    float m_timeInState;                       // 0x50 (actually inside status area... adjusting)
    char _pad54[0x30];                         // 0x54
    StateMachineState* m_pCallState;           // 0x84
    int m_returnFlag;                          // 0x88
    int m_returnStateId;                       // 0x8C
    int m_returnVal;                           // 0x90
    int m_enabled;                             // 0x94

    StateMachine(int machineId, int param2);
    ~StateMachine(void);

    virtual void Startup(void);
    virtual void Shutdown(void);
    virtual void Reset(void);

    void Update(float dt);
    void Draw(ERC* pRC);
    void DrawTopmost(ERC* pRC);
    void SetNextState(int stateId, float delay);
    void CallState(int stateId);
    void ReturnFromState(int returnVal);
    int GetCurStateId(void) const;
    int GetCurStateStage(void) const;
    int GetReturnStateId(void) const;
    int GetLastStateId(void) const;
    int GetCallingStateId(void) const;
    float GetTimeInState(void) const;
    StateMachineState* FindStateById(int stateId);
    StateMachineState* FindState(StateMachineState* pState);
    void SetState(StateMachineState* pState);
    void RemoveAllStates(void);
    void AddState(StateMachineState* pState);
    void DeleteAllStates(void);
    void PushStatus(void);
    void PopStatus(void);

    int GetMachineId(void) const;
    StateMachineManager* GetManager(void) const;
    float GetFrameDeltaTime(void) const;
    int GetReturnVal(void) const;
    void ResetReturnVal(void);
    void Enable(void);
    void Disable(void);
    void PauseUpdate(void);
    void UnpauseUpdate(void);
    int IsEnabled(void);
    int IsPausedUpdate(void);
};

// ============================================================================
// StateMachineManager
// Manages multiple state machines (vector-based container).
// Singleton accessed via SDA r13 - 0xAC04
// ============================================================================
class StateMachineManager {
public:
    StateMachine** m_pBegin;  // 0x00
    StateMachine** m_pEnd;    // 0x04
    // 0x08: secondary vector begin
    // 0x0C: secondary vector end

    static void Startup(void);
    static void Shutdown(void);

    void UpdateMachine(float dt);
    static void UpdateMachines(float dt);
    void DrawMachine(ERC* pRC);
    void DrawTopmostMachine(ERC* pRC);
    static void DrawMachines(ERC* pRC);
    static void DrawTopmostMachines(ERC* pRC);
    StateMachine* FindMachineById(int machineId);
    StateMachine* FindMachine(StateMachine* pMachine);
};

#endif // STATEMACHINE_H
