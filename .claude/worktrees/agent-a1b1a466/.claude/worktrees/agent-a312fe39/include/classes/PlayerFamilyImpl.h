#ifndef PLAYERFAMILYIMPL_H
#define PLAYERFAMILYIMPL_H

#include "types.h"

// PlayerFamilyImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0xD68 (3432 bytes)
// 3 known fields (1 named), 26 methods

class PlayerFamilyImpl {
public:
    // Constructors / Destructors
    PlayerFamilyImpl(int)  // 0x803839BC
    ~PlayerFamilyImpl(void);  // 0x80383A50

    // Methods
    /* ? */ GetInventory(void);  // 0x80386048 (44B)
    void ClearFamily(void);  // 0x80383ACC (164B)
    void DoStream(ReconBuffer *, int);  // 0x80383B70 (336B)
    /* ? */ GetStatValue(int);  // 0x80383CC0 (104B)
    /* ? */ GetStatRef(int, short **);  // 0x80383D28 (144B)
    /* ? */ GetResfileStorageId(short);  // 0x80385FE8 (52B)
    /* ? */ GetGoalAndUnlockData(void);  // 0x80386074 (44B)
    /* ? */ GetClothingUnlocks(void);  // 0x8038601C (44B)
    /* ? */ GetTotalAspirationScore(void);  // 0x803860A0 (44B)
    void SetTotalAspirationScore(int);  // 0x803860CC (40B)
    void ConvertToRegularFamilyOnWrite(void);  // 0x803860F4 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ClearFamily, PlayerFamilyImpl, ~PlayerFamilyImpl)
    u8 _pad_004[0xD5C];  // 0x004
    u32 m_field_D60;  // 0xD60 [W] (ClearFamily, DoStream)
    u32 m_field_D64;  // 0xD64 [W] (PlayerFamilyImpl)
};

#endif // PLAYERFAMILYIMPL_H
