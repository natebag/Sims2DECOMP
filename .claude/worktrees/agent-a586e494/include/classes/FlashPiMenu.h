#ifndef FLASHPIMENU_H
#define FLASHPIMENU_H

#include "types.h"

// FlashPiMenu - struct layout extracted from assembly analysis
// Estimated minimum size: 0x60 (96 bytes)
// 6 known fields (1 named), 32 methods

class FlashPiMenu {
public:
    // Constructors / Destructors
    FlashPiMenu(int)  // 0x800A2594
    FlashPiMenu(void)  // 0x800A8148
    ~FlashPiMenu(void);  // 0x800A25E4

    // Methods
    void CleanUpAllMenus(void);  // 0x800A2668 (32B)
    void Update(void);  // 0x800A2648 (32B)
    void CreateMenuForGoHere(bool);  // 0x800A2688 (412B)
    void CreateGoHereObjectForMenu(void);  // 0x800A3BD8 (1560B)
    void ChooseAction(cXObject *, Interaction *, bool);  // 0x800A41F0 (788B)
    void CleanupDestinationObject(void);  // 0x800A3978 (432B)
    void CreateInteractionMenu(cXObject *, InteractionList &);  // 0x800A3164 (2068B)
    void CreateObjectMenuFromObjList(TNodeList<ISimInstance *> &);  // 0x800A2824 (484B)
    void AddObjectInteractionsToMenu(cXObject *, bool);  // 0x800A2A08 (336B)
    void Die(void);  // 0x800A3B28 (128B)
    void Kill(void);  // 0x800A3BA8 (48B)
    void BackedOutOfMenu(void);  // 0x800A4504 (148B)
    /* ? */ GetPlayerId(void);  // 0x800A81E0 (48B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ChooseAction, CleanupDestinationObject, CreateGoHereObjectForMenu, ...)
    u32 m_field_004;  // 0x004 [R/W] (ChooseAction, CleanupDestinationObject, CreateObjectMenuFromObjList, ...)
    u32 m_field_008;  // 0x008 [R] (AddObjectInteractionsToMenu, BackedOutOfMenu, ChooseAction, ...)
    u32 m_field_00C;  // 0x00C [W] (~FlashPiMenu)
    u8 _pad_010[0x2C];  // 0x010
    u32 m_field_03C;  // 0x03C [R] (CreateInteractionMenu)
    u8 _pad_040[0x1C];  // 0x040
    u32 m_field_05C;  // 0x05C [R] (ChooseAction)
};

#endif // FLASHPIMENU_H
