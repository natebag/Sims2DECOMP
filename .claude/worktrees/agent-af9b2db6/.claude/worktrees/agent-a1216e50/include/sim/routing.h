#ifndef ROUTING_H
#define ROUTING_H

#include "types.h"

// Forward declarations
class cXObject;
class cXPerson;
class ReconBuffer;
struct FTilePt;
struct IRect;
struct IPoint;
struct RoutingParams;

// ============================================================================
// IRect - Integer rectangle (16 bytes)
// ============================================================================
struct IRect {
    int left;    // +0x00
    int top;     // +0x04
    int right;   // +0x08
    int bottom;  // +0x0C
};

// ============================================================================
// IPoint - Integer point (8 bytes)
// ============================================================================
struct IPoint {
    int x; // +0x00
    int y; // +0x04
};

// ============================================================================
// PenaltyRect - Rectangle with routing penalty (20 bytes)
// ============================================================================
struct PenaltyRect {
    PenaltyRect(IRect* rect, int penalty);
    PenaltyRect(int left, int top, int right, int bottom, int penalty);

    int left;     // +0x00
    int top;      // +0x04
    int right;    // +0x08
    int bottom;   // +0x0C
    int penalty;  // +0x10
};

// ============================================================================
// ASTNode - A* search tree node (44 bytes)
// Used in SpacePartition for pathfinding
// ============================================================================
struct ASTNode {
    char _data[0x2C]; // 44 bytes per node
};

// ============================================================================
// SpacePartition - Spatial partitioning for route finding
// Size: 0x5C (92 bytes) based on static fSpacePartition and constructor
//
// Member layout (from constructor at 0x80138C20):
//   +0x00-0x0B: unknown (12 bytes zeroed)
//   +0x0C: int m_field0C
//   +0x10: int m_field10
//   +0x14-0x17: field pair
//   +0x18: int m_field18
//   ...
//   +0x4C: ASTNode* m_nodes (pointer to node array start)
//   +0x50: ASTNode* m_nodesEnd (pointer to node array end)
//   +0x54-0x5B: additional field pairs
// ============================================================================
class SpacePartition {
public:
    SpacePartition(void);
    ~SpacePartition(void);

    void Init(RoutingParams* params);
    void Clear(void);
    void Deallocate(void);

    ASTNode* GetNode(int index);
    int IsSpatialNode(int node);
    void GetTerminals(int* start, int* end);
    void GetNodeRectangle(int index, IRect* outRect);
    int EstimateDistanceToGoal(int node);
    void MeasureDistance(int nodeA, int nodeB, IPoint* outDist);
    int CountSuccessors(int node);
    void BuildSpatialSuccessorList(int node);
    int GetNthSuccessor(int node, int n);

    void FindInterfaceRect(int nodeA, int nodeB, IRect* outRect);
    void FindInterfaceRect(ASTNode* nodeA, ASTNode* nodeB, IRect* outRect);
    void FindInterfacePoint(ASTNode* nodeA, ASTNode* nodeB);
    void GetIntersectingFreeRect(IRect* rect);
    void GetIntersectingPartitionRect(IRect* rect);
    void ExpandRect(PenaltyRect* rect);

    // Data members
    char _pad0[0x0C];         // +0x00
    int m_field0C;            // +0x0C
    int m_field10;            // +0x10
    int m_field14;            // +0x14
    int m_field18;            // +0x18
    int m_field1C;            // +0x1C
    int m_field20;            // +0x20
    int m_field24;            // +0x24
    int m_field28;            // +0x28
    int m_field2C;            // +0x2C
    int m_field30;            // +0x30
    int m_field34;            // +0x34
    int m_field38;            // +0x38
    int m_field3C;            // +0x3C
    int m_field40;            // +0x40
    int m_field44;            // +0x44
    int m_field48;            // +0x48
    ASTNode* m_nodes;         // +0x4C
    ASTNode* m_nodesEnd;      // +0x50
    int m_field54;            // +0x54
    int m_field58;            // +0x58
};

// ============================================================================
// Path - A* pathfinding path
// ============================================================================
class Path {
public:
    ~Path(void);

    void InitAST(void);
    void OpenANode(void);
    void FindSmallestOpenNode(void);
    void DoOneSmooth(void);
    void InitPath(RoutingParams* params);
    static void DeallocateAllPathData(void);

