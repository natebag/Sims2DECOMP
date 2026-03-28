// 0x80090B5C (92 bytes)
// LoadingScreenStateMachine::DeleteLoadingScreen(void)

class LoadingScreenStateMachine { public: void DeleteLoadingScreen(void); };

__attribute__((naked))
void LoadingScreenStateMachine::DeleteLoadingScreen(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x817F0098\n.long 0x2C0B0000\n.long 0x4182002C\n.long 0x812B0390\n.long 0x38800003\n.long 0x8009000C\n.long 0xA8690008\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x38000000\n.long 0x901F00A0\n.long 0x901F0098\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
