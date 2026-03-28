#ifndef CSOUNDCACHEITEM_H
#define CSOUNDCACHEITEM_H

#include "types.h"

// cSoundCacheItem - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 4 known fields (1 named), 17 methods

class cSoundCacheItem {
public:
    // Constructors / Destructors
    cSoundCacheItem(unsigned int)  // 0x8023F1F4
    ~cSoundCacheItem(void);  // 0x8023F4B8

    // Methods
    void ResetUsageTimer(void);  // 0x8023F228 (60B)
    void Update(void);  // 0x8023F264 (596B)
    bool CanUnload(void);  // 0x802490F4 (92B)
    /* ? */ GetLastTimeUsed(void);  // 0x80248D48 (44B)
    bool IsLoaded(void);  // 0x80249150 (44B)
    void destroy(void);  // 0x80248B70 (72B)
    void AddRef(void);  // 0x80248C68 (56B)
    bool HasBeenWaitingForAWhile(void);  // 0x8024917C (76B)
    void DelRef(void);  // 0x80248CA0 (168B)
    void hash(void);  // 0x80249D18 (44B)
    void compare(unsigned int);  // 0x80249D44 (60B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R] - vtable pointer (Update, ~cSoundCacheItem)
    u8 _pad_004[8];  // 0x004
    u32 m_field_00C;  // 0x00C [R/W] (Update)
    u32 m_field_010;  // 0x010 [R/W] (Update, ~cSoundCacheItem)
    u32 m_field_014;  // 0x014 [R/W] (Update)
};

#endif // CSOUNDCACHEITEM_H
