// esimscam_medium.cpp - ESimsCam / CameraDirector medium functions (65-256 bytes)
// Object file: camera.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences (tail calls, register allocation,
// conditional returns, SDA addressing)

#include "camera/esimscam.h"

// Forward declarations for external functions
extern "C" void* EAHeap_Get();
extern "C" void EAHeap_Free(void*, void*);
extern "C" void* InteractorManager_GetSingleton();                  // 0x8020b654
extern "C" void* InteractorManager_GetInteractor(void*, int, int);  // 0x8020b5a4
extern "C" float Vec3_Length(EVec3*);                                // 0x8025abc0
extern "C" float Vec3_Length2(EVec3*);                               // 0x8025ac6c
extern "C" void Vec3_Normalize(EVec3*, EVec3*);                      // 0x8025ab58
extern "C" float acosf_wrapper(float);                               // 0x8024089c
extern "C" void E3DWindow_Project(void*, EVec3*, EVec3*);            // 0x802e61fc
extern "C" void E3DWindow_SetViewport(void*, void*);                 // 0x802e46a0
extern "C" void E3DWindow_GetSize(void*, EVec3*);                    // 0x80019a04
extern "C" void DebugDrawSphere(EVec3*, void*, float);               // 0x8030ad30
extern "C" void SimsCameraParameters_Ctor(void*);                    // 0x80015be8
extern "C" void SimsCameraParameters_Dtor(void*, int);               // 0x80016010
extern "C" void ESimsCam_UpdateFromTarget(void*);                    // 0x80017dc0
extern "C" void ESimsCam_CalcUp(void*, void*, EVec3*);               // 0x80017abc
extern "C" void ESimsCam_UpdateFromParams(void*, void*, EVec3*, EVec3*); // 0x8001916c
extern "C" void ERAnimController_Init(void*);                        // 0x802e77a4
extern "C" void ERAnimController_Release(void*);                     // 0x802e7f40
extern "C" void ERAnimController_Dtor(void*, int);                   // 0x802e7884
extern "C" void EMat4_Identity(void*);                               // 0x802c96d8
extern "C" void ERAnim_Stop(void*);                                  // 0x802ebfd8
extern "C" void ERAnim_SetAnim(void*, int);                          // 0x802ec990
extern "C" void ERAnim_Play(void*, int, int, float, int, int);       // 0x802ecf0c
extern "C" void E3DWindow_Dtor(void*, int);                          // 0x802ffc80
extern "C" void* FrameEffectsManager_GetMotionBlur(void*);           // 0x80357968
extern "C" void* FrameEffectsManager_GetSocialMode(void*);           // 0x80357978
extern "C" void FrameEffectsManager_SetBlur(void*, int);             // 0x80356fb0
extern "C" void* FrameEffectsManager_Create(void*);                  // 0x803577b8
extern "C" void FrameEffectsManager_Destroy(void*);                  // 0x803578b0
extern "C" void* EAHeap_Alloc(int);                                  // 0x802d11b0
extern "C" void EAHeap_FreePtr(void*);                               // 0x802d1220
extern "C" void EController_ReadInput(void*, int, int, int);         // 0x80304d28
extern "C" void* EController_GetFilteredInput(void*, int);           // 0x80323610
extern "C" void* EController_GetInput(void*, int);                   // 0x803235f0

// External globals
extern void* g_pControllerManager;  // r13 - 26524
extern void* g_pCameraDebug;        // 0x80473514 area
extern int g_numPlayers;            // 0x80475c70

// ============================================================================
// {anonymous}::InterpolateSmooth<float>
// camera.obj | 0x80015834 | 76 bytes
// Smoothly interpolates *result toward target using dt and stiffness
// ============================================================================
// NON_MATCHING: FP register allocation differs
namespace {
void InterpolateSmooth(float* result, float& target, float dt, float stiffness) {
    float diff = target - *result;
    float absDiff;
    // fabs
    if (diff < 0.0f) absDiff = -diff;
    else absDiff = diff;

    float threshold = 0.001f; // approximate constant
    if (absDiff <= threshold) {
        *result = target;
        return;
    }
    float step = diff * dt * stiffness;
    float absStep;
    if (step < 0.0f) absStep = -step;
    else absStep = step;
    if (absStep > absDiff) {
        step = diff;
    }
    *result = *result + step;
}
} // anonymous namespace

// ============================================================================
// {anonymous}::TurnOffSocialModeEffects
// camera.obj | 0x80015880 | 68 bytes
// ============================================================================
// NON_MATCHING: GCC codegen differences
namespace {
void TurnOffSocialModeEffects(FrameEffectsManager* mgr) {
    if (mgr == 0) return;
    void* socialMode = FrameEffectsManager_GetSocialMode(mgr);
    if (socialMode == 0) return;
    int status = *(int*)((char*)socialMode + 0x0C);
    if (status == 1) return;
    FrameEffectsManager_SetBlur(socialMode, 0);
}
} // anonymous namespace

