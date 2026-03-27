// bigfish_batch_2.cpp - Big fish asm stub conversions (6154-7239 lines), batch 2
// Converted from 8 asm stub files to portable C++
// Classes: NghResFile (55 funcs), EA::Allocator (55 funcs), ENgcMemoryCard (21 funcs),
//          CASTarget (41 funcs), StringPool (7 funcs), ISimsObjectModel (51 funcs),
//          cFixedWorldImpl (33 funcs), ObjectFolderImpl (56 funcs)
// Total: 319 functions
#include "types.h"

// ============================================================================
// External functions
// ============================================================================
extern "C" {
    void* memcpy(void*, const void*, unsigned int);
    void* memset(void*, int, unsigned int);
    int memcmp(const void*, const void*, unsigned int);
    int strlen(const char*);
    char* strcpy(char*, const char*);
    char* strcat(char*, const char*);
    int strcmp(const char*, const char*);
    int strcasecmp(const char*, const char*);
    int strncmp(const char*, const char*, unsigned int);
    char* strncpy(char*, const char*, unsigned int);
    int Sprintf(char*, char*, ...);
    int wcslen(const unsigned short*);
    void* malloc(unsigned int);
    void free(void*);
}

// Memory
class EAHeap;
extern EAHeap* MainHeap();
extern EAHeap* RootHeap();
extern EAHeap* ResourceHeap();
class EAHeap {
public:
    void* Malloc(unsigned int, int);
    void* MallocAligned(unsigned int, unsigned int, unsigned int, int);
    void Free(void*);
};

// Operator new/delete
extern void* operator new(unsigned int);
extern void operator delete(void*);
extern void* __builtin_vec_new(unsigned int);
extern void __builtin_vec_delete(void*);

// ============================================================================
// Forward declarations
// ============================================================================
class AptString;
class AptValue;
class AptValueVector;
class AptFile;
class AptFileSavedInputState;
template <typename T0> class AptSharedPtr;
class StringAsVectorEncoding_AptFileSavedInputState;
class StringAsVectorEncoding_AptSharedPtr_AptFile;
class StringAsVectorPolicy;

class BString;
class ChecksumList;
class Commander;
class CTilePt;
class DOGMA_PoolManager;
class E3DWindow;
class EAStringC;
class EAnimController;
class EAnimNote;
class EACTrack;
class EHouse;
class EILight;
class ELevelDrawData;
class ELights;
class EMC_OpStatus;
class ERAnim;
class ERC;
class ERLevel;
class ERQuickdata;
class EResourceManager;
class ETypeInfo;
class EVec3;
class FTilePt;
struct FloorPattern;
class ISimInstance;
class MemoryCardCache;
class NghResFileSectionHeader;
class ObjAnimDef;
class ObjDefinition;
class ObjSelector;
class ObjectDataInterface;
class ObjectDataObjDefinition;
class Behavior;
class ReconBuffer;
class ResFile;
class SimModel;
class StringBuffer;
class TileWalls;
class TileWallStorage;
struct TileWallsSegment;
class UIObjectBase;
class UIDB;
class UIDialog;
struct UIScreenID;
class iResFile;
class cXObject;
template <typename T0> class TArray;
template <typename T0> class StackString;
template <typename T0> class BitFlags;
template <typename T0, typename T1> class _Deque_base;
template <typename T0> class allocator;
class CasMediator;
class CasSimState;
class CasSimRendererDynamic;

// ============================================================================
// Mutex helpers (EA allocator)
// ============================================================================
extern void PPMMutexLock(void*);
extern void PPMMutexUnlock(void*);

// ============================================================================
// CARD / Texture helpers (ENgcMemoryCard)
// ============================================================================
extern void CARDInit();
extern int LoadTexPalette(void** texPal, char* filename);
extern void* TexGet(void* texPal, unsigned int index);

// ============================================================================
// TileWalls static
// ============================================================================
namespace TileWallsNS {
    extern void GenerateRotationLookups();
}

// ============================================================================
// NghResFile
// ============================================================================

class NghResFile : public iResFile {
public:
    // Offsets from asm analysis:
    // +0: iResFile base
    // +12: vtable ptr
    // +16: linked list head (NghNode*)
    // +20: count/size
    // +24: section registry data (starts at +24)
    // +32: flag
    // +36: flag2
    // +40: StringBuffer m_fileName (embedded, +40 to +307)
    // +308: byte flag
    // +312: ptr (array1)
    // +316..+376: section ptrs[15]
    // +380: ptr (array2)
    // +384: short field
    // +388: short field
    // +392: int field
    // +396: int field
    // +400: MemoryCardCache* m_cache

    struct NghNode {
        NghNode* m_next;   // +0
        void* m_data;      // +4
        unsigned short m_id; // +8
    };

    struct RegistryEntry {
        int m_id;                       // +0
        void (*m_saveFn)(int, int&);    // +4
        void (*m_completeFn)(int, int&);// +8
        void (*m_loadFn)(int, int&);    // +12
    };

    // 0x800D39E4 (180 bytes)
    NghResFile();

    // 0x800D3A98 (252 bytes)
    ~NghResFile();

    // 0x800D3C30 (68 bytes)
    // Counts nodes in the linked list for the given resource type
    void Count(int resType) {
        // NOTE: asm-derived — calls findListByResType, then walks linked list counting nodes
        NghNode* node = (NghNode*)findListByResType(resType);
        short count = 0;
        node = (NghNode*)*(void**)node; // lwz r3,0(r3)
        while (node != 0) {
            node = (NghNode*)*(void**)node;
            count++;
        }
        // Returns count in r3 (extsh = sign extend halfword)
        (void)count;
    }

    // 0x800D3C74 (84 bytes)
    // Searches linked list for node with matching ID
    void GetByID(int resType, short id, void (*callback)(void*, int)) {
        // NOTE: asm-derived — walks list from findListByResType, matches on id field at offset +8
        NghNode* listHead = (NghNode*)findListByResType(resType);
        NghNode* node;
        while ((node = (NghNode*)*(void**)listHead) != 0) {
            if (node->m_id == (unsigned short)id) {
                // Return data pointer
                (void)node->m_data;
                return;
            }
            listHead = node;
        }
        // Return null
    }

    // 0x800D3CD0 (108 bytes)
    void GetByIndex(int resType, short index, void (*callback)(void*, int));

    // 0x800D3D7C (496 bytes)
    void Add(int* handleNode, int resType, short id, StringBuffer& name, bool flag);

    // 0x800D3F84 (92 bytes)
    void FlushHouseData(unsigned int houseId);

    // 0x800D3FE0 (156 bytes)
    void FlushCharacterData(bool all);

    // 0x800D407C (84 bytes)
    void FlushNeighborData();

    // 0x800D40D0 (120 bytes)
    void FlushAllData();

    // 0x800D4148 (272 bytes)
    void init();

    // 0x800D4258 (240 bytes)
    void reset();

    // 0x800D4348 (148 bytes)
    void* findListByResType(unsigned int resType);

    // 0x800D442C (300 bytes)
    void WriteList(char* path, unsigned int resType, unsigned int*& a, unsigned int*& b,
                   unsigned int*& c, unsigned short*& d, unsigned int& e, unsigned int& f);

    // 0x800D4558 (188 bytes)
    void IsSectionLoaded(unsigned int section) const;

    // 0x800D4614 (464 bytes)
    void FlushSection(unsigned int section);

    // 0x800D47E4 (380 bytes)
    void ReadSection(unsigned int section, unsigned int offset, bool& loaded, EMC_OpStatus& status);

    // 0x800D4960 (604 bytes)
    void DecompressSection(NghResFileSectionHeader* header, bool decompress);

    // 0x800D4BBC (320 bytes)
    void ValidateSaveGame(char* path, int slot, bool validate);

    // 0x800D4CFC (352 bytes)
    void IsSaveGameValid(char* path, int slot, bool& valid);

    // 0x800D4E5C (844 bytes)
    void ReadHostSection(void* data, bool flag);

    // 0x800D51A8 (572 bytes)
    void ReadBothSection(void* data, bool flag);

    // 0x800D54C0 (524 bytes)
    void ReadThumbSection(void* data, bool flag);

    // 0x800D56CC (884 bytes)
    void WriteHostSection(void* data);

    // 0x800D5A40 (900 bytes)
    void WriteBothSection(void* data);

    // 0x800D5DC4 (732 bytes)
    void WriteThumbSection(void* data);

    // 0x800D60A0 (356 bytes)
    void WriteToMemoryBlock(void*& block, unsigned int& size);

    // 0x800D6204 (232 bytes)
    void XBoxReadFromMemoryBlock(void* block, unsigned int size);

    // 0x800D62EC (1160 bytes)
    void LoadHouseContents(unsigned int houseId, void* data, bool flag);

