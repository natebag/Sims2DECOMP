#include "build_mode/interactor.h"
// Decompiled small functions (<=64 bytes) from:
// - interactor.obj (Interactor base, DirectInteractor, SimInteractor,
//                   SocialModeInteractor, FadeSquare)
// - interactormanager.obj (InteractorManager)
// - objectmanipulator.obj (ObjectManipulator, GrabManipulator,
//                          PlaceManipulator, PlacementObject)
//
// 156 total small functions across 6 obj files.

#include "build_mode/interactor.h"

// External SDA-relative data (will be linked later)
// These are placeholders for .sdata2 float constants
static const float s_floatZero = 0.0f;

// External functions (linked from other obj files)
extern "C" void UpdateObjectHighlightsImpl(EIObjectMan*, u32);
extern "C" void* OperatorNew(unsigned long);

// InteractorManager SDA-relative statics
extern "C" {
    // These live in SDA (r13-relative) in the original binary
    extern InteractorModule::InteractorManager* sInteractorManager;  // r13-28516
    extern void* sInputManager;    // r13-28512
    extern void* sVisualizer;      // r13-28508
}

// ============================================================================
// InteractorModule::Interactor — base class (interactor.obj)
// ============================================================================

// 0x80209280 - 36 bytes
// Copies m_pos (EVec3 at +8) into m_prevPos (EVec3 at +0x14)
// Original loads/stores as u32 triples
void InteractorModule::Interactor::Update(float dt) {
    (void)dt;
    u32* src = (u32*)&m_pos;
    u32* dst = (u32*)&m_prevPos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
}

// 0x802092A4 - 8 bytes: stw r4, 4(r3); blr
void InteractorModule::Interactor::AttachCamera(ESimsCam* cam) {
    m_camera = cam;
}

// 0x802092AC - 8 bytes: lwz r3, 4(r3); blr
ESimsCam* InteractorModule::Interactor::GetAttachedCamera() {
    return m_camera;
}

// 0x802092B4 - 36 bytes
// Stores pos.x, pos.y from m_pos (+0x08, +0x0C) as floats,
// and m_extents (+0x50, +0x54) as u32 into info
void InteractorModule::Interactor::GetInteractorInfo(InteractorInfo& info) {
    info.posX = m_pos.x;
    info.posY = m_pos.y;
    info.field_0C = *(u32*)&m_extents.y;  // +0x54
    info.field_08 = *(u32*)&m_extents.x;  // +0x50
}

// 0x802092D8 - 20 bytes
// Stores extents.y then extents.x (reverse order in asm)
void InteractorModule::Interactor::SetExtents(EVec2& extents) {
    m_extents.y = extents.y;
    m_extents.x = extents.x;
}

// 0x802094EC - 4 bytes: blr
void InteractorModule::Interactor::OnCommandPressed(
    InteractorInputManager::InteractorCommand cmd, float value) {
    (void)cmd; (void)value;
}

// 0x802094F0 - 16 bytes: lfs f0,88(r3); fadds f0,f0,f1; stfs f0,88(r3); blr
void InteractorModule::Interactor::AddIdleTime(float dt) {
    m_idleTime = m_idleTime + dt;
}

// 0x80209500 - 16 bytes: lis r9; lfs f0, const(r9); stfs f0, 88(r3); blr
// NON_MATCHING - needs .sdata2 constant for 0.0f
void InteractorModule::Interactor::ResetIdleTime() {
    m_idleTime = s_floatZero;
}

// 0x80209510 - 4 bytes: blr
void InteractorModule::Interactor::UpdateOverlapIntersection(OverlapData* data) {
    (void)data;
}

// 0x80209514 - 4 bytes: blr
void InteractorModule::Interactor::ExecuteObjectActionMenu(cXObject* obj) {
    (void)obj;
}

// 0x80209518 - 4 bytes: blr
void InteractorModule::Interactor::StopInObjectMenu() {
}

// 0x8020951C - 8 bytes: li r3, 0; blr
int InteractorModule::Interactor::ChooseAction(Interaction* interaction) {
    (void)interaction;
    return 0;
}

// 0x80209524 - 8 bytes: addi r3, r3, 8; blr
EVec3* InteractorModule::Interactor::GetPos() {
    return &m_pos;
}

// 0x8020952C - 8 bytes: addi r3, r3, 32; blr
EVec3* InteractorModule::Interactor::GetSnappedPos() {
    return &m_snappedPos;
}

