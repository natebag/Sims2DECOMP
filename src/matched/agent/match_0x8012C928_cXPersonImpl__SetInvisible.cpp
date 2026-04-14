// 0x8012C928 cXPersonImpl::SetInvisible(bool) (40B)
struct cXPersonImpl {
    char pad[156];
    short m_flags;
};

void cXPersonImpl__SetInvisible(cXPersonImpl* self, bool flag) {
    if (flag) self->m_flags |= 1;
    else self->m_flags &= ~1;
}
