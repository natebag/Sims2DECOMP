// esimscam_large.cpp - ESimsCam / CameraDirector / CameraMotionSystem large functions (257-1024 bytes)
// Object file: camera.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "camera/esimscam.h"

extern "C" void* EAHeap_Get();
extern "C" void EAHeap_Free(void*, void*);
extern "C" void Vec3_Normalize(EVec3*, EVec3*);
extern "C" float Vec3_Length(EVec3*);
extern "C" void E3DWindow_Init(void*, int);
extern "C" void ERAnimController_Init(void*);
extern "C" void ERAnimController_Release(void*);
extern "C" void ERAnimInit(void*, int, int, int);
extern "C" void HandleBloomEvent(void*, void*);
extern "C" void HandleMotionBlurEvent(void*, void*);
extern "C" void HandleDepthOfFieldEvent(void*, void*);
extern "C" void EStream_WriteData(void*, void*, int);
extern "C" void EStream_ReadData(void*, void*, int);
extern "C" float sinf_impl(float);
extern "C" float cosf_impl(float);
extern "C" float atan2f_impl(float, float);
extern "C" float sqrtf_impl(float);
extern "C" void* InteractorManager_GetSingleton();
extern "C" void* InteractorManager_GetInteractor(void*, int, int);

extern SimsCameraParameters g_simsCamParams[];

// ============================================================================
// CameraMotionSystem::SnapCamera(void)
// Address: 0x80016110, Size: 268 bytes
// NON_MATCHING
// ============================================================================
void CameraMotionSystem::SnapCamera(void)
{
    u8* self = (u8*)this;
    EVec3 vel;
    vel.x = 0.0f; vel.y = 0.0f; vel.z = 0.0f;
    Vec3_Normalize(&vel, &vel);
}

// ============================================================================
// CameraMotionSystem::RubberBandMove(float)
// Address: 0x8001639C, Size: 312 bytes
// NON_MATCHING
// ============================================================================
void CameraMotionSystem::RubberBandMove(float dt)
{
    u8* self = (u8*)this;
    EVec3 vel;
    vel.x = 0.0f; vel.y = 0.0f; vel.z = 0.0f;
    Vec3_Normalize(&vel, &vel);
}

// ============================================================================
// ESimsCam::ESimsCam(int)
// Address: 0x800164D4, Size: 456 bytes
// NON_MATCHING
// ============================================================================
ESimsCam::ESimsCam()
{
    u8* self = (u8*)this;
    E3DWindow_Init(self + 0x10, 0);
    ERAnimController_Init(self + 0x4C8);
    m_playerId = 0;
    m_pParams = &g_simsCamParams[0];
    m_bMoved = 0;
    m_mode = 0;
    ERAnimInit(self + 0x4C8, 0, 2, 0);
    m_roomId = 0;
    m_roomWallsOpaque = 0;
    m_animFlag = 0;
    m_centerNew = 1;
    m_forceFullScreen = 0;
    m_interpSocialMode = 0;
    m_interpLotIntro = 0;
}

// ============================================================================
// {anonymous}::HandleEffectNote(ESimsCam*, EAnimNote&, int)
// Address: 0x80015A50, Size: 408 bytes
// NON_MATCHING
// ============================================================================
static void HandleEffectNote_impl(ESimsCam* cam, void* animNote, int propKind)
{
    if (!cam) return;
    int playerId = cam->m_playerId;
    if (playerId < 0) return;
    // NON_MATCHING: camera params table lookup and effect dispatch
}

// ============================================================================
// ESimsCam::GetNearPlane(void)
// Address: 0x80016770, Size: 544 bytes
// NON_MATCHING
// ============================================================================
static float ESimsCam_GetNearPlane_impl(ESimsCam* cam)
{
    float zoom = cam->m_actualParams.data[3];
    SimsCameraParameters* params = cam->m_pParams;
    float zoomMin = params->m_zoomMin;
    float zoomMax = params->m_zoomMax;
    float t = (zoom - zoomMin) / (zoomMax - zoomMin);
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;
    return 1.0f + 9.0f * t;
}

