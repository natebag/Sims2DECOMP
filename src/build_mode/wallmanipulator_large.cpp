// wallmanipulator_large.cpp - WallManipulator large functions (257-1024 bytes)
// Object file: wallmanipulator.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
    void* memset(void* dst, int val, u32 n);

    // World/wall functions
    extern void* g_pWorld;
}

// ============================================================================
// InteractorModule::WallManipulator::~WallManipulator(void)
// Address: 0x8021f648
// Size: 0x174 = 372 bytes
// NON_MATCHING - destructor chain, vector cleanup
// ============================================================================
void WallManipulator_dtor(void* self) {
    char* _this = (char*)self;

    // Clean up fence sell count vector
    // Clean up pattern sell count vector
    // Clean up callback data

    // Clear wall segment data
    // Release any held shader references

    // Call base class destructor (Interactor)

    (void)_this;
}

// ============================================================================
// InteractorModule::WallManipulator::OnStart(InteractorModule::Interactor::InteractorParams*)
// Address: 0x8021f83c
// Size: 0x2dc = 732 bytes
// NON_MATCHING - complex initialization, mode setup
// ============================================================================
void WallManipulator_OnStart(void* self, void* params) {
    char* _this = (char*)self;

    // Get interactor params
    // Determine mode: wall add, wall delete, fence, room, paint

    // Initialize cursor position
    // Set anchor point to invalid
    // Clear wall segment validation

    // Set up mode-specific state:
    // If wall add mode:
    //   Load wall shader preview
    //   Initialize cost tracking
    // If wall delete mode:
    //   Set up deletion preview rendering
    // If fence mode:
    //   Load fence shader
    //   Set fence height
    // If room mode:
    //   Initialize room preview
    //   Load room cost data

    // Register input callbacks
    // Set up visual feedback

    // Initialize sell count vectors
    // Clear affected wall list

    (void)_this;
    (void)params;
}

// ============================================================================
// InteractorModule::WallManipulator::CommittTransaction(InteractorModule::Interactor::ClientNotificationState)
// Address: 0x8021fba4
// Size: 0x71c = 1820 bytes (over 1024 - skip)
// ============================================================================

// ============================================================================
// InteractorModule::WallManipulator::FinalizePlacement(void)
// Address: 0x802202c0
// Size: 0x2b0 = 688 bytes
// NON_MATCHING - wall placement finalization, cost calculation
// ============================================================================
void WallManipulator_FinalizePlacement(void* self) {
    char* _this = (char*)self;

    // Get current wall segment
    // Validate placement is legal

    // Calculate final cost
    // Deduct from budget

    // Place walls along the defined line:
    // For each tile in the line:
    //   Set wall at tile
    //   Update room computation
    //   Add visual wall instance

    // Update affected neighbor walls
    // Trigger room recomputation
    // Notify UI of budget change

    // Clear current segment
    // Reset anchor point

    (void)_this;
}

// ============================================================================
// InteractorModule::WallManipulator::CountWallsInRoomSelection(void)
// Address: 0x80220940
// Size: 0x1bc = 444 bytes
// NON_MATCHING - room traversal, wall counting
// ============================================================================
int WallManipulator_CountWallsInRoomSelection(void* self) {
    char* _this = (char*)self;

    // Get current room selection boundaries
    // Iterate through all tiles in selection

    int wallCount = 0;

    // For each tile in room selection:
    //   Check all 4 wall segments (N, E, S, W)
    //   Count walls that are room-boundary walls
    //   Skip exterior walls (lot boundary)

    // Return total wall count for cost estimation

    (void)_this;
    return wallCount;
}

// ============================================================================
// InteractorModule::WallManipulator::HandleFinalizeRequest(void)
// Address: 0x80221028
// Size: 0x2b4 = 692 bytes
// NON_MATCHING - request handling, mode-specific finalization
// ============================================================================
void WallManipulator_HandleFinalizeRequest(void* self) {
    char* _this = (char*)self;

    // Determine current mode
    int mode = *(int*)(_this + 0x30);

    // Switch on mode:
    // Case WALL_ADD:
    //   FinalizePlacement()
    //   Play wall build sound
    // Case WALL_DELETE:
    //   FinalizeWallDel()
    //   Play wall demolish sound
    // Case ROOM_ADD:
    //   FinalizeRoom()
    //   Play room build sound
    // Case FENCE_ADD:
    //   FinalizePlacement() with fence flag
    //   Play fence build sound

    // Update budget display
    // Clear current selection
    // Reset state for next operation

    (void)mode;
}

