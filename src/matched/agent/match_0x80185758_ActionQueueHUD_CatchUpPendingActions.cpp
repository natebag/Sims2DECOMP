/* 0x80185758 (96 bytes)
   ActionQueueHUD::CatchUpPendingActions(void) */

typedef unsigned char u8;

typedef unsigned int u32;

struct ActionQueueHUD {
    u32 field_0;
    u8 pad1[776];
    u8 field_776;
    u8 field_777;
    u8 field_778;
    
    void CompletePendingOperation();
    void StartPendingOperation();
    void RunActionQueue();
    void CatchUpPendingActions();
};

void ActionQueueHUD::CatchUpPendingActions() {
    if (field_778 != 0) {
        CompletePendingOperation();
    }
    while (field_776 > 17) {
        StartPendingOperation();
        CompletePendingOperation();
    }
    RunActionQueue();
}
