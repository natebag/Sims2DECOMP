// 0x80052DEC (80 bytes)
// ISimsObjectModel::IsMultiTilePart(void)

class ISimsObjectModel { public: void IsMultiTilePart(void); };

__attribute__((naked))
void ISimsObjectModel::IsMultiTilePart(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630328\n.long 0x812B0004\n.long 0x80090314\n.long 0xA8690310\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x812300C0\n.long 0x38600001\n.long 0x88090009\n.long 0x2C000000\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