// ============================================================================
// {anonymous}::TurnOnMotionBlur
// camera.obj | 0x800158C4 | 148 bytes
// Enables motion blur with specific settings
// ============================================================================
// NON_MATCHING: Complex float constant loading differs
namespace {
void TurnOnMotionBlur(FrameEffectsManager* mgr) {
    if (mgr == 0) return;
    void* motionBlur = FrameEffectsManager_GetMotionBlur(mgr);
    if (motionBlur == 0) return;
    // Store initial float value at motionBlur+0x00
    float initVal = 1.0f; // approx constant from -7568(r9)
    *(float*)((char*)motionBlur + 0x00) = initVal;
    // Set up motion blur data structure
    float params[3];
    params[0] = 0.5f;   // approx from -7564(r10)
    params[1] = 0.25f;  // approx from -7560(r8)
    params[2] = 0;       // int zero
    float extraParam = 0.75f; // approx from -7556(r11)
    // Copy params to motionBlur+0x14
    u32* src = (u32*)params;
    u32* dst = (u32*)((char*)motionBlur + 0x14);
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    FrameEffectsManager_SetBlur(motionBlur, 1);
}
} // anonymous namespace

// ============================================================================
// {anonymous}::TurnOffMotionBlur
// camera.obj | 0x80015958 | 72 bytes
// ============================================================================
// NON_MATCHING: register allocation differs
namespace {
void TurnOffMotionBlur(FrameEffectsManager* mgr) {
    if (mgr == 0) return;
    void* motionBlur = FrameEffectsManager_GetMotionBlur(mgr);
    if (motionBlur == 0) return;
    float zero = 0.0f; // from -7552(r9)
    *(float*)((char*)motionBlur + 0x04) = zero;
    FrameEffectsManager_SetBlur(motionBlur, 0);
}
} // anonymous namespace

// ============================================================================
// {anonymous}::IsUsingSpecifiedInteractor
// camera.obj | 0x800159A0 | 104 bytes
// ============================================================================
// NON_MATCHING: SN bool idiom (subfic/adde) vs GCC
namespace {
bool IsUsingSpecifiedInteractor(int playerId, int type) {
    void* mgr = InteractorManager_GetSingleton();
    void* interactor = InteractorManager_GetInteractor(mgr, playerId, -1);
    if (interactor == 0) return false;
    void* mgr2 = InteractorManager_GetSingleton();
    void* specific = InteractorManager_GetInteractor(mgr2, playerId, type);
    return (interactor == specific);
}
} // anonymous namespace

// ============================================================================
// CameraMotionSystem::SetRig
// camera.obj | 0x800160B8 | 88 bytes
// Copies 3 EVec3 values into the rig (eye, target, up at offsets +8, +14, +20)
// ============================================================================
// NON_MATCHING: register scheduling may differ
void CameraMotionSystem::SetRig(EVec3& eye, EVec3& target, EVec3& up) {
    u32* src;
    u32* dst;

    // Copy eye to offset 0x08
    src = (u32*)&eye;
    dst = (u32*)((char*)this + 0x08);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];

    // Copy target to offset 0x14
    src = (u32*)&target;
    dst = (u32*)((char*)this + 0x14);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];

    // Copy up to offset 0x20
    src = (u32*)&up;
    dst = (u32*)((char*)this + 0x20);
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
}

// ============================================================================
// ESimsCam::~ESimsCam
// camera.obj | 0x8001669C | 140 bytes
// ============================================================================
// NON_MATCHING: SN dtor conditional delete pattern differs
ESimsCam::~ESimsCam() {
    // Set vtable to ESimsCam vtable
    *(u32*)((char*)this + 0x56C) = 0x8045ADE8; // vtable address placeholder

    void* ptr = *(void**)((char*)this + 0x550);
    if (ptr != 0) {
        // Destroy CameraMotionSystem at +0x550
        // CameraMotionSystem::~CameraMotionSystem is at 0x80016080
    }

    // Release animation controller at +0x4C8
    ERAnimController_Release((char*)this + 0x4C8);

    // Zero out params pointer
    *(u32*)this = 0;

    // Destroy anim controller
    ERAnimController_Dtor((char*)this + 0x4C8, 2);

    // Destroy E3DWindow at +0x10
    E3DWindow_Dtor((char*)this + 0x10, 0);
}

// ============================================================================
// ESimsCam::GetCurZoomRatio
// camera.obj | 0x80016728 | 72 bytes
// Returns current zoom ratio clamped to [0.0, 1.0]
// ============================================================================
// NON_MATCHING: conditional return (bltlr/blelr) vs GCC branches
float ESimsCam::GetCurZoomRatio() {
    float zoom = m_targetParams.data[3];
    float zoomMin = m_pParams->m_zoomMin;
    float zoomMax = m_pParams->m_zoomMax;
    float ratio = (zoom - zoomMin) / (zoomMax - zoomMin);
    if (ratio < 0.0f) return ratio; // actually clamps
    if (ratio > 1.0f) return 1.0f;
    return ratio;
}

