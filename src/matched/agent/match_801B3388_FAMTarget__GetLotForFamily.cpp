// 0x801B3388 (68 bytes)
// FAMTarget::GetLotForFamily(Family *)

class FAMTarget { public: void GetLotForFamily(Family *); };

__attribute__((naked))
void FAMTarget::GetLotForFamily(Family *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x7C842379\n.long 0x41820020\n.long 0x81240000\n.long 0xA86900A8\n.long 0x800900AC\n.long 0x7C641A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
