#ifndef PDATARGET_H
#define PDATARGET_H

#include "types.h"

// PDATarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x178 (376 bytes)
// 52 known fields (13 named), 34 methods

class PDATarget {
public:
    // Constructors / Destructors
    PDATarget(void)  // 0x80584BB0
    ~PDATarget(void);  // 0x80585968

    // Methods
    void HandleSubTargetStateChange(FlowGotoTarget::eFlashState);  // 0x8058694C (2448B)
    void SetupFirstOpenMessage(int, PDATarget::ePDAMode);  // 0x80588090 (320B)
    void SetStartFireOnExit(bool);  // 0x8058899C (64B)
    void SetupMoney(void);  // 0x80584A58 (344B)
    void SetupSkinShaders(int, int);  // 0x80587CFC (728B)
    void SetVariable(char *, char *);  // 0x805860EC (1040B)
    void HandleFirstOpenMessage(int);  // 0x805881D0 (1428B)
    void HandleButtonHelpMessage(int, int);  // 0x805887B8 (484B)
    void HandleSubTargetStateChange(int, PDATarget::ePDAMode);  // 0x805872DC (2592B)
    /* ? */ GetVariable(char *);  // 0x805864FC (508B)
    void Draw(ERC *);  // 0x805866F8 (596B)
    void SelectionCallback(int);  // 0x80587FD4 (188B)
    void Update(void);  // 0x80588764 (84B)
    /* ? */ GetINVTarget(int);  // 0x80593914 (60B)
    /* ? */ GetPdaMode(int);  // 0x80593950 (60B)

    // ---- Field Layout (from assembly analysis) ----
    u16 m_variable;  // 0x000 [R/W] (GetVariable, HandleButtonHelpMessage, PDATarget, ...)
    u8 _pad_002[2];  // 0x002
    u16 m_variable_004;  // 0x004 [R/W] (GetVariable, PDATarget, ~PDATarget)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    u32 m_field_008;  // 0x008 [R/W] (PDATarget, ~PDATarget)
    u32 m_field_00C;  // 0x00C [R/W] (PDATarget, ~PDATarget)
    u32 m_field_010;  // 0x010 [R/W] (PDATarget, ~PDATarget)
    u32 m_field_014;  // 0x014 [R/W] (PDATarget, ~PDATarget)
    u32 m_field_018;  // 0x018 [R/W] (PDATarget, ~PDATarget)
    u32 m_upSkinShaders;  // 0x01C [R/W] (PDATarget, SetupSkinShaders, ~PDATarget)
    u32 m_field_020;  // 0x020 [R/W] (PDATarget, ~PDATarget)
    u32 m_field_024;  // 0x024 [R/W] (PDATarget, ~PDATarget)
    u32 m_field_028;  // 0x028 [W] (PDATarget)
    u32 m_field_02C;  // 0x02C [R] (~PDATarget)
    u8 _pad_030[8];  // 0x030
    u32 m_field_038;  // 0x038 [W] (PDATarget)
    u8 m_field_03C;  // 0x03C [R/W] (PDATarget, ~PDATarget)
    u8 _pad_03D[3];  // 0x03D
    u32 m_field_040;  // 0x040 [W] (PDATarget)
    u32 m_field_044;  // 0x044 [W] (PDATarget)
    u16 m_field_048;  // 0x048 [W] (PDATarget)
    u16 m_field_04A;  // 0x04A [W] (PDATarget)
    u32 m_field_04C;  // 0x04C [W] (PDATarget)
    u8 _pad_050[8];  // 0x050
    u32 m_field_058;  // 0x058 [R/W] (PDATarget, ~PDATarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (PDATarget, ~PDATarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (PDATarget)
    u32 m_upSkinShaders_07C;  // 0x07C [R/W] (PDATarget, SetupSkinShaders, ~PDATarget)
    u32 m_field_080;  // 0x080 [W] (PDATarget, ~PDATarget)
    u32 m_field_084;  // 0x084 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage, PDATarget)
    u32 m_field_088;  // 0x088 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u32 m_field_08C;  // 0x08C [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u32 m_field_090;  // 0x090 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u32 m_field_094;  // 0x094 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u32 m_field_098;  // 0x098 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u8 _pad_09C[0xC];  // 0x09C
    u32 m_field_0A8;  // 0x0A8 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u8 _pad_0AC[0x24];  // 0x0AC
    u32 m_field_0D0;  // 0x0D0 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage)
    u32 m_field_0D4;  // 0x0D4 [W] (PDATarget)
    u8 _pad_0D8[0xC];  // 0x0D8
    u32 m_field_0E4;  // 0x0E4 [W] (PDATarget)
    u8 _pad_0E8[0xC];  // 0x0E8
    u32 m_field_0F4;  // 0x0F4 [W] (PDATarget)
    u8 _pad_0F8[0xC];  // 0x0F8
    u32 m_field_104;  // 0x104 [W] (PDATarget)
    u32 m_field_108;  // 0x108 [W] (PDATarget, ~PDATarget)
    u8 _pad_10C[0x28];  // 0x10C
    u32 m_field_134;  // 0x134 [R] (HandleSubTargetStateChange)
    u8 _pad_138[4];  // 0x138
    u32 m_variable_13C;  // 0x13C [R] (GetVariable, HandleSubTargetStateChange)
    u32 m_variable_140;  // 0x140 [R] (GetVariable, HandleSubTargetStateChange)
    u32 m_field_144;  // 0x144 [R] (HandleSubTargetStateChange)
    u32 m_field_148;  // 0x148 [R] (HandleSubTargetStateChange)
    u32 m_variable_14C;  // 0x14C [W] (SetVariable)
    u32 m_variable_150;  // 0x150 [W] (SetVariable)
    u32 m_variable_154;  // 0x154 [W] (SetVariable)
    u32 m_variable_158;  // 0x158 [W] (SetVariable)
    u32 m_field_15C;  // 0x15C [R/W] (PDATarget, ~PDATarget)
    u8 _pad_160[8];  // 0x160
    u32 m_field_168;  // 0x168 [W] (HandleButtonHelpMessage, HandleFirstOpenMessage, PDATarget)
    u32 m_field_16C;  // 0x16C [R/W] (PDATarget, ~PDATarget)
    u32 m_variable_170;  // 0x170 [R/W] (PDATarget, SelectionCallback, SetVariable)
    u32 m_variable_174;  // 0x174 [R/W] (SelectionCallback, SetVariable)
};

#endif // PDATARGET_H
