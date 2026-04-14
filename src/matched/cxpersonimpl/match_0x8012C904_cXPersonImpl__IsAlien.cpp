// 0x8012C904 cXPersonImpl::IsAlien (12B)

struct cXPerson_IsAlien {
    char pad[0x9C];
    unsigned short m_flags;
    int IsAlien();
};

int cXPerson_IsAlien::IsAlien() {
    return (m_flags >> 3) & 1;
}
