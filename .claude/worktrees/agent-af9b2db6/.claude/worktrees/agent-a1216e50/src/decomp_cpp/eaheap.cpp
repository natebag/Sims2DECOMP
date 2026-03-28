// eaheap.cpp - Decompiled EAHeap class (PC port, functionally correct C++)
//
// Converted from inline PPC asm (src/asm_decomp/EAHeap.cpp) using
// documentation in src/core/eaheap_decomp.cpp.
//
// EAHeap is the top-level memory management interface in The Sims 2 (GC).
// It wraps EA's PPMalloc (EA::Allocator::GeneralAllocator) with:
//   - A small-block pool layer (ProtectedAllocPool via AllocPoolManager)
//   - A hierarchical heap tree for overflow
//
// Three-tier allocation flow:
//   Tier 1: Pool Allocator (for sizes <= 64 bytes) - 8 size classes
//   Tier 2: GeneralAllocator / PPMalloc (for sizes > 64 or pool exhaustion)
//   Tier 3: Heap Hierarchy (overflow to parent/aux heaps)

#include "types.h"

// External functions
extern "C" void* memset(void* s, int c, unsigned int n);
extern "C" int atexit(void (*func)(void));

// Forward declarations
namespace EA { namespace Allocator { class GeneralAllocator; } }

class ProtectedAllocPool;
class FastAllocPool;

template <typename T>
class AllocPoolManager {
public:
    int m_count;
    int m_pad;
    char m_poolData[1]; // Variable-length pool array

    void InitAllocPools(unsigned int* blockCounts);
    void* AttemptPoolAlloc(unsigned int size, unsigned int alignment);
    void* FindPoolForBlock(void* ptr);
};

// ============================================================================
// EAHeap class definition
//
// Inherits from EA::Allocator::GeneralAllocator (0x528 bytes base).
// Total size: 0x538 (1336 bytes).
// ============================================================================

class EAHeap /* : public EA::Allocator::GeneralAllocator */ {
public:
    // Base class: GeneralAllocator occupies bytes 0x000 - 0x527
    // We simulate it with padding + forward declarations
    char _ga_data[0x528];

    // EAHeap-specific fields (from decomp documentation):
    char*    m_name;           // 0x528 - heap name string
    EAHeap*  m_parentHeap;     // 0x52C - first fallback heap
    EAHeap*  m_auxHeap;        // 0x530 - second fallback heap
    u32      m_checkpointId;   // 0x534 - checkpoint tracking ID

    // --- Constructors ---
    EAHeap(char* name, void* buffer, unsigned int size,
           EAHeap* parent, EAHeap* auxHeap);

    // --- Methods ---
    void  Init(void* buffer, unsigned int size);
    void  Clear();
    void* Malloc(unsigned int size, int flags);
    void* MallocAligned(unsigned int size, unsigned int alignment,
                        unsigned int offset, int flags);
    void* Calloc(unsigned int count, unsigned int size, int flags);
    void  Free(void* ptr);
    void  Compact();
    void  ValidateHeap(int level);
    EAHeap* FindHeapForAddress(void* addr) const;

    static void InitializeHeapStatics();
    static void SetNextCheckPoint();
    static int  GetCurrentCheckPoint();

    // --- GeneralAllocator method wrappers ---
    // These forward to the embedded GA. For the PC port, the actual
    // GeneralAllocator implementation would be linked separately.
    void* GA_Malloc(unsigned int size, int flags);
    void* GA_MallocAligned(unsigned int size, unsigned int align,
                           unsigned int offset, int flags);
    void* GA_Calloc(unsigned int count, unsigned int size, int flags);
    void  GA_Free(void* ptr);
    void  GA_Init(void* buffer, unsigned int size, int a, int b, int c, int d);
    void  GA_Compact();
    void  GA_ValidateHeap(int level);
    bool  GA_ContainsAddress(void* addr) const;
    unsigned int GA_GetUsableSize() const;
    void  GA_SetOption(int option, int value);
    void  GA_SetMallocFailureFunction(void* func, void* context);
};

// ============================================================================
// Global state (originally SDA-relative via r13)
// ============================================================================

static AllocPoolManager<ProtectedAllocPool>* s_protectedPoolManager = NULL;
static int s_initialized = 0;
static int g_currentCheckPoint = 0;

