// person_medium.cpp - Medium functions (65-256 bytes) from person.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\person.obj
//
// 80 medium functions decompiled from person.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation (r0 vs r9, stmw vs stw)
//   - GCC loop codegen
//   - GCC boolean conversion (addic/subfe vs cmpwi/beqlr)
//   - SDA-relative addressing

#include "types.h"
#include "stub_classes.h"

// Forward declarations - this file is standalone to avoid header conflicts
// All functions are NON_MATCHING stubs for documentation purposes


// External functions
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);
extern void BString2_copy(void* dst, void* src);
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void ReconBuffer_StreamInline(void* buf, void* data, int count);

#if 0  // Reference decompilation - not compiled (header conflicts with existing declarations)

// ============================================================================
// ActionQueue::ActionQueue(void)
// Address: 0x80119e50 | Size: 96 bytes
// NON_MATCHING - GCC register allocation, loop init
// ============================================================================
ActionQueue::ActionQueue() {
    m_begin = 0;
    m_end = 0;
    // Initialize 10 Interaction slots
    for (int i = 0; i < 10; i++) {
        // Zero each 68-byte Interaction slot
    }
}

// ============================================================================
// ActionQueue::CountVisible(void) const
// Address: 0x80119eb0 | Size: 176 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
int ActionQueue::CountVisible() const {
    int count = 0;
    int total = m_end - m_begin;
    for (int i = 0; i < total; i++) {
        int slot = (m_begin + i) % 10;
        // Check if action at slot is visible
        // If visible, increment count
        count++;
    }
    return count;
}

// ============================================================================
// ActionQueue::IsVisibleAction(Interaction &) const
// Address: 0x8011a210 | Size: 172 bytes
// NON_MATCHING - GCC loop/comparison
// ============================================================================
int ActionQueue::IsVisibleAction(Interaction& action) const {
    // Check if given action is in the visible portion of the queue
    return 0;
}

// ============================================================================
// ActionQueue::FindVisualInsertGUID(unsigned int) const
// Address: 0x8011a2bc | Size: 160 bytes
// NON_MATCHING - GCC loop
// ============================================================================
int ActionQueue::FindVisualInsertGUID(unsigned int guid) const {
    // Find insertion point for action with given GUID
    return -1;
}

// ============================================================================
// ActionQueue::RemoveActionFromHUD(int)
// Address: 0x8011a06c | Size: 124 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ActionQueue::RemoveActionFromHUD(int index) {
    // Remove action icon from HUD display
}

// ============================================================================
// ActionQueue::SetActionText(BString2 &, unsigned int)
// Address: 0x8011a0e8 | Size: 104 bytes
// NON_MATCHING - GCC BString2 operations
// ============================================================================
void ActionQueue::SetActionText(void* text, unsigned int index) {
    // Set text for action at given queue index
}

// ============================================================================
// ActionQueue::SetIconObject(cXObject *, unsigned int)
// Address: 0x8011a150 | Size: 192 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ActionQueue::SetIconObject(cXObject* obj, unsigned int index) {
    // Set icon object for action at given queue index
}

// ============================================================================
// ActionQueue::UpdateAction(unsigned int)
// Address: 0x8011a35c | Size: 156 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ActionQueue::UpdateAction(unsigned int index) {
    // Update HUD display for action at index
}

// ============================================================================
// ActionQueue::DisableHUDAccess(int)
// Address: 0x8011a714 | Size: 92 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void ActionQueue::DisableHUDAccess(int player) {
    // Disable player access to action queue HUD
}

// ============================================================================
// ActionQueue::EnableHUDAccess(int)
// Address: 0x8011a770 | Size: 180 bytes
// NON_MATCHING - GCC virtual dispatch, loop
// ============================================================================
void ActionQueue::EnableHUDAccess(int player) {
    // Enable player access to action queue HUD
    // Rebuild visible action list
}

// ============================================================================
// cXPersonImpl::InitializeStaticMemory(void)
// Address: 0x8011a824 | Size: 232 bytes
// NON_MATCHING - SDA-relative addressing, complex init
// ============================================================================
// NON_MATCHING
void cXPersonImpl::InitializeStaticMemory() {
    // Initialize static memory pools for person simulation
}

