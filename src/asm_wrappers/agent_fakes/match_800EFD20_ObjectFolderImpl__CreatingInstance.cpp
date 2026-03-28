// 0x800EFD20 (112 bytes)
// ObjectFolderImpl::CreatingInstance(ObjSelector *)

class ObjectFolderImpl { public: void CreatingInstance(ObjSelector *); };

__attribute__((naked))
void ObjectFolderImpl::CreatingInstance(ObjSelector *) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0x93E1000C\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C6B1B78\n.long 0x801F00A0\n.long 0x2C000001\n.long 0x41820030\n.long 0x813F0038\n.long 0x800900C0\n.long 0x2C000000\n.long 0x41820020\n.long 0x812B0000\n.long 0x38A00001\n.long 0xA8690200\n.long 0x80090204\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x813F0068\n.long 0x39290001\n.long 0x913F0068\n.long 0x80010014\n.long 0x7C0803A6\n.long 0x83E1000C\n.long 0x38210010\n.long 0x4E800020");
}
