#ifndef MEMORYCARDCACHE_H
#define MEMORYCARDCACHE_H

#include "types.h"

// MemoryCardCache - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 7 known fields (4 named), 30 methods

class MemoryCardCache {
public:
    // Constructors / Destructors
    MemoryCardCache(void)  // 0x8029E6B0
    ~MemoryCardCache(void);  // 0x8029E710

    // Methods
    void PutConfig(char *, unsigned int);  // 0x80290244 (380B)
    /* ? */ GetConfig(char *, unsigned int, int);  // 0x802900B4 (400B)
    void SaveAllToMemoryCard(int);  // 0x8028FAEC (1480B)
    void LoadCacheFromMemoryCard(int);  // 0x8028F540 (88B)
    void LoadCacheFromMemoryCard(int, NghResFile *);  // 0x8028F598 (980B)
    /* ? */ GetMemoryUsage(NghLayout *);  // 0x8028EA90 (204B)
    /* ? */ GetSubSectionMemoryUsage(NghLayout *, int);  // 0x8028EB5C (316B)
    void Init(NghLayout *);  // 0x8028EC98 (476B)
    void Destroy(void);  // 0x8028EE74 (304B)
    /* ? */ GetSection(NghLayout *, char *, unsigned int, unsigned int);  // 0x8028EFA4 (336B)
    void PutSection(NghLayout *, char *, unsigned int, unsigned int);  // 0x8028F0F4 (536B)
    void CacheNghSection(NghLayout *, char *, unsigned int, unsigned int);  // 0x8028F30C (564B)
    void LoadConfigFromMemoryCard(int);  // 0x8028F96C (384B)
    void SetSourceIsFile(void);  // 0x8029E764 (40B)
    bool IsInitialized(void);  // 0x8029E78C (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Destroy, GetConfig, Init, ...)
    u32 m_subSectionMemoryUsage;  // 0x004 [R/W] (Destroy, GetMemoryUsage, GetSection, ...)
    u32 m_section;  // 0x008 [R/W] (Destroy, GetSection, Init, ...)
    u32 m_config_00C;  // 0x00C [R/W] (Destroy, GetConfig, Init, ...)
    u32 m_field_010;  // 0x010 [R/W] (Destroy, Init, PutConfig, ...)
    u32 m_field_014;  // 0x014 [R/W] (CacheNghSection, LoadCacheFromMemoryCard)
    u32 m_field_018;  // 0x018 [R/W] (Destroy, Init)
};

#endif // MEMORYCARDCACHE_H
