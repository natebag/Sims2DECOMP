#ifndef ECONTROLLERMANAGER_H
#define ECONTROLLERMANAGER_H

#include "types.h"

// EControllerManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20C (524 bytes)
// 3 known fields (2 named), 100 methods

class EControllerManager {
public:
    // Constructors / Destructors
    EControllerManager(void)  // 0x808848C4
    ~EControllerManager(void);  // 0x80886D74

    // Methods
    void MapControllerCommands(EBtnToCmdAssoc *, int);  // 0x808857FC (260B)
    void MapPlayerToController(unsigned int, unsigned int);  // 0x80884A88 (296B)
    /* ? */ GetController(unsigned int);  // 0x80885000 (96B)
    /* ? */ GetPlayerControllerIndex(unsigned int);  // 0x80885060 (88B)
    /* ? */ GetCmdDownAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80886DF4 (156B)
    /* ? */ GetPlayerMapped(unsigned int);  // 0x80884FC0 (64B)
    /* ? */ GetControllerCount(void);  // 0x80886DCC (40B)
    void FindActiveController(void);  // 0x8088513C (260B)
    void SwapPlayerControls(unsigned int, unsigned int);  // 0x80884BB0 (980B)
    void UnmapPlayer(unsigned int);  // 0x80884F84 (60B)
    /* ? */ GetCmdPressedExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x8088769C (156B)
    /* ? */ GetCmdPressedAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80886E90 (156B)
    /* ? */ GetPlayerController(unsigned int);  // 0x808850B8 (132B)
    /* ? */ GetBtnPressedAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887180 (128B)
    void Init(void);  // 0x80884938 (124B)
    void Update(void);  // 0x808849B4 (180B)
    void Shutdown(void);  // 0x80884A68 (32B)
    void Flush(void);  // 0x80885240 (180B)
    /* ? */ GetCmdResultAllCtrl(unsigned int, unsigned int (EController::*);  // 0x808852F4 (624B)
    /* ? */ GetBtnResultAllCtrl(unsigned int (EController::*);  // 0x80885564 (664B)
    /* ? */ GetCmdReleasedAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80886F2C (156B)
    /* ? */ GetCmdUpAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80886FC8 (156B)
    /* ? */ GetCmdRepeatAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887064 (156B)
    /* ? */ GetBtnDownAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887100 (128B)
    /* ? */ GetBtnReleasedAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887200 (128B)
    /* ? */ GetBtnUpAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887280 (128B)
    /* ? */ GetBtnRepeatAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887300 (128B)
    /* ? */ GetBtnDownAnyAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887380 (128B)
    /* ? */ GetBtnPressedAnyAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887400 (128B)
    /* ? */ GetBtnReleasedAnyAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887480 (128B)
    /* ? */ GetBtnUpAnyAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887500 (128B)
    /* ? */ GetBtnRepeatAnyAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887580 (128B)
    /* ? */ GetCmdDownExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887600 (156B)
    /* ? */ GetCmdReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887738 (156B)
    /* ? */ GetCmdUpExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x808877D4 (156B)
    /* ? */ GetCmdRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887870 (156B)
    /* ? */ GetBtnDownExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x8088790C (128B)
    /* ? */ GetBtnPressedExlAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x8088798C (128B)
    /* ? */ GetBtnReleasedExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887A0C (128B)
    /* ? */ GetBtnUpExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887A8C (128B)
    /* ? */ GetBtnRepeatExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887B0C (128B)
    /* ? */ GetBtnDownAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887B8C (128B)
    /* ? */ GetBtnPressedAnyExlAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887C0C (128B)
    /* ? */ GetBtnReleasedAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887C8C (128B)
    /* ? */ GetBtnUpAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887D0C (128B)
    /* ? */ GetBtnRepeatAnyExclAllCtrl(unsigned int, unsigned int *, unsigned int);  // 0x80887D8C (128B)
    void BitToIndex(unsigned int);  // 0x80887E0C (92B)
    void IndexToBit(int);  // 0x80887E68 (48B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_cmdResultAllCtrl;  // 0x000 [R] (GetBtnResultAllCtrl, GetCmdResultAllCtrl)
    u32 m_cmdResultAllCtrl_004;  // 0x004 [R] (GetBtnResultAllCtrl, GetCmdResultAllCtrl)
    u8 _pad_008[0x200];  // 0x008
    u32 m_field_208;  // 0x208 [R] (Flush, Update)
};

#endif // ECONTROLLERMANAGER_H
