#ifndef _C2DARRAY_H
#define _C2DARRAY_H

#include "types.h"

// _c2DArray - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 5 known fields (5 named), 38 methods

class _c2DArray {
public:
    // Constructors / Destructors
    _c2DArray(int, int, int, BString &)  // 0x8028C97C
    ~_c2DArray(void);  // 0x8028CA20

    // Methods
    void SetAllocFn(void *(*);  // 0x80090480 (40B)
    void SetFreeFn(void (*);  // 0x800904A8 (40B)
    void ReadFromDisk(iResFile *, int, short, void (*);  // 0x8028C6B8 (552B)
    void Swizzle(void *, int);  // 0x8028C8E0 (156B)
    void SetSize(int, int);  // 0x8028CEB0 (760B)
    void DoStream(ReconBuffer *, bool);  // 0x8028D1A8 (1236B)
    void AddArray(_c2DArray *);  // 0x8028CACC (60B)
    void SetName(BString &);  // 0x8028D9F0 (280B)
    void ClearBytes(signed char);  // 0x8028CD8C (292B)
    /* ? */ GetFreeFn(void);  // 0x8028DEA4 (184B)
    void RemoveArray(_c2DArray *);  // 0x8028CB08 (120B)
    void WriteToDisk(iResFile *, int, short, bool);  // 0x8028CB80 (524B)
    /* ? */ GetAllocFn(void);  // 0x8028DDEC (184B)
    void CopyFrom(BString &);  // 0x8028D67C (80B)
    /* ? */ GetArray(BString &);  // 0x8028D960 (144B)
    void CopyFrom(_c2DArray *);  // 0x8028D6CC (516B)
    void CopyTo(_c2DArray *);  // 0x8028D8D0 (64B)
    void CopyTo(BString &);  // 0x8028D910 (80B)
    /* ? */ GetXSize(void);  // 0x803E46F8 (44B)
    /* ? */ GetYSize(void);  // 0x803E4724 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (SetSize, WriteToDisk)
    u32 m_size_004;  // 0x004 [R/W] (ClearBytes, CopyFrom, DoStream, ...)
    u32 m_size_008;  // 0x008 [R/W] (ClearBytes, CopyFrom, DoStream, ...)
    u32 m_size_00C;  // 0x00C [R/W] (ClearBytes, CopyFrom, DoStream, ...)
    u8 _pad_010[4];  // 0x010
    u32 m_size_014;  // 0x014 [R/W] (ClearBytes, CopyFrom, DoStream, ...)
};

#endif // _C2DARRAY_H
