// 0x8016A8F8 (88 bytes)
// CasSimPartsS2C::~CasSimPartsS2C(void)

class CasSimPartsS2C { public: void ~CasSimPartsS2C(void); };

__attribute__((naked))
void CasSimPartsS2C::~CasSimPartsS2C(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x3BA00000\n.long 0x807F0000\n.long 0x7C9E2378\n.long 0x93BF0004\n.long 0x2C030000\n.long 0x4182000C\n.long 0x481A764D\n.long 0x93BF0000\n.long 0x73C00001\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x481668E9\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
