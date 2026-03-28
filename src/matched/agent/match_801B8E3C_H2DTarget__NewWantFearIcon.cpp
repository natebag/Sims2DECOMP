// 0x801B8E3C (72 bytes)
// H2DTarget::NewWantFearIcon(int, int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *)

class H2DTarget { public: void NewWantFearIcon(int, int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *); };

__attribute__((naked))
void H2DTarget::NewWantFearIcon(int, int, unsigned int, unsigned int, WAFTarget::eWAFIconAnim, Neighbor *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x5484103A\n.long 0x386300AC\n.long 0x7C63202E\n.long 0x7CA42B78\n.long 0x7CC53378\n.long 0x2C030000\n.long 0x7CE63B78\n.long 0x7D074378\n.long 0x7D284B78\n.long 0x41820008\n.long 0x4802AA91\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