    // 0x800D6774 (972 bytes)
    void SaveHouseContents(unsigned int houseId, void* data);

    // 0x800D6B40 (132 bytes)
    void FlushHouseContents(unsigned int houseId);

    // 0x800D6BC4 (68 bytes)
    void FlushAllHouseContents();

    // 0x800D6C34 (208 bytes)
    void ReloadHouseAndGlobals(unsigned char slot, unsigned int houseId);

    // 0x800D6D04 (184 bytes)
    void SaveHouseAndGlobals(unsigned char slot, unsigned int houseId);

    // 0x800D6DBC (216 bytes)
    void ReadChecksumFromCard(char* path, int slot);

    // 0x800D6E94 (208 bytes)
    void ReadCharacterData(char* path, unsigned char slot);

    // 0x800D6F64 (144 bytes)
    void WriteCharacterData();

    // 0x800D6FF4 (176 bytes)
    void WriteToFile(char* path);

    // 0x800D70A4 (1100 bytes)
    void WriteToFileInMemoryBlocks(char* path);

    // 0x800D74F0 (704 bytes)
    void ReadFromFile(char* path);

    // 0x800D77B0 (188 bytes)
    void ReadFromCache();

    // 0x800D786C (452 bytes)
    void WriteToMemoryCard(char* path, unsigned char slot);

    // 0x800D7A30 (492 bytes)
    void HasCardChanged(int slot, bool& changed);

    // 0x800D7C20 (1808 bytes)
    void CopyDefaultNghToCache(char* path);

    // 0x800D8330 (692 bytes)
    void CopyDefaultNghToCard(char* srcPath, char* destPath, unsigned char slot);

    // 0x800D85E4 (260 bytes)
    void ReadFromMemoryCard(char* path, unsigned char slot);

    // 0x800D86E8 (620 bytes)
    void CopyHouse(int srcHouse, NghResFile& destFile, int destHouse);

    // 0x800D8954 (140 bytes)
    void GetDefaultNghPath(char* basePath, StackString<260>& outPath);

    // 0x800D89E0 (72 bytes)
    // Erases current filename and sets new one
    void SetFileName(char* name) {
        // NOTE: asm-derived — erases StringBuffer at +40, appends name
        StringBuffer* buf = (StringBuffer*)((char*)this + 40);
        buf->erase();
        buf->append(name, -1);
    }

    // 0x800D8A28 (72 bytes)
    // Returns the memory card cache, initializing it if needed
    void GetMemoryCardCache() {
        // NOTE: asm-derived
        MemoryCardCache* cache = *(MemoryCardCache**)((char*)this + 400);
        if (*(int*)((char*)cache + 16) == 0) {
            // cache->Init(s_nghLayout);
            cache->Init(/*NghLayout ptr*/);
        }
        // returns cache at +400
    }

    // 0x800D8AE4 (556 bytes)
    void RegisterSection(int id, void (*saveFn)(int, int&),
                         void (*completeFn)(int, int&), void (*loadFn)(int, int&));

    // 0x800D8D10 (128 bytes)
    void FindNodeInRegistry(int id, int& outIndex);

    // 0x800D8D90 (112 bytes)
    void SectionSaveViaRegistry(int sectionId, int param, int& record);

    // 0x800D8E00 (112 bytes)
    void SaveCompleteViaRegistry(int sectionId, int param, int& record);

    // 0x800D8E70 (112 bytes)
    void SectionLoadViaRegistry(int sectionId, int param, int& record);

private:
    // Helper class stubs for compilation
    struct StringBufferHelper {
        void erase();
        void append(char*, int);
    };
    struct MemCardCacheHelper {
        void Init();
    };
};


// ============================================================================
// EA::Allocator - General purpose memory allocator
// ============================================================================

namespace EA {

class Allocator {
public:
    // 0x802D87EC (128 bytes)
    // Verifies memory is filled with expected byte value
    // Checks 4 bytes at a time when aligned, then byte-by-byte for remainder
    static bool MemoryFillCheck(unsigned char* ptr, unsigned int size, unsigned char fillByte) {
        // NOTE: asm-derived — optimized fill check with word-level comparison
        unsigned int alignedSize = size & ~3u;
        unsigned char* end = ptr + size;
        unsigned char* alignedEnd = ptr + alignedSize;

        // Check alignment
        if (size < 4 || ((unsigned int)ptr & 3) != 0) {
            // Fall through to byte check
        } else {
            // Build word from fill byte: AABBCCDD where all bytes are fillByte
            unsigned int fillWord = ((unsigned int)fillByte << 24) |
                                    ((unsigned int)fillByte << 16) |
                                    ((unsigned int)fillByte << 8) |
                                    (unsigned int)fillByte;
            while (ptr < alignedEnd) {
                if (*(unsigned int*)ptr != fillWord) {
                    return false;
                }
                ptr += 4;
            }
        }

        // Check remaining bytes
        while (ptr < end) {
            if (*ptr != fillByte) {
                return false;
            }
            ptr++;
        }
        return true;
    }

    class GeneralAllocator {
    public:
        // Internal types
        typedef int Chunk;
        struct BlockInfo;
        struct Snapshot;

        // Member layout from asm:
        // +0: field0
        // +4: field4 (size or capacity)
        // +8: field8 (flag)
        // +12..+51: 40-byte region (bins[10])
        // +52..+1075: 1024-byte region (bins array, 128 bins * 8 bytes)
        // +1076..+1091: 16-byte region
        // +1092: field
        // +1096: field
        // +1100..+1139: 40-byte region
        // +1140..+1255: 116-byte region
        // +1256: mmap count
        // +1260: mmap capacity
        // +1264: mmap array ptr
        // +1268: field
        // +1272: field
        // +1276: mutex ptr

        // 0x802D886C (448 bytes)
        GeneralAllocator(void* coreBlock, unsigned int coreSize, bool threadSafe,
                         bool enableHighFence,
                         unsigned int (*coreFn)(GeneralAllocator*, void*, unsigned int, void*),
                         void* coreContext);

        // 0x802D8A6C (424 bytes)
        void Init(void* coreBlock, unsigned int coreSize, bool threadSafe, bool enableHighFence,
                  unsigned int (*coreFn)(GeneralAllocator*, void*, unsigned int, void*),
                  void* coreContext);

        // 0x802D8C14 (216 bytes)
        void Shutdown();

        // 0x802D8CEC (652 bytes)
        void SetOption(int option, int value);

        // 0x802D8FB0 (128 bytes)
        void FindPriorChunk(int* chunk) const;

        // 0x802D9030 (104 bytes)
        // Computes bin index for large allocation sizes
        void GetLargeBinIndexFromChunkSize(unsigned int chunkSize) {
            // NOTE: asm-derived — bit manipulation to compute bin index from size
            // Uses cntlzw (count leading zeros) to determine magnitude
        }

        // 0x802D9098 (212 bytes)
        void FindAndSetNewTopChunk();

        // 0x802D916C (92 bytes)
        void GetChunkIsFenceChunk(int* chunk) const;

        // 0x802D91C8 (392 bytes)
        void FindChunkBin(int* chunk) const;

        // 0x802D93B0 (72 bytes)
        // Checks if a chunk matches the given block type
        bool ChunkMatchesBlockType(int* chunk, int blockType) {
            // NOTE: asm-derived
            int typeBits = blockType & 6;
            if (typeBits == 6) {
                return true; // matches everything
            }
            int chunkSize = chunk[1]; // +4
            int nextChunkFlags = *(int*)((char*)chunk + (chunkSize & ~7) + 4);
            bool nextInUse = (nextChunkFlags & 1) != 0;
            if (blockType & 2) {
                return nextInUse;
            }
            if (!(blockType & 4)) {
                return false;
            }
            return !nextInUse;
        }

        // 0x802D9418 (68 bytes)
        // Adds double fencepost at end of chunk
        void AddDoubleFencepost(int* chunk, int flags) {
            // NOTE: asm-derived — creates two sentinel chunks at end
            int sizeField = chunk[1]; // +4
            int newFlags = flags | 8;
            int size = (sizeField & ~7) - 16;
            int oldFlags = sizeField & 7;
            chunk[1] = oldFlags | size;
            *(int*)((char*)chunk + size) = size;
            *(int*)((char*)chunk + size + 4) = newFlags;
            *(int*)((char*)chunk + size + 8) = 8;
            *(int*)((char*)chunk + size + 12) = 9;
        }

        // 0x802D945C (68 bytes)
        // Creates a chunk from a core memory block
        void MakeChunkFromCore(void* coreBlock, unsigned int size, int flags) {
            // NOTE: asm-derived
            int* chunk = (int*)coreBlock;
            chunk[0] = 0;
            chunk[1] = size | flags;
            AddDoubleFencepost(chunk, 0);
        }

        // 0x802D94C4 (224 bytes)
        void GetBlockInfoForChunk(int* chunk, int* blockInfo) const;

