// 0x8012C788 (84 bytes)
// cXPersonImpl::IsCarrying(void)

class cXPersonImpl { public: void IsCarrying(void); };

__attribute__((naked))
void cXPersonImpl::IsCarrying(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630000\n.long 0x38800000\n.long 0x814B0004\n.long 0x812A0004\n.long 0x800902BC\n.long 0xA86902B8\n.long 0x7C0803A6\n.long 0x7C6A1A14\n.long 0x4E800021\n.long 0xA8030004\n.long 0x38600001\n.long 0x2C000000\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