// Global heap pointers (singletons)
static EAHeap* g_RootHeap = NULL;
static EAHeap* g_MainHeap = NULL;
static EAHeap* g_ResourceHeap = NULL;
static EAHeap* g_VMHeap = NULL;
static EAHeap* g_DebugHeap = NULL;
static EAHeap* g_CUIHeap = NULL;
static EAHeap* g_AudioHeap = NULL;
static EAHeap* g_ShaderHeap = NULL;
static EAHeap* g_TextureHeap = NULL;
static EAHeap* g_AnimationHeap = NULL;
static EAHeap* g_ModelHeap = NULL;
static EAHeap* g_FlashesHeap = NULL;
static EAHeap* g_AptHeap = NULL;

// Heap accessor functions
extern "C" EAHeap* RootHeap()      { return g_RootHeap; }
extern "C" EAHeap* MainHeap()      { return g_MainHeap; }
extern "C" EAHeap* ResourceHeap()  { return g_ResourceHeap; }
extern "C" EAHeap* VMHeap()        { return g_VMHeap; }
extern "C" EAHeap* DebugHeap()     { return g_DebugHeap; }
extern "C" EAHeap* CUIHeap()       { return g_CUIHeap; }
extern "C" EAHeap* AudioHeap()     { return g_AudioHeap; }
extern "C" EAHeap* ShaderHeap()    { return g_ShaderHeap; }
extern "C" EAHeap* TextureHeap()   { return g_TextureHeap; }
extern "C" EAHeap* AnimationHeap() { return g_AnimationHeap; }
extern "C" EAHeap* ModelHeap()     { return g_ModelHeap; }
extern "C" EAHeap* FlashesHeap()   { return g_FlashesHeap; }
extern "C" EAHeap* AptHeap()       { return g_AptHeap; }

// Pool block size configuration (from .data at 0x8041E4D8)
static u32 s_poolBlockCounts[8]; // 8 size classes for pool allocator

