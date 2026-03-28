// 0x800A7C60 (68 bytes)
// QuickStringSet::LoadFromDataID(ObjectDataID &)

class QuickStringSet { public: void LoadFromDataID(ObjectDataID &); };

__attribute__((naked))
void QuickStringSet::LoadFromDataID(ObjectDataID &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0xA8A40004\n.long 0xA80900E8\n.long 0x812900EC\n.long 0x7C630214\n.long 0x80840000\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x20030000\n.long 0x7C601914\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
