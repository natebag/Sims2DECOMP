// 0x80110A80 (92 bytes)
// ObjSelector::SetUserName(BString2 &)

class ObjSelector { public: void SetUserName(BString2 &); };

__attribute__((naked))
void ObjSelector::SetUserName(BString2 &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x801F0084\n.long 0x2C000000\n.long 0x4082001C\n.long 0x481BF45D\n.long 0x38A00000\n.long 0x38800004\n.long 0x481BFFF5\n.long 0x4BF91021\n.long 0x907F0084\n.long 0x807F0084\n.long 0x7FC4F378\n.long 0x4BF91305\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
