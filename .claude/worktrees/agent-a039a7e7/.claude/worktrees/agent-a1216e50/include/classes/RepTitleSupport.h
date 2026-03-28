#ifndef REPTITLESUPPORT_H
#define REPTITLESUPPORT_H

#include "types.h"

// RepTitleSupport - struct layout extracted from assembly analysis
// Estimated minimum size: 0x1C (28 bytes)
// 5 known fields (5 named), 14 methods

class RepTitleSupport {
public:
    // Methods
    /* ? */ GetRepTitleRepValue(int);  // 0x804C0E1C (484B)
    /* ? */ GetRepTitleLevel(int);  // 0x804C0DC4 (88B)
    /* ? */ GetRepTitleTitle(int);  // 0x804C1108 (900B)
    /* ? */ GetRepTitleRaw(int, RepTitleSupport::eRepTitleRaw);  // 0x804C0B34 (656B)
    /* ? */ GetRepTableRawTitle(int);  // 0x804C1000 (88B)
    /* ? */ GetRepTableRawFriendTitle(int);  // 0x804C1058 (88B)
    /* ? */ GetRepTableRawEnemyTitle(int);  // 0x804C10B0 (88B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (GetRepTitleRaw, GetRepTitleRepValue, GetRepTitleTitle)
    u32 m_repTitleTitle;  // 0x004 [R] (GetRepTitleRaw, GetRepTitleTitle)
    u32 m_repTitleRaw;  // 0x008 [R] (GetRepTitleRaw)
    u8 _pad_00C[4];  // 0x00C
    u32 m_repTitleRaw_010;  // 0x010 [R] (GetRepTitleRaw)
    u8 _pad_014[4];  // 0x014
    u32 m_repTitleRaw_018;  // 0x018 [R] (GetRepTitleRaw)
};

#endif // REPTITLESUPPORT_H
