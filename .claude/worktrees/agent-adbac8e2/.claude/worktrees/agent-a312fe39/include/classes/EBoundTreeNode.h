#ifndef EBOUNDTREENODE_H
#define EBOUNDTREENODE_H

#include "types.h"

// EBoundTreeNode - struct layout extracted from assembly analysis
// Estimated minimum size: 0x28 (40 bytes)
// 4 known fields (0 named), 36 methods

class EBoundTreeNode {
public:
    // Constructors / Destructors
    EBoundTreeNode(void)  // 0x807477E0
    ~EBoundTreeNode(void);  // 0x80747D2C

    // Methods
    bool IsBoundTreeNode(EStorable *);  // 0x80748094 (76B)
    void Write(EStream &);  // 0x80747850 (128B)
    void Read(EStream &);  // 0x807478D0 (264B)
    /* ? */ GetReadVersion(void);  // 0x80747FA8 (52B)
    void Deallocate(void);  // 0x807479D8 (312B)
    void SafeDelete(void);  // 0x80747E48 (108B)
    /* ? */ GetTypeInfo(void);  // 0x80747EB4 (44B)
    /* ? */ GetTypeName(void);  // 0x80747EE0 (52B)
    /* ? */ GetTypeKey(void);  // 0x80747F14 (52B)
    /* ? */ GetTypeVersion(void);  // 0x80747F48 (56B)
    void RegisterType(unsigned short);  // 0x80747FDC (116B)
    void New(void);  // 0x80747D6C (80B)
    void Construct(EBoundTreeNode *);  // 0x80747DBC (80B)
    void Destruct(EBoundTreeNode *);  // 0x80747E0C (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x80747F80 (40B)
    void CreateCopy(void);  // 0x80748050 (68B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (Deallocate)
    u8 _pad_004[0x18];  // 0x004
    u32 m_field_01C;  // 0x01C [R] (Write)
    u32 m_field_020;  // 0x020 [R] (Write)
    u32 m_field_024;  // 0x024 [R] (Write)
};

#endif // EBOUNDTREENODE_H
