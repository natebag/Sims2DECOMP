// 0x80090E20 (104 bytes)
// LoadingScreenStateMachine::FaderStart(float, bool)

class LoadingScreenStateMachine { public: void FaderStart(float, bool); };

__attribute__((naked))
void LoadingScreenStateMachine::FaderStart(float, bool) {
    asm volatile(".long 0x38000010\n.long 0x394300A8\n.long 0x900A000C\n.long 0x2C040000\n.long 0x41820034\n.long 0xD02A0008\n.long 0x3D20803E\n.long 0xD02300A8\n.long 0x3960FFF2\n.long 0xC00980C0\n.long 0x800A000C\n.long 0xEC000824\n.long 0x7C005838\n.long 0x60000002\n.long 0x900A000C\n.long 0xD00A0004\n.long 0x4E800020\n.long 0xD02A0008\n.long 0x3D20803E\n.long 0xD02300A8\n.long 0xC00980C0\n.long 0x800A000C\n.long 0xEC000824\n.long 0x540007F6\n.long 0x60000001\n.long 0x4BFFFFD4");
}
