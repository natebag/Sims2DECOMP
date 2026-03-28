// 0x800C7D88 (72 bytes)
// cXMTObjectImpl::CAST_IMPL(void)

class cXMTObjectImpl { public: void CAST_IMPL(void); };

__attribute__((naked))
void cXMTObjectImpl::CAST_IMPL(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000020\n.long 0x80630004\n.long 0x81230004\n.long 0xA8090058\n.long 0x8129005C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
