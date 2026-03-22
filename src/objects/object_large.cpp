// object_large.cpp - Large functions (257-1024 bytes) from object.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\object.obj
//
// 46 large functions decompiled from object.obj
//
// NON_MATCHING causes:
//   - GCC virtual dispatch (bctr vs blrl)
//   - GCC register allocation differences
//   - GCC loop codegen (bdnz vs cmpw/blt)
//   - SDA-relative addressing
//   - Division/modulo magic constant differences
//   - GCC destructor ABI

#include "types.h"

// Forward declarations
class cXObject;
class cXObjectImpl;
class cXMTObjectImpl;
class cXPortalImpl;
class cXPersonImpl;
class ObjSelector;
class ObjectModule;
class EdithVariableSet;
class ReconBuffer;
class ISimInstance;
struct FTilePt;
struct FTileRect;
struct CTilePt;
struct PlacementSpec;
struct HierarchySite;

// External functions
extern void* operator_new(unsigned int size);
extern void operator_delete(void* ptr);
extern void memcpy(void* dst, const void* src, unsigned int size);
extern void memmove(void* dst, const void* src, unsigned int size);
extern void memset(void* dst, int val, unsigned int size);

#if 0  // Reference decompilation - not compiled

// ============================================================================
// cXObject::~cXObject(void)
// Address: 0x800D9484 | Size: 360 bytes
// NON_MATCHING - GCC destructor ABI, cleanup chain
//
// Destructor cleans up all impl pointers. Calls virtual destructors on
// each impl through the vtable dispatch mechanism. Zeros out the impl
// pointer storage.
// ============================================================================
cXObject::~cXObject() {
    if (m_pImpls != 0) {
        // Destroy object impl
        if (m_pImpls->m_objectImpl != 0) {
            cXObjectImpl* impl = m_pImpls->m_objectImpl;
            int* vtbl = *(int**)impl;
            short offset = *(short*)((char*)vtbl + 0x24);
            void* fn = *(void**)((char*)vtbl + 0x28);
            ((void(*)(void*, int))fn)((char*)impl + offset, 1);
            m_pImpls->m_objectImpl = 0;
        }

        // Destroy person impl
        if (m_pImpls->m_personImpl != 0) {
            cXPersonImpl* impl = m_pImpls->m_personImpl;
            int* vtbl = *(int**)impl;
            short offset = *(short*)((char*)vtbl + 0x24);
            void* fn = *(void**)((char*)vtbl + 0x28);
            ((void(*)(void*, int))fn)((char*)impl + offset, 1);
            m_pImpls->m_personImpl = 0;
        }

        // Destroy MT object impl
        if (m_pImpls->m_mtObjectImpl != 0) {
            cXMTObjectImpl* impl = m_pImpls->m_mtObjectImpl;
            int* vtbl = *(int**)impl;
            short offset = *(short*)((char*)vtbl + 0x24);
            void* fn = *(void**)((char*)vtbl + 0x28);
            ((void(*)(void*, int))fn)((char*)impl + offset, 1);
            m_pImpls->m_mtObjectImpl = 0;
        }

        // Destroy portal impl
        if (m_pImpls->m_portalImpl != 0) {
            cXPortalImpl* impl = m_pImpls->m_portalImpl;
            int* vtbl = *(int**)impl;
            short offset = *(short*)((char*)vtbl + 0x24);
            void* fn = *(void**)((char*)vtbl + 0x28);
            ((void(*)(void*, int))fn)((char*)impl + offset, 1);
            m_pImpls->m_portalImpl = 0;
        }

        // Free impl storage
        operator_delete(m_pImpls);
        m_pImpls = 0;
    }
}

// ============================================================================
// EdithVariableSet::EdithVariableSet(EdithVariableSet &)
// Address: 0x800E32EC | Size: 264 bytes
// NON_MATCHING - GCC copy constructor codegen
//
// Copy constructor for EdithVariableSet. Deep copies the variable storage
// (vector of byte_key_maps). Allocates new storage and copies each map.
// ============================================================================
EdithVariableSet::EdithVariableSet(EdithVariableSet& other) {
    // Copy internal data
    memcpy(_data, other._data, 0x40);

    // Deep copy the variable maps vector
    // vector at _data+0x00 has [begin, end, capacity]
    void** srcBegin = *(void***)other._data;
    void** srcEnd = *(void***)((char*)other._data + 4);

    if (srcBegin != srcEnd) {
        int count = (int)(srcEnd - srcBegin);
        void** newMem = (void**)operator_new(count * sizeof(void*));

        for (int i = 0; i < count; i++) {
            if (srcBegin[i] != 0) {
                // Deep copy each byte_key_map
                newMem[i] = CopyByteKeyMap(srcBegin[i]);
            } else {
                newMem[i] = 0;
            }
        }

        *(void***)_data = newMem;
        *(void***)((char*)_data + 4) = newMem + count;
        *(void***)((char*)_data + 8) = newMem + count;
    }
}

// ============================================================================
// EdithVariableSet::Reset(void)
// Address: 0x800E7F64 | Size: 264 bytes
// NON_MATCHING - GCC register alloc, cleanup loop
//
// Resets all variable storage. Iterates through the byte_key_maps and
// clears each one, then resets the vector to empty.
// ============================================================================
void EdithVariableSet::Reset() {
    void** begin = *(void***)_data;
    void** end = *(void***)((char*)_data + 4);

    while (begin != end) {
        end--;
        if (*end != 0) {
            // Clear/destroy the byte_key_map
            DestroyByteKeyMap(*end);
            *end = 0;
        }
    }

    // Reset vector
    *(void***)((char*)_data + 4) = *(void***)_data;
}

// ============================================================================
// cXObjectImpl::HierSetSite(HierarchySite *)
// Address: 0x800DCFB8 | Size: 348 bytes
// NON_MATCHING - GCC register alloc, hierarchy manipulation
//
// Sets the hierarchy site for this object. Updates parent/child relationships.
// If the object was previously contained, severs the old relationship first.
// ============================================================================
void cXObjectImpl::HierSetSite(HierarchySite* site) {
    if (site == 0) return;

    // If currently in a hierarchy, sever first
    if (IsContained()) {
        HierSever();
    }

    // Set new location from site
    if (site->m_valid) {
        // Update location
        FTilePt tile;
        tile.x = site->m_tileX;
        tile.y = site->m_tileY;
        SetLocation(tile, site->m_level);

        // Set parent if specified
        if (site->m_parent != 0) {
            cXObjectImpl* parent = site->m_parent;
            int slot = site->m_slot;

            // Link into parent's hierarchy
            HierarchySite* parentSlots = *(HierarchySite**)((char*)parent + 0x90);
            if (parentSlots != 0 && slot >= 0) {
                int slotCount = ((int)(*(char**)((char*)parent + 0x94) -
                                      (char*)parentSlots)) / sizeof(HierarchySite);
                if (slot < slotCount) {
                    parentSlots[slot].m_parent = (cXObjectImpl*)this;
                    // Update our own back-reference
                    *(cXObjectImpl**)((char*)this + 0x90) = parent;
                }
            }
        }
    }
}

// ============================================================================
// cXObjectImpl::UpdateAge(void)
// Address: 0x800DBB18 | Size: 316 bytes
// NON_MATCHING - GCC register alloc, time calculation
//
// Updates the object's age. Calculates elapsed time since creation and
// updates age-related state. May trigger aging events for sims.
// ============================================================================
void cXObjectImpl::UpdateAge() {
    // Get current game time
    void* timeModule = GetTimeModule();
    if (timeModule == 0) return;

    int currentTime = GetGameTime(timeModule);

    // Get creation time from object data
    int creationTime = GetData(0x10);  // Data index for creation time

    if (creationTime <= 0) return;

    int age = currentTime - creationTime;
    if (age < 0) age = 0;

    // Store age
    SetData(0x11, (short)(age & 0xFFFF));

    // Check for age milestones
    int ageInDays = age / (24 * 60);  // Convert from minutes to days
    int oldAgeInDays = GetData(0x12);

    if (ageInDays > oldAgeInDays) {
        SetData(0x12, (short)ageInDays);
        // Trigger day-passed event
        DayPassed();
    }
}

