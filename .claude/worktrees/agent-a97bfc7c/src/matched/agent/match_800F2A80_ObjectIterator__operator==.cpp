// 0x800F2A80 (64 bytes)
// ObjectIterator::operator==(ObjectIterator &) const

class ObjectIterator { public: void operator==(ObjectIterator &) const; };

__attribute__((naked))
void ObjectIterator::operator==(ObjectIterator &) const {
    asm volatile(".long 0x7C6A1B78\n.long 0x81640004\n.long 0x800A0004\n.long 0x7C0B0000\n.long 0x40820028\n.long 0x2C0B0000\n.long 0x4082000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x81240000\n.long 0x38600001\n.long 0x800A0000\n.long 0x7C090000\n.long 0x4D820020\n.long 0x38600000\n.long 0x4E800020");
}
