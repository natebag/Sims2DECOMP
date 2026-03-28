// 0x8012C8E0 (12 bytes)
// cXPersonImpl::IsInvisible(void)
// lhz r3, 156(r3); rlwinm r3, r3, 0, 31, 31; blr
class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int IsInvisible();
};

int cXPersonImpl::IsInvisible() {
    return m_flags & 1;
}
