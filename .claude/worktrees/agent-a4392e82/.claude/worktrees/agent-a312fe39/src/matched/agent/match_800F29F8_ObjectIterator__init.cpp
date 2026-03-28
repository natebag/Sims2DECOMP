// 0x800F29F8 (116 bytes)
// ObjectIterator::init(CTilePt &, ObjectIterator::IterateType)

class ObjectIterator { public: void init(CTilePt &, ObjectIterator::IterateType); };

__attribute__((naked))
void ObjectIterator::init(CTilePt &, ObjectIterator::IterateType) {
    asm volatile(".long 0x9421FFE8\n.long 0x7C0802A6\n.long 0xBFA1000C\n.long 0x9001001C\n.long 0x816DAC14\n.long 0x7C7E1B78\n.long 0x7CBD2B78\n.long 0x812B0000\n.long 0x80090254\n.long 0xA8690250\n.long 0x7C0803A6\n.long 0x7C6B1A14\n.long 0x4E800021\n.long 0x816DAC14\n.long 0x7C641B78\n.long 0x812B0000\n.long 0xA8690090\n.long 0x80090094\n.long 0x7C6B1A14\n.long 0x7C0803A6\n.long 0x4E800021\n.long 0x93BE0008\n.long 0x907E0004\n.long 0x907E0000\n.long 0x8001001C\n.long 0x7C0803A6\n.long 0xBBA1000C\n.long 0x38210018\n.long 0x4E800020");
}
