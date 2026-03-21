// eaheap.h - EAHeap and FPHeap class declarations
// From: base_ngc_release_dvd.lib(e_standard_heap.obj)

#ifndef EAHEAP_H
#define EAHEAP_H

#include "core/eageneralallocator.h"
#include "core/fastallocpool.h"

// AllocPoolManager template - manages a fixed array of alloc pools
// The Validate function iterates pools with a stride, calling Validate on each
template <typename T>
class AllocPoolManager {
public:
    int m_count;        // 0x00
    int m_pad;          // 0x04
    char m_poolData[1]; // 0x08 (raw pool data, accessed with stride)

    void Validate(void);
};

class EAHeap : public EA::Allocator::GeneralAllocator {
public:
    // Offsets from EAHeap constructor:
    // 0x528: m_name (char*)
    // 0x52C: m_parentHeap (EAHeap*)
    // 0x530: m_auxHeap (EAHeap*)
    char* m_name;           // 0x528
    EAHeap* m_parentHeap;   // 0x52C
    EAHeap* m_auxHeap;      // 0x530

    EAHeap(char* name, void* buffer, unsigned int size, EAHeap* parent, EAHeap* auxHeap);

    void Init(void* buffer, unsigned int size);
    void* Malloc(unsigned int size, int align);
    void Free(void* ptr);
    void Clear(void);
    void Compact(void);
    void ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel level);
    EAHeap* FindHeapForAddress(void* addr) const;

    void SetNextCheckPoint(void);
    static int GetCurrentCheckPoint(void);
    void ValidatePools(void);

    static AllocPoolManager<ProtectedAllocPool>* s_poolBlocks;  // via SDA
};

class FPHeap : public EAHeap {
public:
    FPHeap(char* name, void* buffer, unsigned int size, EAHeap* parent, EAHeap* auxHeap);

    void* Malloc(unsigned int size, int align);
    void Free(void* ptr);
    void ValidatePools(void);
};

// Global heap accessor functions
extern "C" {
    EAHeap* RootHeap(void);
    EAHeap* MainHeap(void);
    EAHeap* ResourceHeap(void);
    EAHeap* VMHeap(void);
    EAHeap* DebugHeap(void);
    EAHeap* CUIHeap(void);
    EAHeap* AudioHeap(void);
    EAHeap* ShaderHeap(void);
    EAHeap* TextureHeap(void);
    EAHeap* AnimationHeap(void);
    EAHeap* ModelHeap(void);
    EAHeap* FlashesHeap(void);
    EAHeap* AptHeap(void);
}

// C allocator functions
extern "C" {
    void* malloc(unsigned int size);
    void free(void* ptr);
    void* realloc(void* ptr, unsigned int size);
    void* calloc(unsigned int count, unsigned int size);
    void* memalign(unsigned int align, unsigned int size);
}

// C++ allocator functions
void* __builtin_new(unsigned int size);
void* __builtin_vec_new(unsigned int size);
void __builtin_delete(void* ptr);
void __builtin_vec_delete(void* ptr);

// Default allocator helpers
void* DefaultAlloc(unsigned int size);
void DefaultFree(void* ptr);

// Global checkpoint variable (SDA)
extern int g_currentCheckPoint;

#endif // EAHEAP_H
