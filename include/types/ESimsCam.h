/* include/types/ESimsCam.h — canonical layout for ESimsCam + camera helpers
 *
 * S17 TypeArchaeologist Phase 1B deliverable #9.
 *
 * typereq:cXCamera RESOLVED. The actual class is **ESimsCam** (no `cXCamera`
 * exists in the symbol map; camera.obj contains ESimsCam + SimsCameraParameters
 * + CameraMotionSystem + CameraDirector + CameraManager + ENCamera).
 *
 * Provenance: ported from the mature legacy draft at include/camera/esimscam.h
 * (which itself was already evidence-grounded). Cross-checked against 100+
 * matched ESimsCam .cpp files in src/matched/agent/, src/matched/camera/,
 * src/matched/esimscam/.
 *
 * IMPORTANT layout note: ESimsCam has NO vtable at offset 0. Its vtable is
 * stored at offset 0x56C (set in ctor 0x800233C8 / 0x800164D4). The class is
 * declared as a struct (not class) in handwritten matches so the compiler
 * does not auto-insert a vtable pointer at +0x00.
 */
#ifndef SIMS2_TYPES_ESIMSCAM_H
#define SIMS2_TYPES_ESIMSCAM_H

#include "../types.h"

/* Forward decls */
struct E3DWindow;
struct ERC;
struct cXObject;
struct FrameEffectsManager;
struct CameraBloomDataElement;

/* Local float-EVec3 for camera-space coordinates */
struct CAM_EVec3 {
    /* 0x0 */ float x;
    /* 0x4 */ float y;
    /* 0x8 */ float z;
};

namespace InteractorModule {
    enum InteractorType {
        INTERACTOR_DIRECT_CONTROL = 0,
        INTERACTOR_SOCIAL_MODE = 7
    };
}

namespace Panelstateman { enum Panelstate {}; }
enum CameraMotionType { CAMERA_MOTION_SNAP = 0, CAMERA_MOTION_RUBBERBAND = 1 };
enum CameraAnimationMode {};
typedef int CameraNoiseSetting;

/* ============================================================================
 * SimsCameraParameters — camera tuning constants (loaded from window config)
 *
 * Layout verified from the SetupWindow stub at 0x8002269C and a half-dozen
 * accessor stubs that read these specific floats.
 * ========================================================================== */
struct SimsCameraParameters {
    /* 0x00 */ u8    _pad00[0x10];
    /* 0x10 */ float m_translationStiffMin;
    /* 0x14 */ float m_translationStiffMax;
    /* 0x18 */ float m_rotationStiffMin;
    /* 0x1C */ float m_rotationStiffMax;
    /* 0x20 */ float m_zoomStiffMin;
    /* 0x24 */ float m_zoomStiffMax;
    /* 0x28 */ float m_zoomMin;
    /* 0x2C */ float m_zoomMax;
    /* 0x30 */ u8    _pad30[0x08];
    /* 0x38 */ float m_tiltMin;
    /* 0x3C */ float m_tiltMax;
    /* 0x40 */ u8    _pad40[0x18];
    /* 0x58 */ float m_cursorSpeedMin;
    /* 0x5C */ float m_cursorSpeedMax;
    /* 0x60 */ float m_fovMin;
    /* 0x64 */ float m_fovMax;
    /* 0x68 */ float m_farPlane;
    /* 0x6C */ u8    _pad6C[0x34];
    /* 0xA0 */ float m_screenRectLeft;
    /* 0xA4 */ float m_screenRectTop;
    /* 0xA8 */ float m_screenRectRight;
    /* 0xAC */ float m_screenRectBottom;
    /* 0xB0 */ u8    _padB0[0x04];
    /* 0xB4 */ float m_fieldB4;
    /* 0xB8 */ float m_fieldB8;
};

/* ============================================================================
 * CameraMotionSystem — 8 bytes; pairs a motion mode with a parameter ref
 * ========================================================================== */
