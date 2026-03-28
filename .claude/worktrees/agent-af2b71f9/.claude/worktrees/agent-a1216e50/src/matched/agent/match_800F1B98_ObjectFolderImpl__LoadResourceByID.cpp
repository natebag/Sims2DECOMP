// 0x800F1B98 (104 bytes)
// ObjectFolderImpl::LoadResourceByID(unsigned int, short, ObjectDataInterface &, unsigned int)

class ObjectFolderImpl { public: void LoadResourceByID(unsigned int, short, ObjectDataInterface &, unsigned int); };

__attribute__((naked))
void ObjectFolderImpl::LoadResourceByID(unsigned int, short, ObjectDataInterface &, unsigned int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x2C04FFFF\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000040\n.long 0x2C070000\n.long 0x40820020\n.long 0x81260000\n.long 0xA8690030\n.long 0x80090034\n.long 0x7C661A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x4800001C\n.long 0x81260000\n.long 0xA8690038\n.long 0x8009003C\n.long 0x7C661A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
