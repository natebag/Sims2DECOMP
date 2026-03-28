#ifndef E_STORABLE_H
#define E_STORABLE_H

#include "types.h"

// Forward declarations
class EStream;
class ETypeInfo;

// EChecksum - CRC/hash utility class
class EChecksum {
public:
    static u32 m_table[256]; // CRC table at 0x8043e928

    static u32 Compute(void* data, int len);
    static u32 Compute(char* str);
    static u32 ComputeSymbol(char* str, unsigned int seed);
    static u32 FNVHashString(char* str, unsigned int basis);
    static u64 FNVHashString64(char* str, unsigned long long basis);
};

// EStorable - Base class for serializable objects
// Layout: vtable pointer at 0x00 (4 bytes total)
class EStorable {
public:
    // Virtual destructor via vtable
    // vtable at 0x804690c8

    EStorable* CreateCopy(void) const;
    void AssertValid(ETypeInfo* typeInfo) const;
    int IsDerivedFrom(ETypeInfo* typeInfo) const;
    int IsExactType(ETypeInfo* typeInfo) const;
    EStorable* DynamicCast(ETypeInfo* typeInfo) const;
    EStorable* DynamicCast(ETypeInfo* typeInfo);

    // TArray-style helpers
    static EStorable* New(void);
    static void Construct(EStorable* obj);
    static void Destruct(EStorable* obj);
};

extern ETypeInfo* gpTypeInfo_EStorable;

// EBitArrayProxy - Proxy object for individual bit access
// Layout: EBitArray* m_array at 0x00, int m_index at 0x04
class EBitArray;

class EBitArrayProxy {
public:
    EBitArray* m_array; // 0x00
    int m_index;        // 0x04

    void operator=(bool val);
    void operator|=(bool val);
    void operator&=(bool val);
    void operator^=(bool val);
    operator bool(void);
};

// EBitArray - Dynamically-sized bit array
// Layout:
//   0x00: u32* m_buffer      - pointer to bit data
//   0x04: int  m_size         - number of bits
//   0x08: int  m_allocSize    - allocated size in bits
//   0x0C: int  m_growBy       - grow increment in bits (rounded to 32)
//   0x10: void* m_vtable      - vtable pointer
class EBitArray {
public:
    u32* m_buffer;     // 0x00
    int m_size;        // 0x04
    int m_allocSize;   // 0x08
    int m_growBy;      // 0x0C
    // vtable at 0x10

    // Constructors
    EBitArray(void);
    EBitArray(int size);
    EBitArray(int size, int growBy);
    EBitArray(EBitArray& other);
    ~EBitArray(void);

    // Assignment
    EBitArray& operator=(EBitArray& other);

    // Bit access
    int Get(int index) const;
    void Set(int index, bool value);
    void SetAll(bool value);
    void InvertAll(void);
    void SetGrowBy(int growBy);

    // Resize
    void SetSize(int newSize, int growBy);

    // Memory
    void* AllocateMemory(unsigned long size);
    void FreeMemory(void* ptr);
    void Deallocate(void);

    // Insert/Remove
    void Insert(bool value, int index);
    void InsertElements(int index, int count);
    void Set(EBitArray& src, int srcStart, int dstStart, int count);
    void Insert(EBitArray& src, int srcStart, int dstStart, int count);
    void Insert(EBitArray& src, int index);
    void Remove(int index, int count);

    // Bitwise operators
    EBitArray& operator|=(EBitArray& other);
    EBitArray& operator&=(EBitArray& other);
    EBitArray& operator^=(EBitArray& other);
    int operator==(EBitArray& other) const;
    int operator!=(EBitArray& other) const;
    int Intersection(EBitArray& other) const;

    // Interleave
    void Interleave(int start, int stride, int count);
    void Deinterleave(int start, int stride, int count);

    // Add data
    void Add(unsigned int value, int bitCount);
    void Add(float value);
    void Add(bool value);
    void Add(EBitArray& src);
    void Add(EBitArray& src, int start, int count);

    // Get data
    unsigned int Get(int start, int bitCount) const;
    float GetFloat(int start) const;
    int GetSigned(int start, int bitCount) const;

    // Conversion utilities
    static int ToleranceToSignedBits(float tolerance);
    static int ToleranceToUnsignedBits(float tolerance);
    static int MaxNumberToUnsignedBits(int maxNum);
    static int FloatToSignedBits(float value, int bits);
    static int FloatToUnsignedBits(float value, int bits);
    static float SignedBitsToFloatScaler(int bits);
    static float UnsignedBitsToFloatScaler(int bits);

    // Query
    int GetSize(void) const;
    int GetElementCount(void) const;
    int GetAllocByteCount(void);
    int IsEmpty(void) const;
    u32* GetBuffer(void);

    // Clear
    void Empty(void);
    void RemoveAll(void);
    void Clear(int index);
    void ClearAll(void);
    void FreeUnusedBufferSpace(void);

    // Subscript
    int operator[](int index) const;
    EBitArrayProxy operator[](int index);

    // Debug
    void Print(void);
};

// Free operators
EStream& operator<<(EStream& stream, EBitArray& arr);
EStream& operator>>(EStream& stream, EBitArray& arr);

#endif // E_STORABLE_H
