// 0x801B5A50 (92 bytes)
// G2DTarget::PushAptButtonFiltersForPlayer(int)

class G2DTarget { public: void PushAptButtonFiltersForPlayer(int); };

__attribute__((naked))
void G2DTarget::PushAptButtonFiltersForPlayer(int) {
    asm volatile(".long 0x9421FFF0\n.long 0x7C0802A6\n.long 0xBFC10008\n.long 0x90010014\n.long 0x7C9F2378\n.long 0x7C7E1B78\n.long 0x2C1F0001\n.long 0x40820014\n.long 0x3D208047\n.long 0x80095C70\n.long 0x2C000000\n.long 0x4182001C\n.long 0x809E007C\n.long 0x7FE3FB78\n.long 0x4BFC20BD\n.long 0x57E0103A\n.long 0x393E0120\n.long 0x7C69012E\n.long 0x80010014\n.long 0x7C0803A6\n.long 0xBBC10008\n.long 0x38210010\n.long 0x4E800020");
}
