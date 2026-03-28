#ifndef ISHRUBOBJECT_H
#define ISHRUBOBJECT_H

#include "types.h"

// IShrubObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3CC (972 bytes)
// 7 known fields (5 named), 32 methods

class IShrubObject {
public:
    // Constructors / Destructors
    IShrubObject(void)  // 0x800ED60C
    ~IShrubObject(void);  // 0x800ED664

    // Methods
    void Create(cXObject *, EHouse *);  // 0x800ED6D4 (340B)
    void SetObjOrient(void);  // 0x800ED828 (2508B)
    void SafeDelete(void);  // 0x800F66FC (108B)
    /* ? */ GetTypeInfo(void);  // 0x800F6768 (44B)
    /* ? */ GetTypeName(void);  // 0x800F6794 (52B)
    /* ? */ GetTypeKey(void);  // 0x800F67C8 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800F67FC (56B)
    void RegisterType(unsigned short);  // 0x800F6890 (116B)
    void New(void);  // 0x800F6628 (76B)
    void Construct(IShrubObject *);  // 0x800F6674 (76B)
    void Destruct(IShrubObject *);  // 0x800F66C0 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800F6834 (40B)
    /* ? */ GetReadVersion(void);  // 0x800F685C (52B)
    void CreateCopy(void);  // 0x800F6904 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Create, IShrubObject, ~IShrubObject)
    u32 m_objOrient;  // 0x004 [R] (SetObjOrient)
    u8 _pad_008[0xB8];  // 0x008
    u32 m_objOrient_0C0;  // 0x0C0 [R] (SetObjOrient)
    u8 _pad_0C4[0x5C];  // 0x0C4
    u32 m_field_120;  // 0x120 [R] (Create)
    u8 _pad_124[0x1FC];  // 0x124
    u32 m_field_320;  // 0x320 [W] (IShrubObject, ~IShrubObject)
    u8 _pad_324[4];  // 0x324
    u32 m_objOrient_328;  // 0x328 [R/W] (Create, SetObjOrient)
    u8 _pad_32C[0x9C];  // 0x32C
    u32 m_objOrient_3C8;  // 0x3C8 [R/W] (Create, SetObjOrient)
};

#endif // ISHRUBOBJECT_H
