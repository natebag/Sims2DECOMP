#ifndef CDIRTYXML_H
#define CDIRTYXML_H

#include "types.h"

// CDirtyXml - struct layout extracted from assembly analysis
// Estimated minimum size: 0x24 (36 bytes)
// 5 known fields (1 named), 77 methods

class CDirtyXml {
public:
    // Constructors / Destructors
    CDirtyXml(void)  // 0x8065FDB8
    ~CDirtyXml(void);  // 0x8065F914

    // Methods
    void appendChild(IAptXmlNode *);  // 0x8065F384 (64B)
    void getFirstAttribute(void);  // 0x8065F3C4 (76B)
    void getNextAttribute(void);  // 0x8065F410 (76B)
    void setAttribute(char *, char *);  // 0x8065F45C (72B)
    void getFirstChildNode(void);  // 0x8065F4A4 (68B)
    void getNextChildNode(void);  // 0x8065F4E8 (68B)
    void cloneNode(int);  // 0x8065F52C (64B)
    void firstChild(void);  // 0x8065F56C (68B)
    void hasChildNodes(void);  // 0x8065F5B0 (68B)
    void insertBefore(IAptXmlNode *, IAptXmlNode *);  // 0x8065F5F4 (72B)
    void lastChild(void);  // 0x8065F63C (68B)
    void nextSibling(void);  // 0x8065F680 (68B)
    void nodeName(void);  // 0x8065F6C4 (68B)
    void setNodeName(char *);  // 0x8065F708 (64B)
    void nodeType(void);  // 0x8065F748 (68B)
    void nodeValue(void);  // 0x8065F78C (68B)
    void setNodeValue(char *);  // 0x8065F7D0 (64B)
    void parentNode(void);  // 0x8065F810 (68B)
    void previousSibling(void);  // 0x8065F854 (68B)
    void removeNode(void);  // 0x8065F898 (56B)
    void toString(void);  // 0x8065F8D0 (68B)
    void contentType(void);  // 0x8065F9A0 (40B)
    void setContentType(char *);  // 0x8065F9C8 (36B)
    void createElement(char *);  // 0x8065F9EC (44B)
    void createTextNode(char *);  // 0x8065FA18 (44B)
    void docTypeDecl(void);  // 0x8065FA44 (40B)
    void setDocTypeDecl(char *);  // 0x8065FA6C (36B)
    void getBytesTotal(void);  // 0x8065FA90 (40B)
    void getBytesLoaded(void);  // 0x8065FAB8 (40B)
    void setIgnoreWhite(int);  // 0x8065FAE0 (36B)
    void isIgnoreWhite(void);  // 0x8065FB04 (40B)
    void load(char *);  // 0x8065FB2C (36B)
    void isLoaded(void);  // 0x8065FB50 (40B)
    void parseXml(char *);  // 0x8065FB78 (164B)
    void send(char *);  // 0x8065FC1C (36B)
    void sendAndLoad(char *, IAptXml *);  // 0x8065FC40 (40B)
    void status(void);  // 0x8065FC68 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (~CDirtyXml)
    u32 m_field_004;  // 0x004 [R/W] (parseXml, ~CDirtyXml)
    u8 _pad_008[8];  // 0x008
    u32 m_field_010;  // 0x010 [W] (parseXml)
    u8 _pad_014[8];  // 0x014
    u32 m_field_01C;  // 0x01C [R/W] (parseXml)
    u32 m_field_020;  // 0x020 [W] (~CDirtyXml)
};

#endif // CDIRTYXML_H
