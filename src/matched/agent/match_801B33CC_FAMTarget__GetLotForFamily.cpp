// 0x801B33CC (64 bytes)
// FAMTarget::GetLotForFamily(int)

class FAMTarget { public: void GetLotForFamily(int); };

__attribute__((naked))
void FAMTarget::GetLotForFamily(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C7F1B78\n.long 0x4BFFD93D\n.long 0x7C641B79\n.long 0x38600000\n.long 0x4182000C\n.long 0x7FE3FB78\n.long 0x4BFFFF95\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
