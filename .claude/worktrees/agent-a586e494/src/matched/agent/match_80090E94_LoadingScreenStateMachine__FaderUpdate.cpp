// 0x80090E94 (108 bytes)
// LoadingScreenStateMachine::FaderUpdate(float)

class LoadingScreenStateMachine { public: void FaderUpdate(float); };

__attribute__((naked))
void LoadingScreenStateMachine::FaderUpdate(float) {
    asm volatile(".long 0x386300A8\n.long 0x8003000C\n.long 0x70090010\n.long 0x4D820020\n.long 0x3D20803E\n.long 0xC0030008\n.long 0xC1A980C4\n.long 0xFC006800\n.long 0x4D820020\n.long 0xEC000828\n.long 0xFC006800\n.long 0xD0030008\n.long 0x4C620382\n.long 0x4C830020\n.long 0xD1A30008\n.long 0x70090001\n.long 0x41820014\n.long 0x5400003C\n.long 0x60000004\n.long 0x9003000C\n.long 0x4E800020\n.long 0x70090002\n.long 0x4D820020\n.long 0x540007FA\n.long 0x60000008\n.long 0x9003000C\n.long 0x4E800020");
}
