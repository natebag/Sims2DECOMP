// behavior_tree_decomp.cpp - Behavior Tree System Decompilation
// The Sims 2 GameCube - Core Gameplay Logic
//
// This file documents the complete behavior tree execution system, which is how
// every Sim decides what to do and how every interaction is executed. This is
// THE gameplay system -- understanding it means understanding how every
// interaction in the game works.
//
// Original object files: treesim.obj, interaction.obj, behavior.obj,
//                        treetablequickdata.obj, edithvariableset.obj
//
// ============================================================================
// ARCHITECTURE OVERVIEW
// ============================================================================
//
// The Sims 2 behavior tree system descends from The Sims 1 "Edith" scripting
// engine (named after Edith Sims, the fictitious sister of Will Wright's
// creation). The system executes BHAV (BHAVior) bytecode trees that control
// all Sim and object behavior in the game.
//
// Execution flow:
//
//   1. Player clicks an object -> Interaction created from TreeTable entry
//   2. Interaction queued into ActionQueue on the Sim's cXPersonImpl
//   3. cXPersonImpl::AddAction() validates and enqueues the interaction
//   4. TreeSimImpl is initialized with the interaction's behavior tree
//   5. TreeSimImpl::Simulate() runs the tree tick-by-tick
//   6. DoNodeAction() dispatches each BehaviorNode to its primitive handler
//   7. Primitives return true/false to branch through the BHAV tree
//   8. Tree completes when it hits a return node (253=error, 254=true, 255=false)
//
// Key classes:
//   TreeSim          - Base class, holds references to person/object impls
//   TreeSimImpl      - The actual execution engine (derived from TreeSim)
//   TreeStack        - Stack of StackElems for gosub/return
//   StackElem        - One stack frame: current tree, node index, params, locals
//   Behavior         - Resolves tree IDs to BehaviorNode data from IFF resources
//   BehaviorNode     - A single instruction in a BHAV tree (opcode + operands)
//   Interaction      - A queued user action: person + object + tree entry
//   TreeTable/TTAB   - Table of available interactions on an object
//   TreeTableEntry   - One row: action tree ID, check tree ID, ads, flags
//   EdithVariableSet - Per-object variable storage (the Edith variable system)
//
// ============================================================================

#include "types.h"

// Forward declarations
class TreeSim;
class TreeSimImpl;
class TreeStack;
class StackElem;
class Behavior;
class BehaviorNode;
class BehaviorNodeParam;
class ObjectDataBehaviorTree;
class ObjectDataBehaviorConstants;
class Interaction;
class InteractionList;
class ITreeTable;
class ITreeTableEntry;
class ITreeTableAd;
class TreeTable;
class TreeTableEntry;
class TreeTableQuickData;
class TreeTableEntryQuickData;
class TreeTableAdQuickData;
class TreeTableAdScratch;
class TTabScratchEntry;
class EdithVariableSet;
class ObjTestSim;
class ActionQueue;
class cXObject;
class cXObjectImpl;
class cXPerson;
class cXPersonImpl;
class cXMTObjectImpl;
class cXPortalImpl;
class ObjSelector;
class Language;
class XObjLang;
class IBaseSimInstance;
class ISimInstance;
class ESim;
class BString2;
class ReconBuffer;
class BehaviorFinder;
class StringBuffer;
class XPrimParam;
class EActionIcon;

// ============================================================================
// SECTION 1: BHAV (BEHAVIOR) TREE STRUCTURE
// ============================================================================
//
// A BHAV tree is a directed graph of BehaviorNode instructions stored in IFF
// resource files. Each object in the game can have multiple BHAV trees, which
// are organized into three namespaces:
//
//   - Private:     Trees specific to this object (ID 0x1000-0x1FFF typically)
//   - Semi-Global: Trees shared by objects in the same category
//   - Global:      Trees available to all objects (ID 0x0000-0x00FF)
//
// Tree IDs are 16-bit values. The Behavior class resolves a tree ID to its
// BehaviorNode array by searching through these three namespaces.
//
// Each BehaviorNode is a compact instruction containing:
//   - Opcode (u16): Which primitive to execute (0-254 = primitive, 255+ = gosub)
//   - True destination (u8): Node index to jump to on success
//   - False destination (u8): Node index to jump to on failure
//   - Operand data (u32+): Primitive-specific parameters
//
// Special node index values:
//   253 (0xFD) = Error return (tree failed with error)
//   254 (0xFE) = True return  (tree completed successfully)
//   255 (0xFF) = False return (tree completed with failure)
//
// When a node's opcode is > 255, it is a "gosub" -- a call to another BHAV
// tree. The opcode value IS the tree ID to call.
//

// ============================================================================
// BehaviorNode - a single instruction in a BHAV tree
// ============================================================================
// Deduced from Behavior::GetNode, Behavior::GetNodeRef, DoNodeAction usage
//
// The BehaviorNode is read from IFF resource data. From disassembly of
// DoNodeAction, we can see:
//   - offset 0x00: opcode (u16) loaded at lhz r0,0(r6)
//   - offset 0x02: true_dest (u8) loaded at lbz r0,2(r9)
//   - offset 0x03: false_dest (u8) loaded at lbz r0,3(r9)
//   - offset 0x04: operand data (u32) loaded at lwzu r0,4(r6)
//   - offset 0x08: more operand data loaded at lwz r0,4(r6)
//
struct BehaviorNode {
    u16 opcode;         // 0x00 - primitive opcode or tree ID for gosub
    u8  true_dest;      // 0x02 - node index on true result
    u8  false_dest;     // 0x03 - node index on false result
    u32 operand0;       // 0x04 - first operand word (primitive-specific)
    u32 operand1;       // 0x08 - second operand word
    // May have additional operands depending on version
};

// ============================================================================
// Behavior - tree resolver and namespace manager
// ============================================================================
// Address: various functions at 0x800AB---
// The Behavior class owns three IFF behavior resources (private, semi-global,
// global) and resolves tree IDs to their BehaviorNode arrays.
//
// struct Behavior {
//     s16  m_baseTreeID;         // 0x000 - base tree ID for this namespace
//     u8   m_flags[2];           // 0x002 - flags for single-exit optimization
//     u32  m_pResFile;           // 0x004 - IFF resource file containing trees
//     u32  m_pLanguage;          // 0x008 - XObjLang for this object type
//     u32  m_pSelector;          // 0x00C - ObjSelector for object data lookup
// };
//
// Key methods:
//
// Behavior::GetTree(short treeID, ObjectDataBehaviorTree** outTree, bool)
//   Address: 0x800AC384, Size: 236 bytes
//   Resolves a tree ID to its ObjectDataBehaviorTree resource.
//   Searches private namespace first, then semi-global, then global.
//   Returns non-zero on success.
//
// Behavior::GetNode(short treeID, short nodeIndex, BehaviorNode* outNode)
//   Address: 0x800AB560, Size: 92 bytes
//   Gets a single BehaviorNode by tree ID and node index.
//   Copies the node data into the output parameter.
//
// Behavior::GetNodeRef(short treeID, short nodeIndex, BehaviorNode** outNodePtr)
//   Address: 0x800AB5BC, Size: 504 bytes
//   Gets a pointer to a BehaviorNode without copying.
//   More efficient than GetNode for read-only access.
//   Called by DoNodeAction to get the current instruction.
//
// Behavior::CountPrimitives()
//   Address: 0x800AB930, Size: 56 bytes
//   Returns number of registered primitives in the language.
//
// Behavior::Init(Language*, ObjSelector*)
//   Address: 0x80214580, Size: 320 bytes
//   Initializes the behavior with a language definition and object selector.
//   Sets up the three namespace resolution chain.

