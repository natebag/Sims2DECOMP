// 0x801B0DB4 (68 bytes)
// FAMTarget::GetNumberOfFamilyMembers(Family *)

class FAMTarget { public: void GetNumberOfFamilyMembers(Family *); };

__attribute__((naked))
void FAMTarget::GetNumberOfFamilyMembers(Family *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C842379\n.long 0x41820020\n.long 0x81240000\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C641A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