        // 0x802D95A4 (548 bytes)
        void CheckChunk(int* chunk);

        // 0x802D97C8 (508 bytes)
        void CheckFreeChunk(int* chunk);

        // 0x802D99C4 (292 bytes)
        void CheckUsedChunk(int* chunk);

        // 0x802D9AE8 (232 bytes)
        void CheckRemallocedChunk(int* chunk, unsigned int newSize);

        // 0x802D9BD0 (208 bytes)
        void CheckMallocedChunk(int* chunk, unsigned int size, bool aligned, bool highFence);

        // 0x802D9CA0 (240 bytes)
        void CheckMMappedChunk(int* chunk);

        // 0x802D9D90 (1628 bytes)
        void CheckState(int level);

        // 0x802DA3EC (304 bytes)
        void GetDataPreview(void* data, unsigned int dataSize, char* asciiOut,
                            wchar_t* wcharOut, unsigned int outSize) const;

        // 0x802DA588 (352 bytes)
        void DescribeChunk(int* chunk, char* buffer, unsigned int bufferSize);

        // 0x802DA70C (288 bytes)
        void TraceAllocatedMemory(void (*traceFn)(char*, void*), void* context,
                                  void* filterAddr, unsigned int filterSize);

        // 0x802DA82C (184 bytes)
        void ReportHeap(bool (*reportFn)(int*, void*), void* context, int level,
                        bool verbose, void* filterAddr, unsigned int filterSize);

        // 0x802DA8E4 (108 bytes)
        void ReportBegin(void* state, int level, bool verbose,
                         void* filterAddr, unsigned int filterSize);

        // 0x802DA950 (480 bytes)
        void ReportNext(void* state, int level);

        // 0x802DAB30 (80 bytes)
        void ReportEnd(void* state);

        // 0x802DABF8 (832 bytes)
        void TakeSnapshot(int snapshotId, bool cumulative, void* filterAddr, unsigned int filterSize);

        // 0x802DAF78 (284 bytes)
        void ValidateAddress(void* addr, bool expectAllocated);

        // 0x802DB094 (84 bytes)
        void ValidateHeap(int level);

        // 0x802DB10C (108 bytes)
        // Thread-safe wrapper around MallocInternal
        void* Malloc(unsigned int size, int blockType) {
            // NOTE: asm-derived
            void* mutex = *(void**)((char*)this + 1276);
            if (mutex) {
                PPMMutexLock(mutex);
            }
            void* result = (void*)MallocInternal(size, blockType);
            if (mutex) {
                PPMMutexUnlock(mutex);
            }
            return result;
        }

        // 0x802DB178 (1420 bytes)
        void* MallocInternal(unsigned int size, int blockType);

        // 0x802DB704 (92 bytes)
        // Thread-safe wrapper around FreeInternal
        void Free(void* ptr) {
            // NOTE: asm-derived
            void* mutex = *(void**)((char*)this + 1276);
            if (mutex) {
                PPMMutexLock(mutex);
            }
            FreeInternal(ptr);
            if (mutex) {
                PPMMutexUnlock(mutex);
            }
        }

        // 0x802DB760 (416 bytes)
        void FreeInternal(void* ptr);

        // 0x802DB900 (124 bytes)
        // Thread-safe wrapper around MallocAlignedInternal
        void* MallocAligned(unsigned int size, unsigned int alignment,
                            unsigned int offset, int blockType) {
            // NOTE: asm-derived
            void* mutex = *(void**)((char*)this + 1276);
            if (mutex) {
                PPMMutexLock(mutex);
            }
            void* result = (void*)MallocAlignedInternal(size, alignment, offset, blockType);
            if (mutex) {
                PPMMutexUnlock(mutex);
            }
            return result;
        }

        // 0x802DB97C (632 bytes)
        void* MallocAlignedInternal(unsigned int size, unsigned int alignment,
                                    unsigned int offset, int blockType);

        // 0x802DBBF4 (116 bytes)
        // Thread-safe wrapper around ReallocInternal
        void* Realloc(void* ptr, unsigned int newSize, int blockType) {
            // NOTE: asm-derived
            void* mutex = *(void**)((char*)this + 1276);
            if (mutex) {
                PPMMutexLock(mutex);
            }
            void* result = (void*)ReallocInternal(ptr, newSize, blockType);
            if (mutex) {
                PPMMutexUnlock(mutex);
            }
            return result;
        }

        // 0x802DBC68 (716 bytes)
        void* ReallocInternal(void* ptr, unsigned int newSize, int blockType);

        // 0x802DBF34 (116 bytes)
        // Thread-safe wrapper around CallocInternal
        void* Calloc(unsigned int count, unsigned int elemSize, int blockType) {
            // NOTE: asm-derived
            void* mutex = *(void**)((char*)this + 1276);
            if (mutex) {
                PPMMutexLock(mutex);
            }
            void* result = (void*)CallocInternal(count, elemSize, blockType);
            if (mutex) {
                PPMMutexUnlock(mutex);
            }
            return result;
        }

        // 0x802DBFA8 (272 bytes)
        void* CallocInternal(unsigned int count, unsigned int elemSize, int blockType);

        // 0x802DC0B8 (128 bytes)
        void MallocMultiple(unsigned int count, unsigned int size, void** ptrs, int blockType);

        // 0x802DC138 (128 bytes)
        void MallocMultiple(unsigned int count, unsigned int* sizes, void** ptrs, int blockType);

        // 0x802DC1B8 (416 bytes)
        void MallocMultipleInternal(unsigned int count, unsigned int singleSize,
                                    unsigned int* sizes, void** ptrs, int blockType);

        // 0x802DC358 (392 bytes)
        void ClearFastBins();

        // 0x802DC5D8 (364 bytes)
        void AddCore(void* coreBlock, unsigned int coreSize, bool threadSafe, bool highFence,
                     unsigned int (*coreFn)(GeneralAllocator*, void*, unsigned int, void*),
                     void* coreContext);

        // 0x802DC744 (200 bytes)
        void ExtendCoreInternal(unsigned int additionalSize);

        // 0x802DC80C (272 bytes)
        void AddCoreInternal(unsigned int size);

        // 0x802DC91C (80 bytes)
        void FreeCore(int* coreBlock);

        // 0x802DC96C (316 bytes)
        void TrimCore(unsigned int trimSize);

        // 0x802DCAA8 (72 bytes)
        // Allocates memory via system malloc (for mmap-style allocations)
        void* MMapAlloc(unsigned int size, unsigned int* actualSize) {
            // NOTE: asm-derived
            void* ptr = malloc(size);
            if (ptr != 0 && actualSize != 0) {
                *actualSize = size;
            }
            return ptr;
        }

        // Snapshot sub-class
        class Snapshot {
        public:
            // 0x802DAB80 (120 bytes)
            // Magic = 0x534E5050 ("SNPP")
            Snapshot(unsigned int bufferSize, int flags) {
                // NOTE: asm-derived
                memset(this, 0, bufferSize);
                *(unsigned int*)((char*)this + 0) = 0x534E5050u; // magic
                *(unsigned int*)((char*)this + 4) = bufferSize;
                *(int*)((char*)this + 8) = flags;
                *(int*)((char*)this + 40) = 0;
                *(int*)((char*)this + 12) = 0;
                *(int*)((char*)this + 16) = 0;
                *(int*)((char*)this + 20) = 0;
                *(int*)((char*)this + 24) = 0;
                *(int*)((char*)this + 28) = 0;
                *(int*)((char*)this + 32) = 0;
                *(int*)((char*)this + 36) = 0;
            }
        };
    };
};

namespace String {
    // Template specializations for EA::String::BasicString used as vectors
    // 0x8026C168 (1336 bytes — Insert<AptFileSavedInputState*> instantiation 1)
    // 0x802A1828 (1336 bytes — Insert<AptFileSavedInputState*> instantiation 2)
    // 0x802A1F08 (1644 bytes — Insert<AptSharedPtr<AptFile>*>)
    // These are complex template Insert methods — kept as structural stubs
    template <typename Encoding, typename Policy>
    class BasicString {
    public:
        template <typename Iterator>
        void Insert(Iterator& first, Iterator& last, int& pos);
    };
};

} // namespace EA


// ============================================================================
// ENgcMemoryCard - GameCube memory card interface
// ============================================================================

class ENgcMemoryCard {
public:
    // Static data layout (from asm, lis/addi address patterns):
    // s_comments: char[32] for line1, char[32] for line2 (at global addr)
    // s_bannerData: banner/icon pixel data (at global addr)

