// 0x80005F84 (80 bytes)
// PlayerCheats::IsSingleButton(unsigned short)

class PlayerCheats { public: void IsSingleButton(unsigned short); };

__attribute__((naked))
void PlayerCheats::IsSingleButton(unsigned short) {
    asm volatile(".long 0x38600000\n.long 0x39200000\n.long 0x70800001\n.long 0x41820018\n.long 0x2C030000\n.long 0x38600001\n.long 0x4182000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x39290001\n.long 0x2C09000F\n.long 0x4D810020\n.long 0x7C804E30\n.long 0x700B0001\n.long 0x4182FFEC\n.long 0x2C030000\n.long 0x38600001\n.long 0x4182FFE0\n.long 0x38600000\n.long 0x4E800020");
}
