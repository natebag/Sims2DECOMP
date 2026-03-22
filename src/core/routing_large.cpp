#if 0 // SKIP
// routing_large.cpp - SpacePartition/Path large functions (257-512 bytes)
// Object file: routing.obj
// Functions: GetIntersectingPartitionRect, EstimateDistanceToGoal,
//            MeasureDistance, InitAST, EvalPoint, ~SpacePartition

#include "types.h"
#include "stub_classes.h"

// External functions
extern "C" {
    void* operator_new_wrapper(unsigned int size);   // 0x802d11b0
    void operator_delete_wrapper(void* ptr);         // 0x802d1220
    void* small_alloc(unsigned int size);             // 0x8039c304
    void small_free(void* ptr);                      // 0x8039be60
    void* memcpy(void* dst, const void* src, unsigned int n); // 0x802434f8
    float sqrtf(float x);                            // 0x80240ed0
}

// Forward declarations
struct IRect {
    int left;   // 0x00
    int top;    // 0x04
    int right;  // 0x08
    int bottom; // 0x0C
};

struct IPoint {
    int x;      // 0x00
    int y;      // 0x04
};

struct PartitionNode {
    int x;          // 0x00
    int y;          // 0x04
    int right;      // 0x08
    int bottom;     // 0x0C
    int cost;       // 0x10
    // 20 bytes per node
};

// ============================================================================
// SpacePartition::GetIntersectingPartitionRect(IRect *)
// Address: 0x80138d18
// Size: 280 bytes (0x118)
// NON_MATCHING - register allocation, loop structure
//
// Finds a partition node that intersects the given rectangle.
// Searches through two partition lists (primary at +0x04, secondary at +0x08).
// Returns the first node with cost != 0x7FFFFFFF that intersects.
// ============================================================================
void* SpacePartition_GetIntersectingPartitionRect(void* self, IRect* rect) {
    void* result = 0;

    // Search primary partition list at this+0x04
    void* listData = *(void**)((char*)self + 0x04);
    PartitionNode* begin = (PartitionNode*)*(void**)((char*)listData + 0x00);
    PartitionNode* end = (PartitionNode*)*(void**)((char*)listData + 0x04);

    while (begin != end) {
        // Check AABB intersection
        if (rect->left < begin->right &&
            rect->right > begin->x &&
            rect->top < begin->bottom &&
            rect->bottom > begin->y) {
            result = begin;
            // Check if cost == 0x7FFFFFFF (sentinel)
            if (begin->cost == 0x7FFFFFFF) {
                return result;
            }
        }
        begin = (PartitionNode*)((char*)begin + 20);
    }

    // Search secondary partition list at this+0x08
    void* list2 = *(void**)((char*)self + 0x08);
    if (list2 == 0) return result;

    begin = (PartitionNode*)*(void**)((char*)list2 + 0x00);
    end = (PartitionNode*)*(void**)((char*)list2 + 0x04);

    while (begin != end) {
        if (rect->left < begin->right &&
            rect->right > begin->x &&
            rect->top < begin->bottom &&
            rect->bottom > begin->y) {
            result = begin;
            if (begin->cost == 0x7FFFFFFF) {
                return result;
            }
        }
        begin = (PartitionNode*)((char*)begin + 20);
    }

    return result;
}

// ============================================================================
// SpacePartition::EstimateDistanceToGoal(int)
// Address: 0x80138f30
// Size: 320 bytes (0x140)
// NON_MATCHING - distance calculation with int-to-float conversion
//
// Estimates the Euclidean distance from a partition node to the goal.
// Uses the int-to-float xoris trick for precise conversion.
// ============================================================================
float SpacePartition_EstimateDistanceToGoal(void* self, int nodeIdx) {
    // Check nodeIdx >= 2 (need both source and dest)
    if ((unsigned int)nodeIdx <= 1) {
        return -1.0f; // invalid
    }

    // Get partition node at nodeIdx
    void* nodeResult = 0; // from GetPartitionNode call
    // Validate node index is within partition bounds

    // Get the source partition data at this+0x00
    void* partData = *(void**)((char*)self + 0x00);
    void* innerData = *(void**)partData;
    PartitionNode* nodes = (PartitionNode*)*(void**)innerData;
    int nodeCount = (int)((char*)*(void**)((char*)innerData + 0x04) - (char*)nodes);
    // Division by sizeof(PartitionNode) = 20: multiply by 0xCCCCCCCD then shift
    nodeCount = (int)((unsigned int)nodeCount * (unsigned int)0xCCCCCCCD) >> 2;

    if ((unsigned int)nodeIdx >= (unsigned int)nodeCount) {
        return -1.0f;
    }

    // Also check secondary index
    int destIdx = *(int*)((char*)nodeResult + 0x04);
    if (destIdx < 0) return -1.0f;
    int secondCount = (int)((char*)*(void**)((char*)self + 0x10) - (char*)*(void**)((char*)self + 0x0C));
    secondCount = (int)((unsigned int)secondCount * (unsigned int)0xCCCCCCCD) >> 2;
    if ((unsigned int)destIdx >= (unsigned int)secondCount) {
        return -1.0f;
    }

    // Get source and dest node center coordinates
    PartitionNode* srcNode = (PartitionNode*)((char*)nodes + nodeIdx * 20);
    int goalX = *(int*)((char*)nodeResult + 0x14);
    int goalY = *(int*)((char*)nodeResult + 0x18);

    // Compute center of source node
    int srcCenterX = (srcNode->x + srcNode->right) / 2;
    int srcCenterY = (srcNode->y + srcNode->bottom) / 2;

    // Euclidean distance using int-to-float conversion
    float dx = (float)(srcCenterX - goalX);
    float dy = (float)(srcCenterY - goalY);
    float dist = sqrtf(dx * dx + dy * dy);

    return dist;
}