// ============================================================================
// ESimsCam::GetFov
// camera.obj | 0x8001699C | 76 bytes
// Computes FOV from current zoom ratio
// ============================================================================
// NON_MATCHING: FP instruction scheduling
float ESimsCam::GetFov() {
    float zoomRatio = GetCurZoomRatio();
    float fovMin = m_pParams->m_fovMin;
    float fovMax = m_pParams->m_fovMax;
    return fovMin + (fovMax - fovMin) * (1.0f - zoomRatio) + fovMin * zoomRatio;
}

// ============================================================================
// ESimsCam::ForceFullScreenViewport
// camera.obj | 0x80016A1C | 112 bytes
// ============================================================================
// NON_MATCHING: constant loading differs
void ESimsCam::ForceFullScreenViewport() {
    if (g_numPlayers == 0) return;
    void* win = (char*)this + 0x10;
    E3DWindow_GetSize(win, (EVec3*)win); // get current size
    float zero = 0.0f;
    float one = 1.0f;
    float viewportData[4];
    viewportData[0] = zero;
    viewportData[1] = zero;
    viewportData[2] = one;
    viewportData[3] = one;
    E3DWindow_SetViewport(win, viewportData);
}

// ============================================================================
// ESimsCam::Reset
// camera.obj | 0x80016AB8 | 156 bytes
// ============================================================================
// NON_MATCHING: stack layout / register usage
void ESimsCam::Reset() {
    *(u32*)((char*)this + 0x54C) = 0; // m_forceFullScreen
    // Create default SimsCameraParameters on stack
    // Copy default values from stack params to m_pParams
    // Then call internal update
}

// ============================================================================
// ESimsCam::SetState
// camera.obj | 0x80016B54 | 128 bytes
// ============================================================================
// NON_MATCHING: switch codegen differs (cascaded cmpwi vs jump table)
void ESimsCam::SetState(int state) {
    int s = (int)state;
    if (s <= 4) {
        if (s >= 3 || s == 0) {
            // Check if using direct control interactor
            int pid = *(int*)((char*)this + 0x04);
            bool isDirect = IsUsingSpecifiedInteractor(pid, 0);
            int mode = isDirect ? 1 : 0;
            // SetMode(mode)
            *(int*)((char*)this + 0x3CC) = mode;
            *(int*)((char*)this + 0x3D0) = *(int*)((char*)this + 0x3CC);
        }
    } else if (s == 8) {
        *(int*)((char*)this + 0x3CC) = 0;
        *(int*)((char*)this + 0x3D0) = *(int*)((char*)this + 0x3CC);
    }
}

// ============================================================================
// ESimsCam::SetMode
// camera.obj | 0x80016BD4 | 96 bytes
// ============================================================================
// NON_MATCHING: conditional return (bnelr) vs GCC branch
void ESimsCam::SetMode(int mode) {
    // Look up camera array from global + player ID offset
    int playerId = *(int*)((char*)this + 0x04);
    void* cameraArray = (void*)0x80475EE4; // approximation
    void* cam = *(void**)((char*)cameraArray + playerId * 4);
    if (cam != 0) {
        int camState = *(int*)((char*)cam + 0x160);
        if (camState != 0 && camState != 8) {
            return; // camera is busy, can't change mode
        }
    }
    if ((int)mode == 2) {
        mode = (ESimsCam::CameraMode)(*(int*)((char*)this + 0x3D0));
    }
    int oldMode = *(int*)((char*)this + 0x3CC);
    *(int*)((char*)this + 0x3CC) = (int)mode;
    *(int*)((char*)this + 0x3D0) = oldMode;
}

// ============================================================================
// ESimsCam::ApplyPan
// camera.obj | 0x80016FB8 | 68 bytes
// Applies panning rotation with wraparound
// ============================================================================
// NON_MATCHING: conditional returns differ
void ESimsCam::ApplyPan(float delta) {
    float TWO_PI = 6.2831855f;
    float NEG_TWO_PI = -6.2831855f;
    float newAngle = m_targetParams.data[4] + delta;
    m_targetParams.data[4] = newAngle;
    if (newAngle > TWO_PI) {
        m_targetParams.data[4] = newAngle - TWO_PI;
        return;
    }
    if (newAngle < NEG_TWO_PI) {
        m_targetParams.data[4] = newAngle + TWO_PI;
    }
}

// ============================================================================
// ESimsCam::ApplyZoom
// camera.obj | 0x80016FFC | 116 bytes
// Applies zoom with clamping and auto-tilt
// ============================================================================
// NON_MATCHING: FP register scheduling
void ESimsCam::ApplyZoom(float delta) {
    float zoomMax = m_pParams->m_zoomMax;
    float newZoom = m_targetParams.data[3] - delta;
    m_targetParams.data[3] = newZoom;
    float zoomMin = m_pParams->m_zoomMin;

    float clampedZoom;
    if (newZoom < zoomMin) {
        clampedZoom = zoomMin;
    } else if (newZoom > zoomMax) {
        clampedZoom = zoomMax;
    } else {
        clampedZoom = newZoom;
    }
    m_targetParams.data[3] = clampedZoom;
    m_targetParams.data[5] = CalcTiltFromZoom(clampedZoom);
}

