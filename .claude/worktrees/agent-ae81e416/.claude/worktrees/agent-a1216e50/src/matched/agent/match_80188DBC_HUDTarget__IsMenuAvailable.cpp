// 0x80188DBC (120 bytes)
// HUDTarget::IsMenuAvailable(int) const

class HUDTarget { public: void IsMenuAvailable(int) const; };

__attribute__((naked))
void HUDTarget::IsMenuAvailable(int) const {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x7C7F1B78\n.long 0x7C9E2378\n.long 0x57C0103A\n.long 0x393F00EC\n.long 0x7C69002E\n.long 0x3BA00000\n.long 0x4BFFCB19\n.long 0x70600002\n.long 0x40820030\n.long 0x1D3E00B4\n.long 0x7D29FA14\n.long 0x88090749\n.long 0x2C000001\n.long 0x4082001C\n.long 0x7FE3FB78\n.long 0x7FC4F378\n.long 0x4BFFF53D\n.long 0x2C030000\n.long 0x41820008\n.long 0x3BA00001\n.long 0x7FA3EB78\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
