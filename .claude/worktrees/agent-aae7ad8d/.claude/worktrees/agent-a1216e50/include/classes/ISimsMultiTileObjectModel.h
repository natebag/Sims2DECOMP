#ifndef ISIMSMULTITILEOBJECTMODEL_H
#define ISIMSMULTITILEOBJECTMODEL_H

#include "types.h"

// ISimsMultiTileObjectModel - struct layout extracted from assembly analysis
// Estimated minimum size: 0x460 (1120 bytes)
// 9 known fields (7 named), 32 methods

class ISimsMultiTileObjectModel {
public:
    // Static members (from map file)
    // static ??? _MtuliTileTweekLookupArr;
    // static ??? vOffSets;

    // Constructors / Destructors
    ISimsMultiTileObjectModel(void)  // 0x800EBDDC
    ~ISimsMultiTileObjectModel(void);  // 0x800EBE34

    // Methods
    void Create(cXObject *, EHouse *);  // 0x800EBEA4 (492B)
    void SetObjOrient(void);  // 0x800EC090 (2300B)
    void SafeDelete(void);  // 0x800F60BC (108B)
    /* ? */ GetTypeInfo(void);  // 0x800F6128 (44B)
    /* ? */ GetTypeName(void);  // 0x800F6154 (52B)
    /* ? */ GetTypeKey(void);  // 0x800F6188 (52B)
    /* ? */ GetTypeVersion(void);  // 0x800F61BC (56B)
    void RegisterType(unsigned short);  // 0x800F6250 (116B)
    void New(void);  // 0x800F5FE8 (76B)
    void Construct(ISimsMultiTileObjectModel *);  // 0x800F6034 (76B)
    void Destruct(ISimsMultiTileObjectModel *);  // 0x800F6080 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x800F61F4 (40B)
    /* ? */ GetReadVersion(void);  // 0x800F621C (52B)
    void CreateCopy(void);  // 0x800F62C4 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Create, ISimsMultiTileObjectModel, SetObjOrient, ...)
    f32 m_objOrient_004;  // 0x004 [R/W] (SetObjOrient)
    f32 m_objOrient_008;  // 0x008 [R/W] (SetObjOrient)
    u32 m_objOrient_00C;  // 0x00C [R] (SetObjOrient)
    u8 _pad_010[0x110];  // 0x010
    u32 m_field_120;  // 0x120 [R] (Create)
    u8 _pad_124[0x1FC];  // 0x124
    u32 m_field_320;  // 0x320 [W] (ISimsMultiTileObjectModel, ~ISimsMultiTileObjectModel)
    u8 _pad_324[4];  // 0x324
    u32 m_objOrient_328;  // 0x328 [R/W] (Create, SetObjOrient)
    u8 _pad_32C[0x9C];  // 0x32C
    u32 m_objOrient_3C8;  // 0x3C8 [R/W] (Create, SetObjOrient)
    u8 _pad_3CC[0x90];  // 0x3CC
    u32 m_objOrient_45C;  // 0x45C [W] (SetObjOrient)
};

#endif // ISIMSMULTITILEOBJECTMODEL_H
