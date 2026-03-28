// 0x80110BB4 (108 bytes)
// ObjSelector::GetUserFullName(BString2 &)

class ObjSelector { public: void GetUserFullName(BString2 &); };

__attribute__((naked))
void ObjSelector::GetUserFullName(BString2 &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x4BFFFE61\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x4BF911F1\n.long 0x801F0088\n.long 0x2C000000\n.long 0x41820028\n.long 0x3C80803E\n.long 0x7FC3F378\n.long 0x3884C348\n.long 0x4BF91635\n.long 0x807F0088\n.long 0x4BF92779\n.long 0x7C641B78\n.long 0x7FC3F378\n.long 0x4BF91621\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
