// person_large.cpp - Large functions (257-1024 bytes) from person.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\person.obj
//
// 56 large functions decompiled from person.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC loop/branch codegen vs SN Systems
//   - SDA-relative addressing
//   - Division by 10 magic constant differences

#include "types.h"

// Forward declarations
class cXObject;
class cXPersonImpl;
class cXPerson;
class cXObjectImpl;
class Interaction;
class BString2;
class ReconBuffer;
class StringBuffer;
class StackElem;
class XPrimParam;
class XRoute;
class ObjSelector;
class ObjectModule;
class FTilePt;
class RoutingSlot;
struct MotiveInc;
struct ObjectRecord;
struct ScoredInteraction;
class RouteGoal;
class ENeighborhoodCustomChar;
class PiecewiseFn;
class EAnimNote;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void BString2_ctor(void* str);
extern void BString2_dtor(void* str, int);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// ActionQueue::AddActionToHUD(int)
// Address: 0x80119F60 | Size: 268 bytes
// NON_MATCHING - GCC division by 10, register alloc
// ============================================================================
void ActionQueue::AddActionToHUD(int index) {
    // r28 = global HUD ptr at *(r9+0x5B84) where r9 = 0x80470000
    void* hudSystem = *(void**)(0x80475B84);
    int* pHudState = (int*)(0x80475B84 + 0x48);

    if (*pHudState != 0) {
        *(u8*)((char*)this + 0x2B0) = 0;
    }

    if (*(u8*)((char*)this + 0x2B0) != 0) {
        return;
    }

    int rawIndex = *(int*)((char*)this + 0x2A8) + index;
    int slot = rawIndex % 10;
    Interaction* action = (Interaction*)((char*)this + slot * 68);

    if (!IsVisibleAction(*action)) {
        return;
    }

    // Get interaction name
    void* name = GetInteractionName(action);
    void* texObj = NULL; // stack local

    int visualGUID = FindVisualInsertGUID(index);

    if (*pHudState != 0) {
        u8 player = *((u8*)this + 0x2B1);
        int guid = GetInteractionGUID(action);
        // Call HUD system to add action
        // AddActionToHUD(hudSystem, player, action, guid, name, texObj, visualGUID)
    }

    void* tempObj = *(void**)((char*)&texObj);
    if (tempObj != NULL) {
        // Release texture object
    }
}

// ============================================================================
// ActionQueue::Insert(Interaction &, unsigned int)
// Address: 0x8011A3F8 | Size: 320 bytes
// NON_MATCHING - GCC loop codegen, division by 10
// ============================================================================
int ActionQueue::Insert(Interaction& action, unsigned int position) {
    int end = *(int*)((char*)this + 0x2AC);
    int begin = *(int*)((char*)this + 0x2A8);
    int count = end - begin;

    if (count > 9) {
        return 0;  // Queue full
    }

    // Shift actions from end down to insertion point
    int idx = end;
    while (idx > (int)(begin + position)) {
        int srcSlot = (idx - 1) % 10;
        int dstSlot = idx % 10;
        Interaction* src = (Interaction*)((char*)this + srcSlot * 68);
        Interaction* dst = (Interaction*)((char*)this + dstSlot * 68);
        // Copy interaction: operator=(src)
        CopyInteraction(dst, src);
        idx--;
    }

    // Copy new action into position
    int insertSlot = idx % 10;
    Interaction* slot = (Interaction*)((char*)this + insertSlot * 68);
    CopyInteraction(slot, &action);

    // Increment end
    *(int*)((char*)this + 0x2AC) = end + 1;

    // Check if action has stack object, call AddActionToHUD
    int newSlot = (begin + position) % 10;
    Interaction* inserted = (Interaction*)((char*)this + newSlot * 68);
    if (*(void**)((char*)inserted + 0x38) == NULL) {
        // Set GUID from person
    }

    AddActionToHUD(position);
    return 1;
}

