#ifndef WANTFEAR_H
#define WANTFEAR_H

#include "types.h"

// Forward declarations
class Neighbor;
class BString2;
class ReconBuffer;
class WantFearManager;

// ============================================================================
// WantFear namespace - wants and fears system
// Object file: wantfear.obj
// ============================================================================
namespace WantFear {

// Version constant
extern const int kWantFearVersion;                // 0x80500634
extern const u16 kGenericParam;                   // 0x80500638
extern const u16 kNoActiveIndex;                  // 0x8050063A
extern const u16 kNoBookmarkIndex;                // 0x8050063C
extern const u16 kNoTarget;                       // 0x8050063E
extern const int kMaxAdMax;                       // 0x80500640
extern const u16 kEventBuildBuyCategory;          // 0x80500644
extern const u16 kEventBuildBuyWorth;             // 0x80500646
extern const u16 kEventFamilyFundsOfX;            // 0x80500648
extern const u16 kEventFamilyFundsPlat;           // 0x8050064A
extern const u16 kEventBuildBuyWorthPlatinum;     // 0x8050064C
extern const u16 kEventAddARoom;                  // 0x8050064E
extern const u16 kEventBuildWalls;                // 0x80500650
extern const u16 kEventBuyXLights;                // 0x80500652
extern const u16 kEventBuyXChairs;                // 0x80500654

// Target type enum
enum TargetType {
    kTargetType_None = 0,
    kTargetType_Sim = 1,
    kTargetType_Object = 2,
    kTargetType_Skill = 3,
    kTargetType_Count = 4
};

// ============================================================================
// WantFear::Event - Event descriptor
// Layout (partial, from GetEvent):
//   +0x00: u16 m_eventId
//   +0x02: u8  m_type    (bit 0 = platinum flag)
// Size: 0x24 (36 bytes) based on GetEventByIndex mulli 36
// ============================================================================
struct Event {
    u16 m_eventId;   // +0x00
    u8  m_pad01;     // +0x01
    u8  m_type;      // +0x02 - bit 0 = platinum
    // ... more fields up to 0x24
};

// ============================================================================
// WantFear::Node - Tree node for want/fear hierarchy
// Layout (from disassembly):
//   +0x00: u16 m_nodeId
//   +0x02: u16 m_eventRef
//   +0x06: s16 m_defaultTarget
//   +0x0A: s16 m_firstChildIndex
//   +0x0C: s16 m_numBranches
//   +0x10: AdData m_adData (offset 16)
//   +0x1D: u8  m_flags    (bit 0 = hidden, bit 1 = has target override)
// Size: 0x20 (32 bytes, from slwi r0,r0,5)
// ============================================================================
struct Node {
    u16 m_nodeId;          // +0x00
    u16 m_eventRef;        // +0x02
    u8  m_pad04[2];        // +0x04
    s16 m_defaultTarget;   // +0x06
    u8  m_pad08[2];        // +0x08
    s16 m_firstChildIndex; // +0x0A
    s16 m_numBranches;     // +0x0C
    u8  m_pad0E[2];        // +0x0E
    u8  m_adData[13];      // +0x10 - AdData struct
    u8  m_flags;           // +0x1D - bit 0=hidden, bit 1=has_target_override
    u8  m_pad1E[2];        // +0x1E

    const Event* GetEvent() const;
};

// ============================================================================
// WantFear::Tree - Want/fear tree container
// Layout (from disassembly):
//   +0x00: (base data)
//   +0x02: u16 m_storyFlag (bit 0 = isStoryTree)
//   +0x28: Node* m_nodes (pointer to node array)
//   +0x2C: s8*  m_childIndexData (pointer to child index table)
// ============================================================================
struct Tree {
    u8  m_pad00[2];        // +0x00
    u16 m_storyFlag;       // +0x02 - bit 0 = isStoryTree
    u8  m_pad04[0x24];     // +0x04
    Node* m_nodes;         // +0x28
    void* m_childIndexData; // +0x2C - signed char index table

    void FixupPointers(signed char* indexBase, Node* nodeBase);
    const Node* GetNthChildOfNode(Node* node, short n) const;
};

// ============================================================================
// WantFear::Bookmark - Active want/fear bookmark
// Layout (from disassembly):
//   +0x00: u16 m_treeId
//   +0x02: u16 m_countdown
//   +0x04: Node* m_node
//   +0x08: u16 m_adIndex
// Size: 0x0C (12 bytes)
// ============================================================================
struct AdData;

class Bookmark {
public:
    u16   m_treeId;    // +0x00
    u16   m_countdown; // +0x02
    Node* m_node;      // +0x04
    u16   m_adIndex;   // +0x08

    Bookmark();
    Bookmark(unsigned short treeId, short countdown, Node* node, unsigned short adIndex);
    void Clear();
    void ResetCountdown();
    short GetNumBranches() const;
    bool IsPlatinum() const;
    bool IsFear() const;
    bool IsHidden() const;
    short GetTarget() const;
    bool IsInStoryTree() const;
    const u8* GetAdData() const;
    u32 GetOverlayShader(Neighbor* neighbor) const;
    bool IsDuplicateNode(Bookmark& other) const;
    bool IsDuplicateEvent(Bookmark& other) const;
    bool GetType() const;
    Node* GetNextBookmarkAlongBranch(short branchIndex);
};

// ============================================================================
// WantFear::Notification - Used for SatisfiedBy
// ============================================================================
struct Notification;

} // namespace WantFear

// ============================================================================
// WantFearManager - Global manager for want/fear system
// Layout (from disassembly):
//   +0x08: Event* m_events
//   +0x0C: Tree** m_trees
// ============================================================================
class WantFearManager {
public:
    u8  m_pad00[8];                    // +0x00
    WantFear::Event* m_events;         // +0x08
    WantFear::Tree** m_trees;          // +0x0C

    WantFearManager();
    ~WantFearManager();
    void LoadWants();
    void CaptureLog(bool enable);
    const WantFear::Event* GetEventByIndex(int index) const;
    const WantFear::Event* GetEvent(unsigned short eventId) const;
    const WantFear::Tree* GetTreeByIndex(int index) const;
    const WantFear::Tree* GetTree(unsigned short treeId) const;
    const WantFear::Node* GetStoryTreeRoot(short param1, short param2) const;
    u32 GetCategoryShader(WantFear::TargetType type, short param);
    void PickNewRoot(Neighbor* neighbor, bool param);
    int Lottery(unsigned int* weights, unsigned int count) const;
};

// Global manager pointer at 0x80475EEC (lis r9, -32697 / lwz r3, 24300(r9))
extern WantFearManager* g_pWantFearManager;

#endif // WANTFEAR_H
