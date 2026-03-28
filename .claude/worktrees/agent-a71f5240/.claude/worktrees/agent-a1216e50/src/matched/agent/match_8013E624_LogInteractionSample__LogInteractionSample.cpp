// 0x8013E624 (72 bytes)
// LogInteractionSample::LogInteractionSample(void)

class LogInteractionSample { public: void LogInteractionSample(void); };

__attribute__((naked))
void LogInteractionSample::LogInteractionSample(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x38800000\n.long 0x4BFFFE35\n.long 0x38000000\n.long 0x7FC3F378\n.long 0x901E0034\n.long 0x901E0028\n.long 0x901E002C\n.long 0x901E0030\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
