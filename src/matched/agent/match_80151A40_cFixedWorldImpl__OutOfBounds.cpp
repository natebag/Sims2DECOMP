// 0x80151A40 (80 bytes)
// cFixedWorldImpl::OutOfBounds(CTilePt &) const

class cFixedWorldImpl { public: void OutOfBounds(CTilePt &) const; };

__attribute__((naked))
void cFixedWorldImpl::OutOfBounds(CTilePt &) const {
    asm volatile(".long 0x88040000\n.long 0x7C000774\n.long 0x2C000000\n.long 0x40810034\n.long 0x81230014\n.long 0x3929FFFF\n.long 0x7C004800\n.long 0x40800024\n.long 0x88040001\n.long 0x7C000774\n.long 0x2C000000\n.long 0x40810014\n.long 0x81230018\n.long 0x3929FFFF\n.long 0x7C004800\n.long 0x4180000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x38600000\n.long 0x4E800020");
}