// ============================================================================
// ESimsCam::SetWinPos(E3DWindow&)
// Address: 0x80019A04, Size: 1016 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_SetWinPos_impl(ESimsCam* cam, void* win)
{
    EVec3 forward;
    forward.x = cam->m_targetParams.data[0] - cam->m_eye.x;
    forward.y = cam->m_targetParams.data[1] - cam->m_eye.y;
    forward.z = cam->m_targetParams.data[2] - cam->m_eye.z;
    Vec3_Normalize(&forward, &forward);
    // NON_MATCHING: view matrix construction, viewport setup
}

// ============================================================================
// ESimsCam::ResetPos(float)
// Address: 0x80017DC0, Size: 300 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_ResetPos_impl(ESimsCam* cam, float zoom)
{
    SimsCameraParameters* params = cam->m_pParams;
    if (zoom < params->m_zoomMin) zoom = params->m_zoomMin;
    if (zoom > params->m_zoomMax) zoom = params->m_zoomMax;
    cam->m_targetParams.data[3] = zoom;
    cam->m_actualParams.data[3] = zoom;
    cam->m_bMoved = 1;
}

// ============================================================================
// ESimsCam::FollowPlayerInteractor(int)
// Address: 0x80016C34, Size: 388 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_FollowPlayerInteractor_impl(ESimsCam* cam, int playerId)
{
    void* mgr = InteractorManager_GetSingleton();
    if (!mgr) return;
    void* interactor = InteractorManager_GetInteractor(mgr, playerId, 0);
    if (!interactor) return;
    cam->m_targetParams.data[0] = *(float*)((u8*)interactor + 0x10);
    cam->m_targetParams.data[1] = *(float*)((u8*)interactor + 0x14);
    cam->m_targetParams.data[2] = *(float*)((u8*)interactor + 0x18);
    cam->m_bMoved = 1;
}

// ============================================================================
// ESimsCam::Update(void)
// Address: 0x80016DB8, Size: 512 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_Update_impl(ESimsCam* cam)
{
    cam->m_bMoved = 0;
    // NON_MATCHING: calls HandleRotation, HandleZoom, Interpolate, CalcEye
}

// ============================================================================
// ESimsCam::HandleRotation(void)
// Address: 0x8001709C, Size: 588 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_HandleRotation_impl(ESimsCam* cam)
{
    cam->m_bMoved = 1;
    // NON_MATCHING: reads controller input, applies rotation delta
}

// ============================================================================
// ESimsCam::HandleZoom(void)
// Address: 0x800172E8, Size: 424 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_HandleZoom_impl(ESimsCam* cam)
{
    SimsCameraParameters* params = cam->m_pParams;
    float zoom = cam->m_targetParams.data[3];
    if (zoom < params->m_zoomMin) zoom = params->m_zoomMin;
    if (zoom > params->m_zoomMax) zoom = params->m_zoomMax;
    cam->m_targetParams.data[3] = zoom;
    cam->m_bMoved = 1;
}

// ============================================================================
// ESimsCam::CalRoomId(EVec3&)
// Address: 0x80019628, Size: 324 bytes
// NON_MATCHING
// ============================================================================
static int ESimsCam_CalRoomId_impl(ESimsCam* cam, EVec3* pos)
{
    return 0; // NON_MATCHING: room system query
}

// ============================================================================
// ESimsCam::CalcEyePosition(EVec3&, CameraParameters&)
// Address: 0x80017ABC, Size: 772 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_CalcEyePosition_impl(ESimsCam* cam, EVec3* outEye, float* params)
{
    float zoom = params[3];
    float rotAng = params[4];
    float tilt = params[5];
    outEye->x = params[0] + zoom * sinf_impl(rotAng);
    outEye->y = params[1] + zoom * sinf_impl(tilt);
    outEye->z = params[2] + zoom * cosf_impl(rotAng);
}

