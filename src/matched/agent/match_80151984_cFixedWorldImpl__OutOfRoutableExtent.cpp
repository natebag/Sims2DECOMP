// 0x80151984 (80 bytes)
// cFixedWorldImpl::OutOfRoutableExtent(CTilePt &) const

class cFixedWorldImpl { public: void OutOfRoutableExtent(CTilePt &) const; };

__attribute__((naked))
void cFixedWorldImpl::OutOfRoutableExtent(CTilePt &) const {
    asm volatile(".long 0x89240000\n.long 0x39600000\n.long 0x8003001C\n.long 0x7D290774\n.long 0x7C090000\n.long 0x41800030\n.long 0x80030020\n.long 0x7C090000\n.long 0x41810024\n.long 0x88040001\n.long 0x81230024\n.long 0x7C040774\n.long 0x7C044800\n.long 0x41800010\n.long 0x80030028\n.long 0x7C040000\n.long 0x40810008\n.long 0x39600001\n.long 0x7D635B78\n.long 0x4E800020");
}
