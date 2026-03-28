// 0x8012C8EC (12 bytes)
// cXPersonImpl::IsGreen(void)
// lhz r3, 156(r3); rlwinm r3, r3, 31, 31, 31; blr
class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int IsGreen();
};

int cXPersonImpl::IsGreen() {
    return (m_flags >> 1) & 1;
}