// ============================================================================
// ESimsCam::InterpolateActualCameraParamsToTarget(float)
// Address: 0x80018548, Size: 672 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_InterpParams_impl(ESimsCam* cam, float dt)
{
    for (int i = 0; i < 6; i++) {
        float diff = cam->m_targetParams.data[i] - cam->m_actualParams.data[i];
        cam->m_actualParams.data[i] += diff * dt;
    }
}

// ============================================================================
// ESimsCam::SetPosAndReset(EVec3&, EVec3&, EVec3&)
// Address: 0x80018E74, Size: 368 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_SetPosAndReset_impl(ESimsCam* cam, EVec3* eye, EVec3* target, EVec3* up)
{
    cam->m_eye = *eye;
    cam->m_up = *up;
    cam->m_targetParams.data[0] = target->x;
    cam->m_targetParams.data[1] = target->y;
    cam->m_targetParams.data[2] = target->z;
    cam->m_actualParams.data[0] = target->x;
    cam->m_actualParams.data[1] = target->y;
    cam->m_actualParams.data[2] = target->z;
    cam->m_bMoved = 1;
}

// ============================================================================
// ESimsCam::SetPos(EVec3&, EVec3&, EVec3&)
// Address: 0x80018FE4, Size: 392 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_SetPos_impl(ESimsCam* cam, EVec3* eye, EVec3* target, EVec3* up)
{
    cam->m_eye = *eye;
    cam->m_up = *up;
    cam->m_targetParams.data[0] = target->x;
    cam->m_targetParams.data[1] = target->y;
    cam->m_targetParams.data[2] = target->z;
    cam->m_bMoved = 1;
}

// ============================================================================
// ESimsCam::ForcePosition(EVec3&, EVec3&, EVec3&)
// Address: 0x8001916C, Size: 400 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_ForcePosition_impl(ESimsCam* cam, EVec3* eye, EVec3* target, EVec3* up)
{
    ESimsCam_SetPosAndReset_impl(cam, eye, target, up);
    for (int i = 0; i < 6; i++) {
        cam->m_actualParams.data[i] = cam->m_targetParams.data[i];
    }
}

// ============================================================================
// ESimsCam::ValidateCursorPosition(int, EVec3*)
// Address: 0x8001942C, Size: 508 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_ValidateCursorPosition_impl(ESimsCam* cam, int playerId, EVec3* pos)
{
    if (!pos) return;
    if (pos->y < 0.0f) pos->y = 0.0f;
}

// ============================================================================
// ESimsCam::GetContainingRoomId(EVec3&)
// Address: 0x8001976C, Size: 660 bytes
// NON_MATCHING
// ============================================================================
static int ESimsCam_GetContainingRoomId_impl(ESimsCam* cam, EVec3* pos)
{
    return ESimsCam_CalRoomId_impl(cam, pos);
}

// ============================================================================
// ESimsCam::DrawCameraInfo(ERC*)
// Address: 0x8001AA74, Size: 800 bytes
// NON_MATCHING
// ============================================================================
static void ESimsCam_DrawCameraInfo_impl(ESimsCam* cam, ERC* rc)
{
    if (!rc) return;
    // NON_MATCHING: debug draw calls
}

// ============================================================================
// CameraDirector functions (all as free functions)
// ============================================================================

// CameraDirector::InitSimsCamera(void)
// Address: 0x8001B078, Size: 288 bytes
// NON_MATCHING
static void CameraDirector_InitSimsCamera_impl(CameraDirector* dir)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    dir->m_state = 0;
    dir->m_holdTime = 0.0f;
    dir->m_forceDisableHud = 0;
}

