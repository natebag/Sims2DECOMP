#ifndef ESIMSCAM_H
#define ESIMSCAM_H

#include "types.h"

// Forward declarations
class E3DWindow;
class ERC;
class cXObject;
class FrameEffectsManager;

// EVec3 - 3-component vector (12 bytes)
struct EVec3 {
    float x, y, z;
};

namespace InteractorModule {
    enum InteractorType {
        INTERACTOR_DIRECT_CONTROL = 0,
        INTERACTOR_SOCIAL_MODE = 7
    };
}

namespace Panelstateman {
    enum Panelstate {};
}

enum CameraMotionType {
    CAMERA_MOTION_SNAP = 0,
    CAMERA_MOTION_RUBBERBAND = 1
};

enum CameraAnimationMode {};
// CameraNoiseSetting is passed by value as an int
typedef int CameraNoiseSetting;

// SimsCameraParameters - camera tuning parameters
// Layout confirmed from disassembly offset patterns
struct SimsCameraParameters {
    u8 pad00[0x10];                 // 0x00
    float m_translationStiffMin;    // 0x10
    float m_translationStiffMax;    // 0x14
    float m_rotationStiffMin;       // 0x18
    float m_rotationStiffMax;       // 0x1C
    float m_zoomStiffMin;           // 0x20
    float m_zoomStiffMax;           // 0x24
    float m_zoomMin;                // 0x28
    float m_zoomMax;                // 0x2C
    u8 pad30[0x08];                 // 0x30
    float m_tiltMin;                // 0x38
    float m_tiltMax;                // 0x3C
    u8 pad40[0x18];                 // 0x40
    float m_cursorSpeedMin;         // 0x58
    float m_cursorSpeedMax;         // 0x5C
    float m_fovMin;                 // 0x60
    float m_fovMax;                 // 0x64
    float m_farPlane;               // 0x68
    u8 pad6C[0x34];                 // 0x6C
    float m_screenRectLeft;         // 0xA0
    float m_screenRectTop;          // 0xA4
    float m_screenRectRight;        // 0xA8
    float m_screenRectBottom;       // 0xAC
    u8 padB0[0x04];                 // 0xB0
    float m_fieldB4;                // 0xB4
    float m_fieldB8;                // 0xB8

    void Validate();
};

// CameraMotionSystem - 8 bytes total
struct CameraMotionSystem {
    CameraMotionType m_motionType;          // 0x00
    SimsCameraParameters* m_pParams;        // 0x04

    CameraMotionSystem(SimsCameraParameters* params);
    ~CameraMotionSystem();
    void SetMotionType(CameraMotionType type);
    CameraMotionType GetMotionType();
    void MoveCamera(float dt);
    void SnapCamera();
    void RubberBandMove(float dt);
    void RubberBandInterpolate(EVec3* result, EVec3 target, float dt);
    void SetRig(EVec3& eye, EVec3& target, EVec3& up);
};

// CameraParameters - holds target/eye + zoom/rotAng/tilt (24 bytes)
// data[0-2] = position (x, y, z)
// data[3] = zoom
// data[4] = rotAng
// data[5] = tilt
struct CameraParameters {
    float data[6];
};

// NewControlParms
struct NewControlParms {
    void Validate();
};

// ESimsCam - main camera class
// NO vtable at offset 0. Vtable is at offset 0x56C.
// Uses struct (no virtual) so compiler doesn't insert vtable pointer.
struct ESimsCam {
    ESimsCam();
    ~ESimsCam();

    SimsCameraParameters* m_pParams;        // 0x000
    int m_playerId;                         // 0x004
    int m_bMoved;                           // 0x008
    u8 pad0C[0x04];                         // 0x00C
    u8 m_window[0x3BC];                     // 0x010  E3DWindow
    int m_mode;                             // 0x3CC
    u32 m_field3D0;                         // 0x3D0
    u32 m_field3D4;                         // 0x3D4
    u8 pad3D8[0x40];                        // 0x3D8
    EVec3 m_eye;                            // 0x418 (12 bytes)
    EVec3 m_up;                             // 0x424 (12 bytes)
    u8 pad430[0x0C];                        // 0x430
    CameraParameters m_targetParams;        // 0x43C (24 bytes)
    // m_targetParams.data[3] at 0x448 = zoom
    // m_targetParams.data[4] at 0x44C = rotAng
    // m_targetParams.data[5] at 0x450 = tilt
    CameraParameters m_actualParams;        // 0x454 (24 bytes)
    u8 pad46C[0x0C];                        // 0x46C
    u32 m_animFlag;                         // 0x478
    u8 pad47C[0xC4];                        // 0x47C
    u32 m_centerNew;                        // 0x540
    u16 m_roomId;                           // 0x544
    u8 pad546[0x02];                        // 0x546
    u32 m_roomWallsOpaque;                  // 0x548
    u32 m_forceFullScreen;                  // 0x54C
    u8 pad550[0x04];                        // 0x550
    u32 m_animMode;                         // 0x554
    u32 m_animObj1;                         // 0x558
    u32 m_animObj2;                         // 0x55C
    u32 m_controllerFilterId;               // 0x560
    u32 m_interpSocialMode;                 // 0x564
    u32 m_interpLotIntro;                   // 0x568
    void* m_vtable;                         // 0x56C
    int m_activeNoiseSetting;               // (offset approximate, used in Update)

