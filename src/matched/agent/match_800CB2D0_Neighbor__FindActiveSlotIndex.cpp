// 0x800CB2D0 (92 bytes)
// Neighbor::FindActiveSlotIndex(WantFear::Bookmark &) const

class Neighbor { public: void FindActiveSlotIndex(WantFear::Bookmark &) const; };

__attribute__((naked))
void Neighbor::FindActiveSlotIndex(WantFear::Bookmark &) const {
    asm volatile(".long 0x80040004\n.long 0x39200001\n.long 0x2C000000\n.long 0x40820008\n.long 0x39200000\n.long 0x2C090000\n.long 0x40820014\n.long 0xA86DAD1A\n.long 0x4E800020\n.long 0x7D234B78\n.long 0x4E800020\n.long 0x38000007\n.long 0x38630198\n.long 0x7C0903A6\n.long 0x39200000\n.long 0x80030000\n.long 0x38630004\n.long 0x7C002000\n.long 0x4182FFDC\n.long 0x39290001\n.long 0x4200FFEC\n.long 0xA86DAD1A\n.long 0x4E800020");
}
