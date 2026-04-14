// 0x8012C950 cXPersonImpl::SetIsAlien(bool) (40B)
struct cXPersonImpl {
    char pad[156];
    short m_flags;
};

void cXPersonImpl__SetIsAlien(cXPersonImpl* self, bool flag) {
    if (flag) self->m_flags |= 8;
    else self->m_flags &= ~8;
}