// ============================================================================
// SECTION 2: THE PRIMITIVE OPCODE SYSTEM
// ============================================================================
//
// Primitives are the "instructions" of the BHAV bytecode. Each primitive
// is a C++ function that takes a StackElem and parameters, and returns a
// result code (true/false/error).
//
// When DoNodeAction encounters a node with opcode <= 254, it dispatches to
// the appropriate primitive handler via a vtable-based call mechanism.
//
// The dispatch mechanism (from DoNodeAction disassembly at 0x80148234):
//   1. Load the vtable at offset 0x40 of TreeSimImpl
//   2. Use the opcode as an index into the vtable
//   3. Call the handler: handler(this, stackElem, opcode, paramData)
//   4. Handler returns a result code:
//      - 0 = false (take false branch)
//      - 1 = true (take true branch)
//      - 2 = yield (tree paused, will resume next tick)
//
// The vtable at offset 0x40 points to a table of function pointers
// structured as pairs of (offset, function_pointer). This is the SN Systems
// C++ vtable format where each entry is 8 bytes: a 16-bit this-adjustment
// followed by padding and a 32-bit function pointer.
//
// Primitive handlers are "Try*" methods on cXObjectImpl and cXPersonImpl.
// Each corresponds to one BHAV opcode. Here is the complete primitive table
// reconstructed from symbol data:
//
// === Object Primitives (cXObjectImpl::Try*) ===
//
//   TryAnimate          - Play an animation on the object
//   TryElement          - Access/modify an element (generic variable op)
//   TryRandom           - Generate a random number
//   TryIdle             - Wait/idle for a duration
//   TryUpdate           - Force an object state update
//   TryGrab             - Grab/release an object
//   TryCheckObject      - Test object properties
//   TryTreeBreak        - Breakpoint for debugging
//   TryRoomEffect       - Modify room score
//   TryPlaySound        - Play a sound effect
//   TryKillSounds       - Stop playing sounds
//   TryKillObject       - Destroy an object
//   TryCreateObject     - Spawn a new object
//   TryPreloadObject    - Preload object resources
//   TryDropOnto         - Place object on another
//   TryBudget           - Check/modify family funds
//   TrySetToNext        - Iterate to next object matching criteria
//   TryCallNamedTree    - Call a BHAV tree by string name
//   TryMakeActionString - Build a localized action string
//   TryPushAction       - Push a new interaction onto the queue
//   TryDialog           - Show a dialog/chooser UI
//   TryShowString       - Display text on screen
//   TryUserEvent        - Fire a user-defined event
//   TryTestObjectType   - Check an object's type ID
//   TryIsPersonInArea   - Test if a Sim is in an area
//   TryFindGoodLocation - Find a valid placement location
//   TrySetBalloon       - Show a thought/speech balloon
//   TryRelationship     - Read/write relationship values
//   TryRelationship2    - Extended relationship operations
//   TryFind5WorstMotives- Find the 5 lowest motive scores
//   TryTutorial         - Trigger tutorial messages
//   TryBurn             - Fire/burn effects
//   TryUIEffect         - Trigger UI effects
//   TrySetMotiveDelta   - Set motive decay/gain rate
//   TryFindFunctionalObject - Find nearest functional object
//   TryCallFunctionalTree   - Call tree on found object
//   TryGenericSimCall   - Generic call to Sim subsystem
//   TryAnimateObject    - Animate with new-style params
//   TryCompleteGoal     - Complete a goal/want
//   TryInventoryCommand - Inventory add/remove/check
//   TryCameraControl    - Move/cut camera
//   TryDistanceTo       - Calculate distance
//   TryDirectionTo      - Calculate direction
//   TryNotifyStackObject- Send notification to stack obj
//   TryParticleEffect   - Spawn particle effect
//   TryMemory           - Access Sim memory system
//   TryPassiveInfluence - Set passive influence
//   TryWantsAndFearsNotify - Trigger wants/fears notification
//   TryChangeWantFearTree  - Switch wants/fears tree
//   TryHUDCreate        - Create HUD element
//   TryHUDAddItem       - Add item to HUD
//   TryHUDManage        - Manage HUD visibility
//   TryHUDData          - Read/write HUD data
//   TrySnap             - Snap object to routing slot
//   TryGbaCommunication - GBA link cable communication
//
// === Person Primitives (cXPersonImpl::Try*) ===
//
//   TryElement          - Access person-specific variables
//   TrySetMotiveDelta   - Set motive delta on person
//   TryGosubFoundAction - Gosub into found action tree
//   TryLookTowards      - Orient Sim to look at target
//   TryGotoRoutingSlot  - Route Sim to a slot on an object
//   TryGotoRelative     - Route Sim to a relative position
//   TryReach            - Reach for an object
//   TryChangeSuit       - Change Sim's clothing
//   TryFindBestAction   - Autonomy: find best action
//   TryIdleForInput     - Wait for player input
//   TryIdleAnimate      - Play idle animation
//   TryTestInteractingWith - Test who Sim is interacting with
//   TrySocialMode       - Enter social interaction mode
//
// The actual dispatch is done through the SN Systems vtable mechanism
// visible at 0x80148234-0x80148258:
//   lwz  r9, 0x40(r31)        // load vtable from TreeSimImpl+0x40
//   lha  r3, 8(r9)            // load this-offset from vtable entry
//   lwz  r0, 12(r9)           // load function pointer
//   add  r3, r31, r3          // adjust this pointer
//   mtlr r0                   // load function address
//   blrl                      // call primitive handler

// ============================================================================
// SECTION 3: TREESIM - THE EXECUTION ENGINE
// ============================================================================

// ----------------------------------------------------------------------------
// TreeSim - base class for behavior tree simulation
// Address range: 0x801476B0-0x80149298
// Estimated size: 0x44 (68 bytes) as base, but extends to 0x54+ with TreeSimImpl
// ----------------------------------------------------------------------------
//
// TreeSim is the base class providing access to the simulated entity.
// It holds pointers to the person, object, and related implementations.
// TreeSimImpl derives from it and adds the actual execution logic.
//
// TreeSim layout (from getter/setter analysis):
//   0x00: [inherited from EStorable - vtable ptr and ref counting]
//
// Key accessors (all 8-byte trivial getters/setters):
//   GetPerson()              -> returns cXPerson*
//   GetBaseISimInstance()    -> returns IBaseSimInstance*
//   SetISimInstance(IBaseSimInstance*)
//   GetESimPerson()          -> returns ESim*
//   SetESimPerson(ESim*)
//   setObjectImpl(cXObjectImpl*)
//   setPersonImpl(cXPersonImpl*)
//   setMTObjectImpl(cXMTObjectImpl*)
//   setPortalImpl(cXPortalImpl*)
//   GetMaxIterations()       -> returns int
//   SetMaxIterations(int)
//   IsBreakForPrimTimeOn()   -> returns bool
//   GetTooLongInPrimTime()   -> returns float
//   SetTooLongInPrimTime(bool, float)
//   GetTooLongInTickTime()   -> returns float
//   SetTooLongInTickTime(bool, float)
//   TraceOnPrimTimeBreak()   -> debug flag
//   SetTraceOnPrimTimeBreak(bool)
//   BreakOnCallTreeStringFailure() -> debug flag
//   IsExecutingInMainSim()   -> returns bool

// TreeSim constructor
// Address: 0x801476B0, Size: 48 bytes
// Initializes base class, zeroes out fields
//
// TreeSim::TreeSim() {
//     // EStorable base constructor
//     // Zero-initialize all member pointers
// }

// TreeSim destructor
// Address: 0x80147224, Size: 52 bytes
// Virtual destructor, cleans up resources
//
// TreeSim::~TreeSim() {
//     // Calls EStorable_Delete if ref count reaches zero
// }

// TreeSim::GetPrimName(short primIndex)
// Address: 0x801491BC, Size: 40 bytes
// Returns the name of a primitive by index.
// Delegates to the Language/XObjLang to look up the name.

// TreeSim::_dyncastimpl(SCID)
// Address: 0x800F2BA4, Size: 176 bytes
// SN Systems dynamic cast implementation. Walks the class hierarchy
// checking SCIDs (class identifiers) to perform safe downcasting.

