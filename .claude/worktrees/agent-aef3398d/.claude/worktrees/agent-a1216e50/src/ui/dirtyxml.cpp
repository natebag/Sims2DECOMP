#if 0 // SKIP
// dirtyxml.cpp - CDirtyXmlNode, CDirtyXmlDoc (XML parsing for APT UI)
// Part of the Sims 2 GC decompilation
// Original: u2_ngc_release_dvd(dirtyxml.obj)
//
// Small functions (<=64 bytes) decompiled from the dirtyxml object file.
// CDirtyXmlNode/Doc implement the IAptXmlNode interface for APT UI scripting.

#include "types.h"
#include "stub_classes.h"

// Forward declarations
class IAptXmlNode;

//=============================================================================
// CDirtyXmlNode
//=============================================================================
class CDirtyXmlNode {
public:
    u8 pad00[0x08];
    int m_nodeType;          // 0x08
    void* m_parentNode;      // 0x0C
    void* m_firstChild;      // 0x10
    void* m_lastChild;       // 0x14
    void* m_nextSibling;     // 0x18
    void* m_prevSibling;     // 0x1C
    void* m_childIter;       // 0x20 (used by getFirstChildNode/getNextChildNode)
    char* m_toString;        // 0x24

    // Empty stubs (just blr = 4 bytes)
    void appendChild(IAptXmlNode*) {}           // 0x8023A8F8
    void setAttribute(char*, char*) {}          // 0x8023AA00
    void* cloneNode(int) { return 0; }          // 0x8023AA70
    void* insertBefore(IAptXmlNode*, IAptXmlNode*) { return 0; } // 0x8023AAAC
    void setNodeName(char*) {}                  // 0x8023AB7C
    void setNodeValue(char*) {}                 // 0x8023ABE0
    void removeNode() {}                        // 0x8023AC38

    // nodeType
    // Address: 0x8023AB80, Size: 8
    int nodeType() {
        return m_nodeType;
    }

    // parentNode
    // Address: 0x8023ABE4, Size: 8
    void* parentNode() {
        return m_parentNode;
    }

    // toString
    // Address: 0x8023AC3C, Size: 8
    char* toString() {
        return m_toString;
    }

    // firstChild
    // Address: 0x8023AA74, Size: 32
    void* firstChild() {
        if (m_firstChild == NULL) return NULL;
        return m_firstChild;
    }

    // lastChild
    // Address: 0x8023AAB0, Size: 40
    void* lastChild() {
        if (m_lastChild == NULL) return NULL;
        return m_lastChild;
    }

    // hasChildNodes
    // Address: 0x8023AA94, Size: 24
    bool hasChildNodes() {
        return m_firstChild != NULL;
    }

    // getFirstChildNode
    // Address: 0x8023AA04, Size: 60
    // NON_MATCHING - iterator setup
    void* getFirstChildNode();

    // getNextChildNode
    // Address: 0x8023AA40, Size: 48
    // NON_MATCHING - iterator advance
    void* getNextChildNode();
};
#endif
