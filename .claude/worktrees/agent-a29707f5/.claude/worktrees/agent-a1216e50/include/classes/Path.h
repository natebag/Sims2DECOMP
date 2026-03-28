#ifndef PATH_H
#define PATH_H

#include "types.h"

// Path - struct layout extracted from assembly analysis
// Estimated minimum size: 0x70 (112 bytes)
// 21 known fields (1 named), 21 methods

class Path {
public:
    // Constructors / Destructors
    Path(void)  // 0x803F1E14
    ~Path(void);  // 0x803F1B34

    // Methods
    void DeallocateAllPathData(void);  // 0x803ABD9C (56B)
    void InitAST(void);  // 0x803AA25C (352B)
    void OpenANode(void);  // 0x803AA3BC (2136B)
    void FindSmallestOpenNode(void);  // 0x803ABAEC (688B)
    void DoOneSmooth(void);  // 0x803AAD18 (1740B)
    void InitPath(RoutingParams *);  // 0x803AB9C8 (292B)
    void PathComplete(void);  // 0x803F1F94 (56B)
    /* ? */ GetIterations(void);  // 0x803F1BFC (44B)
    void AdvancePath(void);  // 0x803F1C54 (184B)
    /* ? */ GetFinalPath(void);  // 0x803F1BD0 (44B)
    void ClearPath(void);  // 0x803F1EB4 (224B)
    /* ? */ GetChosenGoal(void);  // 0x803F1C28 (44B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (DoOneSmooth, InitAST, InitPath, ...)
    u32 m_field_004;  // 0x004 [R/W] (DoOneSmooth, InitPath, OpenANode, ...)
    u32 m_field_008;  // 0x008 [W] (InitPath)
    u32 m_field_00C;  // 0x00C [R/W] (OpenANode)
    u8 _pad_010[4];  // 0x010
    u32 m_field_014;  // 0x014 [R/W] (DoOneSmooth, InitAST, InitPath, ...)
    u32 m_field_018;  // 0x018 [R/W] (DoOneSmooth, InitAST, InitPath, ...)
    u32 m_field_01C;  // 0x01C [R/W] (InitAST, OpenANode)
    f32 m_field_020;  // 0x020 [R/W] (FindSmallestOpenNode, InitAST, OpenANode)
    f32 m_field_024;  // 0x024 [R/W] (DoOneSmooth, InitAST, InitPath, ...)
    f32 m_field_028;  // 0x028 [R/W] (DoOneSmooth, InitAST, OpenANode)
    u8 _pad_02C[8];  // 0x02C
    u32 m_field_034;  // 0x034 [W] (InitPath)
    u32 m_field_038;  // 0x038 [W] (InitPath)
    u32 m_field_03C;  // 0x03C [R] (FindSmallestOpenNode, InitAST, OpenANode, ...)
    u32 m_field_040;  // 0x040 [W] (InitAST)
    u8 _pad_044[8];  // 0x044
    u32 m_field_04C;  // 0x04C [R] (InitAST, OpenANode, ~Path)
    u32 m_field_050;  // 0x050 [W] (InitAST)
    u8 _pad_054[8];  // 0x054
    u32 m_field_05C;  // 0x05C [R] (InitAST)
    u32 m_field_060;  // 0x060 [R] (OpenANode)
    u32 m_field_064;  // 0x064 [R/W] (InitAST, OpenANode)
    u32 m_field_068;  // 0x068 [R/W] (InitPath, OpenANode)
    u32 m_field_06C;  // 0x06C [R/W] (DoOneSmooth, InitPath)
};

#endif // PATH_H