// ----------------------------------------------------------------------------
// TreeSimImpl - the actual tree execution implementation
// Address range: 0x8014772C-0x801492C0
// Size: ~0x54 (84 bytes) or larger
// ----------------------------------------------------------------------------
//
// TreeSimImpl is where all behavior tree execution happens. It contains:
//   - A TreeStack for gosub/return call frames
//   - Iteration counter and limits
//   - Current error state
//   - Timer tracking for performance monitoring
//   - Vtable pointing to the primitive dispatch table
//
// Layout (from disassembly analysis of constructor and field accesses):
//
// struct TreeSimImpl : TreeSim {
//     // ---- TreeSim base (inherited) ----
//     void*          m_pTreeSim;     // 0x00 - points to the TreeSim portion
//     u32            m_iterations;   // 0x04 - iteration counter (reset each Simulate)
//     f32            m_tickTime;     // 0x08 - accumulated tick time
//     TreeStack      m_stack;        // 0x0C - embedded TreeStack (size ~0x1C)
//     u32            m_lastNodeOp;   // 0x28 - last executed node opcode
//     u32            m_lastResult;   // 0x2C - last primitive result (0=false, 1=true)
//     void*          m_pParams;      // 0x30 - pointer to current param locals
//     s16            m_error;        // 0x34 - error code (0=none, 1000+=error)
//                                    //        1000 = tree lookup failed
//                                    //        1001 = stack empty
//                                    //        1100 = return (success or error)
//                                    //        1101 = max iterations exceeded
//                                    //        1102 = node not found
//                                    //        1103 = breakpoint hit
//     u16            _pad_036;
//     u32            m_field_038;    // 0x38
//     u32            m_field_03C;    // 0x3C
//     void*          m_pVtable;      // 0x40 - primitive dispatch vtable
// };

// TreeSimImpl::TreeSimImpl(int)
// Address: 0x8014772C, Size: 508 bytes
//
// Constructor. The int parameter controls whether to allocate a new TreeSim
// base or use an existing one. If non-zero, it creates the TreeSim portion
// at offset 0x44 and stores a pointer to it at offset 0x00.
//
// The constructor copies the primitive dispatch vtable from a static table
// at 0x80464F98 into local storage. This vtable has entries for each
// primitive opcode, structured as 8-byte entries (this-offset + func ptr).
//
// The static vtable is 168 bytes (21 entries of 8 bytes each), covering
// the core virtual methods:
//   [0]  = GetStackObj vtable entry
//   [1]  = GetPrimitive dispatch
//   [2]  = HandleError
//   [3]  = HandleReturn
//   ... etc
//
// After copying the vtable, it patches all the this-offsets by adding the
// difference between the local storage and the TreeSim base, so that
// each vtable entry correctly adjusts the this pointer.
//
// Then it initializes:
//   - m_iterations = 0
//   - m_pVtable = pointer to the static dispatch table at 0x80464F68
//   - Creates TreeStack at offset 0x0C
//   - m_field_038 = 0
//   - m_lastNodeOp = 253 (error/uninitialized)
//   - m_lastResult = 0
//   - m_pParams = 0
//   - m_error = 0

// TreeSimImpl::Initialize(int stackSize, short* params)
// Address: 0x80147928, Size: 56 bytes
//
// Initializes the tree stack with the given stack size.
// Optionally copies initial parameter values.
//
// void TreeSimImpl::Initialize(int stackSize, short* params) {
//     m_stack.Initialize(stackSize);
//     // if params, copy to m_pParams
// }

// TreeSimImpl::Reset(Behavior* behavior, short treeID)
// Address: 0x80147A34, Size: 108 bytes
//
// Resets the TreeSim to begin executing a new BHAV tree.
// 1. Calls TreeStack::Reset() to clear the call stack
// 2. If treeID is non-zero:
//    a. Creates initial params (zeroed)
//    b. Calls Gosub(behavior, NULL, treeID) to push the first frame
//    c. Clears the error code to 0
//
// void TreeSimImpl::Reset(Behavior* behavior, short treeID) {
//     m_stack.Reset();
//     if (treeID != 0) {
//         short params[2] = {0, 0};
//         Gosub(behavior, NULL, treeID);
//         m_error = 0;
//     }
// }

// TreeSimImpl::Gosub(Behavior* behavior, short* callerParams, short treeID)
// Address: 0x80147AA0, Size: 464 bytes
//
// The BHAV call instruction. Pushes a new frame onto the TreeStack to
// execute a sub-tree, then returns to the calling tree when done.
//
// This is the mechanism that allows BHAV trees to call other BHAV trees,
// enabling code reuse. The global "Interaction" tree might call a
// "Route to Object" sub-tree, which calls a "Find Path" sub-tree, etc.
//
// Detailed flow:
// 1. Get the current top of stack (m_stack.GetNthFrame(stackSize - 1))
// 2. If callerParams is NULL, get params from the current top frame
//    If the top frame has no BehaviorNode pointer, return failure
// 3. Call Behavior::GetTree(treeID, &tree, false) to resolve the tree
//    If not found, clean up and return failure
// 4. Build a new StackElem frame with:
//    - Tree pointer
//    - Tree ID
//    - Starting node index (0)
//    - Parameter and local variable counts from the tree header
// 5. If callerParams is NULL and the current top frame exists,
//    copy the tree's "num parameters" count from the frame
// 6. Check the tree type:
//    - Type 4 (private): validate node index bounds
//    - Other: start at node 0
// 7. Determine the node version bits
// 8. Call TreeStack::Push(newFrame, params) to push onto the stack
// 9. Return 1 on success, 0 on failure
//
// int TreeSimImpl::Gosub(Behavior* behavior, short* callerParams, short treeID) {
//     StackElem* topFrame = m_stack.GetNthFrame(m_stack.GetStackSize() - 1);
//     StackElem* curFrame = topFrame;
//
//     if (callerParams == NULL) {
//         callerParams = curFrame->GetBehaviorNode();  // from top of stack
//         if (callerParams == NULL) return 0;
//     }
//
//     BehaviorNode* node = NULL;
//     ObjectDataBehaviorTree* tree = NULL;
//     if (!behavior->GetTree(treeID, &tree, false)) {
//         // cleanup: release tree if allocated
//         return 0;
//     }
//
//     // Build new stack frame
//     StackElem newFrame;
//     newFrame.SetTreeID(treeID);
//     if (curFrame) {
//         newFrame.m_someField = curFrame->m_someField;
//     } else {
//         newFrame.m_someField = 0;
//     }
//
//     if (callerParams == NULL) {
//         callerParams = m_pParams;  // at offset 0x30
//     }
//
//     // Check tree type for bounds validation
//     int treeType = tree->GetType();  // function at 0x8015AB14
//     if (treeType == 4) {
//         short nodeCount = callerParams[0];
//         int maxNodes = tree->GetNodeCount();  // at 0x8015AB08
//         if (nodeCount >= maxNodes) {
//             nodeCount = maxNodes - 1;
//         }
//     } else {
//         nodeCount = 0;
//     }
//
//     // Get version info for the tree
//     newFrame.m_version0 = tree->GetVersion0();   // at 0x8015ABA0
//     newFrame.m_version1 = tree->GetVersion1();   // at 0x8015AB2C
//
//     // Push the frame
//     m_stack.Push(&newFrame, callerParams);
//
//     // Release tree reference
//     // ...
//     return 1;
// }

// TreeSimImpl::Simulate(int)
// Address: 0x80148550, Size: 136 bytes
//
// The main per-tick simulation entry point. Called once per game tick for
// each active TreeSim. Runs DoNodeAction in a loop until the tree yields,
// completes, or errors.
//
// This is a tight loop:
//   1. Reset iteration counter to 0
//   2. Reset tick timer to 0.0
//   3. Get current top-of-stack StackElem
//   4. Call DoNodeAction(stackElem)
//   5. Check result:
//      - 0: continue (loop back to step 3)
//      - 1: tree completed (return 1)
//      - 2: tree yielded (return 0, will resume next tick)
//   6. If result <= 0, loop back to step 3
//
// int TreeSimImpl::Simulate(int) {
//     m_iterations = 0;
//     m_tickTime = 0.0f;
//
//     while (true) {
//         StackElem* curElem = GetCurElem();  // vtable call to get top of stack
//         int result = DoNodeAction(curElem);
//
//         if (result == 1) return 1;   // tree completed
//         if (result == 2) return 0;   // tree yielded (will resume)
//         // result == 0: continue to next node
//     }
// }

