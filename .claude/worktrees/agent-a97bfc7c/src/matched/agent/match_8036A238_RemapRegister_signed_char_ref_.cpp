// 0x8036A238 (64 bytes)
// RemapRegister(signed char &)

__attribute__((naked))
void RemapRegister(signed char &) {
    asm volatile(".long 0x88030000\n.long 0x7C000774\n.long 0x2C00000B\n.long 0x4D820020\n.long 0x4C810020\n.long 0x2C000032\n.long 0x41820010\n.long 0x2C000037\n.long 0x41820014\n.long 0x4E800020\n.long 0x3800000B\n.long 0x98030000\n.long 0x4E800020\n.long 0x38000006\n.long 0x98030000\n.long 0x4E800020");
}