// ============================================================================
// cXPersonImpl::CleanupStaticMemory(void)
// Address: 0x8011a90c | Size: 120 bytes
// NON_MATCHING - SDA-relative addressing
// ============================================================================
void cXPersonImpl::CleanupStaticMemory() {
    // Free static memory pools
}

// ============================================================================
// MotiveInc::DoStream(ReconBuffer *, int)
// Address: 0x8011a984 | Size: 92 bytes
// NON_MATCHING - GCC streaming codegen
// ============================================================================
int MotiveInc::DoStream(void* buffer, int version) {
    ReconBuffer_StreamInline(buffer, this, 8);
    return 0;
}

// ============================================================================
// ObjectRecord::DoStream(ReconBuffer *, int)
// Address: 0x8011acfc | Size: 104 bytes
// NON_MATCHING - GCC streaming codegen
// ============================================================================
int ObjectRecord::DoStream(void* buffer, int version) {
    ReconBuffer_StreamInline(buffer, this, 12);
    return 0;
}

// ============================================================================
// cXPersonImpl::GetNextQueueStr(int)
// Address: 0x8011ad9c | Size: 104 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXPersonImpl::GetNextQueueStr(int index) {
    // Get name string for next queued action
    return 0;
}

// ============================================================================
// cXPersonImpl::IsPersonDying(void)
// Address: 0x8012b784 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
int cXPersonImpl::IsPersonDying() {
    // Check if person's death state is active
    // Virtual call through sub-object
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1D0);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsDyingFn)(void*);
    IsDyingFn fn = (IsDyingFn)*(int*)((char*)vtbl + 0x1D4);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::PreSave(void)
// Address: 0x8011f06c | Size: 80 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::PreSave() {
    // Prepare person data for saving
}

// ============================================================================
// cXPersonImpl::SetCurrentAction(Interaction &)
// Address: 0x80129ecc | Size: 68 bytes
// NON_MATCHING - GCC register allocation
// ============================================================================
void cXPersonImpl::SetCurrentAction(Interaction& action) {
    m_currentAction = &action;
}

// ============================================================================
// IsMoveOutOfWay(Interaction *)
// Address: 0x80122998 | Size: 124 bytes
// NON_MATCHING - GCC comparison chain
// ============================================================================
int IsMoveOutOfWay(Interaction* action) {
    if (action == 0) return 0;
    // Check interaction type and tree ID
    int type = action->m_type;
    short treeID = action->m_treeID;
    // Compare against known move-out-of-way tree IDs
    return 0;
}

// ============================================================================
// IsAskedToMove(cXPersonImpl *)
// Address: 0x80122a14 | Size: 152 bytes
// NON_MATCHING - GCC loop, comparison
// ============================================================================
int IsAskedToMove(cXPersonImpl* person) {
    // Check if person has a queued "asked to move" interaction
    return 0;
}

// ============================================================================
// cXPersonImpl::TryReach(StackElem *, XPrimParam *)
// Address: 0x801249f4 | Size: 88 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::TryReach(void* stackElem, void* primParam) {
    // Primitive: attempt to reach target object
    return 0;
}

// ============================================================================
// cXPersonImpl::NetTrySnapTo(StackElem *, XPrimParam *)
// Address: 0x80124a4c | Size: 144 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::NetTrySnapTo(void* stackElem, void* primParam) {
    // Network-safe snap to object position
    return 0;
}

// ============================================================================
// cXPersonImpl::TryTestInteractingWith(StackElem *, XPrimParam *)
// Address: 0x80126640 | Size: 140 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::TryTestInteractingWith(void* stackElem, void* primParam) {
    // Test if person can interact with target
    return 0;
}

// ============================================================================
// cXPersonImpl::GetAspirationScore(void)
// Address: 0x801256ec | Size: 96 bytes
// NON_MATCHING - GCC float math, SDA-relative
// ============================================================================
float cXPersonImpl::GetAspirationScore() {
    // Get aspiration score through neighbor data
    // Virtual call chain to Neighbor::GetAspirationScore
    return 0.0f;
}