// 0x80209534 - 40 bytes
// Copies EVec3 from r4 to m_snappedPos (+0x20), sets m_snapped (+0x2C) = 1
void InteractorModule::Interactor::SnapToPos(EVec3& pos) {
    u32* src = (u32*)&pos;
    u32* dst = (u32*)&m_snappedPos;
    dst[0] = src[0];
    dst[2] = src[2];
    dst[1] = src[1];
    m_snapped = 1;
}

// 0x8020955C - 40 bytes
// Checks m_leftStickActive (+0x44) and m_rightStickActive (+0x48)
int InteractorModule::Interactor::EitherStickCentered() {
    int result = 0;
    if (m_leftStickActive != 0) {
        result = 1;
    } else if (m_rightStickActive != 0) {
        result = 1;
    }
    return result;
}

// 0x802095CC - 8 bytes: lwz r3, 0(r3); blr
int InteractorModule::Interactor::GetPlayerId() {
    return m_playerId;
}

// 0x802095D4 - 8 bytes: stw r4, 76(r3); blr
void InteractorModule::Interactor::SetDrawState(int state) {
    m_drawState = state;
}

// 0x802095DC - 8 bytes: lwz r3, 76(r3); blr
int InteractorModule::Interactor::GetDrawState() {
    return m_drawState;
}

// 0x80209454 - 44 bytes
// NON_MATCHING - swaps this/r4 args, calls external function
void InteractorModule::Interactor::UpdateObjectHighlights(EIObjectMan* objMan) {
    (void)objMan;
}

// 0x80209480 - 56 bytes
// NON_MATCHING - stores state in data, calls callback from params
void InteractorModule::Interactor::NotifyClient(
    ClientNotificationState state, CallbackData& data,
    InteractorParams& params) {
    (void)state; (void)data; (void)params;
}

// ============================================================================
// InteractorModule::DirectInteractor (directinteractor.obj / interactor.obj)
// ============================================================================

// 0x80203E04 - 52 bytes
// NON_MATCHING - calls InteractorManager::GetVisualizer() then registers
void InteractorModule::DirectInteractor::OnCreate() {
}

// 0x80203E38 - 52 bytes
// NON_MATCHING - calls InteractorManager::GetVisualizer() then unregisters
void InteractorModule::DirectInteractor::OnDestroy() {
}

// 0x80204EDC - 48 bytes
// Checks m_interactorInfo (+0x78), copies pos floats if non-null,
// then copies m_extents into info
void InteractorModule::DirectInteractor::GetInteractorInfo(InteractorInfo& info) {
    if (m_interactorInfo != 0) {
        f32* ptr = (f32*)m_interactorInfo;
        info.posX = ptr[0];
        info.posY = ptr[1];
    }
    info.field_0C = *(u32*)&m_extents.y;
    info.field_08 = *(u32*)&m_extents.x;
}

// 0x80204F0C - 24 bytes
// NON_MATCHING - loads specific .sdata2 float constant
void InteractorModule::DirectInteractor::StartCancelTimer() {
    m_cancelTimerActive = 1;
    m_cancelTimerValue = s_floatZero;
}

// 0x80204F24 - 24 bytes
// NON_MATCHING - loads specific .sdata2 float constant
void InteractorModule::DirectInteractor::ClearCancelTimer() {
    m_cancelTimerActive = 0;
    m_cancelTimerValue = s_floatZero;
}

// 0x80204FD8 - 60 bytes
// NON_MATCHING - SDA references for delta time and threshold
int InteractorModule::DirectInteractor::CheckCancelTimer() {
    if (m_cancelTimerActive == 1) {
        // m_cancelTimerValue += *deltaTime;
        // if (m_cancelTimerValue > threshold) return 1;
    }
    return 0;
}

// 0x80205014 - 44 bytes
// NON_MATCHING - swaps this and vis args, calls external PreDraw
void InteractorModule::DirectInteractor::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x80205040 - 44 bytes
// NON_MATCHING - swaps this and vis args, calls external Draw
void InteractorModule::DirectInteractor::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x80205748 - 64 bytes
// Stores float value to different offsets based on command
void InteractorModule::DirectInteractor::OnCommandUpdate(
    InteractorInputManager::InteractorCommand cmd, float value) {
    if (cmd == 18) { *(f32*)((u8*)this + 0x34) = value; return; }
    if (cmd == 19) { *(f32*)((u8*)this + 0x38) = value; return; }
    if (cmd == 11) { *(f32*)((u8*)this + 0x3C) = value; return; }
    if (cmd == 12) { *(f32*)((u8*)this + 0x40) = value; }
}

