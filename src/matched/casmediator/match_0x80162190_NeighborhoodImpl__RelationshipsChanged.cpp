struct Neighbor;

int SortFamilyRelationships(Neighbor *);

struct NeighborhoodImpl {
    char pad_00[0x14];
    Neighbor* m_playerNeighbor;

    int RelationshipsChanged(Neighbor *);
};

int NeighborhoodImpl::RelationshipsChanged(Neighbor* n) {
    Neighbor* player = m_playerNeighbor;
    if (player != 0) {
        return SortFamilyRelationships(player);
    }
    return 0;
}
