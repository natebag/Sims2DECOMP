// 0x80305E10 (128 bytes)
// EDebugMenu::Remove(EDebugMenuItem &)

class EDebugMenu { public: void Remove(EDebugMenuItem &); };

__attribute__((naked))
void EDebugMenu::Remove(EDebugMenuItem &) {
    asm volatile(".long 0x8003000C\n.long 0x3963000C\n.long 0x7C002000\n.long 0x40820010\n.long 0x80040004\n.long 0x9003000C\n.long 0x48000010\n.long 0x81240000\n.long 0x80040004\n.long 0x90090004\n.long 0x800B0004\n.long 0x7C002000\n.long 0x40820010\n.long 0x80040000\n.long 0x900B0004\n.long 0x48000010\n.long 0x80040000\n.long 0x81240004\n.long 0x90090000\n.long 0x81230018\n.long 0x38000001\n.long 0x90030008\n.long 0x3929FFFF\n.long 0x91230018\n.long 0x2C090000\n.long 0x4D820020\n.long 0x81630014\n.long 0x7C0B4800\n.long 0x4D800020\n.long 0x380BFFFF\n.long 0x90030014\n.long 0x4E800020");
}
