// 0x80096568 (64 bytes)
// StateMachineStatus::UpdateCurState(float)

class StateMachineStatus { public: void UpdateCurState(float); };

__attribute__((naked))
void StateMachineStatus::UpdateCurState(float) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81630000\n.long 0x2C0B0000\n.long 0x4182001C\n.long 0x812B0018\n.long 0xA8690028\n.long 0x8009002C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