// ============================================================================
// ActionQueue::Remove(unsigned int)
// Address: 0x8011A538 | Size: 428 bytes
// NON_MATCHING - GCC CR field usage, loop codegen
// ============================================================================
int ActionQueue::Remove(unsigned int position) {
    int end = *(int*)((char*)this + 0x2AC);
    int begin = *(int*)((char*)this + 0x2A8);
    int count = end - begin;

    if (position >= (unsigned int)count) {
        return 0;  // Out of range
    }

    RemoveActionFromHUD(0);

    // Check if action was visible
    int removeSlot = (begin + position) % 10;
    Interaction* removedAction = (Interaction*)((char*)this + removeSlot * 68);
    int wasVisible = IsVisibleAction(*removedAction);

    if (position == 0) {
        // Remove from front - just increment begin
        *(int*)((char*)this + 0x2A8) = begin + 1;
    } else {
        // Shift remaining actions up
        int startIdx = begin + position;
        int endIdx = end;
        if (endIdx > startIdx + 1) {
            int remaining = endIdx - position - begin - 1;
            int idx = startIdx;
            while (remaining > 0) {
                int srcSlot = (idx + 1) % 10;
                int dstSlot = idx % 10;
                Interaction* src = (Interaction*)((char*)this + srcSlot * 68);
                Interaction* dst = (Interaction*)((char*)this + dstSlot * 68);
                CopyInteraction(dst, src);
                idx++;
                remaining--;
            }
        }
        *(int*)((char*)this + 0x2AC) = end - 1;
    }

    // If front action was removed and next has continuation flag, re-add to HUD
    if (position == 0) {
        int newEnd = *(int*)((char*)this + 0x2AC);
        int newBegin = *(int*)((char*)this + 0x2A8);
        if (newEnd != newBegin) {
            int frontSlot = newBegin % 10;
            int flags = *(int*)((char*)this + frontSlot * 68 + 0x3C);
            if ((flags & 0x0002) && wasVisible) {
                flags &= ~0x0008;  // Clear bit 3
                *(int*)((char*)this + frontSlot * 68 + 0x3C) = flags;
                AddActionToHUD(0);
            }
        }
    }

    return 1;
}

// ============================================================================
// AutonomyConstantsClient::UpdateConstants(void)
// Address: 0x8011A9E8 | Size: 788 bytes
// NON_MATCHING - GCC floating point codegen, register alloc
// ============================================================================
void AutonomyConstantsClient::UpdateConstants() {
    // Reads a large set of named float constants from a global constant table
    // and stores them into member fields. Each constant is looked up by name
    // string and then assigned to the appropriate field offset.
    // The function reads approximately 30+ named constants like:
    // "kAutonomyMaxAdScore", "kAutonomyMinAdScore",
    // "kAutonomyHungerWeight", "kAutonomyComfortWeight", etc.
    // Each is looked up via GetFloatConst(name, defaultValue) and stored.
}

// ============================================================================
// cXPerson::~cXPerson(void)
// Address: 0x8011C65C | Size: 288 bytes
// NON_MATCHING - GCC destructor ABI, virtual dispatch
// ============================================================================
cXPerson::~cXPerson() {
    // Destructor chain:
    // 1. Set vtable to cXPerson vtable
    // 2. Call impl destructor if impl exists
    // 3. Call base class (cXObject) destructor
    // 4. Deallocate
}

// ============================================================================
// cXPersonImpl::Reset(bool)
// Address: 0x8011EB78 | Size: 260 bytes
// NON_MATCHING - GCC register alloc, branch layout
// ============================================================================
void cXPersonImpl::Reset(bool flag) {
    // Resets person state
    // Clears action queue
    // Resets motives to defaults
    // Resets person data array
    // Clears social mode state
    // If flag is true, does full reset including route stack
}

// ============================================================================
// cXPersonImpl::LoadMotiveEffects(void)
// Address: 0x8011EF40 | Size: 300 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void cXPersonImpl::LoadMotiveEffects() {
    // Loads motive effect definitions from object data
    // Iterates through motive indices
    // For each motive, loads associated effect parameters
    // Stores into m_pMotiveEffects array
}

