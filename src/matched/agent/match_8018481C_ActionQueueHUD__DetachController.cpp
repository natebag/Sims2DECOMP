// 0x8018481C (80 bytes)
// ActionQueueHUD::DetachController(void)

class ActionQueueHUD { public: void DetachController(void); };

__attribute__((naked))
void ActionQueueHUD::DetachController(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F030C\n.long 0x2C000000\n.long 0x41820020\n.long 0x809F0314\n.long 0x806D9864\n.long 0x4819EDE9\n.long 0x809F030C\n.long 0x48180AA1\n.long 0x38000000\n.long 0x901F030C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
