// house_large.cpp - HouseImpl/HouseStats large functions (257-512 bytes)
// Object file: house.obj
// Functions: Initialize, ComputeAndStoreLotData, GetHouseStats, GetSizeScore, GetFurnishingsScore

#include "core/house.h"

// External functions
extern "C" {
    void* operator_new_wrapper(unsigned int size);   // 0x802d11b0
    void CreateTheWorld(void);                       // 0x8015228c
    void* cSimulator_CreateInstance(void);            // 0x801401e4
    void* ObjectModule_CreateInstance(void);          // 0x800f2c54
    void* RoomList_Create(int);                       // 0x8012cbe8
    void RoomList_Init(void*, int);                   // 0x8012cc54
    void* Neighborhood_GetFirst(void);               // 0x800a752c
    void* SpacePartition_Create(void);               // 0x80135dac
    void RoomSurface_Init(void*, int);               // 0x8012ce1c
    void ObjectList_Next(void*);                     // 0x8039d5c8
    int SpacePartition_GetTileCount(void*);          // 0x80138420
    int SpacePartition_GetFloorType(void*);          // 0x80138358
}

// SDA globals
extern "C" {
    extern void* g_pSimulator;    // r13 - 0x53F8 (r13-21496)
    extern void* g_pObjectModule; // r13 - 0x53EC (r13-21484)
    extern void* g_pHouse;        // r13 - 0x53F4 (r13-21492)
    extern void* g_pFixedWorld;   // r13 - 0x53F0 (r13-21488)
    extern void* g_pRoomMgr;     // r13 - 0x53E0 (r13-21472)
    extern void* g_pCursorGlob;  // r13 - 0x53B0 (r13-21424)
    extern void* g_pLotData;     // r13 - 0x7C68 (r13-31848)
}

// ============================================================================
// HouseImpl::Initialize(void)
// Address: 0x800bb4ac
// Size: 508 bytes (0x1FC)
// NON_MATCHING - vtable dispatch patterns, SDA addressing, complex init flow
//
// Full house initialization: creates world, simulator, object module,
// sets up family reference, creates room lists, initializes rooms.
// ============================================================================
void HouseImpl::Initialize(void) {
    // Create the world (39x39 grid)
    CreateTheWorld();

    // Create simulator instance
    g_pSimulator = cSimulator_CreateInstance();

    // Create object module instance
    g_pObjectModule = ObjectModule_CreateInstance();

    // Virtual call on simulator: Init (vtable offset 0x18/0x1c)
    // Virtual call on object module: Init (vtable offset 0x10/0x14)

    // Get family from house via virtual call on g_pHouse (offset 0x120/0x124)
    // Store result at this+0x14 (m_family)

    // Create SpacePartition (48 bytes)
    void* sp = (void*)operator_new_wrapper(0x30);
    // Initialize space partition
    g_pRoomMgr = sp;

    // Create two RoomLists (16 bytes each)
    void* rl1 = (void*)operator_new_wrapper(0x10);
    // Initialize room list 1
    *(void**)((char*)this + 0x1c) = rl1;
    RoomList_Init(rl1, 8);

    void* rl2 = (void*)operator_new_wrapper(0x10);
    *(void**)((char*)this + 0x20) = rl2;
    RoomList_Init(rl2, 8);

    // Get neighborhood info
    void* nbhood = Neighborhood_GetFirst();
    void* prevNbhood = 0;

    // Swap neighborhoods if different
    if (nbhood != prevNbhood) {
        // Virtual dispatch to shutdown old neighborhood
        // Virtual dispatch to startup new neighborhood
    }

    // Get lot data through virtual dispatch (offset 0xE8/0xEC)
    // If lot data valid, setup room surfaces from lot
    // Initialize room surfaces for both room lists

    // Virtual dispatch to finalize (vtable offset 0x18/0x1C on nbhood)
}

// ============================================================================
// HouseImpl::ComputeAndStoreLotData(void)
// Address: 0x800bbae8
// Size: 340 bytes (0x154)
// NON_MATCHING - complex vtable dispatch chain, multiple SDA globals
//
// Queries lot data from the object module and simulator, stores computed
// values for lot size, room count, and expenses.
// ============================================================================
void HouseImpl::ComputeAndStoreLotData(void) {
    // Virtual call on g_pObjectModule (offset 0x200/0x204) to get lot metrics
    // Returns various lot data into stack locals

    // Virtual call on g_pFixedWorld (offset 0x120/0x124) to get family
    // Store family result

    // If family exists:
    //   Virtual call (offset 0x100/0x104) with lot width
    //   Virtual call (offset 0x110/0x114) with lot height

    // Virtual calls on g_pSimulator:
    //   (offset 0x138/0x13C) with lot data field 1
    //   (offset 0x128/0x12C) with computed field
    //   (offset 0x038/0x03C) with lot type info
}