// TreeSimImpl::DoNodeAction(StackElem* stackElem)
// Address: 0x80147FD8, Size: 1380 bytes (345 instructions)
//
// THE CORE FUNCTION. Executes one step of the behavior tree.
// This is the interpreter's main dispatch loop.
//
// Returns:
//   0 = continue (execute next node)
//   1 = tree completed/error (stop)
//   2 = yielded (primitive requested a pause)
//
// Detailed pseudocode:
//
// int TreeSimImpl::DoNodeAction(StackElem* stackElem) {
//     // --- NULL CHECK ---
//     if (stackElem == NULL) {
//         // Stack is empty. Try to get the current element via vtable
//         StackElem* curElem = this->GetCurElem();  // vtable[3] call
//         if (curElem == NULL) {
//             // No element anywhere -- set error
//             g_treeSimError = 1;
//             m_error = 1102;  // "node not found"
//             // Call error handler via vtable[2]
//             return 2;  // yield (error state)
//         }
//         // Pop the empty stack
//         m_stack.Pop();
//         // Call the "just popped" handler via vtable[3]
//         return 0;  // continue
//     }
//
//     // --- GET BEHAVIOR NODE ---
//     Behavior* behavior = stackElem->GetBehavior();  // at stackElem+0x10
//     if (behavior == NULL) {
//         // No behavior attached -- use our embedded behavior resolver
//         behavior = &m_stack;  // m_stack acts as behavior context
//         int stackSize = m_stack.GetStackSize();
//         if (stackSize <= 1) {
//             // Stack underflow
//             g_treeSimError = 1;
//             m_error = 1001;  // "stack empty"
//             return 2;
//         }
//         m_stack.Pop();
//         // Call return handler via vtable[3]
//         return 0;
//     }
//
//     // --- CHECK NODE INDEX BOUNDS ---
//     u16 nodeIndex = stackElem->m_nodeIndex;  // at stackElem+0x02
//     if (nodeIndex > 250) {
//         // This is a return node (253/254/255)
//         goto handleReturn;
//     }
//
//     // --- RESOLVE THE BHAV NODE ---
//     BehaviorNode* nodeData = NULL;
//     short treeID = stackElem->GetTreeID();
//     short nodeIdx = nodeIndex;
//
//     bool found = behavior->GetNodeRef(treeID, nodeIdx, &nodeData);
//     if (!found) {
//         g_treeSimError = 1;
//         m_error = 1102;  // "node not found"
//         return 2;
//     }
//
//     // --- INCREMENT ITERATION COUNTER ---
//     m_iterations++;
//     if (m_iterations >= g_maxIterations) {  // global at r13-0x7BA4
//         g_treeSimError = 1;
//         m_error = 1101;  // "max iterations exceeded"
//         return 2;
//     }
//
//     // --- DECODE OPCODE ---
//     u16 opcode = nodeData->opcode & 0x7FFF;  // mask off high bit
//
//     if (opcode > 255) {
//         // --- GOSUB: call another BHAV tree ---
//         // The opcode IS the tree ID to call
//         u32* operandPtr = &nodeData->operand0;
//         short* paramData = NULL;
//         bool hasCustomParams = (operandPtr[0] == -1);
//         // Check if next word is also -1 (no custom params sentinel)
//         if (!hasCustomParams) {
//             paramData = (short*)operandPtr;
//         }
//
//         int gosubResult = Gosub(behavior, paramData, opcode);
//         if (gosubResult == 0) {
//             return 0;  // gosub failed, continue
//         }
//
//         // Gosub pushed a new frame; set up to find the first reachable node
//         // in the called tree. Store zero params placeholder on stack.
//         short tempParams[1] = {0};
//
//         // Look up the first node of the called tree
//         BehaviorNode* calledNode = NULL;
//         bool gotNode = behavior->GetTree(
//             stackElem->GetTreeID() & 0x7FFF,
//             // ...
//         );
//         if (gotNode) {
//             // Success: start executing the called tree
//             m_error = 1000;  // "tree lookup succeeded" (internal)
//             // Call vtable handler for tree entry
//             // If there was a node to release, release it
//             return 2;  // yield to let the called tree start next tick
//         } else {
//             // Failed to find tree
//             g_treeSimError = 1;
//             m_error = 1102;  // "node not found"
//             // Call error handler
//             return 2;
//         }
//     }
//
//     // --- PRIMITIVE DISPATCH ---
//     // opcode <= 255: this is a primitive instruction
//     //
//     // Dispatch through the vtable at m_pVtable (offset 0x40)
//     // The vtable entry at index [1] (offset 8) is the main dispatch:
//     //   lha  r3, 8(vtable)  = this-offset
//     //   lwz  r0, 12(vtable) = function pointer
//     //   add  r3, this, offset
//     //   blrl
//     //
//     // The dispatch function receives:
//     //   r3 = adjusted this pointer
//     //   r4 = stackElem
//     //   r5 = opcode
//     //   r6 = pointer to operand data (nodeData + 4)
//     //
//     void* dispatchVtable = m_pVtable;
//     int result = dispatchVtable->Dispatch(this, stackElem, opcode,
//                                            (u8*)(nodeData) + 4);
//     //
//     // result = __cmpdi2(result_hi, result_lo, 0, 1)
//     // This is a 64-bit comparison -- the primitive returns a 64-bit value
//     // where the low word is the actual result and high word is flags.
//     //
//     // After the dispatch, the result is checked:
//
//     if (result == 1) {
//         // --- TRUE RESULT ---
//         u8 trueDest = nodeData->true_dest;
//         if (trueDest == 253) {  // 0xFD = error return
//             m_error = 1100;  // "return with error"
//             // Call error handler
//             return 2;
//         }
//         // Update current node to true destination
//         stackElem->m_nodeIndex = trueDest;
//         m_lastResult = 1;  // true
//         m_lastNodeOp = trueDest;
//         stackElem->m_something = 0;
//         return 0;  // continue
//     }
//     else if (result > 1) {
//         // --- YIELD ---
//         // result == 3 means "gosub completed, return to caller"
//         // result == 4 means "error, abort tree"
//         if (__cmpdi2(resultHi, resultLo, 0, 3) == 1) {
//             return 0;  // gosub return -- continue in caller
//         }
//         if (__cmpdi2(resultHi, resultLo, 0, 3) > 0) {
//             // Error -- abort
//             return 2;  // yield/error
//         }
//         if (__cmpdi2(resultHi, resultLo, 0, 4) == 1) {
//             // Some special case
//         }
//         return 2;  // yield
//     }
//     else {
//         // --- FALSE RESULT ---
//         // result == 0 -- take the false branch
//         if (__cmpdi2(resultHi, resultLo, -1, -1) == 1) {
//             return 2;  // special -1 case = yield
//         }
//         if (__cmpdi2(resultHi, resultLo, 0, 0) == 1) {
//             // False branch
//             u8 falseDest = nodeData->false_dest;
//             if (falseDest == 253) {
//                 m_error = 1100;
//                 return 2;
//             }
//             stackElem->m_nodeIndex = falseDest;
//             m_lastResult = 0;  // false
//             m_lastNodeOp = falseDest;
//             stackElem->m_something = 0;
//             return 0;
//         }
//         return 2;  // unknown -- yield
//     }
//
// handleReturn:
//     // --- RETURN NODE HANDLING ---
//     // nodeIndex values >= 253 are return codes:
//     //   253 = error
//     //   254 = true return
//     //   255 = false return
//
//     s16 returnCode = (s16)nodeIndex;
//     if (returnCode == 253 || returnCode < 253) {
//         // Error or underflow
//         goto errorReturn;
//     }
//
//     if (returnCode > 255) {
//         goto errorReturn;
//     }
//
//     // Valid return (254 or 255)
//     // Pop the current tree and prepare to resume the parent
//     behavior = &m_stack;
//     int stackSize = m_stack.GetStackSize();
//     if (stackSize <= 1) {
//         g_treeSimError = 1;
//         m_error = 1001;
//         return 2;
//     }
//
//     m_stack.Pop();
//     // Call return handler
//
//     // Get the caller's StackElem (now on top of stack)
//     StackElem* callerElem = GetCurElem();
//     m_lastResult = (returnCode == 254) ? 0 : 1;  // 254=true->0, 255=false->1
//
//     if (callerElem->m_something == 0) {
//         return 0;
//     }
//
//     // Look up the caller's current node to get the branch destination
//     BehaviorNode* callerNode = NULL;
//     short callerTreeID = callerElem->GetTreeID();
//     short callerNodeIdx = callerElem->m_nodeIndex;
//     behavior->GetNodeRef(callerTreeID, callerNodeIdx, &callerNode);
//
//     if (callerNode == NULL) {
//         g_treeSimError = 1;
//         m_error = 1102;
//         return 2;
//     }
//
//     // Take the appropriate branch in the caller
//     if (returnCode == 254) {
//         // True return from sub-tree
//         u8 dest = callerNode->true_dest;
//         if (dest == 253) goto errorReturn;
//         callerElem->m_nodeIndex = dest;
//     } else {
//         // False return from sub-tree (255)
//         u8 dest = callerNode->false_dest;
//         if (dest == 253) goto errorReturn;
//         callerElem->m_nodeIndex = dest;
//     }
//     m_lastNodeOp = callerElem->m_nodeIndex;
//     return 0;
//
// errorReturn:
//     g_treeSimError = 1;
//     m_error = 1100;
//     // Call error handler
//     return 2;
// }

