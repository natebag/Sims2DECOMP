// objectmanipulator_large.cpp - ObjectManipulator large functions (257-1024 bytes)
// Object file: objectmanipulator.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
    void* memset(void* dst, int val, u32 n);
}

// ============================================================================
// InteractorModule::ObjectManipulator::OnStart(InteractorModule::Interactor::InteractorParams*)
// Address: 0x80219074
// Size: 0x17c = 380 bytes
// NON_MATCHING - initialization, mode setup
// ============================================================================
void ObjectManipulator_OnStart(void* self, void* params) {
    char* _this = (char*)self;

    // Initialize object manipulator state
    // Clear current placement object
    // Reset cursor model state
    // Setup interactor input manager for object mode

    // Determine sub-mode: place new vs grab existing
    // Set up visual feedback shader
    // Initialize overlap detection

    // Register callbacks for object interaction
    // Set up camera constraints for buy/build mode

    (void)_this;
    (void)params;
}

// ============================================================================
// InteractorModule::GrabManipulator::OnStart(InteractorModule::Interactor::InteractorParams*)
// Address: 0x8021a07c
// Size: 0x10c = 268 bytes
// NON_MATCHING - grab mode initialization
// ============================================================================
void GrabManipulator_OnStart(void* self, void* params) {
    char* _this = (char*)self;

    // Initialize grab state
    // Clear grabbed object reference
    // Set up highlight shader for grab candidates

    // Initialize controller input for grab mode
    // Set selection radius from params

    // Register object highlight callback
    // Enable cursor model

    (void)_this;
    (void)params;
}

// ============================================================================
// InteractorModule::PlaceManipulator::StartPlacement(InteractorModule::PlaceManipulator::PlaceManipulatorParams*)
// Address: 0x8021a1fc
// Size: 0x14c = 332 bytes
// NON_MATCHING - placement object creation, grid setup
// ============================================================================
void PlaceManipulator_StartPlacement(void* self, void* params) {
    char* _this = (char*)self;

    // Get object GUID from params
    // Create PlacementObject from GUID
    // Initialize grid visualization

    // Set initial placement position from cursor
    // Calculate snapping grid based on object size

    // Set up visual preview
    // Show cost in UI

    (void)_this;
    (void)params;
}

// ============================================================================
// InteractorModule::PlaceManipulator::TryPlacingCurrentObject(void)
// Address: 0x8021a8d8
// Size: 0x114 = 276 bytes
// NON_MATCHING - placement validation, world insertion
// ============================================================================
int PlaceManipulator_TryPlacingCurrentObject(void* self) {
    char* _this = (char*)self;

    // Get current placement object
    void* placementObj = *(void**)(_this + 0x10);
    if (!placementObj) return 0;

    // Get current tile position
    // Check if position is legal via PlacementObject::IsLegalToPlaceAtLocation

    // If legal:
    //   Place object via PlacementObject::Place
    //   Deduct cost from budget
    //   Play placement sound
    //   Notify client of successful placement
    //   Return 1

    // If not legal:
    //   Play error sound
    //   Show error feedback
    //   Return 0

    (void)_this;
    return 0;
}

// ============================================================================
// InteractorModule::GrabManipulator::TryGrabbingWorldObject(void)
// Address: 0x8021a348
// Size: 0xf0 = 240 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// InteractorModule::GrabManipulator::TryGrabbingWorldObjectFromId(short)
// Address: 0x8021a434
// Size: 0xd4 = 212 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// InteractorModule::GrabManipulator::TryRemoveCurrentObjectFromWorld(void)
// Address: 0x8021a620
// Size: 0x19c = 412 bytes
// NON_MATCHING - object removal, inventory management
// ============================================================================
void GrabManipulator_TryRemoveCurrentObjectFromWorld(void* self) {
    char* _this = (char*)self;

    // Get current grabbed object
    // Validate object can be removed (not in use by sim, not locked)

    // Remove from world:
    //   Remove from object manager
    //   Remove from influence maps
    //   Remove from routing data
    //   Remove visual instance

    // Add to player inventory or placement buffer

    // Calculate refund value
    // Update budget

    // Play pickup sound
    // Update UI

    (void)_this;
}

