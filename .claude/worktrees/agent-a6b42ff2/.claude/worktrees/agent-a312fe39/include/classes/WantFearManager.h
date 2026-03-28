#ifndef WANTFEARMANAGER_H
#define WANTFEARMANAGER_H

#include "types.h"

// WantFearManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2C (44 bytes)
// 13 known fields (6 named), 24 methods

class WantFearManager {
public:
    // Constructors / Destructors
    WantFearManager(void)  // 0x803D6D98
    ~WantFearManager(void);  // 0x803D6E08

    // Methods
    void CaptureLog(bool);  // 0x803D6E6C (36B)
    /* ? */ GetTree(unsigned short);  // 0x803D7894 (444B)
    void Lottery(unsigned int *, unsigned int);  // 0x803D80A0 (264B)
    void PickNewRoot(Neighbor *, bool);  // 0x803D7D70 (816B)
    /* ? */ GetEvent(unsigned short);  // 0x803D7620 (392B)
    /* ? */ GetStoryTreeRoot(short, short);  // 0x803D7A50 (440B)
    /* ? */ GetCategoryShader(WantFear::TargetType, short);  // 0x803D7C08 (360B)
    void LoadWants(void);  // 0x803D6E90 (1708B)
    /* ? */ GetEventByIndex(int);  // 0x803D753C (228B)
    /* ? */ GetTreeByIndex(int);  // 0x803D77A8 (236B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_tree;  // 0x000 [R/W] (GetCategoryShader, GetStoryTreeRoot, GetTree, ...)
    u8 m_field_002;  // 0x002 [R] (PickNewRoot)
    u8 _pad_003[1];  // 0x003
    u32 m_tree_004;  // 0x004 [R/W] (GetCategoryShader, GetEvent, GetStoryTreeRoot, ...)
    u16 m_event;  // 0x008 [R/W] (GetCategoryShader, GetEvent, GetStoryTreeRoot, ...)
    u8 _pad_00A[1];  // 0x00A
    u8 m_storyTreeRoot;  // 0x00B [R] (GetStoryTreeRoot)
    u32 m_tree_00C;  // 0x00C [R/W] (GetTree, LoadWants, WantFearManager)
    u32 m_field_010;  // 0x010 [R/W] (LoadWants, WantFearManager)
    u32 m_field_014;  // 0x014 [R/W] (LoadWants)
    u32 m_categoryShader;  // 0x018 [R/W] (GetCategoryShader, LoadWants, WantFearManager)
    u32 m_field_01C;  // 0x01C [W] (LoadWants)
    u32 m_field_020;  // 0x020 [W] (LoadWants)
    u32 m_field_024;  // 0x024 [W] (LoadWants)
    u32 m_field_028;  // 0x028 [W] (LoadWants)
};

#endif // WANTFEARMANAGER_H
