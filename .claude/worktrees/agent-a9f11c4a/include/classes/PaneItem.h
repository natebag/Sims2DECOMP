#ifndef PANEITEM_H
#define PANEITEM_H

#include "types.h"

// PaneItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 3 known fields (3 named), 60 methods

class PaneItem {
public:
    // Constructors / Destructors
    PaneItem(ItemType)  // 0x801A18F0
    ~PaneItem(void);  // 0x801A1984

    // Methods
    void SetDrawBeforeApt(bool);  // 0x80188B0C (72B)
    void Enable(bool);  // 0x80193A64 (72B)
    void Disable(void);  // 0x80193AAC (44B)
    void SetValue(int);  // 0x80193B08 (40B)
    bool IsEnabled(void);  // 0x80193AD8 (48B)
    void Startup(void);  // 0x8019C3A4 (32B)
    bool IsSelected(void);  // 0x8019C84C (52B)
    void SetDirtySize(bool);  // 0x8019C8B4 (72B)
    bool IsWaitingToReset(void);  // 0x8019C944 (52B)
    bool IsGotAptPosX(void);  // 0x8019CA08 (52B)
    bool IsGotAptPosY(void);  // 0x8019CA3C (52B)
    void SetWaitingToReset(bool);  // 0x8019C8FC (72B)
    bool IsDrawBeforeApt(void);  // 0x8019C880 (52B)
    bool IsType(ItemType);  // 0x8019CBB0 (60B)
    void Deselect(void);  // 0x8019C820 (44B)
    void Select(void);  // 0x8019C7F4 (44B)
    /* ? */ GetValue(void);  // 0x8019C4D0 (44B)
    void SetPosXDirty(bool);  // 0x8019CA70 (72B)
    void SetPosYDirty(bool);  // 0x8019CAB8 (72B)
    bool IsPosXDirty(void);  // 0x8019CB48 (52B)
    void SetGotAptPosX(bool);  // 0x8019C978 (72B)
    bool IsPosYDirty(void);  // 0x8019CB7C (52B)
    void SetGotAptPosY(bool);  // 0x8019C9C0 (72B)
    void SetWidthDirty(bool);  // 0x8019CB00 (72B)
    void Reset(void);  // 0x8019C3E4 (40B)
    void CalculateSize(void);  // 0x8019C40C (32B)
    void SetPos(EVec2 &);  // 0x8019C4FC (60B)
    /* ? */ GetPos(void);  // 0x8019C538 (44B)
    void SetPosX(float);  // 0x8019C564 (40B)
    /* ? */ GetPosX(void);  // 0x8019C58C (44B)
    void SetPosY(float);  // 0x8019C5B8 (40B)
    /* ? */ GetPosY(void);  // 0x8019C5E0 (44B)
    void SetSize(EVec2 &);  // 0x8019C60C (72B)
    /* ? */ GetSize(void);  // 0x8019C654 (104B)
    void SetSizeX(float);  // 0x8019C6BC (52B)
    /* ? */ GetSizeX(void);  // 0x8019C6F0 (104B)
    void SetSizeY(float);  // 0x8019C758 (52B)
    /* ? */ GetSizeY(void);  // 0x8019C78C (104B)
    void Shutdown(void);  // 0x8019C3C4 (32B)
    void Draw(ERC *, float);  // 0x801A2294 (40B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x14];  // 0x000
    f32 m_sizeX;  // 0x014 [R] (GetSizeX)
    f32 m_sizeY;  // 0x018 [R] (GetSizeY)
    u32 m_size;  // 0x01C [R/W] (GetSize, GetSizeX, GetSizeY, ...)
};

#endif // PANEITEM_H
