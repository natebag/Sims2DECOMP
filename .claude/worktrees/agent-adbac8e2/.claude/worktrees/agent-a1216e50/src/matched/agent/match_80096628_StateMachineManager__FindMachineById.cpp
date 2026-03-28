// 0x80096628 (64 bytes)
// StateMachineManager::FindMachineById(int)

class StateMachineManager { public: void FindMachineById(int); };

__attribute__((naked))
void StateMachineManager::FindMachineById(int) {
    asm volatile(".long 0x80030004\n.long 0x80630000\n.long 0x7C030000\n.long 0x4182002C\n.long 0x7C0B0378\n.long 0x81230000\n.long 0x8009001C\n.long 0x7C002000\n.long 0x4082000C\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x38630004\n.long 0x7C035800\n.long 0x4082FFE0\n.long 0x38600000\n.long 0x4E800020");
}
