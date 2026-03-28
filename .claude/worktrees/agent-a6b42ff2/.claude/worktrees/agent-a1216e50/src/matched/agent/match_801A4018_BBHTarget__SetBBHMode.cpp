// 0x801A4018 (88 bytes)
// BBHTarget::SetBBHMode(BBHTarget::eBBHMode)

class BBHTarget { public: void SetBBHMode(BBHTarget::eBBHMode); };

__attribute__((naked))
void BBHTarget::SetBBHMode(BBHTarget::eBBHMode) {
    asm volatile(".long 0x9421FFE0\n.long 0x7C0802A6\n.long 0x90010024\n.long 0x800300A0\n.long 0x7C002000\n.long 0x41820034\n.long 0x908300A0\n.long 0x38610008\n.long 0x4BFD91FD\n.long 0x3C80803F\n.long 0x38610008\n.long 0x3884DE44\n.long 0x38A00010\n.long 0x38C00000\n.long 0x4BFD9C5D\n.long 0x38610008\n.long 0x38800002\n.long 0x4BFD91F9\n.long 0x80010024\n.long 0x7C0803A6\n.long 0x38210020\n.long 0x4E800020");
}