// ============================================================================
// HouseImpl::GetHouseStats(HouseStats &)
// Address: 0x800bc24c
// Size: 468 bytes (0x1D4)
// NON_MATCHING - complex iteration over object module, conditional counting
//
// Fills a HouseStats struct by iterating through all objects in the house,
// counting bedrooms, bathrooms, and computing square footage.
// ============================================================================
void HouseImpl::GetHouseStats(HouseStats& stats) {
    // Zero out stats struct
    stats.m_objectCount = 0;
    stats.m_squareFeet = 0;
    stats.m_unknown04 = 0;
    stats.m_numBedrooms = 0;
    stats.m_numBathrooms = 0;
    stats.m_lotSize = 0;
    stats.m_numLevels = 0;
    stats.m_unknown18 = 0;
    stats.m_unknown1C = 0;
    stats.m_unknown20 = 0;

    // Get object list from room manager (g_pRoomMgr)
    void* objList = g_pRoomMgr;
    void* first = *(void**)((char*)objList + 0x04);
    void* current = *(void**)((char*)first + 0x08);

    // Iterate all objects
    while (1) {
        void* listEnd = *(void**)((char*)objList + 0x04);
        int notDone = (current != listEnd) ? 1 : 0;
        if (!notDone) break;

        void* obj = *(void**)((char*)current + 0x14);
        if (obj != 0) {
            int value = *(int*)((char*)obj + 0x34);
            if (value != 0) {
                // Check if object counts as interior
                int isExterior = SpacePartition_GetTileCount(obj);
                if (isExterior == 0) {
                    int floorType = SpacePartition_GetFloorType(obj);
                    // Add tile value: value * 9 + floorType
                    int contribution = floorType * 9 + floorType;
                    stats.m_squareFeet += contribution;

                    // Check bedroom count (obj+0x70 > 0)
                    if (*(int*)((char*)obj + 0x70) > 0) {
                        stats.m_numBedrooms++;
                    }

                    // Check bathroom count (obj+0x6c > 0)
                    if (*(int*)((char*)obj + 0x6c) > 0) {
                        stats.m_numBathrooms++;
                    }
                }
            }
        }

        // Next object
        ObjectList_Next(current);
        current = 0; // stub - actual result from ObjectList_Next
    }

    // Get lot level count
    stats.m_numLevels = 1; // from g_pFixedWorld vtable dispatch

    // Compute lot size from world dimensions
    // Virtual dispatch on g_pFixedWorld (offset 0x30/0x34 and 0x38/0x3C)
    int xSize = 1, ySize = 1; // from vtable calls
    int area = xSize * ySize;

    // Classify lot size
    if (area <= 1599) {
        stats.m_lotSize = 0;
    } else if (area <= 2499) {
        stats.m_lotSize = 1;
    } else {
        stats.m_lotSize = 2;
    }

    // Store computed object count from g_pObjectModule vtable
    // Final virtual call on g_pObjectModule (offset 0x208/0x20C)
    // Get expense data from family
    // stats.m_unknown04 = family member count
}

// ============================================================================
// HouseStats::GetSizeScore(void)
// Address: 0x800bc45c
// Size: 352 bytes (0x160)
// NON_MATCHING - curve lookup with float division, binary search
//
// Computes lot size score by looking up the square footage on a score curve.
// Uses a piecewise linear curve with float interpolation.
// ============================================================================
int HouseStats::GetSizeScore(void) {
    int sqFt = m_unknown04;
    if (sqFt == 0) return 0;

    // Convert squareFeet and sqFt to float ratio
    // ratio = (float)(squareFeet ^ 0x80000000) / (float)(sqFt ^ 0x80000000)
    // This is the int-to-float conversion via xoris+stw+lfd+fsub trick

    // Get size score curve from g_pCursorGlob (r13-21424)
    // Virtual call (offset 0x78/0x7C) to get curve data
    void* curveData = 0; // from vtable call

    int numPoints = *(int*)((char*)curveData + 0x08);
    if (numPoints == 0) {
        return 0; // no curve data
    }

    // Binary search / linear scan through curve points
    // Each point is 8 bytes: float x, float y
    // Find the interval containing our ratio
    // Interpolate using curve coefficients

    return 0; // NON_MATCHING - complex float math
}

// ============================================================================
// HouseStats::GetFurnishingsScore(void)
// Address: 0x800bc5bc
// Size: 428 bytes (0x1AC)
// NON_MATCHING - curve lookup with float division
//
// Computes furnishings score similar to GetSizeScore but uses
// furnishings value and a different score curve.
// ============================================================================
int HouseStats::GetFurnishingsScore(void) {
    // Get family member count from g_pSimulator (r13-21496)
    // Virtual call (offset 0x120/0x124) to get family
    // Virtual call (offset 0x130/0x134) to get family size
    // Compute ratio: (float)furnishingsValue / (float)familySize

    // Get furnishings score curve from g_pCursorGlob
    // Virtual call (offset 0x80/0x84) to get curve

    // Same curve lookup as GetSizeScore:
    // Binary search through sorted x values
    // Piecewise linear interpolation
    // Convert result to int via fctiwz

    return 0; // NON_MATCHING - complex float math
}
