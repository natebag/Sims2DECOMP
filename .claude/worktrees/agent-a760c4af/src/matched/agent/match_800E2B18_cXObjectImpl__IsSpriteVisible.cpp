// 0x800E2B18 (88 bytes)
// cXObjectImpl::IsSpriteVisible(short)

class cXObjectImpl { public: void IsSpriteVisible(short); };

__attribute__((naked))
void cXObjectImpl::IsSpriteVisible(short) {
    asm volatile(".long 0xA8030014\n.long 0x7C8B2378\n.long 0x2C000000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x81230088\n.long 0xA8890080\n.long 0x7C0B2000\n.long 0x4180FFEC\n.long 0x7C040214\n.long 0x7C0B0000\n.long 0x4080FFE0\n.long 0x7D245850\n.long 0x81630010\n.long 0x7D294A14\n.long 0x38600001\n.long 0x7C095AAE\n.long 0x2C000000\n.long 0x4C820020\n.long 0x38600000\n.long 0x4E800020");
}
