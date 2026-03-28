// 0x801116E8 (92 bytes)
// ObjSelector::ResetAnimTables(void)

class ObjSelector { public: void ResetAnimTables(void); };

__attribute__((naked))
void ObjSelector::ResetAnimTables(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBF810008\n.long 0x9001001C\n.long 0x3BA30040\n.long 0x3BC00000\n.long 0x3B800000\n.long 0x57DF103A\n.long 0x7C1DF82E\n.long 0x7C030378\n.long 0x2C000000\n.long 0x4182000C\n.long 0x4BF99395\n.long 0x7F9DF92E\n.long 0x381E0001\n.long 0x7C1E0734\n.long 0x2C1E0003\n.long 0x4081FFD8\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBB810008\n.long 0x38210018\n.long 0x4E800020");
}