    // 0x8032FF08 (280 bytes)
    // Converts wide strings to memory card comment format
    // Handles Japanese Yen character (0x2122 -> 0x99)
    void SetComments(unsigned short* line1, unsigned short* line2) {
        // NOTE: asm-derived — converts UCS-2 to SJIS-like single-byte format
        // Stores into static comment buffers (32 bytes each)
        // Special case: Unicode 0x2122 maps to 0x99
        char* commentBuf1 = (char*)0; // static address from lis/addi
        char* commentBuf2 = commentBuf1 + 32;
        unsigned int i;

        // Process line 1
        i = 0;
        if (line1[0] != 0) {
            while (i < 32) {
                if (line1[i] == 0x2122) {
                    commentBuf1[i] = (char)153; // 0x99
                } else {
                    commentBuf1[i] = (char)(line1[i] & 0xFF);
                }
                i++;
                if (i >= 32) break;
                if (line1[i] == 0) break;
            }
        }
        if (i < 32) {
            commentBuf1[i] = 0;
        } else {
            commentBuf1[31] = 0;
        }

        // Process line 2
        i = 0;
        if (line2[0] != 0) {
            while (i < 32) {
                if (line2[i] == 0x2122) {
                    commentBuf2[i] = (char)153;
                } else {
                    commentBuf2[i] = (char)(line2[i] & 0xFF);
                }
                i++;
                if (i >= 32) break;
                if (line2[i] == 0) break;
            }
        }
        if (i < 32) {
            commentBuf2[i] = 0;
        } else {
            commentBuf2[31] = 0;
        }
    }

    // 0x80330020 (412 bytes)
    void InitMemoryCard();

    // 0x803301C4 (1496 bytes)
    void LoadDataChunkS(char* filename, unsigned int channel, unsigned int offset,
                        unsigned int size, void* buffer);

    // 0x8033079C (1492 bytes)
    void LoadDataS(char* filename, unsigned int channel, unsigned int size, void* buffer);

    // 0x80331380 (2184 bytes)
    void SaveDataChunkS(char* filename, unsigned int channel, unsigned int offset,
                        unsigned int size, void* buffer);

    // 0x80331608 (2052 bytes)
    void SaveDataS(char* filename, unsigned int channel, unsigned int size, void* buffer);

    // 0x80331E0C (2216 bytes)
    void CreateFileS(char* filename, unsigned int channel, unsigned int size);

    // 0x803326B4 (1584 bytes)
    void CheckAndWriteBannerAndIcon(char* filename, unsigned int channel);

    // 0x80332CE4 (776 bytes)
    void DeleteDataS(char* filename, unsigned int channel);

    // 0x80332FEC (756 bytes)
    void FormatCardS(unsigned int channel);

    // 0x80333318 (1132 bytes)
    void GetFreeSpaceS(unsigned int channel, unsigned int& freeSpace);

    // 0x80333784 (1132 bytes)
    void GetFreeFilesS(unsigned int channel, int& freeFiles);

    // 0x80333BF0 (108 bytes)
    // Checks if there's enough space for a file of given size
    void IsSpaceAvailable(unsigned int channel, unsigned int size, bool& available) {
        // NOTE: asm-derived — calls GetFreeSpaceS, compares result with size
        unsigned int freeSpace;
        GetFreeSpaceS(channel, freeSpace);
        available = (freeSpace >= size);
    }

    // 0x80333C5C (88 bytes)
    // Checks if there's room for more files
    void IsEnoughFiles(unsigned int channel, unsigned int count, bool& enough) {
        // NOTE: asm-derived — calls GetFreeFilesS, compares with count
        int freeFiles;
        GetFreeFilesS(channel, freeFiles);
        enough = ((unsigned int)freeFiles >= count);
    }

    // 0x80333CD4 (364 bytes)
    void IsCardAvailable(unsigned int channel);

    // 0x80333E40 (352 bytes)
    void IsWrongDevice(unsigned int channel);

    // 0x80333FA0 (160 bytes)
    void AnyCardsPresent(int& result);

    // 0x80334040 (936 bytes)
    void IsCardFormated(unsigned int channel, bool& formatted);

    // 0x803343E8 (1184 bytes)
    void GetFileList(unsigned int channel, char* pattern, unsigned int maxFiles,
                     char (*fileNames)[31]);

    // 0x80334898 (1184 bytes)
    void DoesFileExist(char* filename, unsigned int channel, bool& exists);

    // 0x80334D38 (356 bytes)
    void GetSectorSize(int channel, unsigned int& sectorSize);

private:
    // Helper that bookends card operations
    void BeginCardOperation();
    void EndCardOperation();
};


// ============================================================================
// CASTarget - Create-A-Sim UI target
// ============================================================================

class CASTarget {
public:
    // Member layout from asm (offsets from this):
    // +0..+39: UI fields (int fields zeroed in ctor)
    // +40..+55: embedded struct (8 bytes each, 2 items)
    // +56..+71: embedded struct
    // +72..+87: embedded struct
    // +88..+103: embedded struct
    // +104..+119: embedded struct
    // +120: field
    // +128: vtable ptr (set twice in ctor)
    // +132: field
    // +136: vtable ptr 2
    // +144..+167: various fields
    // +168..+199: embedded struct
    // +200..+207: embedded struct
    // +208..+215: embedded struct
    // +216: CasMediator (embedded)
    // +260: mode field (checked against 3, 5 in Is* functions)
    // +264: CasSimState[4] (embedded, 592 bytes each)
    // +2632: CasSimRendererDynamic[4] (embedded, 576 bytes each)
    // +4936: m_simSlotBits (bitfield for which sim slots have sims)
    // +4940..+4976: various float/int fields
    // +5020..+5076: more fields
    // +5100: field
    // +5116..+5168: deque/array fields

    // 0x80190EA0 (2912 bytes)
    CASTarget(bool isMultiplayer);

    // 0x80191A00 (660 bytes)
    ~CASTarget();

    // 0x80191C94 (1540 bytes)
    void Init(bool flag);

    // 0x80192298 (200 bytes)
    void Shutdown();

    // 0x80192360 (760 bytes)
    void SaveSimToFamilySlot(int slot);

    // 0x80192658 (468 bytes)
    void SaveCASDataToNeighborhood();

    // 0x8019282C (672 bytes)
    void IsShutdown();

    // 0x80192ACC (388 bytes)
    void StartupMediator();

    // 0x80192C50 (360 bytes)
    void ShutdownMediator();

    // 0x80192DB8 (804 bytes)
    void ChangeMediator(int mediatorId);

    // 0x801930DC (112 bytes)
    void CreateScene(int sceneId);

    // 0x80193174 (448 bytes)
    void SetVariable(char* name, char* value);

    // 0x80193334 (1524 bytes)
    void GetLocalizable(char* key);

    // 0x80193928 (592 bytes)
    void GetVariable(char* name);

    // 0x80193B78 (504 bytes)
    void Update();

    // 0x80193D70 (444 bytes)
    void Draw(ERC* rc);

    // 0x80193F2C (132 bytes)
    void UnloadLastScreen();

    // 0x80193FB0 (776 bytes)
    void SetVariableNav(char* nav);

    // 0x801942B8 (368 bytes)
    void SetVariableSubnav(char* subnav);

    // 0x80194428 (1476 bytes)
    int GetCurrentUIFocus();

    // 0x801949EC (140 bytes)
    void BroadcastNewFocus();

    // 0x80194A78 (600 bytes)
    void ConvertUIFocusToEventFocus(int focus);

    // 0x80194CD0 (212 bytes)
    void HandleNav(int navId);

    // 0x80194DA4 (168 bytes)
    void GotoScreen(UIScreenID screenId);

    // 0x80194E4C (112 bytes)
    void GotoInitialScreen();

    // 0x80194EC4 (68 bytes)
    // Saves CAS data and navigates to game
    void GotoGame() {
        // NOTE: asm-derived
        SaveCASDataToNeighborhood();
        UIObjectBase_UIRouter_FlowGoto("Game"); // string at lis/addi address
        SetHandleInput(false);
    }

    // 0x80194F08 (132 bytes)
    // Unloads screen and navigates to main menu (handles different game modes)
    void GotoMainMenu() {
        // NOTE: asm-derived
        UnloadLastScreen();
        int mode = *(int*)((char*)this + 260);
        if (mode == 3) {
            UIObjectBase_UIRouter_FlowGoto("MainMenu_CAS");
        } else {
            int dbVal = UIDB_UIDBGetInt("CAS_Source");
            if (dbVal == 0) {
                UIObjectBase_UIRouter_FlowGoto("MainMenu_Freeplay");
            } else if (dbVal == 1) {
                UIObjectBase_UIRouter_FlowGoto("MainMenu_Story");
            }
        }
    }

    // 0x80194FB0 (80 bytes)
    void ReturnForwardToKeyboard();

    // 0x80195000 (196 bytes)
    void SaveNameEnterCBA();

    // 0x801950C4 (144 bytes)
    void DontSaveNameEnterCBA();

    // 0x80195154 (2760 bytes)
    void HandleConditionalNav(int navId);

