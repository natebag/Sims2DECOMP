#ifndef RELMATRIXIMPL_H
#define RELMATRIXIMPL_H

#include "types.h"

// RelMatrixImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x40 (64 bytes)
// 6 known fields (3 named), 30 methods

class RelMatrixImpl {
public:
    // Constructors / Destructors
    RelMatrixImpl(void)  // 0x80399D84
    ~RelMatrixImpl(void);  // 0x80398114

    // Methods
    void Init(void);  // 0x803971F0 (40B)
    void CopyTo(RelMatrix &);  // 0x80397218 (336B)
    /* ? */ GetArraySize(int);  // 0x80397368 (136B)
    void FindArray(int);  // 0x80397714 (160B)
    void RemoveArray(int);  // 0x803973F0 (200B)
    void SetArraySize(int, int);  // 0x803974B8 (500B)
    void CreateNewArray(int);  // 0x803976AC (104B)
    /* ? */ GetValue(int, int);  // 0x803977B4 (392B)
    void SetValue(int, int, int);  // 0x8039793C (1088B)
    void DoStream(ReconBuffer *, int);  // 0x80397D7C (624B)
    void Clear(void);  // 0x80398064 (176B)
    void CountKeys(void);  // 0x80398178 (72B)
    /* ? */ GetNthKey(int);  // 0x803981C0 (140B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CreateNewArray, DoStream, GetArraySize, ...)
    u32 m_value;  // 0x004 [R/W] (Clear, CopyTo, CreateNewArray, ...)
    u32 m_arraySize_008;  // 0x008 [R] (GetArraySize, SetValue)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [W] (CreateNewArray, DoStream)
    u8 _pad_014[0x24];  // 0x014
    s16 m_field_038;  // 0x038 [R] (DoStream)
    u8 _pad_03A[2];  // 0x03A
    u32 m_field_03C;  // 0x03C [R] (DoStream)
};

#endif // RELMATRIXIMPL_H