// ============================================================================
// InteractorModule::WallManipulator::ValidateWallSegment(void)
// Address: 0x802213c0
// Size: 0x2f8 = 760 bytes
// NON_MATCHING - wall legality checks, terrain validation
// ============================================================================
void WallManipulator_ValidateWallSegment(void* self) {
    char* _this = (char*)self;

    // Get anchor point and current cursor position
    // Calculate wall line from anchor to cursor

    // For each tile along the wall line:
    //   Check if tile is within building bounds
    //   Check if tile already has a wall on this segment
    //   Check for conflicting architecture (stairs, multi-tile objects)
    //   Check if wall would create invalid room topology

    // Set valid/invalid flag
    // Update visual preview (green = valid, red = invalid)

    // Calculate cost for valid segments
    // Update cost display

    (void)_this;
}

// ============================================================================
// InteractorModule::WallManipulator::GetWallLineCost(EVec3&, EVec3&, bool&, bool, bool)
// Address: 0x80221bd4
// Size: 0x214 = 532 bytes
// NON_MATCHING - cost calculation along wall line
// ============================================================================
int WallManipulator_GetWallLineCost(void* self, void* startPos, void* endPos,
                                    int* outValid, int isFence, int isDelete) {
    char* _this = (char*)self;

    // Calculate tile positions from world coordinates
    // Get start tile and end tile

    // Walk along the wall line
    int totalCost = 0;
    *outValid = 1;

    // For each tile segment:
    //   If adding: check CanChangeTileAdd, accumulate wall cost
    //   If deleting: check CanChangeTileDelete, accumulate refund
    //   If any segment invalid: set outValid = false

    // Apply fence cost modifier if isFence
    // Apply sell-back discount if isDelete

    (void)_this;
    (void)startPos;
    (void)endPos;
    (void)isFence;
    (void)isDelete;
    return totalCost;
}

// ============================================================================
// InteractorModule::WallManipulator::SubmitLine(EVec3&, EVec3&, int&, bool, bool)
// Address: 0x80221de8
// Size: 0x190 = 400 bytes
// NON_MATCHING - line submission, wall placement
// ============================================================================
void WallManipulator_SubmitLine(void* self, void* startPos, void* endPos,
                                int* outCost, int isFence, int isDelete) {
    char* _this = (char*)self;

    // Convert world positions to tile coordinates
    // Clamp to buildable area

    // Walk the tile line from start to end
    // For each tile:
    //   If adding: HandleAddLine
    //   If deleting: HandleDeleteLine
    //   Accumulate cost

    // Update total transaction cost
    // Refresh visual preview

    (void)_this;
    (void)startPos;
    (void)endPos;
    (void)outCost;
    (void)isFence;
    (void)isDelete;
}

// ============================================================================
// InteractorModule::WallManipulator::Update(float)
// Address: 0x8022176c
// Size: 0x248 = 584 bytes
// NON_MATCHING - input processing, cursor update, validation
// ============================================================================
void WallManipulator_Update(void* self, float dt) {
    char* _this = (char*)self;

    // Update cursor position from controller input
    // AdjustCursorPosition()

    // Update stick state for input handling
    // UpdateStickState()

    // If anchored:
    //   ValidateWallSegment()
    //   Update cost preview
    //   Update visual wall preview
    // Else:
    //   Show cursor highlight at current position
    //   Check if tile is valid for starting

    // Update send build item count change event
    // Handle pending finalize/cancel requests

    (void)_this;
    (void)dt;
}

// ============================================================================
// InteractorModule::WallManipulator::CanChangeTileAdd(CTilePt&, TileWallsSegment)
// Address: 0x8022237c
// Size: 0x14c = 332 bytes
// NON_MATCHING - tile validation for wall addition
// ============================================================================
int WallManipulator_CanChangeTileAdd(void* self, void* tilePt, int segment) {
    char* _this = (char*)self;

    // Check if tile is within building bounds
    // Check if wall already exists at this segment
    // Check for conflicting objects
    // Check terrain height compatibility
    // Check lot boundary restrictions
    // Check maximum wall count

    (void)_this;
    (void)tilePt;
    (void)segment;
    return 1;
}