// 0x80205788 - 52 bytes
// NON_MATCHING - calls base class ResetInputState then clears field
void InteractorModule::DirectInteractor::ResetInputState() {
    // base::ResetInputState();
    m_inputState = 0;
}

// 0x802057BC - 12 bytes
// NON_MATCHING - loads float constant from .sdata2
f32 InteractorModule::DirectInteractor::GetSelectionRadius() {
    return s_floatZero; // actual value from .sdata2
}

// 0x80205B78 - 56 bytes
// NON_MATCHING - loads global singleton, calls StopMenu with playerId
void InteractorModule::DirectInteractor::StopInObjectMenu() {
}

// 0x80205FB4 - 64 bytes
// NON_MATCHING - sets autonomous flag + calls StopInObjectMenu logic
void InteractorModule::DirectInteractor::SetAutonomous() {
    m_isAutonomous = 1;
}

// 0x80206118 - 8 bytes: lwz r3, 100(r3); blr
u32 InteractorModule::DirectInteractor::GetControlStatus() {
    return m_controlStatus;
}

// 0x80206120 - 12 bytes: li r0, 1; stw r0, 108(r3); blr
void InteractorModule::DirectInteractor::ExitDirectControl() {
    m_exitDirectControl = 1;
}

// 0x8020612C - 8 bytes: lwz r3, 128(r3); blr
int InteractorModule::DirectInteractor::IsAutonomous() {
    return m_isAutonomous;
}

// ============================================================================
// FadeSquare (siminteractor.obj / interactor.obj)
// ============================================================================

// 0x8021CEB0 - 52 bytes
// NON_MATCHING - loads initial fade value from .sdata2
void InteractorModule::FadeSquare::StartDraw(EVec3& pos, bool draw) {
    m_shouldDraw = draw;
    m_pos.x = pos.x;
    m_pos.y = pos.y;
    m_pos.z = pos.z;
    m_fadeValue = 1.0f; // from .sdata2
    m_fading = 0;
}

// 0x8021CEE4 - 12 bytes: li r0, 1; stw r0, 20(r3); blr
void InteractorModule::FadeSquare::StartFade() {
    m_fading = 1;
}

// 0x8021CEF0 - 24 bytes
// NON_MATCHING - loads 0.0f from .sdata2
void InteractorModule::FadeSquare::StopDraw() {
    m_fading = 1;
    m_fadeValue = s_floatZero;
}

// 0x8021CFB0 - 28 bytes
// NON_MATCHING - uses mfcr/rlwinm pattern for float compare
int InteractorModule::FadeSquare::ShouldDraw() {
    return (m_fadeValue > 0.0f) ? 1 : 0;
}

// ============================================================================
// InteractorModule::SimInteractor (siminteractor.obj / interactor.obj)
// ============================================================================

// 0x8021D3F4 - 52 bytes
// NON_MATCHING - calls GetVisualizer(), registers
void InteractorModule::SimInteractor::OnCreate() {
}

// 0x8021D428 - 52 bytes
// NON_MATCHING - calls GetVisualizer(), unregisters
void InteractorModule::SimInteractor::OnDestroy() {
}

// 0x8021DFF4 - 36 bytes
// Same pattern as Interactor::GetInteractorInfo
void InteractorModule::SimInteractor::GetInteractorInfo_SI(InteractorInfo& info) {
    info.posX = m_pos.x;
    info.posY = m_pos.y;
    info.field_0C = *(u32*)&m_extents.y;
    info.field_08 = *(u32*)&m_extents.x;
}

// 0x8021E018 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::SimInteractor::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8021E044 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::SimInteractor::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8021E598 - 64 bytes
void InteractorModule::SimInteractor::OnCommandUpdate(
    InteractorInputManager::InteractorCommand cmd, float value) {
    if (cmd == 7)  { *(f32*)((u8*)this + 0x34) = value; return; }
    if (cmd == 8)  { *(f32*)((u8*)this + 0x38) = value; return; }
    if (cmd == 11) { *(f32*)((u8*)this + 0x3C) = value; return; }
    if (cmd == 12) { *(f32*)((u8*)this + 0x40) = value; }
}

