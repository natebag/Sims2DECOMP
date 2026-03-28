#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "types.h"

// Forward declarations
class ERC;
class EGameState;
class EGameStateMan;
class StateMachine;
class StateMachineState;
class CameraDirector;
class ESimsCam;
class CLoadingScreen;

// EGameStateId - state identifiers
typedef int EGameStateId;

// IntroCameraStartState enum
typedef int IntroCameraStartState;

// OVERALL_GAME_STATE
typedef int OVERALL_GAME_STATE;

// ============================================================================
// EGameState
// Base class for all game states.
// Size: at least 0x0C bytes
// Offset 0x00: m_stateId (int)
// Offset 0x04: m_pManager (EGameStateMan*)
// Offset 0x08: m_pVtable (void*)
// ============================================================================
class EGameState {
public:
    int m_stateId;           // 0x00
    void* m_pManager;        // 0x04
    void* m_pVtable;         // 0x08 - vtable

    EGameState(void);
    ~EGameState(void);

    void* operator new(unsigned int size);
    void operator delete(void* ptr);

    void GetState(EGameStateId* pOutState);
    virtual int InTransportMode(void);
    virtual void PauseAllSounds(void);
    virtual void ResumeAllSounds(void);
};

// ============================================================================
// EGameStateMan
// Manages game states using a vector + linked state transitions.
// Size: at least 0x14 bytes
// Offset 0x00: m_pCurrentState (EGameState*)
// Offset 0x04: m_statesVector (begin)
// Offset 0x08: m_statesVector (end)
// Offset 0x0C: m_statesVector (flag/capacity)
// Offset 0x10: m_nextStateId (int)
// ============================================================================
class EGameStateMan {
public:
    void* m_pCurrentState;   // 0x00
    char _vecData[0x0C];     // 0x04 - vector
    int m_nextStateId;       // 0x10

    EGameStateMan(void);
    ~EGameStateMan(void);

    void SetState(EGameStateId stateId);
    void AddState(EGameState* pState);
    void KillState(void);
    void SoftReset(void);
    void DeleteAllStates(void);
    void Update(void);
    void Draw(ERC* pRC);
};

// ============================================================================
// TheSimsStateMachine flow state interface
// Many state classes delegate IsFlowStateRequestPending/GetFlowStateRequest/
// SetFlowStateCurrent to TheSimsStateMachine via their m_pOwner (offset 0x08).
// ============================================================================

// TheSimsStateMachine - at offset 0x98 has m_pCallState
// Offset 0x84: nextState
// Offset 0x88: currentState
// Offset 0x98: extra state ptr
int TheSimsStateMachine_IsFlowStateRequestPending(StateMachine* pMachine);
int TheSimsStateMachine_GetFlowStateRequest(StateMachine* pMachine);
void TheSimsStateMachine_SetFlowStateCurrent(StateMachine* pMachine);

#endif // GAMESTATE_H
