// 0x80142C40 (108 bytes)
// ObjectSlot::ObjectSlot(void)

class ObjectSlot { public: void ObjectSlot(void); };

__attribute__((naked))
void ObjectSlot::ObjectSlot(void) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C7E1B78\n.long 0x4BFFFD15\n.long 0x3D60803E\n.long 0x3D208046\n.long 0xC00BD6EC\n.long 0x39400000\n.long 0x39294A10\n.long 0x38000000\n.long 0x39600032\n.long 0x913E0000\n.long 0xD01E001C\n.long 0x7FC3F378\n.long 0xB01E0004\n.long 0x917E000C\n.long 0x915E0008\n.long 0xD01E0014\n.long 0xD01E0018\n.long 0x915E0010\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