// ============================================================================
// cXObjectImpl::JustBorn(void)
// Address: 0x800DAC94 | Size: 296 bytes
// NON_MATCHING - GCC register alloc, initialization chain
//
// Called when an object is first created. Initializes default state,
// sets creation timestamp, and triggers any birth events. Sets initial
// attribute values from the object definition.
// ============================================================================
void cXObjectImpl::JustBorn() {
    // Get current game time
    void* timeModule = GetTimeModule();
    int currentTime = 0;
    if (timeModule != 0) {
        currentTime = GetGameTime(timeModule);
    }

    // Store creation time
    SetData(0x10, (short)(currentTime & 0xFFFF));
    SetData(0x11, 0);  // Age = 0
    SetData(0x12, 0);  // Days = 0

    // Initialize attributes from definition
    void* def = *(void**)((char*)this + 0x88);
    if (def != 0) {
        // Copy default attribute values
        int numAttr = *(int*)((char*)def + 0x20);
        short* defaultAttrs = (short*)((char*)def + 0x24);

        for (int i = 0; i < numAttr && i < *(int*)((char*)this + 0x0C); i++) {
            *(short*)((char*)this + 0x08 + i * 2) = defaultAttrs[i];
        }
    }

    // Clear misc flags
    *(int*)((char*)this + 0x84) = 0;

    // Run init tree if available
    short initTreeID = GetTreeID(0);  // ObjEntryPoint 0 = init
    if (initTreeID >= 0) {
        short result = 0;
        RunTree(0, initTreeID, &result);
    }
}

// ============================================================================
// cXObjectImpl::PostLoad(int, bool)
// Address: 0x800DADBC | Size: 940 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch chain
//
// Called after an object is loaded from save data. Reconnects pointers,
// validates state, and runs post-load initialization. This is a large
// function that handles many edge cases for different object types.
// ============================================================================
void cXObjectImpl::PostLoad(int version, bool isNew) {
    // Validate definition pointer
    void* def = *(void**)((char*)this + 0x88);
    if (def == 0) {
        // Try to find definition by ID
        short id = *(short*)((char*)this + 0x64);
        def = FindObjDefByID(id);
        if (def != 0) {
            *(void**)((char*)this + 0x88) = def;
        }
    }

    // Reconnect module pointer
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    if (module == 0) {
        // Get default module
        module = GetDefaultObjectModule();
        *(ObjectModule**)((char*)this + 0x58) = module;
    }

    // Validate attribute array
    int numAttr = *(int*)((char*)this + 0x0C);
    short* attrArray = *(short**)((char*)this + 0x08);
    if (numAttr > 0 && attrArray == 0) {
        // Allocate attribute array
        attrArray = (short*)operator_new(numAttr * sizeof(short));
        memset(attrArray, 0, numAttr * sizeof(short));
        *(short**)((char*)this + 0x08) = attrArray;
    }

    // Reconstruct hierarchy
    HierarchySite* hierSlots = *(HierarchySite**)((char*)this + 0x90);
    HierarchySite* hierSlotsEnd = *(HierarchySite**)((char*)this + 0x94);
    if (hierSlots != 0 && hierSlots != hierSlotsEnd) {
        int slotCount = (int)(hierSlotsEnd - hierSlots) / sizeof(HierarchySite);
        for (int i = 0; i < slotCount; i++) {
            if (hierSlots[i].m_parent != 0) {
                // Validate parent pointer
                cXObjectImpl* parent = hierSlots[i].m_parent;
                if (!ValidateObjectPtr(parent)) {
                    hierSlots[i].m_parent = 0;
                    hierSlots[i].m_valid = 0;
                }
            }
        }
    }

    // Clear sync state
    *(s8*)((char*)this + 0xDC) = 0;
    *(int*)((char*)this + 0xE4) = 0;

    // Clear graphics tag
    *(int*)((char*)this + 0xE8) = 0;

    // Update location if in world
    if (IsInWorld()) {
        FTilePt tile;
        tile.x = *(s32*)((char*)this + 0x68);
        tile.y = *(s32*)((char*)this + 0x6C);
        int level = *(int*)((char*)this + 0x80);

        // Recompute rect
        FTileRect rect;
        ComputeRect(tile, &rect);

        // Update wall adjacency if needed
        void* objDef = *(void**)((char*)this + 0x88);
        if (objDef != 0) {
            int flags = *(int*)((char*)objDef + 0x18);
            if (flags & 0x100) {
                // Requires wall adjacency
                UpdateWallAdjacency();
            }
        }
    }

    // Run post-load tree if available (and not a fresh object)
    if (!isNew) {
        short postLoadTreeID = GetTreeID(3);  // ObjEntryPoint 3 = post-load
        if (postLoadTreeID >= 0) {
            short result = 0;
            RunTree(3, postLoadTreeID, &result);
        }
    }
}

// ============================================================================
// cXObjectImpl::SetHilite(int)
// Address: 0x800DB5D0 | Size: 372 bytes
// NON_MATCHING - GCC register alloc, virtual dispatch
//
// Sets the highlight state for this object. Updates the visual rendering
// to show selection/hover effects. May also update sub-objects in a
// multi-tile object.
// ============================================================================
void cXObjectImpl::SetHilite(int value) {
    // Store hilite value
    int oldHilite = GetHilite();
    // Access through vtable for draw label setup
    int* vtbl = *(int**)this;

    // Set draw label based on hilite
    if (value != 0 && oldHilite == 0) {
        SetDrawLabel(true);
    } else if (value == 0 && oldHilite != 0) {
        SetDrawLabel(false);
    }

    // Store in object's hilite field
    // Hilite is stored in the data array at a specific index
    void* def = *(void**)((char*)this + 0x88);
    if (def != 0) {
        // Get the ISimsObjectModel for visual update
        void* simObj = GetSim();
        if (simObj != 0) {
            // Update visual hilite via ISimsObjectModel
            int* somVtbl = *(int**)simObj;
            short offset = *(short*)((char*)somVtbl + 0x1B8);
            void* fn = *(void**)((char*)somVtbl + 0x1BC);
            ((void(*)(void*, int))fn)((char*)simObj + offset, value);
        }
    }

    // Update multi-tile sub-objects if applicable
    if (IsMultiTile()) {
        cXObjectImpl* next = GetNextImpl();
        while (next != 0) {
            if (next->IsPartOfMe((cXObject*)this)) {
                // Recursively set hilite on sub-objects
                next->SetHilite(value);
            }
            next = next->GetNextImpl();
        }
    }
}

// ============================================================================
// cXObjectImpl::GetCurrentValue(void)
// Address: 0x800DB744 | Size: 528 bytes
// NON_MATCHING - GCC register alloc, value calculation
//
// Calculates the current monetary value of this object. Takes base value
// from definition, applies depreciation based on age and condition,
// and accounts for any upgrades or modifications.
// ============================================================================
void cXObjectImpl::GetCurrentValue() {
    void* def = *(void**)((char*)this + 0x88);
    if (def == 0) return;

    int baseValue = *(int*)((char*)def + 0x30);  // Base price
    if (baseValue <= 0) return;

    // Get age depreciation
    int ageMinutes = 0;
    GetAgeInMinutes();  // Sets ageMinutes internally

    // Calculate depreciation rate
    float depRate = 0.0f;
    int objType = GetType();

    // Different depreciation for different object types
    if (objType == 1) {
        // Appliances depreciate faster
        depRate = 0.002f;
    } else if (objType == 2) {
        // Furniture depreciates slower
        depRate = 0.001f;
    } else {
        depRate = 0.0015f;
    }

    float depreciation = (float)ageMinutes * depRate;
    if (depreciation > 0.8f) depreciation = 0.8f;  // Cap at 80%

    int currentValue = (int)((float)baseValue * (1.0f - depreciation));

    // Check condition modifiers
    if (IsBroken()) {
        currentValue = currentValue / 2;
    }
    if (IsDirty()) {
        currentValue = (int)((float)currentValue * 0.9f);
    }

    // Minimum value is 10% of base
    int minValue = baseValue / 10;
    if (currentValue < minValue) currentValue = minValue;

    // Store result
    SetTemp(0, (short)currentValue);
}

