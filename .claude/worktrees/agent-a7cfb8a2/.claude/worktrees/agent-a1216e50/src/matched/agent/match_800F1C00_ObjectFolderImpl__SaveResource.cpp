// 0x800F1C00 (68 bytes)
// ObjectFolderImpl::SaveResource(unsigned int, short, StringBuffer &, ObjectDataInterface &)

class ObjectFolderImpl { public: void SaveResource(unsigned int, short, StringBuffer &, ObjectDataInterface &); };

__attribute__((naked))
void ObjectFolderImpl::SaveResource(unsigned int, short, StringBuffer &, ObjectDataInterface &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x2C04FFFF\n.long 0x41820020\n.long 0x81270000\n.long 0xA8690040\n.long 0x80090044\n.long 0x7C671A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x48000008\n.long 0x38600000\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
