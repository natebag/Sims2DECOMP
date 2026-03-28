#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "types.h"

// StateMachine - struct layout extracted from assembly analysis
// Estimated minimum size: 0x98 (152 bytes)
// 25 known fields (2 named), 72 methods

class StateMachine {
public:
    // Constructors / Destructors
    StateMachine(int, int)  // 0x801DCF2C
    ~StateMachine(void);  // 0x801DD024

    // Methods
    /* ? */ GetCurStateId(void);  // 0x801DA31C (120B)
    void ReturnFromState(int);  // 0x801DA164 (440B)
    /* ? */ GetReturnVal(void);  // 0x801DD1D8 (44B)
    void ResetReturnVal(void);  // 0x801DD204 (40B)
    void Startup(void);  // 0x801DD0A0 (56B)
    void AddState(StateMachineState *);  // 0x801DA550 (112B)
    void Shutdown(void);  // 0x801DD0D8 (68B)
    void DeleteAllStates(void);  // 0x801DA5C0 (344B)
    void Reset(void);  // 0x801DD11C (56B)
    void SetNextState(int, float);  // 0x801D9DFC (384B)
    void Update(float);  // 0x801D98BC (1112B)
    void Draw(ERC *);  // 0x801D9D14 (104B)
    void CallState(int);  // 0x801D9F7C (488B)
    void DrawTopmost(ERC *);  // 0x801D9D7C (128B)
    void UnpauseUpdate(void);  // 0x801DD2A4 (40B)
    void PauseUpdate(void);  // 0x801DD27C (40B)
    /* ? */ GetTimeInState(void);  // 0x801DA718 (72B)
    bool IsEnabled(void);  // 0x801DD2CC (44B)
    bool IsPausedUpdate(void);  // 0x801DD2F8 (44B)
    void PushStatus(void);  // 0x801DA938 (152B)
    void SetState(StateMachineState *);  // 0x801DA8B8 (128B)
    void PopStatus(void);  // 0x801DA9D0 (268B)
    void FindStateById(int);  // 0x801DA760 (176B)
    /* ? */ GetCurStateStage(void);  // 0x801DA394 (84B)
    /* ? */ GetReturnStateId(void);  // 0x801DA3E8 (96B)
    /* ? */ GetLastStateId(void);  // 0x801DA448 (84B)
    /* ? */ GetCallingStateId(void);  // 0x801DA49C (84B)
    void RemoveAllStates(void);  // 0x801DA4F0 (96B)
    void FindState(StateMachineState *);  // 0x801DA810 (168B)
    /* ? */ GetMachineId(void);  // 0x801DD154 (44B)
    /* ? */ GetManager(void);  // 0x801DD180 (44B)
    /* ? */ GetFrameDeltaTime(void);  // 0x801DD1AC (44B)
    void Enable(void);  // 0x801DD22C (40B)
    void Disable(void);  // 0x801DD254 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (PushStatus, StateMachine)
    u32 m_field_004;  // 0x004 [W] (PushStatus, StateMachine)
    u32 m_field_008;  // 0x008 [W] (PushStatus, StateMachine)
    u32 m_field_00C;  // 0x00C [W] (PushStatus, StateMachine)
    f32 m_field_010;  // 0x010 [W] (PushStatus, StateMachine)
    f32 m_field_014;  // 0x014 [W] (PushStatus, StateMachine)
    u32 m_field_018;  // 0x018 [W] (StateMachine, ~StateMachine)
    u32 m_field_01C;  // 0x01C [W] (StateMachine)
    u32 m_field_020;  // 0x020 [W] (StateMachine)
    u32 m_field_024;  // 0x024 [R/W] (StateMachine, Update)
    f32 m_field_028;  // 0x028 [W] (StateMachine, Update)
    u32 m_field_02C;  // 0x02C [R/W] (AddState, DeleteAllStates, RemoveAllStates, ...)
    u32 m_field_030;  // 0x030 [R/W] (DeleteAllStates, RemoveAllStates)
    u32 m_field_034;  // 0x034 [R/W] (DeleteAllStates)
    u8 _pad_038[4];  // 0x038
    u32 m_field_03C;  // 0x03C [R/W] (PopStatus, PushStatus, StateMachine, ...)
    u32 m_field_040;  // 0x040 [R/W] (Update)
    u32 m_field_044;  // 0x044 [W] (Update)
    u8 _pad_048[4];  // 0x048
    f32 m_field_04C;  // 0x04C [R] (Update)
    u8 _pad_050[4];  // 0x050
    u32 m_field_054;  // 0x054 [W] (StateMachine)
    u8 _pad_058[0xC];  // 0x058
    u32 m_returnStateId;  // 0x064 [R/W] (GetReturnStateId, PopStatus, StateMachine)
    u8 _pad_068[0x1C];  // 0x068
    u32 m_field_084;  // 0x084 [R/W] (StateMachine, Update)
    u32 m_field_088;  // 0x088 [R/W] (StateMachine, Update)
    u32 m_field_08C;  // 0x08C [R/W] (StateMachine, Update)
    u32 m_field_090;  // 0x090 [W] (StateMachine, Update)
    u32 m_field_094;  // 0x094 [R/W] (StateMachine, Update)
};

#endif // STATEMACHINE_H