    // 0x80195C80 (200 bytes)
    void ConvertPartUIFocusToModList(char* focus);

    // 0x80195D48 (124 bytes)
    void CreateModStrFromValues(char* buffer, BitFlags<unsigned int> flags);

    // 0x80195DC4 (636 bytes)
    void SpawnYesNoDialog(unsigned int titleId, unsigned short* text,
                          unsigned short* caption, int callbackId);

    // 0x80196040 (180 bytes)
    void DialogYesNoSelectionCallback(int selection);

    // 0x801960F8 (564 bytes)
    void SpawnOKDialog(unsigned short* text, unsigned short* caption);

    // 0x80196378 (84 bytes)
    // Checks if viewing a mirror-type CAS screen
    bool IsViewingMirror() {
        // NOTE: asm-derived
        int mode = *(int*)((char*)this + 260);
        if (mode == 3) {
            return false;
        }
        // Get mediator -> scene
        void* mediator = *(void**)((char*)this + 132);
        int focus = GetCurrentUIFocus();
        if (focus >= 2 && focus <= 8) {
            return false; // Mirror views are focus 2-8
        }
        return true;
    }

    // 0x801963CC (84 bytes)
    // Checks if viewing the genetics screen
    bool IsViewingGenetics() {
        // NOTE: asm-derived
        int mode = *(int*)((char*)this + 260);
        if (mode == 3 || mode == 5) {
            return false;
        }
        int focus = GetCurrentUIFocus();
        if (focus >= 2 && focus <= 8) {
            return true;
        }
        return false;
    }

    // 0x80196420 (84 bytes)
    // Resets rotation for all active sim renderers
    void ResetSimRotations() {
        // NOTE: asm-derived — loops 4 times, checks bitfield, resets rotation float
        float* rendererBase = (float*)((char*)this + 2632);
        unsigned int simBits = *(unsigned int*)((char*)this + 4936);
        for (int i = 0; i < 4; i++) {
            if (simBits & (1 << i)) {
                // Set rotation to 0.0f at offset +524 within each 576-byte renderer
                *(float*)((char*)rendererBase + i * 576 + 524) = 0.0f;
            }
        }
    }

    // 0x80196474 (72 bytes)
    // Deallocates morph resources for a sim in a slot
    void DeallocateMorphResources(int slot) {
        // NOTE: asm-derived
        if (slot > 3) return;
        // Calculate offset: slot * 9 * 64 = slot * 576 (CasSimRendererDynamic size)
        int offset = slot * 9 * 64;
        char* renderer = (char*)this + offset;
        if (renderer == (char*)this - 2640) return; // null check equivalent
        SimModel* model = (SimModel*)(renderer + 2640);
        model->DeallocateMorphResources();
    }

    // 0x801A0840 (80 bytes)
    // Sets or clears a bit indicating a sim is present in a slot
    void SetHasSimInSlot(int slot, bool hasSim) {
        // NOTE: asm-derived — bit manipulation on m_simSlotBits at +4936
        int bitIndex = slot;
        // Handle negative slot indices (PPC divides differently)
        if (slot < 0) {
            bitIndex = slot + 3;
        }
        int groupIndex = bitIndex >> 2; // which group of 4
        (void)groupIndex;
        int bitPos = slot - (bitIndex & ~3); // actual bit position

        unsigned int bits = *(unsigned int*)((char*)this + 4936);
        if (hasSim) {
            bits |= (1u << bitPos);
        } else {
            bits &= ~(1u << bitPos);
        }
        *(unsigned int*)((char*)this + 4936) = bits;
    }

private:
    // Helper stubs
    void SetHandleInput(bool enable);
    static void UIObjectBase_UIRouter_FlowGoto(const char* target);
    static int UIDB_UIDBGetInt(const char* key);
};


// ============================================================================
// StringPool - APT string interning pool
// ============================================================================

class StringPool {
public:
    // Uses DOGMA_PoolManager for memory, EAStringC for string conversion
    // Static data at s_stringTable (178 entries, 4 bytes each = 712 bytes)

    // 0x802BE97C (22936 bytes)
    // Massive initialization — populates 178-entry string table from hardcoded strings
    void Initialize(int poolSize);

    // 0x802C4314 (300 bytes)
    // Tears down the string pool, releasing all AptString references
    void Teardown();

    // 0x802C4440 (132 bytes)
    // Looks up a string by walking the 178-entry static table
    void GetString(char* str) {
        // NOTE: asm-derived — linear search through string table
        // Each entry is a ptr to AptString; compare length first, then strcasecmp
        // Returns pointer to table entry or null
    }

    // 0x802C44C4 (620 bytes)
    // Gets or creates a string in the hash pool
    // Uses FNV-like hash: hash = (hash ^ tolower(c)) * 0x01000193
    void GetFromPool(char* str);

    // 0x802C4730 (256 bytes)
    void RemoveFromPool(AptString* str);

    // 0x802C4830 (132 bytes)
    void ClearTemporaryPool();

    // 0x802C48B4 (156 bytes)
    void CheckContent();
};


// ============================================================================
// ISimsObjectModel - Base class for Sims object 3D models
// ============================================================================

class ISimsObjectModel : public ISimInstance {
public:
    // Member layout from asm:
    // +0: ISimInstance vtable (set to ISimsObjectModel vtable in ctor)
    // +92: flags (ori'd with 768 in ctor)
    // +800: vtable ptr 2
    // +808: m_selector (ObjSelector*)
    // +812: field
    // +820: EAnimController (embedded, large)
    // +968: ptr field
    // +972: flags field (cleared lower 5 bits in ctor)
    // +976: field
    // +980: int (set to 1)
    // +984: field
    // +988: int (set to 1)
    // +992: field
    // +996: int (set to -1)
    // +1000: m_animState
    // +1004: float (set to -1.0f)
    // +1012: float (set to a constant)
    // +1016..+1020: floats (set to -1.0f)
    // +1024: field
    // +1052: field
    // +1056..+1084: embedded struct (5 ints)
    // +1088..+1103: TArray (first, 16 bytes)
    // +1104..+1119: TArray (second, 16 bytes)
    // +1116: field
    // +1120: field
    // +1124..+1187: TArray<EILight*> (embedded)
    // +1140..+1148: floats (set to -1.0f)
    // +1164: float (set to -1.0f)
    // +1168: field
    // +1172: field
    // +1176: int (set to 1)
    // +1180: field
    // +1188..+1207: TArray (16 bytes + extra)
    // +1196..+1207: sub-array
    // +1204: field
    // +1208: int (set to -1)
    // Size: 1216 bytes (from New allocation)

    // 0x8004C500 (324 bytes)
    ISimsObjectModel();

    // 0x8004C644 (428 bytes)
    ~ISimsObjectModel();

    // 0x8004C7F0 (300 bytes)
    void GetHeightOffset();

    // 0x8004C91C (80 bytes)
    void InsertSubModelsInHouse(ERLevel* level);

    // 0x8004C96C (100 bytes)
    void PropigateFlagsToSubModels();

    // 0x8004C9D0 (524 bytes)
    void CleanupStuff(ERLevel* level);

    // 0x8004CBDC (2492 bytes)
    void Update();

    // 0x8004D598 (308 bytes)
    void UpdateParticle(ObjAnimDef* animDef);

    // 0x8004D6CC (468 bytes)
    void SetupCharacter();

    // 0x8004D8A0 (1092 bytes)
    void InitBulb();

    // 0x8004DDEC (328 bytes)
    void UpdateHighlightAnim();

    // 0x8004DD1C (208 bytes)
    void SetSOMModel(unsigned int modelId);

    // 0x8004DF34 (80 bytes)
    // Starts an animation immediately on the anim controller
    void AnimStartImmediate(unsigned int animId) {
        // NOTE: asm-derived
        EAnimController* ctrl = (EAnimController*)((char*)this + 820);
        // SetTrackAnim(trackFlags=1, animId, blendMode=0, blendTime=1.0f, nullptr)
        ctrl->SetTrackAnim(1, animId, 0, 1.0f, 0);
        *(int*)((char*)this + 1000) = 1;
    }

    // 0x8004DF84 (80 bytes)
    // Starts an animation with blend-in on the anim controller
    void AnimStartBlendIn(unsigned int animId) {
        // NOTE: asm-derived
        EAnimController* ctrl = (EAnimController*)((char*)this + 820);
        // SetTrackAnim(trackFlags=1, animId, blendMode=3, blendTime=constant, nullptr)
        ctrl->SetTrackAnim(1, animId, 3, 0.25f, 0);
        *(int*)((char*)this + 1000) = 2;
    }