// ============================================================================
// cXObjectImpl::DayPassed(void)
// Address: 0x800DB9A8 | Size: 368 bytes
// NON_MATCHING - GCC register alloc, event dispatch
//
// Called when a game day passes for this object. Handles daily maintenance
// like decay, wear, and scheduled events. May trigger needs decay for
// plumbing/appliance objects.
// ============================================================================
void cXObjectImpl::DayPassed() {
    // Run day-passed tree if available
    short dayTreeID = GetTreeID(4);  // ObjEntryPoint 4 = day passed
    if (dayTreeID >= 0) {
        short result = 0;
        RunTree(4, dayTreeID, &result);
    }

    // Apply daily wear
    void* def = *(void**)((char*)this + 0x88);
    if (def != 0) {
        int durability = *(int*)((char*)def + 0x34);
        if (durability > 0) {
            // Decrease remaining durability
            short currentDurability = GetAttr(5);  // Attr 5 = durability
            if (currentDurability > 0) {
                currentDurability--;
                SetAttr(5, currentDurability);

                // Check if broken
                if (currentDurability <= 0) {
                    SetMiscFlag(0x04, true);  // Mark as broken
                }
            }
        }
    }

    // Update age
    UpdateAge();
}

// ============================================================================
// cXObjectImpl::GetPlacementSpec(PlacementSpec *)
// Address: 0x800DCB78 | Size: 468 bytes
// NON_MATCHING - GCC register alloc, struct copy
//
// Fills a PlacementSpec with this object's current placement information.
// Gets tile position, level, parent container, and slot from internal state.
// ============================================================================
void cXObjectImpl::GetPlacementSpec(PlacementSpec* spec) {
    if (spec == 0) return;

    if (!IsInWorld()) {
        spec->m_valid = 0;
        return;
    }

    spec->m_valid = 1;
    spec->m_tileX = *(s32*)((char*)this + 0x68);
    spec->m_tileY = *(s32*)((char*)this + 0x6C);
    spec->m_level = *(int*)((char*)this + 0x80);

    // Check if contained
    if (IsContained()) {
        // Get container info
        HierarchySite* hierSlots = *(HierarchySite**)((char*)this + 0x90);
        if (hierSlots != 0) {
            spec->m_parent = hierSlots[0].m_parent;
            spec->m_slot = hierSlots[0].m_slot;
        } else {
            spec->m_parent = 0;
            spec->m_slot = -1;
        }
    } else {
        spec->m_parent = 0;
        spec->m_slot = -1;
    }
}

// ============================================================================
// cXObjectImpl::HierGetSite(HierarchySite *)
// Address: 0x800DD15C | Size: 268 bytes
// NON_MATCHING - GCC register alloc, struct copy
//
// Gets the hierarchy site for this object (where it is in the containment
// hierarchy). Fills the output HierarchySite with the current position data.
// ============================================================================
void cXObjectImpl::HierGetSite(HierarchySite* site) {
    if (site == 0) return;

    if (!IsContained()) {
        site->m_valid = IsInWorld() ? 1 : 0;
        site->m_tileX = *(s32*)((char*)this + 0x68);
        site->m_tileY = *(s32*)((char*)this + 0x6C);
        site->m_parent = 0;
        site->m_slot = -1;
        site->m_level = *(int*)((char*)this + 0x80);
    } else {
        HierarchySite* hierSlots = *(HierarchySite**)((char*)this + 0x90);
        if (hierSlots != 0) {
            *site = hierSlots[0];
        } else {
            site->m_valid = 0;
        }
    }
}

// ============================================================================
// cXObjectImpl::ExtractContainedSims(void)
// Address: 0x800DD5E4 | Size: 260 bytes
// NON_MATCHING - GCC register alloc, hierarchy traversal
//
// Extracts any sims contained within this object (e.g., sitting in a chair).
// Iterates through containment slots and removes any person objects.
// ============================================================================
void cXObjectImpl::ExtractContainedSims() {
    int slotCount = HierCountSlots();
    for (int i = 0; i < slotCount; i++) {
        HierarchySite* slot = HierGetSlot(i);
        if (slot == 0) continue;
        if (slot->m_parent == 0) continue;

        cXObjectImpl* contained = slot->m_parent;
        // Check if it's a person
        if (contained->IsPerson()) {
            // Extract the sim
            contained->HierSever();
            // Place sim at this object's location
            FTilePt tile;
            tile.x = *(s32*)((char*)this + 0x68);
            tile.y = *(s32*)((char*)this + 0x6C);
            int level = *(int*)((char*)this + 0x80);
            contained->ForceLocation();
        }
    }
}

// ============================================================================
// cXObjectImpl::Pickup(void)
// Address: 0x800DE144 | Size: 508 bytes
// NON_MATCHING - GCC register alloc, state cleanup
//
// Picks up this object from the world. Removes it from the tile grid,
// severs hierarchy, extracts contained sims, and resets placement state.
// ============================================================================
void cXObjectImpl::Pickup() {
    if (!IsInWorld()) return;

    // Extract any contained sims first
    ExtractContainedSims();

    // Sever hierarchy
    if (IsContained()) {
        HierSever();
    }

    // Remove from tile grid
    void* module = *(void**)((char*)this + 0x58);
    if (module != 0) {
        // Virtual call to remove from grid
        int* vtbl = *(int**)module;
        short offset = *(short*)((char*)vtbl + 0x40);
        void* fn = *(void**)((char*)vtbl + 0x44);
        ((void(*)(void*, cXObjectImpl*))fn)((char*)module + offset, this);
    }

    // Clear location
    *(s32*)((char*)this + 0x68) = 0;
    *(s32*)((char*)this + 0x6C) = 0;
    *(int*)((char*)this + 0x80) = 0;

    // Clear rect
    memset((char*)this + 0x70, 0, 16);

    // Remove visual model from house
    void* simObj = GetSim();
    if (simObj != 0) {
        int* somVtbl = *(int**)simObj;
        // SetOutOfWorld
        short offset = *(short*)((char*)somVtbl + 0x120);
        void* fn = *(void**)((char*)somVtbl + 0x124);
        ((void(*)(void*))fn)((char*)simObj + offset);
    }

    // Run pickup tree
    short pickupTreeID = GetTreeID(5);
    if (pickupTreeID >= 0) {
        short result = 0;
        RunTree(5, pickupTreeID, &result);
    }
}

// ============================================================================
// cXObjectImpl::Place(FTilePt &, int, cXObject *, int)
// Address: 0x800DE3C4 | Size: 956 bytes
// NON_MATCHING - GCC register alloc, placement validation
//
// Places this object at the specified tile position and level. Handles
// containment (placing into a slot on another object), wall adjacency,
// and multi-tile placement. Updates the visual model position.
// ============================================================================
void cXObjectImpl::Place(FTilePt& tile, int level, cXObject* parent, int slot) {
    // Validate placement
    if (parent != 0 && slot >= 0) {
        // Placing into a container slot
        cXObjectImpl* parentImpl = parent->CAST_IMPL();
        if (parentImpl == 0) return;

        // Check slot is valid
        int slotCount = parentImpl->HierCountSlots();
        if (slot >= slotCount) return;

        // Set up hierarchy
        HierarchySite site;
        site.m_valid = 1;
        site.m_tileX = tile.x;
        site.m_tileY = tile.y;
        site.m_parent = parentImpl;
        site.m_slot = slot;
        site.m_level = level;

        HierSetSite(&site);
    } else {
        // Placing on the ground
        SetLocation(tile, level);
    }

    // Compute bounding rect
    FTileRect rect;
    ComputeRect(tile, &rect);

    // Add to tile grid
    void* module = *(void**)((char*)this + 0x58);
    if (module != 0) {
        int* vtbl = *(int**)module;
        short offset = *(short*)((char*)vtbl + 0x38);
        void* fn = *(void**)((char*)vtbl + 0x3C);
        ((void(*)(void*, cXObjectImpl*))fn)((char*)module + offset, this);
    }

    // Update visual model
    void* simObj = GetSim();
    if (simObj != 0) {
        // Create/position the model in the house
        int* somVtbl = *(int**)simObj;

        // Get position from tile
        float posX = (float)tile.x * 16.0f + 8.0f;
        float posZ = (float)tile.y * 16.0f + 8.0f;
        float posY = (float)level * 64.0f;

        // Set position
        // EVec3 pos = {posX, posY, posZ}
        float pos[3] = {posX, posY, posZ};
        short offset = *(short*)((char*)somVtbl + 0x130);
        void* fn = *(void**)((char*)somVtbl + 0x134);
        ((void(*)(void*, float*))fn)((char*)simObj + offset, pos);
    }

    // Update wall adjacency if needed
    void* objDef = *(void**)((char*)this + 0x88);
    if (objDef != 0) {
        int flags = *(int*)((char*)objDef + 0x18);
        if (flags & 0x100) {
            UpdateWallAdjacency();
        }
    }

    // Update chair facing
    if (IsChair()) {
        UpdateChairFacing();
    }

    // Run placement tree
    short placeTreeID = GetTreeID(6);
    if (placeTreeID >= 0) {
        short result = 0;
        RunTree(6, placeTreeID, &result);
    }

    // Notify sim object placed
    void* sim = GetSim();
    if (sim != 0) {
        SimObjectPlaced(0);
    }
}

