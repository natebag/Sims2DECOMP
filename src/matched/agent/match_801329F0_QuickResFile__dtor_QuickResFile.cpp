// 0x801329F0 (100 bytes)
// QuickResFile::~QuickResFile(void)

class QuickResFile { public: void ~QuickResFile(void); };

__attribute__((naked))
void QuickResFile::~QuickResFile(void) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x3D208046\n.long 0x7C7E1B78\n.long 0x816DABFC\n.long 0x39294180\n.long 0x913E000C\n.long 0x7C9D2378\n.long 0x7FC4F378\n.long 0x812B0000\n.long 0xA8690110\n.long 0x80090114\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x7FC3F378\n.long 0x7FA4EB78\n.long 0x48002B9D\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
