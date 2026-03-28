// 0x800CDEE0 (80 bytes)
// NeighborhoodImpl::FindNeighborByType(ObjSelector *)

class NeighborhoodImpl { public: void FindNeighborByType(ObjSelector *); };

__attribute__((naked))
void NeighborhoodImpl::FindNeighborByType(ObjSelector *) {
    asm volatile(".long 0x80030078\n.long 0x39400000\n.long 0x81630074\n.long 0x7C0B0000\n.long 0x41820038\n.long 0x7C080378\n.long 0x812B0000\n.long 0x2C090000\n.long 0x4182001C\n.long 0x8009000C\n.long 0x7C002000\n.long 0x40820010\n.long 0x2C0A0000\n.long 0x40820008\n.long 0x7D2A4B78\n.long 0x396B0004\n.long 0x7C0B4000\n.long 0x4082FFD4\n.long 0x7D435378\n.long 0x4E800020");
}