// ============================================================================
// cXObjectImpl::UpdateWallAdjacency(void)
// Address: 0x800E1594 | Size: 496 bytes
// NON_MATCHING - GCC register alloc, wall scanning
//
// Updates the wall adjacency state for this object. Scans adjacent tiles
// for walls and sets the appropriate facing/snapping based on wall position.
// ============================================================================
void cXObjectImpl::UpdateWallAdjacency() {
    if (!IsInWorld()) return;

    FTilePt tile;
    tile.x = *(s32*)((char*)this + 0x68);
    tile.y = *(s32*)((char*)this + 0x6C);
    int level = *(int*)((char*)this + 0x80);

    // Check 4 adjacent tiles for walls
    int wallFlags = 0;

    // Check north
    CTilePt checkTile;
    checkTile.x = tile.x;
    checkTile.y = tile.y - 1;
    int flags = GetWallBlockFlags(checkTile, level);
    if (flags & 0x02) wallFlags |= 0x01;  // Wall to north

    // Check south
    checkTile.y = tile.y + 1;
    flags = GetWallBlockFlags(checkTile, level);
    if (flags & 0x01) wallFlags |= 0x02;  // Wall to south

    // Check east
    checkTile.x = tile.x + 1;
    checkTile.y = tile.y;
    flags = GetWallBlockFlags(checkTile, level);
    if (flags & 0x08) wallFlags |= 0x04;  // Wall to east

    // Check west
    checkTile.x = tile.x - 1;
    flags = GetWallBlockFlags(checkTile, level);
    if (flags & 0x04) wallFlags |= 0x08;  // Wall to west

    // Store wall adjacency flags
    int miscFlags = *(int*)((char*)this + 0x84);
    miscFlags = (miscFlags & ~0xF0) | ((wallFlags & 0x0F) << 4);
    *(int*)((char*)this + 0x84) = miscFlags;
}

// ============================================================================
// cXObjectImpl::SimObjectPlaced(ISimInstance *)
// Address: 0x800EA6B0 | Size: 356 bytes
// NON_MATCHING - GCC register alloc, notification dispatch
//
// Called when a sim's object is placed. Notifies the sim instance that
// its physical object has been placed, allowing it to update routing
// and animation state.
// ============================================================================
void cXObjectImpl::SimObjectPlaced(ISimInstance* instance) {
    void* simObj = GetSim();
    if (simObj == 0) return;

    // Notify the visual model
    int* vtbl = *(int**)simObj;
    short offset = *(short*)((char*)vtbl + 0x1A0);
    void* fn = *(void**)((char*)vtbl + 0x1A4);
    ((void(*)(void*))fn)((char*)simObj + offset);

    // Update lighting
    offset = *(short*)((char*)vtbl + 0x1B0);
    fn = *(void**)((char*)vtbl + 0x1B4);
    ((void(*)(void*))fn)((char*)simObj + offset);

    // If multi-tile, update sub-objects
    if (IsMultiTile()) {
        cXObjectImpl* next = GetNextImpl();
        while (next != 0) {
            if (next->IsPartOfMe((cXObject*)this)) {
                void* nextSim = next->GetSim();
                if (nextSim != 0) {
                    int* nextVtbl = *(int**)nextSim;
                    short off = *(short*)((char*)nextVtbl + 0x1A0);
                    void* f = *(void**)((char*)nextVtbl + 0x1A4);
                    ((void(*)(void*))f)((char*)nextSim + off);
                }
            }
            next = next->GetNextImpl();
        }
    }
}

// ============================================================================
// cXObjectImpl::UpdateChairFacing(void)
// Address: 0x800DE788 | Size: 860 bytes
// NON_MATCHING - GCC register alloc, facing calculation
//
// Updates the facing direction for chair-type objects. Scans for nearby
// tables and social objects to determine optimal facing direction.
// Complex function with distance calculations and priority scoring.
// ============================================================================
void cXObjectImpl::UpdateChairFacing() {
    if (!IsChair()) return;
    if (!IsInWorld()) return;

    FTilePt myTile;
    myTile.x = *(s32*)((char*)this + 0x68);
    myTile.y = *(s32*)((char*)this + 0x6C);
    int myLevel = *(int*)((char*)this + 0x80);

    // Scan for nearby objects to face towards
    int bestDir = -1;
    int bestScore = 0;

    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    if (module == 0) return;

    // Get object iterator
    cXObject* first = GetFirst();
    cXObjectImpl* iter = 0;
    if (first != 0) {
        iter = first->CAST_IMPL();
    }

    while (iter != 0) {
        if (iter == (cXObjectImpl*)this) {
            iter = iter->GetNextImpl();
            continue;
        }

        if (!iter->IsInWorld()) {
            iter = iter->GetNextImpl();
            continue;
        }

        // Check if this is a table or focal point
        int otherType = iter->GetBuildModeType();
        if (otherType != 2 && otherType != 5) {  // 2=table, 5=social object
            iter = iter->GetNextImpl();
            continue;
        }

        // Calculate distance
        FTilePt otherTile;
        otherTile.x = *(s32*)((char*)iter + 0x68);
        otherTile.y = *(s32*)((char*)iter + 0x6C);

        int dx = otherTile.x - myTile.x;
        int dy = otherTile.y - myTile.y;
        int dist = dx * dx + dy * dy;

        if (dist > 16) {  // Too far
            iter = iter->GetNextImpl();
            continue;
        }

        // Score this direction
        int score = (otherType == 2) ? 100 : 50;  // Tables score higher
        score -= dist;

        if (score > bestScore) {
            bestScore = score;
            // Calculate direction from delta
            if (dx > 0 && dy == 0) bestDir = 0;      // East
            else if (dx == 0 && dy > 0) bestDir = 1;  // South
            else if (dx < 0 && dy == 0) bestDir = 2;  // West
            else if (dx == 0 && dy < 0) bestDir = 3;  // North
            else bestDir = -1;  // Diagonal - skip
        }

        iter = iter->GetNextImpl();
    }

    if (bestDir >= 0) {
        // Set facing
        Turn(bestDir);
    }
}

// ============================================================================
// ResolveRoomID(FTilePt &, int)
// Address: 0x800DF228 | Size: 680 bytes
// NON_MATCHING - GCC register alloc, room lookup
//
// Resolves the room ID for a given tile position and level. Walks the
// room data structure to find which room contains the specified tile.
// ============================================================================
int ResolveRoomID(FTilePt& tile, int level) {
    // Get house/lot manager
    void* house = GetCurrentHouse();
    if (house == 0) return -1;

    // Get room data for this level
    void* roomData = GetRoomDataForLevel(house, level);
    if (roomData == 0) return -1;

    // Look up tile in room grid
    int gridWidth = *(int*)((char*)roomData + 0x00);
    int gridHeight = *(int*)((char*)roomData + 0x04);

    if (tile.x < 0 || tile.x >= gridWidth || tile.y < 0 || tile.y >= gridHeight) {
        return 0;  // Outside = room 0 (outdoor)
    }

    // Room grid is a 2D array of room IDs
    short* grid = *(short**)((char*)roomData + 0x08);
    int roomID = (int)grid[tile.y * gridWidth + tile.x];

    return roomID;
}