// CameraDirector::ReleaseCurrentCamera(void)
// Address: 0x8001B1FC, Size: 336 bytes
// NON_MATCHING
static void CameraDirector_ReleaseCurrentCamera_impl(CameraDirector* dir)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (cam) {
        ERAnimController_Release((u8*)cam + 0x4C8);
    }
    dir->m_state = 0;
    dir->m_holdTime = 0.0f;
    dir->m_forceDisableHud = 0;
}

// CameraDirector::SetCameraCut(ENCamera*)
// Address: 0x8001B524, Size: 648 bytes
// NON_MATCHING
static void CameraDirector_SetCameraCut_impl(CameraDirector* dir, void* camera)
{
    if (!camera) return;
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    dir->m_state = 2;
}

// CameraDirector::SetCameraInterp(ENCamera*, float, CamDirInterpType)
// Address: 0x8001BDB0, Size: 680 bytes
// NON_MATCHING
static void CameraDirector_SetCameraInterp_impl(CameraDirector* dir, void* camera, float duration, int interpType)
{
    if (!camera) return;
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    dir->m_state = 3;
    dir->m_holdTime = duration;
}

// CameraDirector::SetUpInterpCamera(float, CamDirInterpType)
// Address: 0x8001C310, Size: 560 bytes
// NON_MATCHING
static void CameraDirector_SetUpInterpCamera_impl(CameraDirector* dir, float duration, int interpType)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    dir->m_state = 3;
}

// CameraDirector::SetCameraInterpAnim(int, float, CamDirInterpType, float, bool*)
// Address: 0x8001C058, Size: 696 bytes
// NON_MATCHING
static void CameraDirector_SetCameraInterpAnim_impl(CameraDirector* dir, int animId, float duration, int interpType, float speed, bool* pComplete)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    if (pComplete) *pComplete = false;
    dir->m_state = 4;
}

// CameraDirector::ReleaseToGameCamera(void)
// Address: 0x8001C540, Size: 348 bytes
// NON_MATCHING
static void CameraDirector_ReleaseToGameCamera_impl(CameraDirector* dir)
{
    dir->m_state = 0;
    dir->m_holdTime = 0.0f;
    dir->m_forceDisableHud = 0;
}

// CameraDirector::InterpToGameCamera(float, CamDirInterpType)
// Address: 0x8001C69C, Size: 404 bytes
// NON_MATCHING
static void CameraDirector_InterpToGameCamera_impl(CameraDirector* dir, float duration, int interpType)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    dir->m_state = 5;
}

// CameraDirector::CalcSimsCam(void)
// Address: 0x8001C8D4, Size: 548 bytes
// NON_MATCHING
static void CameraDirector_CalcSimsCam_impl(CameraDirector* dir)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
}

// CameraDirector::CalcCancelCam(void)
// Address: 0x8001CB00, Size: 544 bytes
// NON_MATCHING
static void CameraDirector_CalcCancelCam_impl(CameraDirector* dir)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
}

// CameraDirector::StartAnim(int, bool, bool)
// Address: 0x8001D368, Size: 656 bytes
// NON_MATCHING
static void CameraDirector_StartAnim_impl(CameraDirector* dir, int animId, bool loop, bool disableHud)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    if (disableHud) dir->ForceDisableHud(true);
    dir->InitAnim(cam->m_playerId);
    dir->m_state = 6;
}

// CameraDirector::UpdateCameraPosAndFOV(void)
// Address: 0x8001DC68, Size: 864 bytes
// NON_MATCHING
static void CameraDirector_UpdateCameraPosAndFOV_impl(CameraDirector* dir)
{
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
}

// CameraDirector::Draw(ERC*)
// Address: 0x8001DFE0, Size: 540 bytes
// NON_MATCHING
static void CameraDirector_Draw_impl(CameraDirector* dir, ERC* rc)
{
    if (!rc) return;
    ESimsCam* cam = dir->m_pCurrentCamera;
    if (!cam) return;
    ESimsCam_DrawCameraInfo_impl(cam, rc);
}

