/* cXPersonImpl::SetInvisible(bool) at 0x8012C928 (40B) */

struct cXPI_InvisFlags {
    char pad[0x9C];
    short m_flags;
    void SetInvisible(bool bInvisible);
};

void cXPI_InvisFlags::SetInvisible(bool bInvisible) {
    if (bInvisible)
        m_flags |= 1;
    else
        m_flags &= ~1;
}
