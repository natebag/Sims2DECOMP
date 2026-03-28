// 0x801EE1A4 (92 bytes)
// INVTarget::GetPlayerFunds(void) const

class INVTarget { public: void GetPlayerFunds(void) const; };

__attribute__((naked))
void INVTarget::GetPlayerFunds(void) const {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DAC08\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000030\n.long 0x80030084\n.long 0x38800001\n.long 0x2C000000\n.long 0x40820008\n.long 0x38800000\n.long 0x812B0000\n.long 0xA86900A0\n.long 0x800900A4\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
