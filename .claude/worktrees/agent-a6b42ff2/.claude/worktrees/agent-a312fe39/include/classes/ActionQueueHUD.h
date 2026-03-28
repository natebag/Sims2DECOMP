#ifndef ACTIONQUEUEHUD_H
#define ACTIONQUEUEHUD_H

#include "types.h"

// ActionQueueHUD - struct layout extracted from assembly analysis
// Estimated minimum size: 0x31A (794 bytes)
// 20 known fields (6 named), 54 methods

class ActionQueueHUD {
public:
    // Constructors / Destructors
    ActionQueueHUD(void)  // 0x804A1F38
    ~ActionQueueHUD(void);  // 0x804A2058

    // Methods
    void Stop(void);  // 0x804A22E4 (584B)
    void DetachController(void);  // 0x804A227C (104B)
    void Start(HUDTarget *);  // 0x804A2160 (52B)
    void AttachController(void);  // 0x804A2194 (232B)
    void Run(void);  // 0x804A252C (108B)
    void RunIngame(void);  // 0x804A2B24 (364B)
    void RunEditActionQueue(void);  // 0x804A2598 (504B)
    void RunActionQueue(void);  // 0x804A38CC (148B)
    void DeactivateEditActionQueue(void);  // 0x804A2A30 (108B)
    void SelectNextAction(void);  // 0x804A2790 (216B)
    void SelectPriorAction(void);  // 0x804A2868 (192B)
    /* ? */ GetPlayerSim(void);  // 0x804A3C38 (132B)
    /* ? */ GetActionCount(void);  // 0x804A6AE4 (44B)
    void OnUserCancelledAction(unsigned int);  // 0x804A2C90 (160B)
    void SelectAction(signed char);  // 0x804A2A9C (136B)
    void ActivateEditActionQueue(void);  // 0x804A2928 (264B)
    void FindActionByGUID(unsigned int);  // 0x804A6B10 (128B)
    void AddAction(ActionQueueHUD::ActionQueueItem &, Interaction *, unsigned int);  // 0x804A2D30 (372B)
    void CatchUpPendingActions(void);  // 0x804A37E4 (232B)
    void StartPendingOperation(void);  // 0x804A3304 (716B)
    void SetAction(ActionQueueHUD::ActionQueueItem &, Interaction *);  // 0x804A2EA4 (340B)
    void RemoveAction(Interaction *);  // 0x804A2FF8 (608B)
    void RemoveAllActions(void);  // 0x804A3258 (172B)
    void CompletePendingOperation(void);  // 0x804A35D0 (532B)
    void UpdateVisual(void);  // 0x804A3960 (728B)
    void Init(int);  // 0x804B07C0 (40B)
    bool IsAvailable(void);  // 0x804B07E8 (60B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ActionQueueHUD, ActionQueueItem::SetupItem, ActionQueueItem::UpdateItem, ...)
    u32 m_field_004;  // 0x004 [R/W] (ActionQueueItem::SetupItem, ActionQueueItem::UpdateItem, RunIngame, ...)
    u32 m_field_008;  // 0x008 [R/W] (ActionQueueItem::SetupItem, ActionQueueItem::UpdateItem)
    u32 m_field_00C;  // 0x00C [W] (ActionQueueItem::SetupItem, ActionQueueItem::UpdateItem)
    u8 _pad_010[0xC];  // 0x010
    u32 m_field_01C;  // 0x01C [R] (Stop)
    u8 _pad_020[0x78];  // 0x020
    u32 m_field_098;  // 0x098 [W] (Stop)
    u8 _pad_09C[0xB4];  // 0x09C
    u32 m_field_150;  // 0x150 [R/W] (ActionQueueHUD, ActivateEditActionQueue, CompletePendingOperation, ...)
    u32 m_field_154;  // 0x154 [W] (ActionQueueHUD, CompletePendingOperation, Stop)
    u32 m_field_158;  // 0x158 [R] (StartPendingOperation)
    u8 _pad_15C[8];  // 0x15C
    u32 m_field_164;  // 0x164 [R] (StartPendingOperation)
    u8 m_visual;  // 0x168 [R/W] (CompletePendingOperation, StartPendingOperation, UpdateVisual)
    u8 _pad_169[0x157];  // 0x169
    u32 m_field_2C0;  // 0x2C0 [R] (CompletePendingOperation, StartPendingOperation)
    u8 _pad_2C4[0x44];  // 0x2C4
    u8 m_action;  // 0x308 [R/W] (ActionQueueHUD, AddAction, CatchUpPendingActions, ...)
    u8 m_visual_309;  // 0x309 [R/W] (ActionQueueHUD, StartPendingOperation, UpdateVisual)
    u8 m_action_30A;  // 0x30A [R/W] (ActionQueueHUD, AddAction, CatchUpPendingActions, ...)
    u8 _pad_30B[1];  // 0x30B
    u32 m_field_30C;  // 0x30C [R/W] (ActionQueueHUD, AttachController, DetachController, ...)
    u32 m_field_310;  // 0x310 [R/W] (ActionQueueHUD, ActivateEditActionQueue, DeactivateEditActionQueue, ...)
    u32 m_playerSim;  // 0x314 [R/W] (ActionQueueHUD, ActivateEditActionQueue, AttachController, ...)
    u8 m_field_318;  // 0x318 [R/W] (ActionQueueHUD, ActivateEditActionQueue, CompletePendingOperation, ...)
    u8 m_field_319;  // 0x319 [R/W] (ActionQueueHUD, ActivateEditActionQueue, CompletePendingOperation, ...)
};

#endif // ACTIONQUEUEHUD_H
