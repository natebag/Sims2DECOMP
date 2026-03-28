#ifndef ESIMSCAM_H
#define ESIMSCAM_H

#include "types.h"

// ESimsCam - struct layout extracted from assembly analysis
// Estimated minimum size: 0x570 (1392 bytes)
// 66 known fields (32 named), 166 methods

class ESimsCam {
public:
    // Static members (from map file)
    // static ??? m_degRotAngDef;
    // static ??? m_degTiltAngDef;
    // static ??? m_zoomDef;
    // static ??? m_vEyeDef;
    // static ??? m_vTargetDef;
    // static ??? m_vUpDef;

    // Constructors / Destructors
    ESimsCam(int)  // 0x8003C018
    ESimsCam(void)  // 0x8004CB40
    ~ESimsCam(void);  // 0x8003C3DC

    // Methods
    /* ? */ GetPlayerId(void);  // 0x8004CF50 (44B)
    /* ? */ GetCurZoomRatio(void);  // 0x8003C4A4 (168B)
    /* ? */ GetNearPlane(void);  // 0x8003C54C (784B)
    /* ? */ GetFarPlane(void);  // 0x8003C85C (48B)
    /* ? */ GetFov(void);  // 0x8003C88C (232B)
    void SetFov(float);  // 0x8003C974 (260B)
    void ForceFullScreenViewport(void);  // 0x8003CA78 (152B)
    void SetWinPos(E3DWindow &);  // 0x80040CB0 (1180B)
    void Init(void);  // 0x8003CB10 (96B)
    void Reset(void);  // 0x8003CB70 (164B)
    void ResetPos(float);  // 0x8003E2C8 (404B)
    void SetState(Panelstateman::Panelstate);  // 0x8003CC14 (172B)
    void SetMode(ESimsCam::CameraMode);  // 0x8003CCC0 (180B)
    void FollowPlayerInteractor(int);  // 0x8003CD74 (400B)
    void Update(void);  // 0x8003CF04 (892B)
    void CursorNotActive(void);  // 0x80041984 (128B)
    void SetActiveNoiseSetting(CameraNoiseSetting);  // 0x80041A04 (512B)
    void UpdateWin(void);  // 0x8003D89C (1848B)
    void FollowSimStiff(void);  // 0x8003E45C (1952B)
    void HandleRotation(void);  // 0x8003D3D8 (732B)
    void HandleZoom(void);  // 0x8003D6B4 (488B)
    void ApplyPan(float);  // 0x8003D280 (88B)
    void ApplyZoom(float);  // 0x8003D2D8 (172B)
    void CalcTiltFromZoom(float);  // 0x8003DFD4 (144B)
    void SetZoom(float);  // 0x8003D384 (84B)
    void ReadControllerRotation(void);  // 0x8004290C (124B)
    /* ? */ GetCursorPos(void);  // 0x8004134C (196B)
    void PointOffScreen(EVec3 &);  // 0x800400B0 (108B)
    void ReadControllerZoom(void);  // 0x80042890 (124B)
    void CalRoomId(EVec3 &);  // 0x8004053C (628B)
    void CalcEyePosition(EVec3 &, ESimsCam::CameraParameters &);  // 0x8003E064 (612B)
    void CenterOnSelectedSim(void);  // 0x8003F160 (2336B)
    void CalcZAxisTheta(EVec3 &);  // 0x80041264 (232B)
    bool IsInDeadZone(EVec3 &);  // 0x8003EBFC (200B)
    void CalcTranslationStiffness(void);  // 0x8003ECC4 (100B)
    void CalcRotationStiffness(void);  // 0x8003ED28 (100B)
    void CalcZoomStiffness(void);  // 0x8003ED8C (100B)
    void InterpolateActualCameraParamsToTarget(float);  // 0x8003EDF0 (792B)
    void SnapActualCameraParamsToTarget(void);  // 0x8003F108 (88B)
    /* ? */ GetPos(EVec3 &, EVec3 &, EVec3 &);  // 0x8003FA80 (152B)
    void SetPosAndReset(EVec3 &, EVec3 &, EVec3 &);  // 0x8003FB18 (400B)
    void SetPos(EVec3 &, EVec3 &, EVec3 &);  // 0x8003FCA8 (448B)
    void CalcPitch(EVec3 &);  // 0x8004114C (280B)
    void ForcePosition(EVec3 &, EVec3 &, EVec3 &);  // 0x8003FE68 (456B)
    void ForceTarget(EVec3 &);  // 0x80040030 (128B)
    void SetTarget(EVec3 &);  // 0x8004CDDC (68B)
    void PointOutsideScreenRect(EVec3 &, float, float, float, float);  // 0x8004011C (324B)
    /* ? */ GetWin(void);  // 0x8004CE20 (44B)
    void ValidateCursorPosition(int, EVec3 *);  // 0x80040260 (732B)
    /* ? */ GetCursorLimitTopWidth(void);  // 0x80041498 (144B)
    /* ? */ GetCursorLimitDepth(void);  // 0x80041528 (144B)
    /* ? */ GetContainingRoomId(EVec3 &);  // 0x800407B0 (1240B)
    void CursorMoved(int, EVec3 &);  // 0x80040C88 (40B)
    void ApplyNoise(EVec3, EVec3, EVec3);  // 0x80041C04 (1916B)
    /* ? */ GetObjectPosition(EVec3 *, cXObject *);  // 0x800415B8 (372B)
    /* ? */ GetObjectOrientation(EVec3 *, cXObject *);  // 0x8004172C (372B)
    /* ? */ GetCursorSpeed(void);  // 0x80041410 (136B)
    void SetAnimationMode(CameraAnimationMode, cXObject *, cXObject *, bool);  // 0x800418A0 (92B)
    void DrawDebug(ERC *);  // 0x800418FC (136B)
    void DrawCameraInfo(ERC *);  // 0x80042380 (1152B)
    void SetControllerFilterId(unsigned int);  // 0x80042800 (52B)
    /* ? */ GetControllerFilterId(void);  // 0x80042834 (44B)
    void ClearControllerFilterId(void);  // 0x80042860 (48B)
    void SetInterpolatingToOrFromSocialModeCameraFlag(bool);  // 0x8004D054 (40B)
    void SetInterpolatingFromLotIntroCameraFlag(bool);  // 0x8004D07C (40B)
    /* ? */ GetTilt(void);  // 0x8004CE78 (44B)
    /* ? */ GetZoom(void);  // 0x8004CE4C (44B)
    void SetCenterNew(bool);  // 0x8004CFD0 (40B)
    /* ? */ GetEye(void);  // 0x8004CD2C (44B)
    /* ? */ GetTarget(void);  // 0x8004CD58 (44B)
    /* ? */ GetUp(void);  // 0x8004CD84 (44B)
    /* ? */ GetForward(void);  // 0x8004CDB0 (44B)
    void SetTilt(float);  // 0x8004CEA4 (40B)
    /* ? */ GetbMoved(void);  // 0x8004CECC (44B)
    /* ? */ GetRotAng(void);  // 0x8004CEF8 (44B)
    /* ? */ GetMode(void);  // 0x8004CF24 (44B)
    void ForceFullScreen(bool);  // 0x8004CF7C (40B)
    bool IsForceFullScreen(void);  // 0x8004CFA4 (44B)
    /* ? */ GetRoomId(void);  // 0x8004CFF8 (48B)
    /* ? */ GetRoomWallsOpaque(void);  // 0x8004D028 (44B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_fov;  // 0x000 [R/W] (ApplyNoise, ApplyZoom, CalRoomId, ...)
    u16 m_win;  // 0x002 [R] (UpdateWin)
    f32 m_containingRoomId;  // 0x004 [R/W] (ApplyNoise, CalcPitch, CalcZAxisTheta, ...)
    f32 m_cursorPos;  // 0x008 [R/W] (ApplyNoise, CalcPitch, CalcZAxisTheta, ...)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R] (Update)
    u8 _pad_014[4];  // 0x014
    u32 m_objectPosition;  // 0x018 [R] (GetObjectOrientation, GetObjectPosition)
    u8 _pad_01C[0x14];  // 0x01C
    u32 m_field_030;  // 0x030 [R] (ApplyNoise)
    u8 _pad_034[0x10];  // 0x034
    u32 m_field_044;  // 0x044 [R] (CursorNotActive)
    u32 m_field_048;  // 0x048 [R] (CursorNotActive)
    u8 _pad_04C[0x64];  // 0x04C
    f32 m_nearPlane;  // 0x0B0 [R] (GetNearPlane)
    u8 _pad_0B4[0x34];  // 0x0B4
    s16 m_containingRoomId_0E8;  // 0x0E8 [R] (GetContainingRoomId)
    u8 _pad_0EA[0x276];  // 0x0EA
    f32 m_field_360;  // 0x360 [R/W] (ValidateCursorPosition)
    u8 _pad_364[8];  // 0x364
    f32 m_field_36C;  // 0x36C [R/W] (ValidateCursorPosition)
    u8 _pad_370[8];  // 0x370
    f32 m_field_378;  // 0x378 [R] (ValidateCursorPosition)
    u8 _pad_37C[8];  // 0x37C
    f32 m_field_384;  // 0x384 [R] (ValidateCursorPosition)
    u8 _pad_388[8];  // 0x388
    f32 m_win_390;  // 0x390 [R/W] (UpdateWin)
    u8 _pad_394[8];  // 0x394
    f32 m_win_39C;  // 0x39C [R/W] (UpdateWin)
    u8 _pad_3A0[8];  // 0x3A0
    f32 m_win_3A8;  // 0x3A8 [R/W] (UpdateWin)
    u8 _pad_3AC[8];  // 0x3AC
    f32 m_win_3B4;  // 0x3B4 [R/W] (UpdateWin)
    u8 _pad_3B8[0x14];  // 0x3B8
    u32 m_mode;  // 0x3CC [R/W] (CenterOnSelectedSim, SetMode, Update)
    u32 m_mode_3D0;  // 0x3D0 [R/W] (CenterOnSelectedSim, SetMode)
    u8 _pad_3D4[0x44];  // 0x3D4
    f32 m_pos;  // 0x418 [R/W] (DrawCameraInfo, FollowSimStiff, ForcePosition, ...)
    f32 m_win_41C;  // 0x41C [R] (DrawCameraInfo, UpdateWin)
    f32 m_field_420;  // 0x420 [R] (DrawCameraInfo, HandleRotation, HandleZoom)
    f32 m_pos_424;  // 0x424 [R/W] (ForcePosition, ResetPos, SetPos, ...)
    u8 _pad_428[8];  // 0x428
    u32 m_field_430;  // 0x430 [W] (CenterOnSelectedSim, FollowPlayerInteractor)
    u8 _pad_434[8];  // 0x434
    f32 m_pos_43C;  // 0x43C [R/W] (CenterOnSelectedSim, DrawCameraInfo, FollowPlayerInteractor, ...)
    f32 m_field_440;  // 0x440 [R/W] (CenterOnSelectedSim, DrawCameraInfo, FollowSimStiff)
    f32 m_winPos;  // 0x444 [R/W] (CenterOnSelectedSim, DrawCameraInfo, SetWinPos)
    f32 m_curZoomRatio;  // 0x448 [R/W] (ApplyZoom, FollowSimStiff, ForcePosition, ...)
    f32 m_pos_44C;  // 0x44C [R/W] (ApplyPan, FollowSimStiff, ForcePosition, ...)
    f32 m_pos_450;  // 0x450 [R/W] (ApplyZoom, ForcePosition, InterpolateActualCameraParamsToTarget, ...)
    f32 m_winPos_454;  // 0x454 [R/W] (FollowPlayerInteractor, InterpolateActualCameraParamsToTarget, SetWinPos)
    f32 m_field_458;  // 0x458 [R] (InterpolateActualCameraParamsToTarget)
    u8 _pad_45C[4];  // 0x45C
    f32 m_field_460;  // 0x460 [R] (InterpolateActualCameraParamsToTarget)
    f32 m_field_464;  // 0x464 [R/W] (InterpolateActualCameraParamsToTarget)
    f32 m_field_468;  // 0x468 [R/W] (InterpolateActualCameraParamsToTarget)
    u32 m_field_46C;  // 0x46C [R/W] (ESimsCam, InterpolateActualCameraParamsToTarget)
    f32 m_field_470;  // 0x470 [R/W] (ESimsCam, FollowSimStiff, InterpolateActualCameraParamsToTarget)
    u32 m_field_474;  // 0x474 [R/W] (ESimsCam, FollowSimStiff, HandleRotation)
    u32 m_winPos_478;  // 0x478 [R/W] (CenterOnSelectedSim, ForcePosition, ResetPos, ...)
    u32 m_field_47C;  // 0x47C [W] (ESimsCam)
    u8 _pad_480[8];  // 0x480
    u32 m_field_488;  // 0x488 [W] (ESimsCam)
    u8 _pad_48C[8];  // 0x48C
    u32 m_field_494;  // 0x494 [W] (ESimsCam)
    u8 _pad_498[8];  // 0x498
    f32 m_field_4A0;  // 0x4A0 [W] (ESimsCam)
    f32 m_field_4A4;  // 0x4A4 [W] (ESimsCam)
    u32 m_activeNoiseSetting;  // 0x4A8 [R/W] (ESimsCam, SetActiveNoiseSetting, Update)
    u32 m_field_4AC;  // 0x4AC [W] (ESimsCam)
    u32 m_field_4B0;  // 0x4B0 [W] (ESimsCam)
    u32 m_field_4B4;  // 0x4B4 [W] (ESimsCam)
    u32 m_field_4B8;  // 0x4B8 [W] (ESimsCam)
    u32 m_field_4BC;  // 0x4BC [W] (ESimsCam)
    u32 m_field_4C0;  // 0x4C0 [W] (ESimsCam)
    u32 m_field_4C4;  // 0x4C4 [W] (ESimsCam)
    u8 _pad_4C8[0x78];  // 0x4C8
    u32 m_field_540;  // 0x540 [R/W] (CenterOnSelectedSim, ESimsCam)
    u16 m_win_544;  // 0x544 [R/W] (ESimsCam, UpdateWin)
    u8 _pad_546[2];  // 0x546
    u32 m_win_548;  // 0x548 [W] (ESimsCam, UpdateWin)
    u32 m_field_54C;  // 0x54C [W] (Reset)
    u32 m_winPos_550;  // 0x550 [R/W] (ESimsCam, HandleRotation, HandleZoom, ...)
    u32 m_winPos_554;  // 0x554 [R] (SetWinPos)
    u32 m_winPos_558;  // 0x558 [R] (SetWinPos)
    u32 m_winPos_55C;  // 0x55C [R] (SetWinPos)
    u32 m_field_560;  // 0x560 [R/W] (ESimsCam, ReadControllerRotation, ReadControllerZoom)
    u32 m_nearPlane_564;  // 0x564 [R/W] (ESimsCam, GetNearPlane, InterpolateActualCameraParamsToTarget, ...)
    u32 m_nearPlane_568;  // 0x568 [R/W] (ESimsCam, GetNearPlane, InterpolateActualCameraParamsToTarget, ...)
    u32 m_field_56C;  // 0x56C [W] (ESimsCam, ~ESimsCam)
};

#endif // ESIMSCAM_H
