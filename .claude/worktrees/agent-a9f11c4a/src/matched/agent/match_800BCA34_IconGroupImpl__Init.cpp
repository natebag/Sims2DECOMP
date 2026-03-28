// 0x800BCA34 (88 bytes)
// IconGroupImpl::Init(int)

class IconGroupImpl { public: void Init(int); };

__attribute__((naked))
void IconGroupImpl::Init(int) {
    asm volatile(".long 0x3D208042\n.long 0x39400000\n.long 0x3929402C\n.long 0x7C09502E\n.long 0x7C002000\n.long 0x40820010\n.long 0x9123000C\n.long 0x90830004\n.long 0x4E800020\n.long 0x394A0001\n.long 0x2C0A000B\n.long 0x4D810020\n.long 0x3D208042\n.long 0x554B1838\n.long 0x3929402C\n.long 0x7C09582E\n.long 0x7C002000\n.long 0x4082FFE0\n.long 0x7C0B4A14\n.long 0x90830004\n.long 0x9003000C\n.long 0x4E800020");
}
