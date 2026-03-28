// 0x80185820 (80 bytes)
// ActionQueueHUD::UpdateVisual(void)

class ActionQueueHUD { public: void UpdateVisual(void); };

__attribute__((naked))
void ActionQueueHUD::UpdateVisual(void) {
    asm volatile(".long 0x80030150\n.long 0x39200000\n.long 0x7C090040\n.long 0x4C800020\n.long 0x89630168\n.long 0x7C0A0378\n.long 0x2C8B0006\n.long 0x2F0B0005\n.long 0x41860020\n.long 0x88030308\n.long 0x2C000000\n.long 0x41820014\n.long 0x88030309\n.long 0x7C090040\n.long 0x41800008\n.long 0x2C0B0001\n.long 0x39290001\n.long 0x7C095040\n.long 0x4180FFD8\n.long 0x4E800020");
}
