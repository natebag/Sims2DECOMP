#ifndef EREDITHTREESET_H
#define EREDITHTREESET_H

#include "types.h"

// EREdithTreeSet - struct layout extracted from assembly analysis
// Estimated minimum size: 0x20 (32 bytes)
// 5 known fields (3 named), 44 methods

class EREdithTreeSet {
public:
    // Constructors / Destructors
    EREdithTreeSet(void)  // 0x808408B8
    ~EREdithTreeSet(void);  // 0x80840914

    // Methods
    /* ? */ GetNumTrees(void);  // 0x8084196C (44B)
    /* ? */ GetTreeIDByName(char *);  // 0x8084147C (172B)
    /* ? */ GetTreeIDByIndex(int);  // 0x80841404 (120B)
    /* ? */ GetBehaviorTree(int);  // 0x80841308 (252B)
    void Deallocate(void);  // 0x80840980 (108B)
    void Write(EStream &);  // 0x808409EC (196B)
    void Read(EStream &);  // 0x80840AB0 (196B)
    void Load(EFile *, unsigned int);  // 0x80840B74 (1940B)
    void SafeDelete(void);  // 0x80841720 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8084178C (44B)
    /* ? */ GetTypeName(void);  // 0x808417B8 (52B)
    /* ? */ GetTypeKey(void);  // 0x808417EC (52B)
    /* ? */ GetTypeVersion(void);  // 0x80841820 (56B)
    void RegisterType(unsigned short);  // 0x808418B4 (116B)
    void New(void);  // 0x8084164C (76B)
    void Construct(EREdithTreeSet *);  // 0x80841698 (76B)
    void Destruct(EREdithTreeSet *);  // 0x808416E4 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80841858 (40B)
    /* ? */ GetReadVersion(void);  // 0x80841880 (52B)
    void CreateCopy(void);  // 0x80841928 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (EREdithTreeSet, ~EREdithTreeSet)
    u8 _pad_004[0xC];  // 0x004
    u32 m_field_010;  // 0x010 [R/W] (Load)
    u32 m_field_014;  // 0x014 [R/W] (Deallocate, EREdithTreeSet, Load)
    u32 m_treeIDByName;  // 0x018 [R/W] (GetBehaviorTree, GetTreeIDByName, Load)
    u32 m_behaviorTree;  // 0x01C [R/W] (Deallocate, EREdithTreeSet, GetBehaviorTree, ...)
};

#endif // EREDITHTREESET_H
