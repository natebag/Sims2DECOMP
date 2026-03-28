#ifndef ERCHARACTER_H
#define ERCHARACTER_H

#include "types.h"

// ERCharacter - struct layout extracted from assembly analysis
// Estimated minimum size: 0xB4 (180 bytes)
// 3 known fields (1 named), 38 methods

class ERCharacter {
public:
    // Constructors / Destructors
    ERCharacter(void)  // 0x8083BB2C
    ~ERCharacter(void);  // 0x8083BB90

    // Methods
    void Load(EFile &);  // 0x8083BC04 (284B)
    void Refresh(EFile *);  // 0x8083BD20 (112B)
    void FindNode(char *);  // 0x8083BD90 (176B)
    void PrintNodes(void);  // 0x8083BE40 (328B)
    void SafeDelete(void);  // 0x8083D5A0 (108B)
    /* ? */ GetTypeInfo(void);  // 0x8083D60C (44B)
    /* ? */ GetTypeName(void);  // 0x8083D638 (52B)
    /* ? */ GetTypeKey(void);  // 0x8083D66C (52B)
    /* ? */ GetTypeVersion(void);  // 0x8083D6A0 (56B)
    void RegisterType(unsigned short);  // 0x8083D734 (116B)
    void New(void);  // 0x8083D4CC (76B)
    void Construct(ERCharacter *);  // 0x8083D518 (76B)
    void Destruct(ERCharacter *);  // 0x8083D564 (60B)
    /* ? */ GetTypeInfoStatic(void);  // 0x8083D6D8 (40B)
    /* ? */ GetReadVersion(void);  // 0x8083D700 (52B)
    void CreateCopy(void);  // 0x8083D7A8 (68B)
    /* ? */ GetNode(int);  // 0x8083D988 (284B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (ERCharacter, ~ERCharacter)
    u8 _pad_004[0x10];  // 0x004
    u32 m_field_014;  // 0x014 [R] (FindNode)
    u8 _pad_018[0x98];  // 0x018
    u32 m_field_0B0;  // 0x0B0 [W] (Load)
};

#endif // ERCHARACTER_H
