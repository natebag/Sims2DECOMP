// 0x8012C928 cXPersonImpl::SetInvisible (40B)

struct cXPerson_SI {
    char pad[0x9C];
    unsigned short m_flags;
    void SetInvisible(int invisible);
};

void cXPerson_SI::SetInvisible(int invisible) {
    if (invisible != 0) {
        m_flags = m_flags | 0x0001;
    } else {
        int f = m_flags;
        m_flags = f & ~1;
    }
}
