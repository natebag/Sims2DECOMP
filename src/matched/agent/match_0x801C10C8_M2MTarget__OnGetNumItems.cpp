// 0x801C10C8 M2MTarget::OnGetNumItems(M2MTarget::ResultStruct&) (64B) — placeholder→nested-class consolidation
//
// Was using generic placeholder struct M2MRS. Promoted to nested class
// M2MTarget::ResultStruct (the symbol mangling `M2MTarget::ResultStruct&`
// matches the filename's hint).
//
// Field naming inferred from usage pattern:
// - field0 == 0xFF  → result = 2  (likely a player-slot ID sentinel)
// - field4 == 0xFF  → result = 8  (likely a second-slot ID sentinel)
// - field8 == 0     → result = 4  (likely an isOccupied flag with 0 = empty)
// - default         → result = 0

class M2MTarget {
public:
    struct ResultStruct {
        int m_primarySlot;   // 0xFF sentinel = unassigned
        int m_secondarySlot; // 0xFF sentinel = unassigned
        int m_isOccupied;    // 0 = empty slot
    };

    int OnGetNumItems(ResultStruct& rs);
};

int M2MTarget::OnGetNumItems(M2MTarget::ResultStruct& rs) {
    int result = 0;
    if (rs.m_primarySlot == 0xff) return 2;
    if (rs.m_secondarySlot == 0xff) return 8;
    if (rs.m_isOccupied == 0) result = 4;
    return result;
}