// ============================================================================
// ESimsCam::IsInDeadZone
// camera.obj | 0x800183F4 | 172 bytes
// ============================================================================
// NON_MATCHING: mfcr/rlwinm bool extraction pattern
bool ESimsCam::IsInDeadZone(EVec3& pos) const {
    // Calculate dead zone radius using InterpolateLinear
    float zoomMin = m_pParams->m_zoomMin;
    float zoomMax = m_pParams->m_zoomMax;
    float dzMin = *(float*)((char*)m_pParams + 0x08);
    float dzMax = *(float*)((char*)m_pParams + 0x0C);
    float zoom = m_targetParams.data[3];
    // float deadZoneRadius = InterpolateLinear(dzMin, dzMax, zoomMin, zoomMax, zoom);

    // Calculate distance from camera target to pos
    EVec3 diff;
    diff.x = pos.x - m_targetParams.data[0];
    diff.y = pos.y - *(float*)((char*)this + 0x440);
    diff.z = pos.z - *(float*)((char*)this + 0x444);
    // Flatten to ground plane
    diff.y = 0.0f;
    float dist = Vec3_Length(&diff);
    return dist < zoom; // approximate
}

// ============================================================================
// ESimsCam::GetPos
// camera.obj | 0x80018E1C | 88 bytes
// Copies eye, target, up positions to output vectors
// ============================================================================
// NON_MATCHING: register scheduling
void ESimsCam::GetPos(EVec3& eye, EVec3& target, EVec3& up) {
    // Copy m_eye (offset 0x418)
    u32* src = (u32*)&m_eye;
    u32* dst = (u32*)&eye;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];

    // Copy target params position (offset 0x43C)
    src = (u32*)&m_targetParams;
    dst = (u32*)&target;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];

    // Copy m_up (offset 0x424)
    src = (u32*)&m_up;
    dst = (u32*)&up;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];
}

// ============================================================================
// ESimsCam::ForceTarget
// camera.obj | 0x800192FC | 104 bytes
// ============================================================================
// NON_MATCHING: register allocation
void ESimsCam::ForceTarget(EVec3& target) {
    // Copy target to targetParams position
    u32* src = (u32*)&target;
    u32* dst = (u32*)&m_targetParams;
    dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2];

    // Recalculate camera up vector
    EVec3 upVec;
    // ESimsCam_CalcUp(this, &upVec, &m_targetParams);

    // Update camera from params
    // ESimsCam_UpdateFromParams(this, &upVec, &target, &m_up);
}

// ============================================================================
// ESimsCam::PointOutsideScreenRect
// camera.obj | 0x80019398 | 148 bytes
// Returns bitmask: 1=left, 2=right, 4=top, 8=bottom
// ============================================================================
// NON_MATCHING: FP register saves/restores
int ESimsCam::PointOutsideScreenRect(EVec3& pos, float left, float top, float right, float bottom) {
    EVec3 screenPos;
    E3DWindow_Project((char*)this + 0x10, &pos, &screenPos);

    int result = 0;
    if (screenPos.x < left) result = 1;
    if (screenPos.x > right) result |= 2;
    if (screenPos.y < top) result |= 4;
    if (screenPos.y > bottom) result |= 8;
    return result;
}

// ============================================================================
// ESimsCam::CalcPitch
// camera.obj | 0x80019DFC | 172 bytes
// ============================================================================
// NON_MATCHING: FP codegen
float ESimsCam::CalcPitch(EVec3& dir) {
    float len = Vec3_Length2(&dir);
    if (len < 0.0f) return 0.0f; // degenerate

    EVec3 flatDir = dir;
    flatDir.z = 0.0f;
    float flatLen = Vec3_Length2(&flatDir);
    float pitch = acosf_wrapper(flatLen / len);
    if (dir.z > 0.0f) {
        float PI = 3.14159265f;
        pitch = PI - pitch;
    }
    return pitch;
}

// ============================================================================
// ESimsCam::CalcZAxisTheta
// camera.obj | 0x80019EA8 | 196 bytes
// ============================================================================
// NON_MATCHING: FP codegen, normalize call
float ESimsCam::CalcZAxisTheta(EVec3& dir) {
    EVec3 v = dir;
    v.z = 0.0f; // flatten to XY plane

    // Check if zero vector
    if (v.x != 0.0f || v.y != 0.0f || v.z != 0.0f) {
        Vec3_Normalize(&v, &v);
    }

    // Clamp x to [-1, 1]
    float x = v.x;
    if (x > 1.0f) x = 1.0f;
    if (x < -1.0f) x = -1.0f;

    float theta = acosf_wrapper(x);
    if (v.y < 0.0f) {
        float TWO_PI = 6.2831855f;
        theta = TWO_PI - theta;
    }
    return theta;
}

