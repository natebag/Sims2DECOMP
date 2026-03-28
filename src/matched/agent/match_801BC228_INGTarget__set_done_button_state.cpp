// 0x801BC228 (92 bytes)
// INGTarget::set_done_button_state(bool)

class INGTarget { public: void set_done_button_state(bool); };

__attribute__((naked))
void INGTarget::set_done_button_state(bool) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x2C040000\n.long 0x806D9DD0\n.long 0x41820010\n.long 0x3D20803F\n.long 0x3909EB58\n.long 0x4800000C\n.long 0x3D20803F\n.long 0x3909EB5C\n.long 0x3C80803F\n.long 0x38A00000\n.long 0x388419C4\n.long 0x38C00000\n.long 0x38E00001\n.long 0x4CC63182\n.long 0x4BE54129\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