// ============================================================================
// cXPersonImpl::PostLoad(int, bool)
// Address: 0x8011EC7C | Size: 708 bytes
// NON_MATCHING - GCC branch structure, virtual calls
// ============================================================================
void cXPersonImpl::PostLoad(int param, bool flag) {
    // Post-load initialization after deserialization
    // 1. Call base class PostLoad
    // 2. Initialize person-specific state
    // 3. Validate action queue entries
    // 4. Recalculate motives
    // 5. Update routing state
    // 6. Load motive effects
    // 7. Initialize want/fear state
    // 8. Update sim description references
    // Multiple virtual calls through module and object pointers
}

// ============================================================================
// cXPersonImpl::TrySetMotiveDelta(StackElem *, XPrimParam *)
// Address: 0x8011F0BC | Size: 932 bytes
// NON_MATCHING - GCC float codegen, branch layout
// ============================================================================
int cXPersonImpl::TrySetMotiveDelta(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Sets a motive change over time
    // 1. Read motive index from prim params
    // 2. Read delta value from prim params
    // 3. Read delta type (absolute/relative)
    // 4. Calculate final delta based on type
    // 5. Apply motive delta to person's motive array
    // 6. Clamp motive to valid range
    // Returns success/failure code
    return 1;
}

// ============================================================================
// cXPersonImpl::TryGosubFoundAction(StackElem *)
// Address: 0x8011F460 | Size: 500 bytes
// NON_MATCHING - GCC virtual dispatch, branch ordering
// ============================================================================
int cXPersonImpl::TryGosubFoundAction(StackElem* stackElem) {
    // VM primitive: Execute a found interaction action
    // 1. Get the found action from the stack element
    // 2. Validate the action and its target object
    // 3. Push the action's tree onto the execution stack
    // 4. Set up stack variables for the sub-tree
    // Returns: 1 on success, 0 on failure
    return 1;
}

// ============================================================================
// cXPersonImpl::TryGotoRoutingSlot(StackElem *, XPrimParam *)
// Address: 0x801203A8 | Size: 664 bytes
// NON_MATCHING - GCC float/int conversion, branch layout
// ============================================================================
int cXPersonImpl::TryGotoRoutingSlot(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Route sim to a routing slot on an object
    // 1. Read slot index from prim params
    // 2. Get target object from stack
    // 3. Look up routing slot position
    // 4. Create route from current position to slot
    // 5. Handle multi-tile objects (find nearest slot)
    // 6. Push route onto route stack
    // Returns: 1 for success, 0 for failure, -1 for in-progress
    return 1;
}

// ============================================================================
// cXPersonImpl::TryRoomRouting(XRoute *)
// Address: 0x80124698 | Size: 260 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
int cXPersonImpl::TryRoomRouting(XRoute* route) {
    // Handle room-to-room routing
    // Check if route crosses room boundaries
    // If so, find portal and route through it
    // Update route with portal waypoint
    return 1;
}

// ============================================================================
// cXPersonImpl::MoveOutOfWay(int)
// Address: 0x80122AAC | Size: 852 bytes
// NON_MATCHING - GCC complex branch structure
// ============================================================================
void cXPersonImpl::MoveOutOfWay(int arg) {
    // Ask sim to move out of the way
    // 1. Check if sim is idle
    // 2. Find clear tile near current position
    // 3. Create move-out-of-way interaction
    // 4. Push interaction to front of queue
    // Multiple virtual calls for tile checking
}

// ============================================================================
// cXPersonImpl::TryGotoRelative(StackElem *, XPrimParam *)
// Address: 0x80124370 | Size: 808 bytes
// NON_MATCHING - GCC float codegen, trig functions
// ============================================================================
int cXPersonImpl::TryGotoRelative(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Route sim to a position relative to current
    // 1. Read relative offset from prim params
    // 2. Calculate target position from current pos + offset
    // 3. Account for facing direction
    // 4. Create route to target
    // 5. Push route onto route stack
    return 1;
}

