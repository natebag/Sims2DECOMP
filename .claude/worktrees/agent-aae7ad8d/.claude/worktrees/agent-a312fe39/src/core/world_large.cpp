// world_large.cpp - cFixedWorldImpl large functions (257-512 bytes)
// Object file: world.obj
// Functions: Load, SetLotBorders, vector<CTilePt>::reserve, vtables

#include "core/world.h"

// External functions
extern "C" {
    void* operator_new_wrapper(unsigned int size);   // 0x802d11b0
    void operator_delete_wrapper(void* ptr);         // 0x802d1220
    int iResFile_Read(void* resFile, void* buf, int typeA, int typeB, int sizeC); // 0x800d1a04
    void iResFile_Close(void* resFile, int flags);   // 0x800d1ba8
    void* iResFile_Open(void* resFile, int a, int b); // 0x800d1b1c
    void EString_SetStr(void* str, void* src);       // 0x8009d8f4
    void EString_Clear(void* str, int flags);        // 0x8009d994
    void FloorLayer_Create(int a, int b);            // 0x80048844
    void FloorLayer_Destroy(void* fl, int flags);    // 0x800488bc
    void WallLayer_Create(int a, int b);             // 0x801133e8
    void WallLayer_Destroy(void* wl, int flags);     // 0x80113470
    void TileGrid_SetFlag(void* grid, int x, int y, unsigned char flags); // 0x800b463c
    void TileGrid_SetBorder(void* grid, int mode);   // 0x800b4724
}

// SDA globals
extern "C" {
    extern void* g_pFixedWorld;  // r13 - 0x53F0 (r13-21488)
}

// ============================================================================
// cFixedWorldImpl::Load(iResFile *, int)
// Address: 0x8014cc0c
// Size: 440 bytes (0x1B8)
// NON_MATCHING - complex file I/O with resource type checking, vtable dispatch
//
// Loads world data from a resource file. Reads terrain/tile/wall data
// in chunks, validates sizes, and creates floor/wall layers.
// ============================================================================
// Using free function to avoid header mismatch
static int cFixedWorldImpl_Load(void* self, void* resFile, int flags) {
    char* _this = (char*)self;
    // Try to read terrain chunk from this+0x2c (terrain resfile)
    // Type signature: 'Arry' (0x41727279)
    void* terrainRes = *(void**)(_this + 0x2c);
    int result = iResFile_Read(terrainRes, resFile, 0x41727279, 0x0B, 0);
    if (result != 0) return result;

    // Try wall chunk from this+0x38
    void* wallRes = *(void**)(_this + 0x38);
    result = iResFile_Read(wallRes, resFile, 0x41727279, 0x0C, 0);
    if (result != 0) return result;

    // Try floor chunk from this+0x34
    void* floorRes = *(void**)(_this + 0x34);
    result = iResFile_Read(floorRes, resFile, 0x41727279, 0x08, 0);
    if (result != 0) return result;

    // Get loaded dimensions
    void* terrData = *(void**)(_this + 0x2c);
    int loadedY = *(int*)((char*)terrData + 0x04);
    int loadedX = *(int*)((char*)terrData + 0x08);

    // Check if dimensions match current world
    if (loadedX == *(int*)(_this + 0x14) &&
        loadedY == *(int*)(_this + 0x18)) {
        return 0;
    }

    // Destroy old floor layer if exists
    void* oldFloor = *(void**)(_this + 0x30);
    if (oldFloor != 0) {
        FloorLayer_Destroy(oldFloor, 3);
    }

    // Create new floor layer with loaded dimensions
    // EString for path
    {
        char pathBuf[16]; // stack local for EString
        EString_SetStr(pathBuf, (void*)0x803ede2c); // rodata path string
        void* newFloor = (void*)operator_new_wrapper(0x18);
        iResFile_Open(newFloor, 2, loadedX); // approximate
        EString_Clear(pathBuf, 2);
    }

    *(void**)(_this + 0x30) = 0; // store new floor

    // Destroy old wall layer if exists
    void* oldWall = *(void**)(_this + 0x3c);
    if (oldWall != 0) {
        FloorLayer_Destroy(oldWall, 3);
    }

    // Create new wall layer
    void* newWall = (void*)operator_new_wrapper(0x0c);
    FloorLayer_Create(loadedX, loadedY);
    *(void**)(_this + 0x3c) = newWall;

    // Destroy old influence map
    void* oldInfl = *(void**)(_this + 0x40);
    if (oldInfl != 0) {
        WallLayer_Destroy(oldInfl, 3);
    }

    // Create new influence map
    void* newInfl = (void*)operator_new_wrapper(0x0c);
    WallLayer_Create(loadedX, loadedY);
    *(void**)(_this + 0x40) = newInfl;

    // Check special case: flags <= 80 and dimensions are 64x64
    if (flags <= 80 && loadedX == 64 && loadedY == 64) {
        // Virtual call to resize (offset 0x28/0x2C) with 39,39,1
        void** vtbl = *(void***)_this;
        typedef void (*ResizeFn)(void*, int, int, int);
        short adj = *(short*)((char*)vtbl + 0x28);
        ResizeFn fn = (ResizeFn)*((void**)((char*)vtbl + 0x2c));
        fn(_this + adj, 39, 39, 1);
    }

    // Update stored dimensions
    *(int*)(_this + 0x14) = loadedX;
    *(int*)(_this + 0x18) = loadedY;

    return 0;
}

