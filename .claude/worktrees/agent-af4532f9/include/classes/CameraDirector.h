#ifndef CAMERADIRECTOR_H
#define CAMERADIRECTOR_H

#include "types.h"

// CameraDirector - struct layout extracted from assembly analysis
// Estimated minimum size: 0x44C (1100 bytes)
// 90 known fields (35 named), 99 methods

class CameraDirector {
public:
    // Constructors / Destructors
    CameraDirector(void)  // 0x80042988
    ~CameraDirector(void);  // 0x80042AA4

    // Methods
    bool IsInControl(void);  // 0x8000E33C (72B)
    /* ? */ GetFrameEffectsManager(void);  // 0x80044660 (44B)
    bool IsInSocialModePlayerControlledCameraMode(void);  // 0x8004D130 (56B)
    void InitAnim(int);  // 0x800450F8 (184B)
    void Reset(void);  // 0x80042B34 (340B)
    void Enable(void);  // 0x8004D168 (44B)
    void EnableControls(void);  // 0x800431E8 (192B)
    void ForceDisableHud(bool);  // 0x80046AFC (116B)
    void RegisterCurrentCamera(ESimsCam *, bool);  // 0x80042C88 (120B)
    void InitCurrentCamera(void);  // 0x80042E80 (148B)
    void InitSimsCamera(void);  // 0x80042D00 (384B)
    void ReleaseCurrentCamera(void);  // 0x80042F14 (488B)
    void DisableControls(void);  // 0x800430FC (236B)
    void AttachDummy(ENDummy *, EMat4 *);  // 0x800432A8 (264B)
    bool IsEnabled(void);  // 0x8004D194 (52B)
    void SetCameraCut(ENCamera *);  // 0x800433B0 (416B)
    void SetCameraCutAnim(int);  // 0x80043550 (712B)
    void SetCameraInterp(ENCamera *, float, CamDirInterpType);  // 0x80043818 (440B)
    void SetUpInterpCamera(float, CamDirInterpType);  // 0x80043C0C (748B)
    void SetCameraInterpAnim(int, float, CamDirInterpType, float, bool *);  // 0x800439D0 (572B)
    void ReleaseToGameCamera(void);  // 0x80043EF8 (460B)
    void LetterBox(bool);  // 0x80045DF8 (92B)
    void CalcSimsCam(void);  // 0x800443CC (660B)
    void InterpToGameCamera(float, CamDirInterpType);  // 0x800440C4 (560B)
    void SetHoldState(float);  // 0x800442F4 (52B)
    void InterpToCancelCamera(float, CamDirInterpType, bool);  // 0x80044328 (164B)
    void CalcCancelCam(void);  // 0x8004468C (636B)
    void SetFOV(float);  // 0x80045058 (160B)
    void CheckCancelled(void);  // 0x80044908 (300B)
    void Interp(void);  // 0x80044A34 (1572B)
    void StartAnim(int, bool, bool);  // 0x800451B0 (584B)
    void StartAnim(AnimRef *, bool, bool);  // 0x800453F8 (120B)
    void Update(void);  // 0x80045470 (1208B)
    void UpdateCameraPosAndFOV(void);  // 0x80045A78 (896B)
    void UpdateAnimNoteTrack(void);  // 0x80045928 (336B)
    void ProcessPropertyEventTags(void);  // 0x80046244 (356B)
    void BloomInterp(void);  // 0x8004683C (376B)
    void BlurInterp(void);  // 0x800469B4 (328B)
    void Draw(ERC *);  // 0x80045E54 (1008B)
    void ProcessAnimEvents(AnimRef *, int, int);  // 0x800463A8 (568B)
    void AnimEventHandler(AnimRef *, EAnimNote &, int);  // 0x800465E0 (432B)
    void BeginCameraBloomInterp(CameraBloomDataElement *);  // 0x80046790 (172B)
    bool IsForceDisableHud(void);  // 0x80046B70 (108B)
    /* ? */ GetLetterBox(void);  // 0x80069418 (44B)
    /* ? */ GetOffsetMatrix(void);  // 0x80069444 (44B)
    bool IsLockedState(void);  // 0x800C16FC (56B)
    bool IsHoldState(void);  // 0x801BF840 (56B)
    void SetIsIntroPlaying(bool);  // 0x801BF8D0 (40B)
    void SetLockState(void);  // 0x801BF818 (40B)
    void Disable(void);  // 0x801BF8A4 (44B)
    /* ? */ GetAnimController(void);  // 0x801E9AC4 (44B)
    /* ? */ GetIsIntroPlaying(void);  // 0x80278D08 (44B)
    bool CancelEnable(void);  // 0x803276D4 (40B)
    bool CancelDisable(void);  // 0x803276FC (40B)
    bool IsCancelTriggered(void);  // 0x80327724 (56B)
    bool CanCancel(void);  // 0x805A97F0 (60B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (CalcCancelCam, CalcSimsCam, InterpToGameCamera, ...)
    u32 m_field_004;  // 0x004 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_008;  // 0x008 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_00C;  // 0x00C [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_010;  // 0x010 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_014;  // 0x014 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_018;  // 0x018 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_01C;  // 0x01C [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_020;  // 0x020 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_024;  // 0x024 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_028;  // 0x028 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_02C;  // 0x02C [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_030;  // 0x030 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_034;  // 0x034 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_038;  // 0x038 [R] (CalcCancelCam, CalcSimsCam)
    u32 m_field_03C;  // 0x03C [R] (CalcCancelCam, CalcSimsCam)
    f32 m_cameraPosAndFOV;  // 0x040 [R] (UpdateCameraPosAndFOV)
    u8 _pad_044[0x1C];  // 0x044
    f32 m_field_060;  // 0x060 [R] (Interp)
    u8 _pad_064[0xC];  // 0x064
    f32 m_upInterpCamera;  // 0x070 [R] (Interp, SetUpInterpCamera)
    u8 _pad_074[0xC];  // 0x074
    f32 m_cameraInterp;  // 0x080 [R/W] (CalcCancelCam, CalcSimsCam, Interp, ...)
    u32 m_cameraInterp_084;  // 0x084 [R/W] (CalcCancelCam, CalcSimsCam, SetCameraCut, ...)
    u8 _pad_088[8];  // 0x088
    f32 m_cameraCutAnim;  // 0x090 [R/W] (Interp, SetCameraCutAnim)
    u8 _pad_094[0xC];  // 0x094
    f32 m_cameraCutAnim_0A0;  // 0x0A0 [R/W] (Interp, SetCameraCutAnim)
    u8 _pad_0A4[0xC];  // 0x0A4
    f32 m_cameraCutAnim_0B0;  // 0x0B0 [R/W] (Interp, SetCameraCutAnim)
    f32 m_cameraCutAnim_0B4;  // 0x0B4 [W] (SetCameraCutAnim)
    f32 m_cameraCutAnim_0B8;  // 0x0B8 [W] (SetCameraCutAnim)
    u8 _pad_0BC[0x44];  // 0x0BC
    u32 m_field_100;  // 0x100 [W] (InitSimsCamera)
    u8 _pad_104[8];  // 0x104
    u32 m_field_10C;  // 0x10C [W] (InitSimsCamera)
    u8 _pad_110[8];  // 0x110
    u32 m_cameraInterp_118;  // 0x118 [R/W] (AttachDummy, InitCurrentCamera, ReleaseCurrentCamera, ...)
    u32 m_cameraInterp_11C;  // 0x11C [R/W] (AttachDummy, InitCurrentCamera, ReleaseCurrentCamera, ...)
    u8 _pad_120[0x40];  // 0x120
    u32 m_cameraInterp_160;  // 0x160 [R/W] (CalcCancelCam, CalcSimsCam, Draw, ...)
    u32 m_field_164;  // 0x164 [R/W] (ReleaseCurrentCamera, Reset, StartAnim, ...)
    f32 m_field_168;  // 0x168 [R/W] (StartAnim, Update)
    u8 _pad_16C[4];  // 0x16C
    u32 m_upInterpCamera_170;  // 0x170 [R/W] (AnimEventHandler, CalcCancelCam, CalcSimsCam, ...)
    f32 m_field_174;  // 0x174 [R/W] (CalcCancelCam, CalcSimsCam, InitSimsCamera)
    f32 m_field_178;  // 0x178 [R/W] (CalcCancelCam, CalcSimsCam, InitSimsCamera, ...)
    f32 m_field_17C;  // 0x17C [R/W] (CalcCancelCam, CalcSimsCam, InitSimsCamera, ...)
    f32 m_field_180;  // 0x180 [R/W] (CalcCancelCam, CalcSimsCam, InitSimsCamera, ...)
    f32 m_field_184;  // 0x184 [R/W] (CalcCancelCam, CalcSimsCam, InitSimsCamera, ...)
    f32 m_field_188;  // 0x188 [W] (InitSimsCamera)
    f32 m_field_18C;  // 0x18C [R/W] (InitSimsCamera, Interp)
    f32 m_upInterpCamera_190;  // 0x190 [R/W] (Interp, ReleaseCurrentCamera, Reset, ...)
    f32 m_upInterpCamera_194;  // 0x194 [R/W] (Interp, ReleaseCurrentCamera, Reset, ...)
    u32 m_upInterpCamera_198;  // 0x198 [R/W] (ReleaseCurrentCamera, Reset, SetUpInterpCamera, ...)
    f32 m_upInterpCamera_19C;  // 0x19C [R/W] (Interp, SetUpInterpCamera)
    f32 m_cameraInterp_1A0;  // 0x1A0 [R/W] (CalcCancelCam, CalcSimsCam, InitCurrentCamera, ...)
    u32 m_field_1A4;  // 0x1A4 [W] (Reset, StartAnim)
    u8 _pad_1A8[0x24];  // 0x1A8
    u32 m_cameraCutAnim_1CC;  // 0x1CC [R] (SetCameraCutAnim, SetCameraInterpAnim, StartAnim)
    u8 _pad_1D0[0x50];  // 0x1D0
    u32 m_cameraInterp_220;  // 0x220 [R/W] (AttachDummy, InitCurrentCamera, ProcessPropertyEventTags, ...)
    f32 m_field_224;  // 0x224 [R/W] (InitCurrentCamera, ProcessPropertyEventTags, ReleaseCurrentCamera, ...)
    f32 m_field_228;  // 0x228 [R/W] (InitCurrentCamera, ProcessPropertyEventTags, ReleaseCurrentCamera, ...)
    f32 m_cameraInterp_22C;  // 0x22C [R/W] (AttachDummy, InitCurrentCamera, InterpToCancelCamera, ...)
    u32 m_cameraInterp_230;  // 0x230 [R/W] (AttachDummy, InitCurrentCamera, ReleaseCurrentCamera, ...)
    u32 m_field_234;  // 0x234 [R/W] (Draw, Reset)
    u32 m_cameraInterp_238;  // 0x238 [R/W] (AttachDummy, CheckCancelled, InterpToGameCamera, ...)
    u32 m_field_23C;  // 0x23C [R/W] (InterpToCancelCamera, Reset, Update)
    u32 m_cameraInterp_240;  // 0x240 [R/W] (AttachDummy, CheckCancelled, InterpToCancelCamera, ...)
    u32 m_field_244;  // 0x244 [R/W] (CameraDirector, CheckCancelled, DisableControls, ...)
    u32 m_field_248;  // 0x248 [R/W] (DisableControls, EnableControls, ReleaseCurrentCamera)
    u32 m_cameraCutAnim_24C;  // 0x24C [R/W] (CalcCancelCam, ReleaseCurrentCamera, Reset, ...)
    f32 m_cameraCutAnim_250;  // 0x250 [R] (SetCameraCutAnim)
    u8 _pad_254[0xC];  // 0x254
    f32 m_cameraCutAnim_260;  // 0x260 [R] (SetCameraCutAnim)
    u8 _pad_264[0xC];  // 0x264
    f32 m_cameraCutAnim_270;  // 0x270 [R] (SetCameraCutAnim)
    u8 _pad_274[0xC];  // 0x274
    f32 m_cameraCutAnim_280;  // 0x280 [R] (SetCameraCutAnim)
    u8 _pad_284[0xC];  // 0x284
    f32 m_cameraCutAnim_290;  // 0x290 [R/W] (SetCameraCutAnim)
    u32 m_cameraCutAnim_294;  // 0x294 [W] (SetCameraCutAnim)
    u8 _pad_298[0x38];  // 0x298
    u32 m_field_2D0;  // 0x2D0 [R/W] (CameraDirector, ~CameraDirector)
    f32 m_field_2D4;  // 0x2D4 [R/W] (BeginCameraBloomInterp, BloomInterp, Reset, ...)
    f32 m_animNoteTrack;  // 0x2D8 [R/W] (BlurInterp, Reset, UpdateAnimNoteTrack)
    f32 m_field_2DC;  // 0x2DC [R] (BloomInterp)
    f32 m_field_2E0;  // 0x2E0 [R] (BloomInterp)
    f32 m_field_2E4;  // 0x2E4 [R] (BloomInterp)
    f32 m_field_2E8;  // 0x2E8 [R] (BloomInterp)
    f32 m_field_2EC;  // 0x2EC [R/W] (BeginCameraBloomInterp, BloomInterp)
    f32 m_field_2F0;  // 0x2F0 [R] (BloomInterp)
    f32 m_field_2F4;  // 0x2F4 [R] (BloomInterp)
    f32 m_field_2F8;  // 0x2F8 [R] (BloomInterp)
    f32 m_field_2FC;  // 0x2FC [R] (BlurInterp)
    f32 m_field_300;  // 0x300 [R] (BlurInterp)
    f32 m_field_304;  // 0x304 [R] (BlurInterp)
    f32 m_field_308;  // 0x308 [R] (BlurInterp)
    f32 m_field_30C;  // 0x30C [R] (BlurInterp)
    f32 m_field_310;  // 0x310 [R] (BlurInterp)
    f32 m_field_314;  // 0x314 [R] (BlurInterp)
    f32 m_field_318;  // 0x318 [R] (BlurInterp)
    u32 m_field_31C;  // 0x31C [R/W] (BeginCameraBloomInterp, BloomInterp, BlurInterp, ...)
    u32 m_field_320;  // 0x320 [R/W] (InterpToGameCamera, ReleaseToGameCamera)
    f32 m_cameraInterpAnim;  // 0x324 [R/W] (CameraDirector, InterpToGameCamera, ReleaseToGameCamera, ...)
    f32 m_cameraInterpAnim_328;  // 0x328 [R/W] (CameraDirector, InterpToGameCamera, ReleaseToGameCamera, ...)
    u8 _pad_32C[0x11C];  // 0x32C
    f32 m_cameraInterpAnim_448;  // 0x448 [R] (InterpToGameCamera, SetCameraInterpAnim)
};

#endif // CAMERADIRECTOR_H
