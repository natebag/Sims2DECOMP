#ifndef REFFECTSATTACHMENT_H
#define REFFECTSATTACHMENT_H

#include "types.h"

// REffectsAttachment - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 6 known fields (1 named), 34 methods

class REffectsAttachment {
public:
    // Constructors / Destructors
    REffectsAttachment(void)  // 0x8087AB78
    ~REffectsAttachment(void);  // 0x8087ABEC

    // Methods
    void OldLoad(EFile *);  // 0x8087AC60 (1260B)
    void Load(EFile *);  // 0x8087B14C (812B)
    void Refresh(EFile *);  // 0x8087B478 (172B)
    void SafeDelete(void);  // 0x8087CEA0 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8087CF0C (44B)
    /* ? */ GetTypeName(void);  // 0x8087CF38 (52B)
    /* ? */ GetTypeKey(void);  // 0x8087CF6C (52B)
    /* ? */ GetTypeVersion(void);  // 0x8087CFA0 (56B)
    void RegisterType(unsigned short);  // 0x8087D034 (116B)
    void New(void);  // 0x8087CDCC (76B)
    void Construct(REffectsAttachment *);  // 0x8087CE18 (76B)
    void Destruct(REffectsAttachment *);  // 0x8087CE64 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8087CFD8 (40B)
    /* ? */ GetReadVersion(void);  // 0x8087D000 (52B)
    void CreateCopy(void);  // 0x8087D0A8 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (REffectsAttachment, ~REffectsAttachment)
    u32 m_field_004;  // 0x004 [R/W] (Load, OldLoad)
    u8 _pad_008[8];  // 0x008
    u32 m_field_010;  // 0x010 [R/W] (Load, OldLoad)
    u32 m_field_014;  // 0x014 [R/W] (Load, OldLoad, REffectsAttachment, ...)
    u32 m_field_018;  // 0x018 [R/W] (REffectsAttachment, Refresh)
    u32 m_field_01C;  // 0x01C [R/W] (Refresh)
};

#endif // REFFECTSATTACHMENT_H