// ============================================================================
// SpacePartition::MeasureDistance(int, int, IPoint *)
// Address: 0x80139070
// Size: 480 bytes (0x1E0)
// NON_MATCHING - complex distance measurement with path finding
//
// Measures the travel distance between two partition nodes, storing
// the waypoint in the output IPoint. Handles special cases for
// adjacent nodes and nodes in different partitions.
// ============================================================================
float SpacePartition_MeasureDistance(void* self, int srcIdx, int destIdx, IPoint* outPoint) {
    // Get partition nodes for src and dest
    void* srcNode = 0; // GetPartitionNode(srcIdx)
    void* destNode = 0; // GetPartitionNode(destIdx)

    if (srcNode == 0 || destNode == 0) return -1.0f;

    // Check if same partition
    if (srcIdx == 0) {
        // Direct distance from source
        int srcCenterX = *(int*)((char*)destNode + 0x00);
        if (srcCenterX < 0) return -1.0f;

        // Validate index bounds
        // Get node from partition list
        // Store waypoint coordinates in outPoint
        outPoint->x = *(int*)((char*)srcNode + 0x14);
        outPoint->y = *(int*)((char*)srcNode + 0x18);

        // Get cost from node and convert to float
        int cost = *(int*)((char*)srcNode + 0x10); // approximate
        float dist = (float)cost;
        return dist;
    }

    if (destIdx == 1) return -1.0f;

    // Different partitions - compute intermediate point
    int samePartition = (*(int*)((char*)srcNode + 0x04) == *(int*)((char*)destNode + 0x04));

    IPoint waypoint;
    if (samePartition) {
        waypoint.x = *(int*)((char*)srcNode + 0x14);
        waypoint.y = *(int*)((char*)srcNode + 0x18);
    } else {
        // Compute crossing point between partitions
        // Uses midpoint calculation
    }

    outPoint->x = waypoint.x;
    outPoint->y = waypoint.y;

    // Compute distance: sqrt(dx^2 + dy^2) for two segments
    int dx1 = waypoint.x - *(int*)((char*)srcNode + 0x14);
    int dy1 = waypoint.y - *(int*)((char*)srcNode + 0x18);
    float seg1 = sqrtf((float)(dx1*dx1 + dy1*dy1));

    // Add node costs
    int cost1 = *(int*)((char*)srcNode + 0x10);
    int cost2 = *(int*)((char*)destNode + 0x10);
    int avgCost = (cost1 + cost2 + 2) / 2;
    float costF = (float)avgCost;
    float totalDist = seg1 + costF;

    return totalDist;
}

// ============================================================================
// Path::InitAST(void)
// Address: 0x8013acac
// Size: 460 bytes (0x1CC)
// NON_MATCHING - A* pathfinding initialization, vector push_back
//
// Initializes A* search tree for pathfinding. Sets up the open list
// with the starting node, computes initial heuristic estimates.
// ============================================================================
int Path_InitAST(void* self) {
    // Copy start/end positions from path data
    int startPos = *(int*)((char*)self + 0x3C);
    int endPos = *(int*)((char*)self + 0x4C);
    *(int*)((char*)self + 0x40) = startPos;
    *(int*)((char*)self + 0x50) = endPos;

    // Get partition data
    // Compute waypoint from routing data
    // SpacePartition_GetPartition and EstimateDistance calls

    // Initialize search node:
    // - cost = -1
    // - float heuristic from rodata constant
    // - estimated distance from EstimateDistance call
    // - store at this+0x64 (startIdx)

    // Push start node onto open list (vector at this+0x3C)
    // Uses same vector push_back pattern as AddState:
    // Check capacity, grow if needed (small_alloc or operator_new)
    // Copy element, update pointers

    return 1;
}

