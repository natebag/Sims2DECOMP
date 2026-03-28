#ifndef FREERESOURCEMANAGER_H
#define FREERESOURCEMANAGER_H

#include "types.h"

// FreeResourceManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0xCA8 (3240 bytes)
// 6 known fields (2 named), 13 methods

class FreeResourceManager {
public:
    // Constructors / Destructors
    FreeResourceManager(EThreadMutex *)  // 0x8089C74C
    ~FreeResourceManager(void);  // 0x808977F0

    // Methods
    void RemoveItem(EResource *);  // 0x8089CB08 (684B)
    void AddItem(EResource *);  // 0x8089C7A8 (672B)
    /* ? */ GetUnreferencedResourceCount(void);  // 0x8089D25C (44B)
    void MakeSpace(int);  // 0x8089CDB4 (1192B)
    bool HasItem(EResource *);  // 0x8089CA48 (192B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_bHasItem;  // 0x000 [R] (HasItem, MakeSpace)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R] (MakeSpace)
    u8 _pad_014[8];  // 0x014
    u32 m_field_01C;  // 0x01C [R/W] (AddItem, FreeResourceManager, MakeSpace)
    u32 m_field_020;  // 0x020 [R] (RemoveItem)
    u8 _pad_024[0xC7C];  // 0x024
    u32 m_bHasItem_CA0;  // 0xCA0 [R/W] (AddItem, FreeResourceManager, HasItem, ...)
    u32 m_field_CA4;  // 0xCA4 [R/W] (AddItem, FreeResourceManager)
};

#endif // FREERESOURCEMANAGER_H