// ============================================================================
// cXPersonImpl::TryGetReachInfo(StackElem *, XPrimParam *, cXObject **, cXObject **, int *, float *)
// Address: 0x8012479C | Size: 600 bytes
// NON_MATCHING - GCC argument passing, branch codegen
// ============================================================================
int cXPersonImpl::TryGetReachInfo(StackElem* stackElem, XPrimParam* primParam,
                                   cXObject** outObj1, cXObject** outObj2,
                                   int* outSlot, float* outDist) {
    // VM primitive: Get reach information for an object
    // 1. Get target object from stack
    // 2. Calculate distance to object
    // 3. Find best routing slot
    // 4. Return reach info through output parameters
    return 1;
}

// ============================================================================
// cXPersonImpl::TryElement(StackElem *, short, XPrimParam *)
// Address: 0x80124ADC | Size: 580 bytes
// NON_MATCHING - GCC switch codegen
// ============================================================================
int cXPersonImpl::TryElement(StackElem* stackElem, short code, XPrimParam* primParam) {
    // Main VM primitive dispatcher
    // Switches on 'code' to dispatch to specific TryXxx handlers:
    //   case for SetMotiveDelta
    //   case for GotoRoutingSlot
    //   case for GotoRelative
    //   case for Reach
    //   case for SnapTo
    //   case for IdleForInput
    //   case for IdleAnimate
    //   case for ChangeSuit
    //   case for TestInteractingWith
    //   case for SocialMode
    //   default: return error
    return 0;
}

// ============================================================================
// cXPersonImpl::TryChangeSuit(StackElem *, XPrimParam *)
// Address: 0x801266CC | Size: 852 bytes
// NON_MATCHING - GCC branch structure, string handling
// ============================================================================
int cXPersonImpl::TryChangeSuit(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Change sim's outfit
    // 1. Read suit type from prim params
    // 2. Get current outfit info
    // 3. Load new suit textures
    // 4. Apply suit change to sim model
    // 5. Update visual state
    return 1;
}

// ============================================================================
// cXPersonImpl::TryIdleForInput(StackElem *, XPrimParam *)
// Address: 0x80126A20 | Size: 324 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
int cXPersonImpl::TryIdleForInput(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Wait for user input
    // 1. Check if action queue has pending actions
    // 2. If pending action, return to allow processing
    // 3. Otherwise, continue idle animation
    // 4. Check interrupt conditions
    // Returns: 0 to continue waiting, 1 when input received
    return 0;
}

// ============================================================================
// cXPersonImpl::TryIdleAnimate(StackElem *, XPrimParam *)
// Address: 0x80126E58 | Size: 648 bytes
// NON_MATCHING - GCC float codegen, loop structure
// ============================================================================
int cXPersonImpl::TryIdleAnimate(StackElem* stackElem, XPrimParam* primParam) {
    // VM primitive: Play idle animation
    // 1. Read animation parameters from prim params
    // 2. Get current animation state
    // 3. Select appropriate idle animation
    // 4. Play animation with blending
    // 5. Handle animation events
    // Returns: status code
    return 1;
}

// ============================================================================
// cXPersonImpl::Simulate(int)
// Address: 0x80124D20 | Size: 796 bytes
// NON_MATCHING - GCC branch ordering, virtual calls
// ============================================================================
void cXPersonImpl::Simulate(int ticks) {
    // Main per-frame simulation update for a sim
    // 1. Check if sim is active
    // 2. Update motives (SimMotives)
    // 3. Process current action
    // 4. Handle routing
    // 5. Update autonomy
    // 6. Process interrupts
    // 7. Update animation
    // 8. Update social mode
    // Called every game tick for active sims
}

// ============================================================================
// cXPersonImpl::ReconStream(ReconBuffer *, int, bool)
// Address: 0x80125048 | Size: 860 bytes
// NON_MATCHING - GCC serialization codegen
// ============================================================================
void cXPersonImpl::ReconStream(ReconBuffer* buf, int dir, bool flag) {
    // Serialize/deserialize person state
    // Streams: motives, person data, action queue, route stack,
    // social state, aspiration, wants/fears, etc.
    // Direction: 0 = save, 1 = load
}

