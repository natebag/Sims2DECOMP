// 0x803576E0 (116 bytes)
// Bloom::SetTargetSettings(BloomSettings &)

class Bloom { public: void SetTargetSettings(BloomSettings &); };

__attribute__((naked))
void Bloom::SetTargetSettings(BloomSettings &) {
    asm volatile(".long 0x38630014\n.long 0x39200018\n.long 0x80040000\n.long 0x3529FFE8\n.long 0x90030000\n.long 0x80040004\n.long 0x90030004\n.long 0x80040008\n.long 0x90030008\n.long 0x8004000C\n.long 0x9003000C\n.long 0x80040010\n.long 0x90030010\n.long 0x80040014\n.long 0x38840018\n.long 0x90030014\n.long 0x38630018\n.long 0x4082FFC4\n.long 0x80040000\n.long 0x90030000\n.long 0x80040004\n.long 0x90030004\n.long 0x80040008\n.long 0x90030008\n.long 0x8004000C\n.long 0x9003000C\n.long 0x80040010\n.long 0x90030010\n.long 0x4E800020");
}
