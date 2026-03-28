// 0x800EB84C (80 bytes)
// cXObjectImpl::GetFirstImpl(void)

class cXObjectImpl { public: void GetFirstImpl(void); };

__attribute__((naked))
void cXObjectImpl::GetFirstImpl(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630058\n.long 0x812B0000\n.long 0x8009009C\n.long 0xA8690098\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230004\n.long 0xA8090520\n.long 0x81290524\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
