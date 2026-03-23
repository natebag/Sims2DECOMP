#ifndef INLEVELBASESTATE_H
#define INLEVELBASESTATE_H

#include "types.h"

// InLevelBaseState - struct layout extracted from assembly analysis
// Estimated minimum size: 0xF0 (240 bytes)
// 29 known fields (1 named), 26 methods

class InLevelBaseState {
public:
    // Constructors / Destructors
    InLevelBaseState(int)  // 0x801B1EB0
    ~InLevelBaseState(void);  // 0x801B1F24

    // Methods
    void Reset(void);  // 0x801AB764 (88B)
    void Shutdown(void);  // 0x801AB7BC (268B)
    void Update(float);  // 0x801AB8C8 (12116B)
    bool IsFlowStateRequestPending(void);  // 0x801B1F80 (80B)
    /* ? */ GetFlowStateRequest(void);  // 0x801B1FD0 (80B)
    void SetFlowStateCurrent(void);  // 0x801B2020 (72B)
    void SavePlayerInteractorState(void);  // 0x801AEB28 (248B)
    void HandleExitToMainMenu(void);  // 0x801AE81C (668B)
    void Draw(ERC *);  // 0x801AEAB8 (112B)
    void dialog_selection_callback(int);  // 0x801AEC20 (124B)
    void dialog_zero_input_callback(void);  // 0x801AEC9C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (InLevelBaseState, Update)
    u32 m_field_004;  // 0x004 [W] (InLevelBaseState, Update)
    u32 m_field_008;  // 0x008 [R/W] (InLevelBaseState, Update)
    u32 m_field_00C;  // 0x00C [W] (InLevelBaseState, Update)
    u32 m_field_010;  // 0x010 [W] (InLevelBaseState, Update)
    u32 m_field_014;  // 0x014 [W] (InLevelBaseState)
    u32 m_field_018;  // 0x018 [W] (InLevelBaseState, ~InLevelBaseState)
    u32 m_field_01C;  // 0x01C [R/W] (InLevelBaseState, Update)
    u32 m_field_020;  // 0x020 [R/W] (InLevelBaseState, Update)
    u8 _pad_024[8];  // 0x024
    u32 m_field_02C;  // 0x02C [R/W] (InLevelBaseState, Update)
    u8 _pad_030[0xC];  // 0x030
    u8 m_field_03C;  // 0x03C [R/W] (Update)
    u8 _pad_03D[3];  // 0x03D
    u32 m_field_040;  // 0x040 [R/W] (Update)
    u32 m_field_044;  // 0x044 [R/W] (Update)
    u32 m_field_048;  // 0x048 [R] (Update)
    u32 m_field_04C;  // 0x04C [R/W] (Update)
    u32 m_field_050;  // 0x050 [R/W] (Update)
    u32 m_field_054;  // 0x054 [R/W] (Update)
    u32 m_field_058;  // 0x058 [R/W] (Update)
    u32 m_field_05C;  // 0x05C [R/W] (Update)
    u32 m_field_060;  // 0x060 [R/W] (Update)
    u32 m_field_064;  // 0x064 [R/W] (Update)
    u8 _pad_068[4];  // 0x068
    u32 m_field_06C;  // 0x06C [R/W] (Update)
    u32 m_field_070;  // 0x070 [R/W] (Update)
    u32 m_field_074;  // 0x074 [R/W] (Update)
    u8 _pad_078[4];  // 0x078
    u32 m_field_07C;  // 0x07C [W] (InLevelBaseState)
    u8 _pad_080[0xC];  // 0x080
    u32 m_field_08C;  // 0x08C [W] (InLevelBaseState)
    u8 _pad_090[4];  // 0x090
    u32 m_field_094;  // 0x094 [R/W] (Update)
    u8 _pad_098[4];  // 0x098
    u32 m_field_09C;  // 0x09C [W] (InLevelBaseState)
    u8 _pad_0A0[0x4C];  // 0x0A0
    u32 m_field_0EC;  // 0x0EC [R] (Update)
};

#endif // INLEVELBASESTATE_H