struct CameraMotionSystem {
    /* 0x0 */ CameraMotionType         m_motionType;
    /* 0x4 */ SimsCameraParameters*    m_pParams;
};

/* CameraParameters — packed target/eye/zoom/rot/tilt vector (24 bytes,
 * 6 floats). Element layout:
 *   data[0..2] = position (x, y, z)
 *   data[3]    = zoom
 *   data[4]    = rotAng
 *   data[5]    = tilt
 */
struct CameraParameters { float data[6]; };

/* NewControlParms — opaque tuning bundle */
struct NewControlParms { /* TODO: layout */ };

/* ============================================================================
 * ESimsCam — primary camera class
 *
 * Total size ≥ 0x570 bytes (vtable at +0x56C + 4).
 * NO vtable at offset 0 — see header note.
 * ========================================================================== */
struct ESimsCam {
    /* 0x000 */ SimsCameraParameters* m_pParams;
    /* 0x004 */ s32           m_playerId;
    /* 0x008 */ s32           m_bMoved;
    /* 0x00C */ u8            _pad00C[0x04];
    /* 0x010 */ u8            m_window[0x3BC];          /* E3DWindow embedded */
    /* 0x3CC */ s32           m_mode;
    /* 0x3D0 */ u32           m_field3D0;
    /* 0x3D4 */ u32           m_field3D4;
    /* 0x3D8 */ u8            _pad3D8[0x40];
    /* 0x418 */ CAM_EVec3     m_eye;
    /* 0x424 */ CAM_EVec3     m_up;
    /* 0x430 */ u8            _pad430[0x0C];
    /* 0x43C */ CameraParameters m_targetParams;        /* zoom @ +0x448,
                                                            rotAng @ +0x44C,
                                                            tilt @ +0x450 */
    /* 0x454 */ CameraParameters m_actualParams;
    /* 0x46C */ u8            _pad46C[0x0C];
    /* 0x478 */ u32           m_animFlag;
    /* 0x47C */ u8            _pad47C[0xC4];
    /* 0x540 */ u32           m_centerNew;
    /* 0x544 */ u16           m_roomId;
    /* 0x546 */ u8            _pad546[0x02];
    /* 0x548 */ u32           m_roomWallsOpaque;
    /* 0x54C */ u32           m_forceFullScreen;
    /* 0x550 */ u8            _pad550[0x04];
    /* 0x554 */ u32           m_animMode;
    /* 0x558 */ u32           m_animObj1;
    /* 0x55C */ u32           m_animObj2;
    /* 0x560 */ u32           m_controllerFilterId;
    /* 0x564 */ u32           m_interpSocialMode;
    /* 0x568 */ u32           m_interpLotIntro;
    /* 0x56C */ void*         m_vtable;                 /* vtable lives HERE,
                                                            NOT at +0x00 */
    /* 0x570+ tail; m_activeNoiseSetting + other fields used by Update */
};

/* ============================================================================
 * CameraDirector — manages active camera + frame effects
 * ========================================================================== */
struct CameraDirector {
    /* 0x000 */ u8                    _pad000[0x160];
    /* 0x160 */ u32                   m_state;
    /* 0x164 */ u8                    _pad164[0x04];
    /* 0x168 */ float                 m_holdTime;
    /* 0x16C */ u32                   m_forceDisableHud;
    /* 0x170 */ ESimsCam*             m_pCurrentCamera;
    /* 0x174 */ u8                    _pad174[0x34];
    /* 0x1A8 */ u8                    m_animObj[0x100];
    /* 0x2A8 */ u8                    _pad2A8[0x28];
    /* 0x2D0 */ FrameEffectsManager*  m_pFrameEffects;
};

/* CameraManager — fixed 4-slot camera array */
struct CameraManager {
    /* 0x0 */ ESimsCam* m_cameras[4];
};

