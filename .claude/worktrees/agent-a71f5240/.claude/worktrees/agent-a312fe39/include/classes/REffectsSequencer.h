#ifndef REFFECTSSEQUENCER_H
#define REFFECTSSEQUENCER_H

#include "types.h"

// REffectsSequencer - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 2 known fields (1 named), 40 methods

class REffectsSequencer {
public:
    // Constructors / Destructors
    REffectsSequencer(void)  // 0x8090FBA0
    ~REffectsSequencer(void);  // 0x8090FBEC

    // Methods
    void Load(EFile *);  // 0x8090FD1C (556B)
    void Deallocate(void);  // 0x8090FC58 (92B)
    void DelRefSubResources(void);  // 0x8090FCB4 (32B)
    void AddRefSubResources(void);  // 0x8090FCD4 (32B)
    void TryIncrementSubResources(void);  // 0x8090FCF4 (40B)
    void Refresh(EFile *);  // 0x8090FF48 (84B)
    void SafeDelete(void);  // 0x809100DC (108B)
    /* ? */ GetTypeInfo(void);  // 0x80910148 (44B)
    /* ? */ GetTypeName(void);  // 0x80910174 (52B)
    /* ? */ GetTypeKey(void);  // 0x809101A8 (52B)
    /* ? */ GetTypeVersion(void);  // 0x809101DC (56B)
    void RegisterType(unsigned short);  // 0x80910270 (116B)
    void New(void);  // 0x80910008 (76B)
    void Construct(REffectsSequencer *);  // 0x80910054 (76B)
    void Destruct(REffectsSequencer *);  // 0x809100A0 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80910214 (40B)
    /* ? */ GetReadVersion(void);  // 0x8091023C (52B)
    void CreateCopy(void);  // 0x809102E4 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Load, ~REffectsSequencer)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
};

#endif // REFFECTSSEQUENCER_H