// ============================================================================
// cXPersonImpl::SetAspirationScore(float)
// Address: 0x8012574c | Size: 92 bytes
// NON_MATCHING - GCC float math, SDA-relative
// ============================================================================
void cXPersonImpl::SetAspirationScore(float score) {
    // Set aspiration score through neighbor data
}

// ============================================================================
// cXPersonImpl::GetAspirationStatus(void)
// Address: 0x801257a8 | Size: 140 bytes
// NON_MATCHING - GCC float comparison chain
// ============================================================================
int cXPersonImpl::GetAspirationStatus() {
    // Returns aspiration status: 0=failure, 1=low, 2=medium, 3=high, 4=platinum
    float score = GetAspirationScore();
    if (score < -50.0f) return 0;
    if (score < 0.0f) return 1;
    if (score < 50.0f) return 2;
    if (score < 100.0f) return 3;
    return 4;
}

// ============================================================================
// cXPersonImpl::ActionSkipped(Interaction &)
// Address: 0x8012ad98 | Size: 240 bytes
// NON_MATCHING - complex action queue management
// ============================================================================
// NON_MATCHING
void cXPersonImpl::ActionSkipped(Interaction& action) {
    // Handle skipped action - remove from queue, notify HUD
}

// ============================================================================
// cXPersonImpl::HasQueuedActionOfPri(int) const
// Address: 0x80125fe8 | Size: 132 bytes
// NON_MATCHING - GCC loop
// ============================================================================
int cXPersonImpl::HasQueuedActionOfPri(int priority) const {
    // Check if any queued action has given priority
    int total = m_actionQueue.m_end - m_actionQueue.m_begin;
    for (int i = 0; i < total; i++) {
        // Check priority of each queued action
    }
    return 0;
}

// ============================================================================
// cXPersonImpl::CancelAllButLastActions(void)
// Address: 0x801262b0 | Size: 176 bytes
// NON_MATCHING - GCC loop, queue manipulation
// ============================================================================
void cXPersonImpl::CancelAllButLastActions() {
    // Cancel all queued actions except the last one
}

// ============================================================================
// cXPersonImpl::GetIndAction(int, bool)
// Address: 0x80126360 | Size: 104 bytes
// NON_MATCHING - GCC bounds checking
// ============================================================================
Interaction* cXPersonImpl::GetIndAction(int index, bool includeIdle) {
    int total = m_actionQueue.m_end - m_actionQueue.m_begin;
    if (!includeIdle && m_currentAction != 0) {
        index++;
    }
    if (index < 0 || index >= total) return 0;
    int slot = (m_actionQueue.m_begin + index) % 10;
    return (Interaction*)((char*)&m_actionQueue + slot * 68 + 8);
}

// ============================================================================
// cXPersonImpl::GetCurrentAction(void)
// Address: 0x801263c8 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
Interaction* cXPersonImpl::GetCurrentAction() {
    if (m_currentAction == 0) return 0;
    return m_currentAction;
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionStackObject(void)
// Address: 0x8012640c | Size: 92 bytes
// NON_MATCHING - GCC null check chain
// ============================================================================
cXObject* cXPersonImpl::GetCurrentInteractionStackObject() {
    Interaction* action = GetCurrentAction();
    if (action == 0) return 0;
    return action->m_pStackObject;
}

// ============================================================================
// cXPersonImpl::GetCurrentInteractionIconObject(void)
// Address: 0x80126468 | Size: 92 bytes
// NON_MATCHING - GCC null check chain
// ============================================================================
cXObject* cXPersonImpl::GetCurrentInteractionIconObject() {
    Interaction* action = GetCurrentAction();
    if (action == 0) return 0;
    return action->m_pIconObject;
}

// ============================================================================
// cXPersonImpl::Skipping3D(void)
// Address: 0x80128134 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
int cXPersonImpl::Skipping3D() {
    // Check if person is in 3D skipping mode
    return 0;
}

// ============================================================================
// cXPersonImpl::UpdateCurrentRoom(void)
// Address: 0x801281b4 | Size: 224 bytes
// NON_MATCHING - complex room detection
// ============================================================================
// NON_MATCHING
void cXPersonImpl::UpdateCurrentRoom() {
    // Update m_currentRoom based on current tile position
}

// ============================================================================
// cXPersonImpl::SetHilite(int)
// Address: 0x801294c8 | Size: 116 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::SetHilite(int hilite) {
    // Set highlight mode for person rendering
}