    // Static space partition used for pathfinding
    static SpacePartition fSpacePartition;
};

// ============================================================================
// TileList - List of tile positions for route paths
// ============================================================================
class TileList {
public:
    void FindNearestPoint(FTilePt* pt, int param);
};

// ============================================================================
// RoutingSlot - Routing slot for object interaction positioning
// ============================================================================
struct RoutingSlot {
    char _data[0x3C]; // 60 bytes per slot (from copy loop in XRoute::Construct: 48+12)
};

// ============================================================================
// RouteGoal - A single routing goal (16 bytes)
// ============================================================================
struct RouteGoal {
    char _data[0x10]; // 16 bytes per goal
};

// ============================================================================
// XRoute - Extended routing system for sim movement
// Size: at least 0xA4 bytes
//
// Member layout (from XRoute::XRoute and XRoute::Construct):
//   +0x00: RouteGoal* m_goalsBegin   (vector start)
//   +0x04: RouteGoal* m_goalsEnd     (vector end)
//   +0x08: int m_field08             (vector capacity/alloc end)
//   +0x0C: int m_field0C             (vector padding)
//   +0x10: RoutingSlot m_routingSlot (48 bytes - copied from RoutingSlot*)
//   +0x4C: cXObject* m_targetObj
//   +0x50: cXObject* m_sourceObj
//   +0x54: int m_currentGoal         (-1 = none)
//   +0x58: int m_bestGoal            (-1 = none)
//   +0x5C: int m_field5C
//   +0x60: int m_field60
//   ...
// ============================================================================
class XRoute {
public:
    XRoute(void);
    XRoute(cXObject* source, cXObject* target, RoutingSlot* slot);
    void Construct(cXObject* source, cXObject* target, RoutingSlot* slot);

    RoutingSlot* GetRoutingSlot(void);
    bool HasCurrentGoal(void);
    int CountGoals(void);
    RouteGoal* GetNthGoal(int n);
    void SetCurrentGoal(int index);
    RouteGoal* GetCurrentGoal(void);
    void DoStream(ReconBuffer* buffer, int direction);
    void ResetGoals(void);

    void AddGoal(RouteGoal& goal);
    void GetMaxScore(void);
    void ClearCurrentGoal(void);
    void BuildGoalList(void);
    void ChooseStartingPoint(void);
    void ConstructGoals(void);
    void FindPath(TileList& tileList);
    int EvalTileForGoal(FTilePt& tile, int param);
    bool IsPersonSittingOnChairGoal(cXPerson* person);
    bool ShouldIgnore(cXObject* obj);

    // Data members
    RouteGoal* m_goalsBegin;   // +0x00
    RouteGoal* m_goalsEnd;     // +0x04
    RouteGoal* m_goalsAlloc;   // +0x08
    int m_field0C;             // +0x0C
    RoutingSlot m_routingSlot; // +0x10 (0x3C bytes, ends at +0x4C)
    cXObject* m_targetObj;     // +0x4C
    cXObject* m_sourceObj;     // +0x50
    int m_currentGoal;         // +0x54  (-1 = none)
    int m_bestGoal;            // +0x58  (-1 = none)
    int m_field5C;             // +0x5C
    int m_field60;             // +0x60
    char _pad64[0x40];        // +0x64 ... additional fields
};

// ============================================================================
// Free functions
// ============================================================================
void BuildRoomPartition(unsigned short roomId, void* penaltyRects, bool flag);
void BuildRoomPartition(unsigned short roomId, void* penaltyRects);

void FindIntersectingRect(IRect* rect, void* penaltyRects);
int IsRectInside(IRect* a, IRect* b);
void EvalPoint(IPoint p1, IPoint p2, IPoint p3, IPoint* outPt, float* outDist);
void Stuck(void* penaltyRects, IPoint* point);
void CollapsePenaltyRects(void* penaltyRects);
void TransformToWorldCoords(FTilePt* src, float param1, float param2, int param3, FTilePt* dst);
void SetDirectionForGoalSearch(cXObject* obj, short param1, short param2, RoutingSlot* slot);

// Static init/fini
extern void __static_initialization_and_destruction_0(int init, int priority);

#endif // ROUTING_H
