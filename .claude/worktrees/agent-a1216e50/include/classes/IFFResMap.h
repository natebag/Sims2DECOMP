#ifndef IFFRESMAP_H
#define IFFRESMAP_H

#include "types.h"

// IFFResMap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x18 (24 bytes)
// 8 known fields (7 named), 42 methods

class IFFResMap {
public:
    // Constructors / Destructors
    IFFResMap(void)  // 0x80258EA4
    ~IFFResMap(void);  // 0x80258E64

    // Methods
    void UpdateOffset(int, int);  // 0x8025044C (360B)
    /* ? */ GetResList(unsigned int, bool);  // 0x802505B4 (280B)
    void MakeNewNode(unsigned int);  // 0x802506CC (152B)
    /* ? */ GetNode(unsigned int, int, void (*);  // 0x80250764 (272B)
    /* ? */ GetNodeWithLanguage(unsigned int, int, char, void (*);  // 0x80250874 (428B)
    /* ? */ GetNode(unsigned int, StackString<64> &, void (*);  // 0x80250A20 (284B)
    /* ? */ GetNode(Memory::HandleNode *, unsigned int *, void (*);  // 0x80250B3C (272B)
    /* ? */ GetIndNode(unsigned int, int, void (*);  // 0x80250C4C (220B)
    void RemoveNode(IFFResNode *);  // 0x80250D28 (340B)
    void CountTypes(void);  // 0x80250E7C (68B)
    /* ? */ GetIndexedType(int);  // 0x80250EC0 (144B)
    void CountNodes(unsigned int);  // 0x80250F50 (128B)
    void FreeAllHandles(void);  // 0x80250FD0 (196B)
    void RemoveAllNodes(void);  // 0x80251094 (56B)
    void RemoveAllNodesOfType(unsigned int);  // 0x802510CC (112B)
    /* ? */ GetLastSwizzleProc(unsigned int);  // 0x8025113C (124B)
    /* ? */ GetHighestID(unsigned int, short);  // 0x802511B8 (232B)
    void DoStream(ReconBuffer *, int);  // 0x802512A0 (116B)
    void AddToFragSize(int);  // 0x80258F08 (48B)
    /* ? */ GetFragSize(void);  // 0x80258F60 (44B)
    void SetFragSize(int);  // 0x80258F38 (40B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (CountNodes, DoStream, FreeAllHandles, ...)
    u32 m_resList_004;  // 0x004 [R/W] (CountNodes, FreeAllHandles, GetHighestID, ...)
    s16 m_highestID;  // 0x006 [R] (GetHighestID)
    s16 m_nodeWithLanguage;  // 0x008 [R/W] (GetNode, GetNodeWithLanguage, MakeNewNode, ...)
    u16 m_field_00A;  // 0x00A [W] (MakeNewNode, RemoveNode)
    u32 m_resList_00C;  // 0x00C [R/W] (GetNode, GetResList, MakeNewNode, ...)
    u32 m_resList_010;  // 0x010 [R/W] (GetResList, RemoveAllNodesOfType, RemoveNode)
    u32 m_nodeWithLanguage_014;  // 0x014 [R/W] (GetIndNode, GetLastSwizzleProc, GetNode, ...)
};

#endif // IFFRESMAP_H
