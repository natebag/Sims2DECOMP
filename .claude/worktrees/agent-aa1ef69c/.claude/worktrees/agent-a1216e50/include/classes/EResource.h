#ifndef ERESOURCE_H
#define ERESOURCE_H

#include "types.h"

// EResource - struct layout extracted from assembly analysis
// Estimated minimum size: 0xE (14 bytes)
// 3 known fields (1 named), 76 methods

class EResource {
public:
    // Constructors / Destructors
    EResource(void)  // 0x808486B0
    ~EResource(void);  // 0x808487BC

    // Methods
    void DelRef(void);  // 0x80848B94 (264B)
    void AddRef(void);  // 0x80848D40 (200B)
    /* ? */ GetResId(void);  // 0x80849D14 (44B)
    /* ? */ GetResName(void);  // 0x80849E3C (72B)
    /* ? */ GetResSize(void);  // 0x80849DC8 (48B)
    /* ? */ GetNumRefs(void);  // 0x80849D68 (48B)
    bool IsManaged(void);  // 0x80849CB0 (60B)
    void Detach(void);  // 0x80848C9C (164B)
    void SetResName(char *);  // 0x80849DF8 (68B)
    void SetResSize(unsigned int);  // 0x80849D98 (48B)
    void SetResId(unsigned int);  // 0x80849D40 (40B)
    void Write(EStream &);  // 0x80848918 (128B)
    void Read(EStream &);  // 0x80848998 (260B)
    void Load(EFile &);  // 0x80848A9C (248B)
    bool IsSafeToDelete(void);  // 0x80849CEC (40B)
    void DelRefSubResources(void);  // 0x80849FE0 (32B)
    void AddRefSubResources(void);  // 0x8084A000 (32B)
    void TryIncrementSubResources(void);  // 0x8084A020 (40B)
    void DetachClone(void);  // 0x8084A048 (32B)
    void Init(void);  // 0x80849F9C (32B)
    void Refresh(EFile *);  // 0x80849FBC (36B)
    /* ? */ GetReadVersion(void);  // 0x80849BC4 (52B)
    void Refresh(void);  // 0x80848E08 (80B)
    void SafeDelete(void);  // 0x80849A64 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80849AD0 (44B)
    /* ? */ GetTypeName(void);  // 0x80849AFC (52B)
    /* ? */ GetTypeKey(void);  // 0x80849B30 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80849B64 (56B)
    void RegisterType(unsigned short);  // 0x80849BF8 (116B)
    void New(void);  // 0x80849990 (76B)
    void Construct(EResource *);  // 0x808499DC (76B)
    void Destruct(EResource *);  // 0x80849A28 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80849B9C (40B)
    void CreateCopy(void);  // 0x80849C6C (68B)
    void SetCheckPoint(unsigned int);  // 0x80849E84 (40B)
    /* ? */ GetCheckPoint(void);  // 0x80849EAC (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DelRef, ~EResource)
    u32 m_field_004;  // 0x004 [R] (DelRef, ~EResource)
    u8 _pad_008[4];  // 0x008
    s16 m_field_00C;  // 0x00C [R/W] (DelRef)
};

#endif // ERESOURCE_H
