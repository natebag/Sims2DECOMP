// 0x801BEF40 (96 bytes)
// K2YTarget::SetStartMode(K2YTarget::eK2yboardMode)

class K2YTarget { public: void SetStartMode(K2YTarget::eK2yboardMode); };

__attribute__((naked))
void K2YTarget::SetStartMode(K2YTarget::eK2yboardMode) {
    asm volatile(".long 0x800D89D0\n.long 0x2C000005\n.long 0x41820034\n.long 0x40810014\n.long 0x2C000008\n.long 0x41820034\n.long 0x4180001C\n.long 0x48000038\n.long 0x2C000003\n.long 0x41820030\n.long 0x4181000C\n.long 0x2C000000\n.long 0x41800024\n.long 0x906D89D0\n.long 0x4E800020\n.long 0x38000004\n.long 0x900D89D0\n.long 0x4E800020\n.long 0x38000007\n.long 0x900D89D0\n.long 0x4E800020\n.long 0x38000002\n.long 0x900D89D0\n.long 0x4E800020");
}
