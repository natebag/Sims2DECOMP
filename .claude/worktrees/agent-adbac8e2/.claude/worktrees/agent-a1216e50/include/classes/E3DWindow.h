#ifndef E3DWINDOW_H
#define E3DWINDOW_H

#include "types.h"

// E3DWindow - struct layout extracted from assembly analysis
// Estimated minimum size: 0x348 (840 bytes)
// 118 known fields (33 named), 90 methods

class E3DWindow {
public:
    // Constructors / Destructors
    E3DWindow(void)  // 0x8079F138
    ~E3DWindow(void);  // 0x807A3A38

    // Methods
    /* ? */ GetNormalizedProjection(void);  // 0x807A49B0 (44B)
    void SetLookAt(EVec3 &, EVec3 &, EVec3 &);  // 0x8079F9BC (112B)
    void SetProjection(float, float, float, float);  // 0x8079F308 (200B)
    void SetViewport(TRect<float> &);  // 0x8079FA2C (88B)
    void SetOrthoProjectionForUIHD(float, float, float, float, float, float, float, float, float, float, float);  // 0x8079F460 (704B)
    void SetOrthoProjection(float, float, float, float, float, float);  // 0x8079F720 (484B)
    void Select(ERC *);  // 0x807A1B8C (340B)
    void TransformToScreen(EVec3 &, EVec2 &);  // 0x807A1E40 (356B)
    /* ? */ Get3DQuadFromScreenTrapAtZ(float, float *, Quad *);  // 0x807A36F4 (836B)
    /* ? */ GetLookDir(void);  // 0x807A492C (44B)
    void Test(EBound3 &);  // 0x807A0B94 (1736B)
    /* ? */ GetLookPos(void);  // 0x807A4900 (44B)
    void TestAsRect(EBound3 &);  // 0x807A125C (948B)
    void Test(EBoundSphere &);  // 0x807A0978 (540B)
    void TransformToWorld(EVec2 &, EVec3 &);  // 0x807A258C (776B)
    void TransformToScreen(EVec3 &, EVec3 &, float);  // 0x807A1FA4 (432B)
    void SetFrustumType(int);  // 0x807A2C58 (84B)
    /* ? */ GetLookAt(void);  // 0x807A4958 (44B)
    void ProjectionMatrixChanged(void);  // 0x807A1A08 (88B)
    void CopyProjection(E3DWindow *);  // 0x8079F3D0 (144B)
    void SetLookAt(EMat4 &);  // 0x8079F904 (92B)
    void LookAtMatrixChanged(void);  // 0x807A1A60 (216B)
    void SetLookAtPos(EMat4 &);  // 0x8079F960 (92B)
    void CalcViewport(void);  // 0x8079FA84 (120B)
    void CalcViewportStructures(void);  // 0x8079FC80 (3320B)
    void CalcViewportInv(void);  // 0x8079FAFC (120B)
    void Test(EVec3 *, int);  // 0x807A1610 (1016B)
    void CalcLookAtDotProjection(void);  // 0x807A1B38 (84B)
    void InputCoordinatesChanged(void);  // 0x807A1CE0 (64B)
    void OutputCoordinatesChanged(void);  // 0x807A1D20 (64B)
    void CalcTextureProjection(EMat4 &);  // 0x807A1D60 (224B)
    void CameraTransformToScreen(EVec3 &, EVec3 &);  // 0x807A2154 (412B)
    void BackCullTest(EVec3 *);  // 0x807A22F0 (668B)
    /* ? */ GetFOVLengths(float *, float *);  // 0x807A2ACC (396B)
    /* ? */ GetNearFar(float *, float *);  // 0x807A2894 (568B)
    void PinToFrustrum(EVec3 *);  // 0x807A2CAC (1360B)
    void CornerToWorld(EVec3 *, int);  // 0x807A31FC (184B)
    void ProjectToZPlane(EVec3 *, float, EVec3 &);  // 0x807A32B4 (408B)
    void MakeLineOnPlane(EVec3 *, float, EVec3 &);  // 0x807A344C (232B)
    /* ? */ GetFrustrumQuadAtZ(float, Quad *);  // 0x807A3534 (448B)
    void Cast3DWindow(void);  // 0x807A49DC (40B)
    /* ? */ GetViewport(void);  // 0x807A48B0 (80B)
    /* ? */ GetProjection(void);  // 0x807A4984 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_orthoProjectionForUIHD;  // 0x000 [R] (CalcViewport, CalcViewportInv, SetOrthoProjectionForUIHD, ...)
    f32 m_orthoProjectionForUIHD_004;  // 0x004 [R/W] (MakeLineOnPlane, ProjectToZPlane, SetOrthoProjectionForUIHD, ...)
    f32 m_orthoProjectionForUIHD_008;  // 0x008 [R/W] (CalcTextureProjection, MakeLineOnPlane, ProjectToZPlane, ...)
    f32 m_orthoProjectionForUIHD_00C;  // 0x00C [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_010;  // 0x010 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    f32 m_orthoProjectionForUIHD_014;  // 0x014 [R/W] (CalcTextureProjection, CalcViewport, CalcViewportInv, ...)
    u32 m_orthoProjectionForUIHD_018;  // 0x018 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_01C;  // 0x01C [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_020;  // 0x020 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_024;  // 0x024 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_028;  // 0x028 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_02C;  // 0x02C [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    f32 m_orthoProjectionForUIHD_030;  // 0x030 [R/W] (CalcTextureProjection, CalcViewport, CalcViewportInv, ...)
    f32 m_orthoProjectionForUIHD_034;  // 0x034 [R/W] (CalcTextureProjection, CalcViewport, CalcViewportInv, ...)
    u32 m_orthoProjectionForUIHD_038;  // 0x038 [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjectionForUIHD_03C;  // 0x03C [R/W] (CalcTextureProjection, SetOrthoProjectionForUIHD)
    f32 m_field_040;  // 0x040 [R] (E3DWindow)
    u8 _pad_044[0xC];  // 0x044
    f32 m_field_050;  // 0x050 [R] (E3DWindow, Select)
    u8 _pad_054[0xC];  // 0x054
    f32 m_field_060;  // 0x060 [R] (CalcViewportStructures)
    f32 m_field_064;  // 0x064 [R] (CalcViewportStructures)
    f32 m_field_068;  // 0x068 [R] (CalcViewportStructures)
    f32 m_field_06C;  // 0x06C [R] (CalcViewportStructures)
    u8 _pad_070[0x2C];  // 0x070
    u32 m_field_09C;  // 0x09C [R/W] (E3DWindow, Select)
    u32 m_lookAt;  // 0x0A0 [W] (SetLookAt)
    u32 m_lookAt_0A4;  // 0x0A4 [W] (SetLookAt)
    u8 _pad_0A8[0x38];  // 0x0A8
    f32 m_3DQuadFromScreenTrapAtZ;  // 0x0E0 [R/W] (CalcViewportStructures, CornerToWorld, Get3DQuadFromScreenTrapAtZ, ...)
    u32 m_lookAtPos;  // 0x0E4 [W] (SetLookAtPos)
    u8 _pad_0E8[8];  // 0x0E8
    f32 m_field_0F0;  // 0x0F0 [R] (TransformToWorld)
    u8 _pad_0F4[0xC];  // 0x0F4
    f32 m_field_100;  // 0x100 [R] (TransformToWorld)
    u8 _pad_104[0xC];  // 0x104
    u32 m_field_110;  // 0x110 [R] (LookAtMatrixChanged)
    u8 _pad_114[0xC];  // 0x114
    u32 m_field_120;  // 0x120 [R] (CalcTextureProjection)
    u32 m_field_124;  // 0x124 [R] (CalcTextureProjection)
    u8 _pad_128[0x38];  // 0x128
    u32 m_orthoProjection;  // 0x160 [R/W] (CopyProjection, ProjectionMatrixChanged, SetOrthoProjection, ...)
    u32 m_orthoProjection_164;  // 0x164 [R/W] (CopyProjection, ProjectionMatrixChanged, SetOrthoProjection, ...)
    u8 _pad_168[0x38];  // 0x168
    u32 m_field_1A0;  // 0x1A0 [W] (ProjectionMatrixChanged)
    u32 m_field_1A4;  // 0x1A4 [W] (ProjectionMatrixChanged)
    u8 _pad_1A8[0x38];  // 0x1A8
    f32 m_orthoProjection_1E0;  // 0x1E0 [R/W] (SetOrthoProjection, SetOrthoProjectionForUIHD)
    u32 m_orthoProjection_1E4;  // 0x1E4 [W] (SetOrthoProjection, SetOrthoProjectionForUIHD)
    u8 _pad_1E8[8];  // 0x1E8
    f32 m_orthoProjection_1F0;  // 0x1F0 [R/W] (SetOrthoProjection, SetOrthoProjectionForUIHD)
    u8 _pad_1F4[0x1C];  // 0x1F4
    f32 m_orthoProjection_210;  // 0x210 [R/W] (SetOrthoProjection, SetOrthoProjectionForUIHD)
    u8 _pad_214[0xC];  // 0x214
    f32 m_viewport;  // 0x220 [R/W] (CalcViewport, CalcViewportInv, E3DWindow, ...)
    f32 m_field_224;  // 0x224 [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_228;  // 0x228 [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_22C;  // 0x22C [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_230;  // 0x230 [R/W] (CalcViewport, CalcViewportInv, E3DWindow, ...)
    f32 m_field_234;  // 0x234 [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_238;  // 0x238 [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_23C;  // 0x23C [R/W] (CalcViewport, CalcViewportInv)
    f32 m_field_240;  // 0x240 [R] (BackCullTest, CalcViewportStructures, TransformToWorld)
    f32 m_field_244;  // 0x244 [R] (BackCullTest, CalcViewportStructures, TransformToWorld)
    f32 m_field_248;  // 0x248 [R] (CalcViewportStructures)
    u8 _pad_24C[4];  // 0x24C
    f32 m_field_250;  // 0x250 [R] (BackCullTest, CalcViewportStructures, TransformToWorld)
    f32 m_field_254;  // 0x254 [R] (BackCullTest, CalcViewportStructures, TransformToWorld)
    f32 m_field_258;  // 0x258 [R] (CalcViewportStructures)
    u8 _pad_25C[0x24];  // 0x25C
    f32 m_3DQuadFromScreenTrapAtZ_280;  // 0x280 [R/W] (CalcViewportStructures, CornerToWorld, Get3DQuadFromScreenTrapAtZ, ...)
    f32 m_field_284;  // 0x284 [R] (CalcViewportStructures)
    f32 m_field_288;  // 0x288 [R] (CalcViewportStructures, ProjectToZPlane)
    f32 m_orthoProjection_28C;  // 0x28C [W] (CopyProjection, E3DWindow, SetOrthoProjection, ...)
    u32 m_field_290;  // 0x290 [W] (LookAtMatrixChanged)
    u8 _pad_294[8];  // 0x294
    f32 m_orthoProjection_29C;  // 0x29C [W] (CopyProjection, E3DWindow, SetOrthoProjection, ...)
    f32 m_field_2A0;  // 0x2A0 [R/W] (CalcViewportStructures, PinToFrustrum, Test, ...)
    f32 m_field_2A4;  // 0x2A4 [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2A8;  // 0x2A8 [R] (PinToFrustrum, Test)
    f32 m_field_2AC;  // 0x2AC [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2B0;  // 0x2B0 [R/W] (CalcViewportStructures, PinToFrustrum, Test, ...)
    f32 m_field_2B4;  // 0x2B4 [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2B8;  // 0x2B8 [R] (PinToFrustrum, Test)
    f32 m_field_2BC;  // 0x2BC [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2C0;  // 0x2C0 [R/W] (CalcViewportStructures, PinToFrustrum, Test, ...)
    f32 m_field_2C4;  // 0x2C4 [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2C8;  // 0x2C8 [R] (PinToFrustrum, Test)
    f32 m_field_2CC;  // 0x2CC [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2D0;  // 0x2D0 [R/W] (CalcViewportStructures, PinToFrustrum, Test, ...)
    f32 m_field_2D4;  // 0x2D4 [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2D8;  // 0x2D8 [R] (PinToFrustrum, Test)
    f32 m_field_2DC;  // 0x2DC [R] (PinToFrustrum, Test, TestAsRect)
    f32 m_field_2E0;  // 0x2E0 [R/W] (CalcViewportStructures, PinToFrustrum, Test)
    f32 m_field_2E4;  // 0x2E4 [R] (PinToFrustrum, Test)
    f32 m_field_2E8;  // 0x2E8 [R] (PinToFrustrum, Test)
    f32 m_field_2EC;  // 0x2EC [R] (PinToFrustrum, Test)
    f32 m_orthoProjection_2F0;  // 0x2F0 [R/W] (CopyProjection, PinToFrustrum, SetOrthoProjection, ...)
    f32 m_orthoProjection_2F4;  // 0x2F4 [R/W] (CopyProjection, SetOrthoProjection, SetOrthoProjectionForUIHD, ...)
    f32 m_orthoProjection_2F8;  // 0x2F8 [R/W] (CopyProjection, PinToFrustrum, SetOrthoProjection, ...)
    u8 m_field_2FC;  // 0x2FC [R] (Test, TestAsRect)
    u8 m_field_2FD;  // 0x2FD [R] (Test, TestAsRect)
    u8 m_field_2FE;  // 0x2FE [R] (Test)
    u8 m_field_2FF;  // 0x2FF [R] (Test, TestAsRect)
    u8 m_field_300;  // 0x300 [R] (Test, TestAsRect)
    u8 m_field_301;  // 0x301 [R] (Test)
    u8 m_field_302;  // 0x302 [R] (Test, TestAsRect)
    u8 m_field_303;  // 0x303 [R] (Test, TestAsRect)
    u8 m_field_304;  // 0x304 [R] (Test)
    u8 m_field_305;  // 0x305 [R] (Test, TestAsRect)
    u8 m_field_306;  // 0x306 [R] (Test, TestAsRect)
    u8 m_field_307;  // 0x307 [R] (Test)
    u8 m_field_308;  // 0x308 [R] (Test)
    u8 m_field_309;  // 0x309 [R] (Test)
    u8 m_field_30A;  // 0x30A [R] (Test)
    u8 m_field_30B;  // 0x30B [R] (Test, TestAsRect)
    u8 m_field_30C;  // 0x30C [R] (Test, TestAsRect)
    u8 m_field_30D;  // 0x30D [R] (Test)
    u8 m_field_30E;  // 0x30E [R] (Test, TestAsRect)
    u8 m_field_30F;  // 0x30F [R] (Test, TestAsRect)
    u8 m_field_310;  // 0x310 [R] (Test)
    u8 m_field_311;  // 0x311 [R] (Test, TestAsRect)
    u8 m_field_312;  // 0x312 [R] (Test, TestAsRect)
    u8 m_field_313;  // 0x313 [R] (Test)
    u8 m_field_314;  // 0x314 [R] (Test, TestAsRect)
    u8 m_field_315;  // 0x315 [R] (Test, TestAsRect)
    u8 m_field_316;  // 0x316 [R] (Test)
    u8 m_field_317;  // 0x317 [R] (Test)
    u8 m_field_318;  // 0x318 [R] (Test)
    u8 m_field_319;  // 0x319 [R] (Test)
    u8 _pad_31A[2];  // 0x31A
    u32 m_field_31C;  // 0x31C [R/W] (CalcViewportStructures, E3DWindow)
    f32 m_field_320;  // 0x320 [R/W] (CalcViewportStructures)
    u8 _pad_324[8];  // 0x324
    f32 m_field_32C;  // 0x32C [R/W] (CalcViewportStructures)
    u8 _pad_330[8];  // 0x330
    f32 m_field_338;  // 0x338 [R/W] (CalcViewportStructures)
    u8 _pad_33C[8];  // 0x33C
    f32 m_field_344;  // 0x344 [R/W] (CalcViewportStructures)
};

#endif // E3DWINDOW_H
