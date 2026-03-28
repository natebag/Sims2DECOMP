// 0x8005A348 (116 bytes)
// PlumbBob::SetColor(EVec3 *)

class PlumbBob { public: void SetColor(EVec3 *); };

__attribute__((naked))
void PlumbBob::SetColor(EVec3 *) {
    asm volatile(".long 0x9421FFE8\n.long 0x81640000\n.long 0x39230040\n.long 0x80040008\n.long 0x3D008048\n.long 0x81440004\n.long 0x38E10008\n.long 0x91630040\n.long 0x38C30030\n.long 0x90090008\n.long 0x91490004\n.long 0xC16855C4\n.long 0xC0040000\n.long 0xC1A40008\n.long 0xC1840004\n.long 0xEC0002F2\n.long 0xD0010008\n.long 0xEDAD02F2\n.long 0xED8C02F2\n.long 0xD1A10010\n.long 0xD181000C\n.long 0x80010008\n.long 0x81270008\n.long 0x81670004\n.long 0x90030030\n.long 0x91260008\n.long 0x91660004\n.long 0x38210018\n.long 0x4E800020");
}
