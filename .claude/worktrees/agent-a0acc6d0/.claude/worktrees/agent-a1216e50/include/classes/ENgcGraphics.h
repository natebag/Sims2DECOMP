#ifndef ENGCGRAPHICS_H
#define ENGCGRAPHICS_H

#include "types.h"

// ENgcGraphics - struct layout extracted from assembly analysis
// Estimated minimum size: 0x32C (812 bytes)
// 14 known fields (1 named), 42 methods

class ENgcGraphics {
public:
    // Constructors / Destructors
    ENgcGraphics(void)  // 0x808A9C30
    ~ENgcGraphics(void);  // 0x808A9C84

    // Methods
    void Init(void);  // 0x808A9CD0 (280B)
    void SetBackgroundColor(EVec3 &, int, bool);  // 0x808A9DE8 (100B)
    /* ? */ GetScreenShot(char *);  // 0x808A9E4C (68B)
    void Destroy(ERenderSurface *);  // 0x808A9E90 (72B)
    void AllocDL(RCMode);  // 0x808A9ED8 (88B)
    void FreeDL(EDL *, RCMode);  // 0x808A9F30 (128B)
    void AllocRC(RCMode);  // 0x808A9FEC (168B)
    void FreeRC(ERC *, RCMode);  // 0x808AA094 (140B)
    void AllocTexture(void);  // 0x808AA120 (80B)
    void FreeTexture(ETexture *);  // 0x808AA170 (124B)
    void AllocShader(void);  // 0x808AA1EC (80B)
    void FreeShader(EShader *);  // 0x808AA23C (124B)
    void AllocRenderSurface(void);  // 0x808AA2B8 (84B)
    void FreeRenderSurface(ERenderSurface *);  // 0x808AA30C (124B)
    void AllocMovie(void);  // 0x808AA388 (84B)
    void FreeMovie(EMovie *);  // 0x808AA3DC (124B)
    void EndFrame(void);  // 0x808AA458 (1168B)
    void DrawCensorRects(ERC *);  // 0x808AA8E8 (284B)
    void ProcessFrameEffects(void);  // 0x808AAA04 (148B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (EndFrame, Init)
    u8 _pad_004[0x60];  // 0x004
    u32 m_field_064;  // 0x064 [W] (AllocDL)
    u8 _pad_068[8];  // 0x068
    u32 m_field_070;  // 0x070 [R] (EndFrame)
    u8 _pad_074[0x1C];  // 0x074
    u32 m_field_090;  // 0x090 [R] (EndFrame)
    u8 _pad_094[0xC];  // 0x094
    f32 m_field_0A0;  // 0x0A0 [R] (EndFrame)
    u8 _pad_0A4[0x200];  // 0x0A4
    u32 m_censorRects;  // 0x2A4 [R/W] (DrawCensorRects)
    u8 _pad_2A8[0x38];  // 0x2A8
    f32 m_field_2E0;  // 0x2E0 [R] (ProcessFrameEffects)
    f32 m_field_2E4;  // 0x2E4 [R] (ProcessFrameEffects)
    f32 m_field_2E8;  // 0x2E8 [R] (ProcessFrameEffects)
    u8 _pad_2EC[8];  // 0x2EC
    f32 m_field_2F4;  // 0x2F4 [R] (ProcessFrameEffects)
    f32 m_field_2F8;  // 0x2F8 [R] (ProcessFrameEffects)
    u8 _pad_2FC[4];  // 0x2FC
    f32 m_field_300;  // 0x300 [R] (ProcessFrameEffects)
    u8 _pad_304[0x1C];  // 0x304
    u32 m_field_320;  // 0x320 [R] (ProcessFrameEffects)
    u8 _pad_324[4];  // 0x324
    u32 m_field_328;  // 0x328 [W] (Init)
};

#endif // ENGCGRAPHICS_H
