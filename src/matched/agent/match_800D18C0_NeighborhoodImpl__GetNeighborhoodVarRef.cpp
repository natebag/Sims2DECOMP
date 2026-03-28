/* NeighborhoodImpl::GetNeighborhoodVarRef(int) - 0x800D18C0 (16 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x84];
    short m_vars[1];

    short *GetNeighborhoodVarRef(int index);
};

short *NeighborhoodImpl::GetNeighborhoodVarRef(int index) {
    return &m_vars[index];
}
