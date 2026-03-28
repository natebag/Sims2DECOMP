// 0x80196A54 (100 bytes)
// CASBodyTarget::SetVariableSubnav(int, int)

class CASBodyTarget { public: void SetVariableSubnav(int, int); };

__attribute__((naked))
void CASBodyTarget::SetVariableSubnav(int, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7CA52B79\n.long 0x41820044\n.long 0x2C040001\n.long 0x41820028\n.long 0x41810010\n.long 0x2C040000\n.long 0x41820028\n.long 0x4800002C\n.long 0x2C040004\n.long 0x40820024\n.long 0x7CA42B78\n.long 0x4800021D\n.long 0x48000018\n.long 0x7CA42B78\n.long 0x480002DD\n.long 0x4800000C\n.long 0x7CA42B78\n.long 0x480003A5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
