// 0x8012C904 (12 bytes)
// cXPersonImpl::IsAlien(void)
// lhz r3, 156(r3); rlwinm r3, r3, 29, 31, 31; blr
class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int IsAlien();
};

int cXPersonImpl::IsAlien() {
    return (m_flags >> 3) & 1;
}
