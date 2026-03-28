struct Neighbor;

int SortNeighborRelationships(Neighbor *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    Neighbor* m_playerNeighbor;

    int LevelComplete(int);
};

int NeighborhoodImpl::LevelComplete(int level) {
    Neighbor* player = m_playerNeighbor;
    if (player != 0) {
        return SortNeighborRelationships(player);
    }
    return 0;
}