// ============================================================================
// cXObjectImpl::ComputeRect(FTilePt &, FTileRect *)
// Address: 0x800DF4D0 | Size: 692 bytes
// NON_MATCHING - GCC register alloc, rect calculation
//
// Computes the bounding rectangle of this object at the given tile position.
// Accounts for object dimensions, rotation, and multi-tile size.
// ============================================================================
void cXObjectImpl::ComputeRect(FTilePt& tile, FTileRect* outRect) {
    if (outRect == 0) return;

    void* def = *(void**)((char*)this + 0x88);
    if (def == 0) {
        outRect->x = tile.x;
        outRect->y = tile.y;
        *(int*)((char*)outRect + 8) = tile.x;
        *(int*)((char*)outRect + 12) = tile.y;
        return;
    }

    // Get tile dimensions
    int width = 1;
    int height = 1;
    GetNumTiles(width, height);

    // Get current direction
    int dir = GetFrontFaceDirection();

    // Apply rotation to dimensions
    if (dir == 1 || dir == 3) {
        // 90 or 270 degrees - swap width and height
        int temp = width;
        width = height;
        height = temp;
    }

    // Compute rect
    outRect->x = tile.x;
    outRect->y = tile.y;
    *(int*)((char*)outRect + 8) = tile.x + width - 1;
    *(int*)((char*)outRect + 12) = tile.y + height - 1;

    // Store in internal rect
    memcpy((char*)this + 0x70, outRect, 16);
}

// ============================================================================
// cXObjectImpl::SetLocation(FTilePt &, int)
// Address: 0x800DF784 | Size: 792 bytes
// NON_MATCHING - GCC register alloc, grid update
//
// Sets the object's tile location and level. Updates the tile grid,
// room assignment, and visual model position. Handles multi-tile objects
// by updating all component tiles.
// ============================================================================
void cXObjectImpl::SetLocation(FTilePt& tile, int level) {
    // Store position
    *(s32*)((char*)this + 0x68) = tile.x;
    *(s32*)((char*)this + 0x6C) = tile.y;
    *(int*)((char*)this + 0x80) = level;

    // Compute bounding rect
    FTileRect rect;
    ComputeRect(tile, &rect);

    // Update room assignment
    int roomID = ResolveRoomID(tile, level);
    // Store room (may be at a data index)
    SetData(0x0E, (short)roomID);  // Data index for room

    // Update visual model position
    void* simObj = GetSim();
    if (simObj != 0) {
        // Calculate world position from tile
        float posX = (float)tile.x * 16.0f + 8.0f;
        float posZ = (float)tile.y * 16.0f + 8.0f;
        float posY = (float)level * 64.0f;

        float pos[3] = {posX, posY, posZ};

        int* vtbl = *(int**)simObj;
        short offset = *(short*)((char*)vtbl + 0x130);
        void* fn = *(void**)((char*)vtbl + 0x134);
        ((void(*)(void*, float*))fn)((char*)simObj + offset, pos);

        // Set orientation
        offset = *(short*)((char*)vtbl + 0x1C0);
        fn = *(void**)((char*)vtbl + 0x1C4);
        ((void(*)(void*))fn)((char*)simObj + offset);
    }
}

// ============================================================================
// cXObjectImpl::Turn(int)
// Address: 0x800DFA9C | Size: 352 bytes
// NON_MATCHING - GCC register alloc, direction table
//
// Turns the object to face the specified direction (0-3).
// Updates the facing in data storage and recomputes bounding rect.
// Uses sXDirTable for direction-to-angle conversion.
// ============================================================================
void cXObjectImpl::Turn(int direction) {
    // Normalize direction to 0-3
    direction = direction & 3;

    // Store direction
    int prevDir = GetFrontFaceDirection();
    if (prevDir == direction) return;

    // Update direction in data
    int miscFlags = *(int*)((char*)this + 0x84);
    miscFlags = (miscFlags & ~0x03) | (direction & 0x03);
    *(int*)((char*)this + 0x84) = miscFlags;

    // Recompute rect
    FTilePt tile;
    tile.x = *(s32*)((char*)this + 0x68);
    tile.y = *(s32*)((char*)this + 0x6C);
    FTileRect rect;
    ComputeRect(tile, &rect);

    // Update visual rotation
    void* simObj = GetSim();
    if (simObj != 0) {
        int* vtbl = *(int**)simObj;
        // Use direction table for angle
        float angle = (float)sXDirTable[direction] * 3.14159265f / 2.0f;

        short offset = *(short*)((char*)vtbl + 0x140);
        void* fn = *(void**)((char*)vtbl + 0x144);
        ((void(*)(void*, float))fn)((char*)simObj + offset, angle);
    }
}

// ============================================================================
// cXObjectImpl::CalcShortDistanceIn16thsOfTiles(cXObject *)
// Address: 0x800DFEE0 | Size: 416 bytes
// NON_MATCHING - GCC register alloc, distance calc
//
// Calculates the short distance to another object in 16ths of tiles.
// Uses Manhattan distance on tile positions.
// ============================================================================
void cXObjectImpl::CalcShortDistanceIn16thsOfTiles(cXObject* other) {
    if (other == 0) {
        SetTemp(0, 0x7FFF);
        return;
    }

    cXObjectImpl* otherImpl = other->CAST_IMPL();
    if (otherImpl == 0 || !otherImpl->IsInWorld() || !IsInWorld()) {
        SetTemp(0, 0x7FFF);
        return;
    }

    // Get positions
    s32 myX = *(s32*)((char*)this + 0x68);
    s32 myY = *(s32*)((char*)this + 0x6C);
    s32 otherX = *(s32*)((char*)otherImpl + 0x68);
    s32 otherY = *(s32*)((char*)otherImpl + 0x6C);

    // Manhattan distance in 16ths of tiles
    int dx = myX - otherX;
    if (dx < 0) dx = -dx;
    int dy = myY - otherY;
    if (dy < 0) dy = -dy;

    int dist = (dx + dy) * 16;

    // Clamp to short range
    if (dist > 0x7FFF) dist = 0x7FFF;

    SetTemp(0, (short)dist);
}

// ============================================================================
// cXObjectImpl::CalcDistanceWithPentalties(cXObject *)
// Address: 0x800E0080 | Size: 808 bytes
// NON_MATCHING - GCC register alloc, penalty calculations
//
// Calculates distance to another object with penalties for walls, stairs,
// and other obstacles. Used for routing/pathfinding cost estimation.
// ============================================================================
void cXObjectImpl::CalcDistanceWithPentalties(cXObject* other) {
    if (other == 0) {
        SetTemp(0, 0x7FFF);
        return;
    }

    cXObjectImpl* otherImpl = other->CAST_IMPL();
    if (otherImpl == 0 || !otherImpl->IsInWorld() || !IsInWorld()) {
        SetTemp(0, 0x7FFF);
        return;
    }

    s32 myX = *(s32*)((char*)this + 0x68);
    s32 myY = *(s32*)((char*)this + 0x6C);
    int myLevel = *(int*)((char*)this + 0x80);

    s32 otherX = *(s32*)((char*)otherImpl + 0x68);
    s32 otherY = *(s32*)((char*)otherImpl + 0x6C);
    int otherLevel = *(int*)((char*)otherImpl + 0x80);

    // Base distance
    int dx = myX - otherX;
    if (dx < 0) dx = -dx;
    int dy = myY - otherY;
    if (dy < 0) dy = -dy;

    int baseDist = dx + dy;

    // Level penalty
    int levelDiff = myLevel - otherLevel;
    if (levelDiff < 0) levelDiff = -levelDiff;
    int levelPenalty = levelDiff * 100;  // 100 tiles per level change

    // Room penalty (different rooms add cost)
    int myRoom = GetRoom();
    int otherRoom = otherImpl->GetRoom();
    int roomPenalty = (myRoom != otherRoom) ? 20 : 0;

    // Wall penalty (check line of sight)
    int wallPenalty = 0;
    // Simplified wall check
    FTilePt checkTile;
    checkTile.x = myX;
    checkTile.y = myY;
    int wallCount = CountWallsBetween(checkTile, myLevel, otherX, otherY);
    wallPenalty = wallCount * 30;

    int totalDist = baseDist + levelPenalty + roomPenalty + wallPenalty;
    if (totalDist > 0x7FFF) totalDist = 0x7FFF;

    SetTemp(0, (short)totalDist);
}