    // Inline zoom/rotAng/tilt accessors into targetParams
    float& zoom()   { return m_targetParams.data[3]; }
    float& rotAng() { return m_targetParams.data[4]; }
    float& tilt()   { return m_targetParams.data[5]; }
    float zoom_const()   const { return m_targetParams.data[3]; }
    float rotAng_const() const { return m_targetParams.data[4]; }
    float tilt_const()   const { return m_targetParams.data[5]; }

    // Accessors
    const EVec3* GetEye() const;
    const EVec3* GetTarget() const;
    const EVec3* GetUp() const;
    const EVec3* GetForward() const;
    void SetTarget(EVec3& target);
    E3DWindow* GetWin();
    float GetZoom() const;
    float GetTilt() const;
    void SetTilt(float tilt);
    int GetbMoved() const;
    float GetRotAng() const;
    int GetMode() const;
    int GetPlayerId();
    void ForceFullScreen(bool force);
    bool IsForceFullScreen();
    void SetCenterNew(bool val);
    int GetRoomId();
    int GetRoomWallsOpaque();
    void SetInterpolatingToOrFromSocialModeCameraFlag(bool flag);
    void SetInterpolatingFromLotIntroCameraFlag(bool flag);

    // Camera operations
    void Init();
    float GetFarPlane();
    void SetFov(float fov);
    float CalcTiltFromZoom(float zoom);
    void SetZoom(float zoom);
    bool PointOffScreen(EVec3& pos);
    float CalcTranslationStiffness() const;
    float CalcRotationStiffness() const;
    float CalcZoomStiffness() const;
    void SnapActualCameraParamsToTarget();
    float GetCursorLimitTopWidth();
    float GetCursorLimitDepth();
    void CursorMoved(int playerId, EVec3& pos);
    float GetCursorSpeed();
    void SetAnimationMode(CameraAnimationMode mode, cXObject* obj1, cXObject* obj2, bool flag);
    int SetControllerFilterId(unsigned int filterId);
    unsigned int GetControllerFilterId() const;
    int ClearControllerFilterId();

    void* operator new(unsigned int size);
    void operator delete(void* ptr);

    // Medium functions
    enum CameraMode {};
    float GetCurZoomRatio();
    float GetFov();
    void ForceFullScreenViewport();
    void Reset();
    void SetState(Panelstateman::Panelstate state);
    void SetMode(CameraMode mode);
    void ApplyPan(float delta);
    void ApplyZoom(float delta);
    bool IsInDeadZone(EVec3& pos) const;
    void GetPos(EVec3& eye, EVec3& target, EVec3& up);
    void ForceTarget(EVec3& target);
    int PointOutsideScreenRect(EVec3& pos, float left, float top, float right, float bottom);
    float CalcPitch(EVec3& dir);
    float CalcZAxisTheta(EVec3& dir);
    EVec3 GetCursorPos();
    void GetObjectPosition(EVec3* outPos, cXObject* obj);
    void GetObjectOrientation(EVec3* outDir, cXObject* obj);
    void DrawDebug(ERC* rc);
    int CursorNotActive();
    void SetActiveNoiseSetting(CameraNoiseSetting setting);
    void Update();
    void FollowPlayerInteractor(int playerId);
    void FollowSimStiff();
    int HandleRotation();
    int HandleZoom();
    void UpdateWin();
    void ReadControllerZoom();
    void ReadControllerRotation();

    static int m_modeDef;
    static NewControlParms s_newControlParms;
};

struct CameraBloomDataElement;

// CameraDirector
struct CameraDirector {
    CameraDirector();
    ~CameraDirector();

    u8 pad000[0x160];
    u32 m_state;                            // 0x160
    u8 pad164[0x04];
    float m_holdTime;                       // 0x168
    u32 m_forceDisableHud;                  // 0x16C
    ESimsCam* m_pCurrentCamera;             // 0x170
    u8 pad174[0x34];
    u8 m_animObj[0x100];                    // 0x1A8
    u8 pad2A8[0x28];
    FrameEffectsManager* m_pFrameEffects;   // 0x2D0

    FrameEffectsManager* GetFrameEffectsManager();
    void InitAnim(int playerId);
    void RegisterCurrentCamera(ESimsCam* cam, bool force);
    void LetterBox(bool enable);
    void SetHoldState(float holdTime);
    void ForceDisableHud(bool disable);
    bool IsForceDisableHud();

    // Medium functions
    void Reset();
    void InitCurrentCamera();
    void EnableControls();
    void DisableControls();
    void AttachDummy(void* dummy, void* mat);
    void InterpToCancelCamera(float time, int type, bool flag);
    void SetFOV(float fov);
    int CheckCancelled();
    void StartAnim(void* animRef, bool loop, bool flag);
    void UpdateAnimNoteTrack();
    void ProcessPropertyEventTags();
    void BloomInterp();
    void BlurInterp();
    void ProcessAnimEvents(void* animRef, int startFrame, int endFrame);
    void AnimEventHandler(void* animRef, void* note, int type);
    void Update();
    void Interp();
    void ReleaseCurrentCamera();
    void CalcCancelCam();
    void UpdateCameraPosAndFOV();
    void BeginCameraBloomInterp(CameraBloomDataElement* bloomData);
};

// CameraManager
struct CameraManager {
    ESimsCam* m_cameras[4];

    void Update();
    void SetCamera(int index, ESimsCam* cam);
    ESimsCam* GetCamera(int index);
};

// ENCamera
struct ENCamera {
    char m_name[64];    // 0x00
    int m_id;           // 0x40
    int m_numKeys;      // 0x44

    void SetName(char* name);
    void SetID(int id);
    void SetKeys(int numKeys);
    char* GetName();
    int GetID();
    int GetKeys();
};

#endif // ESIMSCAM_H
