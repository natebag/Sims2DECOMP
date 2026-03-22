// nghresfile_large.cpp - NghResFile large functions (257-1024 bytes)
// Object file: nghresfile.obj
// All NON_MATCHING - GCC vs SN Systems codegen differences

#include "types.h"

extern "C" {
    void* operator_new_wrapper(u32 size);
    void operator_delete_wrapper(void* ptr);
    void* memcpy(void* dst, const void* src, u32 n);
    void* memset(void* dst, int val, u32 n);
    int strcmp(const char* s1, const char* s2);
}

// ============================================================================
// NghLayout::IsOffsetARegistrySubSection(unsigned int, NghResFile::RegistryID&, NghResFile::SectionID&)
// Address: 0x800d27cc
// Size: 0x210 = 528 bytes
// NON_MATCHING - offset calculation, section lookup logic
// ============================================================================
int NghLayout_IsOffsetARegistrySubSection(void* self, u32 offset, void* outRegistryID, void* outSectionID) {
    char* _this = (char*)self;

    // Get total number of sections
    int numSections = *(int*)(_this + 0x08);

    // Iterate through sections to find matching offset
    u32 currentOffset = 0;
    for (int i = 0; i < numSections; i++) {
        // Get section size
        u32 sectionSize = *(u32*)(_this + 0x10 + i * 0x0C);

        // Check if offset falls within this section
        if (offset >= currentOffset && offset < currentOffset + sectionSize) {
            // Found the section, now check subsections
            int numSubSections = *(int*)(_this + 0x14 + i * 0x0C);

            u32 subOffset = currentOffset;
            for (int j = 0; j < numSubSections; j++) {
                u32 subSize = *(u32*)(_this + 0x18 + i * 0x0C + j * 8);
                if (offset >= subOffset && offset < subOffset + subSize) {
                    // Check if this is a registry subsection
                    int type = *(int*)(_this + 0x1C + i * 0x0C + j * 8);
                    if (type == 1) { // Registry type
                        *(int*)outRegistryID = i;
                        *(int*)outSectionID = j;
                        return 1;
                    }
                    return 0;
                }
                subOffset += subSize;
            }
            return 0;
        }
        currentOffset += sectionSize;
    }
    return 0;
}

// ============================================================================
// MemoryCardCache::Init(NghLayout*)
// Address: 0x800d2ab4
// Size: 0x138 = 312 bytes
// NON_MATCHING - memory allocation, cache initialization
// ============================================================================
void MemoryCardCache_Init(void* self, void* layout) {
    char* _this = (char*)self;

    // Get total cache size from layout
    // Allocate cache buffer
    // Initialize cache entries for each section

    // Set layout pointer
    *(void**)(_this + 0x00) = layout;

    // Initialize dirty flags
    *(int*)(_this + 0x04) = 0;

    // Get section count from layout
    int numSections = *(int*)((char*)layout + 0x08);

    // Allocate section tracking arrays
    // For each section:
    //   Allocate buffer for cached data
    //   Set valid flag to false
    //   Set dirty flag to false

    (void)numSections;
}

// ============================================================================
// MemoryCardCache::GetSection(NghLayout*, char*, unsigned int, unsigned int)
// Address: 0x800d2cc0
// Size: 0xdc = 220 bytes (under 257 - skip)
// ============================================================================

// ============================================================================
// MemoryCardCache::PutSection(NghLayout*, char*, unsigned int, unsigned int)
// Address: 0x800d2d9c
// Size: 0xe0 = 224 bytes (under 257 - skip)
// ============================================================================

// ============================================================================
// MemoryCardCache::CacheNghSection(NghLayout*, char*, unsigned int, unsigned int)
// Address: 0x800d2e7c
// Size: 0x140 = 320 bytes
// NON_MATCHING - cache lookup, memory copy
// ============================================================================
void MemoryCardCache_CacheNghSection(void* self, void* layout, char* data, u32 offset, u32 size) {
    char* _this = (char*)self;

    // Look up section number for offset
    // Get subsection number for offset
    // Check if section is already cached

    // If not cached, allocate cache buffer
    // Copy data into cache
    // Mark section as valid
    // Mark section as dirty

    (void)_this;
    (void)layout;
    (void)data;
    (void)offset;
    (void)size;
}

// ============================================================================
// MemoryCardCache::LoadCacheFromMemoryCard(int, NghResFile*)
// Address: 0x800d2fe0
// Size: 0x278 = 632 bytes
// NON_MATCHING - file I/O, section loading
// ============================================================================
void MemoryCardCache_LoadCacheFromMemoryCard_NghResFile(void* self, int slot, void* nghFile) {
    char* _this = (char*)self;

    // Open memory card file for reading
    // Read header to verify format version

    // For each cached section:
    //   Read section header
    //   Verify section ID matches
    //   Read section data
    //   Store in cache buffer
    //   Mark as valid

    // Handle errors:
    //   If file corrupted, clear cache
    //   If version mismatch, clear and re-save

    // Close file

    (void)_this;
    (void)slot;
    (void)nghFile;
}

