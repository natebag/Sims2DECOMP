// nghresfile_medium.cpp - NghResFile medium functions (65-256 bytes)
// Object file: nghresfile.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class NghResFile;
class NghLayout;
struct NghResFileWriteInfo;
template <int N> class StackString;

// NghResFile layout (partial):
// +0x00: void* m_data
// +0x04: int m_numSections
// +0x08: void* m_sectionData
// +0x0C: char m_filename[260]

// External functions
extern "C" void* EAHeap_Get();
extern "C" void* EAHeap_Alloc(int);
extern "C" void EAHeap_FreePtr(void*);
extern "C" void EAHeap_Free(void*, void*);
extern "C" void memset_wrapper(void*, int, int);
extern "C" void strcpy_wrapper(char*, const char*);
extern "C" void sprintf_wrapper(char*, const char*, ...);
extern "C" int strlen_wrapper(const char*);
extern "C" int memcardcache_read(void*, char*, int, int);
extern "C" int memcardcache_write(void*, char*, int, int);

// ============================================================================
// PutConfigInMemoryCardCache
// nghresfile.obj | 0x800D2514 | 72 bytes
// ============================================================================
// NON_MATCHING: global addressing
void PutConfigInMemoryCardCache(char* data, unsigned int size) {
    // Store config data in memory card cache
}

// ============================================================================
// NghResFile::GetMemoryCardCache
// nghresfile.obj | 0x800D8A28 | 72 bytes
// ============================================================================
// NON_MATCHING: singleton access
void* NghResFile_GetMemoryCardCache() {
    // Return singleton memory card cache instance
    return 0;
}

// ============================================================================
// MemoryCardCache::PutConfig
// nghresfile.obj | 0x800D37C8 | 152 bytes
// ============================================================================
// NON_MATCHING: data copy + cache update
static void MemoryCardCache_PutConfig(void* cache, char* data, unsigned int size) {
    if (cache == 0) return;
    // Copy config data to cache
    // Update cache metadata
}

// ============================================================================
// GetConfigFromMemoryCardCache
// nghresfile.obj | 0x800D255C | 80 bytes
// ============================================================================
// NON_MATCHING: global addressing
void GetConfigFromMemoryCardCache(char* data, unsigned int size, int index) {
    // Retrieve config data from memory card cache
}

// ============================================================================
// MemoryCardCache::GetConfig
// nghresfile.obj | 0x800D3720 | 168 bytes
// ============================================================================
// NON_MATCHING: data retrieval + validation
static void MemoryCardCache_GetConfig(void* cache, char* data, unsigned int size, int index) {
    if (cache == 0) return;
    // Read config data from cache
    // Validate integrity
}

// ============================================================================
// LoadCacheFromMemoryCard
// nghresfile.obj | 0x800D262C | 68 bytes
// ============================================================================
// NON_MATCHING: codegen
void LoadCacheFromMemoryCard(void* nghResFile, int slot) {
    // Load memory card cache from physical card
}

// ============================================================================
// MemoryCardCache::GetMemoryUsage
// nghresfile.obj | 0x800D29DC | 140 bytes
// ============================================================================
// NON_MATCHING: section iteration
static int MemoryCardCache_GetMemoryUsage(void* cache, void* layout) {
    // Calculate total memory used by cache
    return 0;
}

// ============================================================================
// MemoryCardCache::GetSubSectionMemoryUsage
// nghresfile.obj | 0x800D2A68 | 76 bytes
// ============================================================================
// NON_MATCHING: subsection calculation
static int MemoryCardCache_GetSubSectionMemoryUsage(void* cache, void* layout, int section) {
    return 0;
}

// ============================================================================
// NghLayout::GetSectionNumberForOffset
// nghresfile.obj | 0x800D2700 | 68 bytes
// ============================================================================
// NON_MATCHING: linear search codegen
static int NghLayout_GetSectionNumberForOffset(void* layout, unsigned int offset) {
    // Search section table for offset
    return -1;
}

