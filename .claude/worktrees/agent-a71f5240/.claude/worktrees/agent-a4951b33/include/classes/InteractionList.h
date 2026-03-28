#ifndef INTERACTIONLIST_H
#define INTERACTIONLIST_H

#include "types.h"

// InteractionList - struct layout extracted from assembly analysis
// Estimated minimum size: 0x8 (8 bytes)
// 2 known fields (1 named), 18 methods

class InteractionList {
public:
    // Constructors / Destructors
    InteractionList(void)  // 0x80334968
    ~InteractionList(void);  // 0x803349A0

    // Methods
    void begin(void);  // 0x800A7ECC (76B)
    void end(void);  // 0x800A7F18 (76B)
    void size(void);  // 0x803349F8 (104B)
    void remove(InteractionList::iterator &);  // 0x80334B98 (456B)
    void clear(void);  // 0x80334D60 (184B)
    void push_back(Interaction &);  // 0x80334A60 (144B)
    void push_back(cXPerson *, cXObject *, int, int);  // 0x80334AF0 (168B)
    void increment(InteractionList::iterator &);  // 0x80334E18 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (clear, push_back, remove)
    u32 m_field_004;  // 0x004 [R/W] (clear, push_back, remove)
};

#endif // INTERACTIONLIST_H
