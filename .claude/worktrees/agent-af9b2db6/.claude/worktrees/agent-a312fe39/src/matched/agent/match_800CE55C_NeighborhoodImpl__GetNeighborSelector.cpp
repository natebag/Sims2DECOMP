// 0x800CE55C (72 bytes)
// NeighborhoodImpl::GetNeighborSelector(int)

class NeighborhoodImpl { public: void GetNeighborSelector(int); };

__attribute__((naked))
void NeighborhoodImpl::GetNeighborSelector(int) {
    asm volatile(".long 0x9421FFF8\n.long 0x7C0802A6\n.long 0x9001000C\n.long 0x81230000\n.long 0xA80900B8\n.long 0x812900BC\n.long 0x7C630214\n.long 0x7D2803A6\n.long 0x4E800021\n.long 0x7C631B79\n.long 0x4082000C\n.long 0x38600000\n.long 0x48000008\n.long 0x8063000C\n.long 0x8001000C\n.long 0x7C0803A6\n.long 0x38210008\n.long 0x4E800020");
}