// ============================================================================
// EdithVariableSet::ReconOldFdata(ReconBuffer *, unsigned int)
// Address: 0x800E7D30 | Size: 564 bytes
// NON_MATCHING - GCC register alloc, legacy format parsing
//
// Reads variable data from an old (legacy) format ReconBuffer. Handles
// format version differences for backwards compatibility with older
// save files.
// ============================================================================
void EdithVariableSet::ReconOldFdata(ReconBuffer* buffer, unsigned int version) {
    if (buffer == 0) return;

    // Clear existing data
    Reset();

    if (version == 0) {
        // Oldest format - flat array of shorts
        int count = 0;
        ReconBuffer_StreamInt(buffer, &count);

        for (int i = 0; i < count; i++) {
            unsigned char key = 0;
            short value = 0;
            ReconBuffer_StreamByte(buffer, &key);
            ReconBuffer_StreamShort(buffer, &value);
            WriteVar((int)key, value);
        }
    } else if (version == 1) {
        // Version 1 - categorized variables
        int categoryCount = 0;
        ReconBuffer_StreamInt(buffer, &categoryCount);

        for (int cat = 0; cat < categoryCount; cat++) {
            int varCount = 0;
            ReconBuffer_StreamInt(buffer, &varCount);

            for (int i = 0; i < varCount; i++) {
                unsigned char key = 0;
                short value = 0;
                ReconBuffer_StreamByte(buffer, &key);
                ReconBuffer_StreamShort(buffer, &value);
                int fullKey = (cat << 8) | (int)key;
                WriteVar(fullKey, value);
            }
        }
    }
}

// ============================================================================
// cXObjectImpl::ReconSlots(ReconBuffer *, int)
// Address: 0x800E0BA8 | Size: 908 bytes
// NON_MATCHING - GCC register alloc, slot serialization
//
// Serializes/deserializes the object's slot data (hierarchy, routing,
// containment). Large function that handles multiple slot types and
// their associated data.
// ============================================================================
void cXObjectImpl::ReconSlots(ReconBuffer* buffer, int direction) {
    if (buffer == 0) return;

    // Stream hierarchy slot count
    int hierCount = 0;
    HierarchySite* hierSlots = *(HierarchySite**)((char*)this + 0x90);
    HierarchySite* hierSlotsEnd = *(HierarchySite**)((char*)this + 0x94);

    if (direction == 1) {
        // Writing
        if (hierSlots != 0 && hierSlotsEnd != 0) {
            hierCount = (int)(hierSlotsEnd - hierSlots);
        }
    }

    ReconBuffer_StreamInt(buffer, &hierCount);

    if (direction == 0) {
        // Reading - allocate hierarchy slots
        if (hierSlots != 0) {
            operator_delete(hierSlots);
        }

        if (hierCount > 0) {
            hierSlots = (HierarchySite*)operator_new(hierCount * sizeof(HierarchySite));
            *(HierarchySite**)((char*)this + 0x90) = hierSlots;
            *(HierarchySite**)((char*)this + 0x94) = hierSlots + hierCount;
        } else {
            *(HierarchySite**)((char*)this + 0x90) = 0;
            *(HierarchySite**)((char*)this + 0x94) = 0;
        }
    }

    // Stream each hierarchy slot
    for (int i = 0; i < hierCount; i++) {
        HierarchySite* slot = &hierSlots[i];
        ReconBuffer_StreamInt(buffer, &slot->m_valid);
        ReconBuffer_StreamInt(buffer, &slot->m_tileX);
        ReconBuffer_StreamInt(buffer, &slot->m_tileY);

        // Stream parent as object ID
        short parentID = 0;
        if (direction == 1 && slot->m_parent != 0) {
            parentID = slot->m_parent->GetID();
        }
        ReconBuffer_StreamShort(buffer, &parentID);
        if (direction == 0) {
            // Will be resolved during post-load
            slot->m_parent = (cXObjectImpl*)(int)parentID;
        }

        ReconBuffer_StreamInt(buffer, &slot->m_slot);
        ReconBuffer_StreamInt(buffer, &slot->m_level);
    }

    // Stream routing slots
    int routingCount = GetNumRoutingSlots();
    ReconBuffer_StreamInt(buffer, &routingCount);

    // Routing slots are read-only from definition, don't stream their data
}

// ============================================================================
// cXObjectImpl::GetAgeInMinutes(void)
// Address: 0x800E184C | Size: 396 bytes
// NON_MATCHING - GCC register alloc, time calculation
//
// Gets the object's age in game minutes. Computes elapsed time from
// creation timestamp to current game time.
// ============================================================================
void cXObjectImpl::GetAgeInMinutes() {
    void* timeModule = GetTimeModule();
    if (timeModule == 0) {
        SetTemp(0, 0);
        return;
    }

    int currentTime = GetGameTime(timeModule);
    int creationTime = GetData(0x10);

    int age = currentTime - creationTime;
    if (age < 0) age = 0;

    // Also check for overflow in short range
    if (age > 0x7FFF) age = 0x7FFF;

    SetTemp(0, (short)age);
}

// ============================================================================
// cXObjectImpl::GetInteractionLeader(void)
// Address: 0x800E19D8 | Size: 284 bytes
// NON_MATCHING - GCC register alloc, hierarchy traversal
//
// Gets the leader object for the current interaction. Walks up the
// containment hierarchy to find the root object driving the interaction.
// ============================================================================
void cXObjectImpl::GetInteractionLeader() {
    cXObjectImpl* current = this;

    // Walk up hierarchy
    while (current != 0 && current->IsContained()) {
        HierarchySite* site = *(HierarchySite**)((char*)current + 0x90);
        if (site == 0 || site->m_parent == 0) break;
        current = site->m_parent;
    }

    // Return leader object
    if (current != 0) {
        cXObject* obj = *(cXObject**)((char*)current + 0x04);
        SetTemp(0, (short)current->GetID());
    } else {
        SetTemp(0, -1);
    }
}

// ============================================================================
// cXObjectImpl::UserCanPickup(void)
// Address: 0x800E1AF4 | Size: 452 bytes
// NON_MATCHING - GCC register alloc, condition chain
//
// Checks if the user is allowed to pick up this object. Validates
// multiple conditions: not a person, not in use, is in world, is
// from catalog, etc.
// ============================================================================
bool cXObjectImpl::UserCanPickup() {
    // Can't pickup people
    if (IsPerson()) return false;

    // Must be in world
    if (!IsInWorld()) return false;

    // Must not be in use
    if (IsOccupied()) return false;

    // Must be from catalog
    if (!IsFromCatalog()) return false;

    // Must not be a door or window (special placement rules)
    if (IsDoor() || IsWindow()) {
        // Doors/windows can be picked up only if not blocking route
        // Additional check needed
    }

    // Must not be support (table with stuff on it)
    if (IsSupport()) {
        // Check if any objects are on us
        int slotCount = CountObjectSlots();
        for (int i = 0; i < slotCount; i++) {
            void* contained = GetContainedObject(i);
            if (contained != 0) {
                return false;  // Has objects on it
            }
        }
    }

    // Check if object is burning
    if (IsBurning()) return false;

    // Must not be sim-independent special object
    if (SimIndependent()) return false;

    return true;
}

