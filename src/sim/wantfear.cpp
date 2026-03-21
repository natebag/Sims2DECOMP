// wantfear.cpp - Decompiled small functions from wantfear.obj
// Original: c:\BuildAgent\cm3-build22-NGC\CMBuild\output\obj\u2_ngc_release_dvd\wantfear.obj
//
// 17 small functions (<=64 bytes) decompiled

#include "sim/wantfear.h"

// Global manager pointer at 0x80475EEC
// Accessed via: lis r9,-32697 / lwz r3,24300(r9)
extern WantFearManager* g_pWantFearManager;

// ============================================================================
// WantFear::Node::GetEvent
// Address: 0x8014AB00, Size: 44 bytes
// Loads event ref from node, calls WantFearManager::GetEvent
// NON_MATCHING - tail call pattern: GCC may optimize differently than SN
// ============================================================================
const WantFear::Event* WantFear::Node::GetEvent() const {
    return g_pWantFearManager->GetEvent(m_eventRef);
}

// ============================================================================
// WantFear::Tree::FixupPointers
// Address: 0x8014AB2C, Size: 32 bytes
// MATCHING
// Adjusts node and child index pointers by base offsets
// ============================================================================
void WantFear::Tree::FixupPointers(signed char* indexBase, WantFear::Node* nodeBase) {
    // m_nodes offset is shifted left by 5 (32-byte nodes)
    // m_childIndexData is raw byte offset
    m_childIndexData = (void*)((u8*)m_childIndexData + (u32)indexBase);
    m_nodes = (Node*)((u8*)nodeBase + ((u32)m_nodes << 5));
}

// ============================================================================
// WantFear::Tree::GetNthChildOfNode
// Address: 0x8014AB4C, Size: 36 bytes
// MATCHING
// Returns the Nth child node of a given parent node
// ============================================================================
const WantFear::Node* WantFear::Tree::GetNthChildOfNode(WantFear::Node* node, short n) const {
    short index = ((short*)m_childIndexData)[node->m_firstChildIndex + n];
    return (const Node*)((u8*)m_nodes + (index << 5));
}

// ============================================================================
// WantFear::Bookmark::Bookmark (default)
// Address: 0x8014AB70, Size: 48 bytes
// NON_MATCHING - GCC prologue/epilogue register save differs from SN
// Calls Clear() to initialize
// ============================================================================
WantFear::Bookmark::Bookmark() {
    Clear();
}

// ============================================================================
// WantFear::Bookmark::Clear
// Address: 0x8014ABC8, Size: 28 bytes
// MATCHING
// Zeros out all fields
// ============================================================================
void WantFear::Bookmark::Clear() {
    m_adIndex = 0;
    m_node = 0;
    m_treeId = 0;
    m_countdown = 0;
}

// ============================================================================
// WantFear::Bookmark::Bookmark (parameterized)
// Address: 0x8014ABA0, Size: 40 bytes
// NON_MATCHING - conditional return (beqlr) pattern may differ
// ============================================================================
WantFear::Bookmark::Bookmark(unsigned short treeId, short countdown, WantFear::Node* node, unsigned short adIndex) {
    m_countdown = 0;
    m_treeId = treeId;
    m_adIndex = adIndex;
    m_node = node;
    // Only set countdown if node has target override flag
    if (node->m_flags & 2) {
        m_countdown = countdown;
    }
}

// ============================================================================
// WantFear::Bookmark::GetNumBranches
// Address: 0x8014AC34, Size: 12 bytes
// MATCHING
// Returns number of branches from the referenced node
// ============================================================================
short WantFear::Bookmark::GetNumBranches() const {
    return m_node->m_numBranches;
}

// ============================================================================
// WantFear::Bookmark::IsPlatinum
// Address: 0x8014AC40, Size: 52 bytes
// NON_MATCHING - bool conversion pattern differs (subfic/adde vs branch)
// Gets event from node, checks if type byte == 1 (platinum)
// ============================================================================
bool WantFear::Bookmark::IsPlatinum() const {
    const Event* event = m_node->GetEvent();
    return (event->m_type == 1);
}

// ============================================================================
// WantFear::Bookmark::IsFear
// Address: 0x8014AC74, Size: 52 bytes
// NON_MATCHING - bool conversion pattern differs (subfic/adde vs branch)
// Gets event from node, checks if type byte has bit 7 set (0x80 = fear)
// ============================================================================
bool WantFear::Bookmark::IsFear() const {
    const Event* event = m_node->GetEvent();
    return (event->m_type == 0x80);
}

// ============================================================================
// WantFear::Bookmark::IsHidden
// Address: 0x8014ACA8, Size: 16 bytes
// MATCHING
// Returns bit 0 of node flags
// ============================================================================
bool WantFear::Bookmark::IsHidden() const {
    return m_node->m_flags & 1;
}

// ============================================================================
// WantFear::Bookmark::GetTarget
// Address: 0x8014B36C, Size: 32 bytes
// MATCHING
// Returns target - either from node default or from bookmark countdown field
// ============================================================================
short WantFear::Bookmark::GetTarget() const {
    if (!(m_node->m_flags & 2)) {
        return m_node->m_defaultTarget;
    }
    return m_countdown;
}

// ============================================================================
// WantFear::Bookmark::IsInStoryTree
// Address: 0x8014AE08, Size: 52 bytes
// NON_MATCHING - SDA access pattern and function call sequence
// Looks up tree by treeId and checks story flag
// ============================================================================
bool WantFear::Bookmark::IsInStoryTree() const {
    const WantFear::Tree* tree = g_pWantFearManager->GetTree(m_treeId);
    return tree->m_storyFlag & 1;
}

// ============================================================================
// WantFear::Bookmark::GetAdData
// Address: 0x8014B38C, Size: 12 bytes
// MATCHING
// Returns pointer to ad data in the node (at offset +0x10)
// ============================================================================
const u8* WantFear::Bookmark::GetAdData() const {
    return &m_node->m_adData[0];
}

// ============================================================================
// WantFear::Bookmark::GetOverlayShader
// Address: 0x8014B440, Size: 12 bytes
// MATCHING
// Returns a constant shader value (0x9F93FF74)
// ============================================================================
u32 WantFear::Bookmark::GetOverlayShader(Neighbor* neighbor) const {
    return 0x9F93FF74;
}

// ============================================================================
// WantFearManager::CaptureLog
// Address: 0x8014BD04, Size: 4 bytes
// MATCHING
// Empty stub function (no-op in release build)
// ============================================================================
void WantFearManager::CaptureLog(bool enable) {
    // no-op
}

// ============================================================================
// WantFearManager::GetEventByIndex
// Address: 0x8014BF20, Size: 16 bytes
// MATCHING
// Returns event at given index (events are 36 bytes each)
// ============================================================================
const WantFear::Event* WantFearManager::GetEventByIndex(int index) const {
    return (const WantFear::Event*)((u8*)m_events + index * 36);
}

// ============================================================================
// WantFearManager::GetTreeByIndex
// Address: 0x8014BFBC, Size: 16 bytes
// MATCHING
// Returns tree pointer at given index
// ============================================================================
const WantFear::Tree* WantFearManager::GetTreeByIndex(int index) const {
    return m_trees[index];
}