// ============================================================================
// SetLotBorders(int, int, int, int)
// Address: 0x801517c0
// Size: 452 bytes (0x1C4)
// NON_MATCHING - nested loops with vtable dispatch, border flag logic
//
// Sets the border flags on all tiles around the lot perimeter.
// Iterates X and Y edges, setting walkability and border markers.
// ============================================================================
void SetLotBorders(int x1, int y1, int x2, int y2) {
    // Adjust coordinates by +1
    int adjX1 = x1 + 1;
    int adjY1 = y1 + 1;
    int adjX2 = x2 + 1;
    int adjY2 = y2 + 1;

    void* world = g_pFixedWorld;

    // Get world X size via vtable (offset 0x30/0x34)
    // Compute border range: xSize - adjY2, store adjY1

    // Outer loop: iterate X from 0 to worldXSize
    for (int x = 0; ; x++) {
        // Get xSize via vtable
        void** vtbl = *(void***)world;
        // if x >= xSize, break

        // Inner loop: iterate Y from 0 to worldYSize
        for (int y = 0; ; y++) {
            // Get ySize via vtable
            // if y >= ySize, break

            // Create tile point on stack
            // Call TileGrid_SetFlag with current x,y and border type 1
            // Get world tile flags via vtable (offset 0xFC/0x100)
            // Check if tile is within lot bounds
            int inBounds = 0;
            // Compare against adjX1, adjX2, adjY1, adjY2 bounds
            // If in bounds: clear bit 0x20 (mask with 0xDF)
            // If out of bounds: set bit 0x20 (OR with 0x20)

            // Store modified flags via vtable (offset 0x100/0x104)
            // Move tile point by 2 units via TileGrid_SetBorder
            (void)x; (void)y;
            break; // placeholder
        }
        break; // placeholder
    }
}

// ============================================================================
// vector<CTilePt, allocator<CTilePt> >::reserve(unsigned int)
// Address: 0x803ae260
// Size: 372 bytes (0x174)
// NON_MATCHING - STL vector reserve with small/large alloc branching
//
// Standard vector::reserve implementation for CTilePt elements.
// Uses small_alloc for <=128 bytes, operator new otherwise.
// ============================================================================
void vector_CTilePt_reserve(void* vec, unsigned int newCap) {
    // Similar to AddState vector reallocation
    // Get begin, end, capacity pointers
    // If newCap <= current capacity, return
    // Allocate new buffer (small_alloc or operator_new)
    // Copy elements via memcpy
    // Free old buffer
    // Update begin, end, capacity pointers
    (void)vec;
    (void)newCap;
}
