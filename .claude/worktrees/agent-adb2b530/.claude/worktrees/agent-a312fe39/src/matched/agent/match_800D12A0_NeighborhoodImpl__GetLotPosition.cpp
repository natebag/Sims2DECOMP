// 0x800D12A0 (64 bytes)
// NeighborhoodImpl::GetLotPosition(int, int *, int *)

class NeighborhoodImpl { public: void GetLotPosition(int, int *, int *); };

__attribute__((naked))
void NeighborhoodImpl::GetLotPosition(int, int *, int *) {
    asm volatile(".long 0x3804FFFF\n.long 0x28000008\n.long 0x40810014\n.long 0x38000000\n.long 0x90060000\n.long 0x90050000\n.long 0x4E800020\n.long 0x3D208048\n.long 0x548A1838\n.long 0x392962DC\n.long 0x7D69502E\n.long 0x39290004\n.long 0x91650000\n.long 0x7C09502E\n.long 0x90060000\n.long 0x4E800020");
}