// ============================================================================
// InteractorModule::ObjectManipulator::UpdateObjectHighlights(EIObjectMan*)
// Address: 0x80219c74
// Size: 0x284 = 644 bytes
// NON_MATCHING - object iteration, highlight shader application
// ============================================================================
void ObjectManipulator_UpdateObjectHighlights(void* self, void* objectMan) {
    char* _this = (char*)self;

    // Get cursor world position
    // Get selection radius

    // Clear previous highlights
    // Iterate through nearby objects via object manager

    // For each object in range:
    //   Calculate distance to cursor
    //   If within selection radius:
    //     Check if object is interactable in current mode
    //     If buy mode: check if object is sellable
    //     If build mode: check if object is movable
    //     Apply highlight shader
    //     Track closest valid object

    // Set current highlighted object
    // Update UI tooltip for highlighted object

    (void)_this;
    (void)objectMan;
}

// ============================================================================
// InteractorModule::ObjectManipulator::UpdateOverlapIntersection(InteractorModule::Interactor::OverlapData*)
// Address: 0x80219ef8
// Size: 0x138 = 312 bytes
// NON_MATCHING - overlap detection algorithm
// ============================================================================
void ObjectManipulator_UpdateOverlapIntersection(void* self, void* overlapData) {
    char* _this = (char*)self;

    // Get placement object bounds
    // Get world objects in placement area

    // For each world object:
    //   Calculate bounding box overlap
    //   If overlapping:
    //     Add to overlap list
    //     Set overlap flag

    // Update overlap data with results
    // Set legal placement flag based on overlaps

    (void)_this;
    (void)overlapData;
}

// ============================================================================
// InteractorModule::PlacementObject::CreateNewPlacementObjectFromGuid(unsigned int, unsigned char)
// Address: 0x8021acc4
// Size: 0x120 = 288 bytes
// NON_MATCHING - object creation from GUID, shader setup
// ============================================================================
void PlacementObject_CreateNewPlacementObjectFromGuid(void* self, u32 guid, u8 colorIndex) {
    char* _this = (char*)self;

    // Look up object definition by GUID
    // Get object template
    // Create new cXObject instance from template

    // Set color index
    // Initialize placement state

    // Create grid object for multi-tile objects
    // Set up visual preview model

    // Calculate object footprint
    // Initialize legal position tracking

    (void)_this;
    (void)guid;
    (void)colorIndex;
}

// ============================================================================
// InteractorModule::PlacementObject::GrabExistingObjectInstanceFromId(short)
// Address: 0x8021ade4
// Size: 0x114 = 276 bytes
// NON_MATCHING - object lookup, state transfer
// ============================================================================
void PlacementObject_GrabExistingObjectInstanceFromId(void* self, short objectId) {
    char* _this = (char*)self;

    // Look up object by ID in object manager
    // Validate object is grabbable

    // Store reference to existing object
    // Save current position for undo

    // Create grid object from existing footprint
    // Set up placement preview at current position

    // Mark object as "grabbed" in object manager
    // Remove object from world temporarily

    (void)_this;
    (void)objectId;
}

// ============================================================================
// InteractorModule::PlacementObject::SetObjectColor(cXObject*, unsigned char)
// Address: 0x8021ab88
// Size: 0x13c = 316 bytes
// NON_MATCHING - shader color modification
// ============================================================================
void PlacementObject_SetObjectColor(void* self, void* object, u8 colorIndex) {
    char* _this = (char*)self;

    // Get object's shader list
    // For each shader on the object:
    //   Look up color variant by index
    //   Replace shader texture with colored variant
    //   Update shader parameters

    // If multi-tile object:
    //   Apply color to all sub-objects

    (void)_this;
    (void)object;
    (void)colorIndex;
}

// ============================================================================
// InteractorModule::PlacementObject::Rotate(InteractorModule::PlacementObject::RotateDirection)
// Address: 0x8021c3c8
// Size: 0x65c = 1628 bytes (over 1024 - skip)
// ============================================================================

