#ifndef SPACEPARTITION_H
#define SPACEPARTITION_H

#include "types.h"

// SpacePartition - struct layout extracted from assembly analysis
// Estimated minimum size: 0x58 (88 bytes)
// 19 known fields (6 named), 40 methods

class SpacePartition {
public:
    // Constructors / Destructors
    SpacePartition(void)  // 0x803A73F0
    ~SpacePartition(void);  // 0x803AC880

    // Methods
    void FindInterfaceRect(int, int, IRect *);  // 0x803A7070 (280B)
    /* ? */ GetNode(int);  // 0x803A7820 (132B)
    void FindInterfaceRect(ASTNode *, ASTNode *, IRect *);  // 0x803A7188 (388B)
    void FindInterfacePoint(ASTNode *, ASTNode *);  // 0x803A730C (228B)
    /* ? */ GetIntersectingFreeRect(IRect *);  // 0x803A74A8 (400B)
    /* ? */ GetIntersectingPartitionRect(IRect *);  // 0x803A7638 (488B)
    /* ? */ GetNodeRectangle(int, IRect *);  // 0x803A78A4 (252B)
    bool IsSpatialNode(int);  // 0x803A79A0 (100B)
    void EstimateDistanceToGoal(int);  // 0x803A7A04 (1160B)
    void MeasureDistance(int, int, IPoint *);  // 0x803A7E8C (1056B)
    /* ? */ GetTerminals(int *, int *);  // 0x803A82AC (64B)
    void CountSuccessors(int);  // 0x803A82EC (1008B)
    void BuildSpatialSuccessorList(int);  // 0x803A9680 (3036B)
    /* ? */ GetNthSuccessor(int, int);  // 0x803A86DC (692B)
    void Clear(void);  // 0x803A8990 (108B)
    void Deallocate(void);  // 0x803A89FC (484B)
    void ExpandRect(PenaltyRect *);  // 0x803A8C88 (2552B)
    void Init(RoutingParams *);  // 0x803AB3E4 (1508B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (BuildSpatialSuccessorList, CountSuccessors, EstimateDistanceToGoal, ...)
    u32 m_intersectingPartitionRect_004;  // 0x004 [R/W] (BuildSpatialSuccessorList, CountSuccessors, FindInterfacePoint, ...)
    u32 m_intersectingPartitionRect_008;  // 0x008 [R/W] (BuildSpatialSuccessorList, CountSuccessors, GetIntersectingPartitionRect, ...)
    u32 m_nthSuccessor;  // 0x00C [R/W] (BuildSpatialSuccessorList, Clear, CountSuccessors, ...)
    u32 m_intersectingPartitionRect_010;  // 0x010 [R/W] (BuildSpatialSuccessorList, Deallocate, EstimateDistanceToGoal, ...)
    u32 m_field_014;  // 0x014 [R/W] (BuildSpatialSuccessorList, Deallocate, Init, ...)
    u32 m_field_018;  // 0x018 [R] (MeasureDistance)
    u32 m_field_01C;  // 0x01C [R/W] (Clear, CountSuccessors, Deallocate, ...)
    u32 m_field_020;  // 0x020 [R/W] (Deallocate)
    u32 m_field_024;  // 0x024 [R/W] (Deallocate)
    u8 _pad_028[4];  // 0x028
    u32 m_field_02C;  // 0x02C [R/W] (Clear, CountSuccessors, Deallocate, ...)
    u32 m_field_030;  // 0x030 [R/W] (Deallocate)
    u32 m_field_034;  // 0x034 [R/W] (Deallocate)
    u8 _pad_038[4];  // 0x038
    u32 m_nthSuccessor_03C;  // 0x03C [R/W] (Clear, CountSuccessors, Deallocate, ...)
    u32 m_field_040;  // 0x040 [R/W] (Deallocate)
    u32 m_field_044;  // 0x044 [R/W] (Deallocate)
    u8 _pad_048[4];  // 0x048
    u32 m_field_04C;  // 0x04C [R/W] (BuildSpatialSuccessorList, Clear, Deallocate, ...)
    u32 m_field_050;  // 0x050 [R/W] (Deallocate)
    u32 m_field_054;  // 0x054 [R/W] (Deallocate)
};

#endif // SPACEPARTITION_H
