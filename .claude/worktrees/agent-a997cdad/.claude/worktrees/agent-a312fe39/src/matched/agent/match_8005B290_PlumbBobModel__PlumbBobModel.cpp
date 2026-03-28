// 0x8005B290 (100 bytes)
// PlumbBobModel::PlumbBobModel(void)

class PlumbBobModel { public: void PlumbBobModel(void); };

__attribute__((naked))
void PlumbBobModel::PlumbBobModel(void) {
    asm volatile(".long 0x3D40803D\n.long 0x3D60803D\n.long 0xC00B4314\n.long 0x7C691B78\n.long 0xC1AA4310\n.long 0x3969000C\n.long 0xD0090008\n.long 0x3D408048\n.long 0xD1A90004\n.long 0x38000000\n.long 0xD1A90000\n.long 0xD00B0004\n.long 0xD00B0008\n.long 0xD009000C\n.long 0xC1AA55C0\n.long 0xD0090034\n.long 0xD1A90018\n.long 0x90090038\n.long 0xD009001C\n.long 0x90090020\n.long 0x90090024\n.long 0x90090028\n.long 0x9009002C\n.long 0xD0090030\n.long 0x4E800020");
}
