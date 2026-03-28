// 0x8012D160 (68 bytes)
// PlayerFamilyImpl::GetStatRef(int, short **)

class PlayerFamilyImpl { public: void GetStatRef(int, short **); };

__attribute__((naked))
void PlayerFamilyImpl::GetStatRef(int, short **) {
    asm volatile(".long 0x7C601B78\n.long 0x7CA52B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x28040018\n.long 0x4181001C\n.long 0x7D242214\n.long 0x38600001\n.long 0x39290CA8\n.long 0x7D204A14\n.long 0x91250000\n.long 0x4E800020\n.long 0x38000000\n.long 0x38600000\n.long 0x90050000\n.long 0x4E800020");
}
