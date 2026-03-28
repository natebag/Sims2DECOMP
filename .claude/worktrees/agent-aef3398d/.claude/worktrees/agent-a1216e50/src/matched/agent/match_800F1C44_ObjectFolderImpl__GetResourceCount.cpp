// 0x800F1C44 (116 bytes)
// ObjectFolderImpl::GetResourceCount(unsigned int, unsigned int, unsigned int)

class ObjectFolderImpl { public: void GetResourceCount(unsigned int, unsigned int, unsigned int); };

__attribute__((naked))
void ObjectFolderImpl::GetResourceCount(unsigned int, unsigned int, unsigned int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C6B1B78\n.long 0x7CA42B78\n.long 0x2C060001\n.long 0x4182000C\n.long 0x38600000\n.long 0x48000038\n.long 0x812B0000\n.long 0x8009003C\n.long 0xA8690038\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x8123000C\n.long 0x7FE4FB78\n.long 0xA8090078\n.long 0x8129007C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
