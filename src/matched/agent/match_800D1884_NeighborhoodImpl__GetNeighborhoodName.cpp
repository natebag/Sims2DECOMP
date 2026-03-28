/* NeighborhoodImpl::GetNeighborhoodName(void) - 0x800D1884 (36 bytes) */

struct StringBuffer2 {
    const char *c_str(void) const;
};

struct NeighborhoodImpl {
    int m_pad0;
    StringBuffer2 m_name;

    const char *GetNeighborhoodName(void);
};

const char *NeighborhoodImpl::GetNeighborhoodName(void) {
    return m_name.c_str();
}