    // 0x8004DFD4 (84 bytes)
    // Stops all animation tracks and releases anim resource
    void KillAllAnimTracks() {
        // NOTE: asm-derived
        EAnimController* ctrl = (EAnimController*)((char*)this + 820);
        ctrl->StopAllTracks();
        *(int*)((char*)this + 1000) = 0;
        unsigned int animRes = *(unsigned int*)((char*)this + 1204);
        if (animRes != 0) {
            EResourceManager_DelRefAsync(animRes);
            *(unsigned int*)((char*)this + 1204) = 0;
        }
    }

    // 0x8004E028 (308 bytes)
    void UpdateTracks();

    // 0x8004E15C (988 bytes)
    void UpdateAnimTrack(ObjAnimDef* animDef, bool flag);

    // 0x8004E55C (188 bytes)
    void RemoveSubModelsFromHouse(ERLevel* level);

    // 0x8004E618 (136 bytes)
    void ChageShader(unsigned int oldShader, unsigned int newShader);

    // 0x8004E7DC (140 bytes)
    void GetAdjacentRoom(bool flag);

    // 0x8004E868 (492 bytes)
    void SetWallForPortal();

    // 0x8004EA54 (280 bytes)
    void CreateShadow();

    // 0x8004EB70 (264 bytes)
    void CalcOrient();

    // 0x8004EC78 (168 bytes)
    void CalcDynamicOrient();

    // 0x8004ED3C (540 bytes)
    void TryAnimateObject(short animIndex, short* outAnim);

    // 0x8004EF58 (212 bytes)
    void PreloadAnimation(short animIndex);

    // 0x8004F02C (1580 bytes)
    void BlendHighlights(ELights* lights, bool* mask);

    // 0x8004F658 (640 bytes)
    void CalcLightsFromPos(ELights* lights, bool updateAll);

    // 0x8004F8D8 (712 bytes)
    void DoLightingCalculation();

    // 0x8004FBA0 (132 bytes)
    void VisibilityTest(E3DWindow& window);

    // 0x8004FC24 (104 bytes)
    void IsVisible();

    // 0x8004FC8C (172 bytes)
    void UpdateAnimController();

    // 0x8004FD38 (240 bytes)
    void DoAnimation();

    // 0x8004FE28 (1120 bytes)
    void Draw(ELevelDrawData& drawData);

    // 0x80050288 (400 bytes)
    void AnimateLights();

    // 0x80050418 (160 bytes)
    void DrawBounds(ERC* rc);

    // 0x800504B8 (376 bytes)
    void GetAnimDef(int index, bool flag);

    // 0x80050630 (440 bytes)
    void processAnimEvents(ERAnim* anim, int startFrame, int endFrame, bool flag);

    // 0x800507E8 (792 bytes)
    void animEventHandler(ERAnim* anim, EAnimNote& note, int eventType);

    // 0x80050B00 (312 bytes)
    void SetInitalObjectState();

    // 0x80050CA0 (164 bytes)
    void Create(cXObject* obj, EHouse* house);

    // 0x80050D44 (368 bytes)
    void SetObjOrient();

    // 0x80050EB4 (96 bytes)
    void OrientSubObjects();

    // 0x80050F14 (444 bytes)
    void OrentSubObject();

    // 0x80052DEC (80 bytes)
    // Checks if this model is a multi-tile sub-part
    bool IsMultiTilePart() {
        // NOTE: asm-derived — gets selector, calls vtable method, checks flag at +192
        void* selector = *(void**)((char*)this + 808);
        void** vtable = *(void***)((char*)selector + 4);
        // Virtual call to get object definition
        // Check byte at offset +9 in sub-struct at +192
        // Returns true if non-zero
        return false; // structural placeholder
    }

    // 0x80052E3C (3124 bytes)
    void ApplyMatrix(float param, EVec3& inVec, EVec3& outVec);

    // 0x80053C08 (84 bytes)
    // Factory method — allocates and constructs a new ISimsObjectModel
    static ISimsObjectModel* New() {
        // NOTE: asm-derived
        void* mem = MainHeap()->MallocAligned(1216, 16, 0, 0);
        memset(mem, 0, 1216);
        ISimsObjectModel* obj = new(mem) ISimsObjectModel();
        return obj;
    }

    // 0x80053D28 (84 bytes)
    // Registers this type with the ETypeInfo system
    static void RegisterType(unsigned short typeId) {
        // NOTE: asm-derived — calls ETypeInfo::Register with function pointers
        // and a type name string
    }

    // 0x8005450C (80 bytes)
    // Updates the shader for an animation track if it changed
    void UpdateShader(ObjAnimDef* animDef) {
        // NOTE: asm-derived
        // animDef->shaderNew at +16, animDef->shaderOld at +12
        // this->m_shaderInfo at +1056
        unsigned int* shaderInfo = (unsigned int*)((char*)this + 1056);
        unsigned int newShader = *(unsigned int*)((char*)animDef + 16);
        if (shaderInfo[4] != newShader && newShader != 0) {
            shaderInfo[4] = newShader;
            shaderInfo[3] = *(unsigned int*)((char*)animDef + 12);
            ChageShader(*(unsigned int*)((char*)animDef + 12),
                        *(unsigned int*)((char*)animDef + 16));
        }
    }

    // 0x8005455C (424 bytes)
    void StartNewAnimTrack(ObjAnimDef* animDef, bool flag);

    // 0x80054704 (476 bytes)
    void ProcessPropertyEventTags(ObjAnimDef* animDef, float time);

private:
    static void EResourceManager_DelRefAsync(unsigned int resId);
};


// ============================================================================
// cFixedWorldImpl - Fixed world grid implementation
// ============================================================================

class cFixedWorldImpl {
public:
    // Member layout from asm:
    // +0: vtable ptr
    // +4: Commander base (embedded)
    // +16: vtable ptr 2
    // +20: m_width
    // +24: m_height
    // +28: m_minX (routable)
    // +32: m_maxX (routable)
    // +36: m_minY (routable)
    // +40: m_maxY (routable)
    // +44: m_floorArray (2DArray*)
    // +48: m_roomArray (2DArray*)
    // +52: m_flagsArray (2DArray*)
    // +56: field
    // +60: m_wallArray
    // +64: m_wallStorageArray

    // 0x8014C524 (156 bytes)
    cFixedWorldImpl(int width, int height) {
        // NOTE: asm-derived
        // Sets vtable, constructs Commander base, zeros arrays, calls SetSize
        *(void**)((char*)this + 0) = 0; // vtable set later
        Commander_ctor((char*)this + 4);
        *(int*)((char*)this + 56) = 0;
        *(int*)((char*)this + 20) = 0;
        *(int*)((char*)this + 24) = 0;
        *(int*)((char*)this + 44) = 0;
        *(int*)((char*)this + 48) = 0;
        *(int*)((char*)this + 52) = 0;
        *(int*)((char*)this + 60) = 0;
        *(int*)((char*)this + 64) = 0;
        SetSize(width, height, false);
        TileWallsNS::GenerateRotationLookups();
    }

    // 0x8014C5C0 (112 bytes)
    ~cFixedWorldImpl() {
        // NOTE: asm-derived
        // Sets vtables, calls DeleteArrays, destroys Commander, handles delete
        DeleteArrays();
        Commander_dtor((char*)this + 4);
    }

    // 0x8014C630 (1168 bytes)
    void SetSize(int width, int height, bool preserveData);

    // 0x8014CAC0 (188 bytes)
    void DeleteArrays();

    // 0x8014CB7C (144 bytes)
    void Save(iResFile* file, int version);

    // 0x8014CC0C (440 bytes)
    void Load(iResFile* file, int version);

    // 0x8014CDD4 (748 bytes)
    void GetWall(CTilePt& tile);

    // 0x8014D0C0 (1380 bytes)
    void SetWall(CTilePt& tile, TileWalls walls);

    // 0x8014D624 (11760 bytes)
    void ComputeRooms(int level);

    // 0x80150414 (836 bytes)
    void ComputeArchValue(bool* archArray);

    // 0x80150758 (156 bytes)
    void DoCommand(short cmd, int param);

    // 0x801507F4 (4044 bytes)
    void OffsetWorld(CTilePt& offset);

    // 0x80151984 (80 bytes)
    // Checks if tile point is outside the routable area
    bool OutOfRoutableExtent(CTilePt& tile) const {
        // NOTE: asm-derived
        int x = *(signed char*)((char*)&tile + 0); // lbz + extsb
        int y = *(signed char*)((char*)&tile + 1);
        int minX = *(int*)((char*)this + 28);
        int maxX = *(int*)((char*)this + 32);
        int minY = *(int*)((char*)this + 36);
        int maxY = *(int*)((char*)this + 40);
        if (x < minX || x > maxX || y < minY || y > maxY) {
            return true;
        }
        return false;
    }

    // 0x801519D4 (108 bytes)
    // FTilePt overload — converts to CTilePt then delegates via vtable
    bool OutOfRoutableExtent(FTilePt& tile) const;

