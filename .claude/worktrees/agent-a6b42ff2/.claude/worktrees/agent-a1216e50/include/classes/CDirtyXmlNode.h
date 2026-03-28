#ifndef CDIRTYXMLNODE_H
#define CDIRTYXMLNODE_H

#include "types.h"

// CDirtyXmlNode - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 6 known fields (1 named), 45 methods

class CDirtyXmlNode {
public:
    // Constructors / Destructors
    CDirtyXmlNode(void)  // 0x8065FD6C
    ~CDirtyXmlNode(void);  // 0x8065EB50

    // Methods
    void appendChild(IAptXmlNode *);  // 0x8065EC70 (36B)
    void getFirstAttribute(void);  // 0x8065EC94 (120B)
    void getNextAttribute(void);  // 0x8065ED0C (224B)
    void setAttribute(char *, char *);  // 0x8065EDEC (40B)
    void getFirstChildNode(void);  // 0x8065EE14 (120B)
    void getNextChildNode(void);  // 0x8065EE8C (112B)
    void cloneNode(int);  // 0x8065EEFC (36B)
    void firstChild(void);  // 0x8065EF20 (76B)
    void hasChildNodes(void);  // 0x8065EF6C (60B)
    void insertBefore(IAptXmlNode *, IAptXmlNode *);  // 0x8065EFA8 (40B)
    void lastChild(void);  // 0x8065EFD0 (96B)
    void nextSibling(void);  // 0x8065F030 (188B)
    void nodeName(void);  // 0x8065F0EC (124B)
    void setNodeName(char *);  // 0x8065F168 (36B)
    void nodeType(void);  // 0x8065F18C (44B)
    void nodeValue(void);  // 0x8065F1B8 (124B)
    void setNodeValue(char *);  // 0x8065F234 (36B)
    void parentNode(void);  // 0x8065F258 (44B)
    void previousSibling(void);  // 0x8065F284 (184B)
    void removeNode(void);  // 0x8065F33C (32B)
    void toString(void);  // 0x8065F35C (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (getNextAttribute, ~CDirtyXmlNode)
    u32 m_field_004;  // 0x004 [R/W] (getNextAttribute, nodeName, nodeValue)
    u32 m_field_008;  // 0x008 [R] (nodeName, nodeValue)
    u32 m_field_00C;  // 0x00C [R] (nextSibling, previousSibling)
    u32 m_field_010;  // 0x010 [R] (~CDirtyXmlNode)
    u8 _pad_014[8];  // 0x014
    u32 m_field_01C;  // 0x01C [R] (~CDirtyXmlNode)
};

#endif // CDIRTYXMLNODE_H
