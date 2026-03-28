// e_storable.cpp - EChecksum, EStorable, EBitArray functions
// From: base_ngc_release_dvd.lib(e_checksum.obj, e_storable.obj, e_bitarray.obj)
// Small functions (<=64 bytes) decompiled from these objects

#include "core/e_storable.h"

// External function declarations
extern "C" void* __builtin_new(unsigned int size);

// Forward declarations for called functions
class EAHeap;
extern EAHeap* MainHeap(void);
extern "C" void* EAHeap_Malloc(EAHeap* heap, unsigned int size, int align);
extern "C" void EAHeap_Free(EAHeap* heap, void* ptr);

// EStorable vtable pointer constant
// The vtable for EStorable is at 0x804690c8
// The value stored at obj+0 is the vtable address
extern "C" void* EStorable_vtable[]; // at 0x804690c8

// ============================================================================
// EChecksum small functions from e_checksum.obj
// ============================================================================

// EChecksum::FNVHashString - 0x802c5f98 (56 bytes)
// NON_MATCHING - loop structure and compare/xor order differ
// FNV-1a style hash of a null-terminated string
u32 EChecksum::FNVHashString(char* str, unsigned int basis) {
    u32 hash = basis;
    char c = *str;
    if (c == 0) return hash;
    do {
        hash = hash * 0x01000193;
        hash ^= (int)(signed char)c;
        c = *++str;
    } while (c != 0);
    return hash;
}

// ============================================================================
// EStorable small functions from e_storable.obj
// ============================================================================

// EStorable::AssertValid - 0x802d1420 (32 bytes)
// Asserts that this object is derived from the given type
void EStorable::AssertValid(ETypeInfo* typeInfo) const {
    IsDerivedFrom(typeInfo);
}

// EStorable::New - 0x803c2448 (52 bytes)
// Allocates a new EStorable and sets its vtable
EStorable* EStorable::New(void) {
    EStorable* obj = (EStorable*)__builtin_new(4);
    *(void**)obj = EStorable_vtable;
    return obj;
}

// EStorable::Construct - 0x803c247c (16 bytes)
// Placement-constructs an EStorable (just sets vtable)
void EStorable::Construct(EStorable* obj) {
    *(void**)obj = EStorable_vtable;
}

// EStorable::Destruct - 0x803c248c (36 bytes)
// NON_MATCHING - calls ~EStorable with deleting flag via vtable dispatch
// Original: li r4,2; bl EStorable::~EStorable
extern void EStorable_Destructor(EStorable* obj, int flags);
void EStorable::Destruct(EStorable* obj) {
    EStorable_Destructor(obj, 2);
}

// ============================================================================
// EBitArray small functions from e_bitarray.obj
// ============================================================================

// EBitArrayProxy::operator=(bool) - 0x802df398 (44 bytes)
// NON_MATCHING - original calls Set as bl, ours inlines it
// Sets the proxied bit to value
void EBitArrayProxy::operator=(bool val) {
    m_array->Set(m_index, val);
}

// EBitArrayProxy::operator bool - 0x802df51c (40 bytes)
// NON_MATCHING - original calls Get as bl, ours inlines it
// Returns the proxied bit value
EBitArrayProxy::operator bool(void) {
    return m_array->Get(m_index);
}

// EBitArray::Get(int) const - 0x802df780 (64 bytes)
// NON_MATCHING - original uses rlwinm for >>5 and &31, ours uses srawi+slwi
// Gets a single bit by index, returns 0 or 1
int EBitArray::Get(int index) const {
    if (index >= m_size) {
        return 0;
    }
    int wordIndex = index >> 5;
    int bitIndex = index & 31;
    u32 mask = 1 << bitIndex;
    if (m_buffer[wordIndex] & mask) {
        return 1;
    }
    return 0;
}

// EBitArray::Set(int, bool) - 0x802df7c0 (60 bytes)
// NON_MATCHING - original uses rlwinm for >>5, ours uses srawi+slwi. Register order differs.
// Sets or clears a single bit by index
void EBitArray::Set(int index, bool value) {
    int wordIndex = index >> 5;
    int bitIndex = index & 31;
    u32 mask = 1 << bitIndex;
    if (value) {
        m_buffer[wordIndex] |= mask;
    } else {
        m_buffer[wordIndex] &= ~mask;
    }
}

// EBitArray::SetGrowBy - 0x802df8dc (16 bytes)
// Sets grow-by amount, rounded up to multiple of 32
void EBitArray::SetGrowBy(int growBy) {
    m_growBy = (growBy + 31) & ~31;
}

// EBitArray::AllocateMemory - 0x802df6bc (56 bytes)
// Allocates memory through MainHeap
void* EBitArray::AllocateMemory(unsigned long size) {
    EAHeap* heap = MainHeap();
    return EAHeap_Malloc(heap, size, 0);
}

// EBitArray::FreeMemory - 0x802df6f4 (56 bytes)
// Frees memory through MainHeap, with null check
void EBitArray::FreeMemory(void* ptr) {
    if (ptr != 0) {
        EAHeap* heap = MainHeap();
        EAHeap_Free(heap, ptr);
    }
}

