#ifndef FAMTARGET_H
#define FAMTARGET_H

#include "types.h"

// FAMTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x450 (1104 bytes)
// 47 known fields (24 named), 104 methods

class FAMTarget {
public:
    // Constructors / Destructors
    FAMTarget(void)  // 0x804F8790
    ~FAMTarget(void);  // 0x804F9258

    // Methods
    void OnReturnFromCreateAFamily(bool);  // 0x804FBF5C (280B)
    void UnloadScreen(void);  // 0x804F92D4 (76B)
    void UpdateText(void);  // 0x804FA484 (2996B)
    void UpdateShaders(void);  // 0x804FB088 (116B)
    void UpdateMenuState(FAMTarget::FAM_STATE);  // 0x804FDAC4 (1096B)
    void SetVariable(char *, char *);  // 0x804F9320 (720B)
    void Shutdown(void);  // 0x804FA3E8 (32B)
    void UpdateMenuState(char *, char *);  // 0x804FA428 (92B)
    void SetCurrentChoice(char *);  // 0x804FEAD0 (348B)
    void OnLeftKeyPressed(char *, char *);  // 0x804FB038 (40B)
    void OnRightKeyPressed(char *, char *);  // 0x804FB060 (40B)
    void OnXKeyPressed(char *, char *);  // 0x804FC6F4 (5024B)
    void OnCancelKeyPressed(char *, char *);  // 0x804FC0C4 (640B)
    void OnUpKeyPressed(char *, char *);  // 0x804FC344 (476B)
    void OnDownKeyPressed(char *, char *);  // 0x804FC520 (468B)
    /* ? */ GetLocalizable(char *);  // 0x804F95F0 (3032B)
    void ConvertSelectedLotIndexToActualGameIndex(int);  // 0x804FDFB0 (80B)
    /* ? */ GetLotName(int);  // 0x804FE8D0 (128B)
    /* ? */ GetSelectedLotDescription(unsigned wchar_t *);  // 0x804FE6E0 (148B)
    /* ? */ GetMoneyForLot(int);  // 0x804FED2C (192B)
    /* ? */ GetFamilyInLot(int);  // 0x804FEC2C (160B)
    /* ? */ GetMoneyForFamilyInLotSelect(char *, unsigned wchar_t *);  // 0x804FE280 (320B)
    void ConvertNumericMoneyToString(int, unsigned wchar_t *);  // 0x804FE774 (116B)
    /* ? */ GetNameForFamilyInLotSelect(char *, unsigned wchar_t *);  // 0x804FE08C (500B)
    /* ? */ GetFamilyText(char *, unsigned wchar_t *);  // 0x804FB690 (488B)
    /* ? */ GetLotNameInFamilySelect(char *);  // 0x804FEFF0 (328B)
    /* ? */ GetNameForFamily(Family *, unsigned wchar_t *);  // 0x804FE950 (384B)
    /* ? */ GetVariable(char *);  // 0x804FA1C8 (544B)
    /* ? */ GetLotForFamily(int);  // 0x804FEF74 (124B)
    void Update(void);  // 0x804FA408 (32B)
    void UpdateLotSelectShaders(void);  // 0x804FB350 (684B)
    void UpdateFamilySelectShaders(void);  // 0x804FE3C0 (800B)
    void UpdateOccupiedShaders(void);  // 0x804FB0FC (596B)
    void UpdateTempShaders(void);  // 0x804FB5FC (148B)
    void ConvertSelectedFamilyIndexToActualGameIndex(int);  // 0x804FBA18 (52B)
    /* ? */ GetMoneyForFamily(Family *, unsigned wchar_t *);  // 0x804FE7E8 (232B)
    void OnLotSelect(void);  // 0x804FB878 (96B)
    bool IsSelectedLotOccupied(void);  // 0x804FBADC (204B)
    /* ? */ GetFamilyInFamilyList(int);  // 0x804FB8D8 (152B)
    void DoesFamilyExistInFamilyChoice(int);  // 0x804FB970 (168B)
    /* ? */ GetNumberOfFamilyMembers(Family *);  // 0x804FBA4C (144B)
    void OnCancelDialog(void);  // 0x804FBBA8 (64B)
    void OnDialogSelection(int);  // 0x804FBBE8 (884B)
    void EvictFamily(void);  // 0x804FEDEC (132B)
    void GoUpMenuTree(void);  // 0x804FE000 (140B)
    void OnBackoutToMainMenuDialogClose(int);  // 0x804FC074 (80B)
    /* ? */ GetNumberOfChoicesInState(FAMTarget::FAM_STATE);  // 0x804FDF0C (164B)
    void LaunchLot(void);  // 0x804FECCC (96B)
    void OnCircleKeyPressed(char *, char *);  // 0x804FDA94 (48B)
    /* ? */ GetLotForFamily(Family *);  // 0x804FEE70 (260B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_nameForFamilyInLotSelect;  // 0x000 [R/W] (FAMTarget, GetLocalizable, GetMoneyForFamily, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (FAMTarget, GetVariable, OnXKeyPressed, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (FAMTarget, GoUpMenuTree, OnXKeyPressed, ...)
    u32 m_nameForFamilyInLotSelect_00C;  // 0x00C [R/W] (FAMTarget, GetNameForFamily, GetNameForFamilyInLotSelect, ...)
    u32 m_field_010;  // 0x010 [R/W] (FAMTarget, GoUpMenuTree, UpdateMenuState, ...)
    u32 m_field_014;  // 0x014 [R/W] (FAMTarget, GoUpMenuTree, ~FAMTarget)
    u32 m_menuState;  // 0x018 [R/W] (FAMTarget, UpdateMenuState, ~FAMTarget)
    u32 m_field_01C;  // 0x01C [R/W] (FAMTarget, UpdateFamilySelectShaders, UpdateLotSelectShaders, ...)
    u32 m_field_020;  // 0x020 [R/W] (FAMTarget, ~FAMTarget)
    u32 m_field_024;  // 0x024 [R/W] (FAMTarget, ~FAMTarget)
    u32 m_field_028;  // 0x028 [W] (FAMTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (FAMTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (FAMTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (FAMTarget, ~FAMTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (FAMTarget, ~FAMTarget)
    u8 _pad_06C[4];  // 0x06C
    u32 m_moneyForLot;  // 0x070 [W] (GetMoneyForLot)
    u8 _pad_074[4];  // 0x074
    u32 m_field_078;  // 0x078 [W] (FAMTarget)
    u32 m_field_07C;  // 0x07C [R/W] (FAMTarget, UpdateFamilySelectShaders, UpdateLotSelectShaders, ...)
    u32 m_field_080;  // 0x080 [W] (FAMTarget, ~FAMTarget)
    u32 m_variable_084;  // 0x084 [W] (FAMTarget, GetVariable)
    u32 m_variable_088;  // 0x088 [R/W] (FAMTarget, GetVariable, OnCancelKeyPressed, ...)
    u32 m_menuState_08C;  // 0x08C [R/W] (FAMTarget, UpdateMenuState)
    u32 m_menuState_090;  // 0x090 [R/W] (FAMTarget, GoUpMenuTree, UpdateMenuState)
    u8 _pad_094[0xC];  // 0x094
    u32 m_menuState_0A0;  // 0x0A0 [R/W] (FAMTarget, GoUpMenuTree, UpdateMenuState)
    u8 _pad_0A4[0x1C];  // 0x0A4
    u32 m_menuState_0C0;  // 0x0C0 [R/W] (FAMTarget, GoUpMenuTree, UpdateMenuState)
    u32 m_field_0C4;  // 0x0C4 [W] (FAMTarget, OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_0C8[8];  // 0x0C8
    u32 m_field_0D0;  // 0x0D0 [W] (OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_0D4[4];  // 0x0D4
    u32 m_field_0D8;  // 0x0D8 [W] (OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_0DC[8];  // 0x0DC
    u32 m_field_0E4;  // 0x0E4 [W] (OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_0E8[0x2C];  // 0x0E8
    u32 m_field_114;  // 0x114 [W] (FAMTarget, OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_118[0xC];  // 0x118
    u32 m_field_124;  // 0x124 [W] (FAMTarget, OnCancelKeyPressed, OnXKeyPressed)
    u8 _pad_128[0xC];  // 0x128
    u32 m_field_134;  // 0x134 [W] (FAMTarget, OnCancelKeyPressed, OnXKeyPressed)
    s16 m_field_138;  // 0x138 [R] (OnXKeyPressed)
    u8 _pad_13A[0x12];  // 0x13A
    u32 m_nameForFamilyInLotSelect_14C;  // 0x14C [R/W] (EvictFamily, FAMTarget, GetLocalizable, ...)
    u32 m_currentChoice;  // 0x150 [R/W] (FAMTarget, OnDialogSelection, OnDownKeyPressed, ...)
    u32 m_numberOfChoicesInState;  // 0x154 [R/W] (FAMTarget, GetNumberOfChoicesInState)
    u32 m_numberOfChoicesInState_158;  // 0x158 [R/W] (FAMTarget, GetNumberOfChoicesInState, OnDownKeyPressed, ...)
    u32 m_currentChoice_15C;  // 0x15C [R/W] (FAMTarget, OnDialogSelection, OnDownKeyPressed, ...)
    u32 m_currentChoice_160;  // 0x160 [R/W] (FAMTarget, OnDialogSelection, OnDownKeyPressed, ...)
    u32 m_currentChoice_164;  // 0x164 [R/W] (FAMTarget, OnDialogSelection, OnDownKeyPressed, ...)
    u32 m_field_168;  // 0x168 [R/W] (FAMTarget, OnDownKeyPressed, OnUpKeyPressed)
    u32 m_localizable;  // 0x16C [R/W] (FAMTarget, GetLocalizable, OnReturnFromCreateAFamily, ...)
    u8 _pad_170[0x20];  // 0x170
    s16 m_moneyForLot_190;  // 0x190 [R] (GetMoneyForLot)
    u8 _pad_192[2];  // 0x192
    u32 m_moneyForLot_194;  // 0x194 [R] (GetMoneyForLot)
    u8 _pad_198[0x2B0];  // 0x198
    u32 m_menuState_448;  // 0x448 [W] (UpdateMenuState)
    u32 m_menuState_44C;  // 0x44C [W] (UpdateMenuState)
};

#endif // FAMTARGET_H
