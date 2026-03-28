#if 0 // SKIP
// e_redblacktree_large.cpp - ERedBlackTree large functions (257-1024 bytes)
// Object file: base_ngc_release_dvd.lib(e_redblacktree.obj)
// All NON_MATCHING due to: GCC vs SN Systems codegen differences

#include "types.h"
#include "stub_classes.h"

// Forward declarations
extern "C" void* EAHeap_Alloc(int size);
extern "C" void EAHeap_Free2(void* ptr);

// ERedBlackTreeNode layout:
// 0x00 = left child
// 0x04 = right child (also vtable for ERedBlackTreeNode)
// 0x08 = parent
// 0x0C = prev (linked list)
// 0x10 = next (linked list)
// 0x14 = color (0=black, 1=red)
// 0x18 = key
// 0x1C = value
struct ERedBlackTreeNode {
    ERedBlackTreeNode* m_left;       // 0x00
    ERedBlackTreeNode* m_right;      // 0x04
    ERedBlackTreeNode* m_parent;     // 0x08
    ERedBlackTreeNode* m_prev;       // 0x0C
    ERedBlackTreeNode* m_next;       // 0x10
    u32 m_color;                     // 0x14
    u32 m_key;                       // 0x18
    u32 m_value;                     // 0x1C
};

// ERedBlackTree layout:
// 0x00 = first node (linked list head)
// 0x04 = last node (linked list tail)
// 0x08 = root node
// 0x0C = count
struct ERedBlackTree {
    ERedBlackTreeNode* m_first;      // 0x00
    ERedBlackTreeNode* m_last;       // 0x04
    ERedBlackTreeNode* m_root;       // 0x08
    u32 m_count;                     // 0x0C

    void RotateLeft(ERedBlackTreeNode* node);
    void RotateRight(ERedBlackTreeNode* node);
    void InsertFixup(ERedBlackTreeNode* node);
    ERedBlackTreeNode* InsertAt(ERedBlackTreeNode* parent, u32 key, u32 value);
    void RemoveFixup(ERedBlackTreeNode* node);
    void Remove(void* iter);
};

// RotateLeft and RotateRight are called by InsertFixup/RemoveFixup
// They are at 0x802CDA24 and 0x802CDAA0 respectively (< 257 bytes each)

// ============================================================================
// ERedBlackTree::InsertFixup(ERedBlackTreeNode*)
// Address: 0x802CDB1C
// Size: 328 bytes
// NON_MATCHING - red-black tree insert fixup (rebalancing after insert)
// ============================================================================
void ERedBlackTree::InsertFixup(ERedBlackTreeNode* node)
{
    // Standard red-black tree insert fixup algorithm
    while (node != m_root && node->m_parent->m_color == 1) {
        ERedBlackTreeNode* parent = node->m_parent;
        ERedBlackTreeNode* grandparent = parent->m_parent;

        if (parent == grandparent->m_left) {
            // Parent is left child of grandparent
            ERedBlackTreeNode* uncle = grandparent->m_right;

            if (uncle && uncle->m_color == 1) {
                // Case 1: Uncle is red
                parent->m_color = 0;    // black
                uncle->m_color = 0;     // black
                grandparent->m_color = 1; // red
                node = grandparent;
            } else {
                // Case 2: Uncle is black, node is right child
                if (node == parent->m_right) {
                    node = parent;
                    RotateLeft(node);
                }
                // Case 3: Uncle is black, node is left child
                node->m_parent->m_color = 0;
                node->m_parent->m_parent->m_color = 1;
                RotateRight(node->m_parent->m_parent);
            }
        } else {
            // Mirror: parent is right child of grandparent
            ERedBlackTreeNode* uncle = grandparent->m_left;

            if (uncle && uncle->m_color == 1) {
                parent->m_color = 0;
                uncle->m_color = 0;
                grandparent->m_color = 1;
                node = grandparent;
            } else {
                if (node == parent->m_left) {
                    node = parent;
                    RotateRight(node);
                }
                node->m_parent->m_color = 0;
                node->m_parent->m_parent->m_color = 1;
                RotateLeft(node->m_parent->m_parent);
            }
        }
    }

    // Root is always black
    m_root->m_color = 0;
}

