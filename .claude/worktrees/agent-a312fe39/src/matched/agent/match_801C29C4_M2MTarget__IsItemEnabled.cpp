// 0x801C29C4 (96 bytes)
// M2MTarget::IsItemEnabled(int)

class M2MTarget { public: void IsItemEnabled(int); };

__attribute__((naked))
void M2MTarget::IsItemEnabled(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030168\n.long 0x39200001\n.long 0x2C000000\n.long 0x4082000C\n.long 0x39200000\n.long 0x4800002C\n.long 0x8003010C\n.long 0x2C0000FF\n.long 0x4082000C\n.long 0x4BFFF24D\n.long 0x48000014\n.long 0x80030110\n.long 0x2C0000FF\n.long 0x4082000C\n.long 0x4BFFF2F9\n.long 0x7C691B78\n.long 0x7D234B78\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
