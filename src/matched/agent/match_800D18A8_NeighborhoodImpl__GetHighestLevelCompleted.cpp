/* NeighborhoodImpl::GetHighestLevelCompleted(void) - 0x800D18A8 (8 bytes) */

struct NeighborhoodImpl {
    char m_pad[0x84];
    short m_highestLevelCompleted;

    short GetHighestLevelCompleted(void);
};

short NeighborhoodImpl::GetHighestLevelCompleted(void) {
    return m_highestLevelCompleted;
}