// ============================================================================
// ERedBlackTree::InsertAt(ERedBlackTreeNode*, unsigned int, unsigned int)
// Address: 0x802CDE58
// Size: 336 bytes
// NON_MATCHING - inserts a new node at the given parent
// ============================================================================
ERedBlackTreeNode* ERedBlackTree::InsertAt(ERedBlackTreeNode* parent, u32 key, u32 value)
{
    // Allocate new node (32 bytes)
    ERedBlackTreeNode* node = (ERedBlackTreeNode*)EAHeap_Alloc(32);
    if (!node) return 0;

    // Initialize node
    node->m_color = 1; // red
    node->m_parent = parent;
    node->m_key = key;
    node->m_value = value;

    // Initialize vtable-like field
    // NON_MATCHING: link-time address for vtable
    node->m_right = (ERedBlackTreeNode*)0x8044ED34;
    node->m_left = (ERedBlackTreeNode*)0x8044ED34;

    if (parent == 0) {
        // Tree was empty - this becomes root
        m_root = node;
        // Link into list
        ERedBlackTreeNode* oldFirst = m_first;
        node->m_next = oldFirst;
        if (oldFirst) {
            oldFirst->m_prev = node;
        } else {
            m_last = node;
        }
        node->m_prev = 0;
        m_first = node;
    } else if (key < parent->m_key) {
        // Insert as left child
        parent->m_left = node;

        // Link into doubly-linked list before parent
        ERedBlackTreeNode* prevNode = parent->m_prev;
        if (prevNode) {
            prevNode->m_next = node;
            node->m_prev = prevNode;
            parent->m_prev = node;
            node->m_next = parent;
        } else {
            // node becomes new first
            ERedBlackTreeNode* oldFirst = m_first;
            node->m_next = oldFirst;
            if (oldFirst) {
                oldFirst->m_prev = node;
            }
            node->m_prev = 0;
            m_first = node;
        }
    } else {
        // Insert as right child
        parent->m_right = node;

        // Link into list after parent
        ERedBlackTreeNode* nextNode = parent->m_next;
        if (nextNode) {
            nextNode->m_prev = node;
            node->m_next = nextNode;
            parent->m_next = node;
            node->m_prev = parent;
        } else {
            // node becomes new last
            ERedBlackTreeNode* oldLast = m_last;
            node->m_prev = oldLast;
            if (oldLast) {
                oldLast->m_next = node;
            } else {
                m_first = node;
            }
            node->m_next = 0;
            m_last = node;
        }
    }

    // Fix up red-black tree properties
    InsertFixup(node);

    return node;
}

// ============================================================================
// ERedBlackTree::RemoveFixup(ERedBlackTreeNode*)
// Address: 0x802CDFA8
// Size: 476 bytes
// NON_MATCHING - red-black tree delete fixup
// ============================================================================
void ERedBlackTree::RemoveFixup(ERedBlackTreeNode* node)
{
    while (node != m_root && node->m_color == 0) {
        ERedBlackTreeNode* parent = node->m_parent;

        if (node == parent->m_left) {
            ERedBlackTreeNode* sibling = parent->m_right;

            // Case 1: sibling is red
            if (sibling->m_color == 1) {
                sibling->m_color = 0;
                parent->m_color = 1;
                RotateLeft(parent);
                sibling = node->m_parent->m_right;
            }

            // Case 2: sibling's children are both black
            if (sibling->m_right->m_color == 0 && sibling->m_left->m_color == 0) {
                sibling->m_color = 1;
                node = node->m_parent;
            } else {
                // Case 3: sibling's right child is black
                if (sibling->m_right->m_color == 0) {
                    sibling->m_left->m_color = 0;
                    sibling->m_color = 1;
                    RotateRight(sibling);
                    sibling = node->m_parent->m_right;
                }
                // Case 4: sibling's right child is red
                sibling->m_color = node->m_parent->m_color;
                node->m_parent->m_color = 0;
                sibling->m_right->m_color = 0;
                RotateLeft(node->m_parent);
                node = m_root;
            }
        } else {
            // Mirror cases for right child
            ERedBlackTreeNode* sibling = parent->m_left;

            if (sibling->m_color == 1) {
                sibling->m_color = 0;
                parent->m_color = 1;
                RotateRight(parent);
                sibling = node->m_parent->m_left;
            }

            if (sibling->m_right->m_color == 0 && sibling->m_left->m_color == 0) {
                sibling->m_color = 1;
                node = node->m_parent;
            } else {
                if (sibling->m_left->m_color == 0) {
                    sibling->m_right->m_color = 0;
                    sibling->m_color = 1;
                    RotateLeft(sibling);
                    sibling = node->m_parent->m_left;
                }
                sibling->m_color = node->m_parent->m_color;
                node->m_parent->m_color = 0;
                sibling->m_left->m_color = 0;
                RotateRight(node->m_parent);
                node = m_root;
            }
        }
    }

    node->m_color = 0;
}

// ============================================================================
// ERedBlackTree::Remove(RBIteratorPtrType*)
// Address: 0x802CE1CC
// Size: 480 bytes
// NON_MATCHING - removes a node from the tree
// ============================================================================
void ERedBlackTree::Remove(void* iter)
{
    ERedBlackTreeNode* node = *(ERedBlackTreeNode**)iter;
    if (!node) return;

    ERedBlackTreeNode* splice;
    ERedBlackTreeNode* child;

    // Find node to splice out
    if (node->m_left == 0 || node->m_right == 0) {
        splice = node;
    } else {
        // Find successor
        splice = node->m_next;
    }

    // Get child of splice node
    if (splice->m_left != 0) {
        child = splice->m_left;
    } else {
        child = splice->m_right;
    }

    // Splice out the node
    if (child) {
        child->m_parent = splice->m_parent;
    }

    if (splice->m_parent == 0) {
        m_root = child;
    } else if (splice == splice->m_parent->m_left) {
        splice->m_parent->m_left = child;
    } else {
        splice->m_parent->m_right = child;
    }

    // If splice != node, copy data
    if (splice != node) {
        node->m_key = splice->m_key;
        node->m_value = splice->m_value;
    }

    // Unlink from doubly-linked list
    if (splice->m_prev) {
        splice->m_prev->m_next = splice->m_next;
    } else {
        m_first = splice->m_next;
    }
    if (splice->m_next) {
        splice->m_next->m_prev = splice->m_prev;
    } else {
        m_last = splice->m_prev;
    }

    // Fix up if black node was removed
    if (splice->m_color == 0 && child) {
        RemoveFixup(child);
    }

    // Free the spliced node
    EAHeap_Free2(splice);
}
#endif