// ============================================================================
// cXObjectImpl::UserCanPlace(FTilePt &, int, cXObject *, int)
// Address: 0x800E1E30 | Size: 452 bytes
// NON_MATCHING - GCC register alloc, placement validation
//
// Checks if the user can place this object at the given location.
// Validates tile occupancy, wall conflicts, level boundaries, etc.
// ============================================================================
bool cXObjectImpl::UserCanPlace(FTilePt& tile, int level, cXObject* parent, int slot) {
    if (parent != 0 && slot >= 0) {
        // Placing into a container
        cXObjectImpl* parentImpl = parent->CAST_IMPL();
        if (parentImpl == 0) return false;

        // Check slot is empty
        void* contained = parentImpl->GetContainedObject(slot);
        if (contained != 0) return false;

        return true;
    }

    // Placing on ground - check tile occupancy
    FTileRect rect;
    ComputeRect(tile, &rect);

    // Check each tile in the rect
    for (int y = rect.y; y <= *(int*)((char*)&rect + 12); y++) {
        for (int x = rect.x; x <= *(int*)((char*)&rect + 8); x++) {
            FTilePt checkTile;
            checkTile.x = x;
            checkTile.y = y;

            // Check for existing objects
            void* obstacle = GetObstacleAtTile(checkTile, level);
            if (obstacle != 0) return false;

            // Check for wall conflicts
            if (GetWallBlockFlagsForPlacement(checkTile, level) != 0) {
                // Check wall placement flags
                int wallFlags = GetWallPlacementFlags();
                if (wallFlags == 0) return false;  // Can't be on wall
            }
        }
    }

    return true;
}

// ============================================================================
// cXObjectImpl::UserPlace(FTilePt &, int, cXObject *, int)
// Address: 0x800E1FF4 | Size: 308 bytes
// NON_MATCHING - GCC register alloc, placement dispatch
//
// Places the object at the user's chosen location. Validates the placement
// and calls Place() if valid.
// ============================================================================
void cXObjectImpl::UserPlace(FTilePt& tile, int level, cXObject* parent, int slot) {
    if (!UserCanPlace(tile, level, parent, slot)) return;

    // Set placed-from-inventory flag if applicable
    if (!IsInWorld()) {
        SetWasPlacedFromInventory(true);
    }

    // Do the placement
    Place(tile, level, parent, slot);
}

// ============================================================================
// cXObjectImpl::UserPickup(bool)
// Address: 0x800E2128 | Size: 308 bytes
// NON_MATCHING - GCC register alloc, cleanup dispatch
//
// Picks up the object on behalf of the user. If flag is true, returns
// to inventory. Otherwise just removes from world.
// ============================================================================
void cXObjectImpl::UserPickup(bool toInventory) {
    if (!UserCanPickup()) return;

    // Cancel any running interactions
    void* simObj = GetSim();
    if (simObj != 0) {
        // Notify sim system
    }

    // Pickup from world
    Pickup();

    if (toInventory) {
        // Add to inventory
        SetWasPlacedFromInventory(true);
        // Additional inventory logic
    }
}

// ============================================================================
// cXObjectImpl::ShouldAutoRotate(void)
// Address: 0x800E2364 | Size: 480 bytes
// NON_MATCHING - GCC register alloc, flag check chain
//
// Determines if this object should automatically rotate to face a
// nearby table, wall, or other reference point. Checks object type
// flags and nearby geometry.
// ============================================================================
bool cXObjectImpl::ShouldAutoRotate() {
    // Check if auto-rotate is enabled globally
    if (!cXObject::GetAutoReset()) return false;

    // Check object definition flags
    void* def = *(void**)((char*)this + 0x88);
    if (def == 0) return false;

    int objFlags = *(int*)((char*)def + 0x18);

    // Some objects never auto-rotate
    if (objFlags & 0x200) return false;  // No auto-rotate flag

    // Chairs auto-rotate to face tables
    if (IsChair()) return true;

    // Wall objects auto-rotate to face wall
    int wallPlacement = GetWallPlacementFlags();
    if (wallPlacement != 0) return true;

    return false;
}

// ============================================================================
// cXObjectImpl::CanChooseAutonomously(void)
// Address: 0x800E2604 | Size: 324 bytes
// NON_MATCHING - GCC register alloc, flag checks
//
// Checks if sims can autonomously choose to interact with this object.
// Validates object state (not broken, accessible, has interactions).
// ============================================================================
bool cXObjectImpl::CanChooseAutonomously() {
    // Must have autonomy interactions
    void* treeTab = GetTreeTab();
    if (treeTab == 0) return false;

    // Check if any autonomous interactions exist
    int autonomyCount = GetAutonomousInteractionCount(treeTab);
    if (autonomyCount <= 0) return false;

    // Must not be broken
    if (IsBroken()) return false;

    // Must be in world
    if (!IsInWorld()) return false;

    // Check global free will setting
    if (!GetFreeWill()) return false;

    // Must be sim-enabled
    if (!SimEnabled()) return false;

    return true;
}

// ============================================================================
// cXObject::GetWallBlockFlagsAtTile(CTilePt &, int)
// Address: 0x800E28AC | Size: 444 bytes
// NON_MATCHING - GCC register alloc, wall data lookup
//
// Gets the wall block flags at a specific tile. Used for collision and
// placement validation. Returns a bitmask of wall directions.
// ============================================================================
int cXObject::GetWallBlockFlagsAtTile(CTilePt& tile, int level) {
    cXObjectImpl* impl = CAST_IMPL();
    if (impl == 0) return 0;

    void* module = *(void**)((char*)impl + 0x58);
    if (module == 0) return 0;

    // Call through module to get wall data
    int* vtbl = *(int**)module;
    short offset = *(short*)((char*)vtbl + 0x60);
    void* fn = *(void**)((char*)vtbl + 0x64);
    return ((int(*)(void*, void*, int))fn)((char*)module + offset, &tile, level);
}

// ============================================================================
// cXObjectImpl::SyncObjectIsReady(signed char)
// Address: 0x800E2B70 | Size: 452 bytes
// NON_MATCHING - GCC register alloc, sync logic
//
// Called when a sync object becomes ready. Processes the sync notification
// and updates the waiting state. If there are queued actions waiting
// on this sync, processes them.
// ============================================================================
void cXObjectImpl::SyncObjectIsReady(s8 value) {
    *(s8*)((char*)this + 0xDC) = value;
    *(int*)((char*)this + 0xE4) = 0;

    // Check if any sims are waiting on this object
    ObjectModule* module = *(ObjectModule**)((char*)this + 0x58);
    if (module == 0) return;

    // Get object iterator to find waiting sims
    cXObject* first = GetFirst();
    if (first == 0) return;

    cXObjectImpl* iter = first->CAST_IMPL();
    while (iter != 0) {
        if (iter->IsPerson()) {
            // Check if this sim is waiting for our sync
            s8 waitSync = *(s8*)((char*)iter + 0xDC);
            if (waitSync == value) {
                // Notify sim that sync is ready
                int* vtbl = *(int**)iter;
                short offset = *(short*)((char*)vtbl + 0x1D0);
                void* fn = *(void**)((char*)vtbl + 0x1D4);
                ((void(*)(void*))fn)((char*)iter + offset);
            }
        }
        iter = iter->GetNextImpl();
    }
}

// ============================================================================
// cXObjectImpl::SyncObjectIsReady(void)
// Address: 0x800E2E04 | Size: 272 bytes
// NON_MATCHING - GCC register alloc
//
// No-argument version that marks the sync object as ready with default
// value and clears the waiting state.
// ============================================================================
void cXObjectImpl::SyncObjectIsReady() {
    SyncObjectIsReady(1);
}

// ============================================================================
// EdithVariableSet::GetCategoryVariableMap(unsigned short)
// Address: 0x800E84FC | Size: 664 bytes
// NON_MATCHING - GCC register alloc, map lookup
//
// Gets the variable map for a specific category. If the category doesn't
// exist yet, creates a new byte_key_map for it and adds it to the vector.
// ============================================================================
void* EdithVariableSet::GetCategoryVariableMap(unsigned short category) {
    // Get vector of maps
    void** begin = *(void***)_data;
    void** end = *(void***)((char*)_data + 4);

    // Check if category already has a map
    int mapCount = (int)(end - begin);
    if ((int)category < mapCount) {
        void* existingMap = begin[category];
        if (existingMap != 0) {
            return existingMap;
        }
    }

    // Need to create a new map
    void* newMap = CreateByteKeyMap();
    if (newMap == 0) return 0;

    // Ensure vector is large enough
    if ((int)category >= mapCount) {
        // Grow vector
        int newSize = (int)category + 1;
        void** capEnd = *(void***)((char*)_data + 8);
        int currentCap = (int)(capEnd - begin);

        if (newSize > currentCap) {
            int newCap = newSize > currentCap * 2 ? newSize : currentCap * 2;
            void** newMem = (void**)operator_new(newCap * sizeof(void*));
            memset(newMem, 0, newCap * sizeof(void*));

            if (mapCount > 0) {
                memcpy(newMem, begin, mapCount * sizeof(void*));
            }

            if (begin != 0) {
                operator_delete(begin);
            }

            *(void***)_data = newMem;
            *(void***)((char*)_data + 4) = newMem + newSize;
            *(void***)((char*)_data + 8) = newMem + newCap;
            begin = newMem;
        } else {
            *(void***)((char*)_data + 4) = begin + newSize;
        }

        // Zero new entries
        for (int i = mapCount; i < newSize; i++) {
            begin[i] = 0;
        }
    }

    begin[category] = newMap;
    return newMap;
}