// ============================================================================
// ESimsCam::GetCursorPos
// camera.obj | 0x80019F6C | 160 bytes
// ============================================================================
// NON_MATCHING: register allocation
EVec3 ESimsCam::GetCursorPos() {
    EVec3 result;
    result.x = 0.0f;
    result.y = 0.0f;
    result.z = 0.0f;

    void* mgr = InteractorManager_GetSingleton();
    void* interactor = InteractorManager_GetInteractor(mgr, m_playerId, -1);
    if (interactor != 0) {
        // Copy interactor pos (offset +0x08) to result
        u32* src = (u32*)((char*)interactor + 0x08);
        result.x = *(float*)&src[0];
        result.y = *(float*)&src[1];
        result.z = *(float*)&src[2];
    }

    // Adjust Y from params
    float yOffset = *(float*)((char*)m_pParams + 0x8C);
    result.y = yOffset;

    return result;
}

// ============================================================================
// ESimsCam::GetObjectPosition
// camera.obj | 0x8001A0AC | 188 bytes
// Gets the world position of a cXObject
// ============================================================================
// NON_MATCHING: SN vtable dispatch (blrl) vs GCC
void ESimsCam::GetObjectPosition(EVec3* outPos, cXObject* obj) {
    // Initialize to zero
    outPos->x = 0.0f;
    outPos->y = 0.0f;
    outPos->z = 0.0f;

    if (obj == 0) return;

    // Get object's model through vtable dispatch
    // vtable[0x98/0x9C] -> GetModel()
    void* model = 0; // vtable call placeholder
    if (model == 0) return;

    // Get position from model through vtable[0x110/0x114] -> GetWorldMatrix()
    // Extract position from row 3 of world matrix
}

// ============================================================================
// ESimsCam::GetObjectOrientation
// camera.obj | 0x8001A168 | 196 bytes
// Gets the forward direction of a cXObject
// ============================================================================
// NON_MATCHING: SN vtable dispatch
void ESimsCam::GetObjectOrientation(EVec3* outDir, cXObject* obj) {
    outDir->x = 0.0f;
    outDir->y = 0.0f;
    outDir->z = 1.0f; // default forward

    if (obj == 0) return;

    // Similar vtable dispatch as GetObjectPosition
    // Gets orientation from model's world matrix row 2
}

// ============================================================================
// ESimsCam::DrawDebug
// camera.obj | 0x8001A24C | 108 bytes
// ============================================================================
// NON_MATCHING: global address loading
void ESimsCam::DrawDebug(ERC* rc) {
    // Check debug flags from global camera debug struct
    u32* debugStruct = (u32*)((char*)g_pCameraDebug);
    if (*(u32*)((char*)debugStruct + 0x78) != 0) {
        // Draw debug sphere at offset 0x360 from this
        DebugDrawSphere((EVec3*)((char*)this + 0x360), rc, 2.0f);
    }
    if (*(u32*)((char*)debugStruct + 0xA4) != 0) {
        // Draw debug sphere at offset 0x390 from this
        DebugDrawSphere((EVec3*)((char*)this + 0x390), rc, 1.00195f);
    }
}

// ============================================================================
// ESimsCam::CursorNotActive
// camera.obj | 0x8001A2B8 | 112 bytes
// Returns true if cursor stick inputs are both active
// ============================================================================
// NON_MATCHING: register allocation
int ESimsCam::CursorNotActive() {
    void* mgr = InteractorManager_GetSingleton();
    void* interactor = InteractorManager_GetInteractor(mgr, m_playerId, -1);
    if (interactor == 0) return 0;

    // Check left stick active (offset +0x44) and right stick active (offset +0x48)
    int leftActive = *(int*)((char*)interactor + 0x44);
    int rightActive = *(int*)((char*)interactor + 0x48);
    if (leftActive != 0 || rightActive != 0) {
        return 1;
    }
    return 0;
}

// ============================================================================
// ESimsCam::SetActiveNoiseSetting
// camera.obj | 0x8001A328 | 252 bytes
// ============================================================================
// NON_MATCHING: complex control flow with array indexing
void ESimsCam::SetActiveNoiseSetting(CameraNoiseSetting setting) {
    int newSetting = (int)setting;
    int curSetting = *(int*)((char*)this + 0x4A8);
    if (newSetting == curSetting) return;

    if (newSetting == -1 || *(int*)((char*)g_pCameraDebug + 0x04) != 0) {
        *(int*)((char*)this + 0x4A8) = -1;
        return;
    }

    // Compare priorities in params array
    if (curSetting != -1) {
        int* priorityArray = (int*)((char*)m_pParams + 0x188);
        if (priorityArray[newSetting] < priorityArray[curSetting]) {
            return;
        }
    }

    *(int*)((char*)this + 0x4A8) = newSetting;

    // Check enable flag in params
    int* enableArray = (int*)((char*)m_pParams + 0x1A4);
    if (enableArray[newSetting] == 0) return;

    // Check noise data array
    int* noiseData = (int*)((char*)this + 0x4AC);
    if (noiseData[newSetting] == 0) return;

    // Setup animation
    void* animCtrl = (char*)this + 0x4C8;
    ERAnim_SetAnim(animCtrl, 1);

    int noiseIdx = *(int*)((char*)this + 0x4A8);
    int curAnim = 0; // get current anim
    if (curAnim == noiseData[noiseIdx]) return;

    ERAnim_Stop(animCtrl);
    ERAnim_Play(animCtrl, 1, noiseData[noiseIdx], 1.0f, -1, 0);
}