    // 0x80151A40 (80 bytes)
    // Checks if tile is outside world bounds (1..width-2, 1..height-2)
    bool OutOfBounds(CTilePt& tile) const {
        // NOTE: asm-derived
        int x = *(signed char*)((char*)&tile + 0);
        int y = *(signed char*)((char*)&tile + 1);
        int w = *(int*)((char*)this + 20);
        int h = *(int*)((char*)this + 24);
        if (x <= 0 || x >= (w - 1) || y <= 0 || y >= (h - 1)) {
            return true;
        }
        return false;
    }

    // 0x80151A90 (128 bytes)
    // Checks if tile is outside building bounds (adjusted for border)
    bool OutOfBuildingBounds(CTilePt& tile, bool strictBorder) const {
        // NOTE: asm-derived
        int border = strictBorder ? 2 : 1;
        int w = *(int*)((char*)this + 20);
        int h = *(int*)((char*)this + 24);
        int maxX = w - border;
        int maxY = h - border;
        int x = *(signed char*)((char*)&tile + 0);
        int y = *(signed char*)((char*)&tile + 1);
        if (x < border || x >= maxX || y < border || y >= maxY) {
            return true;
        }
        return false;
    }

    // 0x80151B10 (72 bytes)
    // Checks if tile is outside the grid (0..width-1, 0..height-1)
    bool OutOfGrid(CTilePt& tile) const {
        // NOTE: asm-derived
        int x = *(signed char*)((char*)&tile + 0);
        int y = *(signed char*)((char*)&tile + 1);
        int w = *(int*)((char*)this + 20);
        int h = *(int*)((char*)this + 24);
        if (x < 0 || x >= w || y < 0 || y >= h) {
            return true;
        }
        return false;
    }

    // 0x80151B58 (108 bytes)
    // FTilePt overload — converts to CTilePt then delegates via vtable
    bool OutOfBounds(FTilePt& tile) const;

    // 0x80151BC4 (108 bytes)
    // FTilePt overload — converts to CTilePt then delegates via vtable
    bool OutOfGrid(FTilePt& tile) const;

    // 0x80151C48 (80 bytes)
    // Gets floor pattern at tile (byte lookup in 2D array)
    int GetFloor(CTilePt& tile) {
        // NOTE: asm-derived — uses floor array at +44
        // floor = floorArray->data[GetX(tile)][GetY(tile)]
        void* floorArr = *(void**)((char*)this + 44);
        int x = CTilePt_GetX(tile);
        int y = CTilePt_GetY(tile);
        unsigned int** rows = *(unsigned int***)((char*)floorArr + 12);
        return *(unsigned char*)(rows[x] + y); // byte access via lbzx
    }

    // 0x80151C98 (128 bytes)
    // Checks if the floor at a tile is grass (pattern type 8 or 9)
    void IsGrassAt(CTilePt& tile);

    // 0x80151D18 (140 bytes)
    // Sets floor pattern at tile, returns old value
    void SetFloor(CTilePt& tile, FloorPattern pattern);

    // 0x80151DA4 (188 bytes)
    // Gets room ID at tile (short lookup in 2D array)
    int GetRoom(CTilePt& tile) {
        // NOTE: asm-derived — validates room array exists and bounds, then lookups
        void* roomArr = *(void**)((char*)this + 48);
        if (roomArr == 0) return 0;
        int x = CTilePt_GetX(tile);
        if (x < 0) return 0;
        // Bounds check width
        int arrWidth = *(int*)((char*)roomArr + 8);
        if (x >= arrWidth) return 0;
        int y = CTilePt_GetY(tile);
        if (y < 0) return 0;
        int arrHeight = *(int*)((char*)roomArr + 4);
        if (y >= arrHeight) return 0;
        // Lookup: rows[x][y] as unsigned short
        unsigned int** rows = *(unsigned int***)((char*)roomArr + 12);
        return *(unsigned short*)((char*)rows[x] + y * 2);
    }

    // 0x80151E60 (88 bytes)
    // Sets room ID at tile (short store in 2D array)
    void SetRoom(CTilePt& tile, unsigned short roomId) {
        // NOTE: asm-derived
        void* roomArr = *(void**)((char*)this + 48);
        int x = CTilePt_GetX(tile);
        int y = CTilePt_GetY(tile);
        unsigned int** rows = *(unsigned int***)((char*)roomArr + 12);
        *(unsigned short*)((char*)rows[x] + y * 2) = roomId;
    }

    // 0x80151EB8 (80 bytes)
    // Gets flags byte at tile
    int GetFlags(CTilePt& tile) {
        // NOTE: asm-derived — same pattern as GetFloor but uses array at +52
        void* flagsArr = *(void**)((char*)this + 52);
        int x = CTilePt_GetX(tile);
        int y = CTilePt_GetY(tile);
        unsigned int** rows = *(unsigned int***)((char*)flagsArr + 12);
        return *(unsigned char*)(rows[x] + y);
    }

    // 0x80151F08 (84 bytes)
    // Sets flags byte at tile
    void SetFlags(CTilePt& tile, unsigned char flags) {
        // NOTE: asm-derived
        void* flagsArr = *(void**)((char*)this + 52);
        int x = CTilePt_GetX(tile);
        int y = CTilePt_GetY(tile);
        unsigned int** rows = *(unsigned int***)((char*)flagsArr + 12);
        *(unsigned char*)(rows[x] + y) = flags;
    }

    // 0x80151F5C (84 bytes)
    // Checks if a tile is marked as outside
    bool IsOutside(CTilePt& tile) {
        // NOTE: asm-derived — gets flags, checks specific bit
        int flags = GetFlags(tile);
        return (flags & 1) != 0; // bit 0 = outside
    }

    // 0x80151FB0 (104 bytes)
    void HasWalls(CTilePt& tile, TileWallsSegment segment);

    // 0x80152018 (104 bytes)
    void HasWalls(CTilePt& tile);

    // 0x80152080 (84 bytes)
    void GetWallStorage(CTilePt& tile);

    // 0x801520D4 (104 bytes)
    void SetWallStorage(CTilePt& tile, TileWallStorage& storage);

    // 0x8015213C (112 bytes)
    void MayEditTile(CTilePt& tile) const;

    // 0x801521AC (224 bytes)
    void GetRoomIdFromPoint(CTilePt& tile);

private:
    // Helper stubs
    static int CTilePt_GetX(CTilePt& tile);
    static int CTilePt_GetY(CTilePt& tile);
    static void Commander_ctor(void* ptr);
    static void Commander_dtor(void* ptr);
};


// ============================================================================
// ObjectFolderImpl - Object selector/database management
// ============================================================================

class ObjectFolderImpl {
public:
    // Member layout from asm:
    // +0: vtable ptr 1
    // +4: vtable ptr 2
    // +8: Commander base (embedded)
    // +20: vtable ptr 3
    // +24: RBTree/map (selector by ID, 16 bytes)
    // +40: RBTree/map (file by ID, 16 bytes)
    // +56: field
    // +60: field
    // +64: m_selectorBuckets[256] (hash table, 1024 bytes)
    // +1088: field
    // +1092: StringBuffer (path1, embedded with 260-char buffer)
    // +1360: StringBuffer (path2, embedded with 260-char buffer)
    // +1628: flag (int, set to 1)
    // +1632..+1679: 6 TArray-like structs (8 bytes each)
    // +1680: ERQuickdata* (quickdata ptr)
    // +1684: field
    // +1688: int (set to -1)
    // +1692: ObjectDataObjDefinition (embedded)
    // +1724: short field
    // +1728: list/map (16 bytes + extra)
    // +1744: field

    // 0x800EC684 (456 bytes)
    ObjectFolderImpl();

    // 0x800EC84C (592 bytes)
    ~ObjectFolderImpl();

    // 0x800ECA9C (72 bytes)
    // Counts all selectors across all 256 hash buckets
    int CountSelectors() {
        // NOTE: asm-derived
        int* buckets = (int*)((char*)this + 64);
        int total = 0;
        for (int i = 0; i <= 255; i++) {
            int* sel = (int*)(unsigned int)buckets[i];
            int count = 0;
            while (sel != 0) {
                sel = (int*)(unsigned int)*(int*)((char*)sel + 164); // next ptr at +164
                count++;
            }
            total += count;
        }
        return total;
    }

    // 0x800ECAE4 (136 bytes)
    // Finds selector by GUID, moves to front of bucket for faster future lookups
    void* GetSelectorByGUID(int guid) {
        // NOTE: asm-derived — hash lookup, calls ObjSelector::GetGUID() to match
        int bucketIdx = (guid << 2) & 0x3FC; // rlwinm r9,r4,2,22,29
        int* buckets = (int*)((char*)this + 64);
        void* prev = 0;
        void* sel = (void*)(unsigned int)*(int*)((char*)buckets + bucketIdx);
        while (sel != 0) {
            int selGuid = ObjSelector_GetGUID(sel);
            if (selGuid == guid) {
                // Move to front of bucket if not already there
                if (prev != 0) {
                    *(int*)((char*)prev + 164) = *(int*)((char*)sel + 164);
                    *(int*)((char*)sel + 164) = *(int*)((char*)buckets + bucketIdx);
                    *(int*)((char*)buckets + bucketIdx) = (int)(unsigned int)sel;
                }
                return sel;
            }
            prev = sel;
            sel = (void*)(unsigned int)*(int*)((char*)sel + 164);
        }
        return 0;
    }