// TreeSimImpl::RunCheckTree(Behavior*, short treeID, short param, short* result)
// Address: 0x80147C70, Size: 744 bytes
//
// Runs a "check tree" to completion without yielding. Check trees are
// short BHAV trees that return true/false to validate whether an
// interaction is available. They run synchronously (not tick-by-tick).
//
// This is used by ObjTestSim::TestInteraction to validate each entry
// in the TreeTable before showing it in the pie menu.
//
// Flow:
// 1. Save current error state
// 2. Create a temporary StackElem frame
// 3. Push the check tree via TreeStack::Push
// 4. Gosub into the check tree
// 5. Set the initial parameter value
// 6. Save current iteration count and tick time
// 7. Loop: call DoNodeAction until result != 0
//    - If result == 1 (completed):
//      * Check if breakpoint was hit (error 1103)
//      * If no breakpoint, check the global "check tree result" flag
//      * Store result and return
//    - If result > 1 (error): handle error
// 8. When complete, pop the stack frame
// 9. Restore iteration count and tick time
// 10. Return the check tree result
//
// int TreeSimImpl::RunCheckTree(Behavior* behavior, short treeID,
//                                short param, short* result) {
//     s16 savedError = m_error;
//     if (savedError != 0) return 0;
//
//     // Setup temporary frame
//     StackElem frame;
//     frame.m_value = 1;
//     frame.m_nodeIndex = 0;
//     frame.m_userData = 0;
//     TreeStack* stack = &m_stack;
//
//     frame.SetTreeID(-1);
//     stack->Push(&frame, NULL);
//     frame.m_nodeIndex = 0;
//     frame.m_version0 = 0;
//     frame.m_version1 = 0;
//
//     // Gosub into the check tree
//     if (!Gosub(behavior, result, treeID)) {
//         // Cleanup
//         goto done;
//     }
//
//     // Set initial parameter
//     StackElem* curElem = GetCurElem();
//     curElem->m_field_004 = param;
//
//     // Save state
//     int savedIterations = m_iterations;
//     g_globalFlag = 0;  // at r13-0x7BA8
//
//     // Reset counters for the check tree
//     m_iterations = 0;
//     m_tickTime = 0.0f;
//
//     // Execute loop
//     while (true) {
//         StackElem* elem = GetCurElem();
//         int treeID_check = elem->GetTreeID();
//         if (treeID_check == -1) break;  // done
//
//         int result = DoNodeAction(elem);
//         if (result == 0) continue;
//         if (result < 0 || result > 2) continue;
//
//         // result == 1 or 2
//         // Check for debugger breakpoint
//         bool isDebugBrk = /* check via deep vtable chain */;
//         if (!isDebugBrk) {
//             // Error: breakpoint not supported in check trees
//             m_error = 1103;
//             // Handle error
//             break;
//         }
//
//         // Check global flag
//         // ... deep vtable chain to get debug info
//         // ...
//         break;
//     }
//
//     // Pop the temporary frame
//     while (GetCurElem() != NULL) {
//         int tid = GetCurElem()->GetTreeID();
//         if (tid == -1) break;
//         // pop
//     }
//
// done:
//     // Restore state
//     stack->Pop();
//     m_tickTime = savedTickTime;
//     m_iterations = savedIterations;
//     g_globalFlag = savedFlag;
//     return resultValue;
// }

// TreeSimImpl::RunOneTickTree(Behavior*, short, short, short*)
// Address: 0x80147F58, Size: 56 bytes
// Runs exactly one tick of tree execution, then returns.
// Similar to RunCheckTree but does not loop to completion.

// TreeSimImpl::HandleBreakpoint(StackElem*, BehaviorNode*)
// Address: 0x80147F90, Size: 72 bytes
// Debug support -- handles breakpoints set in the Edith IDE.
// In the GC release build, this is mostly a no-op.

// TreeSimImpl::GetHighLevelAction()
// Address: 0x801485D8, Size: 244 bytes
// Walks up the call stack to find the topmost "action" tree.
// Used to display what the Sim is currently doing in the UI.

// TreeSimImpl::GetCurElem()
// Address: 0x801486CC, Size: 60 bytes
// Returns the current top-of-stack StackElem.

// TreeSimImpl::GetMainSimElem()
// Address: 0x80148708, Size: 196 bytes
// Returns the StackElem for the main (bottom) simulation level.

// TreeSimImpl::GetNthElem(short n)
// Address: 0x801487CC, Size: 36 bytes
// Returns the Nth StackElem from the bottom of the stack.

// TreeSimImpl::GetStackSize()
// Address: 0x801487F0, Size: 40 bytes
// Returns the number of frames on the TreeStack.

// ============================================================================
// SECTION 4: THE TREESTACK AND STACK FRAME SYSTEM
// ============================================================================
//
// The TreeStack is a growable stack of StackElem frames. Each StackElem
// represents one level of the BHAV call hierarchy:
//
//   [Bottom] Main interaction tree
//            |-> Sub-tree called by gosub
//                |-> Another sub-tree
//   [Top]            |-> Current executing tree
//
// When DoNodeAction encounters a gosub opcode (>255), it pushes a new
// StackElem. When it encounters a return node (253-255), it pops.

// StackElem layout (from disassembly):
// struct StackElem {
//     u16  m_treeIDPacked; // 0x00 - tree ID with flags packed
//     u16  m_nodeIndex;    // 0x02 - current node index in the tree
//     u16  m_numParams;    // 0x04 - number of parameters
//     u8   m_version0;     // 0x06 - tree version byte 0
//     u8   m_version1;     // 0x07 - tree version byte 1
//     u32  m_pTreeData;    // 0x08 - pointer to ObjectDataBehaviorTree
//     u32  m_field_00C;    // 0x0C - unknown
//     u32  m_pBehavior;    // 0x10 - pointer to Behavior (tree resolver)
//     // After this: dynamically-sized arrays:
//     //   short params[numParams]   - parameters passed from caller
//     //   short locals[numLocals]   - local variables for this tree
// };
//
// StackElem::GetTreeID() const
// Address: 0x80149118, Size: 32 bytes
// Unpacks the tree ID from m_treeIDPacked.
// If raw value is -1, returns -1 (sentinel for "no tree").
// Otherwise returns raw & 0x7FFF.
//
// int StackElem::GetTreeID() const {
//     u16 raw = m_treeIDPacked;
//     if ((s16)raw == -1) return -1;
//     return raw & 0x7FFF;
// }
//
// StackElem::SetTreeID(short id)
// Address: 0x80149138, Size: 36 bytes
// Packs the tree ID into m_treeIDPacked.
//
// StackElem::GetParams()
// Address: 0x80148B7C, Size: 8 bytes
// Returns pointer to the params array (immediately after the fixed fields).
// short* GetParams() { return (short*)((u8*)this + sizeof_fixed_part); }
//
// StackElem::GetLocals()
// Address: 0x80148B84, Size: 20 bytes
// Returns pointer to the locals array (after params).
//
// StackElem::GetSize() const
// Address: 0x80148B98, Size: 28 bytes
// Returns total size of this frame including params and locals.
//
// StackElem::NextFrame() const
// Address: 0x80148BB4, Size: 48 bytes
// Returns pointer to the next frame (this + GetSize()).
//
// StackElem::Setup(StackElem* src, short* params)
// Address: 0x80148BE4, Size: 160 bytes
// Copies frame header from src and initializes params/locals.
//
// StackElem::GetTreeName(StringBuffer&)
// Address: 0x8014754C, Size: 92 bytes
// Looks up the tree name from the resource manager.
//
// StackElem::ReconStream(ReconBuffer*, int, BehaviorFinder*)
// Address: 0x801475A8, Size: 264 bytes
// Serializes frame state for save/load.
//
// StackElem::SetBreak(bool) / GetBreak()
// Address: 0x8014917C / 0x8014915C
// Debug breakpoint flag per frame.

