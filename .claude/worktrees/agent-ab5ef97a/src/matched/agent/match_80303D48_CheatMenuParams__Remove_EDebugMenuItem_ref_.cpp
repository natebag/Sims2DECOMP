// 0x80303D48 (100 bytes)
// CheatMenuParams::Remove(EDebugMenuItem &)

class CheatMenuParams { public: void Remove(EDebugMenuItem &); };

__attribute__((naked))
void CheatMenuParams::Remove(EDebugMenuItem &) {
    asm volatile(".long 0x80030008\n.long 0x2C000000\n.long 0x4D820020\n.long 0x80030000\n.long 0x7C002000\n.long 0x40820010\n.long 0x80040004\n.long 0x90030000\n.long 0x48000010\n.long 0x81240000\n.long 0x80040004\n.long 0x90090004\n.long 0x80030004\n.long 0x7C002000\n.long 0x40820010\n.long 0x80040000\n.long 0x90030004\n.long 0x48000010\n.long 0x80040000\n.long 0x81240004\n.long 0x90090000\n.long 0x81230008\n.long 0x3929FFFF\n.long 0x91230008\n.long 0x4E800020");
}
