// 0x801EB580 (100 bytes)
// GOLTarget::IsMapGoalUnlocked(int, int, int)

class GOLTarget { public: void IsMapGoalUnlocked(int, int, int); };

__attribute__((naked))
void GOLTarget::IsMapGoalUnlocked(int, int, int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x816DAC1C\n.long 0x38800001\n.long 0x812B0000\n.long 0x80090124\n.long 0xA8690120\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x81230000\n.long 0xA8090148\n.long 0x8129014C\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x38600000\n.long 0x41820008\n.long 0x38600001\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