// TreeStack methods:
//
// TreeStack::TreeStack(TreeSimImpl& impl)
// Address: 0x80147164, Size: 52 bytes
// Constructor. Stores reference to parent TreeSimImpl.
//
// TreeStack::Initialize(int stackSize)
// Address: 0x80147450, Size: 36 bytes
// Allocates memory for the stack.
//
// TreeStack::Push(StackElem* frame, short* params)
// Address: 0x80148EC8, Size: 384 bytes
// Pushes a new frame onto the stack. Copies the frame header,
// allocates space for params and locals, and initializes them.
//
// TreeStack::Pop()
// Address: 0x80149048, Size: 124 bytes
// Pops the top frame from the stack.
//
// TreeStack::Reset()
// Address: 0x801490C4, Size: 12 bytes
// Resets the stack to empty.
//
// TreeStack::GetStackSize()
// Address: 0x80149104, Size: 20 bytes
// Returns number of frames on the stack.
//
// TreeStack::GetNthFrame(int n)
// Address: 0x801490D0, Size: 52 bytes
// Returns the Nth frame from the bottom.
//
// TreeStack::GetNewFrame()
// Address: 0x80148C84, Size: 72 bytes
// Returns pointer to next available frame slot.
//
// TreeStack::GetMemUsed()
// Address: 0x80148CCC, Size: 92 bytes
// Returns bytes used by the stack.
//
// TreeStack::GetMemReserved()
// Address: 0x80148D28, Size: 16 bytes
// Returns total bytes reserved for the stack.
//
// TreeStack::AssignFrames(int count)
// Address: 0x80148D38, Size: 400 bytes
// Allocates and initializes frame slots.
//
// TreeStack::MakeNewFrame(unsigned int size)
// Address: 0x80147474, Size: 216 bytes
// Creates a new frame of the given size on the stack.
//
// TreeStack::ReconStream(ReconBuffer*, int, BehaviorFinder*)
// Address: 0x80148818, Size: 864 bytes
// Serializes entire stack for save/load.

// ============================================================================
// SECTION 5: INTERACTIONS - HOW THEY ARE QUEUED AND EXECUTED
// ============================================================================
//
// An Interaction represents a queued action for a Sim. When the player
// clicks "Cook Dinner" on a stove, an Interaction is created linking:
//   - The Sim (cXPerson) who will perform the action
//   - The Object (cXObject) being interacted with
//   - The TreeTable entry index identifying which behavior to run
//   - Various flags and metadata
//
// Interaction layout (from accessor analysis):
//
// struct Interaction {
//     void*      m_pVtable;          // 0x00 - vtable
//     u32        m_type;             // 0x04 - interaction type enum
//     cXPerson*  m_pPerson;          // 0x08 - Sim performing the action
//     cXObject*  m_pStackObject;     // 0x0C - primary target object
//     cXObject*  m_pCurObject;       // 0x10 - current object (may differ from stack)
//     int        m_treeTabEntryIdx;  // 0x14 - index into TreeTable
//     short      m_stackVars[4];     // 0x18 - 4 stack variables (0x18-0x1F)
//     int        m_localVarsCount;   // 0x20 - number of local variables
//     short*     m_pLocalVars;       // 0x24 - heap-allocated local variables
//     int        m_priority;         // 0x28 - priority for queue ordering
//     short      m_treeID;           // 0x2C - BHAV tree ID to execute
//     u8         _pad_02E[2];
//     float      m_attenuation;      // 0x30 - advertising attenuation value
//     BString2   m_name;             // 0x34 - display name (BString2, ~12 bytes)
//     int        m_flags;            // 0x3C - bitfield of flags (see below)
//     void*      m_field_040;        // 0x40 - unknown
//
//     // Flag bits in m_flags (at offset 0x3C):
//     //   bit 0:     AutoFirstSelect  (auto-start this action)
//     //   bit 1:     Continuation     (continues previous action)
//     //   bit 2:     Checked          (has been check-tree validated)
//     //   bit 3:     Available        (is available to execute)
//     //   bit 4:     Hidden           (don't show in pie menu)
//     //   bit 5:     PushToHead       (insert at front of queue)
//     //   bit 6:     CarryNameOver    (keep name from previous action)
//     //   bit 7:     NameChanged      (name was explicitly set)
//     //   bit 8:     Cancelled        (action was cancelled)
//     //   bit 9:     DebugOverride    (debug mode override)
//     //   bit 10:    MustRun          (cannot be cancelled)
//     //   bit 11:    Disabled         (greyed out in menu)
//     //   bits 12-14: TextColor       (3-bit tColor enum)
//     //   bit 15:    RunAsSub         (run as sub-action)
// };
//
// Interaction flag constants (deduced from bit positions in accessors):
enum InteractionFlags {
    FLAG_AUTO_FIRST_SELECT = 0x0001,   // bit 0
    FLAG_CONTINUATION      = 0x0002,   // bit 1
    FLAG_CHECKED           = 0x0004,   // bit 2
    FLAG_AVAILABLE         = 0x0008,   // bit 3
    FLAG_HIDDEN            = 0x0010,   // bit 4
    FLAG_PUSH_TO_HEAD      = 0x0020,   // bit 5
    FLAG_CARRY_NAME_OVER   = 0x0040,   // bit 6
    FLAG_NAME_CHANGED      = 0x0080,   // bit 7
    FLAG_CANCELLED         = 0x0100,   // bit 8
    FLAG_DEBUG_OVERRIDE    = 0x0200,   // bit 9
    FLAG_MUST_RUN          = 0x0400,   // bit 10
    FLAG_DISABLED          = 0x0800,   // bit 11
    FLAG_TEXT_COLOR_MASK   = 0x7000,   // bits 12-14
    FLAG_TEXT_COLOR_SHIFT  = 12,
    FLAG_RUN_AS_SUB        = 0x8000,   // bit 15
};

// The Interaction lifecycle:
//
// 1. CREATION:
//    Interaction(cXPerson*, cXObject*, int treeTabIdx, int type)
//    Address: 0x800C1574, Size: 424 bytes
//
//    - Stores person, object, type, and treeTabEntryIndex
//    - Calls Interaction::GetEntry() to look up the TreeTableEntry
//    - From the entry, reads:
//      * m_treeID (the BHAV tree to execute)  -- via vtable at offset 0x128
//      * m_attenuation (advertising value) -- via vtable at offset 0x158
//      * MustRun flag -- via vtable at offset 0xD8
//      * ManualOnly flag -- via vtable at offset 0x190
//    - Zeroes out stack vars, local vars, name, unique ID
//    - Calls SetUniqueID() to assign a unique interaction ID
//
// 2. VALIDATION:
//    ObjTestSim::TestInteraction(Interaction*, bool, bool, bool, TTabScratchEntry**)
//    Address: 0x80112188, Size: 1368 bytes
//
//    - Creates a temporary TreeSimImpl
//    - Calls TreeSimImpl::RunCheckTree() with the entry's CheckTreeID
//    - If the check tree returns true, the interaction is valid
//    - Sets up interaction colors based on check result
//
// 3. MENU DISPLAY:
//    ObjTestSim::AppendInteractionsForMenu(InteractionList&, int)
//    Address: 0x8011271C, Size: 1164 bytes
//
//    - Iterates all TreeTable entries on the object
//    - For each, creates a temporary Interaction
//    - Calls TestInteraction to validate
//    - If valid, adds to the InteractionList for pie menu display
//
// 4. QUEUEING:
//    cXPersonImpl::AddAction(Interaction*)
//    Address: 0x80125ADC, Size: 904 bytes
//
//    - Calls GetEntry() to check if the interaction is Immediate
//    - If Immediate: calls RunImmediateAction() -- runs synchronously
//    - Otherwise: checks for duplicate actions in the queue
//      * If same icon object and tree tab entry: skip (duplicate)
//    - Checks if the queue has room (max ~10 actions)
//    - If PushToHead flag: inserts at front
//    - Otherwise: calls ActionQueue::Enqueue() to add to back
//
// 5. EXECUTION:
//    When it's this Sim's turn to act:
//    a. cXPersonImpl::SetCurrentAction() picks the next Interaction
//    b. A TreeSimImpl is initialized with the interaction's BHAV tree
//    c. TreeSimImpl::Simulate() runs each tick
//    d. DoNodeAction() dispatches nodes until completion or yield
//    e. When the tree returns, the action is complete