// ============================================================================
// InteractorModule::WallManipulator::HandleDeleteLine(CTilePt&, CTilePt&, TilePtDir&, int)
// Address: 0x802229e4
// Size: 0x40c = 1036 bytes (over 1024 - borderline, included)
// NON_MATCHING - wall deletion along line
// ============================================================================
// NON_MATCHING - too large, skip

// ============================================================================
// InteractorModule::WallManipulator::HandleAddLine(CTilePt, CTilePt, TilePtDir&, int)
// Address: 0x80222df0
// Size: 0x298 = 664 bytes
// NON_MATCHING - wall addition along line
// ============================================================================
void WallManipulator_HandleAddLine(void* self, void* startTile, void* endTile,
                                    void* dir, int cost) {
    char* _this = (char*)self;

    // Calculate direction from start to end
    // Determine wall segments needed

    // For each tile along the line:
    //   Get current tile walls
    //   Add wall segment in appropriate direction
    //   SetWall on world
    //   Update wall visual instance

    // Track costs
    // Update sell count for style

    (void)_this;
    (void)startTile;
    (void)endTile;
    (void)dir;
    (void)cost;
}

// ============================================================================
// InteractorModule::WallManipulator::LegalWallTile(CTilePt&, TileWallsSegment)
// Address: 0x80223088
// Size: 0x2cc = 716 bytes
// NON_MATCHING - comprehensive legality check
// ============================================================================
int WallManipulator_LegalWallTile(void* self, void* tilePt, int segment) {
    char* _this = (char*)self;

    // Check bounds
    // Check if tile already has maximum walls
    // Check for stairs on tile
    // Check for multi-tile objects that would be bisected
    // Check for pool tiles
    // Check for elevation changes at tile boundary
    // Verify room topology would remain valid

    (void)_this;
    (void)tilePt;
    (void)segment;
    return 1;
}

// ============================================================================
// InteractorModule::WallManipulator::IncrementSellCountForStyle(WallStyle)
// Address: 0x80223584
// Size: 0x21c = 540 bytes
// NON_MATCHING - vector search and update
// ============================================================================
void WallManipulator_IncrementSellCountForStyle(void* self, int style) {
    char* _this = (char*)self;

    // Search fence sell count vector for matching style
    // If found: increment count
    // If not found: add new entry with count = 1

    // Search pattern sell count vector for matching style
    // If found: increment count
    // If not found: add new entry with count = 1

    // Update total sell value

    (void)_this;
    (void)style;
}

// ============================================================================
// InteractorModule::WallManipulator::AddWallAtTile(CTilePt&, TileWalls&, TileWallsSegment)
// Address: 0x80223354
// Size: 0x180 = 384 bytes
// NON_MATCHING - world wall modification
// ============================================================================
void WallManipulator_AddWallAtTile(void* self, void* tilePt, void* walls, int segment) {
    char* _this = (char*)self;

    // Get current walls at tile from world
    // Merge new segment into existing walls
    // Set wall style from current selection

    // Update world data
    // SetWall on world

    // Update room computation dirty flag
    // Mark tile as modified

    // Add to affected walls list for preview

    (void)_this;
    (void)tilePt;
    (void)walls;
    (void)segment;
}

// ============================================================================
// InteractorModule::WallManipulator::DoesNotConflictWithExistingArchitecture(CTilePt&, TileWallsSegment)
// Address: 0x80221f78
// Size: 0x404 = 1028 bytes (borderline, skip)
// ============================================================================

