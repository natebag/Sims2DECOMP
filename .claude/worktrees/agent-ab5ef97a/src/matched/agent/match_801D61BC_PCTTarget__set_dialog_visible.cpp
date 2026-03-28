// 0x801D61BC (92 bytes)
// PCTTarget::set_dialog_visible(bool)

class PCTTarget { public: void set_dialog_visible(bool); };

__attribute__((naked))
void PCTTarget::set_dialog_visible(bool) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x90010014\n.long 0x2C040000\n.long 0x41820010\n.long 0x3D20803F\n.long 0x3929EB58\n.long 0x4800000C\n.long 0x3D20803F\n.long 0x3929EB5C\n.long 0x3C60803F\n.long 0x91210008\n.long 0x38634350\n.long 0x38800000\n.long 0x38A00000\n.long 0x38C00001\n.long 0x38E10008\n.long 0x4BFA1B55\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x38210010\n.long 0x4E800020");
}
