// 0x80135588 (80 bytes)
// iResFile::iResFile(void)

class iResFile { public: void iResFile(void); };

__attribute__((naked))
void iResFile::iResFile(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x3D208046\n.long 0x7C7E1B78\n.long 0x392943B8\n.long 0x38000000\n.long 0x913E000C\n.long 0x901E0008\n.long 0x4BFFFF8D\n.long 0x7FC3F378\n.long 0x38800000\n.long 0x48000071\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
