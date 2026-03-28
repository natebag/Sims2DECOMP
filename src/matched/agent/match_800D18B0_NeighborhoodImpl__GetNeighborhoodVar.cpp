/* NeighborhoodImpl::GetNeighborhoodVar(int) const - 0x800D18B0 (16 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x84];
    short m_vars[1];

    short GetNeighborhoodVar(int index) const;
};

short NeighborhoodImpl::GetNeighborhoodVar(int index) const {
    return m_vars[index];
}
