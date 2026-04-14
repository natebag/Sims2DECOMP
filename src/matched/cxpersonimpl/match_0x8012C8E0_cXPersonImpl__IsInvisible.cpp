// 0x8012C8E0 cXPersonImpl::IsInvisible (12B)

struct cXPerson_IsInvisible {
    char pad[0x9C];
    unsigned short m_flags;
    int IsInvisible();
};

int cXPerson_IsInvisible::IsInvisible() {
    return (m_flags >> 0) & 1;
}
