#ifndef CREATEASIMBASESTATE_H
#define CREATEASIMBASESTATE_H

#include "types.h"

// CreateASimBaseState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1634 (5684 bytes)
// 8 known fields (0 named), 28 methods

class CreateASimBaseState {
public:
    // Constructors / Destructors
    CreateASimBaseState(int)  // 0x801A6EC8
    ~CreateASimBaseState(void);  // 0x801A64E8

    // Methods
    void Startup(void);  // 0x801A2C94 (344B)
    void Shutdown(void);  // 0x801A2DEC (260B)
    void Reset(void);  // 0x801A2EF0 (128B)
    /* ? */ GetDatasetName(char *);  // 0x801A2F70 (68B)
    void Update(float);  // 0x801A2FB4 (2716B)
    bool IsFlowStateRequestPending(void);  // 0x801A6FD8 (80B)
    /* ? */ GetFlowStateRequest(void);  // 0x801A7028 (80B)
    void SetFlowStateCurrent(void);  // 0x801A7078 (72B)
    void OnBackOut(void);  // 0x801A3A50 (528B)
    void Draw(ERC *);  // 0x801A3C60 (72B)
    void CASAccepted(void);  // 0x801A6F48 (72B)
    void CASCanceled(void);  // 0x801A6F90 (72B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[8];  // 0x000
    u32 m_field_008;  // 0x008 [R] (OnBackOut, Update)
    u32 m_field_00C;  // 0x00C [R/W] (Reset, Update)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (Reset, Update)
    u32 m_field_020;  // 0x020 [R/W] (Reset, Update)
    u32 m_field_024;  // 0x024 [R/W] (Shutdown, Update)
    u32 m_field_028;  // 0x028 [W] (Reset, Update)
    u32 m_field_02C;  // 0x02C [W] (OnBackOut, Reset, Update)
    u8 _pad_030[0x1600];  // 0x030
    u32 m_field_1630;  // 0x1630 [R] (OnBackOut)
};

#endif // CREATEASIMBASESTATE_H
