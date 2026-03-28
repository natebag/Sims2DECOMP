// 0x80110B58 (92 bytes)
// ObjSelector::SetUserLastName(BString2 &)

class ObjSelector { public: void SetUserLastName(BString2 &); };

__attribute__((naked))
void ObjSelector::SetUserLastName(BString2 &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x801F0088\n.long 0x2C000000\n.long 0x4082001C\n.long 0x481BF385\n.long 0x38A00000\n.long 0x38800004\n.long 0x481BFF1D\n.long 0x4BF90F49\n.long 0x907F0088\n.long 0x807F0088\n.long 0x7FC4F378\n.long 0x4BF9122D\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
