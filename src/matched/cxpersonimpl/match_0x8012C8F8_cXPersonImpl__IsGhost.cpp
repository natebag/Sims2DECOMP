// 0x8012C8F8 cXPersonImpl::IsGhost (12B)

struct cXPerson_IsGhost {
    char pad[0x9C];
    unsigned short m_flags;
    int IsGhost();
};

int cXPerson_IsGhost::IsGhost() {
    return (m_flags >> 2) & 1;
}
