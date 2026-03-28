#ifndef TREESIM_H
#define TREESIM_H

#include "types.h"

// TreeSim - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 4 known fields (0 named), 50 methods

class TreeSim {
public:
    // Constructors / Destructors
    TreeSim(void)  // 0x803CADEC
    ~TreeSim(void);  // 0x803CA5B4

    // Methods
    void _dyncastimpl(SCID);  // 0x802D87F8 (356B)
    /* ? */ GetESimPerson(void);  // 0x803CF2F8 (44B)
    void SetISimInstance(IBaseSimInstance *);  // 0x803CF260 (152B)
    void SetESimPerson(ESim *);  // 0x803CF324 (152B)
    /* ? */ GetPerson(void);  // 0x803CF208 (44B)
    void setObjectImpl(cXObjectImpl *);  // 0x803CF168 (40B)
    void setPersonImpl(cXPersonImpl *);  // 0x803CF190 (40B)
    void setMTObjectImpl(cXMTObjectImpl *);  // 0x803CF1B8 (40B)
    void setPortalImpl(cXPortalImpl *);  // 0x803CF1E0 (40B)
    /* ? */ GetPrimName(short);  // 0x803CE5F4 (120B)
    void BreakOnCallTreeStringFailure(void);  // 0x803CF550 (44B)
    bool IsExecutingInMainSim(void);  // 0x803CF5A4 (44B)
    /* ? */ GetBaseISimInstance(void);  // 0x803CF234 (44B)
    /* ? */ GetMaxIterations(void);  // 0x803CF3BC (44B)
    void SetMaxIterations(int);  // 0x803CF3E8 (40B)
    bool IsBreakForPrimTimeOn(void);  // 0x803CF410 (44B)
    /* ? */ GetTooLongInPrimTime(void);  // 0x803CF43C (44B)
    void SetTooLongInPrimTime(bool, float);  // 0x803CF468 (52B)
    /* ? */ GetTooLongInTickTime(void);  // 0x803CF49C (44B)
    void SetTooLongInTickTime(bool, float);  // 0x803CF4C8 (52B)
    void TraceOnPrimTimeBreak(void);  // 0x803CF4FC (44B)
    void SetTraceOnPrimTimeBreak(bool);  // 0x803CF528 (40B)
    void SetBreakOnCallTreeStringFailure(bool);  // 0x803CF57C (40B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (_dyncastimpl)
    u32 m_field_004;  // 0x004 [R] (_dyncastimpl)
    u32 m_field_008;  // 0x008 [R] (_dyncastimpl)
    u32 m_field_00C;  // 0x00C [R] (_dyncastimpl)
};

#endif // TREESIM_H