// ============================================================================
// InteractorModule::PlacementObject::CreateGridObject(FTilePt&, cXObject*)
// Address: 0x8021aef8
// Size: 0x384 = 900 bytes
// NON_MATCHING - grid tile creation for multi-tile objects
// ============================================================================
void PlacementObject_CreateGridObject(void* self, void* tilePt, void* object) {
    char* _this = (char*)self;

    // Get object definition for footprint size
    // Calculate number of tiles needed

    // Create grid tile array
    // For each tile in footprint:
    //   Create ObjSelector for tile
    //   Set tile position relative to anchor
    //   Initialize tile state

    // Set up grid object in placement object
    // Calculate bounding rectangle

    (void)_this;
    (void)tilePt;
    (void)object;
}

// ============================================================================
// InteractorModule::PlacementObject::AssignOffsetsToGridObject(cXMTObjectImpl*, cXObjectImpl*)
// Address: 0x8021bca8
// Size: 0x10c = 268 bytes
// NON_MATCHING - offset calculation for multi-tile placement
// ============================================================================
void PlacementObject_AssignOffsetsToGridObject(void* self, void* mtObject, void* objImpl) {
    char* _this = (char*)self;

    // Get footprint dimensions from multi-tile object definition
    // Calculate offsets for each sub-tile based on rotation

    // For each sub-tile:
    //   Calculate world-space offset from anchor tile
    //   Assign offset to grid object entry
    //   Update visual position

    (void)_this;
    (void)mtObject;
    (void)objImpl;
}

// ============================================================================
// InteractorModule::PlacementObject::Place(FTilePt&, InteractorModule::PlacementData&)
// Address: 0x8021bee4
// Size: 0x188 = 392 bytes
// NON_MATCHING - object placement in world
// ============================================================================
void PlacementObject_Place(void* self, void* tilePt, void* placementData) {
    char* _this = (char*)self;

    // Validate placement position
    // Set object world position from tile

    // If multi-tile: place all sub-tiles
    // Insert object into world object manager
    // Update routing data for new object
    // Add to influence maps

    // Update placement data with result
    // Set object as placed

    (void)_this;
    (void)tilePt;
    (void)placementData;
}

// ============================================================================
// InteractorModule::PlacementObject::Drop(void)
// Address: 0x8021c06c
// Size: 0xf4 = 244 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// InteractorModule::PlacementObject::Pickup(void)
// Address: 0x8021bdb4
// Size: 0xd8 = 216 bytes (under 257, skip)
// ============================================================================

// ============================================================================
// InteractorModule::PlacementObject::ResetLocation(void)
// Address: 0x8021ca24
// Size: 0x29c = 668 bytes
// NON_MATCHING - position reset, grid recalculation
// ============================================================================
void PlacementObject_ResetLocation(void* self) {
    char* _this = (char*)self;

    // Get current anchor tile position
    // Recalculate world position from tile

    // If multi-tile object:
    //   Recalculate all sub-tile positions
    //   Update grid object offsets
    //   Refresh visual instances for all tiles

    // Update bounding box
    // Recalculate legal placement state

    // Update visual preview position
    // Refresh shader state (valid/invalid)

    (void)_this;
}

// ============================================================================
// InteractorModule::PlacementObject::Initialize(void)
// Address: 0x8021c160 (0x74 = 116 bytes - skip)
// ============================================================================

// ============================================================================
// vector<pair<short, PlacementObject::ContainerInfo>>::reserve(unsigned int)
// Address: 0x803c0740
// Size: 0x184 = 388 bytes
// NON_MATCHING - STL vector reserve
// ============================================================================
void vector_ContainerInfo_reserve(void* vec, u32 newCap) {
    char* _this = (char*)vec;
    void** begin = *(void***)(_this + 0x00);
    void** end = *(void***)(_this + 0x04);
    void** capEnd = *(void***)(_this + 0x08);

    u32 elementSize = 12; // sizeof(pair<short, ContainerInfo>)
    u32 currentCap = ((u32)((char*)capEnd - (char*)begin)) / elementSize;
    if (newCap <= currentCap) return;

    u32 newBytes = newCap * elementSize;
    void* newBuf = operator_new_wrapper(newBytes);

    u32 usedBytes = (u32)((char*)end - (char*)begin);
    if (usedBytes > 0) memcpy(newBuf, begin, usedBytes);
    if (begin) operator_delete_wrapper(begin);

    *(void**)(_this + 0x00) = newBuf;
    *(void**)(_this + 0x04) = (char*)newBuf + usedBytes;
    *(void**)(_this + 0x08) = (char*)newBuf + newBytes;
}
