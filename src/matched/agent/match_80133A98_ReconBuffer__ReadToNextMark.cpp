// 0x80133A98 (76 bytes)
// ReconBuffer::ReadToNextMark(void)

class ReconBuffer { public: void ReadToNextMark(void); };

__attribute__((naked))
void ReconBuffer::ReadToNextMark(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x801F0018\n.long 0x2C000000\n.long 0x41820008\n.long 0x4BFFF80D\n.long 0x801F000C\n.long 0x2C000000\n.long 0x4082000C\n.long 0x801F002C\n.long 0x901F0008\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
