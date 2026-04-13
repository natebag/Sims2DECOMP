/* NeighborhoodImpl::SetNeighborhoodVar(int, short) - 0x800D18D0 (16 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x84];
    short m_vars[1];

    void SetNeighborhoodVar(int index, short value);
};

void NeighborhoodImpl::SetNeighborhoodVar(int index, short value) {
    m_vars[index] = value;
}
