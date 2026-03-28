// 0x8004AFA8 (68 bytes)
// BBI::InventoryItems::GetNewItemIndex(void) const

class BBI { public: void InventoryItems::GetNewItemIndex(void) const; };

__attribute__((naked))
void BBI::InventoryItems::GetNewItemIndex(void) const {
    asm volatile(".long 0x39600000\n.long 0x3940FFFF\n.long 0x7C03582E\n.long 0x2C000000\n.long 0x4082000C\n.long 0x39400000\n.long 0x48000024\n.long 0x396B0001\n.long 0x2C0B0023\n.long 0x41810018\n.long 0x5560103A\n.long 0x7D23002E\n.long 0x2C090000\n.long 0x4082FFE8\n.long 0x7D6A5B78\n.long 0x7D435378\n.long 0x4E800020");
}
