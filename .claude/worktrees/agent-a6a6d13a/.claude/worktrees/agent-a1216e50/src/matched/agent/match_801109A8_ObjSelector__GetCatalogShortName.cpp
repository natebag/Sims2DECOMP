// 0x801109A8 (92 bytes)
// ObjSelector::GetCatalogShortName(void)

class ObjSelector { public: void GetCatalogShortName(void); };

__attribute__((naked))
void ObjSelector::GetCatalogShortName(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x7C832378\n.long 0x4BFFFE81\n.long 0x48000AC9\n.long 0x7C641B78\n.long 0x81240000\n.long 0x7FC3F378\n.long 0xA8090028\n.long 0x8129002C\n.long 0x7C840214\n.long 0x7D2803A6\n.long 0x4CC63182\n.long 0x4E800021\n.long 0x7FC3F378\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
