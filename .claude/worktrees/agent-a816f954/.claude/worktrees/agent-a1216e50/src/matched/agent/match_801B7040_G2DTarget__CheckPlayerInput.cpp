// 0x801B7040 (76 bytes)
// G2DTarget::CheckPlayerInput(char *)

class G2DTarget { public: void CheckPlayerInput(char *); };

__attribute__((naked))
void G2DTarget::CheckPlayerInput(char *) {
    asm volatile(".long 0x800300A4\n.long 0x2C000000\n.long 0x4082000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x88840000\n.long 0x3804FFD0\n.long 0x28000001\n.long 0x4181FFEC\n.long 0x7C890774\n.long 0x8063009C\n.long 0x3929FFD0\n.long 0x7C091800\n.long 0x41820010\n.long 0x2C030002\n.long 0x38600000\n.long 0x4C820020\n.long 0x38600001\n.long 0x4E800020");
}