// Interaction::GetEntry() const
// Address: 0x800C182C, Size: 112 bytes
//
// Looks up the ITreeTableEntry for this interaction's treeTabEntryIndex.
// This is how the interaction finds its BHAV tree ID, check tree ID,
// and advertising values.
//
// ITreeTableEntry* Interaction::GetEntry() const {
//     cXObject* obj = m_pStackObject;
//     if (obj == NULL) return NULL;
//     // Get the object's tree table
//     ITreeTable* ttab = obj->GetTreeTab();
//     if (ttab == NULL) return NULL;
//     // Look up entry by index
//     return ttab->GetEntryByIndex(m_treeTabEntryIdx);
// }

// InteractionList - linked list of Interactions
// Address: 0x80113018-0x80113308
//
// A simple linked list used to collect interactions for pie menus
// and autonomy processing. Not a std::list -- custom implementation.
//
// InteractionList::push_back(Interaction&) - adds copy to end
// InteractionList::push_back(cXPerson*, cXObject*, int, int) - creates and adds
// InteractionList::remove(iterator&) - removes at position
// InteractionList::clear() - removes all
// InteractionList::size() const - returns count
// InteractionList::increment(iterator&) - advance iterator

// ActionQueue - the per-Sim action queue
// Address: 0x8011A210-0x8011A714
//
// Each cXPersonImpl has an ActionQueue that holds queued Interactions.
// The queue is displayed in the UI as the action queue HUD.
//
// ActionQueue::Insert(Interaction&, unsigned int) - insert at position
// ActionQueue::Enqueue(Interaction&) - add to end
// ActionQueue::IsVisibleAction(Interaction&) const - check if shown in HUD

// ============================================================================
// SECTION 6: TREE TABLE (TTAB) - AVAILABLE INTERACTIONS ON OBJECTS
// ============================================================================
//
// The TreeTable (TTAB resource) defines which interactions are available
// on an object. Each object type has one TreeTable listing its pie menu
// entries.
//
// TreeTable -> contains N TreeTableEntry records
// Each TreeTableEntry defines:
//   - Action Tree ID:  the BHAV tree to execute when selected
//   - Check Tree ID:   a BHAV tree that validates availability
//   - Name:            localized string for the pie menu
//   - Flags:           availability modifiers
//   - Ads:             motive advertising values
//   - Attenuation:     distance falloff for autonomy
//
// There are two implementations:
//   TreeTable        - loaded from IFF resources (traditional)
//   TreeTableQuickData - loaded from QuickData (optimized GC format)
//
// The QuickData system is a GC-specific optimization that precomputes
// and caches frequently-accessed object data for faster loading.

// TreeTableQuickData layout:
// struct TreeTableQuickData {
//     void*  m_pVtable;       // 0x00
//     u32    m_pEntries;      // 0x04 - array of TreeTableEntryQuickData
//     u32    m_entryCount;    // 0x08 - number of entries
//     u32    m_field_00C;     // 0x0C
//     u8     _pad[0x10];      // 0x10
//     u32    m_refCount;      // 0x20
//     u32    m_pDataID;       // 0x24 - ObjectDataID
// };
//
// TreeTableQuickData::GetNthEntry(int n) const
// Address: 0x8015E088, Size: 244 bytes
// Returns the Nth entry, creating a QuickData wrapper if needed.
//
// TreeTableQuickData::GetEntryByIndex(int index) const
// Address: 0x8015E17C, Size: 96 bytes
// Finds entry by its unique index value.
//
// TreeTableQuickData::GetEntryByTreeID(short treeID, short) const
// Address: 0x8015E1DC, Size: 92 bytes
// Finds entry by the action tree ID.
//
// TreeTableQuickData::CountEntries() const
// Address: 0x8015E900, Size: 44 bytes
// Returns number of TreeTable entries.
//
// TreeTableQuickData::GetPrefixCheckTreeID() const
// Address: 0x8015E92C, Size: 28 bytes
// Returns the global prefix check tree ID. This tree runs before
// any interaction's check tree, providing a global availability filter.

// TreeTableEntryQuickData layout:
// struct TreeTableEntryQuickData {
//     s16    m_index;          // 0x00 - unique entry index
//     s16    m_orderIndex;     // 0x02 - display order in pie menu
//     s16    m_numAds;         // 0x04 - number of motive ads
//     u8     _pad[2];
//     u32    m_pAds;           // 0x08 - array of TreeTableAdQuickData
//     u32    m_field_00C;      // 0x0C
//     // ... more fields
//     u32    m_refCount;       // 0x18
// };
//
// Key entry properties:
//   GetActionTreeID()    - BHAV tree to run for this interaction
//   GetCheckTreeID()     - BHAV tree to validate availability
//   GetImmediate()       - runs immediately (no queue)
//   GetAutoFirstSelect() - auto-start when clicked
//   GetMustRun()         - cannot be cancelled by player
//   GetAvailableToVisitors()   - visitor Sims can use
//   GetAvailableToAdults()     - adult Sims can use
//   GetAvailableToGhosts()     - ghost Sims can use
//   GetCanJoin()         - other Sims can join
//   GetManualOnly()      - only available via player click, not autonomy
//   GetDebugOnly()       - only in debug mode
//   GetIgnorePrefixTree()- skip the global prefix check tree
//   GetAttenuation()     - distance falloff type
//   GetAutonomyThreshold()- minimum score for autonomous selection

// TreeTableAdQuickData - motive advertising
// Each TreeTableEntry can have multiple "ads" that describe how the
// interaction affects Sim motives. The autonomy system uses these to
// score interactions.
//
// struct TreeTableAdQuickData {
//     s16 m_personalityAd;  // which personality trait boosts this
//     s16 m_min;            // minimum motive effect
//     s16 m_max;            // maximum motive effect
//     s16 m_range;          // effective range
// };