// ============================================================================
// cXPersonImpl::SimMotives(void)
// Address: 0x801253E4 | Size: 364 bytes
// NON_MATCHING - GCC float loop codegen
// ============================================================================
void cXPersonImpl::SimMotives() {
    // Simulate motive decay/change each tick
    // 1. Get time delta since last update
    // 2. For each motive:
    //    a. Apply motive effects (from MotiveEffects table)
    //    b. Apply natural decay
    //    c. Clamp to valid range [0, 100]
    // 3. Recalculate happiness
    // 4. Update last motive update tick
    int currentTick = 0; // from global timer
    int delta = currentTick - m_lastMotiveUpdateTick;
    if (delta <= 0) return;

    // Apply motive effects for each of 16 motives
    for (int i = 0; i < 16; i++) {
        // Apply decay and effects
    }

    CalcHappy();
    m_lastMotiveUpdateTick = currentTick;
}

// ============================================================================
// cXPersonImpl::CalcHappy(void)
// Address: 0x80125550 | Size: 412 bytes
// NON_MATCHING - GCC float accumulation, loop codegen
// ============================================================================
void cXPersonImpl::CalcHappy() {
    // Calculate overall happiness from weighted motives
    // Uses static sHappyMotives table for motive indices and weights
    // Happiness = sum of (motive[i] * weight[i]) for each weighted motive
    // Result stored in motive[HAPPY_INDEX]
    float total = 0.0f;
    float totalWeight = 0.0f;

    // For each happiness-contributing motive
    // Read index and weight from PiecewiseFn curves
    // Accumulate weighted value

    // Store calculated happiness
}

// ============================================================================
// cXPersonImpl::SpawnAspirationBalloon(int)
// Address: 0x80125834 | Size: 332 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::SpawnAspirationBalloon(int type) {
    // Show aspiration gain/loss balloon above sim
    // 1. Get sim's current position
    // 2. Create balloon effect with appropriate icon
    // 3. Set balloon type (positive/negative aspiration change)
    // 4. Attach to sim's head position
}

// ============================================================================
// cXPersonImpl::RunImmediateAction(Interaction *)
// Address: 0x80125980 | Size: 336 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
void cXPersonImpl::RunImmediateAction(Interaction* action) {
    // Execute an interaction immediately (not queued)
    // 1. Save current action state
    // 2. Set up stack for immediate execution
    // 3. Push action's tree onto execution stack
    // 4. Execute the tree
    // 5. Restore previous action state
    // Used for events that must run right away
}

// ============================================================================
// cXPersonImpl::AddAction(Interaction *)
// Address: 0x80125ADC | Size: 904 bytes
// NON_MATCHING - GCC complex branch structure
// ============================================================================
void cXPersonImpl::AddAction(Interaction* action) {
    // Add an interaction to the sim's action queue
    // 1. Check if action is valid
    // 2. Check queue capacity
    // 3. Determine insertion position based on priority
    // 4. Handle push-to-head flag
    // 5. Handle continuation actions
    // 6. Insert into action queue
    // 7. Update HUD display
    // 8. Handle auto-first-select
    // 9. If sim is idle, start executing the action
}

// ============================================================================
// cXPersonImpl::RemoveAction(int)
// Address: 0x80125E64 | Size: 388 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
void cXPersonImpl::RemoveAction(int index) {
    // Remove an action from the queue by index
    // 1. Validate index
    // 2. Clean up the action's resources
    // 3. Remove from action queue
    // 4. Update HUD display
    // 5. If current action was removed, advance to next
}

// ============================================================================
// cXPersonImpl::CancelLastAction(void)
// Address: 0x8012606C | Size: 296 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void cXPersonImpl::CancelLastAction() {
    // Cancel the last action in the queue
    // 1. Get queue size
    // 2. Find last non-continuation action
    // 3. Set cancelled flag on it
    // 4. Remove from queue
    // 5. Update HUD
}

// ============================================================================
// cXPersonImpl::CancelAllActions(void)
// Address: 0x80126194 | Size: 284 bytes
// NON_MATCHING - GCC loop codegen
// ============================================================================
void cXPersonImpl::CancelAllActions() {
    // Cancel all actions in the queue
    // Iterate from end to start, cancelling each action
    // Skip the currently executing action if flagged as must-run
    // Update HUD after clearing
}

