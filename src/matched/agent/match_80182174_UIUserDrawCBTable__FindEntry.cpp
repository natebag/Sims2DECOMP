// 0x80182174 (92 bytes)
// UIUserDrawCBTable::FindEntry(char *)

class UIUserDrawCBTable { public: void FindEntry(char *); };

__attribute__((naked))
void UIUserDrawCBTable::FindEntry(char *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83E30000\n.long 0x7C9E2378\n.long 0x48000008\n.long 0x83FF0004\n.long 0x2C1F0000\n.long 0x41820020\n.long 0x807F0008\n.long 0x7C03F000\n.long 0x41820014\n.long 0x7FC4F378\n.long 0x480C168D\n.long 0x2C030000\n.long 0x4082FFDC\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
