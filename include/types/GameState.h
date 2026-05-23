/* include/types/GameState.h — canonical layout for EGameState / EGameStateMan
 *
 * S18 TypeArchaeologist deliverable. Opportunistic legacy promotion of
 * include/core/gamestate.h. Top-level game-state-machine plumbing —
 * cross-class utility for ANY conversion that touches game-mode transitions
 * (Live/Build/Buy/Pause), state transitions, or the loading screen flow.
 */
#ifndef SIMS2_TYPES_GAMESTATE_H
#define SIMS2_TYPES_GAMESTATE_H

#include "../types.h"

/* Forward decls */
struct ERC;
struct EGameStateMan;
struct StateMachine;
struct StateMachineState;
struct CameraDirector;
struct ESimsCam;
struct CLoadingScreen;

/* Opaque ID typedefs */
typedef s32 EGameStateId;
typedef s32 IntroCameraStartState;
typedef s32 OVERALL_GAME_STATE;

/* ============================================================================
 * EGameState — base class for all game-state nodes
 *
 * Head size: 0x0C bytes.
 *
 * NOTE on vtable shape: m_pVtable @ +0x08 (NOT +0x00) — SN-style vtable-at-
 * end-of-head, mirrors Interactor/cXObjectImpl/ESimsCam/FastAllocPool.
 * ========================================================================== */
class EGameState {
public:
    /* 0x00 */ s32   m_stateId;
    /* 0x04 */ void* m_pManager;        /* EGameStateMan* — back-link */
    /* 0x08 */ void* m_pVtable;         /* SN-style vtable */

    EGameState(void);
    ~EGameState(void);

    void* operator new(u32 size);
    void  operator delete(void* ptr);

    void GetState(EGameStateId* pOutState);

    virtual s32  InTransportMode(void);
    virtual void PauseAllSounds(void);
    virtual void ResumeAllSounds(void);
};

/* ============================================================================
 * EGameStateMan — manages game states using a vector + linked transitions
 *
 * Head size: 0x14 bytes.
 * ========================================================================== */
class EGameStateMan {
public:
    /* 0x00 */ void* m_pCurrentState;   /* EGameState* */
    /* 0x04 */ u8    _vecData[0x0C];    /* embedded begin/end/cap vector */
    /* 0x10 */ s32   m_nextStateId;

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

/* ============================================================================
 * TheSimsStateMachine flow-state interface
 *
 * Many EGameState subclasses delegate IsFlowStateRequestPending /
 * GetFlowStateRequest / SetFlowStateCurrent to TheSimsStateMachine via
 * their m_pManager back-link (offset 0x08 in some subclasses' StateMachine
 * sub-region — legacy offsets: nextState @ +0x84, currentState @ +0x88,
 * extra state ptr @ +0x98).
 * ========================================================================== */
s32  TheSimsStateMachine_IsFlowStateRequestPending(StateMachine* pMachine);
s32  TheSimsStateMachine_GetFlowStateRequest(StateMachine* pMachine);
void TheSimsStateMachine_SetFlowStateCurrent(StateMachine* pMachine);

#endif /* SIMS2_TYPES_GAMESTATE_H */
