// 0x803056BC (68 bytes)
// EController::GetFilterIndex(unsigned int)

class EController { public: void GetFilterIndex(unsigned int); };

__attribute__((naked))
void EController::GetFilterIndex(unsigned int) {
    asm volatile(".long 0x7C6B1B78\n.long 0x7C842379\n.long 0x41820034\n.long 0x806B0008\n.long 0x2C030000\n.long 0x41800028\n.long 0x1D23000C\n.long 0x3929000C\n.long 0x7D295A14\n.long 0x80090000\n.long 0x3929FFF4\n.long 0x7C002000\n.long 0x4D820020\n.long 0x3463FFFF\n.long 0x4080FFEC\n.long 0x3860FFFF\n.long 0x4E800020");
}
