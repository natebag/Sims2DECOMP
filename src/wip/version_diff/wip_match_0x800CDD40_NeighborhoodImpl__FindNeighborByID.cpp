// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 56B: register-allocation wall. Parked by OpusWorker S9.
// Original path: src/matched/neighborhoodimpl/match_0x800CDD40_NeighborhoodImpl__FindNeighborByID.cpp
//
// 0x800CDD40 NeighborhoodImpl::FindNeighborByID (56B)

struct Neighbor;

struct NeighborhoodImpl {
    char pad[116];
    int m_arrayStart;
    int m_arrayEnd;
    Neighbor* FindNeighborByID(int id);
};

Neighbor* NeighborhoodImpl::FindNeighborByID(int id) {
    if (id <= 0) return 0;
    int count = (m_arrayEnd - m_arrayStart) >> 2;
    if ((unsigned int)id > (unsigned int)count) return 0;
    return ((Neighbor**)m_arrayStart)[id - 1];
}
