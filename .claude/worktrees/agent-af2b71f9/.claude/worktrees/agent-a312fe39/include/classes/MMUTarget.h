#ifndef MMUTARGET_H
#define MMUTARGET_H

#include "types.h"

// MMUTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x360 (864 bytes)
// 52 known fields (15 named), 106 methods

class MMUTarget {
public:
    // Constructors / Destructors
    MMUTarget(void)  // 0x805174E8
    ~MMUTarget(void);  // 0x80517CCC

    // Methods
    void OnStartGameComplete(bool);  // 0x8051BA58 (184B)
    /* ? */ GetSingleton(void);  // 0x80517DCC (44B)
    void OnCreditsClose(void);  // 0x80517DF8 (40B)
    /* ? */ GetCurrentMainScreenChoice(void);  // 0x80550050 (44B)
    void UpdateText(void);  // 0x8051AAC4 (1180B)
    void SetVariable(char *, char *);  // 0x80517E20 (1392B)
    void UpdateDevMenuState(char *, char *);  // 0x8051BB10 (116B)
    void OnNGHSelect(char *, char *);  // 0x8051BB84 (204B)
    void LaunchLot(int);  // 0x80519AF4 (140B)
    void UpdateTopLevelChoice(char *, char *);  // 0x8051A8FC (96B)
    void UpdateGameplayChoice(char *, char *);  // 0x8051A95C (96B)
    void UpdateNumberOfPlayersChoice(char *, char *);  // 0x8051A9BC (96B)
    void UpdateMenuState(char *, char *);  // 0x8051AF60 (472B)
    void GoUpMenuTree(char *, char *);  // 0x8051B138 (392B)
    void IncrementChoice(char *, char *);  // 0x8051B580 (492B)
    void DecrementChoice(char *, char *);  // 0x8051B86C (492B)
    void SetCurrentChoice(char *);  // 0x8051B76C (256B)
    void OnXKeyPressed(char *, char *);  // 0x8051A028 (2032B)
    void OnUpKeyPressed(char *, char *);  // 0x80519C04 (200B)
    void OnDownKeyPressed(char *, char *);  // 0x80519CCC (216B)
    void OnCircleKeyPressed(char *, char *);  // 0x8051A894 (104B)
    void OnLeftKeyPressed(char *, char *);  // 0x80519DA4 (72B)
    void OnRightKeyPressed(char *, char *);  // 0x80519DEC (72B)
    void OnCancelKeyPressed(char *, char *);  // 0x8051A818 (124B)
    /* ? */ GetVariable(char *);  // 0x80518390 (776B)
    /* ? */ GetNumberOfControllers(void);  // 0x8051B2C0 (532B)
    /* ? */ GetNumberOfChoicesInState(MMUTarget::MMU_MENU_STATE);  // 0x8051B4D4 (172B)
    /* ? */ GetLocalizable(char *);  // 0x80518698 (1940B)
    /* ? */ GetListItemName(char *);  // 0x805190FC (136B)
    void Update(void);  // 0x80518E2C (308B)
    void PollControllersForNumOfPlayersState(void);  // 0x8051BC84 (116B)
    void Draw(ERC *);  // 0x80518F60 (412B)
    /* ? */ GetNGHListItemName(char *);  // 0x80519628 (456B)
    /* ? */ GetLotListItemName(char *);  // 0x805197F0 (272B)
    void ChangeScreenMode(void);  // 0x80519184 (232B)
    void UpdateListItems(void);  // 0x8051926C (116B)
    void UpdateNGHListItems(void);  // 0x805192E0 (424B)
    void UpdateLotListItems(void);  // 0x80519488 (416B)
    void EnterLot(int);  // 0x80519900 (500B)
    void LaunchFreeplay(void);  // 0x80519B80 (132B)
    void EndPlayerNumberChooser(void);  // 0x80519F78 (176B)
    void OnDialogClose(int);  // 0x8051BCF8 (144B)
    void OnCancelDialog(void);  // 0x8051BD88 (32B)
    void OnDialog2Close(int);  // 0x8051BDA8 (36B)
    void OnCancelDialog2(void);  // 0x8051BDCC (32B)
    void Dialog2ClosedCallback(void);  // 0x8051BDEC (112B)
    void OnTopLevelChoiceChange(void);  // 0x8051AA1C (56B)
    void OnGameplayLevelChoiceChange(void);  // 0x8051AA54 (56B)
    void OnNumberOfPlayersChoiceChange(void);  // 0x8051AA8C (56B)
    void ChangeScreenMode(MMUTarget::MMU_MODE);  // 0x8051BC50 (52B)
    /* ? */ GetCurrentGameplayChoice(void);  // 0x8055007C (44B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_localizable;  // 0x000 [R/W] (GetLocalizable, GetVariable, MMUTarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable;  // 0x004 [R/W] (Draw, GetVariable, MMUTarget, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (Draw, GoUpMenuTree, MMUTarget, ...)
    u32 m_field_00C;  // 0x00C [R/W] (Draw, GoUpMenuTree, MMUTarget, ...)
    u8 m_field_010;  // 0x010 [R/W] (Draw, GoUpMenuTree, MMUTarget, ...)
    u8 _pad_011[3];  // 0x011
    u32 m_field_014;  // 0x014 [R/W] (GoUpMenuTree, MMUTarget, ~MMUTarget)
    u32 m_menuState;  // 0x018 [R/W] (MMUTarget, UpdateMenuState, ~MMUTarget)
    u32 m_field_01C;  // 0x01C [R/W] (MMUTarget, ~MMUTarget)
    u32 m_field_020;  // 0x020 [R/W] (MMUTarget, ~MMUTarget)
    u32 m_field_024;  // 0x024 [R/W] (MMUTarget, ~MMUTarget)
    u32 m_field_028;  // 0x028 [W] (MMUTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (MMUTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (MMUTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (MMUTarget, ~MMUTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (MMUTarget, ~MMUTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (MMUTarget)
    u32 m_field_07C;  // 0x07C [R/W] (MMUTarget, ~MMUTarget)
    u32 m_currentChoice;  // 0x080 [R/W] (DecrementChoice, GoUpMenuTree, IncrementChoice, ...)
    u32 m_variable_084;  // 0x084 [W] (GetVariable, MMUTarget)
    u32 m_field_088;  // 0x088 [W] (MMUTarget)
    u32 m_listItemName;  // 0x08C [R/W] (ChangeScreenMode, DecrementChoice, Draw, ...)
    u32 m_field_090;  // 0x090 [W] (ChangeScreenMode, MMUTarget, OnNGHSelect)
    u32 m_field_094;  // 0x094 [W] (MMUTarget)
    u32 m_field_098;  // 0x098 [R/W] (LaunchLot, MMUTarget, OnDownKeyPressed, ...)
    u32 m_field_09C;  // 0x09C [R/W] (ChangeScreenMode, MMUTarget, OnDownKeyPressed, ...)
    u32 m_field_0A0;  // 0x0A0 [R/W] (MMUTarget, OnDownKeyPressed, OnUpKeyPressed, ...)
    u32 m_field_0A4;  // 0x0A4 [R/W] (DecrementChoice, EndPlayerNumberChooser, IncrementChoice, ...)
    u32 m_topLevelChoice;  // 0x0A8 [W] (MMUTarget, UpdateTopLevelChoice)
    u32 m_field_0AC;  // 0x0AC [R/W] (MMUTarget, OnXKeyPressed, Update, ...)
    u32 m_numberOfChoicesInState;  // 0x0B0 [R/W] (DecrementChoice, GetNumberOfChoicesInState, GetVariable, ...)
    u32 m_menuState_0B4;  // 0x0B4 [W] (MMUTarget, UpdateMenuState)
    u32 m_localizable_0B8;  // 0x0B8 [R/W] (DecrementChoice, GetLocalizable, IncrementChoice, ...)
    u32 m_gameplayChoice;  // 0x0BC [W] (MMUTarget, UpdateGameplayChoice)
    u32 m_field_0C0;  // 0x0C0 [R/W] (DecrementChoice, IncrementChoice, MMUTarget, ...)
    u32 m_numberOfPlayersChoice;  // 0x0C4 [W] (MMUTarget, UpdateNumberOfPlayersChoice)
    u32 m_field_0C8;  // 0x0C8 [R/W] (GoUpMenuTree, MMUTarget)
    u8 _pad_0CC[0xC];  // 0x0CC
    u32 m_field_0D8;  // 0x0D8 [R/W] (GoUpMenuTree, MMUTarget)
    u8 _pad_0DC[0x1C];  // 0x0DC
    u32 m_menuState_0F8;  // 0x0F8 [R/W] (GoUpMenuTree, MMUTarget, UpdateMenuState)
    u32 m_field_0FC;  // 0x0FC [R/W] (MMUTarget, Update)
    u32 m_field_100;  // 0x100 [R/W] (MMUTarget, OnStartGameComplete, OnXKeyPressed, ...)
    u32 m_field_104;  // 0x104 [W] (MMUTarget, OnXKeyPressed)
    u8 _pad_108[8];  // 0x108
    u32 m_field_110;  // 0x110 [W] (OnXKeyPressed)
    u8 _pad_114[4];  // 0x114
    u32 m_field_118;  // 0x118 [W] (OnXKeyPressed)
    u8 _pad_11C[4];  // 0x11C
    u32 m_field_120;  // 0x120 [W] (OnXKeyPressed)
    u32 m_field_124;  // 0x124 [W] (OnXKeyPressed)
    u8 _pad_128[0x2C];  // 0x128
    u32 m_field_154;  // 0x154 [W] (MMUTarget, OnXKeyPressed)
    u8 _pad_158[0xC];  // 0x158
    u32 m_field_164;  // 0x164 [W] (MMUTarget, OnXKeyPressed)
    u8 _pad_168[0xC];  // 0x168
    u32 m_field_174;  // 0x174 [W] (MMUTarget, OnXKeyPressed)
    u8 _pad_178[0x14];  // 0x178
    u32 m_field_18C;  // 0x18C [R/W] (Draw, MMUTarget)
    u32 m_field_190;  // 0x190 [R/W] (Dialog2ClosedCallback, OnStartGameComplete, OnXKeyPressed, ...)
    u8 _pad_194[0x1C8];  // 0x194
    u32 m_localizable_35C;  // 0x35C [R] (GetLocalizable)
};

#endif // MMUTARGET_H