// Forward declarations for failure callbacks
static bool MallocFailureCallback_Root(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Audio(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_VM(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Shader(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Texture(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Animation(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Model(void* ga, unsigned int size, unsigned int flags, void* ctx);
static bool MallocFailureCallback_Flashes(void* ga, unsigned int size, unsigned int flags, void* ctx);

// Cleanup function registered with atexit
static void HeapCleanup() {
    // Cleanup pool manager on exit
    // Original registers this with atexit during InitializeHeapStatics
}


// ============================================================================
// EAHeap::EAHeap - Constructor
// Address: 0x802D09DC | 128 bytes
//
// Initializes the embedded GeneralAllocator with no initial memory (autoGrow=1),
// stores the name and child heap pointers, then calls Clear() and Init().
// ============================================================================

EAHeap::EAHeap(char* name, void* buffer, unsigned int size,
               EAHeap* parent, EAHeap* auxHeap) {
    // The original calls GeneralAllocator ctor with:
    //   this, NULL, 0, autoGrow=1, 0, 0, 0
    // The GA base is constructed with default parameters.

    m_name       = name;
    m_parentHeap = parent;
    m_auxHeap    = auxHeap;

    Clear();
    Init(buffer, size);
}


// ============================================================================
// EAHeap::Init - Initialize with memory region
// Address: 0x802D0A5C | 72 bytes
//
// If either buffer or size is 0/NULL, returns without initializing.
// Otherwise initializes the GeneralAllocator with the given memory.
// ============================================================================

void EAHeap::Init(void* buffer, unsigned int size) {
    if (buffer == NULL || size == 0) {
        return; // Original returns 1 (error code) but we ignore it
    }

    // Initialize GeneralAllocator with:
    //   buffer, size, autoGrow=0, supportThreads=0, growFunc=NULL, growFuncContext=NULL
    GA_Init(buffer, size, 0, 0, 0, 0);
}


// ============================================================================
// EAHeap::Clear - Reset heap state
// Address: 0x802D0E88 | 76 bytes
//
// Resets the checkpoint ID and sets two GeneralAllocator options:
//   Option 2 = 0 (kOptionEnableHighAllocation)
//   Option 10 = 0 (kOptionEnableDebugChecks)
// ============================================================================

void EAHeap::Clear() {
    m_checkpointId = 0;

    // Disable high allocation and debug checks for a clean slate
    GA_SetOption(2, 0);   // kOptionEnableHighAllocation = 0
    GA_SetOption(10, 0);  // kOptionEnableDebugChecks = 0
}


// ============================================================================
// EAHeap::Malloc - Core allocation function
// Address: 0x802D0AA4 | 204 bytes
//
// Three-tier allocation strategy:
//   Tier 1: Try pool allocation for small blocks (skip for DebugHeap)
//   Tier 2: Try this heap's GeneralAllocator
//   Tier 3: Try parent heap, then aux heap recursively
// ============================================================================

void* EAHeap::Malloc(unsigned int size, int flags) {
    if (size == 0) {
        return NULL;
    }

    // Tier 1: Try pool allocation (skip for DebugHeap)
    if (this != g_DebugHeap) {
        if (s_protectedPoolManager != NULL) {
            void* poolResult = s_protectedPoolManager->AttemptPoolAlloc(size, 8);
            if (poolResult != NULL) {
                return poolResult;
            }
        }
    }

    // Tier 2: Try GeneralAllocator
    void* gaResult = GA_Malloc(size, flags);
    if (gaResult != NULL) {
        return gaResult;
    }

    // Tier 3: Try parent heap
    void* result = NULL;
    if (m_parentHeap != NULL) {
        result = m_parentHeap->Malloc(size, flags);
    }

    // Tier 3b: Try aux heap
    if (result == NULL && m_auxHeap != NULL) {
        result = m_auxHeap->Malloc(size, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::MallocAligned - Aligned allocation
// Address: 0x802D0B70 | 276 bytes
//
// Same three-tier strategy but with alignment support.
// First adjusts size to be a multiple of alignment.
// If alignment <= 8, falls through to regular Malloc (PPMalloc default is 8).
// ============================================================================

void* EAHeap::MallocAligned(unsigned int size, unsigned int alignment,
                            unsigned int offset, int flags) {
    // Compute aligned size: round up to nearest multiple of alignment
    unsigned int adjustedSize = (size + alignment - 1) & ~(alignment - 1);
    if (adjustedSize == 0) {
        return NULL;
    }

    // If alignment is default (8 or less), use regular Malloc
    if (alignment <= 8) {
        return Malloc(adjustedSize, flags);
    }

    // Tier 1: Try pool allocation (skip for DebugHeap)
    if (this != g_DebugHeap) {
        if (s_protectedPoolManager != NULL) {
            void* poolResult = s_protectedPoolManager->AttemptPoolAlloc(adjustedSize, alignment);
            if (poolResult != NULL) {
                return poolResult;
            }
        }
    }

    // Tier 2: Try GeneralAllocator aligned alloc
    void* gaResult = GA_MallocAligned(adjustedSize, alignment, offset, flags);
    if (gaResult != NULL) {
        return gaResult;
    }

    // Tier 3: Try parent and aux heaps
    void* result = NULL;
    if (m_parentHeap != NULL) {
        result = m_parentHeap->MallocAligned(adjustedSize, alignment, offset, flags);
    }
    if (result == NULL && m_auxHeap != NULL) {
        result = m_auxHeap->MallocAligned(adjustedSize, alignment, offset, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::Calloc - Allocate and zero memory
// Address: 0x802D0C84 | 244 bytes
//
// Allocates count * size bytes and zeroes them.
// Pool allocations are manually zeroed with memset.
// GeneralAllocator::Calloc zeros internally.
// ============================================================================

void* EAHeap::Calloc(unsigned int count, unsigned int size, int flags) {
    unsigned int totalSize = count * size;
    if (totalSize == 0) {
        return NULL;
    }

    // Tier 1: Pool allocation + manual zeroing
    if (this != g_DebugHeap) {
        if (s_protectedPoolManager != NULL) {
            void* poolResult = s_protectedPoolManager->AttemptPoolAlloc(totalSize, 8);
            if (poolResult != NULL) {
                memset(poolResult, 0, totalSize);
                return poolResult;
            }
        }
    }

    // Tier 2: GeneralAllocator::Calloc (zeros memory internally)
    void* gaResult = GA_Calloc(count, size, flags);
    if (gaResult != NULL) {
        return gaResult;
    }

    // Tier 3: Child heaps
    void* result = NULL;
    if (m_parentHeap != NULL) {
        result = m_parentHeap->Calloc(count, size, flags);
    }
    if (result == NULL && m_auxHeap != NULL) {
        result = m_auxHeap->Calloc(count, size, flags);
    }

    return result;
}


// ============================================================================
// EAHeap::Free - Free allocated memory
// Address: 0x802D0D78 | 176 bytes
//
// Two paths:
//   Path A: If ptr belongs to a pool, free via ProtectedAllocPool (with mutex)
//   Path B: Find owning heap via FindHeapForAddress, free via GA
// ============================================================================

void EAHeap::Free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    // Check if ptr belongs to a pool
    if (s_protectedPoolManager != NULL) {
        void* pool = s_protectedPoolManager->FindPoolForBlock(ptr);
        if (pool != NULL) {
            // Pool found - free via ProtectedAllocPool with lock
            // Original code:
            //   pool->mutex.Lock(-1);
            //   FastAllocPool::Free(pool, ptr);
            //   pool->mutex.Unlock();
            // TODO: implement ProtectedAllocPool::Free for PC port
            return;
        }
    }

    // Not in a pool - find which heap owns this address
    EAHeap* owningHeap = FindHeapForAddress(ptr);
    if (owningHeap != NULL) {
        owningHeap->GA_Free(ptr);
    }
}


// ============================================================================
// EAHeap::Compact - Coalesce free chunks
// Address: 0x802D0E28 | 96 bytes
//
// Compacts the GeneralAllocator by coalescing adjacent free chunks.
// Optionally acquires a lock if the GA has a mutex (offset 0x4FC).
// Only compacts if GA flag bit 0 is set (compact enabled).
// ============================================================================

void EAHeap::Compact() {
    // Check if GA has a mutex (at offset 0x4FC in GeneralAllocator)
    void* mutex = *(void**)(_ga_data + 0x4FC);

    // Lock if mutex exists
    // if (mutex) PPMMutexLock(mutex);

    // Check if compact is enabled (flag bit 0 at offset 0x04)
    u32 gaFlags = *(u32*)(_ga_data + 0x04);
    if (gaFlags & 1) {
        GA_Compact();
    }

    // Unlock if mutex exists
    // if (mutex) PPMMutexUnlock(mutex);
}


// ============================================================================
// EAHeap::ValidateHeap - Validate heap integrity
// Address: 0x802D0ED4 | 80 bytes
//
// Skips validation if usable size <= 1024 (too small / uninitialized).
// Otherwise compacts first, then runs GA validation.
// ============================================================================

void EAHeap::ValidateHeap(int level) {
    unsigned int usableSize = GA_GetUsableSize();
    if (usableSize <= 1024) {
        return; // Too small to validate
    }

    Compact();
    GA_ValidateHeap(level);
}


// ============================================================================
// EAHeap::FindHeapForAddress - Find owning heap for a pointer
// Address: 0x802D0F24 | 124 bytes
//
// Recursively searches this heap and its children (parent, aux) to find
// which heap's GeneralAllocator contains the given address.
// ============================================================================

EAHeap* EAHeap::FindHeapForAddress(void* addr) const {
    // Check if this heap's GA contains the address
    if (GA_ContainsAddress(addr)) {
        return const_cast<EAHeap*>(this);
    }

    // Try parent heap recursively
    if (m_parentHeap != NULL) {
        EAHeap* result = m_parentHeap->FindHeapForAddress(addr);
        if (result != NULL) {
            return result;
        }
    }

    // Try aux heap recursively
    if (m_auxHeap != NULL) {
        EAHeap* result = m_auxHeap->FindHeapForAddress(addr);
        if (result != NULL) {
            return result;
        }
    }

    return NULL;
}


// ============================================================================
// EAHeap::SetNextCheckPoint - Increment global checkpoint
// ============================================================================

void EAHeap::SetNextCheckPoint() {
    g_currentCheckPoint++;
}


// ============================================================================
// EAHeap::GetCurrentCheckPoint - Return global checkpoint value
// ============================================================================

int EAHeap::GetCurrentCheckPoint() {
    return g_currentCheckPoint;
}


// ============================================================================
// EAHeap::InitializeHeapStatics - One-time global initialization
// Address: 0x802D070C | 384 bytes
//
// Phase 1: Construct 8 ProtectedAllocPool instances in the pool manager
// Phase 2: Initialize pool manager with block count configuration
// Phase 3: Configure named heaps (SetOption, SetMallocFailureFunction)
// ============================================================================

void EAHeap::InitializeHeapStatics() {
    // Phase 1: Construct pool manager if not already initialized
    if (!s_initialized) {
        // The original code constructs 8 ProtectedAllocPool objects at
        // poolMgr + 8, poolMgr + 60, poolMgr + 112, ... (stride 52 bytes)
        // Each pool handles a different size class: 8, 16, 24, 32, 40, 48, 56, 64
        //
        // For the PC port, we would use a standard allocator or
        // re-implement the pool system. Placeholder:
        s_initialized = 1;

        // Register cleanup handler
        atexit(HeapCleanup);
    }

    // Phase 2: Initialize pool manager with block counts from .data
    // s_protectedPoolManager->InitAllocPools(s_poolBlockCounts);

    // Phase 3: Configure heap options and failure callbacks
    //
    // ResourceHeap -> SetOption(6, 0)
    // ModelHeap    -> SetOption(6, 0)
    //
    // RootHeap      -> SetMallocFailureFunction(MallocFailureCallback_Root, NULL)
    // MainHeap      -> SetMallocFailureFunction(MallocFailureCallback_Root, NULL)
    // ResourceHeap  -> SetMallocFailureFunction(MallocFailureCallback_Root, NULL)
    // AudioHeap     -> SetMallocFailureFunction(MallocFailureCallback_Audio, NULL)
    // VMHeap        -> SetMallocFailureFunction(MallocFailureCallback_VM, NULL)
    // ShaderHeap    -> SetMallocFailureFunction(MallocFailureCallback_Shader, NULL)
    // TextureHeap   -> SetMallocFailureFunction(MallocFailureCallback_Texture, NULL)
    // AnimationHeap -> SetMallocFailureFunction(MallocFailureCallback_Animation, NULL)
    // ModelHeap     -> SetMallocFailureFunction(MallocFailureCallback_Model, NULL)
    // FlashesHeap   -> SetMallocFailureFunction(MallocFailureCallback_Flashes, NULL)
}


// ============================================================================
// GeneralAllocator method wrappers
//
// For the PC port, these would call into the actual PPMalloc implementation.
// Currently they are stubs that document the interface.
// ============================================================================

void* EAHeap::GA_Malloc(unsigned int size, int flags) {
    // Forward to GeneralAllocator::Malloc(size, flags)
    // Original address: varies per heap instance
    return NULL; // TODO: link to PPMalloc
}

void* EAHeap::GA_MallocAligned(unsigned int size, unsigned int align,
                               unsigned int offset, int flags) {
    return NULL; // TODO: link to PPMalloc
}

void* EAHeap::GA_Calloc(unsigned int count, unsigned int size, int flags) {
    return NULL; // TODO: link to PPMalloc
}

void EAHeap::GA_Free(void* ptr) {
    // Forward to GeneralAllocator::Free(ptr)
}

void EAHeap::GA_Init(void* buffer, unsigned int size, int a, int b, int c, int d) {
    // Forward to GeneralAllocator::Init(buffer, size, a, b, c, d)
}

void EAHeap::GA_Compact() {
    // Forward to GeneralAllocator::Compact()
}

void EAHeap::GA_ValidateHeap(int level) {
    // Forward to GeneralAllocator::ValidateHeap(level)
}

bool EAHeap::GA_ContainsAddress(void* addr) const {
    // Forward to GeneralAllocator::ContainsAddress(addr)
    return false; // TODO
}

unsigned int EAHeap::GA_GetUsableSize() const {
    // Forward to GeneralAllocator::GetUsableSize()
    return 0; // TODO
}

void EAHeap::GA_SetOption(int option, int value) {
    // Forward to GeneralAllocator::SetOption(option, value)
}

void EAHeap::GA_SetMallocFailureFunction(void* func, void* context) {
    // Forward to GeneralAllocator::SetMallocFailureFunction(func, context)
}
