// 0x801BC284 (112 bytes)
// INGTarget::update_mix_ing_name(unsigned int)

class INGTarget { public: void update_mix_ing_name(unsigned int); };

__attribute__((naked))
void INGTarget::update_mix_ing_name(unsigned int) {
    asm volatile(".long 0x9421FFD8\n.long 0x7C0802A6\n.long 0x9001002C\n.long 0x7C852378\n.long 0x28050003\n.long 0x41810048\n.long 0x3C80803F\n.long 0x38A50001\n.long 0x3884DDA0\n.long 0x38610008\n.long 0x4CC63182\n.long 0x481225D9\n.long 0x806D9DD0\n.long 0x3C80803F\n.long 0x388419D8\n.long 0x38A00000\n.long 0x38C00000\n.long 0x38E00001\n.long 0x39010008\n.long 0x4CC63182\n.long 0x4BE540C1\n.long 0x38600001\n.long 0x48000008\n.long 0x38600000\n.long 0x8001002C\n.long 0x7C0803A6\n.long 0x38210028\n.long 0x4E800020");
}
