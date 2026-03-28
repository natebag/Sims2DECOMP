// 0x800968A0 (100 bytes)
// StateMachineManager::DrawTopmostMachine(ERC *)

class StateMachineManager { public: void DrawTopmostMachine(ERC *); };

__attribute__((naked))
void StateMachineManager::DrawTopmostMachine(ERC *) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0x7C9D2378\n.long 0x83FE0000\n.long 0x48000028\n.long 0x817F0000\n.long 0x7FA4EB78\n.long 0x3BFF0004\n.long 0x812B0018\n.long 0x8009003C\n.long 0xA8690038\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x801E0004\n.long 0x7C1F0000\n.long 0x4082FFD4\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
