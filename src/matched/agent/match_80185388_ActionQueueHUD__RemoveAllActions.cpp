// 0x80185388 (116 bytes)
// ActionQueueHUD::RemoveAllActions(void)

class ActionQueueHUD { public: void RemoveAllActions(void); };

__attribute__((naked))
void ActionQueueHUD::RemoveAllActions(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x88030308\n.long 0x28000001\n.long 0x4081000C\n.long 0x38000001\n.long 0x98030308\n.long 0x89230308\n.long 0x39600006\n.long 0x390302C0\n.long 0x39400000\n.long 0x1D290014\n.long 0x7D234A14\n.long 0x99690168\n.long 0x88030308\n.long 0x5400103A\n.long 0x7D48012E\n.long 0x89230308\n.long 0x8803030A\n.long 0x39290001\n.long 0x99230308\n.long 0x2C000000\n.long 0x40820008\n.long 0x48000015\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
