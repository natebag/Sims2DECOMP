// 0x80184520 (108 bytes)
// ActionMenu::GetPlayerSim(void) const

class ActionMenu { public: void GetPlayerSim(void) const; };

__attribute__((naked))
void ActionMenu::GetPlayerSim(void) const {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x800300A8\n.long 0x3D208047\n.long 0x39295DCC\n.long 0x5400103A\n.long 0x392900BC\n.long 0x7FE9002E\n.long 0x2C1F0000\n.long 0x41820028\n.long 0x813F0004\n.long 0xA8690308\n.long 0x8009030C\n.long 0x7C7F1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x2C030000\n.long 0x40820008\n.long 0x3BE00000\n.long 0x7FE3FB78\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