/* ENCamera — camera waypoint/keyframe metadata (used by lattice nav) */
struct ENCamera {
    /* 0x00 */ char m_name[64];
    /* 0x40 */ s32  m_id;
    /* 0x44 */ s32  m_numKeys;
};

/* ============================================================================
 * Function prototypes — ESimsCam matched methods (100+ total; subset)
 * ========================================================================== */

/* Lifecycle */
extern "C" void f_800233C8(void); /* ESimsCam::ESimsCam(int)                  */
extern "C" void f_800164D4(void); /* ESimsCam::ESimsCam(int) — Lane 6 variant?*/
extern "C" void f_8001669C(void); /* ESimsCam::~ESimsCam(void)                */
extern "C" void f_8001E944(void); /* ESimsCam::ctor (alt)                     */
extern "C" void f_8001E9A4(void); /* ESimsCam::operator new(u32)              */
extern "C" void f_8001E9F8(void); /* ESimsCam::operator delete(void*)         */

/* Trivial state getters (all small SEMANTIC-style stubs under src/matched/camera/) */
extern "C" void f_8001EA74(void); /* GetZoom() const                          */
extern "C" void f_8001EA7C(void); /* GetTilt() const                          */
extern "C" void f_8001EA8C(void); /* GetbMoved() const                        */
extern "C" void f_8001EA94(void); /* GetRotAng() const                        */
extern "C" void f_8001EA9C(void); /* GetMode() const                          */
extern "C" void f_8001EAA4(void); /* GetPlayerId()                            */
extern "C" void f_8001EAAC(void); /* ForceFullScreen(bool)                    */
extern "C" void f_8001EAB4(void); /* IsForceFullScreen()                      */
extern "C" void f_8001EABC(void); /* SetCenterNew(bool)                       */
extern "C" void f_8001EAC4(void); /* GetRoomId()                              */
extern "C" void f_8001EACC(void); /* GetRoomWallsOpaque()                     */
extern "C" void f_8001EAD4(void); /* SetInterpolatingToOrFromSocialMode...    */
extern "C" void f_8001EADC(void); /* SetInterpolatingFromLotIntroCamera...    */