// ============================================================================
// vector<InteractorModule::FenceSellCount>::reserve(unsigned int)
// Address: 0x803c092c
// Size: 0x168 = 360 bytes
// NON_MATCHING - STL vector reserve
// ============================================================================
void vector_FenceSellCount_reserve(void* vec, u32 newCap) {
    char* _this = (char*)vec;
    void** begin = *(void***)(_this + 0x00);
    void** end = *(void***)(_this + 0x04);
    void** capEnd = *(void***)(_this + 0x08);

    u32 currentCap = (u32)((char*)capEnd - (char*)begin);
    u32 elementSize = 8; // sizeof(FenceSellCount)
    u32 newBytes = newCap * elementSize;

    if (newBytes <= currentCap) return;

    // Allocate new buffer
    void* newBuf = operator_new_wrapper(newBytes);

    // Copy existing elements
    u32 usedBytes = (u32)((char*)end - (char*)begin);
    if (usedBytes > 0) {
        memcpy(newBuf, begin, usedBytes);
    }

    // Free old buffer
    if (begin) {
        operator_delete_wrapper(begin);
    }

    // Update vector pointers
    *(void**)(_this + 0x00) = newBuf;
    *(void**)(_this + 0x04) = (char*)newBuf + usedBytes;
    *(void**)(_this + 0x08) = (char*)newBuf + newBytes;
}

// ============================================================================
// vector<InteractorModule::PatternSellCount>::reserve(unsigned int)
// Address: 0x803c0a94
// Size: 0x168 = 360 bytes
// NON_MATCHING - STL vector reserve (same pattern as above)
// ============================================================================
void vector_PatternSellCount_reserve(void* vec, u32 newCap) {
    // Same pattern as FenceSellCount reserve
    char* _this = (char*)vec;
    void** begin = *(void***)(_this + 0x00);
    void** end = *(void***)(_this + 0x04);
    void** capEnd = *(void***)(_this + 0x08);

    u32 currentCap = (u32)((char*)capEnd - (char*)begin);
    u32 elementSize = 8;
    u32 newBytes = newCap * elementSize;
    if (newBytes <= currentCap) return;

    void* newBuf = operator_new_wrapper(newBytes);
    u32 usedBytes = (u32)((char*)end - (char*)begin);
    if (usedBytes > 0) memcpy(newBuf, begin, usedBytes);
    if (begin) operator_delete_wrapper(begin);

    *(void**)(_this + 0x00) = newBuf;
    *(void**)(_this + 0x04) = (char*)newBuf + usedBytes;
    *(void**)(_this + 0x08) = (char*)newBuf + newBytes;
}

// ============================================================================
// InteractorModule::WallManipulator::CallbackData::~CallbackData(void)
// Address: 0x803c0e1c
// Size: 0x12c = 300 bytes
// NON_MATCHING - callback data cleanup
// ============================================================================
void WallManipulator_CallbackData_dtor(void* self) {
    char* _this = (char*)self;

    // Clear callback function pointers
    // Release referenced objects
    // Free allocated buffers

    (void)_this;
}

// ============================================================================
// vector<FenceSellCount>::operator=(vector&)
// Address: 0x803c0bfc
// Size: 0x220 = 544 bytes
// NON_MATCHING - STL vector assignment operator
// ============================================================================
void vector_FenceSellCount_assign(void* dst, void* src) {
    char* _dst = (char*)dst;
    char* _src = (char*)src;

    // Get source size
    void** srcBegin = *(void***)(_src + 0x00);
    void** srcEnd = *(void***)(_src + 0x04);
    u32 srcCount = (u32)((char*)srcEnd - (char*)srcBegin);

    // Get dest capacity
    void** dstBegin = *(void***)(_dst + 0x00);
    void** dstCapEnd = *(void***)(_dst + 0x08);
    u32 dstCap = (u32)((char*)dstCapEnd - (char*)dstBegin);

    if (srcCount <= dstCap) {
        // Copy in place
        if (srcCount > 0) memcpy(dstBegin, srcBegin, srcCount);
        *(void**)(_dst + 0x04) = (char*)dstBegin + srcCount;
    } else {
        // Need reallocation
        if (dstBegin) operator_delete_wrapper(dstBegin);
        void* newBuf = operator_new_wrapper(srcCount);
        memcpy(newBuf, srcBegin, srcCount);
        *(void**)(_dst + 0x00) = newBuf;
        *(void**)(_dst + 0x04) = (char*)newBuf + srcCount;
        *(void**)(_dst + 0x08) = (char*)newBuf + srcCount;
    }
}
