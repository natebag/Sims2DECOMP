// 0x801847C4 (88 bytes)
// ActionQueueHUD::AttachController(void)

class ActionQueueHUD { public: void AttachController(void); };

__attribute__((naked))
void ActionQueueHUD::AttachController(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F030C\n.long 0x2C000000\n.long 0x40820028\n.long 0x809F0314\n.long 0x806D9864\n.long 0x4819EE41\n.long 0x3CA0803F\n.long 0x38800000\n.long 0x38A5A7F0\n.long 0x38C00064\n.long 0x481809FD\n.long 0x907F030C\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
