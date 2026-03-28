#ifndef TREETABLEENTRY_H
#define TREETABLEENTRY_H

#include "types.h"

// TreeTableEntry - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 34 methods

class TreeTableEntry {
public:
    // Methods
    /* ? */ GetAttenuationValue(bool);  // 0x803D0A28 (88B)
    void CountAds(void);  // 0x80404990 (40B)
    /* ? */ GetAdByID(int);  // 0x804049B8 (236B)
    /* ? */ GetName(void);  // 0x80404AA4 (44B)
    /* ? */ GetIndex(void);  // 0x80407DB0 (48B)
    /* ? */ GetOrderIndex(void);  // 0x80407D80 (48B)
    /* ? */ GetAvailableToVisitors(void);  // 0x80407DE0 (68B)
    /* ? */ GetCanJoin(void);  // 0x80407E24 (52B)
    /* ? */ GetImmediate(void);  // 0x80407E58 (52B)
    /* ? */ GetAllowConsecutive(void);  // 0x80407E8C (52B)
    /* ? */ GetAvailableToGhosts(void);  // 0x80407EC0 (52B)
    /* ? */ GetAvailableToAdults(void);  // 0x80407EF4 (56B)
    /* ? */ GetAvailableToChildrenDemo(void);  // 0x80407F2C (52B)
    /* ? */ GetJoinIndex(void);  // 0x80407F60 (48B)
    /* ? */ GetDebugOnly(void);  // 0x80407F90 (116B)
    /* ? */ GetAutoFirstSelect(void);  // 0x80408004 (52B)
    /* ? */ GetAvailableToVisitingPlayers(void);  // 0x80408038 (52B)
    /* ? */ GetManualOnly(void);  // 0x80408108 (60B)
    /* ? */ GetIgnorePrefixTree(void);  // 0x8040806C (52B)
    /* ? */ GetMustRun(void);  // 0x804080A0 (52B)
    /* ? */ GetRangeRef(int);  // 0x804081E0 (84B)
    /* ? */ GetMinRef(int);  // 0x80408234 (84B)
    /* ? */ GetPersonalityVarRef(int);  // 0x80408288 (80B)
    /* ? */ GetActionTreeID(void);  // 0x804082D8 (48B)
    /* ? */ GetCheckTreeID(void);  // 0x80408308 (48B)
    /* ? */ GetAttenuation(void);  // 0x80408338 (44B)
    /* ? */ GetCustomAttenuationValue(void);  // 0x80408394 (44B)
    /* ? */ GetAutonomyThreshold(void);  // 0x80408364 (48B)
    /* ? */ GetFlags(void);  // 0x804083C0 (44B)
    /* ? */ GetUseCustomActivation(void);  // 0x804080D4 (52B)
    /* ? */ GetActivationSubtile(unsigned char &, unsigned char &);  // 0x804083EC (76B)
    /* ? */ GetActivationExtents(unsigned char &, unsigned char &, unsigned char &, unsigned char &);  // 0x80408438 (124B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_adByID;  // 0x004 [R] (GetAdByID)
    s16 m_adByID_006;  // 0x006 [R] (GetAdByID)
};

#endif // TREETABLEENTRY_H
