// 0x80110A2C (84 bytes)
// ObjSelector::GetUserName(void)

class ObjSelector { public: void GetUserName(void); };

__attribute__((naked))
void ObjSelector::GetUserName(void) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x80630084\n.long 0x2C030000\n.long 0x40820030\n.long 0x800DA1A0\n.long 0x2C000000\n.long 0x40820020\n.long 0x386DA19C\n.long 0x4BF91081\n.long 0x38000001\n.long 0x3C608011\n.long 0x900DA1A0\n.long 0x38630A04\n.long 0x48131D99\n.long 0x386DA19C\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
