#ifndef ERDATASET_H
#define ERDATASET_H

#include "types.h"

// ERDataset - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 7 known fields (1 named), 38 methods

class ERDataset {
public:
    // Constructors / Destructors
    ERDataset(void)  // 0x8083E28C
    ~ERDataset(void);  // 0x8083E300

    // Methods
    void Deallocate(void);  // 0x8083E37C (168B)
    void AddRefSubResources(void);  // 0x8083E424 (292B)
    void DelRefSubResources(void);  // 0x8083E548 (196B)
    void TryIncrementSubResources(void);  // 0x8083E60C (352B)
    void Load(EFile *, unsigned int);  // 0x8083E76C (1840B)
    void SafeDelete(void);  // 0x8083F814 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8083F880 (44B)
    /* ? */ GetTypeName(void);  // 0x8083F8AC (52B)
    /* ? */ GetTypeKey(void);  // 0x8083F8E0 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8083F914 (56B)
    void RegisterType(unsigned short);  // 0x8083F9A8 (116B)
    void New(void);  // 0x8083F740 (76B)
    void Construct(ERDataset *);  // 0x8083F78C (76B)
    void Destruct(ERDataset *);  // 0x8083F7D8 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8083F94C (40B)
    /* ? */ GetReadVersion(void);  // 0x8083F974 (52B)
    void CreateCopy(void);  // 0x8083FA1C (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Deallocate, ERDataset, Load, ...)
    u32 m_field_004;  // 0x004 [W] (Load)
    u32 m_field_008;  // 0x008 [W] (Load)
    u8 _pad_00C[4];  // 0x00C
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (AddRefSubResources, Deallocate, DelRefSubResources, ...)
    u32 m_field_018;  // 0x018 [R/W] (Deallocate, ERDataset)
    u32 m_field_01C;  // 0x01C [R/W] (Deallocate)
};

#endif // ERDATASET_H
