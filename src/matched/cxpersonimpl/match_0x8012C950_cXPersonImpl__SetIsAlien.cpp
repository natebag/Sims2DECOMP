// 0x8012C950 cXPersonImpl::SetIsAlien (40B)

struct cXPerson_SIA {
    char pad[0x9C];
    unsigned short m_flags;
    void SetIsAlien(int alien);
};

void cXPerson_SIA::SetIsAlien(int alien) {
    if (alien != 0) {
        m_flags = m_flags | 0x0008;
    } else {
        int f = m_flags;
        m_flags = f & ~8;
    }
}