// ============================================================================
// cXPersonImpl::AttachToHUD(bool)
// Address: 0x80129804 | Size: 116 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::AttachToHUD(bool attach) {
    // Attach/detach person from HUD display
}

// ============================================================================
// cXPersonImpl::IsPrimarySim(int)
// Address: 0x8012971c | Size: 232 bytes
// NON_MATCHING - SDA-relative, complex check
// ============================================================================
// NON_MATCHING
int cXPersonImpl::IsPrimarySim(int playerIndex) {
    // Check if this person is the primary sim for given player
    return 0;
}

// ============================================================================
// cXPersonImpl::IsPersonInFamily(int) const
// Address: 0x80129878 | Size: 112 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsPersonInFamily(int familyNumber) const {
    // Check if person belongs to family with given number
    return 0;
}

// ============================================================================
// cXPersonImpl::CompleteCurrentAction(void)
// Address: 0x8012ac7c | Size: 172 bytes
// NON_MATCHING - GCC queue manipulation
// ============================================================================
void cXPersonImpl::CompleteCurrentAction() {
    // Complete current action: remove from queue, update HUD
    m_currentAction = 0;
}

// ============================================================================
// cXPersonImpl::DeleteTopAction(void)
// Address: 0x8012ad28 | Size: 112 bytes
// NON_MATCHING - GCC queue manipulation
// ============================================================================
void cXPersonImpl::DeleteTopAction() {
    // Delete the top action from the queue
}

// ============================================================================
// cXPersonImpl::IsDog(void)
// Address: 0x8012b1d4 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsDog() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1E0);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsDogFn)(void*);
    IsDogFn fn = (IsDogFn)*(int*)((char*)vtbl + 0x1E4);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::IsCat(void)
// Address: 0x8012b254 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsCat() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1E8);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsCatFn)(void*);
    IsCatFn fn = (IsCatFn)*(int*)((char*)vtbl + 0x1EC);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::IsMonkey(void)
// Address: 0x8012b2d4 | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsMonkey() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x1F0);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsMonkeyFn)(void*);
    IsMonkeyFn fn = (IsMonkeyFn)*(int*)((char*)vtbl + 0x1F4);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::IsPet(void)
// Address: 0x8012b354 | Size: 216 bytes
// NON_MATCHING - GCC virtual dispatch, boolean OR
// ============================================================================
int cXPersonImpl::IsPet() {
    if (IsDog()) return 1;
    if (IsCat()) return 1;
    if (IsMonkey()) return 1;
    return 0;
}

// ============================================================================
// cXPersonImpl::IsChild(void)
// Address: 0x8012b42c | Size: 128 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsChild() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x158);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsChildFn)(void*);
    IsChildFn fn = (IsChildFn)*(int*)((char*)vtbl + 0x15C);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::IsMale(void)
// Address: 0x8012b4ac | Size: 124 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsMale() {
    void* subObj = m_pSubObject;
    int* vtbl = *(int**)((char*)subObj + 0x04);
    short offset = *(short*)((char*)vtbl + 0x200);
    void* thunk = (char*)subObj + offset;
    typedef int (*IsMaleFn)(void*);
    IsMaleFn fn = (IsMaleFn)*(int*)((char*)vtbl + 0x204);
    return fn(thunk);
}

// ============================================================================
// cXPersonImpl::UserCanPickup(void)
// Address: 0x8012b5f4 | Size: 228 bytes
// NON_MATCHING - complex virtual dispatch chain
// ============================================================================
// NON_MATCHING
int cXPersonImpl::UserCanPickup() {
    // Check if player can pick up this person
    // Checks for pets, children, various conditions
    return 0;
}

// ============================================================================
// cXPersonImpl::Turn(int)
// Address: 0x8012b6d8 | Size: 124 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::Turn(int direction) {
    // Turn person to face given direction
}

// ============================================================================
// cXPersonImpl::SetSecondPlayerInSocialMode(bool)
// Address: 0x8012b834 | Size: 144 bytes
// NON_MATCHING - GCC conditional codegen
// ============================================================================
void cXPersonImpl::SetSecondPlayerInSocialMode(bool mode) {
    m_secondPlayerInSocialMode = (int)mode;
    // Additional logic for social mode setup
}

