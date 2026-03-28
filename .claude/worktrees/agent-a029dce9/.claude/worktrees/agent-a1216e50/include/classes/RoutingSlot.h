#ifndef ROUTINGSLOT_H
#define ROUTINGSLOT_H

#include "types.h"

// RoutingSlot - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3C (60 bytes)
// 15 known fields (4 named), 91 methods

class RoutingSlot {
public:
    // Constructors / Destructors
    RoutingSlot(RoutingSlot &)  // 0x8037E524
    RoutingSlot(void)  // 0x803BDEAC
    RoutingSlot(SlotDescriptor *)  // 0x803BDF78
    ~RoutingSlot(void);  // 0x803C2DAC

    // Methods
    void SnapsToDirection(void);  // 0x803C3204 (68B)
    /* ? */ GetSnapDirection(void);  // 0x803C3248 (116B)
    /* ? */ GetSnapTargetSlot(void);  // 0x803C31D8 (44B)
    /* ? */ GetIgnoreRooms(void);  // 0x803C3038 (68B)
    /* ? */ GetXOffset(void);  // 0x803C34F8 (44B)
    /* ? */ GetYOffset(void);  // 0x803C3524 (44B)
    void SetAllowFailureTrees(bool);  // 0x803C3368 (68B)
    void SetIgnoreRooms(bool);  // 0x803C307C (68B)
    /* ? */ GetAllowFailureTrees(void);  // 0x803C33AC (52B)
    bool IsFacingTowardsObject(void);  // 0x803C2F00 (60B)
    void AllowDirection(int);  // 0x803BE178 (208B)
    void AllowAnyRotation(void);  // 0x803BE248 (44B)
    void SetDistances(int, int, int);  // 0x803BE3AC (68B)
    void AllowAnyFacing(void);  // 0x803BE274 (40B)
    void SetMultiplier(RoutingSlot::VerticalPosition, int);  // 0x803BE488 (64B)
    void SetHasRandomScoring(bool);  // 0x803C3324 (68B)
    void SetResolution(int);  // 0x803C34D0 (40B)
    /* ? */ GetUseAverageObjectLocation(void);  // 0x803C349C (52B)
    bool IsAnyFacingAllowed(void);  // 0x803C2EC4 (60B)
    bool IsFacingAwayFromObject(void);  // 0x803C2F3C (60B)
    bool IsOnTopOfObject(void);  // 0x803C2DF8 (60B)
    bool IsAnyRotationAllowed(void);  // 0x803C2E80 (68B)
    /* ? */ GetFacingDirection(void);  // 0x803C2F78 (192B)
    void SetTileDistances(float, float, float);  // 0x803BE3F0 (152B)
    void SetAllowDifferentAlts(bool);  // 0x803C33E0 (68B)
    void SetIsOnTopOfObject(void);  // 0x803BE14C (44B)
    void FaceTowardsObject(void);  // 0x803BE29C (40B)
    void SetFacingDirection(int);  // 0x803BE2EC (192B)
    void WriteSlot(SlotDescriptor *);  // 0x803BE074 (216B)
    void FaceAwayFromObject(void);  // 0x803BE2C4 (40B)
    bool IsDirectionAllowed(int);  // 0x803C2E34 (76B)
    /* ? */ GetMinDist(void);  // 0x803C30C0 (44B)
    /* ? */ GetMaxDist(void);  // 0x803C30EC (44B)
    /* ? */ GetOptimalDist(void);  // 0x803C3118 (44B)
    /* ? */ GetResolution(void);  // 0x803C3144 (44B)
    /* ? */ GetGradient(void);  // 0x803C3170 (44B)
    /* ? */ GetMultiplier(RoutingSlot::VerticalPosition);  // 0x803C319C (60B)
    void Absolute(void);  // 0x803C32BC (52B)
    bool HasRandomScoring(void);  // 0x803C32F0 (52B)
    /* ? */ GetAllowDifferentAlts(void);  // 0x803C3424 (52B)
    void SetUseAverageObjectLocation(bool);  // 0x803C3458 (68B)
    /* ? */ GetAltOffset(void);  // 0x803C3550 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (RoutingSlot)
    f32 m_field_004;  // 0x004 [W] (RoutingSlot)
    f32 m_field_008;  // 0x008 [W] (RoutingSlot)
    f32 m_field_00C;  // 0x00C [W] (RoutingSlot)
    u32 m_field_010;  // 0x010 [W] (RoutingSlot)
    u32 m_field_014;  // 0x014 [W] (RoutingSlot)
    u32 m_field_018;  // 0x018 [W] (RoutingSlot)
    u32 m_field_01C;  // 0x01C [W] (RoutingSlot)
    u32 m_field_020;  // 0x020 [W] (RoutingSlot)
    u32 m_tileDistances;  // 0x024 [W] (RoutingSlot, SetTileDistances)
    u32 m_tileDistances_028;  // 0x028 [W] (RoutingSlot, SetTileDistances)
    u32 m_tileDistances_02C;  // 0x02C [W] (RoutingSlot, SetTileDistances)
    f32 m_field_030;  // 0x030 [W] (RoutingSlot)
    u32 m_field_034;  // 0x034 [W] (RoutingSlot)
    u32 m_field_038;  // 0x038 [W] (RoutingSlot)
};

#endif // ROUTINGSLOT_H
