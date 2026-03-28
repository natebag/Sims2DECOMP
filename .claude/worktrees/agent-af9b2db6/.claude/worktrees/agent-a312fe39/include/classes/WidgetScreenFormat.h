#ifndef WIDGETSCREENFORMAT_H
#define WIDGETSCREENFORMAT_H

#include "types.h"

// WidgetScreenFormat - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 9 known fields (7 named), 18 methods

class WidgetScreenFormat {
public:
    // Constructors / Destructors
    WidgetScreenFormat(void)  // 0x8049AF50
    ~WidgetScreenFormat(void);  // 0x8049AF98

    // Methods
    void LaunchWidgetScreenLayout(char **, int, int);  // 0x8049B008 (356B)
    void IterateScreenLayout(char **, WidgetScreenFormat::IterationType);  // 0x8049B16C (228B)
    void IterateTags(WidgetScreenFormat::IterationType);  // 0x8049B250 (720B)
    /* ? */ GetNextTag(WidgetScreenFormat::IterationType);  // 0x8049B520 (824B)
    bool IsValidTag(char *);  // 0x8049B858 (248B)
    bool IsDataValid(char *);  // 0x8049B950 (2240B)
    bool IsPlayerSpecificTag(char *);  // 0x8049C210 (376B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetNextTag, IterateScreenLayout, IterateTags)
    u32 m_nextTag_004;  // 0x004 [R/W] (GetNextTag, IterateScreenLayout, IterateTags)
    u32 m_nextTag_008;  // 0x008 [R/W] (GetNextTag, IsDataValid)
    u32 m_nextTag_00C;  // 0x00C [R/W] (GetNextTag, IterateScreenLayout, IterateTags, ...)
    u32 m_field_010;  // 0x010 [R/W] (LaunchWidgetScreenLayout, ~WidgetScreenFormat)
    u32 m_nextTag_014;  // 0x014 [R/W] (GetNextTag, IterateTags, LaunchWidgetScreenLayout)
    u32 m_nextTag_018;  // 0x018 [R/W] (GetNextTag, IterateTags)
    u32 m_field_01C;  // 0x01C [W] (LaunchWidgetScreenLayout)
    u8 m_nextTag_01F;  // 0x01F [R] (GetNextTag)
};

#endif // WIDGETSCREENFORMAT_H
