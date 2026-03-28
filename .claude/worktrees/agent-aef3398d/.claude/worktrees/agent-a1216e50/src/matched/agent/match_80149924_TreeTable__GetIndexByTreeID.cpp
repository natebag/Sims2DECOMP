// 0x80149924 (92 bytes)
// TreeTable::GetIndexByTreeID(short, short) const

class TreeTable { public: void GetIndexByTreeID(short, short) const; };

__attribute__((naked))
void TreeTable::GetIndexByTreeID(short, short) const {
    asm volatile(".long 0x81230000\n.long 0x39000000\n.long 0x2C090000\n.long 0x41820008\n.long 0x8109FFFC\n.long 0x38600000\n.long 0x7C034000\n.long 0x40800038\n.long 0x7D2A4B78\n.long 0x1D230024\n.long 0x7C0A4AAE\n.long 0x7D6A4A14\n.long 0x7C002000\n.long 0x40820010\n.long 0xA80B0002\n.long 0x7C002800\n.long 0x4D820020\n.long 0x38030001\n.long 0x7C030734\n.long 0x7C034000\n.long 0x4180FFD4\n.long 0x3860FFFF\n.long 0x4E800020");
}
