#ifndef CASGENETICSTARGET_H
#define CASGENETICSTARGET_H

#include "types.h"

// CASGeneticsTarget - struct layout extracted from assembly analysis
// Estimated minimum size: 0x41C (1052 bytes)
// 46 known fields (13 named), 44 methods

class CASGeneticsTarget {
public:
    // Constructors / Destructors
    CASGeneticsTarget(void)  // 0x804CDF4C
    ~CASGeneticsTarget(void);  // 0x804CE610

    // Methods
    void HandleGenerateStageBG(void);  // 0x804CFE04 (768B)
    /* ? */ GetCasGenetics(void);  // 0x804DF7BC (44B)
    /* ? */ GetLocalizableSubnav(int, unsigned wchar_t *);  // 0x804CEECC (504B)
    void SetVariableSubnav(int, int);  // 0x804CEB98 (560B)
    /* ? */ GetWarnOnGenerate(void);  // 0x804DF830 (76B)
    void BeginGenerate(void);  // 0x804CFC18 (492B)
    void SetGenerateDefaultSim(bool);  // 0x804DF87C (72B)
    void SetWarnOnGenerate(bool);  // 0x804DF7E8 (72B)
    void SetVariable(char *, char *);  // 0x804CE8F8 (672B)
    void ClearGrandparentTexture(unsigned int);  // 0x804CF2E4 (304B)
    void ClearParentTexture(unsigned int);  // 0x804CF81C (556B)
    void SetDoneButtonState(void);  // 0x804CFB84 (148B)
    bool IsGenerating(void);  // 0x804DF8C4 (64B)
    /* ? */ GetDefaultSim(bool, CasSimDescriptionS2C &);  // 0x804CFA48 (316B)
    /* ? */ GetVariable(char *);  // 0x804CEDC8 (260B)
    void SetGrandparentIndex(unsigned int, int);  // 0x804CF0C4 (252B)
    void ShowGrandparentTexture(unsigned int, int);  // 0x804CF1C0 (292B)
    void CreateParentTexture(unsigned int);  // 0x804CF414 (1032B)
    void Update(void);  // 0x804D0104 (1120B)
    void Draw(ERC *);  // 0x804D0564 (352B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_variable;  // 0x000 [R/W] (CASGeneticsTarget, GetVariable, HandleGenerateStageBG, ...)
    u8 _pad_001[3];  // 0x001
    f32 m_variable_004;  // 0x004 [R/W] (CASGeneticsTarget, GetVariable, HandleGenerateStageBG, ...)
    u8 m_variable_006;  // 0x006 [W] (GetVariable)
    u8 _pad_007[1];  // 0x007
    f32 m_field_008;  // 0x008 [R/W] (CASGeneticsTarget, HandleGenerateStageBG, ~CASGeneticsTarget)
    f32 m_field_00C;  // 0x00C [R/W] (CASGeneticsTarget, HandleGenerateStageBG, ~CASGeneticsTarget)
    u32 m_field_010;  // 0x010 [R/W] (CASGeneticsTarget, HandleGenerateStageBG, ~CASGeneticsTarget)
    u32 m_field_014;  // 0x014 [R/W] (CASGeneticsTarget, HandleGenerateStageBG, ~CASGeneticsTarget)
    u32 m_field_018;  // 0x018 [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_01C;  // 0x01C [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_020;  // 0x020 [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_024;  // 0x024 [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_028;  // 0x028 [W] (CASGeneticsTarget)
    u8 _pad_02C[0xC];  // 0x02C
    u32 m_field_038;  // 0x038 [W] (CASGeneticsTarget)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [W] (CASGeneticsTarget)
    u8 _pad_04C[0xC];  // 0x04C
    u32 m_field_058;  // 0x058 [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u8 _pad_05C[0xC];  // 0x05C
    u32 m_field_068;  // 0x068 [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u8 _pad_06C[0xC];  // 0x06C
    u32 m_field_078;  // 0x078 [W] (CASGeneticsTarget)
    u32 m_field_07C;  // 0x07C [R/W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_080;  // 0x080 [W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_variable_084;  // 0x084 [R/W] (CASGeneticsTarget, HandleGenerateStageBG, SetVariable, ...)
    u32 m_field_088;  // 0x088 [W] (CASGeneticsTarget, ~CASGeneticsTarget)
    u32 m_field_08C;  // 0x08C [W] (CASGeneticsTarget)
    u32 m_field_090;  // 0x090 [W] (CASGeneticsTarget)
    u32 m_defaultSim;  // 0x094 [R/W] (CASGeneticsTarget, CreateParentTexture, GetDefaultSim, ...)
    u32 m_field_098;  // 0x098 [W] (CASGeneticsTarget)
    u32 m_field_09C;  // 0x09C [R/W] (BeginGenerate, CASGeneticsTarget, Update)
    u32 m_field_0A0;  // 0x0A0 [R/W] (BeginGenerate, CASGeneticsTarget, Update)
    u32 m_field_0A4;  // 0x0A4 [R/W] (BeginGenerate, CASGeneticsTarget, Update)
    u32 m_field_0A8;  // 0x0A8 [R/W] (BeginGenerate, CASGeneticsTarget, Update)
    u8 _pad_0AC[0x248];  // 0x0AC
    u32 m_variable_2F4;  // 0x2F4 [R/W] (CASGeneticsTarget, HandleGenerateStageBG, SetVariable, ...)
    u32 m_variable_2F8;  // 0x2F8 [R/W] (CASGeneticsTarget, Draw, SetVariable, ...)
    u32 m_field_2FC;  // 0x2FC [R/W] (CASGeneticsTarget, CreateParentTexture, HandleGenerateStageBG, ...)
    u32 m_grandparentIndex;  // 0x300 [R/W] (BeginGenerate, CASGeneticsTarget, SetGrandparentIndex, ...)
    u32 m_field_304;  // 0x304 [W] (CASGeneticsTarget)
    u32 m_field_308;  // 0x308 [W] (CASGeneticsTarget)
    u32 m_field_30C;  // 0x30C [W] (CASGeneticsTarget)
    u32 m_field_310;  // 0x310 [W] (CASGeneticsTarget)
    u32 m_field_314;  // 0x314 [W] (CASGeneticsTarget)
    u32 m_field_318;  // 0x318 [W] (CASGeneticsTarget)
    u32 m_variable_31C;  // 0x31C [W] (SetVariable)
    u8 _pad_320[0xC];  // 0x320
    f32 m_variable_32C;  // 0x32C [R/W] (SetVariable)
    u8 _pad_330[8];  // 0x330
    u32 m_variable_338;  // 0x338 [W] (SetVariable)
    u8 _pad_33C[0xD0];  // 0x33C
    u32 m_variable_40C;  // 0x40C [W] (SetVariable)
    u32 m_variable_410;  // 0x410 [W] (SetVariable)
    u32 m_field_414;  // 0x414 [R/W] (BeginGenerate, CASGeneticsTarget, Update, ...)
    u32 m_field_418;  // 0x418 [R/W] (BeginGenerate, CASGeneticsTarget, Update, ...)
};

#endif // CASGENETICSTARGET_H