/* Camera ops (verified via SEMANTIC matches in src/matched/camera/, esimscam/) */
extern "C" void f_80016728(void); /* GetCurZoomRatio()                        */
extern "C" void f_80016770(void); /* GetNearPlane()                           */
extern "C" void f_80016990(void); /* GetFarPlane()                            */
extern "C" void f_8001699C(void); /* GetFov()                                 */
extern "C" void f_800169E8(void); /* SetFov(float)                            */
extern "C" void f_80016A1C(void); /* ForceFullScreenViewport()                */
extern "C" void f_80016A8C(void); /* Init()                                   */
extern "C" void f_80016AB8(void); /* Reset()                                  */
extern "C" void f_80016B54(void); /* SetState(Panelstateman::Panelstate)      */
extern "C" void f_80016BD4(void); /* SetMode(CameraMode)                      */
extern "C" void f_80016C34(void); /* FollowPlayerInteractor(int)              */
extern "C" void f_80016DB8(void); /* Update()                                 */
extern "C" void f_80016FB8(void); /* ApplyPan(float)                          */
extern "C" void f_80016FFC(void); /* ApplyZoom(float)                         */
extern "C" void f_80017070(void); /* SetZoom(float)                           */
extern "C" void f_8001709C(void); /* HandleRotation()                         */
extern "C" void f_800172E8(void); /* HandleZoom()                             */
extern "C" void f_80017490(void); /* UpdateWin()                              */
extern "C" void f_80017A90(void); /* CalcTiltFromZoom(float)                  */
extern "C" void f_80017ABC(void); /* CalcEyePosition(EVec3&, CameraParameters&) */
extern "C" void f_80017DC0(void); /* ResetPos(float)                          */
extern "C" void f_80017EEC(void); /* FollowSimStiff()                         */
extern "C" void f_800183F4(void); /* IsInDeadZone(EVec3&) const               */
extern "C" void f_800184A0(void); /* CalcTranslationStiffness() const         */
extern "C" void f_800184D8(void); /* CalcRotationStiffness() const            */
extern "C" void f_80018510(void); /* CalcZoomStiffness() const                */
extern "C" void f_80018548(void); /* InterpolateActualCameraParamsToTarget(f) */
extern "C" void f_800187E8(void); /* SnapActualCameraParamsToTarget()         */
extern "C" void f_80018824(void); /* CenterOnSelectedSim()                    */
extern "C" void f_80018E1C(void); /* GetPos(EVec3&, EVec3&, EVec3&)           */
extern "C" void f_80018E74(void); /* SetPosAndReset(EVec3&)                   */
extern "C" void f_80018FE4(void); /* SetPos(EVec3&)                           */
extern "C" void f_8001916C(void); /* ForcePosition(EVec3&)                    */
extern "C" void f_800192FC(void); /* ForceTarget(EVec3&)                      */
extern "C" void f_80019364(void); /* PointOffScreen(EVec3&)                   */
extern "C" void f_80019398(void); /* PointOutsideScreenRect(EVec3&, ...)      */
extern "C" void f_8001942C(void); /* ValidateCursorPosition(int)              */
extern "C" void f_80019628(void); /* CalRoomId(EVec3&)                        */
extern "C" void f_8001976C(void); /* GetContainingRoomId(EVec3&)              */
extern "C" void f_80019A00(void); /* CursorMoved(int, EVec3&)                 */
extern "C" void f_80019A04(void); /* SetWinPos(E3DWindow&)                    */
extern "C" void f_80019DFC(void); /* CalcPitch(EVec3&)                        */
extern "C" void f_80019EA8(void); /* CalcZAxisTheta(EVec3&)                   */
extern "C" void f_80019F6C(void); /* GetCursorPos()                           */
extern "C" void f_8001A00C(void); /* GetCursorSpeed()                         */
extern "C" void f_8001A03C(void); /* GetCursorLimitTopWidth()                 */
extern "C" void f_8001A074(void); /* GetCursorLimitDepth()                    */
extern "C" void f_8001A0AC(void); /* GetObjectPosition(EVec3*, cXObject*)     */
extern "C" void f_8001A168(void); /* GetObjectOrientation(EVec3*, cXObject*)  */
extern "C" void f_8001A22C(void); /* SetAnimationMode(CameraAnimationMode...) */
extern "C" void f_8001A24C(void); /* DrawDebug(ERC*)                          */
extern "C" void f_8001A2B8(void); /* CursorNotActive()                        */
extern "C" void f_8001A328(void); /* SetActiveNoiseSetting(CameraNoiseSetting)*/
extern "C" void f_8001A424(void); /* ApplyNoise(EVec3*)                       */
extern "C" void f_8001AA74(void); /* DrawCameraInfo(ERC*)                     */
extern "C" void f_8001AD94(void); /* SetControllerFilterId(u32)               */
extern "C" void f_8001ADA0(void); /* GetControllerFilterId() const            */
extern "C" void f_8001ADA8(void); /* ClearControllerFilterId()                */
extern "C" void f_8001ADB8(void); /* ReadControllerZoom()                     */
extern "C" void f_8001AE0C(void); /* ReadControllerRotation()                 */
extern "C" void f_8001EA4C(void); /* SetTarget(EVec3&)                        */
extern "C" void f_80026B24(void); /* SetWinPos(E3DWindow&) — alt addr         */

/* CameraDirector */
extern "C" void f_8001B038(void); /* CameraDirector::RegisterCurrentCamera(...) */
extern "C" void f_80029E6C(void); /* CameraDirector::GetFrameEffectsManager() */

#endif /* SIMS2_TYPES_ESIMSCAM_H */