// ============================================================================
// SECTION 7: EDITH VARIABLE SET - THE OBJECT VARIABLE SYSTEM
// ============================================================================
//
// The EdithVariableSet is a per-object variable storage system inherited
// from The Sims 1's "Edith" level editor. It provides named variable
// categories that BHAV trees can read and write.
//
// "Edith" was the internal name for The Sims 1's behavior editor tool,
// named after Edith Sims. The variable system it defined became the
// standard way to store per-object state.
//
// EdithVariableSet layout (from constructor and field access analysis):
//
// struct EdithVariableSet {
//     u8   m_bitmap[12];        // 0x00 - bitmap tracking which vars are set
//                               //        (72 bits = 9 bytes, aligned to 12)
//     u32  m_pDynamic;          // 0x0C - byte_key_map for dynamically-allocated vars
//     u32  m_pDynamicEnd;       // 0x10 - end pointer for dynamic vars
//     u32  m_field_014;         // 0x14 - unknown (cleared in ctor, part of inline cache)
//     u32  m_field_018;         // 0x18 - unknown
//     u8   m_categoryID;        // 0x1C - variable category ID
//     u8   _pad_01D;
//     s16  m_varPerson;         // 0x1E - var 8: "Person" variable (inline)
//     s16  m_varRoom;           // 0x20 - var 25: "Room" variable (inline)
//     s16  m_varObject;         // 0x22 - var 29: fixed variable (inline)
//     s16  m_varCount;          // 0x24 - var 34: fixed variable (inline)
//     s16  m_varAge;            // 0x26 - var 1: "Age" variable (inline)
//     s16  m_varID;             // 0x28 - var 0: "ID" variable (inline)
//     s16  m_varGender;         // 0x2A - var 66: "Gender" variable (inline)
//     s16  m_varSomething;      // 0x2C - var 39: fixed variable (inline)
// };
//
// The variable system uses two storage tiers:
//
// 1. INLINE VARIABLES (fast path):
//    Several commonly-accessed variables are stored directly in the struct
//    at fixed offsets. The operator[] checks for these IDs first and returns
//    a direct pointer. This avoids the bitmap/key-map lookup entirely.
//
//    Inline variable mapping (from operator[] at 0x800E4040):
//      var  8 -> offset 0x1E (m_varPerson)
//      var 25 -> offset 0x20 (m_varRoom)
//      var 29 -> offset 0x22
//      var 34 -> offset 0x24
//      var  1 -> offset 0x26 (m_varAge)
//      var  0 -> offset 0x28 (m_varID)
//      var 66 -> offset 0x2A (m_varGender)
//      var 39 -> offset 0x2C
//
// 2. DYNAMIC VARIABLES (general case):
//    All other variables are stored in a byte_key_map<72, short> at offset 0x0C.
//    This is a compact sorted map keyed by variable ID (0-71) with short values.
//    The bitmap at offset 0x00 tracks which variable IDs are present.
//
//    The bitmap is a 72-bit field (3 u32 words = 12 bytes). Each bit
//    corresponds to one variable ID. If the bit is set, the variable
//    exists in the byte_key_map.
//
// Variable Categories (from Initialize switch table at 0x800E33F4):
//   The Initialize function has a large switch statement on category IDs
//   (0-47+) that sets up default variable values for each category.
//   Categories include:
//     0  = Object ID
//     1  = Age
//     3  = (some category with special init)
//     7  = (another category)
//     8  = Person
//     11 = (another category)
//     14 = same as 3
//     23 = (another category)
//     24 = (another category)
//     25 = Room
//     29 = (another category)
//     ...etc up to category 47+
//
// EdithVariableSet::Initialize(cXObjectImpl*)
// Address: 0x800E33F4, Size: 3040 bytes
// The largest function in the set. Initializes variables based on the
// object's category. Uses a category-to-variable mapping table at
// 0x803EAF1C. For each category, looks up or creates a "category variable
// map" and copies default values into the byte_key_map.
//
// EdithVariableSet::operator[](int varID)
// Address: 0x800E4040, Size: 1304 bytes
// Read access to a variable by ID. Returns a pointer to the short value.
//
// Fast path (when g_edithInitialized at r13-0x7C74 is 0):
//   Checks inline variables first (IDs 0,1,8,25,29,34,39,66)
//   Returns direct pointer into struct
//
// Slow path:
//   Looks up in the byte_key_map using bitmap-guided binary search.
//   The bitmap at offset 0x00 is checked to see if the variable exists.
//   If not found, returns pointer to a zero value.
//
// EdithVariableSet::WriteVar(int varID, short value)
// Address: 0x800E4558, Size: 4836 bytes (!)
// Write access. The largest function in the class because it handles:
//   1. Inline variable fast path (same IDs as operator[])
//   2. Bitmap update for the byte_key_map
//   3. Insertion into the byte_key_map if not present
//   4. Notification system -- certain variable writes trigger callbacks
//   5. Special handling for var 0 (ID) which updates the dirty flag
//
// EdithVariableSet::Contains(int varID)
// Address: 0x800E806C, Size: 1168 bytes
// Checks if a variable ID exists in the set.
// Uses the bitmap for quick rejection, then searches the byte_key_map.
//
// EdithVariableSet::Insert(pair<unsigned int, short>&)
// Address: 0x800E5DBC, Size: 6588 bytes (!!)
// Inserts a new variable into the byte_key_map.
// This is extremely large because it handles:
//   - Bitmap updates
//   - Sorted insertion into the key map
//   - Memory reallocation if the map grows
//   - Category-specific side effects
//
// EdithVariableSet::Reset()
// Address: 0x800E7F64, Size: 264 bytes
// Clears all variables and resets the bitmap.
//
// EdithVariableSet::RemoveInstanceVariable(unsigned char varID)
// Address: 0x800E7778, Size: 740 bytes
// Removes a single variable from the dynamic storage.
//
// EdithVariableSet::ShrinkToExactSize(byte_key_map&)
// Address: 0x800E7A5C, Size: 440 bytes
// Compacts the byte_key_map to use only the memory it needs.
//
// EdithVariableSet::GetCategoryVariableMap(unsigned short category)
// Address: 0x800E84FC, Size: 664 bytes
// Looks up the category-to-variable mapping table.
//
// EdithVariableSet::CreateCategoryVariableMap(unsigned short category)
// Address: 0x800E8794, Size: 7964 bytes (!!!)
// Creates a new category variable map. This is the single largest function
// in the entire EdithVariableSet -- nearly 8KB of code. It contains a
// massive switch statement that defines default variable values for every
// possible object category in the game.
//
// EdithVariableSet::ReconStream(ReconBuffer*, int)
// Address: 0x800E583C, Size: 1408 bytes
// Serialization for save/load. Writes the bitmap and all variable values.
//
// EdithVariableSet::ReconOldFdata(ReconBuffer*, unsigned int)
// Address: 0x800E7D30, Size: 564 bytes
// Legacy deserialization for old save formats.
//
// EdithVariableSet::ReconKeyBitSet(ReconBuffer*, iterator)
// Address: 0x800E7C14, Size: 284 bytes
// Serializes the bitmap portion of the key set.

// ============================================================================
// SECTION 8: HOW IT ALL FITS TOGETHER - COMPLETE EXECUTION FLOW
// ============================================================================
//
// Here is the complete flow from player click to action completion:
//
// 1. PLAYER CLICKS OBJECT
//    FlashPiMenu::AddObjectInteractionsToMenu(cXObject*, bool)
//      -> ObjTestSim::AppendInteractionsForMenu(InteractionList&, int)
//         For each TreeTableEntry in the object's TTAB:
//           -> Create temporary Interaction(person, object, entryIndex, type)
//           -> ObjTestSim::TestInteraction(interaction, ...)
//              -> TreeSimImpl::RunCheckTree(behavior, checkTreeID, ...)
//                 [Runs the check tree synchronously to completion]
//              -> If passed, add to InteractionList
//           -> ObjTestSim::SetupInteractionColors(interaction, result)
//    FlashPiMenu::CreateInteractionMenu(cXObject*, InteractionList&)
//      -> Build pie menu from the validated InteractionList
//
// 2. PLAYER SELECTS ACTION FROM PIE MENU
//    FlashPiMenu::ChooseAction(cXObject*, Interaction*, bool)
//      -> InteractorModule::SimInteractor::ChooseAction(Interaction*)
//         -> cXPersonImpl::AddAction(Interaction*)
//            -> Check if Immediate: run now via RunImmediateAction()
//            -> Check for duplicate actions in queue
//            -> ActionQueue::Enqueue(interaction)
//
// 3. SIM'S TURN TO ACT (per tick)
//    cXPersonImpl update loop:
//      -> Get current action from ActionQueue
//      -> Initialize TreeSimImpl with action's BHAV tree
//         -> TreeSimImpl::Reset(behavior, treeID)
//            -> TreeStack::Reset()
//            -> TreeSimImpl::Gosub(behavior, NULL, treeID)
//               -> Behavior::GetTree(treeID, &tree) -- resolve tree
//               -> TreeStack::Push(frame) -- push initial frame
//
// 4. TREE EXECUTION (per tick)
//    TreeSimImpl::Simulate(int)
//      -> Reset iteration counter
//      -> Loop:
//         -> StackElem* curElem = GetCurElem()
//         -> int result = DoNodeAction(curElem)
//            -> Get BehaviorNode from curElem's tree and node index
//            -> If opcode <= 254: PRIMITIVE
//               -> Dispatch through vtable to Try* function
//               -> Try* function reads params, does work, returns result
//               -> Update curElem's nodeIndex to true_dest or false_dest
//            -> If opcode > 255: GOSUB
//               -> Push new frame for the called tree
//               -> Continue execution in the called tree
//            -> If nodeIndex >= 253: RETURN
//               -> Pop frame, resume caller with true/false result
//         -> If result == 1: tree done, stop
//         -> If result == 2: tree yielded, stop for this tick
//         -> If result == 0: continue to next node
//
// 5. TREE COMPLETION
//    When the outermost tree returns (node 254 or 255):
//      -> TreeSimImpl::Simulate returns 1
//      -> Action is complete, removed from ActionQueue
//      -> Next queued action begins
//
// This system processes thousands of BHAV instructions per game tick
// across all active Sims and objects. The iteration limit (checked in
// DoNodeAction at r13-0x7BA4) prevents infinite loops from freezing
// the game. The tick time tracking prevents any single tree from
// consuming too much frame time.
//
// The entire Sims 2 gameplay -- from cooking dinner to socializing to
// going to work -- is expressed as BHAV trees dispatching primitives
// through this system.
//
// ============================================================================
// END OF BEHAVIOR TREE SYSTEM DECOMPILATION
// ============================================================================
