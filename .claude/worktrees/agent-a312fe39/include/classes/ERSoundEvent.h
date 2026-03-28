#ifndef ERSOUNDEVENT_H
#define ERSOUNDEVENT_H

#include "types.h"

// ERSoundEvent - struct layout extracted from assembly analysis
// Estimated minimum size: 0x34 (52 bytes)
// 4 known fields (1 named), 42 methods

class ERSoundEvent {
public:
    // Constructors / Destructors
    ERSoundEvent(void)  // 0x80871EA0
    ~ERSoundEvent(void);  // 0x80871EF8

    // Methods
    /* ? */ GetEventType(void);  // 0x80873844 (48B)
    /* ? */ GetVolume(void);  // 0x80873874 (48B)
    /* ? */ GetProb(void);  // 0x808738A4 (48B)
    void SetVolume(int);  // 0x808738D4 (44B)
    void SetProb(int);  // 0x80873900 (44B)
    void Load(EFile *);  // 0x80871F6C (1992B)
    void Refresh(EFile *);  // 0x80872734 (76B)
    void SafeDelete(void);  // 0x8087353C (108B)
    /* ? */ GetTypeInfo(void);  // 0x808735A8 (44B)
    /* ? */ GetTypeName(void);  // 0x808735D4 (52B)
    /* ? */ GetTypeKey(void);  // 0x80873608 (52B)
    /* ? */ GetTypeVersion(void);  // 0x8087363C (56B)
    void RegisterType(unsigned short);  // 0x808736D0 (116B)
    void New(void);  // 0x80873468 (76B)
    void Construct(ERSoundEvent *);  // 0x808734B4 (76B)
    void Destruct(ERSoundEvent *);  // 0x80873500 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80873674 (40B)
    /* ? */ GetReadVersion(void);  // 0x8087369C (52B)
    void CreateCopy(void);  // 0x80873744 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERSoundEvent, ~ERSoundEvent)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u8 _pad_014[0x10];  // 0x014
    u32 m_field_024;  // 0x024 [R] (Load)
    u8 _pad_028[8];  // 0x028
    u32 m_field_030;  // 0x030 [W] (Load)
};

#endif // ERSOUNDEVENT_H
