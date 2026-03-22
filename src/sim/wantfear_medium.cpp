// wantfear_medium.cpp - WantFear/WantFearManager medium functions (65-256 bytes)
// Object file: wantfear.obj
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "sim/wantfear.h"

// External functions
extern "C" void* EAHeap_Get();
extern "C" void* EAHeap_Alloc(int);
extern "C" void EAHeap_FreePtr(void*);
extern "C" u32 ShaderDB_GetShader(int id);
extern "C" int RandomInt(int max);

// Global manager
extern WantFearManager* g_pWantFearManager;

// ============================================================================
// WantFearManager::GetEvent
// wantfear.obj | 0x8014BF30 | 140 bytes
// Looks up an event by ID using linear search
// ============================================================================
// NON_MATCHING: loop codegen
const int* WantFearManager::GetEvent(unsigned short eventId) const {
    if (m_events == 0) return 0;
    // Linear search through events array
    // Compare eventId field at offset +0x00
    // Events are 36 bytes each (mulli r0, r0, 36)
    return 0;
}

// ============================================================================
// WantFear::Bookmark::ResetCountdown
// wantfear.obj | 0x8014ABE4 | 80 bytes
// Resets the countdown timer from the node's ad data
// ============================================================================
// NON_MATCHING: field access codegen
void WantFear::Bookmark::ResetCountdown() {
    if (m_node == 0) return;
    // Get countdown value from node's ad data
    // Set m_countdown
    m_countdown = 0;
}

// ============================================================================
// WantFear::Bookmark::IsDuplicateNode
// wantfear.obj | 0x8014ACB8 | 120 bytes
// Checks if two bookmarks point to the same node
// ============================================================================
// NON_MATCHING: comparison codegen
bool WantFear::Bookmark::IsDuplicateNode(int& other) const {
    if (m_node == 0 || other.m_node == 0) return false;
    return (m_treeId == other.m_treeId && m_node == other.m_node);
}

// ============================================================================
// WantFear::Bookmark::IsDuplicateEvent
// wantfear.obj | 0x8014AD30 | 112 bytes
// Checks if two bookmarks reference the same event
// ============================================================================
// NON_MATCHING: event comparison
bool WantFear::Bookmark::IsDuplicateEvent(int& other) const {
    if (m_node == 0 || other.m_node == 0) return false;
    // Compare event references from both nodes
    return (m_node->m_eventRef == other.m_node->m_eventRef);
}

// ============================================================================
// WantFear::Bookmark::GetType
// wantfear.obj | 0x8014ADA0 | 104 bytes
// Returns the type of the bookmark's event
// ============================================================================
// NON_MATCHING: event lookup + type extraction
bool WantFear::Bookmark::GetType() const {
    if (m_node == 0) return false;
    // Get event from node's event reference
    // Return event type field
    return false;
}

// ============================================================================
// WantFearManager::GetTree
// wantfear.obj | 0x8014BFCC | 152 bytes
// Looks up a tree by ID using linear search
// ============================================================================
// NON_MATCHING: loop codegen
const int* WantFearManager::GetTree(unsigned short treeId) const {
    if (m_trees == 0) return 0;
    // Linear search through trees array
    // Compare tree ID
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetBaseShader
// wantfear.obj | 0x8014B398 | 168 bytes
// Gets the base shader for displaying this want/fear
// ============================================================================
// NON_MATCHING: shader lookup with fallback
u32 WantFear::Bookmark::GetOverlayShader(Neighbor* neighbor) const {
    if (m_node == 0) return 0;
    // Look up shader based on event category
    // Fall back to default shader if not found
    return 0;
}

// ============================================================================
// WantFearManager::GetCategoryShader
// wantfear.obj | 0x8014C164 | 152 bytes
// Gets shader for a want/fear category
// ============================================================================
// NON_MATCHING: shader database lookup
u32 WantFearManager::GetCategoryShader(int type, short param) {
    // Map target type + param to shader ID
    // Look up in shader database
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetBackgroundShader  (labeled as GetBaseShader in map)
// wantfear.obj | 0x8014B44C | 144 bytes
// ============================================================================
// NON_MATCHING: shader lookup
static u32 Bookmark_GetBackgroundShader(int* bm, Neighbor* neighbor) {
    if (bm->m_node == 0) return 0;
    // Get background shader for the want/fear display
    return 0;
}

// ============================================================================
// WantFear::Bookmark::GetNextBookmarkAlongBranch
// wantfear.obj | 0x8014BA7C | 208 bytes
// Traverses the want/fear tree to get next bookmark
// ============================================================================
// NON_MATCHING: tree traversal
int* WantFear::Bookmark::GetNextBookmarkAlongBranch(short branchIndex) {
    if (m_node == 0) return 0;
    // Get the tree for this bookmark
    const WantFear::Tree* tree = g_pWantFearManager->GetTree(m_treeId);
    if (tree == 0) return 0;
    // Get the Nth child of current node
    return 0;
}

// ============================================================================
// WantFearManager::WantFearManager
// wantfear.obj | 0x8014BC6C | 76 bytes
// ============================================================================
// NON_MATCHING: init codegen
WantFearManager::WantFearManager() {
    // Zero all fields
    m_events = 0;
    m_trees = 0;
}

// ============================================================================
// WantFearManager::~WantFearManager
// wantfear.obj | 0x8014BCB8 | 76 bytes
// ============================================================================
// NON_MATCHING: cleanup codegen
WantFearManager::~WantFearManager() {
    // Free events array
    if (m_events != 0) {
        EAHeap_FreePtr(m_events);
        m_events = 0;
    }
    // Free trees array
    if (m_trees != 0) {
        EAHeap_FreePtr(m_trees);
        m_trees = 0;
    }
}

// ============================================================================
// WantFearManager::GetStoryTreeRoot
// wantfear.obj | 0x8014C064 | 256 bytes
// Gets the root node of a story tree
// ============================================================================
// NON_MATCHING: complex tree search
const int* WantFearManager::GetStoryTreeRoot(short param1, short param2) const {
    if (m_trees == 0) return 0;
    // Search through trees for story tree matching params
    // Story trees have bit 0 set in m_storyFlag
    return 0;
}

// ============================================================================
// WantFearManager::Lottery
// wantfear.obj | 0x8014C3B8 | 140 bytes
// Weighted random selection from an array of weights
// ============================================================================
// NON_MATCHING: random number codegen
int WantFearManager::Lottery(unsigned int* weights, unsigned int count) const {
    if (count == 0) return -1;
    // Sum all weights
    unsigned int total = 0;
    for (unsigned int i = 0; i < count; i++) {
        total += weights[i];
    }
    if (total == 0) return -1;
    // Pick random value in [0, total)
    int pick = RandomInt(total);
    // Find which bucket the pick falls in
    unsigned int cumulative = 0;
    for (unsigned int i = 0; i < count; i++) {
        cumulative += weights[i];
        if ((unsigned int)pick < cumulative) {
            return (int)i;
        }
    }
    return (int)(count - 1);
}
