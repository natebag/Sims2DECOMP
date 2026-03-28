// 0x801849F0 (64 bytes)
// ActionQueueHUD::Run(void)

class ActionQueueHUD { public: void Run(void); };

__attribute__((naked))
void ActionQueueHUD::Run(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x88030318\n.long 0x2C000001\n.long 0x41820010\n.long 0x2C000002\n.long 0x41820010\n.long 0x48000010\n.long 0x48000479\n.long 0x48000008\n.long 0x48000015\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
