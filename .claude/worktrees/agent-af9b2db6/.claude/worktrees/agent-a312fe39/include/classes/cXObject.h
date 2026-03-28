#ifndef CXOBJECT_H
#define CXOBJECT_H

#include "types.h"

// cXObject - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (2 named), 36 methods

class cXObject {
public:
    // Static members (from map file)
    // static ??? kNumTemp;
    // static ??? kNumDataDeleted;
    // static ??? kNumData;
    // static ??? s_OriginalFDataCount;

    // Constructors / Destructors
    cXObject(int)  // 0x802B88D4
    ~cXObject(void);  // 0x8029FCE4

    // Methods
    void CAST_IMPL(void);  // 0x802B8AEC (120B)
    void SetFreeWill(bool);  // 0x802A3CB8 (156B)
    void setMTObjectImpl(cXMTObjectImpl *);  // 0x802B8A6C (64B)
    void setPortalImpl(cXPortalImpl *);  // 0x802B8AAC (64B)
    /* ? */ GetPersonWidth(void);  // 0x8029FED8 (44B)
    /* ? */ GetFreeWill(void);  // 0x8029FF04 (44B)
    /* ? */ GetAutoCenter(void);  // 0x8029FF30 (44B)
    void SetAutoCenter(bool);  // 0x8029FF5C (44B)
    /* ? */ GetAutoReset(void);  // 0x8029FF88 (44B)
    void SetAutoReset(bool);  // 0x8029FFB4 (44B)
    /* ? */ GetGlobalInitTreeID(void);  // 0x8029FFE0 (36B)
    /* ? */ GetGlobalMainTreeID(void);  // 0x802A0004 (36B)
    void setObjectImpl(cXObjectImpl *);  // 0x802B89EC (64B)
    void SetGlobalFreeWillOverride(bool);  // 0x802A3D54 (44B)
    /* ? */ GetWallBlockFlagsAtTile(CTilePt &, int);  // 0x802B0BD8 (780B)
    void setPersonImpl(cXPersonImpl *);  // 0x802B8A2C (64B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_wallBlockFlagsAtTile;  // 0x000 [R/W] (GetWallBlockFlagsAtTile, cXObject, ~cXObject)
    u8 _pad_002[2];  // 0x002
    u32 m_wallBlockFlagsAtTile_004;  // 0x004 [R/W] (GetWallBlockFlagsAtTile, cXObject, ~cXObject)
};

#endif // CXOBJECT_H
