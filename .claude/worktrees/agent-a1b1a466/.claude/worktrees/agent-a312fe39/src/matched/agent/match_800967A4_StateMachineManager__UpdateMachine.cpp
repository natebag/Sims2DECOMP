// 0x800967A4 (108 bytes)
// StateMachineManager::UpdateMachine(float)

class StateMachineManager { public: void UpdateMachine(float); };

__attribute__((naked))
void StateMachineManager::UpdateMachine(float) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xDBE10010\n.long 0xBFC10008\n.long 0x9001001C\n.long 0x7C7E1B78\n.long 0xFFE00890\n.long 0x83FE0000\n.long 0x48000028\n.long 0x817F0000\n.long 0xFC20F890\n.long 0x3BFF0004\n.long 0x812B0018\n.long 0x8009002C\n.long 0xA8690028\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x801E0004\n.long 0x7C1F0000\n.long 0x4082FFD4\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0xCBE10010\n.long 0x38210018\n.long 0x4E800020");
}
