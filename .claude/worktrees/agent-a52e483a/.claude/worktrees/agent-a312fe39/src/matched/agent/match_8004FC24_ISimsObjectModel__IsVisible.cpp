// 0x8004FC24 (104 bytes)
// ISimsObjectModel::IsVisible(void)

class ISimsObjectModel { public: void IsVisible(void); };

__attribute__((naked))
void ISimsObjectModel::IsVisible(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80030120\n.long 0x2C000000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4800003C\n.long 0x81630328\n.long 0x2C0B0000\n.long 0x4182002C\n.long 0x812B0004\n.long 0x38800022\n.long 0xA8690260\n.long 0x80090264\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600000\n.long 0x40820008\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
