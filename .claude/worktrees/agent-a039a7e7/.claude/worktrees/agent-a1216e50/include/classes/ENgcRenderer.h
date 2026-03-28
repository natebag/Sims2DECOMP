#ifndef ENGCRENDERER_H
#define ENGCRENDERER_H

#include "types.h"

// ENgcRenderer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4668 (18024 bytes)
// 119 known fields (33 named), 288 methods

class ENgcRenderer {
public:
    // Static members (from map file)
    // static ??? kFrameEffectsBufferFormat;

    // Constructors / Destructors
    ENgcRenderer(void)  // 0x808BE9D4
    ~ENgcRenderer(void);  // 0x808BEB6C

    // Methods
    /* ? */ GetZTestSettings(unsigned char &, unsigned char &, unsigned char &);  // 0x808D4904 (68B)
    /* ? */ GetRenderMode(void);  // 0x808D48C0 (68B)
    void InitVideo(int &, int &);  // 0x808C0EDC (1104B)
    /* ? */ GetExternalFrameBuffer(void);  // 0x808BFFA8 (76B)
    void Init(int &, int &);  // 0x808BEC28 (100B)
    void SetClearColor(EVec3 &, bool);  // 0x808BFF38 (112B)
    void ProcessFrameEffects(float, float, float, float, EVec3 &, EVec3 &);  // 0x808D1C78 (4280B)
    void TriStrip(EGEVert *, int);  // 0x808C54C8 (1336B)
    void TriStripPacked(int, float *, float *, unsigned char *, signed char *, unsigned char *, unsigned char *, bool);  // 0x808C6040 (4288B)
    void CreateGXDisplayList(EDL *, _GXPrimitive, int, float *, float *, unsigned char *, signed char *, unsigned int &, bool);  // 0x808BF6AC (992B)
    void CreateGXDisplayList(EDL *, _GXPrimitive, int, unsigned short *, int, float *, float *, unsigned char *, signed char *, unsigned int &, bool);  // 0x808BEC8C (1296B)
    void CreateGXDisplayList(EDL *, _GXPrimitive, int, short *, short *, unsigned char *, signed char *, unsigned int &, bool, bool);  // 0x808BFA8C (1196B)
    void CreateGXDisplayList(EDL *, _GXPrimitive, int, unsigned short *, int, short *, short *, unsigned char *, signed char *, unsigned int &, bool);  // 0x808BF19C (1296B)
    void SetShader(ENgcShader *, unsigned int);  // 0x808CF7C4 (1520B)
    void ScrambleRect(EVec2 &, EVec2 &, float);  // 0x808CFEB4 (1952B)
    void ModelMatrices(EMat4 *, int);  // 0x808C8ABC (224B)
    void ModelMatrixIndex(int, int);  // 0x808C8B9C (416B)
    void Execute(EDLEntry *);  // 0x808C500C (448B)
    void SetTexture(ENgcTexture *, int);  // 0x808C9010 (552B)
    void EnableGeometryModes(EDLEntry *);  // 0x808C9238 (204B)
    void DisableGeometryModes(EDLEntry *);  // 0x808C9304 (204B)
    void SetGeometryModes(EDLEntry *);  // 0x808C93D0 (192B)
    void EnableRasterModes(EDLEntry *);  // 0x808C9490 (116B)
    void DisableRasterModes(EDLEntry *);  // 0x808C9504 (116B)
    void SetRasterModes(EDLEntry *);  // 0x808C9578 (104B)
    void Viewport(EDLEntry *);  // 0x808C8610 (360B)
    void ClipRect(EDLEntry *);  // 0x808C8778 (108B)
    void Scissor(EDLEntry *);  // 0x808C87E4 (624B)
    void ViewMatrix(EDLEntry *);  // 0x808C8DD0 (144B)
    void ProjectionMatrix(EDLEntry *);  // 0x808C8E60 (128B)
    void WindowMatrix(EDLEntry *);  // 0x808C8EE0 (140B)
    void SaveState(EDLEntry *);  // 0x808C8598 (60B)
    void RestoreState(EDLEntry *);  // 0x808C85D4 (60B)
    void Lights(EDLEntry *);  // 0x808C961C (472B)
    void Material(EDLEntry *);  // 0x808CA258 (104B)
    void Rect(EDLEntry *);  // 0x808C97F4 (1208B)
    void RectList(EDLEntry *);  // 0x808CD258 (1180B)
    void RectListRot(EDLEntry *);  // 0x808CCCB4 (1444B)
    void DirectRect(EDLEntry *);  // 0x808C9CAC (1452B)
    void TextureMatrix(EDLEntry *);  // 0x808C8F6C (44B)
    void ZTest(EDLEntry *);  // 0x808CA464 (260B)
    void AlphaTest(EDLEntry *);  // 0x808CA568 (252B)
    void Stencil(EDLEntry *);  // 0x808CD6F4 (740B)
    void SetBlendMode(EDLEntry *);  // 0x808CC2D0 (192B)
    void SetCombineMode(EDLEntry *);  // 0x808CC260 (112B)
    void SetAlpha(float);  // 0x808C95E0 (60B)
    void RenderSurface(EDLEntry *);  // 0x808CA664 (536B)
    void QuadList(int, float *, float *, unsigned char *, signed char *, unsigned char *, unsigned char *, bool);  // 0x808CB0DC (4484B)
    void SpriteListPacked(int, float *, float *, unsigned char *, signed char *, unsigned char *);  // 0x808CAAE0 (1228B)
    void LineList(EGEVert *, int);  // 0x808C82A8 (372B)
    void ParticleListBegin(unsigned int, unsigned int);  // 0x808D2F54 (136B)
    void ParticleListEnd(unsigned int);  // 0x808D2FDC (1468B)
    void TriStrip(EDLEntry *);  // 0x808C5460 (104B)
    void QuadList(EDLEntry *);  // 0x808CAFAC (304B)
    void DisplayList(EDLEntry *);  // 0x808C841C (224B)
    void Goto(EDLEntry *);  // 0x808C84FC (56B)
    void End(EDLEntry *);  // 0x808C8534 (100B)
    void ModelMatrices(EDLEntry *);  // 0x808C8A54 (104B)
    void Texture(EDLEntry *);  // 0x808C8F98 (120B)
    void LineList(EDLEntry *);  // 0x808C8240 (104B)
    void ModelMatrixIndices(EDLEntry *);  // 0x808C8D3C (148B)
    void MipMapSetup(EDLEntry *);  // 0x808CA2C0 (188B)
    void Debug(EDLEntry *);  // 0x808CA37C (148B)
    void GeometrySetup(EDLEntry *);  // 0x808CA410 (84B)
    void TriStripPacked(EDLEntry *);  // 0x808C5F18 (296B)
    void TriIndexed(EDLEntry *);  // 0x808CA87C (188B)
    void SaveImageData(EDLEntry *);  // 0x808CA938 (188B)
    void SpriteListPacked(EDLEntry *);  // 0x808CA9F4 (236B)
    void MovieFrame(EDLEntry *);  // 0x808CC390 (2340B)
    void TriStripPackedInt(EDLEntry *);  // 0x808C7100 (4416B)
    void NgcTexInvalidateAll(EDLEntry *);  // 0x808CD9D8 (64B)
    void NgcGXDisplayListInt(EDLEntry *);  // 0x808CDA18 (1484B)
    void NgcGXDisplayList(EDLEntry *);  // 0x808CDFE4 (1504B)
    void NgcTriListInt(EDLEntry *);  // 0x808CE5C4 (1708B)
    void NgcTriList(EDLEntry *);  // 0x808CEC70 (1660B)
    void NgcScreenTriList(EDLEntry *);  // 0x808CF2EC (1068B)
    void ReadMetrics(EDLEntry *);  // 0x808CF718 (76B)
    void Shader(EDLEntry *);  // 0x808CF764 (96B)
    void ScrambleRect(EDLEntry *);  // 0x808CFDB4 (256B)
    void ShowPerfGraphs(bool);  // 0x808BEBC4 (36B)
    /* ? */ GetCurrentTexture(int);  // 0x808BEBE8 (64B)
    void CycleToNextFrameBuffer(void);  // 0x808BFFF4 (128B)
    void VIPreRetraceCallback(unsigned long);  // 0x808C02E0 (384B)
    void VIPostRetraceCallback(unsigned long);  // 0x808C0460 (32B)
    void BreakPtCallback(void);  // 0x808C0480 (72B)
    void DrawSyncCallback(unsigned short);  // 0x808C04C8 (52B)
    void AddDrawSync(void);  // 0x808C04FC (112B)
    void InitGX(_GXRenderModeObj *);  // 0x808C0624 (1248B)
    void InitGXVertexFormats(void);  // 0x808C0B04 (984B)
    void InitData(void);  // 0x808C132C (1788B)
    void UpdateLightingEquation(void);  // 0x808C2894 (2520B)
    void UpdateTEVStages(void);  // 0x808C392C (5856B)
    void ClearRect(EVec4 &, EVec4 &);  // 0x808C1A28 (1360B)
    void QueueBeginFrame(int);  // 0x808C1F78 (84B)
    void BeginFrame(ENgcRendCommand *);  // 0x808C2124 (200B)
    void QueueDisplayList(EDL *, bool);  // 0x808C1FCC (96B)
    void DisplayList(ENgcRendCommand *);  // 0x808C21EC (152B)
    void QueueEndFrame(EEvent &);  // 0x808C202C (84B)
    void EndFrame(ENgcRendCommand *);  // 0x808C2284 (944B)
    void QueueSwap(int, int);  // 0x808C2080 (96B)
    void Swap(ENgcRendCommand *);  // 0x808C2634 (212B)
    void Flush(void);  // 0x808C20E0 (68B)
    void Flush(ENgcRendCommand *);  // 0x808C2708 (56B)
    void PushAndClearViewport(void);  // 0x808C2740 (284B)
    void RestoreViewport(void);  // 0x808C285C (56B)
    void SetupTEVStagePassColor(_GXTevStageID);  // 0x808C326C (232B)
    void Setup1TEVStageTexture(int, int &, int, int &);  // 0x808C3354 (484B)
    void Setup2TEVStageTexture(int, int &, int, int &);  // 0x808C3538 (1012B)
    void WeightedBlend(_GXPrimitive, int, float *, signed char *, float *, unsigned char *, unsigned char *, bool);  // 0x808C5A00 (1304B)
    void WeightedBlendInt(_GXPrimitive, int, short *, signed char *, short *, unsigned char *, unsigned char *, bool);  // 0x808D06F4 (1144B)
    void SimpleSkinning(_GXPrimitive, int, short *, signed char *, short *, unsigned char *, unsigned char *, bool);  // 0x808D0B6C (1276B)
    void ScaleTexture(_GXTexObj *, void *, int, float);  // 0x808D1068 (508B)
    void DrawTextureToFullViewportWithJitter(float, float);  // 0x808D1264 (712B)
    void DrawFrameWithBloomAndMotionBlur(float, float);  // 0x808D152C (872B)
    void ProcessThumbnail(void *, int, float, float);  // 0x808D1894 (996B)
    /* ? */ GetNextExternalFrameBuffer(void);  // 0x808D2D64 (52B)
    /* ? */ GetRenderStateCache(void);  // 0x808D2D30 (52B)
    /* ? */ GetPreviousFrameBuffer(int *, int *);  // 0x808D2D98 (236B)
    /* ? */ GetCurrentRenderMode(void);  // 0x808D2E84 (156B)
    /* ? */ GetFrameEffectsScratchMemory(void);  // 0x808D2F20 (52B)
    void AcquireCopyMutex(void);  // 0x808D4948 (60B)
    void ReleaseCopyMutex(void);  // 0x808D4984 (60B)
    void RecalcMatrices(EDLEntry *);  // 0x808D68EC (180B)
    void TriFan(EDLEntry *);  // 0x808D643C (96B)
    void TriList(EDLEntry *);  // 0x808D649C (96B)
    void PointList(EDLEntry *);  // 0x808D655C (96B)
    void SpriteList(EDLEntry *);  // 0x808D65BC (96B)
    void SendGSDisplayList(EDLEntry *);  // 0x808D661C (180B)
    void LineStrip(EDLEntry *);  // 0x808D64FC (96B)
    void CallbackParam(EDLEntry *);  // 0x808D66D0 (180B)
    void Callback(EDLEntry *);  // 0x808D6784 (180B)
    void GEList(EDLEntry *);  // 0x808D6838 (180B)
    void SetMipMap(EDLEntry *);  // 0x808D69A0 (96B)
    void Vertex(EDLEntry *);  // 0x808D6A00 (192B)
    void PointListPacked(EDLEntry *);  // 0x808D6AC0 (192B)
    void NoOp(EDLEntry *);  // 0x808D6B80 (36B)
    void VerifyMpg(EDLEntry *);  // 0x808D6BA4 (96B)
    void ParticleList(EDLEntry *);  // 0x808D6C04 (96B)
    void ParticleListRot(EDLEntry *);  // 0x808D6C64 (96B)
    void LineStreakList(EDLEntry *);  // 0x808D6CC4 (108B)
    void SetAlpha(EDLEntry *);  // 0x808D6D30 (96B)
    void CopyScreenToTexture(EDLEntry *);  // 0x808D6D90 (96B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateGXDisplayList, ENgcRenderer, GetCurrentRenderMode, ...)
    u8 m_field_001;  // 0x001 [W] (InitData)
    u8 m_field_002;  // 0x002 [W] (InitData)
    u8 m_field_003;  // 0x003 [W] (InitData)
    f32 m_currentRenderMode_004;  // 0x004 [R/W] (ENgcRenderer, GetCurrentRenderMode, InitData, ...)
    f32 m_currentRenderMode_008;  // 0x008 [R/W] (ENgcRenderer, GetCurrentRenderMode, InitData, ...)
    f32 m_currentRenderMode_00C;  // 0x00C [R/W] (ENgcRenderer, GetCurrentRenderMode, InitData, ...)
    u32 m_currentRenderMode_010;  // 0x010 [R/W] (ENgcRenderer, GetCurrentRenderMode, UpdateLightingEquation)
    f32 m_currentRenderMode_014;  // 0x014 [R/W] (ENgcRenderer, GetCurrentRenderMode, UpdateLightingEquation)
    f32 m_field_018;  // 0x018 [W] (ENgcRenderer)
    u8 m_field_01C;  // 0x01C [W] (ENgcRenderer)
    u8 m_field_01D;  // 0x01D [W] (ENgcRenderer)
    u8 m_field_01E;  // 0x01E [W] (ENgcRenderer)
    u8 m_field_01F;  // 0x01F [W] (ENgcRenderer)
    u8 m_field_020;  // 0x020 [W] (ENgcRenderer)
    u8 m_field_021;  // 0x021 [W] (ENgcRenderer)
    u8 m_field_022;  // 0x022 [W] (ENgcRenderer)
    u8 m_field_023;  // 0x023 [W] (ENgcRenderer)
    u8 m_field_024;  // 0x024 [R/W] (ENgcRenderer, MovieFrame)
    u8 m_field_025;  // 0x025 [W] (ENgcRenderer)
    u16 m_field_026;  // 0x026 [W] (ENgcRenderer)
    u32 m_field_028;  // 0x028 [W] (ENgcRenderer, InitData)
    f32 m_field_02C;  // 0x02C [R/W] (ENgcRenderer, InitData)
    u32 m_field_030;  // 0x030 [W] (ENgcRenderer, InitData)
    u32 m_field_034;  // 0x034 [W] (ENgcRenderer)
    u32 m_field_038;  // 0x038 [W] (ENgcRenderer, InitData)
    u32 m_field_03C;  // 0x03C [W] (ENgcRenderer, InitData)
    u32 m_field_040;  // 0x040 [W] (InitData)
    u32 m_field_044;  // 0x044 [W] (InitData)
    u32 m_field_048;  // 0x048 [W] (InitData)
    u32 m_field_04C;  // 0x04C [W] (InitData)
    u8 _pad_050[0x1C];  // 0x050
    u8 m_field_06C;  // 0x06C [W] (InitData)
    u8 _pad_06D[0x2CB];  // 0x06D
    u32 m_field_338;  // 0x338 [W] (ENgcRenderer)
    u8 _pad_33C[4];  // 0x33C
    u32 m_field_340;  // 0x340 [R/W] (CycleToNextFrameBuffer, EndFrame, InitVideo)
    u8 _pad_344[8];  // 0x344
    u32 m_field_34C;  // 0x34C [R/W] (CycleToNextFrameBuffer, ENgcRenderer, EndFrame, ...)
    u32 m_field_350;  // 0x350 [R/W] (InitVideo)
    u32 m_field_354;  // 0x354 [W] (InitVideo)
    u32 m_field_358;  // 0x358 [R/W] (InitGX)
    u32 m_field_35C;  // 0x35C [R/W] (Swap)
    u32 m_clearColor;  // 0x360 [R/W] (ENgcRenderer, EndFrame, SetClearColor)
    u32 m_field_364;  // 0x364 [R] (InitVideo)
    u16 m_field_368;  // 0x368 [R] (EndFrame, InitGX, InitVideo, ...)
    u16 m_field_36A;  // 0x36A [R] (EndFrame, InitGX, InitVideo, ...)
    u16 m_field_36C;  // 0x36C [R] (InitVideo, ScrambleRect)
    u8 _pad_36E[4];  // 0x36E
    u16 m_field_372;  // 0x372 [R] (ClearRect, DirectRect, InitData, ...)
    u16 m_field_374;  // 0x374 [R] (ClearRect, DirectRect, InitData, ...)
    u8 _pad_376[7];  // 0x376
    u8 m_field_37D;  // 0x37D [R] (EndFrame, RenderSurface)
    u8 _pad_37E[0x18];  // 0x37E
    u32 m_field_396;  // 0x396 [W] (InitVideo)
    u8 _pad_39A[6];  // 0x39A
    u32 m_shader;  // 0x3A0 [R/W] (ENgcRenderer, SetShader, UpdateTEVStages)
    u8 m_tEVStages;  // 0x3A3 [R] (UpdateTEVStages)
    f32 m_tEVStages_3A4;  // 0x3A4 [R/W] (InitData, UpdateTEVStages)
    u32 m_field_3A8;  // 0x3A8 [W] (InitGX)
    u8 m_field_3AC;  // 0x3AC [R/W] (EndFrame, InitData, InitVideo)
    u8 _pad_3AD[3];  // 0x3AD
    u32 m_clearColor_3B0;  // 0x3B0 [R/W] (EndFrame, InitData, InitVideo, ...)
    u8 _pad_3B4[4];  // 0x3B4
    u32 m_field_3B8;  // 0x3B8 [W] (InitData)
    u8 m_field_3BC;  // 0x3BC [W] (InitData)
    u8 _pad_3BD[3];  // 0x3BD
    u32 m_field_3C0;  // 0x3C0 [W] (InitData)
    u32 m_field_3C4;  // 0x3C4 [W] (InitData)
    u8 m_field_3C8;  // 0x3C8 [W] (InitData)
    u8 _pad_3C9[0xB];  // 0x3C9
    u8 m_field_3D4;  // 0x3D4 [W] (InitData)
    u8 _pad_3D5[0xC3];  // 0x3D5
    u32 m_field_498;  // 0x498 [W] (WindowMatrix)
    u32 m_field_49C;  // 0x49C [W] (WindowMatrix)
    u8 _pad_4A0[0x38];  // 0x4A0
    u32 m_geometryModes;  // 0x4D8 [R/W] (AlphaTest, ClearRect, DirectRect, ...)
    u32 m_field_4DC;  // 0x4DC [R/W] (DirectRect, Execute, InitData, ...)
    u32 m_field_4E0;  // 0x4E0 [R/W] (Execute)
    u8 _pad_4E4[0x2C];  // 0x4E4
    u32 m_geometryModes_510;  // 0x510 [R/W] (DirectRect, DisableGeometryModes, ENgcRenderer, ...)
    u32 m_shader_514;  // 0x514 [R/W] (InitData, SetShader, UpdateTEVStages)
    f32 m_shader_518;  // 0x518 [R/W] (ENgcRenderer, InitData, Material, ...)
    u8 _pad_51C[0xC];  // 0x51C
    f32 m_shader_528;  // 0x528 [R/W] (ENgcRenderer, InitData, Material, ...)
    u8 _pad_52C[0xC];  // 0x52C
    f32 m_shader_538;  // 0x538 [R/W] (ENgcRenderer, InitData, Material, ...)
    u8 _pad_53C[0x28];  // 0x53C
    u8 m_tEVStages_564;  // 0x564 [R] (UpdateTEVStages)
    u8 m_tEVStages_565;  // 0x565 [R] (UpdateTEVStages)
    u8 m_tEVStages_566;  // 0x566 [R] (UpdateTEVStages)
    u8 m_tEVStages_567;  // 0x567 [R] (UpdateTEVStages)
    u8 m_tEVStages_568;  // 0x568 [R] (UpdateTEVStages)
    u8 _pad_569[0x2B];  // 0x569
    u32 m_tEVStages_594;  // 0x594 [R] (UpdateTEVStages)
    u8 _pad_598[0xC];  // 0x598
    u8 m_tEVStages_5A4;  // 0x5A4 [R] (UpdateTEVStages)
    u8 m_tEVStages_5A5;  // 0x5A5 [R] (UpdateTEVStages)
    u8 m_tEVStages_5A6;  // 0x5A6 [R] (UpdateTEVStages)
    u8 m_tEVStages_5A7;  // 0x5A7 [R] (UpdateTEVStages)
    u8 m_tEVStages_5A8;  // 0x5A8 [R] (UpdateTEVStages)
    u8 _pad_5A9[0x1F];  // 0x5A9
    u32 m_field_5C8;  // 0x5C8 [R/W] (NgcGXDisplayList, NgcGXDisplayListInt, QuadList, ...)
    u32 m_field_5CC;  // 0x5CC [R/W] (QuadList, SimpleSkinning, TriStripPacked, ...)
    u8 _pad_5D0[0x80];  // 0x5D0
    f32 m_lightingEquation;  // 0x650 [R/W] (InitData, Lights, UpdateLightingEquation)
    u8 _pad_654[0xC];  // 0x654
    u32 m_field_660;  // 0x660 [W] (InitData)
    u8 _pad_664[8];  // 0x664
    u32 m_field_66C;  // 0x66C [W] (InitData)
    u8 _pad_670[8];  // 0x670
    u32 m_field_678;  // 0x678 [W] (InitData)
    u8 _pad_67C[8];  // 0x67C
    u32 m_field_684;  // 0x684 [W] (InitData)
    u8 _pad_688[8];  // 0x688
    u32 m_field_690;  // 0x690 [W] (InitData)
    u8 _pad_694[8];  // 0x694
    u32 m_field_69C;  // 0x69C [W] (InitData)
    u8 _pad_6A0[0x2C];  // 0x6A0
    u32 m_field_6CC;  // 0x6CC [R/W] (InitData)
    u32 m_field_6D0;  // 0x6D0 [R/W] (InitData)
    u32 m_field_6D4;  // 0x6D4 [R/W] (InitData)
    u8 _pad_6D8[0x10];  // 0x6D8
    u32 m_field_6E8;  // 0x6E8 [W] (InitData)
    u8 _pad_6EC[4];  // 0x6EC
    u8 m_field_6F0;  // 0x6F0 [W] (InitData)
    u8 _pad_6F1[0x77];  // 0x6F1
    u8 m_lightingEquation_768;  // 0x768 [R/W] (InitData, Lights, UpdateLightingEquation)
    u8 m_lightingEquation_769;  // 0x769 [R/W] (InitData, Lights, UpdateLightingEquation)
    u8 _pad_76A[0x32];  // 0x76A
    u32 m_field_79C;  // 0x79C [W] (InitData)
    u8 _pad_7A0[0x214];  // 0x7A0
    f32 m_field_9B4;  // 0x9B4 [W] (InitData)
    f32 m_field_9B8;  // 0x9B8 [W] (InitData)
    u8 _pad_9BC[4];  // 0x9BC
    f32 m_field_9C0;  // 0x9C0 [W] (InitData)
    u8 _pad_9C4[4];  // 0x9C4
    u32 m_field_9C8;  // 0x9C8 [W] (InitData)
    u8 _pad_9CC[4];  // 0x9CC
    u32 m_field_9D0;  // 0x9D0 [W] (InitData)
    u8 _pad_9D4[0x1330];  // 0x9D4
    f32 m_field_1D04;  // 0x1D04 [R] (InitData)
    f64 m_field_1D08;  // 0x1D08 [R] (InitData)
    u8 _pad_1D10[0xE30];  // 0x1D10
    u32 m_field_2B40;  // 0x2B40 [R] (InitData)
    u8 _pad_2B44[0x1A2C];  // 0x2B44
    u32 m_field_4570;  // 0x4570 [W] (ModelMatrices)
    u8 _pad_4574[0xC0];  // 0x4574
    u8 m_texture;  // 0x4634 [R/W] (InitData, SetTexture)
    u8 _pad_4635[3];  // 0x4635
    u32 m_field_4638;  // 0x4638 [R] (DirectRect, MovieFrame, NgcScreenTriList, ...)
    u32 m_tEVStages_463C;  // 0x463C [R] (UpdateTEVStages)
    u8 _pad_4640[4];  // 0x4640
    u8 m_field_4644;  // 0x4644 [W] (ZTest)
    u8 m_field_4645;  // 0x4645 [W] (ZTest)
    u8 m_field_4646;  // 0x4646 [W] (ZTest)
    u8 _pad_4647[1];  // 0x4647
    u32 m_field_4648;  // 0x4648 [W] (BeginFrame)
    u32 m_field_464C;  // 0x464C [W] (InitVideo)
    u32 m_field_4650;  // 0x4650 [R/W] (EndFrame, InitVideo)
    u8 _pad_4654[8];  // 0x4654
    u32 m_field_465C;  // 0x465C [R/W] (InitData, ParticleListBegin, ParticleListEnd)
    u32 m_field_4660;  // 0x4660 [W] (ParticleListBegin)
    u32 m_field_4664;  // 0x4664 [W] (ParticleListBegin)
};

#endif // ENGCRENDERER_H
