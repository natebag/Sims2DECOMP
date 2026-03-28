// 0x80195D48 (124 bytes)
// CASTarget::CreateModStrFromValues(char *, BitFlags<unsigned int>)

class CASTarget { public: void CreateModStrFromValues(char *, BitFlags<unsigned int>); };

__attribute__((naked))
void CASTarget::CreateModStrFromValues(char *, BitFlags<unsigned int>) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7CBE2B78\n.long 0x7FE3FB78\n.long 0x38800000\n.long 0x38A00008\n.long 0x480AD879\n.long 0x38000007\n.long 0x39200000\n.long 0x7C0903A6\n.long 0x801E0000\n.long 0x39600030\n.long 0x7C004C30\n.long 0x700A0001\n.long 0x41820008\n.long 0x39600031\n.long 0x7D7F49AE\n.long 0x39290001\n.long 0x4200FFE0\n.long 0x39200031\n.long 0x38000000\n.long 0x981F0008\n.long 0x993F0007\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
