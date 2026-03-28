#ifndef ENGCRENDERSTATECACHE_H
#define ENGCRENDERSTATECACHE_H

#include "types.h"

// ENgcRenderStateCache - struct layout extracted from assembly analysis
// Estimated minimum size: 0x9DC (2524 bytes)
// 50 known fields (0 named), 37 methods

class ENgcRenderStateCache {
public:
    // Methods
    void SetModified(unsigned int);  // 0x808D4A14 (52B)
    void ClearLIghtingState(void);  // 0x808D4A48 (68B)
    void Invalidate(void);  // 0x808D49C0 (40B)
    void ClearVtxDesc(void);  // 0x808D4AC0 (140B)
    void SetVtxDesc(_GXAttr, _GXAttrType);  // 0x808D4B4C (84B)
    void SetAlphaCompare(_GXCompare, unsigned char, _GXAlphaOp, _GXCompare, unsigned char);  // 0x808D4CB4 (108B)
    void SetZCompLoc(unsigned char);  // 0x808D4D20 (72B)
    void SetChanAmbColor(_GXColor);  // 0x808D52FC (96B)
    void SetChanMatColor(_GXColor);  // 0x808D535C (96B)
    void SetChanCtrl(_GXChannelID, unsigned char, _GXColorSrc, _GXColorSrc, unsigned int, _GXDiffuseFn, _GXAttnFn);  // 0x808D51D0 (300B)
    void SetNumTevStages(unsigned char);  // 0x808D4D68 (72B)
    void SetTevSwapMode(_GXTevStageID, _GXTevSwapSel, _GXTevSwapSel);  // 0x808D5164 (108B)
    void SetTevOrder(_GXTevStageID, _GXTexCoordID, _GXTexMapID, _GXChannelID);  // 0x808D4DB0 (144B)
    void SetTevColorIn(_GXTevStageID, _GXTevColorArg, _GXTevColorArg, _GXTevColorArg, _GXTevColorArg);  // 0x808D4E40 (160B)
    void SetTevAlphaIn(_GXTevStageID, _GXTevAlphaArg, _GXTevAlphaArg, _GXTevAlphaArg, _GXTevAlphaArg);  // 0x808D4EE0 (160B)
    void SetTevColorOp(_GXTevStageID, _GXTevOp, _GXTevBias, _GXTevScale, unsigned char, _GXTevRegID);  // 0x808D4F80 (180B)
    void SetTevAlphaOp(_GXTevStageID, _GXTevOp, _GXTevBias, _GXTevScale, unsigned char, _GXTevRegID);  // 0x808D50B0 (180B)
    void SetZMode(unsigned char, _GXCompare, unsigned char);  // 0x808D4C58 (92B)
    void SetCurrentMtx(_GXPosNrmMtx);  // 0x808D4A8C (52B)
    void SetModified(void);  // 0x808D49E8 (44B)
    void LoadLightObjImm(_GXLightObj &, int);  // 0x808D53BC (216B)
    void SetBlendMode(_GXBlendFactor, _GXBlendFactor);  // 0x808D4BFC (92B)
    void SetTevOutReg(_GXTevStageID, _GXTevRegID);  // 0x808D5034 (124B)
    void SaveViewportState(void);  // 0x808D7520 (316B)
    void SaveState(void);  // 0x808D723C (364B)
    void Apply(bool);  // 0x808D77A4 (7736B)
    void RestoreViewportState(void);  // 0x808D765C (328B)
    void RestoreState(void);  // 0x808D73A8 (376B)
    void operator=(ENgcRenderStateCache &);  // 0x808D6DF0 (1100B)
    bool IsModified(void);  // 0x808D976C (60B)
    bool IsInvalid(void);  // 0x808D97A8 (60B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_field_000;  // 0x000 [R/W] (Apply, operator=)
    f32 m_field_004;  // 0x004 [R/W] (Apply, operator=)
    f32 m_field_008;  // 0x008 [R/W] (Apply, operator=)
    f32 m_field_00C;  // 0x00C [R] (Apply)
    f32 m_field_010;  // 0x010 [R] (Apply)
    f32 m_field_014;  // 0x014 [R] (Apply)
    f32 m_field_018;  // 0x018 [R] (Apply)
    f32 m_field_01C;  // 0x01C [R] (Apply)
    f32 m_field_020;  // 0x020 [R] (Apply)
    f32 m_field_024;  // 0x024 [R] (Apply)
    f32 m_field_028;  // 0x028 [R] (Apply)
    f32 m_field_02C;  // 0x02C [R] (Apply)
    u32 m_field_030;  // 0x030 [R] (Apply)
    u8 _pad_034[4];  // 0x034
    f32 m_field_038;  // 0x038 [R] (Apply)
    u32 m_field_03C;  // 0x03C [R] (Apply)
    u32 m_field_040;  // 0x040 [R] (Apply)
    u32 m_field_044;  // 0x044 [R] (Apply)
    u32 m_field_048;  // 0x048 [R] (Apply)
    u32 m_field_04C;  // 0x04C [R] (Apply)
    u8 _pad_050[0x1C];  // 0x050
    u8 m_field_06C;  // 0x06C [R] (Apply)
    u8 _pad_06D[0x33F];  // 0x06D
    u8 m_field_3AC;  // 0x3AC [R/W] (Apply, RestoreState, SaveState, ...)
    u8 _pad_3AD[3];  // 0x3AD
    u32 m_field_3B0;  // 0x3B0 [R] (Apply)
    u8 m_field_3B4;  // 0x3B4 [R] (Apply)
    u8 _pad_3B5[3];  // 0x3B5
    u32 m_field_3B8;  // 0x3B8 [R/W] (Apply, RestoreState, SaveState, ...)
    u8 m_field_3BC;  // 0x3BC [R] (Apply)
    u8 _pad_3BD[3];  // 0x3BD
    u32 m_field_3C0;  // 0x3C0 [R] (Apply)
    u32 m_field_3C4;  // 0x3C4 [R] (Apply)
    u8 m_field_3C8;  // 0x3C8 [R] (Apply)
    u8 m_field_3C9;  // 0x3C9 [R] (Apply)
    u8 _pad_3CA[2];  // 0x3CA
    u8 m_field_3CC;  // 0x3CC [R] (Apply)
    u8 _pad_3CD[3];  // 0x3CD
    u8 m_field_3D0;  // 0x3D0 [R] (Apply)
    u8 _pad_3D1[0x2F7];  // 0x3D1
    u32 m_field_6C8;  // 0x6C8 [R/W] (Apply, operator=)
    u32 m_field_6CC;  // 0x6CC [R/W] (Apply, RestoreState, RestoreViewportState, ...)
    u32 m_field_6D0;  // 0x6D0 [R/W] (Apply, operator=)
    u16 m_field_6D2;  // 0x6D2 [R] (Apply)
    u32 m_field_6D4;  // 0x6D4 [R/W] (Apply, operator=)
    u32 m_field_6D8;  // 0x6D8 [R/W] (Apply, operator=)
    u32 m_field_6DC;  // 0x6DC [R] (Apply)
    u32 m_field_6E0;  // 0x6E0 [R] (Apply)
    u32 m_field_6E4;  // 0x6E4 [R] (Apply)
    u32 m_field_6E8;  // 0x6E8 [R/W] (Apply, RestoreState, SaveState, ...)
    u32 m_field_6EC;  // 0x6EC [R/W] (Apply, RestoreState, SaveState, ...)
    u8 m_field_6F0;  // 0x6F0 [R/W] (Apply, operator=)
    u8 _pad_6F1[0xAB];  // 0x6F1
    u32 m_field_79C;  // 0x79C [R] (Apply)
    u8 _pad_7A0[0x210];  // 0x7A0
    f32 m_field_9B0;  // 0x9B0 [R/W] (Apply, RestoreViewportState, SaveViewportState, ...)
    u8 _pad_9B4[0x14];  // 0x9B4
    u32 m_field_9C8;  // 0x9C8 [R/W] (Apply, RestoreViewportState, SaveViewportState, ...)
    u32 m_field_9CC;  // 0x9CC [R] (Apply)
    u32 m_field_9D0;  // 0x9D0 [R] (Apply)
    u32 m_field_9D4;  // 0x9D4 [R] (Apply)
    u32 m_field_9D8;  // 0x9D8 [R/W] (Apply, operator=)
};

#endif // ENGCRENDERSTATECACHE_H
