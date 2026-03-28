// 0x80185758 (96 bytes)
// ActionQueueHUD::CatchUpPendingActions(void)

class ActionQueueHUD { public: void CatchUpPendingActions(void); };

__attribute__((naked))
void ActionQueueHUD::CatchUpPendingActions(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x881F030A\n.long 0x2C000000\n.long 0x4182001C\n.long 0x4BFFFE59\n.long 0x48000014\n.long 0x7FE3FB78\n.long 0x4BFFFC79\n.long 0x7FE3FB78\n.long 0x4BFFFE45\n.long 0x881F0308\n.long 0x28000011\n.long 0x4181FFE8\n.long 0x7FE3FB78\n.long 0x48000019\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