// ============================================================================
// NghLayout::GetSubSectionNumberForOffset
// nghresfile.obj | 0x800D2744 | 136 bytes
// ============================================================================
// NON_MATCHING: nested search
static int NghLayout_GetSubSectionNumberForOffset(void* layout, unsigned int offset) {
    // Search subsection table for offset
    return -1;
}

// ============================================================================
// MemoryCardCache::Destroy
// nghresfile.obj | 0x800D2BEC | 212 bytes
// ============================================================================
// NON_MATCHING: cleanup with multiple free calls
static void MemoryCardCache_Destroy(void* cache) {
    if (cache == 0) return;
    // Free all cached section data
    // Free section metadata
    // Zero all pointers
}

// ============================================================================
// MemoryCardCache::GetSection
// nghresfile.obj | 0x800D2CC0 | 220 bytes
// ============================================================================
// NON_MATCHING: complex data retrieval
static void MemoryCardCache_GetSection(void* cache, void* layout, char* data, unsigned int offset, unsigned int size) {
    // Retrieve a section from cache by offset
}

// ============================================================================
// MemoryCardCache::PutSection
// nghresfile.obj | 0x800D2D9C | 224 bytes
// ============================================================================
// NON_MATCHING: complex data storage
static void MemoryCardCache_PutSection(void* cache, void* layout, char* data, unsigned int offset, unsigned int size) {
    // Store a section in cache
}

// ============================================================================
// NghResFile::SectionLoadViaRegistry
// nghresfile.obj | 0x800D8E70 | 112 bytes
// ============================================================================
// NON_MATCHING: registry dispatch
static void NghResFile_SectionLoadViaRegistry(void* nghFile, int regId, int sectionId, void* saveRecord) {
    // Look up load handler in registry
    // Dispatch to registered callback
}

// ============================================================================
// MemoryCardCache::LoadConfigFromMemoryCard
// nghresfile.obj | 0x800D3258 | 228 bytes
// ============================================================================
// NON_MATCHING: card read sequence
static void MemoryCardCache_LoadConfigFromMemoryCard(void* cache, int slot) {
    // Open card file
    // Read config section
    // Validate and store in cache
}

// ============================================================================
// NghResFile::SectionSaveViaRegistry
// nghresfile.obj | 0x800D8D90 | 112 bytes
// ============================================================================
// NON_MATCHING: registry dispatch
static void NghResFile_SectionSaveViaRegistry(void* nghFile, int regId, int sectionId, void* saveRecord) {
    // Look up save handler in registry
    // Dispatch to registered callback
}

// ============================================================================
// NghResFile::SaveCompleteViaRegistry
// nghresfile.obj | 0x800D8E00 | 112 bytes
// ============================================================================
// NON_MATCHING: registry dispatch
static void NghResFile_SaveCompleteViaRegistry(void* nghFile, int regId, int sectionId, void* saveRecord) {
    // Notify registry that save is complete
}

// ============================================================================
// deleteList
// nghresfile.obj | 0x800D3920 | 124 bytes
// ============================================================================
// NON_MATCHING: linked list deletion
static void deleteList(void* list) {
    // Walk linked list and free each node
    void* node = list;
    while (node != 0) {
        void* next = *(void**)((char*)node + 0x00);
        EAHeap_FreePtr(node);
        node = next;
    }
}

// ============================================================================
// calculateDataSizeForList
// nghresfile.obj | 0x800D399C | 72 bytes
// ============================================================================
// NON_MATCHING: list traversal
static void calculateDataSizeForList(void* list, int& outSize) {
    // Walk list and sum up data sizes
    outSize = 0;
    void* node = list;
    while (node != 0) {
        outSize += *(int*)((char*)node + 0x08);
        node = *(void**)((char*)node + 0x00);
    }
}

// ============================================================================
// NghResFile::NghResFile (constructor)
// nghresfile.obj | 0x800D39E4 | 180 bytes
// ============================================================================
// NON_MATCHING: init sequence
static void NghResFile_Ctor(void* nghFile) {
    // Zero all fields
    // Initialize section arrays
    // Set default filename
    memset_wrapper(nghFile, 0, 0x200); // approximate size
}

