// 0x80106568 (72 bytes)
// cXObjectImpl::TryGbaCommunication(StackElem *, XPrimParam *)

class cXObjectImpl { public: void TryGbaCommunication(StackElem *, XPrimParam *); };

__attribute__((naked))
void cXObjectImpl::TryGbaCommunication(StackElem *, XPrimParam *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208047\n.long 0x80095C70\n.long 0x2C000000\n.long 0x40820018\n.long 0x4BF32A2D\n.long 0x2C030000\n.long 0x38600000\n.long 0x38800001\n.long 0x4082000C\n.long 0x38600000\n.long 0x38800000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
