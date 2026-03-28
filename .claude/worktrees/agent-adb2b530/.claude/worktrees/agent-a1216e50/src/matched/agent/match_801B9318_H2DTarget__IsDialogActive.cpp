// 0x801B9318 (116 bytes)
// H2DTarget::IsDialogActive(void)

class H2DTarget { public: void IsDialogActive(void); };

__attribute__((naked))
void H2DTarget::IsDialogActive(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x3BC00000\n.long 0x807F00C8\n.long 0x2C030000\n.long 0x41820010\n.long 0x4800A965\n.long 0x2C030000\n.long 0x4082002C\n.long 0x3D208047\n.long 0x80695F08\n.long 0x2C030000\n.long 0x41820010\n.long 0x4BFFC6AD\n.long 0x2C030000\n.long 0x40820010\n.long 0x801F00CC\n.long 0x2C000000\n.long 0x41820008\n.long 0x3BC00001\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