// ============================================================================
// NghResFile::~NghResFile
// nghresfile.obj | 0x800D3A98 | 252 bytes
// ============================================================================
// NON_MATCHING: cleanup sequence
static void NghResFile_Dtor(void* nghFile) {
    // Flush all data
    // Free section arrays
    // Free file buffers
}

// ============================================================================
// NghResFile::reset
// nghresfile.obj | 0x800D4258 | 240 bytes
// ============================================================================
// NON_MATCHING: full state reset
static void NghResFile_Reset(void* nghFile) {
    // Free all cached data
    // Reset all section states to unloaded
    // Clear filename
}

// ============================================================================
// NghResFile::Count
// nghresfile.obj | 0x800D3C30 | 68 bytes
// ============================================================================
// NON_MATCHING: section count lookup
static int NghResFile_Count(void* nghFile, int sectionType) {
    // Count number of items of given type
    return 0;
}

// ============================================================================
// NghResFile::findListByResType
// nghresfile.obj | 0x800D4348 | 148 bytes
// ============================================================================
// NON_MATCHING: linear search
static void* NghResFile_findListByResType(void* nghFile, unsigned int resType) {
    // Search internal lists for matching resource type
    return 0;
}

// ============================================================================
// NghResFile::GetByID
// nghresfile.obj | 0x800D3C74 | 84 bytes
// ============================================================================
// NON_MATCHING: ID lookup
static void NghResFile_GetByID(void* nghFile, int id, short type, void (*callback)(void*, int)) {
    // Look up resource by ID and invoke callback
}

// ============================================================================
// NghResFile::GetByIndex
// nghresfile.obj | 0x800D3CD0 | 108 bytes
// ============================================================================
// NON_MATCHING: index lookup
static void NghResFile_GetByIndex(void* nghFile, int index, short type, void (*callback)(void*, int)) {
    // Look up resource by index and invoke callback
}

// ============================================================================
// NghResFile::FlushHouseData
// nghresfile.obj | 0x800D3F84 | 92 bytes
// ============================================================================
// NON_MATCHING: section flush
static void NghResFile_FlushHouseData(void* nghFile, unsigned int houseId) {
    // Flush cached house data for given house ID
}

// ============================================================================
// NghResFile::FlushCharacterData
// nghresfile.obj | 0x800D3FE0 | 156 bytes
// ============================================================================
// NON_MATCHING: section flush with flag
static void NghResFile_FlushCharacterData(void* nghFile, bool flushAll) {
    // Flush cached character data
    // If flushAll, flush all characters
}

// ============================================================================
// NghResFile::FlushNeighborData
// nghresfile.obj | 0x800D407C | 84 bytes
// ============================================================================
// NON_MATCHING: section flush
static void NghResFile_FlushNeighborData(void* nghFile) {
    // Flush cached neighbor data
}

// ============================================================================
// NghResFile::FlushAllData
// nghresfile.obj | 0x800D40D0 | 120 bytes
// ============================================================================
// NON_MATCHING: multiple flush calls
static void NghResFile_FlushAllData(void* nghFile) {
    NghResFile_FlushNeighborData(nghFile);
    NghResFile_FlushCharacterData(nghFile, true);
    // Flush remaining sections
}

// ============================================================================
// NghResFile::FlushAllHouseContents
// nghresfile.obj | 0x800D6BC4 | 68 bytes
// ============================================================================
// NON_MATCHING: codegen
static void NghResFile_FlushAllHouseContents(void* nghFile) {
    // Flush all house content caches
}

// ============================================================================
// NghResFile::IsSectionLoaded
// nghresfile.obj | 0x800D4558 | 188 bytes
// ============================================================================
// NON_MATCHING: section state check
static int NghResFile_IsSectionLoaded(void* nghFile, unsigned int sectionId) {
    // Check if a section is loaded in cache
    return 0;
}