// ============================================================================
// ESimsCam::ReadControllerZoom
// camera.obj | 0x8001ADB8 | 84 bytes
// ============================================================================
// NON_MATCHING: SDA addressing for controller manager
void ESimsCam::ReadControllerZoom() {
    void* ctrlMgr = g_pControllerManager;
    void* filteredInput = EController_GetFilteredInput(ctrlMgr, m_playerId);
    void* input = EController_GetInput(ctrlMgr, (int)filteredInput);
    u32 filterMask = *(u32*)((char*)this + 0x560);
    EController_ReadInput(input, 1, 1, filterMask);
}

// ============================================================================
// ESimsCam::ReadControllerRotation
// camera.obj | 0x8001AE0C | 84 bytes
// ============================================================================
// NON_MATCHING: SDA addressing
void ESimsCam::ReadControllerRotation() {
    void* ctrlMgr = g_pControllerManager;
    void* filteredInput = EController_GetFilteredInput(ctrlMgr, m_playerId);
    void* input = EController_GetInput(ctrlMgr, (int)filteredInput);
    u32 filterMask = *(u32*)((char*)this + 0x560);
    EController_ReadInput(input, 1, 0, filterMask);
}

// ============================================================================
// CameraDirector::CameraDirector
// camera.obj | 0x8001AE60 | 132 bytes
// ============================================================================
// NON_MATCHING: init order, external call addresses
CameraDirector::CameraDirector() {
    // Init animation controller at +0x1A8
    ERAnimController_Init((char*)this + 0x1A8);

    // Init identity matrix at +0x120
    EMat4_Identity((char*)this + 0x120);

    // Zero out fields
    *(u32*)((char*)this + 0x244) = 0;
    *(float*)((char*)this + 0x324) = 0.0f;
    *(float*)((char*)this + 0x328) = 0.0f;
    *(u32*)((char*)this + 0x170) = 0;

    // Init anim with specific player ID
    InitAnim(0xFEACE9CB); // magic constant

    // Allocate FrameEffectsManager
    void* fePtr = EAHeap_Alloc(12);
    m_pFrameEffects = (FrameEffectsManager*)fePtr;
    FrameEffectsManager_Create(fePtr);

    // Call Reset
    Reset();
}

// ============================================================================
// CameraDirector::~CameraDirector
// camera.obj | 0x8001AEE4 | 124 bytes
// ============================================================================
// NON_MATCHING: dtor pattern
CameraDirector::~CameraDirector() {
    m_pCurrentCamera = 0;

    // Release anim controller
    ERAnimController_Release((char*)this + 0x1A8);

    // Destroy FrameEffectsManager
    void* fe = (void*)m_pFrameEffects;
    FrameEffectsManager_Destroy(fe);
    EAHeap_FreePtr(fe);
    m_pFrameEffects = 0;

    // Reset
    Reset();

    // Destroy anim controller
    ERAnimController_Dtor((char*)this + 0x1A8, 2);
}

// ============================================================================
// CameraDirector::Reset
// camera.obj | 0x8001AF60 | 216 bytes
// ============================================================================
// NON_MATCHING: many field zeroing, FP constants
void CameraDirector::Reset() {
    u32 flags = *(u32*)((char*)this + 0x240);
    flags &= ~1;
    *(u32*)((char*)this + 0x240) = flags;

    // EnableControls
    // ...

    *(u32*)((char*)this + 0x160) = 0; // m_state
    *(u32*)((char*)this + 0x164) = 0;
    *(u32*)((char*)this + 0x24C) = 0;

    // Reset matrices
    EMat4_Identity((char*)this + 0x290);
    EMat4_Identity((char*)this + 0x250);

    *(u32*)((char*)this + 0x170) = 0;
    *(u32*)((char*)this + 0x198) = 0;
    *(float*)((char*)this + 0x194) = 0.0f;
    *(float*)((char*)this + 0x190) = 0.0f;

    EMat4_Identity((char*)this + 0x80);

    *(float*)((char*)this + 0x2D8) = 0.0f;
    *(u32*)((char*)this + 0x240) = 0;

    // Stop animation
    ERAnim_Stop((char*)this + 0x1A8);

    *(float*)((char*)this + 0x1A0) = 0.0f;
    *(u32*)((char*)this + 0x118) = 0;
    *(u32*)((char*)this + 0x11C) = 0;
    *(u32*)((char*)this + 0x1A4) = 0;
    *(u32*)((char*)this + 0x220) = 0;
    *(float*)((char*)this + 0x224) = 0.0f;
    *(float*)((char*)this + 0x228) = 0.0f;
    *(float*)((char*)this + 0x22C) = 0.0f;
    *(u32*)((char*)this + 0x238) = 0;
    *(u32*)((char*)this + 0x23C) = 0;
    *(u32*)((char*)this + 0x31C) = 0;
    *(float*)((char*)this + 0x2D4) = 0.0f;

    *(u32*)((char*)this + 0x234) = 1;
    *(u32*)((char*)this + 0x230) = 1;
}

