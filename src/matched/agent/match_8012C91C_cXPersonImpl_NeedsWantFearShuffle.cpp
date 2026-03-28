// 0x8012C91C (12 bytes)
// cXPersonImpl::NeedsWantFearShuffle(void)
// lhz r3, 156(r3); rlwinm r3, r3, 27, 31, 31; blr
class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int NeedsWantFearShuffle();
};

int cXPersonImpl::NeedsWantFearShuffle() {
    return (m_flags >> 5) & 1;
}
