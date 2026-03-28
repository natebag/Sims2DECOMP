#ifndef LIVEMODEINITSTATE_H
#define LIVEMODEINITSTATE_H

#include "types.h"

// LiveModeInitState - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 5 known fields (0 named), 18 methods

class LiveModeInitState {
public:
    // Constructors / Destructors
    LiveModeInitState(int)  // 0x801BFD28
    ~LiveModeInitState(void);  // 0x801BE4E4

    // Methods
    void Shutdown(void);  // 0x801B2E58 (124B)
    void Reset(void);  // 0x801B2ED4 (488B)
    void Update(float);  // 0x801B30BC (7412B)
    void DatasetPendingAddRefAsync(void);  // 0x801BFD9C (60B)
    void DatasetFinishAddRefAsync(void);  // 0x801B4ED0 (72B)
    void Draw(ERC *);  // 0x801B4DB0 (72B)
    void DatasetGetRef(void);  // 0x801B4DF8 (216B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Update)
    s16 m_field_004;  // 0x004 [R] (Update)
    u8 _pad_006[6];  // 0x006
    u32 m_field_00C;  // 0x00C [R/W] (Reset, Update)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R/W] (DatasetGetRef, Reset, Update)
    u8 _pad_020[4];  // 0x020
    u32 m_field_024;  // 0x024 [R] (Update)
};

#endif // LIVEMODEINITSTATE_H
