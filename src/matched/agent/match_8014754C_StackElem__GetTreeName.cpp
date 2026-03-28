// 0x8014754C (92 bytes)
// StackElem::GetTreeName(StringBuffer &)

class StackElem { public: void GetTreeName(StringBuffer &); };

__attribute__((naked))
void StackElem::GetTreeName(StringBuffer &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x83E30010\n.long 0x7C9E2378\n.long 0x2C1F0000\n.long 0x4182001C\n.long 0x48001BAD\n.long 0x7C641B78\n.long 0x7FC5F378\n.long 0x7FE3FB78\n.long 0x4BF64F29\n.long 0x48000014\n.long 0x3C80803E\n.long 0x7FC3F378\n.long 0x3884D7BC\n.long 0x4BF5F199\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
