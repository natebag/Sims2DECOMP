// 0x801EB5E4 (120 bytes)
// GOLTarget::IsHouseUnlocked(int, int)

class GOLTarget { public: void IsHouseUnlocked(int, int); };

__attribute__((naked))
void GOLTarget::IsHouseUnlocked(int, int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x806DAC1C\n.long 0x38800001\n.long 0x3BE00000\n.long 0x81230000\n.long 0xA8090120\n.long 0x81290124\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C6B1B79\n.long 0x41820028\n.long 0x812B0000\n.long 0xA8690148\n.long 0x8009014C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x41820008\n.long 0x3BE00001\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
