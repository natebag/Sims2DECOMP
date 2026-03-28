// 0x80105D70 (100 bytes)
// cXObjectImpl::TryTreeBreak(StackElem *, XPrimParam *)

class cXObjectImpl { public: void TryTreeBreak(StackElem *, XPrimParam *); };

__attribute__((naked))
void cXObjectImpl::TryTreeBreak(StackElem *, XPrimParam *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x7CA92B78\n.long 0x38C00000\n.long 0xA8A90000\n.long 0x38E00000\n.long 0xA8890002\n.long 0x39010008\n.long 0x48004D11\n.long 0x2C03FFFF\n.long 0x40820018\n.long 0x2C04FFFF\n.long 0x40820010\n.long 0x3860FFFF\n.long 0x3880FFFF\n.long 0x48000014\n.long 0x38000000\n.long 0x38600000\n.long 0xB0010008\n.long 0x38800001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
