// 0x80132E18 (124 bytes)
// ReconBuffer::~ReconBuffer(void)

class ReconBuffer { public: void ~ReconBuffer(void); };

__attribute__((naked))
void ReconBuffer::~ReconBuffer(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x801F000C\n.long 0x2C000001\n.long 0x40820028\n.long 0x817F001C\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0000\n.long 0xA8690108\n.long 0x8009010C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x807F001C\n.long 0x4BF74719\n.long 0x38000000\n.long 0x73C90001\n.long 0x901F001C\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4819E3A5\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