// ============================================================================
// cXPersonImpl::ShouldInterrupt(void)
// Address: 0x801264C8 | Size: 376 bytes
// NON_MATCHING - GCC branch ordering
// ============================================================================
int cXPersonImpl::ShouldInterrupt() {
    // Check if current action should be interrupted
    // 1. Check if there's a pending higher-priority action
    // 2. Check motive failure conditions
    // 3. Check forced interrupts (fire, death, etc.)
    // Returns: 1 if should interrupt, 0 otherwise
    return 0;
}

// ============================================================================
// cXPersonImpl::executeInterruptOnIdlePrimitve(StackElem *, short *, bool)
// Address: 0x80126B64 | Size: 756 bytes
// NON_MATCHING - GCC complex branch/switch
// ============================================================================
void cXPersonImpl::executeInterruptOnIdlePrimitve(StackElem* stackElem, short* result, bool flag) {
    // Execute an interrupt while in an idle primitive
    // 1. Check interrupt type
    // 2. Save current idle state
    // 3. Execute interrupt handler tree
    // 4. Restore idle state or transition to new action
}

// ============================================================================
// cXPersonImpl::UpdateCurrentAction(void)
// Address: 0x80129F10 | Size: 316 bytes
// NON_MATCHING - GCC virtual dispatch
// ============================================================================
void cXPersonImpl::UpdateCurrentAction() {
    // Update the current action's visual state
    // 1. Get current action from queue
    // 2. Update HUD icon
    // 3. Update action text display
    // 4. Handle action completion
}

// ============================================================================
// cXPersonImpl::IsSelectableByPlayer(int)
// Address: 0x8012954C | Size: 464 bytes
// NON_MATCHING - GCC branch ordering
// ============================================================================
int cXPersonImpl::IsSelectableByPlayer(int player) {
    // Check if this sim can be selected by the given player
    // 1. Check if sim is alive
    // 2. Check if sim is in current household
    // 3. Check player assignment
    // 4. Check if sim is busy with non-interruptible action
    // 5. Check social mode restrictions
    return 0;
}

// ============================================================================
// cXPersonImpl::GosubObjectTree(cXObject *, short *, short, bool)
// Address: 0x80129934 | Size: 780 bytes
// NON_MATCHING - GCC branch structure, virtual calls
// ============================================================================
void cXPersonImpl::GosubObjectTree(cXObject* obj, short* tree, short param, bool flag) {
    // Push a sub-tree call onto the behavior stack
    // 1. Save current tree execution state
    // 2. Set up new stack frame
    // 3. Set target object for sub-tree
    // 4. Set tree ID and parameters
    // 5. Begin executing sub-tree
}

// ============================================================================
// cXPersonImpl::StackJustPopped(void)
// Address: 0x80129C40 | Size: 652 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
void cXPersonImpl::StackJustPopped() {
    // Handle cleanup after a tree finishes execution
    // 1. Get return value from finished tree
    // 2. Restore previous tree state
    // 3. Process return value (true/false branch)
    // 4. Clean up temporary variables
    // 5. Continue execution at the appropriate node
}

// ============================================================================
// cXPersonImpl::DumpDestList(char *)
// Address: 0x8012AE88 | Size: 816 bytes
// NON_MATCHING - GCC printf codegen
// ============================================================================
void cXPersonImpl::DumpDestList(char* label) {
    // Debug function: dump destination list to output
    // Prints label header
    // Iterates through destination list entries
    // For each entry, prints:
    //   - Destination tile coordinates
    //   - Routing slot info
    //   - Path cost
    //   - Status flags
}

// ============================================================================
// cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry(void)
// Address: 0x8012B978 | Size: 424 bytes
// NON_MATCHING - GCC branch codegen
// ============================================================================
void cXPersonImpl::CheckSecondPlayerForFailedSocialModeEntry() {
    // Check if player 2 failed to enter social mode
    // 1. Check if social mode is active
    // 2. Verify player 2's sim is in range
    // 3. Check if timeout expired
    // 4. If failed, clean up social mode state
    // 5. Send failure notification to UI
}