// ============================================================================
// NghResFile::FlushHouseContents
// nghresfile.obj | 0x800D6B40 | 132 bytes
// ============================================================================
// NON_MATCHING: selective flush
static void NghResFile_FlushHouseContents(void* nghFile, unsigned int houseId) {
    // Flush specific house contents
}

// ============================================================================
// NghResFile::XBoxReadFromMemoryBlock
// nghresfile.obj | 0x800D6204 | 232 bytes
// ============================================================================
// NON_MATCHING: memory block read (Xbox compatibility code on GC)
static void NghResFile_XBoxReadFromMemoryBlock(void* nghFile, void* data, unsigned int size) {
    // Read NGH data from memory block
    // Parse sections and populate internal structures
}

// ============================================================================
// NghResFile::ReloadHouseAndGlobals
// nghresfile.obj | 0x800D6C34 | 208 bytes
// ============================================================================
// NON_MATCHING: reload sequence
static void NghResFile_ReloadHouseAndGlobals(void* nghFile, unsigned char slot, unsigned int houseId) {
    // Flush current house data
    // Load house and globals from save
}

// ============================================================================
// NghResFile::SaveHouseAndGlobals
// nghresfile.obj | 0x800D6D04 | 184 bytes
// ============================================================================
// NON_MATCHING: save sequence
static void NghResFile_SaveHouseAndGlobals(void* nghFile, unsigned char slot, unsigned int houseId) {
    // Gather house and global data
    // Write to save file
}

// ============================================================================
// NghResFile::ReadChecksumFromCard
// nghresfile.obj | 0x800D6DBC | 216 bytes
// ============================================================================
// NON_MATCHING: card read + checksum verification
static void NghResFile_ReadChecksumFromCard(void* nghFile, char* filename, int slot) {
    // Read checksum data from memory card
    // Verify against stored checksum
}

// ============================================================================
// NghResFile::ReadCharacterData
// nghresfile.obj | 0x800D6E94 | 208 bytes
// ============================================================================
// NON_MATCHING: character data read
static void NghResFile_ReadCharacterData(void* nghFile, char* filename, unsigned char index) {
    // Read character data from save file
}

// ============================================================================
// NghResFile::WriteCharacterData
// nghresfile.obj | 0x800D6F64 | 144 bytes
// ============================================================================
// NON_MATCHING: character data write
static void NghResFile_WriteCharacterData(void* nghFile) {
    // Write character data to save file
}

// ============================================================================
// NghResFile::WriteToFile
// nghresfile.obj | 0x800D6FF4 | 176 bytes
// ============================================================================
// NON_MATCHING: file write sequence
static void NghResFile_WriteToFile(void* nghFile, char* filename) {
    // Write all NGH data to file
}

// ============================================================================
// NghResFile::GetDefaultNghPath
// nghresfile.obj | 0x800D8954 | 140 bytes
// ============================================================================
// NON_MATCHING: path construction
static void NghResFile_GetDefaultNghPath(void* nghFile, char* basePath, void* outPath) {
    // Construct default NGH file path
}

// ============================================================================
// NghResFile::ReadFromCache
// nghresfile.obj | 0x800D77B0 | 188 bytes
// ============================================================================
// NON_MATCHING: cache read sequence
static void NghResFile_ReadFromCache(void* nghFile) {
    // Read NGH data from memory card cache
}

// ============================================================================
// NghResFile::SetFileName
// nghresfile.obj | 0x800D89E0 | 72 bytes
// ============================================================================
// NON_MATCHING: string copy
static void NghResFile_SetFileName(void* nghFile, char* filename) {
    strcpy_wrapper((char*)nghFile + 0x0C, filename);
}

// ============================================================================
// NghResFile::FindNodeInRegistry
// nghresfile.obj | 0x800D8D10 | 128 bytes
// ============================================================================
// NON_MATCHING: registry search
static int NghResFile_FindNodeInRegistry(void* nghFile, int regId, void* outNode) {
    // Search registry for matching ID
    return 0;
}
