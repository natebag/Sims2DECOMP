/* 0x801857B8 (104 bytes)
   ActionQueueHUD::RunActionQueue(void) */

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
    void UpdateVisual();
    void RunActionQueue();
};

void ActionQueueHUD::RunActionQueue() {
    if (field_778 != 0) {
        field_778--;
        if (field_778 == 0) {
            CompletePendingOperation();
            if (field_776 != 0) {
                StartPendingOperation();
            }
        }
        UpdateVisual();
    }
}
