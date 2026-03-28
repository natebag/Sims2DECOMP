// 0x800EB1D0 (72 bytes)
// cXObjectImpl::IsRoof(void)

class cXObjectImpl { public: void IsRoof(void); };

__attribute__((naked))
void cXObjectImpl::IsRoof(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630004\n.long 0x812B0004\n.long 0x80090314\n.long 0xA8690310\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0xA8630012\n.long 0x6863000E\n.long 0x20030000\n.long 0x7C601914\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
