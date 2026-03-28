#ifndef EBITARRAY_H
#define EBITARRAY_H

#include "types.h"

// EBitArray - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (4 named), 114 methods

class EBitArray {
public:
    // Constructors / Destructors
    EBitArray(void)  // 0x807930E0
    EBitArray(int)  // 0x807931A0
    EBitArray(int, int)  // 0x8079321C
    EBitArray(EBitArray &)  // 0x8079329C
    ~EBitArray(void);  // 0x807957AC

    // Methods
    /* ? */ GetSize(void);  // 0x8079584C (44B)
    /* ? */ Get(int, int);  // 0x80794B0C (396B)
    void SignedBitsToFloatScaler(int);  // 0x807952B0 (240B)
    void UnsignedBitsToFloatScaler(int);  // 0x807953A0 (236B)
    /* ? */ GetFloat(int);  // 0x80794C98 (100B)
    /* ? */ GetSigned(int, int);  // 0x80794CFC (228B)
    void Set(int, bool);  // 0x80793558 (304B)
    /* ? */ Get(int);  // 0x80793438 (288B)
    void SetGrowBy(int);  // 0x807937F0 (52B)
    void SetSize(int, int);  // 0x80793824 (684B)
    void operator=(EBitArray &);  // 0x80794068 (128B)
    void AllocateMemory(unsigned long);  // 0x80793314 (88B)
    void FreeMemory(void *);  // 0x8079336C (84B)
    void Deallocate(void);  // 0x807933C0 (120B)
    void SetAll(bool);  // 0x80793688 (220B)
    /* ? */ GetElementCount(void);  // 0x807940E8 (56B)
    void InvertAll(void);  // 0x80793764 (140B)
    void Clear(int);  // 0x80795AA4 (68B)
    void Insert(bool, int);  // 0x80793AD0 (88B)
    void InsertElements(int, int);  // 0x80793D94 (396B)
    void Set(EBitArray &, int, int, int);  // 0x80793B28 (400B)
    void Insert(EBitArray &, int, int, int);  // 0x80793CB8 (220B)
    void Remove(int, int);  // 0x80793F20 (328B)
    void operator|=(EBitArray &);  // 0x80794120 (292B)
    void operator&=(EBitArray &);  // 0x80794244 (292B)
    void operator^=(EBitArray &);  // 0x80794368 (292B)
    void operator==(EBitArray &);  // 0x8079448C (228B)
    void Intersection(EBitArray &);  // 0x80794570 (308B)
    void Interleave(int, int, int);  // 0x807946A4 (308B)
    void Deinterleave(int, int, int);  // 0x807947D8 (308B)
    void Print(void);  // 0x8079490C (172B)
    void Add(unsigned int, int);  // 0x807949B8 (260B)
    void Add(bool);  // 0x807958D4 (80B)
    void Add(float);  // 0x80794ABC (80B)
    void ToleranceToSignedBits(float);  // 0x80794DE0 (188B)
    void ToleranceToUnsignedBits(float);  // 0x80794E9C (184B)
    void MaxNumberToUnsignedBits(int);  // 0x80794F54 (124B)
    void FloatToSignedBits(float, int);  // 0x80794FD0 (392B)
    void FloatToUnsignedBits(float, int);  // 0x80795158 (344B)
    /* ? */ GetAllocByteCount(void);  // 0x8079548C (80B)
    void FreeUnusedBufferSpace(void);  // 0x8079580C (64B)
    void Insert(EBitArray &, int);  // 0x80795878 (92B)
    void Add(EBitArray &);  // 0x80795924 (80B)
    void Add(EBitArray &, int, int);  // 0x80795974 (96B)
    bool IsEmpty(void);  // 0x807959D4 (80B)
    void Empty(void);  // 0x80795A24 (64B)
    void RemoveAll(void);  // 0x80795A64 (64B)
    void ClearAll(void);  // 0x80795AE8 (60B)
    void operator[](int);  // 0x80795B24 (184B)
    void operator!=(EBitArray &);  // 0x80795C9C (80B)
    /* ? */ GetBuffer(void);  // 0x80795CEC (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Deallocate, EBitArray, Get, ...)
    u32 m_size_004;  // 0x004 [R/W] (Add, Deallocate, EBitArray, ...)
    u32 m_size_008;  // 0x008 [R/W] (Deallocate, EBitArray, InsertElements, ...)
    u32 m_field_00C;  // 0x00C [R] (InsertElements)
    u32 m_size_010;  // 0x010 [R/W] (Deallocate, Deinterleave, EBitArray, ...)
};

#endif // EBITARRAY_H