// ============================================================================
// EvalPoint(IPoint, IPoint, IPoint, IPoint *, float *)
// Address: 0x8013ba9c
// Size: 388 bytes (0x184)
// NON_MATCHING - complex floating point math, distance calculations
//
// Evaluates a candidate waypoint for path smoothing. Computes the
// total distance through the candidate point and compares against
// the current best distance.
// ============================================================================
int EvalPoint(IPoint src, IPoint dest, IPoint candidate, IPoint* bestPoint, float* bestDist) {
    // Convert all coordinates to float
    // Compute distance from src to candidate: sqrt(dx^2 + dy^2)
    float dx1 = (float)(src.x - candidate.x);
    float dy1 = (float)(src.y - candidate.y);
    float seg1 = sqrtf(dx1 * dx1 + dy1 * dy1);

    // Compute distance from candidate to dest: sqrt(dx^2 + dy^2)
    float dx2 = (float)(candidate.x - dest.x);
    float dy2 = (float)(candidate.y - dest.y);
    float seg2 = sqrtf(dx2 * dx2 + dy2 * dy2);

    // Total distance through candidate
    float totalDist = seg1 + seg2;

    // Compare against current best
    if (totalDist < *bestDist) {
        *bestDist = totalDist;
        bestPoint->x = candidate.x;
        bestPoint->y = candidate.y;
        return 1;
    }

    return 0;
}

// ============================================================================
// SpacePartition::~SpacePartition(void)
// Address: 0x803acc5c
// Size: 388 bytes (0x184)
// NON_MATCHING - complex destructor freeing multiple vectors
//
// Destructor for SpacePartition. Frees all internal vectors/arrays
// using size-based dispatch (small_free for <=128 bytes).
// ============================================================================
void SpacePartition_Destructor(void* self, int flags) {
    // Free vector at this+0x4C (44-byte elements)
    // Iterate to find end, compute count
    void* vec1Begin = *(void**)((char*)self + 0x4C);
    void* vec1End = *(void**)((char*)self + 0x50);
    // Walk to end (stride 44 = 0x2C)
    if (vec1Begin != 0) {
        int size1 = (int)((char*)vec1End - (char*)vec1Begin);
        // Division by 44: multiply by 0xBA2E8BA3, shift right 2
        int byteSize1 = (size1 * (int)0xBA2E8BA3) >> 2;
        byteSize1 *= 44;
        if ((unsigned int)byteSize1 > 128)
            operator_delete_wrapper(vec1Begin);
        else
            small_free(vec1Begin);
    }

    // Free vector at this+0x3C (4-byte elements)
    void* vec2Begin = *(void**)((char*)self + 0x3C);
    if (vec2Begin != 0) {
        int size2 = (int)((char*)*(void**)((char*)self + 0x48) - (char*)vec2Begin);
        size2 &= ~3;
        if ((unsigned int)size2 > 128)
            operator_delete_wrapper(vec2Begin);
        else
            small_free(vec2Begin);
    }

    // Free vector at this+0x2C
    void* vec3Begin = *(void**)((char*)self + 0x2C);
    if (vec3Begin != 0) {
        int size3 = (int)((char*)*(void**)((char*)self + 0x38) - (char*)vec3Begin);
        size3 &= ~3;
        if ((unsigned int)size3 > 128)
            operator_delete_wrapper(vec3Begin);
        else
            small_free(vec3Begin);
    }

    // Free vector at this+0x1C
    void* vec4Begin = *(void**)((char*)self + 0x1C);
    if (vec4Begin != 0) {
        int size4 = (int)((char*)*(void**)((char*)self + 0x28) - (char*)vec4Begin);
        size4 &= ~3;
        if ((unsigned int)size4 > 128)
            operator_delete_wrapper(vec4Begin);
        else
            small_free(vec4Begin);
    }

    // Free vector at this+0x0C (20-byte elements)
    void* vec5Begin = *(void**)((char*)self + 0x0C);
    void* vec5End = *(void**)((char*)self + 0x10);
    // Walk to end (stride 20 = 0x14)
    if (vec5Begin != 0) {
        int size5 = (int)((char*)vec5End - (char*)vec5Begin);
        // Division by 20: multiply by 0xCCCCCCCD, shift right 2
        int byteSize5 = (size5 * (int)0xCCCCCCCD) >> 2;
        byteSize5 *= 20;
        if ((unsigned int)byteSize5 > 128)
            operator_delete_wrapper(vec5Begin);
        else
            small_free(vec5Begin);
    }

    // If flags & 1: delete this
    if (flags & 1) {
        operator_delete_wrapper(self);
    }
}
#endif