// 0x8021E5D8 - 56 bytes
// NON_MATCHING - calls base ResetInputState, clears two fields
void InteractorModule::SimInteractor::ResetInputState() {
    // base::ResetInputState();
    *(u32*)((u8*)this + 0x188) = 0;
    m_inputState = 0;
}

// 0x8021E890 - 24 bytes
// NON_MATCHING - loads float from .sdata
void InteractorModule::SimInteractor::ResetSnapTimer() {
    *(u32*)((u8*)this + 0x198) = 0;
    *(f32*)((u8*)this + 0x184) = s_floatZero;
}

// 0x8021E8A8 - 64 bytes
// NON_MATCHING - calls base GetSelectionRadius, conditionally overrides
f32 InteractorModule::SimInteractor::GetSelectionRadius() {
    return s_floatZero;
}

// 0x8021ECB0 - 12 bytes: li r0, 0; stw r0, 532(r3); blr
void InteractorModule::SimInteractor::ReturnPlumbobToSim(
    PlumbBob* plumbBob, EVec3& pos) {
    (void)plumbBob; (void)pos;
    *(u32*)((u8*)this + 0x214) = 0;
}

// 0x8021F0AC - 12 bytes: li r0, 1; stw r0, 392(r3); blr
void InteractorModule::SimInteractor::SetupCutToSim() {
    *(u32*)((u8*)this + 0x188) = 1;
}

// 0x8021F0B8 - 16 bytes: mulli r4, r4, 28; addi r4, r4, 100; add r3, r3, r4; blr
InteractorModule::FadeSquare* InteractorModule::SimInteractor::GetFadeSquare(int index) {
    return (FadeSquare*)((u8*)this + index * 28 + 100);
}

// 0x8021F0C8 - 16 bytes
void InteractorModule::SimInteractor::SetPlumbBobShadowSave(u32 value) {
    if ((s32)value == -1) return;
    *(u32*)((u8*)this + 0x190) = value;
}

// 0x8021F0D8 - 20 bytes
u32 InteractorModule::SimInteractor::GetPlumbBobShadowSave() {
    u32 saved = *(u32*)((u8*)this + 0x190);
    *(u32*)((u8*)this + 0x190) = (u32)-1;
    return saved;
}

// ============================================================================
// InteractorModule::SocialModeInteractor (socialmodeinteractor.obj)
// ============================================================================

// 0x8021F198 - 60 bytes
// NON_MATCHING - calls GetVisualizer(), registers, sets m_chosenActionID = -1
void InteractorModule::SocialModeInteractor::OnCreate() {
}

// 0x8021F1D4 - 52 bytes
// NON_MATCHING - calls GetVisualizer(), unregisters
void InteractorModule::SocialModeInteractor::OnDestroy() {
}

// 0x8021F3D8 - 4 bytes: blr
void InteractorModule::SocialModeInteractor::GetInteractorInfo_SMI(
    InteractorInfo& info) {
    (void)info;
}

// 0x8021F3DC - 4 bytes: blr
void InteractorModule::SocialModeInteractor::OnCommandPressed_SMI(
    InteractorInputManager::InteractorCommand cmd, float value) {
    (void)cmd; (void)value;
}

// 0x8021F3E0 - 4 bytes: blr
void InteractorModule::SocialModeInteractor::OnCommandReleased(
    InteractorInputManager::InteractorCommand cmd) {
    (void)cmd;
}

// 0x8021F3E4 - 4 bytes: blr
void InteractorModule::SocialModeInteractor::OnCommandUpdate_SMI(
    InteractorInputManager::InteractorCommand cmd, float value) {
    (void)cmd; (void)value;
}

// 0x8021F3E8 - 52 bytes
// NON_MATCHING - calls base ResetInputState, clears m_inputState
void InteractorModule::SocialModeInteractor::ResetInputState() {
    m_inputState = 0;
}

// 0x8021F41C - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::SocialModeInteractor::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8021F448 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::SocialModeInteractor::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8021F474 - 12 bytes
// NON_MATCHING - loads float from .sdata2
f32 InteractorModule::SocialModeInteractor::GetSelectionRadius() {
    return s_floatZero;
}

// 0x8021F548 - 44 bytes
// Stores interaction ID (or -2 if null) into m_chosenActionID
int InteractorModule::SocialModeInteractor::ChooseAction(Interaction* interaction) {
    if (interaction != 0) {
        u32 actionId = *(u32*)((u8*)interaction + 20);
        m_chosenActionID = (s16)actionId;
    } else {
        m_chosenActionID = -2;
    }
    return 1;
}