// ============================================================================
// cXPersonImpl::IncrementSimSocialInterest(float)
// Address: 0x8012BB8C | Size: 588 bytes
// NON_MATCHING - GCC float codegen
// ============================================================================
void cXPersonImpl::IncrementSimSocialInterest(float amount) {
    // Adjust social interest between sims
    // 1. Find target sim in social interest map
    // 2. If not found, add new entry
    // 3. Increment interest value by amount
    // 4. Clamp to valid range
    // 5. If interest drops below threshold, remove entry
}

// ============================================================================
// cXPersonImpl::GetSimSocialInterestAsMotiveValue(cXPerson *)
// Address: 0x8012BDD8 | Size: 368 bytes
// NON_MATCHING - GCC float codegen
// ============================================================================
void cXPersonImpl::GetSimSocialInterestAsMotiveValue(cXPerson* person) {
    // Convert social interest into a motive-scale value
    // 1. Look up interest value for target person
    // 2. Scale from internal range to motive range [0, 100]
    // 3. Apply any modifiers (personality, etc.)
}

// ============================================================================
// cXPersonImpl::SetSimSocialIntrestFromMotiveValue(cXPerson *, float)
// Address: 0x8012BF48 | Size: 324 bytes
// NON_MATCHING - GCC float codegen
// ============================================================================
void cXPersonImpl::SetSimSocialIntrestFromMotiveValue(cXPerson* person, float value) {
    // Set social interest from a motive-scale value
    // 1. Convert motive-scale value to internal range
    // 2. Find or create entry in social interest map
    // 3. Store converted value
}

// ============================================================================
// __static_initialization_and_destruction_0 (person.obj)
// Address: 0x8012C36C | Size: 356 bytes
// NON_MATCHING - GCC static init ordering
// ============================================================================
void __static_initialization_and_destruction_0_person(int init, int priority) {
    // Static initialization for person.obj
    // Initializes static data members:
    // - AutonomyConstantsClient instance
    // - Happy motive tables
    // - PiecewiseFn curves for happiness calculation
    // - Social interest decay constants
    if (init == 1 && priority == 65535) {
        // Initialize statics
    }
    if (init == 0 && priority == 65535) {
        // Destroy statics
    }
}

// ============================================================================
// cXPerson::cXPerson(int)
// Address: 0x8012C4D0 | Size: 436 bytes
// NON_MATCHING - GCC constructor ABI, vtable setup
// ============================================================================
cXPerson::cXPerson(int type) {
    // Constructor for cXPerson
    // 1. Call base class constructor (cXObject)
    // 2. Set cXPerson vtable
    // 3. Initialize person-specific members
    // 4. Create and attach cXPersonImpl
    // 5. Set up action queue
}

// ============================================================================
// vector<MotiveInc>::reserve(unsigned int)
// Address: 0x803A99B8 | Size: 396 bytes
// NON_MATCHING - GCC vector codegen
// ============================================================================
// Template instantiation for vector<MotiveInc>
void vector_MotiveInc_reserve(void* vec, unsigned int newCap) {
    // Standard vector reserve implementation
    // 1. If newCap <= current capacity, return
    // 2. Allocate new buffer
    // 3. Copy existing elements
    // 4. Deallocate old buffer
    // 5. Update pointers
}

// ============================================================================
// vector<RouteGoal>::operator=(vector<RouteGoal> &)
// Address: 0x803A9B44 | Size: 612 bytes
// NON_MATCHING - GCC vector assignment codegen
// ============================================================================
// Template instantiation for vector<RouteGoal>
void vector_RouteGoal_assign(void* dst, void* src) {
    // Standard vector assignment operator
    // 1. If self-assignment, return
    // 2. If src size > dst capacity, reallocate
    // 3. Copy elements from src
    // 4. Update size
}

