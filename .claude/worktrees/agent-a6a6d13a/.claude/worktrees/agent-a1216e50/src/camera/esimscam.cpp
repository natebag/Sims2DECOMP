// esimscam.cpp - ESimsCam camera system (camera.obj)
// Decompiled small functions (<=64 bytes) from The Sims 2 GameCube
// Object file: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\camera.obj

#include "camera/esimscam.h"

// External function declarations
extern "C" void* EAHeap_Get();                                          // 0x802cff00
extern "C" void EAHeap_Free(void*, void*);                             // 0x802d0d78
extern "C" void strncpy_safe(void* dst, const void* src, int len);     // 0x80243b6c
extern "C" void ERAnimInit(void* animObj, int id, int count, int flags); // 0x802e7ac8
extern "C" void __static_init_helper(int construct, u32 priority);      // 0x8001e87c
extern "C" void TArray_ENCameraPoint_Resize(void* arr, int count, int flags); // 0x8039ced0

// IsUsingSpecifiedInteractor (camera.obj internal, >64 bytes)
static bool IsUsingSpecifiedInteractor(int playerId, InteractorModule::InteractorType type);

// InterpolateLinear<float> - camera.obj local helper
// 0x8039d620 - 60 bytes
// __attribute__((noinline)) prevents the compiler from inlining into callers
static float __attribute__((noinline)) InterpolateLinear(float valMin, float valMax, float rangeMin, float rangeMax, float t) {
    if (t > rangeMax) {
        return valMax;
    }
    if (t < rangeMin) {
        return valMin;
    }
    return valMin + (valMax - valMin) * (t - rangeMin) / (rangeMax - rangeMin);
}

// ===================================================================
// Anonymous namespace helpers
// ===================================================================

namespace {

// 0x80015a08 - 36 bytes
bool IsUsingDirectControlInteractor(int playerId) {
    return IsUsingSpecifiedInteractor(playerId, InteractorModule::INTERACTOR_DIRECT_CONTROL);
}

// 0x80015a2c - 36 bytes
bool IsUsingSocialModeInteractor(int playerId) {
    return IsUsingSpecifiedInteractor(playerId, InteractorModule::INTERACTOR_SOCIAL_MODE);
}

} // anonymous namespace

// ===================================================================
// SimsCameraParameters
// ===================================================================

// 0x80016044 - 40 bytes
void SimsCameraParameters::Validate() {
    if (m_zoomMax < m_zoomMin) {
        m_zoomMax = m_zoomMin;
    }
    m_fieldB4 = m_tiltMin;
    m_fieldB8 = m_zoomMin;
}

// ===================================================================
// CameraMotionSystem
// ===================================================================

// 0x8001606c - 20 bytes
CameraMotionSystem::CameraMotionSystem(SimsCameraParameters* params) {
    m_motionType = CAMERA_MOTION_SNAP;
    m_pParams = params;
}

// 0x80016080 - 40 bytes
CameraMotionSystem::~CameraMotionSystem() {
}

// 0x800160a8 - 8 bytes
void CameraMotionSystem::SetMotionType(CameraMotionType type) {
    m_motionType = type;
}

// 0x800160b0 - 8 bytes
CameraMotionType CameraMotionSystem::GetMotionType() {
    return m_motionType;
}

// 0x8001621c - 60 bytes
void CameraMotionSystem::MoveCamera(float dt) {
    if (m_motionType == CAMERA_MOTION_SNAP) {
        SnapCamera();
    } else if (m_motionType == CAMERA_MOTION_RUBBERBAND) {
        RubberBandMove(dt);
    } else {
        SnapCamera();
    }
}

// ===================================================================
// ESimsCam - 8-byte accessors
// ===================================================================

// 0x8001ea2c - 8 bytes - addi r3, r3, 0x418
const EVec3* ESimsCam::GetEye() const {
    return &m_eye;
}