// 0x8021F574 - 8 bytes: lha r3, 96(r3); blr
s16 InteractorModule::SocialModeInteractor::GetChosenActionID() {
    return m_chosenActionID;
}

// 0x8021F57C - 12 bytes: li r0, -1; sth r0, 96(r3); blr
void InteractorModule::SocialModeInteractor::ResetChosenAction() {
    m_chosenActionID = -1;
}

// 0x8021F588 - 8 bytes: lwz r3, 108(r3); blr
int InteractorModule::SocialModeInteractor::GetTimout() {
    return m_timeout;
}

// 0x8021F590 - 8 bytes: stw r4, 108(r3); blr
void InteractorModule::SocialModeInteractor::SetTimout(int timeout) {
    m_timeout = timeout;
}

// ============================================================================
// InteractorModule::InteractorManager (interactormanager.obj)
// ============================================================================

// 0x8020B654 - 60 bytes
// NON_MATCHING - singleton pattern with operator new + constructor
InteractorModule::InteractorManager*
InteractorModule::InteractorManager::GetSingleton() {
    return 0; // singleton logic with SDA refs
}

// 0x8020B690 - 8 bytes: lwz r3, sda_offset(r13); blr
InteractorModule::InteractorInputManager*
InteractorModule::InteractorManager::GetInputManager() {
    return (InteractorInputManager*)sInputManager;
}

// 0x8020B698 - 8 bytes: lwz r3, sda_offset(r13); blr
InteractorModule::InteractorVisualizer*
InteractorModule::InteractorManager::GetVisualizer() {
    return (InteractorVisualizer*)sVisualizer;
}

// 0x8020B6A0 - 8 bytes: lwz r3, 0(r3); blr
u32 InteractorModule::InteractorManager::IsInitialized() {
    return m_initialized;
}

// 0x8020BDBC - 56 bytes
// Validates player ID against initialized state and max bounds
int InteractorModule::InteractorManager::IsValidPlayerId(int playerId) const {
    if (m_initialized == 0) return 0;
    if (playerId < 0) return 0;
    if (playerId >= (int)m_maxPlayers) return 0;
    if (playerId > 7) return 0;
    return 1;
}

// ============================================================================
// InteractorModule::ObjectManipulator (objectmanipulator.obj)
// ============================================================================

// 0x8021900C - 52 bytes
// NON_MATCHING - calls GetVisualizer(), registers
void InteractorModule::ObjectManipulator::OnCreate() {
}

// 0x80219040 - 52 bytes
// NON_MATCHING - calls GetVisualizer(), unregisters
void InteractorModule::ObjectManipulator::OnDestroy() {
}

// 0x802191F0 - 60 bytes
// NON_MATCHING - calls external cleanup functions
void InteractorModule::ObjectManipulator::OnStop() {
}

// 0x8021922C - 4 bytes: blr
void InteractorModule::ObjectManipulator::OnCommandPressed_OM(
    InteractorInputManager::InteractorCommand cmd, float value) {
    (void)cmd; (void)value;
}

// 0x80219488 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::ObjectManipulator::PreDraw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x802194B4 - 44 bytes
// NON_MATCHING - swaps this/vis, calls external
void InteractorModule::ObjectManipulator::Draw(InteractorVisualizer& vis) {
    (void)vis;
}

// 0x8021A030 - 4 bytes: blr
void InteractorModule::ObjectManipulator::SetUIDebugName(cXObject* obj) {
    (void)obj;
}

// 0x8021A034 - 8 bytes: stw r4, 168(r3); blr
void InteractorModule::ObjectManipulator::SetIsCursorModelEnabled(bool enabled) {
    *(u32*)((u8*)this + 0xA8) = (u32)enabled;
}

// 0x8021A03C - 8 bytes: lwz r3, 168(r3); blr
int InteractorModule::ObjectManipulator::GetIsCursorModelEnabled() const {
    return *(u32*)((u8*)this + 0xA8);
}

// 0x8021A044 - 56 bytes
// NON_MATCHING - calls ObjectManipulator::OnCreate, sets func table
void InteractorModule::GrabManipulator::OnCreate() {
}

// 0x8021A188 - 56 bytes
// NON_MATCHING - calls ObjectManipulator::OnCreate, sets func table
void InteractorModule::PlaceManipulator::OnCreate() {
}

// 0x8021A1C0 - 60 bytes
// NON_MATCHING - calls ObjectManipulator::OnStart then dispatches
void InteractorModule::PlaceManipulator::OnStart(
    Interactor::InteractorParams* params) {
    (void)params;
}