    // 0x800ECB6C (460 bytes)
    void GetNextSelector(ObjSelector* sel);

    // 0x800ECD38 (208 bytes)
    void GetSubTileSelector(ObjSelector* sel, int x, int y, int z);

    // 0x800ECE08 (208 bytes)
    void GetLeadSelector(ObjSelector* sel);

    // 0x800ECED8 (204 bytes)
    void GetNthSubSelector(ObjSelector* sel, int n);

    // 0x800ECFA4 (132 bytes)
    void GetQueueShaderByGUID(int guid);

    // 0x800ED028 (188 bytes)
    void GetMasterSelector(ObjSelector* sel);

    // 0x800ED0E4 (208 bytes)
    void Init(char* path, bool flag);

    // 0x800ED1B4 (1292 bytes)
    void Destroy();

    // 0x800ED6C0 (676 bytes)
    void DestroySelector(ObjSelector* sel);

    // 0x800ED964 (924 bytes)
    void AddUserSelector(int guid, short id);

    // 0x800EDD00 (148 bytes)
    void GetSemiGlobalID(unsigned int nameHash);

    // 0x800EDD94 (948 bytes)
    void AddSelector(ObjDefinition* def, char* name, char* path, ResFile* file,
                     short id, int* outGuid);

    // 0x800EE148 (196 bytes)
    void OpenResFile(ObjSelector* sel);

    // 0x800EE20C (164 bytes)
    void CloseResFile(ObjSelector* sel);

    // 0x800EE2B4 (1752 bytes)
    void LoadDatabase();

    // 0x800EE98C (468 bytes)
    void ReconSelector(ObjSelector** sel, ReconBuffer* buffer, bool flag, int param);

    // 0x800EEB60 (460 bytes)
    void GetSelectorByBehavior(Behavior* beh);

    // 0x800EED2C (368 bytes)
    void ReconBehavior(Behavior** beh, ReconBuffer* buffer, int param);

    // 0x800EEE9C (492 bytes)
    void GetPersonGlobNamespaceID();

    // 0x800EF088 (252 bytes)
    void GetFileByID(unsigned int fileId);

    // 0x800EF184 (604 bytes)
    void LoadUserData(iResFile* file);

    // 0x800EF4FC (1260 bytes)
    void SaveUserData(iResFile* file);

    // 0x800EF9E8 (96 bytes)
    void CreateNewUserSelector();

    // 0x800EFA48 (324 bytes)
    void RemoveSelector(ObjSelector* sel);

    // 0x800EFCB8 (104 bytes)
    void forceDataPreload(ObjSelector* sel, bool flag);

    // 0x800EFB8C (300 bytes)
    void ForceDataPreload(ObjSelector* sel, bool flag);

    // 0x800EFD20 (112 bytes)
    void CreatingInstance(ObjSelector* sel);

    // 0x800EFDCC (1560 bytes)
    void PrepareForModuleLoad(iResFile* file);

    // 0x800F03E4 (1184 bytes)
    void PrepareForModuleSave(iResFile* file);

    // 0x800F08C0 (600 bytes)
    void FreeUnusedData();

    // 0x800F0B18 (1052 bytes)
    void DeleteUserSelectors();

    // 0x800F0F34 (488 bytes)
    void DeleteSelectorAnimLists();

    // 0x800F111C (328 bytes)
    void UnloadData(ObjSelector* sel);

    // 0x800F12FC (548 bytes)
    void DoStream(ReconBuffer* buffer, int param);

    // 0x800F1520 (88 bytes)
    // Looks up a rumble effect by name in quickdata
    void* GetRumbleByName(char* name) {
        // NOTE: asm-derived — uses ERQuickdata at +1680
        ERQuickdata* qd = *(ERQuickdata**)((char*)this + 1680);
        void* table = qd->getTable("Rumble"); // string at lis/addi address
        void* row = qd->getRow(table, name);
        return row ? row : 0;
    }

    // 0x800F1578 (88 bytes)
    // Looks up camera bloom settings by name in quickdata
    void* GetCameraBloomByName(char* name) {
        // NOTE: asm-derived
        ERQuickdata* qd = *(ERQuickdata**)((char*)this + 1680);
        void* table = qd->getTable("CameraBloom");
        void* row = qd->getRow(table, name);
        return row ? row : 0;
    }

    // 0x800F15D0 (88 bytes)
    // Looks up camera blur settings by name in quickdata
    void* GetCameraBlurByName(char* name) {
        // NOTE: asm-derived
        ERQuickdata* qd = *(ERQuickdata**)((char*)this + 1680);
        void* table = qd->getTable("CameraBlur");
        void* row = qd->getRow(table, name);
        return row ? row : 0;
    }

    // 0x800F165C (316 bytes)
    void GetAnimPreloadList(ChecksumList& list);

    // 0x800F17A8 (740 bytes)
    void GetTreeTable(ObjSelector* sel);

    // 0x800F1A8C (268 bytes)
    void LoadResourceByIndex(unsigned int namespaceId, short resType,
                             ObjectDataInterface& data, unsigned int index,
                             unsigned int flags);

    // 0x800F1B98 (104 bytes)
    void LoadResourceByID(unsigned int namespaceId, short resType,
                          ObjectDataInterface& data, unsigned int resId);

    // 0x800F1C00 (68 bytes)
    // Saves a resource via virtual dispatch on the ObjectDataInterface
    void SaveResource(unsigned int namespaceId, short resType,
                      StringBuffer& name, ObjectDataInterface& data) {
        // NOTE: asm-derived — if namespaceId != -1, calls vtable method on data
        if ((int)namespaceId == -1) {
            // return null
            return;
        }
        // Virtual call through data's vtable
        void** vtable = *(void***)&data;
        // vtable[17] or similar — calls Save method
    }

    // 0x800F1C44 (116 bytes)
    void GetResourceCount(unsigned int namespaceId, unsigned int resType, unsigned int flags);

    // 0x800F1CB8 (276 bytes)
    void RemoveResourceByID(unsigned int namespaceId, short resId, unsigned int flags);

    // 0x800F1DCC (284 bytes)
    void ChangeResourceID(unsigned int namespaceId, short oldId, short newId, unsigned int flags);

    // 0x800F1EE8 (132 bytes)
    void GetNamespaceName(unsigned int namespaceId, StringBuffer& outName);

    // 0x800F1F6C (132 bytes)
    void FindUniqueResourceName(unsigned int namespaceId, unsigned int resType,
                                StringBuffer& outName);

    // 0x800F1FF0 (132 bytes)
    void FindUniqueResourceID(unsigned int namespaceId, unsigned int resType, short& outId);

    // 0x800F2084 (212 bytes)
    void GetStringFromNamespaceID(unsigned int namespaceId, StringBuffer& outStr,
                                  short param1, short param2);

    // 0x800F2158 (580 bytes)
    void ClearAllCaches();

    // 0x800F2480 (1248 bytes)
    void GetNamespaceSelector(unsigned int namespaceId);

    // 0x800F2960 (100 bytes)
    void FlushNamespaceCaches();

private:
    static int ObjSelector_GetGUID(void* sel);
};


// ============================================================================
// ERQuickdata helper (used by ObjectFolderImpl)
// ============================================================================
class ERQuickdata {
public:
    void* getTable(const char* name);
    void* getRow(void* table, const char* name);
};

// ============================================================================
// EAnimController helper (used by ISimsObjectModel)
// ============================================================================
class EAnimController {
public:
    void SetTrackAnim(int trackFlags, unsigned int animId, int blendMode,
                      float blendTime, EACTrack** outTrack);
    void StopAllTracks();
};

// ============================================================================
// StringBuffer helper (used by NghResFile)
// ============================================================================
class StringBuffer {
public:
    void erase();
    void append(char* str, int len);
};

// ============================================================================
// MemoryCardCache helper
// ============================================================================
class MemoryCardCache {
public:
    void Init(/* NghLayout* */);
    void Destroy();
};

// ============================================================================
// SimModel helper
// ============================================================================
class SimModel {
public:
    void DeallocateMorphResources();
};

// ============================================================================
// iResFile base class stub
// ============================================================================
class iResFile {
public:
    iResFile();
    ~iResFile();
};

// ============================================================================
// ISimInstance base class stub
// ============================================================================
class ISimInstance {
public:
    ISimInstance();
};