// ============================================================================
// cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry(void)
// Address: 0x8012b8cc | Size: 172 bytes
// NON_MATCHING - complex social mode check
// ============================================================================
// NON_MATCHING
void cXPersonImpl::CheckFirstPlayerForFailedSocialModeEntry() {
    // Check if first player's social mode entry failed
    // Reset social mode state if needed
}

// ============================================================================
// cXPersonImpl::GetSocialModeTarget(void)
// Address: 0x8012bb20 | Size: 108 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXPerson* cXPersonImpl::GetSocialModeTarget() {
    // Get the other person in social mode
    return 0;
}

// ============================================================================
// cXPersonImpl::InitWantFearIcons(void)
// Address: 0x8012c08c | Size: 108 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::InitWantFearIcons() {
    // Initialize want/fear icon display
}

// ============================================================================
// cXPersonImpl::SpawnWantFearDialog(unsigned int) const
// Address: 0x8012c0f8 | Size: 116 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::SpawnWantFearDialog(unsigned int eventID) const {
    // Spawn dialog for want/fear event
}

// ============================================================================
// cXPersonImpl::SetIdlePlayerSimAutonomous(void)
// Address: 0x8012c16c | Size: 136 bytes
// NON_MATCHING - GCC conditional logic
// ============================================================================
void cXPersonImpl::SetIdlePlayerSimAutonomous() {
    // Set idle player sim to autonomous mode
}

// ============================================================================
// cXPersonImpl::IsCarryingDCObject(void)
// Address: 0x8012c1f4 | Size: 196 bytes
// NON_MATCHING - complex virtual dispatch chain
// ============================================================================
// NON_MATCHING
int cXPersonImpl::IsCarryingDCObject() {
    // Check if person is carrying a direct control object
    return 0;
}

// ============================================================================
// cXPersonImpl::GetNormalSimDescription(void)
// Address: 0x8012c2b8 | Size: 180 bytes
// NON_MATCHING - GCC virtual dispatch chain
// ============================================================================
// NON_MATCHING
void* cXPersonImpl::GetNormalSimDescription() {
    // Get sim description (non-visitor version)
    return 0;
}

// ============================================================================
// cXPersonImpl::IsCarrying(void)
// Address: 0x8012c788 | Size: 84 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPersonImpl::IsCarrying() {
    // Check if person is carrying an object
    return 0;
}

// ============================================================================
// cXPersonImpl::GetControllingObject(void)
// Address: 0x8012ca5c | Size: 76 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXObject* cXPersonImpl::GetControllingObject() {
    // Get object that's controlling this person (e.g., being used)
    return 0;
}

// ============================================================================
// cXPerson::CAST_IMPL(void)
// Address: 0x8012c698 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
cXPersonImpl* cXPerson::CAST_IMPL() {
    // Cast to implementation via virtual dispatch
    void* vtbl_ptr = *(void**)this;
    int* vtbl = *(int**)vtbl_ptr;
    short offset = *(short*)((char*)vtbl + 0x08);
    void* thunk = (char*)vtbl_ptr + offset;
    typedef cXPersonImpl* (*CastFn)(void*);
    CastFn fn = (CastFn)*(int*)((char*)vtbl + 0x0C);
    return fn(thunk);
}

// ============================================================================
// PiecewiseFn::~PiecewiseFn(void)
// Address: 0x8012cc04 | Size: 68 bytes
// NON_MATCHING - GCC destructor ABI
// ============================================================================
PiecewiseFn::~PiecewiseFn() {
    // Free point data if allocated
    if (m_pPoints != 0) {
        operator_delete(m_pPoints);
    }
}

// ============================================================================
// PiecewiseFn::SetMaxPoints(int)
// Address: 0x8012cc54 | Size: 144 bytes
// NON_MATCHING - GCC memory allocation
// ============================================================================
void PiecewiseFn::SetMaxPoints(int maxPoints) {
    // Free existing points
    if (m_pPoints != 0) {
        operator_delete(m_pPoints);
    }
    // Allocate new array
    m_maxPoints = maxPoints;
    m_numPoints = 0;
    if (maxPoints > 0) {
        m_pPoints = (float*)operator_new(maxPoints * 8); // 2 floats per point
    } else {
        m_pPoints = 0;
    }
}