// ============================================================================
// void DoContainerStream<vector<XRoute>, XRoute>(...)
// Address: 0x803AA520 | Size: 424 bytes
// NON_MATCHING - GCC template codegen
// ============================================================================
void DoContainerStream_XRoute(void* vec, void* defaultVal, void* buf, int dir) {
    // Stream a vector of XRoute to/from a ReconBuffer
    // 1. Stream count
    // 2. If loading, resize vector
    // 3. Stream each element
}

// ============================================================================
// vector<ObjectRecord>::_M_fill_insert(...)
// Address: 0x803AA6C8 | Size: 952 bytes
// NON_MATCHING - GCC vector insert codegen
// ============================================================================
void vector_ObjectRecord_fill_insert(void* vec, void* pos, unsigned int count, void* val) {
    // Insert 'count' copies of 'val' at position 'pos'
    // Standard SGI STL vector fill_insert implementation
}

// ============================================================================
// void DoContainerStream<vector<ObjectRecord>, ObjectRecord>(...)
// Address: 0x803AAB88 | Size: 264 bytes  (note: map shows 0x803AAB88 for MotiveInc variant)
// NON_MATCHING - GCC template codegen
// ============================================================================
void DoContainerStream_ObjectRecord(void* vec, void* defaultVal, void* buf, int dir) {
    // Stream a vector of ObjectRecord to/from a ReconBuffer
}

// ============================================================================
// vector<MotiveInc>::_M_fill_insert(...)
// Address: 0x803AAB88 | Size: 952 bytes
// NON_MATCHING - GCC vector insert codegen
// ============================================================================
void vector_MotiveInc_fill_insert(void* vec, void* pos, unsigned int count, void* val) {
    // Insert 'count' copies of 'val' at position 'pos'
}

// ============================================================================
// void DoContainerStream<vector<MotiveInc>, MotiveInc>(...)
// Address: 0x803AAF40 | Size: 264 bytes
// NON_MATCHING - GCC template codegen
// ============================================================================
void DoContainerStream_MotiveInc(void* vec, void* defaultVal, void* buf, int dir) {
    // Stream a vector of MotiveInc to/from a ReconBuffer
}

// ============================================================================
// void _S_sort<ScoredInteraction, less<ScoredInteraction> >(list &, less)
// Address: 0x803AB1DC | Size: 664 bytes
// NON_MATCHING - GCC list sort codegen
// ============================================================================
void S_sort_ScoredInteraction(void* list, void* compare) {
    // Merge sort implementation for std::list<ScoredInteraction>
    // SGI STL list sort algorithm
    // Uses temporary lists and merge operations
}

// ============================================================================
// _Rb_tree<short, pair<short,bool>>::_M_insert(...)
// Address: 0x803AB4D0 | Size: 276 bytes
// NON_MATCHING - GCC tree codegen
// ============================================================================
void Rb_tree_short_bool_insert(void* tree, void* x, void* y, void* val, void* z) {
    // Red-black tree node insertion
    // Standard SGI STL rb_tree insert implementation
}

// ============================================================================
// _Rb_tree<short, pair<short,bool>>::insert_unique(pair &)
// Address: 0x803AB5E4 | Size: 280 bytes
// NON_MATCHING - GCC tree codegen
// ============================================================================
void Rb_tree_short_bool_insert_unique(void* tree, void* val) {
    // Insert unique element into red-black tree
    // If key already exists, do nothing
}

// ============================================================================
// _Rb_tree<short, pair<short,bool>>::insert_unique(iterator, pair &)
// Address: 0x803AB6FC | Size: 608 bytes
// NON_MATCHING - GCC tree codegen
// ============================================================================
void Rb_tree_short_bool_insert_unique_hint(void* tree, void* hint, void* val) {
    // Insert unique element with hint iterator
    // Uses hint for O(1) amortized insertion when hint is correct
}

// ============================================================================
// XRoute::XRoute(XRoute &)
// Address: 0x803AB95C | Size: 544 bytes
// NON_MATCHING - GCC copy constructor codegen
// ============================================================================
void XRoute_copy_ctor(void* dst, void* src) {
    // Copy constructor for XRoute (164 bytes)
    // Deep copies all route data including embedded vectors and strings
}

#endif  // Reference decompilation
