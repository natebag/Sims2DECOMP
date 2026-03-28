// 0x801B3314 (116 bytes)
// FAMTarget::EvictFamily(void)

class FAMTarget { public: void EvictFamily(void); };

__attribute__((naked))
void FAMTarget::EvictFamily(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x809F014C\n.long 0x4BFFF6C5\n.long 0x800D84D0\n.long 0x7C7E1B78\n.long 0x2C000000\n.long 0x40820014\n.long 0x38600078\n.long 0x4811DE6D\n.long 0x4BFC3D79\n.long 0x906D84D0\n.long 0x806D84D0\n.long 0x3C803FE4\n.long 0x6084572B\n.long 0x4BFC4315\n.long 0x387EFFFF\n.long 0x4BE8FECD\n.long 0x7FE3FB78\n.long 0x38800002\n.long 0x4BFFF299\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