// 0x8021A8D0 - 8 bytes: addi r3, r3, 100; blr
void* InteractorModule::ObjectManipulator::GetPlacementObject() {
    return (void*)((u8*)this + 0x64);
}

// 0x8021AAB8 - 56 bytes
// Zeroes out PlacementObject fields
InteractorModule::PlacementObject::PlacementObject() {
    m_object = 0;
    m_field_04 = 0;
    m_field_14 = 0;
    m_field_18 = 0;
    m_field_1C = 0;
    m_field_12 = 0;
    m_field_28 = 0;
}

// 0x8021C1D4 - 52 bytes
// NON_MATCHING - calls external CanDestroy check
int InteractorModule::PlacementObject::CanObjectBeDestroyed() {
    if (m_object != 0) {
        return 0; // would call external function
    }
    return 0;
}

// 0x8021C344 - 64 bytes
// NON_MATCHING - sets global flag, calls external reset, clears flag
void InteractorModule::PlacementObject::ResetDirection() {
    if (m_object != 0) {
        // Set global flag, call ResetDirection with m_direction, clear flag
    }
}

// ============================================================================
// Destructors (require vtable setup - NON_MATCHING)
// ============================================================================

// 0x80203DD0 - 52 bytes
// NON_MATCHING - sets vtable at +0x5C, conditionally calls operator delete
// DirectInteractor::~DirectInteractor - needs exact vtable address
static void DirectInteractor_dtor_stub(int* self, int flags) {
    // lis r9, hi(vtable); addi r9, r9, lo(vtable)
    // stw r9, 92(r3) -- store vtable at +0x5C
    // andi. r0, r4, 1; beq skip; bl __dl__FUl
    (void)self; (void)flags;
}

// 0x802094B8 - 52 bytes
// NON_MATCHING - sets vtable at +0x5C, conditionally calls operator delete
// Interactor::~Interactor - needs exact vtable address
static void Interactor_dtor_stub(int* self, int flags) {
    (void)self; (void)flags;
}

// 0x8021F164 - 52 bytes
// NON_MATCHING - sets vtable at +0x5C, conditionally calls operator delete
// SocialModeInteractor::~SocialModeInteractor - needs exact vtable address
static void SocialModeInteractor_dtor_stub(
    InteractorModule::SocialModeInteractor* self, int flags) {
    (void)self; (void)flags;
}

// 0x8021CD90 - 56 bytes
// NON_MATCHING - sets vtable at +0x5C and +0xBC, calls base ObjectManipulator dtor
// GrabManipulator::~GrabManipulator
static void GrabManipulator_dtor_stub(
    InteractorModule::GrabManipulator* self) {
    (void)self;
}

// 0x8021CDC8 - 56 bytes
// NON_MATCHING - sets vtable at +0x5C and +0xBC, calls base ObjectManipulator dtor
// PlaceManipulator::~PlaceManipulator
static void PlaceManipulator_dtor_stub(
    InteractorModule::PlaceManipulator* self) {
    (void)self;
}

// ============================================================================
// Static initializers and global constructors (NON_MATCHING)
// ============================================================================

// 0x802061F8 - 44 bytes
// NON_MATCHING - global constructors keyed to InteractorModule::c_DirectInteractorWalkCutoff
// Calls __static_initialization_and_destruction_0 with args (1, 0xFFFF)
static void _GLOBAL__I_c_DirectInteractorWalkCutoff() {
    // li r4, 0; li r3, 1; ori r4, r4, 0xFFFF
    // bl __static_initialization_and_destruction_0
}

// 0x8021F074 - 56 bytes
// NON_MATCHING - __static_initialization_and_destruction_0 for siminteractor
// Writes float values to static data if __initialize_p == 1 && __priority == 0xFFFF
static void __static_initialization_and_destruction_0_sim(int __initialize_p, int __priority) {
    (void)__initialize_p; (void)__priority;
    // Stores initial float values to SDA-relative static data
}

// 0x8021F0EC - 44 bytes
// NON_MATCHING - global constructors keyed to FadeSquare::FadeSquare(void)
// Calls __static_initialization_and_destruction_0 with args (1, 0xFFFF)
static void _GLOBAL__I_FadeSquare() {
    // li r4, 0; li r3, 1; ori r4, r4, 0xFFFF
    // bl __static_initialization_and_destruction_0
}
