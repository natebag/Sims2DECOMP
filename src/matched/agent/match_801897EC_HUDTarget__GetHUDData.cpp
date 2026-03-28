// 0x801897EC (120 bytes)
// HUDTarget::GetHUDData(short, short &)

class HUDTarget { public: void GetHUDData(short, short &); };

__attribute__((naked))
void HUDTarget::GetHUDData(short, short &) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7CBF2B78\n.long 0x2C040005\n.long 0x4082001C\n.long 0x800300A0\n.long 0x2C000000\n.long 0x41820010\n.long 0x4BFFFD99\n.long 0xB07F0000\n.long 0x48000030\n.long 0x5480043E\n.long 0x28000005\n.long 0x4081000C\n.long 0x38600000\n.long 0x48000020\n.long 0x80030104\n.long 0x396300A4\n.long 0x1C000006\n.long 0x7C040214\n.long 0x7D2B00AE\n.long 0xB13F0000\n.long 0x38600001\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