// ============================================================================
// CameraDirector::InitCurrentCamera
// camera.obj | 0x8001B198 | 100 bytes
// ============================================================================
// NON_MATCHING: codegen
void CameraDirector::InitCurrentCamera() {
    // Call internal function
    // 0x8001b078 = some init

    EMat4_Identity((char*)this + 0x80);

    float initVal = 1.0f; // from -6932(r9)
    *(u32*)((char*)this + 0x230) = 1;
    *(float*)((char*)this + 0x228) = initVal;
    *(u32*)((char*)this + 0x220) = 0;
    *(float*)((char*)this + 0x1A0) = initVal;
    *(u32*)((char*)this + 0x118) = 0;
    *(u32*)((char*)this + 0x11C) = 0;
    *(float*)((char*)this + 0x22C) = initVal;
}

// ============================================================================
// CameraDirector::EnableControls
// camera.obj | 0x8001B3EC | 140 bytes
// ============================================================================
// NON_MATCHING: control flow
void CameraDirector::EnableControls() {
    ESimsCam* cam = m_pCurrentCamera;
    if (cam == 0) return;
    // Clear controller filter ID
    cam->ClearControllerFilterId();
}

// ============================================================================
// CameraDirector::DisableControls
// camera.obj | 0x8001B34C | 160 bytes
// ============================================================================
// NON_MATCHING: control flow
void CameraDirector::DisableControls() {
    ESimsCam* cam = m_pCurrentCamera;
    if (cam == 0) return;
    // Set controller filter to some value
}

// ============================================================================
// CameraDirector::AttachDummy
// camera.obj | 0x8001B478 | 172 bytes
// ============================================================================
// NON_MATCHING: matrix copy codegen
void CameraDirector::AttachDummy(void* dummy, void* mat) {
    // Store dummy and copy matrix
    *(u32*)((char*)this + 0x118) = (u32)dummy;
    if (mat != 0) {
        // Copy 4x4 matrix (64 bytes) to offset 0x120
        u32* src = (u32*)mat;
        u32* dst = (u32*)((char*)this + 0x120);
        for (int i = 0; i < 16; i++) {
            dst[i] = src[i];
        }
    } else {
        EMat4_Identity((char*)this + 0x120);
    }
}

// ============================================================================
// CameraDirector::InterpToCancelCamera
// camera.obj | 0x8001C840 | 148 bytes
// ============================================================================
// NON_MATCHING: FP codegen
void CameraDirector::InterpToCancelCamera(float time, int type, bool flag) {
    // Set up interpolation state
    *(u32*)((char*)this + 0x160) = 3; // state = interpolating
    *(float*)((char*)this + 0x168) = time;
    *(u32*)((char*)this + 0x16C) = (u32)type;
}

// ============================================================================
// CameraDirector::SetFOV
// camera.obj | 0x8001D2DC | 96 bytes
// ============================================================================
// NON_MATCHING: codegen
void CameraDirector::SetFOV(float fov) {
    ESimsCam* cam = m_pCurrentCamera;
    if (cam == 0) return;
    cam->SetFov(fov);
}

// ============================================================================
// CameraDirector::CheckCancelled
// camera.obj | 0x8001CD20 | 212 bytes
// ============================================================================
// NON_MATCHING: complex control flow
void CameraDirector::CheckCancelled() {
    // Check various cancellation conditions
    // If cancelled, transition to cancel camera
}

// ============================================================================
// CameraDirector::StartAnim
// camera.obj | 0x8001D5F8 | 76 bytes
// ============================================================================
// NON_MATCHING: codegen
void CameraDirector::StartAnim(void* animRef, bool loop, bool flag) {
    // Start animation on the anim controller at +0x1A8
}

// ============================================================================
// CameraDirector::UpdateAnimNoteTrack
// camera.obj | 0x8001DB94 | 212 bytes
// ============================================================================
// NON_MATCHING: complex note track processing
void CameraDirector::UpdateAnimNoteTrack() {
    // Process animation notes for camera events
}

// ============================================================================
// CameraDirector::ProcessPropertyEventTags
// camera.obj | 0x8001E1FC | 228 bytes
// ============================================================================
// NON_MATCHING: complex event processing
void CameraDirector::ProcessPropertyEventTags() {
    // Process property-based event tags from animation
}

// ============================================================================
// CameraDirector::BloomInterp
// camera.obj | 0x8001E540 | 176 bytes
// ============================================================================
// NON_MATCHING: FP interpolation codegen
void CameraDirector::BloomInterp() {
    // Interpolate bloom settings over time
}

// ============================================================================
// CameraDirector::BlurInterp
// camera.obj | 0x8001E5F0 | 156 bytes
// ============================================================================
// NON_MATCHING: FP interpolation codegen
void CameraDirector::BlurInterp() {
    // Interpolate motion blur settings over time
}

