// eageneralallocator.h - EA::Allocator::GeneralAllocator class declarations
// From: base_ngc_release_dvd.lib(eageneralallocator.obj)

#ifndef EAGENERALALLOCATOR_H
#define EAGENERALALLOCATOR_H

namespace EA {
namespace Allocator {

class GeneralAllocator {
public:
    enum HeapValidationLevel {
        kHeapValidationLevelNone = 0,
        kHeapValidationLevelBasic = 1,
        kHeapValidationLevelDetail = 2,
        kHeapValidationLevelFull = 3
    };

    struct Chunk {
        unsigned int m_prevSize;    // 0x00
        unsigned int m_size;        // 0x04
        Chunk* m_fd;                // 0x08
        Chunk* m_bk;                // 0x0C
    };

    struct CoreBlock {
        void* m_start;              // 0x00
        unsigned int m_size;        // 0x04
        unsigned int m_reserved1;   // 0x08
        unsigned int m_reserved2;   // 0x0C
        unsigned int m_reserved3;   // 0x10
        unsigned int m_reserved4;   // 0x14
        unsigned int m_reserved5;   // 0x18
        unsigned int m_reserved6;   // 0x1C
        CoreBlock* m_next;          // 0x20
        CoreBlock* m_prev;          // 0x24
    };

    struct BlockInfo {
        void* m_start;              // 0x00
        unsigned int m_size;        // 0x04
        unsigned int m_reserved1;   // 0x08
        unsigned int m_reserved2;   // 0x0C
        unsigned char m_type;       // 0x10
        unsigned char m_pad1;       // 0x11
        unsigned char m_pad2;       // 0x12
        unsigned char m_pad3;       // 0x13
        unsigned int m_extra;       // 0x14
    };

    struct HookInfo {
        // Hook info structure
    };

    // Constructor/destructor
    GeneralAllocator();
    GeneralAllocator(void* buffer, unsigned int size, int coreBlockCount,
                     unsigned int flags, unsigned int reserved1, unsigned int reserved2);
    virtual ~GeneralAllocator(void);

    // Init/Shutdown
    int Init(void* buffer, unsigned int size, int coreBlockCount,
             unsigned int flags, unsigned int reserved1, unsigned int reserved2);
    void Shutdown(void);

    // Core allocation
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int align, unsigned int offset, int flags);
    void* Calloc(unsigned int count, unsigned int size, int flags);
    void* Realloc(void* ptr, unsigned int size, int flags);
    void Free(void* ptr);

    // Core blocks
    int AddCoreBlock(void* buffer, unsigned int size, int flags,
                     unsigned int reserved1, unsigned int reserved2, unsigned int reserved3);
    void LinkCoreBlock(CoreBlock* block, CoreBlock* after);
    void UnlinkCoreBlock(CoreBlock* block);
    CoreBlock* FindCoreBlockForAddress(void* addr) const;
    unsigned int GetTotalCoreSize(void) const;

    // Chunk management
    void SetNewTopChunk(Chunk* chunk, bool link);
    void AdjustTopChunk(Chunk* chunk, unsigned int size);
    int ChunkMatchesLowHigh(int flags, Chunk* chunk, unsigned int size) const;
    void SetFencepostAfterChunk(Chunk* chunk, unsigned int size);
    void AdjustHighFence(void);

    // Query
    static unsigned int GetPageSize(void);
    unsigned int GetUsableSize(void* ptr) const;
    unsigned int GetBlockSize(void* ptr) const;
    void GetBlockInfoForCoreBlock(CoreBlock* coreBlock, BlockInfo* info) const;

    // Callbacks
    void SetMallocFailureFunction(bool (*func)(GeneralAllocator*, unsigned int, unsigned int, void*), void* context);
    void SetHookFuncton(void (*func)(HookInfo*, void*), void* context);
    void SetTraceFunction(void (*func)(char*, void*), void* context);
    void SetTraceFieldDelimiters(unsigned char begin, unsigned char end);
    void SetAssertionFailureFunction(void (*func)(char*, void*), void* context);

    // Assertion/trace
    static void AssertionFailureFunctionDefault(char* msg, void* context);
    static void TraceFunctionDefault(char* msg, void* context);
    void AssertionFailure(char* msg) const;

    // Debug
    void DescribeData(void* ptr, char* desc, unsigned int descSize);
    void* TakeSnapshot(int flags);
    void FreeSnapshot(void* snapshot);
    void SetAutoHeapValidation(HeapValidationLevel level, unsigned int freq);

    // MMap
    void* MMapAlloc(unsigned int size);
    void MMapFree(void* ptr, unsigned int size);

    // Member data - offsets from disassembly analysis
    // The class is large - about 0x534 bytes for EAHeap subclass
    // Key member offsets:
    // 0x034: m_binChunks (sentinel node for circular list)
    // 0x044: m_topChunk
    // 0x044C: m_coreBlockSentinel
    // 0x046C: m_coreBlockList (first real core block)
    // 0x0484: m_traceFieldBegin
    // 0x0485: m_traceFieldEnd
    // 0x0488: m_validationLevel
    // 0x048C: m_validationFreq
    // 0x0490: m_validationCounter
    // 0x04BC: m_hookFunc
    // 0x04C0: m_hookContext
    // 0x04C4: m_mallocFailFunc
    // 0x04C8: m_mallocFailContext
    // 0x04D0: m_assertFunc
    // 0x04D4: m_assertContext
    // 0x04D8: m_traceFunc
    // 0x04DC: m_traceContext
    // 0x04FC: m_mutex (pointer)
    char _padding[0x528]; // Total size to reach EAHeap fields
};

} // namespace Allocator
} // namespace EA

// PPM helper functions (global, used by GeneralAllocator)
int PPM_VERIFY(EA::Allocator::GeneralAllocator* alloc, bool condition);
void* PPMMutexCreate(void* mutex);
void PPMMutexDestroy(void* mutex);
int PPMMutexLock(void* mutex);
int PPMMutexUnlock(void* mutex);
int PPMMutexGetLockCount(void* mutex);

#endif // EAGENERALALLOCATOR_H
