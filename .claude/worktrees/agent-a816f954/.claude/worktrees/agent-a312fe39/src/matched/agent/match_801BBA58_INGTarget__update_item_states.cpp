// 0x801BBA58 (96 bytes)
// INGTarget::update_item_states(void)

class INGTarget { public: void update_item_states(void); };

__attribute__((naked))
void INGTarget::update_item_states(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7D1B78\n.long 0x3BC00000\n.long 0x3BFD01B0\n.long 0x809F0000\n.long 0x7FA3EB78\n.long 0x3BFF0004\n.long 0x48000279\n.long 0x7C651B78\n.long 0x7FC4F378\n.long 0x7FA3EB78\n.long 0x3BDE0001\n.long 0x480006FD\n.long 0x281E000B\n.long 0x4081FFD8\n.long 0x38600001\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
