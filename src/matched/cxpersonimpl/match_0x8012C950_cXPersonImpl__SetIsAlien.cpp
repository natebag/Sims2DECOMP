/* cXPersonImpl::SetIsAlien(bool) at 0x8012C950 (40B) */

struct cXPI_AlienFlags {
    char pad[0x9C];
    short m_flags;
    void SetIsAlien(bool bAlien);
};

void cXPI_AlienFlags::SetIsAlien(bool bAlien) {
    if (bAlien)
        m_flags |= 8;
    else
        m_flags &= ~8;
}
