#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "types.h"

// Behavior - struct layout extracted from assembly analysis
// Estimated minimum size: 0x10 (16 bytes)
// 6 known fields (6 named), 58 methods

class Behavior {
public:
    // Constructors / Destructors
    Behavior(void)  // 0x80212684
    ~Behavior(void);  // 0x802126D0

    // Methods
    void CountNodes(short);  // 0x8021289C (232B)
    /* ? */ GetTree(short, ObjectDataBehaviorTree **, bool);  // 0x80213E88 (840B)
    /* ? */ GetNamespaceID(void);  // 0x80212984 (68B)
    /* ? */ GetSemiGlobalNamespaceID(void);  // 0x802129C8 (68B)
    /* ? */ GetGlobNamespaceID(void);  // 0x80212A0C (64B)
    /* ? */ GetNode(short, short, BehaviorNode *);  // 0x80212A4C (304B)
    /* ? */ GetNodeRef(short, short, BehaviorNode **);  // 0x80212B7C (944B)
    bool IsNodeReachable(short, int);  // 0x80212F2C (492B)
    /* ? */ GetNodeText(short, BehaviorNode *, StringBuffer &);  // 0x80213118 (148B)
    /* ? */ GetNodeText(short, short, StringBuffer &);  // 0x802131AC (176B)
    void CountPrimitives(void);  // 0x8021325C (112B)
    /* ? */ GetResFileID(short);  // 0x802132CC (216B)
    /* ? */ GetBaseID(short);  // 0x802133A4 (176B)
    /* ? */ GetMaxID(short);  // 0x80213454 (176B)
    /* ? */ GetTreeClass(short);  // 0x80213504 (216B)
    /* ? */ GetClassName(short, StringBuffer &);  // 0x802135DC (212B)
    bool IsSingleExit(short, short);  // 0x802136B0 (548B)
    /* ? */ GetCumulativeTreeVersion(short);  // 0x80213A14 (1140B)
    /* ? */ GetOwner(void);  // 0x80216630 (44B)
    /* ? */ GetTreeIDByNameFast(char *);  // 0x802141D0 (116B)
    /* ? */ GetTreeName(short, StringBuffer &);  // 0x80214244 (400B)
    /* ? */ GetConstants(short, ObjectDataBehaviorConstants **);  // 0x802143D4 (428B)
    void Init(Language *, ObjSelector *);  // 0x80214580 (320B)
    /* ? */ GetLanguage(void);  // 0x8021665C (44B)
    /* ? */ GetResFileIDByClass(short);  // 0x80216688 (124B)
    bool IsDefaultParam(BehaviorNodeParam *);  // 0x80216704 (80B)
    void SetDefaultParam(BehaviorNodeParam *);  // 0x80216754 (48B)

    // ---- Field Layout (from assembly analysis) ----
    s16 m_treeName;  // 0x000 [R/W] (GetConstants, GetCumulativeTreeVersion, GetNodeRef, ...)
    u8 m_bIsSingleExit;  // 0x002 [R] (IsNodeReachable, IsSingleExit)
    u8 m_bIsSingleExit_003;  // 0x003 [R] (IsNodeReachable, IsSingleExit)
    u32 m_resFileID;  // 0x004 [R/W] (GetCumulativeTreeVersion, GetResFileID, Init)
    u32 m_treeName_008;  // 0x008 [R/W] (GetTreeName, Init, IsSingleExit)
    u32 m_cumulativeTreeVersion;  // 0x00C [R/W] (GetCumulativeTreeVersion, Init)
};

#endif // BEHAVIOR_H
