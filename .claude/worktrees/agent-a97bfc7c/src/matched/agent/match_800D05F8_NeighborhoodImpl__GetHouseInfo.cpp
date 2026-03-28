// 0x800D05F8 (72 bytes)
// NeighborhoodImpl::GetHouseInfo(NghResFile *, HouseInfo *)

class NeighborhoodImpl { public: void GetHouseInfo(NghResFile *, HouseInfo *); };

__attribute__((naked))
void NeighborhoodImpl::GetHouseInfo(NghResFile *, HouseInfo *) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0x7CA72B78\n.long 0x7CE83B78\n.long 0x38A7000C\n.long 0xA8090060\n.long 0x38C70004\n.long 0x81290064\n.long 0x38E70008\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
