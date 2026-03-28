// 0x800692E4 (112 bytes)
// SAnimator2::EndAutoRun(void)

class SAnimator2 { public: void EndAutoRun(void); };

__attribute__((naked))
void SAnimator2::EndAutoRun(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0600\n.long 0x2C000001\n.long 0x4182000C\n.long 0x38600000\n.long 0x48000038\n.long 0x815F0004\n.long 0x38800011\n.long 0x38A00000\n.long 0x816A0000\n.long 0x812B0004\n.long 0x800901EC\n.long 0xA86901E8\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0x38600001\n.long 0x901F0600\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
