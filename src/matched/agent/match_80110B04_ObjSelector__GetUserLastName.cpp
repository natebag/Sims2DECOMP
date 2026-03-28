// 0x80110B04 (84 bytes)
// ObjSelector::GetUserLastName(void)

class ObjSelector { public: void GetUserLastName(void); };

__attribute__((naked))
void ObjSelector::GetUserLastName(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80630088\n.long 0x2C030000\n.long 0x40820030\n.long 0x800DA1A8\n.long 0x2C000000\n.long 0x40820020\n.long 0x386DA1A4\n.long 0x4BF90FA9\n.long 0x38000001\n.long 0x3C608011\n.long 0x900DA1A8\n.long 0x38630ADC\n.long 0x48131CC1\n.long 0x386DA1A4\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
