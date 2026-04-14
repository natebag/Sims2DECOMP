// 0x8012C8EC cXPersonImpl::IsGreen (12B)

struct cXPerson_IsGreen {
    char pad[0x9C];
    unsigned short m_flags;
    int IsGreen();
};

int cXPerson_IsGreen::IsGreen() {
    return (m_flags >> 1) & 1;
}
