#ifndef ISIMSCOUNTERTOPOBJECT_H
#define ISIMSCOUNTERTOPOBJECT_H

#include "types.h"

// ISimsCounterTopObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3D0 (976 bytes)
// 10 known fields (9 named), 34 methods

class ISimsCounterTopObject {
public:
    // Constructors / Destructors
    ISimsCounterTopObject(void)  // 0x800ECAD8
    ~ISimsCounterTopObject(void);  // 0x800ECB30

    // Methods
    void Create(cXObject *, EHouse *);  // 0x800ECBA0 (284B)
    void SetObjOrient(void);  // 0x800ECCBC (2052B)
    bool IsSinkId(cXObject *);  // 0x800F8324 (256B)
    void SafeDelete(void);  // 0x800F63DC (108B)
    /* ? */ GetTypeInfo(void);  // 0x800F6448 (44B)
    /* ? */ GetTypeName(void);  // 0x800F6474 (52B)
    /* ? */ GetTypeKey(void);  // 0x800F64A8 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800F64DC (56B)
    void RegisterType(unsigned short);  // 0x800F6570 (116B)
    void New(void);  // 0x800F6308 (76B)
    void Construct(ISimsCounterTopObject *);  // 0x800F6354 (76B)
    void Destruct(ISimsCounterTopObject *);  // 0x800F63A0 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800F6514 (40B)
    /* ? */ GetReadVersion(void);  // 0x800F653C (52B)
    void CreateCopy(void);  // 0x800F65E4 (68B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_objOrient;  // 0x000 [R/W] (ISimsCounterTopObject, SetObjOrient, ~ISimsCounterTopObject)
    u8 _pad_002[2];  // 0x002
    u32 m_objOrient_004;  // 0x004 [R] (SetObjOrient)
    u32 m_objOrient_008;  // 0x008 [R] (SetObjOrient)
    u8 _pad_00C[0x10];  // 0x00C
    u32 m_objOrient_01C;  // 0x01C [W] (SetObjOrient)
    u8 _pad_020[8];  // 0x020
    u32 m_objOrient_028;  // 0x028 [W] (SetObjOrient)
    u8 _pad_02C[0x94];  // 0x02C
    u32 m_objOrient_0C0;  // 0x0C0 [R] (IsSinkId, SetObjOrient)
    u8 _pad_0C4[0x25C];  // 0x0C4
    u32 m_field_320;  // 0x320 [W] (ISimsCounterTopObject, ~ISimsCounterTopObject)
    u8 _pad_324[4];  // 0x324
    u32 m_objOrient_328;  // 0x328 [R] (SetObjOrient)
    u8 _pad_32C[0x9C];  // 0x32C
    u32 m_objOrient_3C8;  // 0x3C8 [R/W] (SetObjOrient)
    u32 m_objOrient_3CC;  // 0x3CC [R/W] (SetObjOrient)
};

#endif // ISIMSCOUNTERTOPOBJECT_H