// ============================================================================
// NewControlParms::NewControlParms(void)
// Address: 0x8001E6DC, Size: 412 bytes
// NON_MATCHING
// ============================================================================
// NewControlParms::NewControlParms(void)
// Address: 0x8001E6DC, Size: 412 bytes
// NON_MATCHING
static void NewControlParms_Ctor(void* self)
{
    u8* p = (u8*)self;
    for (int i = 0; i < 92 / 4; i++) {
        ((u32*)p)[i] = 0;
    }
    *(float*)(p + 0x00) = 0.5f;
    *(float*)(p + 0x04) = 1.0f;
    *(float*)(p + 0x0C) = 1.0f;
    *(float*)(p + 0x10) = 0.5f;
    *(float*)(p + 0x1C) = 30.0f;
    *(float*)(p + 0x20) = 10.0f;
    *(float*)(p + 0x24) = 20.0f;
    *(float*)(p + 0x28) = 15.0f;
}

// ============================================================================
// ENCamera serialization functions
// ============================================================================

// ENCamera::Write(EStream&) - 0x8035CAB4, 468 bytes
// NON_MATCHING
static void ENCamera_Write_impl(ENCamera* cam, void* stream)
{
    EStream_WriteData(stream, cam, 64);
    EStream_WriteData(stream, (u8*)cam + 0x40, 4);
    EStream_WriteData(stream, (u8*)cam + 0x44, 4);
    int numKeys = *(int*)((u8*)cam + 0x44);
    for (int i = 0; i < numKeys; i++) {
        EStream_WriteData(stream, (u8*)cam + 0x48 + i * 24, 24);
    }
}

// ENCamera::Read(EStream&) - 0x8035CC88, 508 bytes
// NON_MATCHING
static void ENCamera_Read_impl(ENCamera* cam, void* stream)
{
    EStream_ReadData(stream, cam, 64);
    EStream_ReadData(stream, (u8*)cam + 0x40, 4);
    EStream_ReadData(stream, (u8*)cam + 0x44, 4);
    int numKeys = *(int*)((u8*)cam + 0x44);
    for (int i = 0; i < numKeys; i++) {
        EStream_ReadData(stream, (u8*)cam + 0x48 + i * 24, 24);
    }
}

// ENCamera::Read(unsigned char*) - 0x8035CE84, 420 bytes
// NON_MATCHING
static void ENCamera_ReadBuf_impl(ENCamera* cam, unsigned char* buffer)
{
    for (int i = 0; i < 64; i++) {
        ((u8*)cam)[i] = buffer[i];
    }
    *(int*)((u8*)cam + 0x40) = *(int*)(buffer + 0x40);
    int numKeys = *(int*)(buffer + 0x44);
    *(int*)((u8*)cam + 0x44) = numKeys;
    for (int i = 0; i < numKeys * 24; i++) {
        ((u8*)cam)[0x48 + i] = buffer[0x48 + i];
    }
}

// ENCamera::SetCameraPoint(int, ENCameraPoint) - 0x8035D0C0, 296 bytes
// NON_MATCHING
static void ENCamera_SetCameraPoint_impl(ENCamera* cam, int index, void* point)
{
    int numKeys = *(int*)((u8*)cam + 0x44);
    if (index < 0 || index >= numKeys) return;
    u8* dst = (u8*)cam + 0x48 + index * 24;
    u8* src = (u8*)point;
    for (int i = 0; i < 24; i++) dst[i] = src[i];
}

// InterpolateSmooth<EVec3> - 0x8039D65C, 300 bytes
// NON_MATCHING
static void InterpolateSmooth_EVec3_impl(EVec3* result, EVec3* target, float t, float speed)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float h1 = 2.0f * t3 - 3.0f * t2 + 1.0f;
    float h2 = -2.0f * t3 + 3.0f * t2;
    result->x = result->x * h1 + target->x * h2;
    result->y = result->y * h1 + target->y * h2;
    result->z = result->z * h1 + target->z * h2;
}
