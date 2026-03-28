// 0x8004516C (100 bytes)
// ObjectSaveIDTable::findHRSel(short) const

class ObjectSaveIDTable { public: void findHRSel(short) const; };

__attribute__((naked))
void ObjectSaveIDTable::findHRSel(short) const {
    asm volatile(".long 0x81230000\n.long 0x39400000\n.long 0x38600000\n.long 0x3D290001\n.long 0x80096004\n.long 0x38E96004\n.long 0x39098004\n.long 0x7C030000\n.long 0x4C800020\n.long 0xA808000C\n.long 0x7C002000\n.long 0x4082000C\n.long 0x7D034378\n.long 0x4E800020\n.long 0x80070000\n.long 0x394A0001\n.long 0x7C0A0000\n.long 0x4C800020\n.long 0x1C0A001C\n.long 0x7D604214\n.long 0xA92B000C\n.long 0x7C092000\n.long 0x4082FFE0\n.long 0x7D635B78\n.long 0x4E800020");
}