// 0x8001ea34 - 8 bytes - addi r3, r3, 0x43C
const EVec3* ESimsCam::GetTarget() const {
    return (const EVec3*)&m_targetParams;
}

// 0x8001ea3c - 8 bytes - addi r3, r3, 0x424
const EVec3* ESimsCam::GetUp() const {
    return &m_up;
}

// 0x8001ea44 - 8 bytes - addi r3, r3, 0x424 (same as GetUp)
const EVec3* ESimsCam::GetForward() const {
    return &m_up;
}

// 0x8001ea4c - 32 bytes
// NON_MATCHING: register scheduling differs from original SN Systems compiler
void ESimsCam::SetTarget(EVec3& target) {
    u32* src = (u32*)&target;
    u32* dst = (u32*)&m_targetParams;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

// 0x8001ea6c - 8 bytes - addi r3, r3, 0x10
E3DWindow* ESimsCam::GetWin() {
    return (E3DWindow*)m_window;
}

// 0x8001ea74 - 8 bytes - lfs f1, 0x448(r3) = targetParams.data[3]
float ESimsCam::GetZoom() const {
    return m_targetParams.data[3];
}

// 0x8001ea7c - 8 bytes - lfs f1, 0x450(r3) = targetParams.data[5]
float ESimsCam::GetTilt() const {
    return m_targetParams.data[5];
}

// 0x8001ea84 - 8 bytes - stfs f1, 0x450(r3)
void ESimsCam::SetTilt(float t) {
    m_targetParams.data[5] = t;
}

// 0x8001ea8c - 8 bytes - lwz r3, 0x08(r3)
int ESimsCam::GetbMoved() const {
    return m_bMoved;
}

// 0x8001ea94 - 8 bytes - lfs f1, 0x44C(r3) = targetParams.data[4]
float ESimsCam::GetRotAng() const {
    return m_targetParams.data[4];
}

// 0x8001ea9c - 8 bytes - lwz r3, 0x3CC(r3)
int ESimsCam::GetMode() const {
    return m_mode;
}

// 0x8001eaa4 - 8 bytes - lwz r3, 0x04(r3)
int ESimsCam::GetPlayerId() {
    return m_playerId;
}

// 0x8001eaac - 8 bytes - stw r4, 0x54C(r3)
void ESimsCam::ForceFullScreen(bool force) {
    m_forceFullScreen = (u32)force;
}

// 0x8001eab4 - 8 bytes - lwz r3, 0x54C(r3)
// NON_MATCHING: bool return type causes conversion; original returns raw u32
bool ESimsCam::IsForceFullScreen() {
    return (bool)m_forceFullScreen;
}

// 0x8001eabc - 8 bytes - stw r4, 0x540(r3)
void ESimsCam::SetCenterNew(bool val) {
    m_centerNew = (u32)val;
}

// 0x8001eac4 - 8 bytes - lhz r3, 0x544(r3)
int ESimsCam::GetRoomId() {
    return (int)m_roomId;
}

// 0x8001eacc - 8 bytes - lwz r3, 0x548(r3)
int ESimsCam::GetRoomWallsOpaque() {
    return (int)m_roomWallsOpaque;
}

// 0x8001ead4 - 8 bytes - stw r4, 0x564(r3)
void ESimsCam::SetInterpolatingToOrFromSocialModeCameraFlag(bool flag) {
    m_interpSocialMode = (u32)flag;
}

// 0x8001eadc - 8 bytes - stw r4, 0x568(r3)
void ESimsCam::SetInterpolatingFromLotIntroCameraFlag(bool flag) {
    m_interpLotIntro = (u32)flag;
}

// ===================================================================
// ESimsCam - Camera parameter calculations
// ===================================================================

// 0x80016990 - 12 bytes
// lwz r9, 0(r3); lfs f1, 0x68(r9); blr
float ESimsCam::GetFarPlane() {
    return m_pParams->m_farPlane;
}

// 0x800169e8 - 52 bytes
void ESimsCam::SetFov(float fov) {
    float fovMin = m_pParams->m_fovMin;
    float fovMax = m_pParams->m_fovMax;
    float zoomMin = m_pParams->m_zoomMin;
    float zoomMax = m_pParams->m_zoomMax;
    float fovRange = fovMax - fovMin;
    float zoomRange = zoomMax - zoomMin;
    float t = fov - fovMin;
    m_targetParams.data[3] = (t * zoomRange + zoomMin * fovRange) / fovRange;
}

// 0x80017a90 - 44 bytes
float ESimsCam::CalcTiltFromZoom(float z) {
    float zoomMin = m_pParams->m_zoomMin;
    float zoomMax = m_pParams->m_zoomMax;
    float tiltMin = m_pParams->m_tiltMin;
    float tiltMax = m_pParams->m_tiltMax;
    float t = (z - zoomMin) / (zoomMax - zoomMin);
    return tiltMin + t * (tiltMax - tiltMin);
}

// 0x80019a00 - 4 bytes (just blr)
void ESimsCam::CursorMoved(int playerId, EVec3& pos) {
    (void)playerId;
    (void)pos;
}

// 0x8001a00c - 48 bytes
float ESimsCam::GetCursorSpeed() {
    float zoomMin = m_pParams->m_zoomMin;
    float zoomMax = m_pParams->m_zoomMax;
    float t = (m_targetParams.data[3] - zoomMin) / (zoomMax - zoomMin);
    float speedMin = m_pParams->m_cursorSpeedMin;
    float speedMax = m_pParams->m_cursorSpeedMax;
    return speedMin + t * (speedMax - speedMin);
}

// 0x80019364 - 52 bytes
// NON_MATCHING: needs to call PointOutsideScreenRect (not decompiled)
bool ESimsCam::PointOffScreen(EVec3& pos) {
    // float left = m_pParams->m_screenRectLeft;
    // float top = m_pParams->m_screenRectTop;
    // float right = m_pParams->m_screenRectRight;
    // float bottom = m_pParams->m_screenRectBottom;
    // return PointOutsideScreenRect(pos, left, top, right, bottom);
    return false; // NON_MATCHING
}

// 0x800184a0 - 56 bytes
float ESimsCam::CalcTranslationStiffness() const {
    return InterpolateLinear(
        m_pParams->m_translationStiffMin,
        m_pParams->m_translationStiffMax,
        m_pParams->m_zoomMin,
        m_pParams->m_zoomMax,
        m_targetParams.data[3]);
}

// 0x800184d8 - 56 bytes
float ESimsCam::CalcRotationStiffness() const {
    return InterpolateLinear(
        m_pParams->m_rotationStiffMin,
        m_pParams->m_rotationStiffMax,
        m_pParams->m_zoomMin,
        m_pParams->m_zoomMax,
        m_targetParams.data[3]);
}

// 0x80018510 - 56 bytes
float ESimsCam::CalcZoomStiffness() const {
    return InterpolateLinear(
        m_pParams->m_zoomStiffMin,
        m_pParams->m_zoomStiffMax,
        m_pParams->m_zoomMin,
        m_pParams->m_zoomMax,
        m_targetParams.data[3]);
}

// 0x800187e8 - 60 bytes
// NON_MATCHING: original uses lwz/stw (integer copies), compiler generates lfs/stfs
void ESimsCam::SnapActualCameraParamsToTarget() {
    u32* src = (u32*)&m_targetParams;
    u32* dst = (u32*)&m_actualParams;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
    dst[4] = src[4];
    dst[5] = src[5];
}

// 0x8001a22c - 32 bytes
void ESimsCam::SetAnimationMode(CameraAnimationMode mode, cXObject* obj1, cXObject* obj2, bool flag) {
    m_animMode = (u32)mode;
    m_animObj1 = (u32)obj1;
    m_animObj2 = (u32)obj2;
    if (!flag) return;
    m_animFlag = 1;
}

// 0x8001ad94 - 12 bytes
int ESimsCam::SetControllerFilterId(unsigned int filterId) {
    m_controllerFilterId = filterId;
    return 1;
}

// 0x8001ada0 - 8 bytes
unsigned int ESimsCam::GetControllerFilterId() const {
    return m_controllerFilterId;
}

// 0x8001ada8 - 16 bytes
int ESimsCam::ClearControllerFilterId() {
    m_controllerFilterId = 0;
    return 1;
}

// 0x8001e9f8 - 52 bytes
// NON_MATCHING: requires correct EAHeap function addresses (link-time)
void ESimsCam::operator delete(void* ptr) {
    void* heap = EAHeap_Get();
    EAHeap_Free(heap, ptr);
}

// ===================================================================
// CameraDirector
// ===================================================================

// 0x8001caf8 - 8 bytes
FrameEffectsManager* CameraDirector::GetFrameEffectsManager() {
    return m_pFrameEffects;
}

// 0x8001d33c - 44 bytes
// NON_MATCHING: requires correct ERAnimInit address (link-time)
void CameraDirector::InitAnim(int playerId) {
    ERAnimInit(m_animObj, playerId, 2, 0);
}

// 0x8001c830 - 16 bytes
void CameraDirector::SetHoldState(float holdTime) {
    m_holdTime = holdTime;
    m_state = 2;
}

// 0x8001dfc8 - 24 bytes
// NON_MATCHING: compiler generates andi./bnelr instead of xori/andi./beqlr
void CameraDirector::LetterBox(bool enable) {
    u32 disableFlag = *(u32*)((u8*)this + 0x240);
    if (((disableFlag ^ 1) & 1) == 0) return;
    *(u32*)((u8*)this + 0x234) = (u32)enable;
}

// ===================================================================
// CameraManager
// ===================================================================

// 0x8001ec94 - 12 bytes
// slwi r4, r4, 2; stwx r5, r3, r4
void CameraManager::SetCamera(int index, ESimsCam* cam) {
    m_cameras[index] = cam;
}

// ===================================================================
// ENCamera
// ===================================================================

// 0x8035d1e8 - 36 bytes
// NON_MATCHING: requires correct strncpy address (link-time)
void ENCamera::SetName(char* name) {
    strncpy_safe(m_name, name, 64);
}

// 0x8035d20c - 8 bytes
void ENCamera::SetID(int id) {
    m_id = id;
}

// 0x8035d214 - 52 bytes
// NON_MATCHING: requires TArray function address (link-time)
void ENCamera::SetKeys(int numKeys) {
    m_numKeys = numKeys;
    TArray_ENCameraPoint_Resize((void*)((u8*)this + 0x48), numKeys, 0);
}

// 0x8035d248 - 4 bytes (just blr - returns this since name is at offset 0)
char* ENCamera::GetName() {
    return m_name;
}

// 0x8035d24c - 8 bytes
int ENCamera::GetID() {
    return m_id;
}

// 0x8035d254 - 8 bytes
int ENCamera::GetKeys() {
    return m_numKeys;
}

// ===================================================================
// NewControlParms
// ===================================================================

// 0x8001e878 - 4 bytes (empty)
void NewControlParms::Validate() {
}

// ===================================================================
// Global constructors/destructors
// ===================================================================

// 0x8001eae4 - 44 bytes
static void _GLOBAL__I_ESimsCam_m_modeDef() __attribute__((constructor));
static void _GLOBAL__I_ESimsCam_m_modeDef() {
    __static_init_helper(1, 0xFFFF);
}

// 0x8001eb10 - 44 bytes
static void _GLOBAL__D_ESimsCam_m_modeDef() __attribute__((destructor));
static void _GLOBAL__D_ESimsCam_m_modeDef() {
    __static_init_helper(0, 0xFFFF);
}
