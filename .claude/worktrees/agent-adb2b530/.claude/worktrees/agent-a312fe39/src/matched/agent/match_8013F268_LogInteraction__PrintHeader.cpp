// 0x8013F268 (64 bytes)
// LogInteraction::PrintHeader(void)

class LogInteraction { public: void PrintHeader(void); };

__attribute__((naked))
void LogInteraction::PrintHeader(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x3C80803E\n.long 0x386D9FF4\n.long 0x3884D524\n.long 0x4BF65F09\n.long 0x3C80803E\n.long 0x386D9FF4\n.long 0x3884D52C\n.long 0x4BF65EF9\n.long 0x4BFFF5E5\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
