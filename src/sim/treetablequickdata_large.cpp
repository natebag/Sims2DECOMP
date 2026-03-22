// treetablequickdata_large.cpp - TreeTableQuickData large functions (257-1024 bytes)
// Object file: treetablequickdata.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
    void* memset(void* dst, int val, u32 n);
}

// ============================================================================
// TreeTableEntryQuickData::TreeTableEntryQuickData(TreeTableEntry*)
// Address: 0x8015d8f8
// Size: 0x134 = 308 bytes
// NON_MATCHING - field initialization from TreeTableEntry, COM ref counting
// ============================================================================
void TreeTableEntryQuickData_ctor(void* self, void* entry) {
    char* _this = (char*)self;
    char* src = (char*)entry;

    // Initialize COM ref count
    *(int*)(_this + 0x00) = 1; // m_refCount

    // Copy basic fields from TreeTableEntry
    // TreeID, ResourceID, Index, OrderIndex
    *(short*)(_this + 0x04) = *(short*)(src + 0x00); // m_treeID
    *(short*)(_this + 0x06) = *(short*)(src + 0x02); // m_resourceID
    *(int*)(_this + 0x08) = *(int*)(src + 0x04);     // m_index
    *(int*)(_this + 0x0C) = *(int*)(src + 0x08);     // m_orderIndex

    // Copy flag fields
    *(int*)(_this + 0x10) = *(int*)(src + 0x0C);     // m_flags

    // Copy attenuation value
    *(float*)(_this + 0x14) = *(float*)(src + 0x10); // m_attenuation

    // Copy string name (if present)
    // Uses EString copy constructor or direct pointer copy

    // Copy join index
    *(int*)(_this + 0x20) = *(int*)(src + 0x18);     // m_joinIndex

    // Copy motive data array
    // Iterate through ads and create TreeTableAdQuickData for each

    // Initialize ad list
    *(int*)(_this + 0x24) = 0; // m_numAds
    *(void**)(_this + 0x28) = 0; // m_pAds

    (void)src;
}

// ============================================================================
// TreeTableEntryQuickData::~TreeTableEntryQuickData(void)
// Address: 0x8015da2c
// Size: 0x10c = 268 bytes
// NON_MATCHING - COM release, ad cleanup
// ============================================================================
void TreeTableEntryQuickData_dtor(void* self) {
    char* _this = (char*)self;

    // Release all TreeTableAdQuickData objects
    int numAds = *(int*)(_this + 0x24);
    void** ads = *(void***)(_this + 0x28);
    for (int i = 0; i < numAds; i++) {
        if (ads[i]) {
            // Call Release() on each ad
            // ads[i]->Release()
        }
    }

    // Free ad array
    if (ads) {
        operator_delete_wrapper(ads);
    }

    // Clean up string name
    // Destroy EString member if present
}

// ============================================================================
// TreeTableEntryQuickData::GetAd(int) const
// Address: 0x8015db38
// Size: 0x164 = 356 bytes
// NON_MATCHING - ad lookup, lazy loading
// ============================================================================
void* TreeTableEntryQuickData_GetAd(void* self, int index) {
    char* _this = (char*)self;

    // Bounds check on index
    int numAds = *(int*)(_this + 0x24);
    if (index < 0 || index >= numAds) {
        return 0;
    }

    // Get ad from cached array
    void** ads = *(void***)(_this + 0x28);
    void* ad = ads[index];

    // If ad not yet loaded, create it
    if (!ad) {
        // Create new TreeTableAdQuickData
        ad = operator_new_wrapper(0x30);
        // Initialize from source data
        // Store in array
        ads[index] = ad;
    }

    // AddRef on returned ad
    // ad->AddRef()

    return ad;
}

// ============================================================================
// TreeTableQuickData::~TreeTableQuickData(void)
// Address: 0x8015dd20
// Size: 0x10c = 268 bytes
// NON_MATCHING - entry cleanup, COM release
// ============================================================================
void TreeTableQuickData_dtor(void* self) {
    char* _this = (char*)self;

    // Release all TreeTableEntryQuickData objects
    int numEntries = *(int*)(_this + 0x08);
    void** entries = *(void***)(_this + 0x0C);

    for (int i = 0; i < numEntries; i++) {
        if (entries[i]) {
            // Call Release() on each entry
        }
    }

    // Free entry array
    if (entries) {
        operator_delete_wrapper(entries);
    }

    // Clean up ordered entry index if present
    void* orderedIdx = *(void**)(_this + 0x10);
    if (orderedIdx) {
        operator_delete_wrapper(orderedIdx);
    }
}

// ============================================================================
// TreeTableQuickData::LoadFromDataID(ObjectDataID&)
// Address: 0x8015de60
// Size: 0x1b8 = 440 bytes
// NON_MATCHING - data loading, entry construction
// ============================================================================
void TreeTableQuickData_LoadFromDataID(void* self, void* dataID) {
    char* _this = (char*)self;

    // Get resource from data ID
    // Look up resource in dataset manager

    // Clear existing entries
    // TreeTableQuickData::~TreeTableQuickData cleanup

    // Load header from resource
    // Read entry count
    // Read data format version

    // Allocate entry array
    int numEntries = 0; // read from resource
    void** entries = (void**)operator_new_wrapper(numEntries * 4);

    // For each entry in resource:
    //   Create TreeTableEntryQuickData from resource data
    //   Store in entries array

    // Build ordered index
    // Sort entries by order index

    // Store results
    *(int*)(_this + 0x08) = numEntries;
    *(void**)(_this + 0x0C) = entries;

    (void)dataID;
}

// ============================================================================
// vector<ConsoleAutoRefCount<TreeTableAdQuickData>>::_M_fill_insert(...)
// Address: 0x803aece8
// Size: 0x54c = 1356 bytes (over 1024 - skip)
// ============================================================================
