// 0x801D49E0 (76 bytes)
// PCTTarget::get_cell_info_at_gridindex(unsigned int) const

class PCTTarget { public: void get_cell_info_at_gridindex(unsigned int) const; };

__attribute__((naked))
void PCTTarget::get_cell_info_at_gridindex(unsigned int) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFFFDD\n.long 0x801F00C0\n.long 0x7C030040\n.long 0x40800014\n.long 0x1C030018\n.long 0x807F00BC\n.long 0x7C630214\n.long 0x48000008\n.long 0x38600000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
