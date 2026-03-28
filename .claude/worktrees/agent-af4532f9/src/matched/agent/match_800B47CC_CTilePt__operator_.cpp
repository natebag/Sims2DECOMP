// 0x800B47CC (68 bytes)
// CTilePt::operator<(CTilePt &) const

class CTilePt { public: void operator<(CTilePt &) const; };

__attribute__((naked))
void CTilePt::operator<(CTilePt &) const {
    asm volatile(".long 0x89230000\n.long 0x39600000\n.long 0x88040000\n.long 0x7D290774\n.long 0x7C000774\n.long 0x7C090000\n.long 0x41800020\n.long 0x40820020\n.long 0x89230001\n.long 0x88040001\n.long 0x7D290774\n.long 0x7C000774\n.long 0x7C090000\n.long 0x40800008\n.long 0x39600001\n.long 0x7D635B78\n.long 0x4E800020");
}