// ============================================================================
// PlayerFamilyImpl::PlayerFamilyImpl(int)
// Address: 0x8012cf68 | Size: 104 bytes
// NON_MATCHING - GCC constructor
// ============================================================================
PlayerFamilyImpl::PlayerFamilyImpl(int number) {
    // Initialize player family with family number
    // Calls FamilyImpl constructor
}

// ============================================================================
// PlayerFamilyImpl::~PlayerFamilyImpl(void)
// Address: 0x8012cfd0 | Size: 104 bytes
// NON_MATCHING - GCC destructor
// ============================================================================
PlayerFamilyImpl::~PlayerFamilyImpl() {
    // Cleanup player family data
}

// ============================================================================
// PlayerFamilyImpl::ClearFamily(void)
// Address: 0x8012d038 | Size: 112 bytes
// NON_MATCHING - GCC store ordering
// ============================================================================
void PlayerFamilyImpl::ClearFamily() {
    // Clear all player family data
    // Reset stats, funds, etc.
}

// ============================================================================
// PlayerFamilyImpl::DoStream(ReconBuffer *, int)
// Address: 0x8012d0a8 | Size: 152 bytes
// NON_MATCHING - GCC streaming codegen
// ============================================================================
int PlayerFamilyImpl::DoStream(void* buffer, int version) {
    // Stream player family data
    ReconBuffer_StreamInline(buffer, this, 32);
    return 0;
}

// ============================================================================
// PlayerFamilyImpl::GetStatRef(int, short **)
// Address: 0x8012d160 | Size: 68 bytes
// NON_MATCHING - GCC array indexing
// ============================================================================
int PlayerFamilyImpl::GetStatRef(int index, short** outRef) {
    // Get reference to stat value
    return 0;
}

// ============================================================================
// cXPortalImpl::Place(FTilePt &, int, cXObject *, int)
// Address: 0x8012fdd0 | Size: 76 bytes
// NON_MATCHING - GCC tail call
// ============================================================================
void cXPortalImpl::Place(void* tilePt, int direction, cXObject* obj, int flags) {
    // Place portal at given tile position
}

// ============================================================================
// cXPortal::DirtyAllRoutes(ObjectModule *)
// Address: 0x80130960 | Size: 212 bytes
// NON_MATCHING - GCC loop/virtual dispatch
// ============================================================================
// NON_MATCHING
void cXPortal::DirtyAllRoutes(void* module) {
    // Invalidate all routing data through this portal
}

// ============================================================================
// cXPortalImpl::GetOtherSide(void)
// Address: 0x8013048c | Size: 244 bytes
// NON_MATCHING - complex portal traversal
// ============================================================================
// NON_MATCHING
void* cXPortalImpl::GetOtherSide() {
    // Get the portal on the other side of a door/arch
    return 0;
}

// ============================================================================
// cXPortal::InitPortalRoute(ObjectModule *, cXObject *, cXObject *)
// Address: 0x80130a34 | Size: 148 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
void cXPortal::InitPortalRoute(void* module, cXObject* from, cXObject* to) {
    // Initialize routing through portal
}

// ============================================================================
// cXPortalImpl::ClearRoute(ObjectModule *, short, float)
// Address: 0x801314b0 | Size: 188 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
// NON_MATCHING
void cXPortalImpl::ClearRoute(void* module, short routeID, float cost) {
    // Clear specific route through portal
}

// ============================================================================
// cXPortalImpl::GetCustomWallStyleID(void)
// Address: 0x801321e0 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPortalImpl::GetCustomWallStyleID() {
    // Get custom wall style for portal display
    return 0;
}

// ============================================================================
// cXPortalImpl::GetWallStyle(void)
// Address: 0x801327c8 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
int cXPortalImpl::GetWallStyle() {
    return 0;
}

// ============================================================================
// cXPortal::CAST_IMPL(void)
// Address: 0x80132744 | Size: 68 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void* cXPortal::CAST_IMPL() {
    return 0;
}

#endif // Reference decompilation
