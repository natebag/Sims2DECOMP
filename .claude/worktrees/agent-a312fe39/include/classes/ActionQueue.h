#ifndef ACTIONQUEUE_H
#define ACTIONQUEUE_H

#include "types.h"

// ActionQueue - struct layout extracted from assembly analysis
// Estimated minimum size: 0x2B2 (690 bytes)
// 6 known fields (2 named), 33 methods

class ActionQueue {
public:
    // Constructors / Destructors
    ActionQueue(void)  // 0x803513F8
    ~ActionQueue(void);  // 0x80379328

    // Methods
    void Peek(unsigned int, Interaction &);  // 0x803299B8 (84B)
    void CountVisible(void);  // 0x80351440 (240B)
    void Count(void);  // 0x803793B4 (68B)
    bool IsVisibleAction(Interaction &);  // 0x8035186C (272B)
    void AddActionToHUD(int);  // 0x80351530 (328B)
    void FindVisualInsertGUID(unsigned int);  // 0x8035197C (188B)
    void RemoveActionFromHUD(int);  // 0x80351678 (172B)
    void SetActionText(BString2 &, unsigned int);  // 0x80351724 (124B)
    void SetIconObject(cXObject *, unsigned int);  // 0x803517A0 (204B)
    void UpdateAction(unsigned int);  // 0x80351A38 (164B)
    void Insert(Interaction &, unsigned int);  // 0x80351ADC (172B)
    void Remove(unsigned int);  // 0x80351B88 (296B)
    void Enqueue(Interaction &);  // 0x80351CB0 (92B)
    void DisableHUDAccess(int);  // 0x80351D0C (132B)
    void EnableHUDAccess(int);  // 0x80351D90 (252B)
    void Peek(unsigned int);  // 0x80379604 (76B)
    void PeekNC(unsigned int);  // 0x803795B8 (76B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x38];  // 0x000
    u32 m_field_038;  // 0x038 [R] (Insert)
    u8 _pad_03C[0xC];  // 0x03C
    u32 m_field_048;  // 0x048 [R] (AddActionToHUD)
    u8 _pad_04C[0x25C];  // 0x04C
    u32 m_iconObject;  // 0x2A8 [R/W] (ActionQueue, AddActionToHUD, CountVisible, ...)
    u32 m_iconObject_2AC;  // 0x2AC [R/W] (ActionQueue, CountVisible, EnableHUDAccess, ...)
    u8 m_field_2B0;  // 0x2B0 [R/W] (ActionQueue, AddActionToHUD, DisableHUDAccess, ...)
    u8 m_field_2B1;  // 0x2B1 [R/W] (AddActionToHUD, DisableHUDAccess, EnableHUDAccess, ...)
};

#endif // ACTIONQUEUE_H
