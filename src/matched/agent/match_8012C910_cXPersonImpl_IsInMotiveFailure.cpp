// 0x8012C910 (12 bytes)
// cXPersonImpl::IsInMotiveFailure(void)
// lhz r3, 156(r3); rlwinm r3, r3, 28, 31, 31; blr
class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int IsInMotiveFailure();
};

int cXPersonImpl::IsInMotiveFailure() {
    return (m_flags >> 4) & 1;
}
