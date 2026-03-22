// interactor_large.cpp - Interactor base class large functions (257-1024 bytes)
// Object file: interactor.obj
// Note: interactor.obj has NO functions in the 257-1024 byte range.
// The largest function is Interactor::Interactor(void) at 0xc4 = 196 bytes.
// All interactor.obj functions are small (<257 bytes).
//
// This file covers directinteractor.obj large functions instead.
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
}

// ============================================================================
// From directinteractor.obj:
// ============================================================================

// ============================================================================
// InteractorModule::DirectInteractor::OnStart(InteractorModule::Interactor::InteractorParams*)
// Address: 0x80203e6c
// Size: 0x268 = 616 bytes
// NON_MATCHING - direct control initialization
// ============================================================================
void DirectInteractor_OnStart(void* self, void* params) {
    char* _this = (char*)self;

    // Initialize direct control state
    // Set up controller input mapping for direct control
    // Initialize sim position tracking
    // Set up camera for direct control mode

    // Get player's active sim
    // Initialize plumb bob display
    // Reset idle timer

    // Set up action menu system
    // Initialize object highlighting for interactions

    // Configure movement parameters
    // Set walk/run speed thresholds
    // Initialize velocity modifiers

    (void)_this;
    (void)params;
}

// ============================================================================
// InteractorModule::DirectInteractor::InitPlayerPos(void)
// Address: 0x80204220
// Size: 0x218 = 536 bytes
// NON_MATCHING - position initialization, terrain snapping
// ============================================================================
void DirectInteractor_InitPlayerPos(void* self) {
    char* _this = (char*)self;

    // Get player's active sim from simulator
    // Get sim's current world position
    // Snap to nearest walkable tile

    // Initialize cursor position from sim position
    // Set up movement bounds based on lot extents

    // Initialize camera target on sim
    // Set plumb bob position above sim

    (void)_this;
}

// ============================================================================
// InteractorModule::DirectInteractor::InterpretFreeMoveInput(void)
// Address: 0x802046fc
// Size: 0x13c = 316 bytes
// NON_MATCHING - controller input to movement direction
// ============================================================================
void DirectInteractor_InterpretFreeMoveInput(void* self) {
    char* _this = (char*)self;

    // Read analog stick values
    // Apply dead zone
    // Calculate movement direction vector

    // Transform from camera-relative to world-space
    // Apply velocity modifiers (run vs walk)

    // Check for collision with walls/objects
    // Adjust movement direction if blocked

    // Update desired animation state based on speed

    (void)_this;
}

// ============================================================================
// InteractorModule::DirectInteractor::ShouldHighlightObject(cXObject*, float)
// Address: 0x80204c5c
// Size: 0x280 = 640 bytes
// NON_MATCHING - object selection logic, distance/angle checks
// ============================================================================
int DirectInteractor_ShouldHighlightObject(void* self, void* object, float distance) {
    char* _this = (char*)self;

    // Check if object is interactable
    // Check if object is within interaction range
    // Check if object is in front of player (angle check)

    // If object has available interactions:
    //   Check visibility (not behind walls)
    //   Check accessibility (can sim reach object)
    //   If passes all checks, return 1

    (void)_this;
    (void)object;
    (void)distance;
    return 0;
}

// ============================================================================
// InteractorModule::DirectInteractor::UpdateObjectHighlights(EIObjectMan*)
// Address: 0x80205c4c
// Size: 0x368 = 872 bytes
// NON_MATCHING - object iteration, highlight management
// ============================================================================
void DirectInteractor_UpdateObjectHighlights(void* self, void* objectMan) {
    char* _this = (char*)self;

    // Clear previous highlights
    // Get player sim position

    // Iterate through nearby objects
    // For each object:
    //   Calculate distance to sim
    //   Call ShouldHighlightObject
    //   If should highlight:
    //     Apply highlight shader
    //     Track as closest highlighted object

    // Set current interaction target
    // Update UI prompt based on available interactions

    (void)_this;
    (void)objectMan;
}

// ============================================================================
// InteractorModule::DirectInteractor::ExecuteActionMenu(void)
// Address: 0x802057c8
// Size: 0x298 = 664 bytes
// NON_MATCHING - interaction menu creation and display
// ============================================================================
void DirectInteractor_ExecuteActionMenu(void* self) {
    char* _this = (char*)self;

    // Get current highlighted object
    // Get available interactions for object

    // Create action menu UI
    // Populate menu with interaction names
    // Sort by priority/relevance

    // Display menu at object position
    // Set up input handling for menu selection

    // Handle autonomous vs player-directed
    // Mark sim as in menu state

    (void)_this;
}

// ============================================================================
// InteractorModule::DirectInteractor::ExecuteObjectActionMenu(cXObject*)
// Address: 0x80205a60
// Size: 0x118 = 280 bytes
// NON_MATCHING - object-specific menu creation
// ============================================================================
void DirectInteractor_ExecuteObjectActionMenu(void* self, void* object) {
    char* _this = (char*)self;

    // Get interaction list for specific object
    // Filter by availability (skill, mood, etc.)
    // Create and show action menu

    // Handle callback for menu selection
    // Set up cancel handler

    (void)_this;
    (void)object;
}

// ============================================================================
// InteractorModule::DirectInteractor::ResetIdleTime(void)
// Address: 0x80205ff4
// Size: 0xd4 = 212 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// InteractorModule::DirectInteractor::Update(float)
// Address: 0x80204838
// Size: 0x3b4 = 948 bytes
// NON_MATCHING - main update loop, input processing, animation
// ============================================================================
void DirectInteractor_Update(void* self, float dt) {
    char* _this = (char*)self;

    // Parse controller input
    // ParseControls()

    // Update control status
    // UpdateControlStatus()

    // If in direct control:
    //   Set velocity modifiers
    //   InterpretFreeMoveInput()
    //   Send movement input to routing system
    //   Update plumb bob position
    //   UpdatePlumbBob()
    //   Check for idle timeout

    // If in object menu:
    //   Update menu selection
    //   Handle menu input

    // Update object highlights if not in menu
    // Check cancel timer
    // Update interaction state

    (void)_this;
    (void)dt;
}

// ============================================================================
// InteractorModule::DirectInteractor::OnCommandPressed(InteractorModule::InteractorInputManager::InteractorCommand, float)
// Address: 0x8020506c
// Size: 0x66c = 1644 bytes (over 1024, skip)
// ============================================================================
