// 0x800C71F0 (80 bytes)
// cXMTObjectImpl::IsDynamic(void)

class cXMTObjectImpl { public: void IsDynamic(void); };

__attribute__((naked))
void cXMTObjectImpl::IsDynamic(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630000\n.long 0x38800008\n.long 0x814B0004\n.long 0x812A0004\n.long 0xA86901D0\n.long 0x800901D4\n.long 0x7C6A1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600001\n.long 0x40820008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
