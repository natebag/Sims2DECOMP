// 0x80184E04 (76 bytes)
// ActionQueueHUD::DeactivateEditActionQueue(void)

class ActionQueueHUD { public: void DeactivateEditActionQueue(void); };

__attribute__((naked))
void ActionQueueHUD::DeactivateEditActionQueue(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000001\n.long 0x981E0318\n.long 0x809E0314\n.long 0x806D9864\n.long 0x4819E805\n.long 0x809E0310\n.long 0x481804BD\n.long 0x38000000\n.long 0x901E0310\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
