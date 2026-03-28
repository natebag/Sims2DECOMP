// 0x801D1994 (116 bytes)
// PZ1Target::~PZ1Target(void)

class PZ1Target { public: void ~PZ1Target(void); };

__attribute__((naked))
void PZ1Target::~PZ1Target(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3D208046\n.long 0x800300BC\n.long 0x392971E8\n.long 0x91230080\n.long 0x2C00001E\n.long 0x4182002C\n.long 0x41810010\n.long 0x2C00001A\n.long 0x41820014\n.long 0x48000030\n.long 0x2C000027\n.long 0x41820020\n.long 0x48000024\n.long 0x8003008C\n.long 0x900D8BF0\n.long 0x48000018\n.long 0x8003008C\n.long 0x900D8BF4\n.long 0x4800000C\n.long 0x8003008C\n.long 0x900D8BF8\n.long 0x4BFFE79D\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
