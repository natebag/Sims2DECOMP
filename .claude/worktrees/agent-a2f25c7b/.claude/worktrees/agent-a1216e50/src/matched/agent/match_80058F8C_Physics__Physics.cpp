// 0x80058F8C (72 bytes)
// Physics::Physics(void)

class Physics { public: void Physics(void); };

__attribute__((naked))
void Physics::Physics(void) {
    asm volatile(".long 0x3D60803D\n.long 0x7C691B78\n.long 0xC00B3E08\n.long 0x3949000C\n.long 0x39690018\n.long 0xD0090008\n.long 0xD0090004\n.long 0xD0090000\n.long 0xD00A0004\n.long 0xD00A0008\n.long 0xD009000C\n.long 0xD00B0004\n.long 0xD00B0008\n.long 0xD009002C\n.long 0xD0090018\n.long 0xD0090024\n.long 0xD0090028\n.long 0x4E800020");
}