// ============================================================================
// MemoryCardCache::SaveAllToMemoryCard(int)
// Address: 0x800d333c
// Size: 0x3e4 = 996 bytes
// NON_MATCHING - file I/O, section iteration, save logic
// ============================================================================
void MemoryCardCache_SaveAllToMemoryCard(void* self, int slot) {
    char* _this = (char*)self;

    // Get layout
    void* layout = *(void**)(_this + 0x00);

    // Calculate total save size
    // Open memory card file for writing

    // Write header with version info
    // Write section count

    // For each section:
    //   If section is dirty or forced:
    //     Write section header (ID, size)
    //     Write section data from cache
    //     Clear dirty flag

    // Write checksum at end of file
    // Close file

    // Handle errors:
    //   If write fails, report error
    //   If card full, report no space

    (void)layout;
    (void)slot;
}

// ============================================================================
// NghResFile::NghResFile(void)
// Address: 0x800d39e4 (skip - 0xb4 = 180 bytes)
// ============================================================================

// ============================================================================
// NghResFile::init(void)
// Address: 0x800d4148
// Size: 0x110 = 272 bytes
// NON_MATCHING - member initialization, list setup
// ============================================================================
void NghResFile_init(void* self) {
    char* _this = (char*)self;

    // Initialize write info lists
    *(void**)(_this + 0x04) = 0; // m_pWriteInfoList
    *(int*)(_this + 0x08) = 0;   // m_writeInfoCount

    // Initialize section lists
    // Create empty list for each resource type
    for (int i = 0; i < 8; i++) {
        *(void**)(_this + 0x10 + i * 4) = 0;
    }

    // Set file handle to invalid
    *(int*)(_this + 0x30) = -1;

    // Initialize cache pointer
    *(void**)(_this + 0x34) = 0;

    // Set valid flag
    *(int*)(_this + 0x38) = 0;

    // Initialize current house
    *(u32*)(_this + 0x3C) = 0xFFFFFFFF;
}

// ============================================================================
// NghResFile::Add(Memory::HandleNode*, int, short, StringBuffer&, bool)
// Address: 0x800d3d7c
// Size: 0x1f0 = 496 bytes
// NON_MATCHING - resource list management, handle allocation
// ============================================================================
void NghResFile_Add(void* self, void* handleNode, int resType, short id, void* name, int overwrite) {
    char* _this = (char*)self;

    // Find or create list for resType
    // Check if resource with same ID already exists

    // If exists and overwrite:
    //   Remove old entry
    //   Free old handle

    // If exists and !overwrite:
    //   Return without adding

    // Allocate new write info entry
    // Set resource type, ID, name
    // Set handle node reference

    // Add to write info list
    // Increment write info count

    // Mark file as dirty

    (void)_this;
    (void)handleNode;
    (void)resType;
    (void)id;
    (void)name;
    (void)overwrite;
}

// ============================================================================
// NghResFile::ValidateSaveGame(char*, int, bool)
// Address: 0x800d4bbc
// Size: 0x140 = 320 bytes
// NON_MATCHING - checksum validation, version checking
// ============================================================================
int NghResFile_ValidateSaveGame(void* self, char* data, int size, int strict) {
    char* _this = (char*)self;

    // Read header from data
    // Verify magic number
    // Check version number against current build

    // If strict mode:
    //   Verify checksum of entire save data
    //   Check section integrity
    //   Verify all required sections present

    // If not strict:
    //   Just check header magic and version

    // Return 1 if valid, 0 if invalid

    (void)_this;
    (void)data;
    (void)size;
    (void)strict;
    return 1;
}

// ============================================================================
// NghResFile::FlushSection(unsigned int)
// Address: 0x800d4614
// Size: 0x1d0 = 464 bytes
// NON_MATCHING - section data flushing, cache cleanup
// ============================================================================
void NghResFile_FlushSection(void* self, u32 sectionId) {
    char* _this = (char*)self;

    // Find section in write info list by sectionId
    // Get section data pointer

    // If section has cached data:
    //   Write cache to NGH file
    //   Free cache buffer
    //   Clear cache entry

    // Remove all write info entries for this section
    // Decrement write info count

    // Update section tracking
    // Mark section as flushed

    (void)_this;
    (void)sectionId;
}

// ============================================================================
// NghResFile::findListByResType(unsigned int)
// Address: 0x800d4348 (0x94 = 148 bytes - skip, under 257)
// ============================================================================

// ============================================================================
// NghResFile::reset(void)
// Address: 0x800d4258 (0xf0 = 240 bytes - skip, under 257)
// ============================================================================

// ============================================================================
// MemoryCardCache::LoadConfigFromMemoryCard(int)
// Address: 0x800d3258
// Size: 0xe4 = 228 bytes (under 257 - skip)
// ============================================================================

// ============================================================================
// MemoryCardCache::Destroy(void)
// Address: 0x800d2bec (0xd4 = 212 bytes - skip)
// ============================================================================

// ============================================================================
// MemoryCardCache::PutConfig(char*, unsigned int)
// Address: 0x800d37c8 (0x98 = 152 bytes - skip)
// ============================================================================

// ============================================================================
// ObjectList::AddObject(cXObject*)
// Address: 0x80048590  (from influencemap.obj but related)
// Size: 0x184 = 388 bytes -- moved to influencemap_large.cpp
// ============================================================================
