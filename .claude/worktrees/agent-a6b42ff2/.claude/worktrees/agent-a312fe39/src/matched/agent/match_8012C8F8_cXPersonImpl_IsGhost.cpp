// 0x8012C8F8 (12 bytes)
// cXPersonImpl::IsGhost(void)
// lhz r3, 156(r3); rlwinm r3, r3, 30, 31, 31; blr
class cXPerson;

class cXPersonImpl {
public:
    char m_pad[156];
    unsigned short m_flags;
    int IsGhost();
};

int cXPersonImpl::IsGhost() {
    return (m_flags >> 2) & 1;
}
