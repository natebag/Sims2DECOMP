// 0x8016A894 (100 bytes)
// CasSimPartsS2C::CasSimPartsS2C(void)

class CasSimPartsS2C { public: void CasSimPartsS2C(void); };

__attribute__((naked))
void CasSimPartsS2C::CasSimPartsS2C(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38000000\n.long 0x39200001\n.long 0x3C60804C\n.long 0x3C802A2A\n.long 0x913E0008\n.long 0x901E000C\n.long 0x3863AEA0\n.long 0x901E0000\n.long 0x6084F469\n.long 0x901E0004\n.long 0x38A00000\n.long 0x38C00000\n.long 0x481BC421\n.long 0x907E0000\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
