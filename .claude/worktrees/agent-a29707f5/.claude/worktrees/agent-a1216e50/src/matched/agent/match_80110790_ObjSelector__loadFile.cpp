// 0x80110790 (76 bytes)
// ObjSelector::loadFile(void)

class ObjSelector { public: void loadFile(void); };

__attribute__((naked))
void ObjSelector::loadFile(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x817E0050\n.long 0x7FC4F378\n.long 0x812B0000\n.long 0xA8690148\n.long 0x8009014C\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x807E0000\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
