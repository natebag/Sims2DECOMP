// 0x800B70B8 (68 bytes)
// FloatConstantsQuickData::LoadFromDataID(ObjectDataID &)

class FloatConstantsQuickData { public: void LoadFromDataID(ObjectDataID &); };

__attribute__((naked))
void FloatConstantsQuickData::LoadFromDataID(ObjectDataID &) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0xA8A40004\n.long 0xA8090078\n.long 0x8129007C\n.long 0x7C630214\n.long 0x80840000\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x20030000\n.long 0x7C601914\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
