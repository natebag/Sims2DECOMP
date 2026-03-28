#ifndef TREESIMIMPL_H
#define TREESIMIMPL_H

#include "types.h"

// TreeSimImpl - struct layout extracted from assembly analysis
// Estimated minimum size: 0x44 (68 bytes)
// 13 known fields (4 named), 58 methods

class TreeSimImpl {
public:
    // Constructors / Destructors
    TreeSimImpl(int)  // 0x803CAEE0
    ~TreeSimImpl(void);  // 0x803CA610

    // Methods
    /* ? */ GetISimInstance(void);  // 0x803CAE50 (144B)
    void StackJustPopped(void);  // 0x803CD794 (40B)
    void Initialize(int, short *);  // 0x803CB23C (80B)
    void SetError(short);  // 0x803CA940 (52B)
    /* ? */ GetError(void);  // 0x803CA974 (48B)
    void ClearError(void);  // 0x803CA9A4 (40B)
    /* ? */ GetHighLevelAction(void);  // 0x803CD2B0 (460B)
    /* ? */ GetCurElem(void);  // 0x803CD47C (104B)
    /* ? */ GetMainSimElem(void);  // 0x803CD4E4 (500B)
    /* ? */ GetNthElem(short);  // 0x803CD6D8 (104B)
    /* ? */ GetStackSize(void);  // 0x803CD740 (84B)
    /* ? */ GetCurrentPrimitive(void);  // 0x803CB324 (336B)
    /* ? */ GetIterations(void);  // 0x803CF5D0 (44B)
    /* ? */ GetLastTransition(void);  // 0x803CD100 (216B)
    /* ? */ GetLastResult(void);  // 0x803CF5FC (44B)
    bool HasMainTreeSim(void);  // 0x803CF628 (56B)
    void SetNoMainTreeSim(bool);  // 0x803CF660 (40B)
    void RunCheckTree(Behavior *, short, short, short *);  // 0x803CB82C (1556B)
    void Reset(Behavior *, short);  // 0x803CB474 (152B)
    void RunOneTickTree(Behavior *, short, short, short *);  // 0x803CBE40 (164B)
    void HandleBreakpoint(StackElem *, BehaviorNode *);  // 0x803CBEE4 (112B)
    void Simulate(int);  // 0x803CD1D8 (216B)
    void Gosub(Behavior *, short *, short);  // 0x803CB50C (800B)
    /* ? */ GetCurrentNode(short *, short *);  // 0x803CB28C (152B)
    void DoNodeAction(StackElem *);  // 0x803CBF98 (4456B)
    void AsTreeSim(void);  // 0x803CF688 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoNodeAction, GetCurrentNode, GetCurrentPrimitive, ...)
    s16 m_currentNode;  // 0x002 [R/W] (DoNodeAction, GetCurrentNode, GetCurrentPrimitive)
    u8 m_field_003;  // 0x003 [R] (DoNodeAction)
    u16 m_field_004;  // 0x004 [R/W] (DoNodeAction, Gosub, RunCheckTree, ...)
    u8 _pad_006[2];  // 0x006
    f32 m_field_008;  // 0x008 [R/W] (DoNodeAction, RunCheckTree, Simulate)
    u8 _pad_00C[4];  // 0x00C
    u32 m_currentPrimitive;  // 0x010 [R] (DoNodeAction, GetCurrentPrimitive, GetHighLevelAction, ...)
    u8 _pad_014[4];  // 0x014
    u32 m_mainSimElem;  // 0x018 [R] (DoNodeAction, GetHighLevelAction, GetMainSimElem, ...)
    u8 _pad_01C[0xC];  // 0x01C
    u32 m_field_028;  // 0x028 [W] (DoNodeAction, TreeSimImpl)
    u32 m_field_02C;  // 0x02C [W] (DoNodeAction, TreeSimImpl)
    u32 m_field_030;  // 0x030 [R/W] (Gosub, TreeSimImpl)
    s16 m_field_034;  // 0x034 [R/W] (DoNodeAction, Reset, RunCheckTree, ...)
    u8 _pad_036[2];  // 0x036
    u32 m_field_038;  // 0x038 [W] (TreeSimImpl)
    u8 _pad_03C[4];  // 0x03C
    u32 m_field_040;  // 0x040 [R/W] (DoNodeAction, RunCheckTree, TreeSimImpl, ...)
};

#endif // TREESIMIMPL_H