// ============================================================================
// EdithVariableSet::RemoveInstanceVariable(unsigned char)
// Address: 0x800E7778 | Size: 740 bytes
// NON_MATCHING - GCC register alloc, map manipulation
//
// Removes an instance variable by key from the variable set. Finds the
// correct category map and removes the entry from it. If the map becomes
// empty, may clean it up.
// ============================================================================
void EdithVariableSet::RemoveInstanceVariable(unsigned char key) {
    // Determine category from key
    unsigned short category = (unsigned short)(key >> 3);

    void** begin = *(void***)_data;
    void** end = *(void***)((char*)_data + 4);
    int mapCount = (int)(end - begin);

    if ((int)category >= mapCount) return;

    void* map = begin[category];
    if (map == 0) return;

    // Remove from byte_key_map
    RemoveFromByteKeyMap(map, key);

    // Check if map is now empty
    int remaining = ByteKeyMapSize(map);
    if (remaining == 0) {
        DestroyByteKeyMap(map);
        begin[category] = 0;

        // Shrink vector if trailing nulls
        while (mapCount > 0 && begin[mapCount - 1] == 0) {
            mapCount--;
        }
        *(void***)((char*)_data + 4) = begin + mapCount;
    }
}

// ============================================================================
// EdithVariableSet::ReconKeyBitSet(ReconBuffer *, ...)
// Address: 0x800E7C14 | Size: 284 bytes
// NON_MATCHING - GCC register alloc, bit manipulation
//
// Serializes a key bit set from a byte_key_map iterator. Used during
// variable serialization to compact the key space.
// ============================================================================
void EdithVariableSet::ReconKeyBitSet(ReconBuffer* buffer, void* iterator) {
    if (buffer == 0) return;

    // Serialize the bit set that represents which keys are present
    // Iterator points to byte_key_map internal data
    unsigned char bitSet[9];  // 72 bits = 9 bytes
    memset(bitSet, 0, 9);

    // Walk through map entries and set bits
    while (IteratorValid(iterator)) {
        unsigned char key = IteratorKey(iterator);
        int byteIdx = key / 8;
        int bitIdx = key % 8;
        if (byteIdx < 9) {
            bitSet[byteIdx] |= (1 << bitIdx);
        }
        IteratorAdvance(iterator);
    }

    // Stream the bit set
    ReconBuffer_StreamData(buffer, bitSet, 9);
}

// ============================================================================
// EdithVariableSet::ShrinkToExactSize(byte_key_map<72, short, ...> &)
// Address: 0x800E7A5C | Size: 440 bytes
// NON_MATCHING - GCC register alloc, memory management
//
// Shrinks a byte_key_map's internal storage to exactly fit its current
// contents, freeing wasted capacity.
// ============================================================================
void EdithVariableSet::ShrinkToExactSize(void* map) {
    if (map == 0) return;

    int size = ByteKeyMapSize(map);
    if (size <= 0) return;

    int capacity = ByteKeyMapCapacity(map);
    if (size == capacity) return;  // Already exact

    // Allocate new storage
    int elemSize = 2;  // short values
    void* newStorage = operator_new(size * elemSize);
    if (newStorage == 0) return;

    // Copy entries
    CopyByteKeyMapEntries(map, newStorage, size);

    // Swap storage
    void* oldStorage = ByteKeyMapGetStorage(map);
    ByteKeyMapSetStorage(map, newStorage, size);

    if (oldStorage != 0) {
        operator_delete(oldStorage);
    }
}

// ============================================================================
// vector<byte_key_map<72, short, ...> >::reserve(unsigned int)
// Address: 0x803A61B8 | Size: 596 bytes
// NON_MATCHING - GCC STL vector reserve
// ============================================================================
void vector_byte_key_map_reserve(void* vec, unsigned int newCap) {
    void** pBegin = (void**)vec;
    void** pEnd = (void**)((char*)vec + 4);
    void** pCapEnd = (void**)((char*)vec + 8);

    void* begin = *pBegin;
    void* capEnd = *pCapEnd;
    int elemSize = 4;  // pointer size

    unsigned int currentCap = ((char*)capEnd - (char*)begin) / elemSize;
    if (newCap <= currentCap) return;

    void* end = *pEnd;
    int currentSize = ((char*)end - (char*)begin) / elemSize;

    void* newMem = operator_new(newCap * elemSize);
    if (currentSize > 0) {
        memcpy(newMem, begin, currentSize * elemSize);
    }
    if (begin != 0) {
        operator_delete(begin);
    }

    *pBegin = newMem;
    *pEnd = (char*)newMem + currentSize * elemSize;
    *pCapEnd = (char*)newMem + newCap * elemSize;
}

// ============================================================================
// vector<short>::reserve(unsigned int)
// Address: 0x803A640C | Size: 308 bytes
// NON_MATCHING - GCC STL vector reserve
// ============================================================================
void vector_short_reserve(void* vec, unsigned int newCap) {
    short** pBegin = (short**)vec;
    short** pEnd = (short**)((char*)vec + 4);
    short** pCapEnd = (short**)((char*)vec + 8);

    short* begin = *pBegin;
    short* capEnd = *pCapEnd;

    unsigned int currentCap = (unsigned int)(capEnd - begin);
    if (newCap <= currentCap) return;

    short* end = *pEnd;
    int currentSize = (int)(end - begin);

    short* newMem = (short*)operator_new(newCap * sizeof(short));
    if (currentSize > 0) {
        memcpy(newMem, begin, currentSize * sizeof(short));
    }
    if (begin != 0) {
        operator_delete(begin);
    }

    *pBegin = newMem;
    *pEnd = newMem + currentSize;
    *pCapEnd = newMem + newCap;
}

// ============================================================================
// vector<short>::operator=(vector<short> &)
// Address: 0x803A6640 | Size: 380 bytes
// NON_MATCHING - GCC STL vector assignment
// ============================================================================
void vector_short_assign(void* dst, void* src) {
    short** dstBegin = (short**)dst;
    short** dstEnd = (short**)((char*)dst + 4);
    short** dstCapEnd = (short**)((char*)dst + 8);

    short** srcBegin = (short**)src;
    short** srcEnd = (short**)((char*)src + 4);

    short* sBegin = *srcBegin;
    short* sEnd = *srcEnd;
    int srcSize = (int)(sEnd - sBegin);

    short* dBegin = *dstBegin;
    short* dCapEnd = *dstCapEnd;
    int dstCap = (int)(dCapEnd - dBegin);

    if (srcSize <= dstCap) {
        // Fits in existing storage
        if (srcSize > 0) {
            memcpy(dBegin, sBegin, srcSize * sizeof(short));
        }
        *dstEnd = dBegin + srcSize;
    } else {
        // Need reallocation
        if (dBegin != 0) {
            operator_delete(dBegin);
        }

        short* newMem = (short*)operator_new(srcSize * sizeof(short));
        memcpy(newMem, sBegin, srcSize * sizeof(short));

        *dstBegin = newMem;
        *dstEnd = newMem + srcSize;
        *dstCapEnd = newMem + srcSize;
    }
}

// ============================================================================
// EdithVariableSet::s_VariablesUsed
// Address: 0x803DAF1C | Size: 288 bytes
// This is BSS data, not a function
// ============================================================================
// char EdithVariableSet_s_VariablesUsed[288];

// ============================================================================
// EdithVariableSet::s_IsForcedInstanceVariable
// Address: 0x803DB03C | Size: 288 bytes
// This is BSS data, not a function
// ============================================================================
// char EdithVariableSet_s_IsForcedInstanceVariable[288];

#endif // Reference decompilation
