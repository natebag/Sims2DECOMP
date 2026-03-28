#ifndef OBJECTDATABEHAVIORCONSTANTS_H
#define OBJECTDATABEHAVIORCONSTANTS_H

#include "types.h"

// ObjectDataBehaviorConstants - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 4 known fields (4 named), 28 methods

class ObjectDataBehaviorConstants {
public:
    // Constructors / Destructors
    ObjectDataBehaviorConstants(void)  // 0x803F5790
    ObjectDataBehaviorConstants(ObjectDataBehaviorConstants &)  // 0x803F5808
    ~ObjectDataBehaviorConstants(void);  // 0x803F5978

    // Methods
    void CountValues(void);  // 0x803F5A74 (52B)
    void SetValueCount(int);  // 0x803F5BA8 (404B)
    bool IsTuning(void);  // 0x803F5D3C (56B)
    void SetIsTuning(bool);  // 0x803F5D74 (84B)
    /* ? */ GetValueName(int);  // 0x803F5AA8 (92B)
    void SetValue(int, short);  // 0x803F5B04 (76B)
    void SetValueName(int, char *);  // 0x803F5B50 (88B)
    /* ? */ GetResourceName(StringBuffer &);  // 0x803F5DC8 (68B)
    void SetResourceName(StringBuffer &);  // 0x803F5E0C (44B)
    /* ? */ GetDataID(void);  // 0x803F736C (80B)
    /* ? */ GetValue(int);  // 0x803F7328 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ObjectDataBehaviorConstants, ~ObjectDataBehaviorConstants)
    u16 m_valueCount;  // 0x004 [R/W] (ObjectDataBehaviorConstants, SetValueCount)
    u8 _pad_006[0xA];  // 0x006
    u32 m_valueCount_010;  // 0x010 [R/W] (ObjectDataBehaviorConstants, SetValueCount, ~ObjectDataBehaviorConstants)
    u32 m_valueCount_014;  // 0x014 [R/W] (ObjectDataBehaviorConstants, SetValueCount, ~ObjectDataBehaviorConstants)
};

#endif // OBJECTDATABEHAVIORCONSTANTS_H
