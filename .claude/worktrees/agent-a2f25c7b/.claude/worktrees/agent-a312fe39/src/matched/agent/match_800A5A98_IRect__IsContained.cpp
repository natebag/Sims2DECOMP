// 0x800A5A98 (76 bytes)
// IRect::IsContained(IRect *) const

class IRect { public: void IsContained(IRect *) const; };

__attribute__((naked))
void IRect::IsContained(IRect *) const {
    asm volatile(".long 0x81230008\n.long 0x80040008\n.long 0x7C090000\n.long 0x41810038\n.long 0x81230000\n.long 0x80040000\n.long 0x7C090000\n.long 0x41800028\n.long 0x81230004\n.long 0x80040004\n.long 0x7C090000\n.long 0x41800018\n.long 0x8123000C\n.long 0x8004000C\n.long 0x38600001\n.long 0x7C090000\n.long 0x4C810020\n.long 0x38600000\n.long 0x4E800020");
}
