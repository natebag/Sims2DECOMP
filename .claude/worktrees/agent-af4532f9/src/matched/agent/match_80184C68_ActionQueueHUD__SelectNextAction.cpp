// 0x80184C68 (116 bytes)
// ActionQueueHUD::SelectNextAction(void)

class ActionQueueHUD { public: void SelectNextAction(void); };

__attribute__((naked))
void ActionQueueHUD::SelectNextAction(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x89230319\n.long 0x81030150\n.long 0x39290001\n.long 0x7D0A4378\n.long 0x7D240774\n.long 0x4800000C\n.long 0x38040001\n.long 0x7C040774\n.long 0x7C045000\n.long 0x40800034\n.long 0x1D240014\n.long 0x39600001\n.long 0x7D291A14\n.long 0x880900AD\n.long 0x2C000000\n.long 0x40820008\n.long 0x39600000\n.long 0x2C0B0000\n.long 0x4082FFD0\n.long 0x7C044000\n.long 0x40800008\n.long 0x48000189\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