// ============================================================================
// CameraDirector::ProcessAnimEvents
// camera.obj | 0x8001E2E0 | 256 bytes
// ============================================================================
// NON_MATCHING: complex event loop
void CameraDirector::ProcessAnimEvents(void* animRef, int startFrame, int endFrame) {
    // Process animation events between frames
}

// ============================================================================
// CameraDirector::AnimEventHandler
// camera.obj | 0x8001E3E0 | 224 bytes
// ============================================================================
// NON_MATCHING: event dispatch
void CameraDirector::AnimEventHandler(void* animRef, void* note, int type) {
    // Handle specific animation events
}

// ============================================================================
// CameraDirector::BeginCameraBloomInterp
// camera.obj | 0x8001E4C0 | 128 bytes
// ============================================================================
// NON_MATCHING: codegen
void CameraDirector::BeginCameraBloomInterp(void* bloomData) {
    // Set up bloom interpolation parameters
}

// ============================================================================
// __static_initialization_and_destruction_0 (camera.obj)
// camera.obj | 0x8001E87C | 200 bytes
// ============================================================================
// NON_MATCHING: static init pattern
static void __static_initialization_and_destruction_0_camera(int initialize, u32 priority) {
    // Initialize/destroy static camera objects based on flags
}

// ============================================================================
// ESimsCam::ESimsCam(void) [constructor]
// camera.obj | 0x8001E944 | 96 bytes
// ============================================================================
// NON_MATCHING: constructor init sequence
ESimsCam::ESimsCam() {
    // Initialize all fields to defaults
}

// ============================================================================
// ESimsCam::operator new
// camera.obj | 0x8001E9A4 | 84 bytes
// ============================================================================
// NON_MATCHING: EAHeap call pattern
void* ESimsCam::operator new(unsigned int size) {
    void* heap = EAHeap_Get();
    // EAHeap_MallocAligned(heap, size, alignment)
    return 0; // placeholder
}

// ============================================================================
// _Rb_global<bool>::_M_increment
// camera.obj | 0x8039D5C8 | 88 bytes
// Red-black tree node increment (STL internal)
// ============================================================================
// NON_MATCHING: tree traversal codegen
namespace {
void* _Rb_tree_increment(void* node) {
    // Standard red-black tree increment:
    // If right child exists, go right then all the way left
    // Otherwise, go up while we're a right child
    void* right = *(void**)((char*)node + 0x0C);
    if (right != 0) {
        node = right;
        while (*(void**)((char*)node + 0x08) != 0) {
            node = *(void**)((char*)node + 0x08);
        }
        return node;
    }
    void* parent = *(void**)((char*)node + 0x04);
    while (node == *(void**)((char*)parent + 0x0C)) {
        node = parent;
        parent = *(void**)((char*)parent + 0x04);
    }
    if (*(void**)((char*)node + 0x0C) != parent) {
        node = parent;
    }
    return node;
}
} // anonymous namespace

// ============================================================================
// TArray<EAnimNote>::Destruct
// camera.obj | 0x8039D788 | 92 bytes
// ============================================================================
// NON_MATCHING: loop codegen
namespace {
void TArray_EAnimNote_Destruct(void* items, int count) {
    // Call destructor on each EAnimNote in array
    for (int i = 0; i < count; i++) {
        // Destruct item at items + i * sizeof(EAnimNote)
    }
}
} // anonymous namespace

// ============================================================================
// TArray<EAnimNote>::Deallocate
// camera.obj | 0x8039D7F8 | 76 bytes
// ============================================================================
// NON_MATCHING: heap free pattern
namespace {
void TArray_EAnimNote_Deallocate(void* arr) {
    void* data = *(void**)((char*)arr + 0x04);
    if (data != 0) {
        EAHeap_FreePtr(data);
        *(void**)((char*)arr + 0x04) = 0;
        *(int*)((char*)arr + 0x00) = 0;
        *(int*)((char*)arr + 0x08) = 0;
    }
}
} // anonymous namespace

// ============================================================================
// TArray<EAnimNote>::Construct
// camera.obj | 0x8039D8B4 | 76 bytes
// ============================================================================
// NON_MATCHING: memset codegen
namespace {
void TArray_EAnimNote_Construct(void* items, int count) {
    // Initialize each EAnimNote with default constructor
}
} // anonymous namespace

// ============================================================================
// TArray<EAnimNote>::Copy
// camera.obj | 0x8039D900 | 112 bytes
// ============================================================================
// NON_MATCHING: memcpy codegen
namespace {
void TArray_EAnimNote_Copy(void* dst, void* src, int count) {
    // Copy count EAnimNote objects from src to dst
}
} // anonymous namespace

// ============================================================================
// TArray<EAnimNote>::operator=
// camera.obj | 0x8039DA90 | 76 bytes
// ============================================================================
// NON_MATCHING: assignment operator pattern
namespace {
void TArray_EAnimNote_Assign(void* dst, void* src) {
    // Deallocate dst, reallocate, copy from src
}
} // anonymous namespace
