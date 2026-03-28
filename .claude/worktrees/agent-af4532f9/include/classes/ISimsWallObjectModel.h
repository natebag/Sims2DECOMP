#ifndef ISIMSWALLOBJECTMODEL_H
#define ISIMSWALLOBJECTMODEL_H

#include "types.h"

// ISimsWallObjectModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x464 (1124 bytes)
// 12 known fields (10 named), 34 methods

class ISimsWallObjectModel {
public:
    // Constructors / Destructors
    ISimsWallObjectModel(void)  // 0x800EAC68
    ~ISimsWallObjectModel(void);  // 0x800EACC0

    // Methods
    void CreateShadow(void);  // 0x800EAD30 (144B)
    void Create(cXObject *, EHouse *);  // 0x800EADC0 (340B)
    void SetObjOrient(void);  // 0x800EAF14 (3428B)
    void SafeDelete(void);  // 0x800F5D9C (108B)
    /* ? */ GetTypeInfo(void);  // 0x800F5E08 (44B)
    /* ? */ GetTypeName(void);  // 0x800F5E34 (52B)
    /* ? */ GetTypeKey(void);  // 0x800F5E68 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800F5E9C (56B)
    void RegisterType(unsigned short);  // 0x800F5F30 (116B)
    void New(void);  // 0x800F5CC8 (76B)
    void Construct(ISimsWallObjectModel *);  // 0x800F5D14 (76B)
    void Destruct(ISimsWallObjectModel *);  // 0x800F5D60 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800F5ED4 (40B)
    /* ? */ GetReadVersion(void);  // 0x800F5EFC (52B)
    void CreateCopy(void);  // 0x800F5FA4 (68B)

    // ---- Field Layout (from assembly analysis) ----
    f32 m_objOrient;  // 0x000 [R/W] (Create, ISimsWallObjectModel, SetObjOrient, ...)
    f32 m_objOrient_004;  // 0x004 [R/W] (SetObjOrient)
    f32 m_objOrient_008;  // 0x008 [R/W] (SetObjOrient)
    u32 m_objOrient_00C;  // 0x00C [R] (SetObjOrient)
    u8 _pad_010[0x9C];  // 0x010
    f32 m_objOrient_0AC;  // 0x0AC [R/W] (SetObjOrient)
    u8 _pad_0B0[8];  // 0x0B0
    f32 m_objOrient_0B8;  // 0x0B8 [R/W] (SetObjOrient)
    u8 _pad_0BC[4];  // 0x0BC
    u32 m_objOrient_0C0;  // 0x0C0 [R] (SetObjOrient)
    u8 _pad_0C4[0x5C];  // 0x0C4
    u32 m_field_120;  // 0x120 [R] (Create)
    u8 _pad_124[0x1FC];  // 0x124
    u32 m_field_320;  // 0x320 [W] (ISimsWallObjectModel, ~ISimsWallObjectModel)
    u8 _pad_324[4];  // 0x324
    u32 m_objOrient_328;  // 0x328 [R/W] (Create, SetObjOrient)
    u8 _pad_32C[0x9C];  // 0x32C
    u32 m_objOrient_3C8;  // 0x3C8 [R/W] (Create, SetObjOrient)
    u8 _pad_3CC[0x94];  // 0x3CC
    u32 m_objOrient_460;  // 0x460 [R] (SetObjOrient)
};

#endif // ISIMSWALLOBJECTMODEL_H