// EBitArray::GetElementCount - 0x802dfcc4 (16 bytes)
// Returns number of 32-bit words needed
int EBitArray::GetElementCount(void) const {
    return (m_size + 31) >> 5;
}

// EBitArray::Print - 0x802e00ac (4 bytes)
// No-op stub
void EBitArray::Print(void) {
}

// EBitArray::Add(float) - 0x802e011c (44 bytes)
// Adds a float as 32 raw bits
void EBitArray::Add(float value) {
    // Reinterpret float bits as unsigned int
    union { float f; unsigned int u; } conv;
    conv.f = value;
    Add(conv.u, 32);
}

// EBitArray::GetFloat - 0x802e01f0 (48 bytes)
// Gets 32 bits and reinterprets as float
float EBitArray::GetFloat(int start) const {
    unsigned int bits = Get(start, 32);
    union { unsigned int u; float f; } conv;
    conv.u = bits;
    return conv.f;
}

// EBitArray::MaxNumberToUnsignedBits - 0x802e03c0 (52 bytes)
// NON_MATCHING - loop unrolled differently by compiler
// Returns minimum number of bits to represent maxNum
int EBitArray::MaxNumberToUnsignedBits(int maxNum) {
    int bits = 1;
    if (maxNum <= 1) return bits;
    do {
        bits++;
        if (bits > 31) return bits;
    } while (maxNum > (1 << bits) - 1);
    return bits;
}

// EBitArray::GetAllocByteCount - 0x802e05a0 (36 bytes)
// Returns allocated byte count, or 0 if no buffer
int EBitArray::GetAllocByteCount(void) {
    if (m_buffer == 0) {
        return 0;
    }
    return ((m_size + 31) >> 5) * 4;
}

// EBitArray::FreeUnusedBufferSpace - 0x802e0744 (40 bytes)
// Resizes to exact current size (trims excess allocation)
void EBitArray::FreeUnusedBufferSpace(void) {
    SetSize(m_size, 0);
}

// EBitArray::GetSize - 0x802e076c (8 bytes)
// Returns number of bits
int EBitArray::GetSize(void) const {
    return m_size;
}

// EBitArray::Insert(EBitArray&, int) - 0x802e0774 (44 bytes)
// Inserts entire other array at given position
void EBitArray::Insert(EBitArray& src, int index) {
    Insert(src, 0, index, src.m_size);
}

// EBitArray::Add(bool) - 0x802e07a0 (36 bytes)
// Appends a single bit
void EBitArray::Add(bool value) {
    Insert(value, m_size);
}

// EBitArray::Add(EBitArray&) - 0x802e07c4 (44 bytes)
// Appends entire other array
void EBitArray::Add(EBitArray& src) {
    Insert(src, 0, m_size, src.m_size);
}

// EBitArray::Add(EBitArray&, int, int) - 0x802e07f0 (40 bytes)
// Appends a range from another array
void EBitArray::Add(EBitArray& src, int start, int count) {
    Insert(src, start, m_size, count);
}

// EBitArray::IsEmpty - 0x802e0818 (16 bytes)
// NON_MATCHING - original uses subfic+adde idiom, ours uses cntlzw+srwi
// Returns 1 if size is 0, else 0
int EBitArray::IsEmpty(void) const {
    return m_size == 0;
}

// EBitArray::Empty - 0x802e0828 (40 bytes)
// Resets to empty (size 0, no allocation)
void EBitArray::Empty(void) {
    SetSize(0, 0);
}

// EBitArray::RemoveAll - 0x802e0850 (40 bytes)
// Same as Empty
void EBitArray::RemoveAll(void) {
    SetSize(0, 0);
}

// EBitArray::Clear(int) - 0x802e0878 (36 bytes)
// NON_MATCHING - original calls Set() via bl, ours inlines it
// Clears a single bit
void EBitArray::Clear(int index) {
    Set(index, false);
}

// EBitArray::ClearAll - 0x802e089c (36 bytes)
// Sets all bits to false
void EBitArray::ClearAll(void) {
    SetAll(false);
}

// EBitArray::operator[](int) const - 0x802e08c0 (32 bytes)
// Returns bit value at index
int EBitArray::operator[](int index) const {
    return Get(index);
}

// EBitArray::operator[](int) - 0x802e08e0 (16 bytes)
// NON_MATCHING - Returns proxy for bit manipulation
// Original stores via hidden return ptr: stw this,0(retptr); stw index,4(retptr)
// devkitPPC optimizes this away entirely since proxy is trivial struct
EBitArrayProxy EBitArray::operator[](int index) {
    EBitArrayProxy proxy;
    proxy.m_array = this;
    proxy.m_index = index;
    return proxy;
}

// EBitArray::operator!=(EBitArray&) const - 0x802e08f0 (36 bytes)
// Returns negation of operator==
int EBitArray::operator!=(EBitArray& other) const {
    return (*this == other) ^ 1;
}

// EBitArray::GetBuffer - 0x802e0914 (8 bytes)
// Returns raw buffer pointer
u32* EBitArray::GetBuffer(void) {
    return m_buffer;
}
