// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 68B: register pinning wall. Parked S12.
// Original path: src/matched/bbi/match_0x8004AFA8_BBI__InventoryItems__GetNewItemIndex.cpp
//
// 0x8004AFA8 (68B) BBI::InventoryItems::GetNewItemIndex(void) const

namespace BBI {

struct InventoryItems {
    int m_items[35];
    int GetNewItemIndex() const;
};

int InventoryItems::GetNewItemIndex() const {
    int result = -1;
    if (m_items[0] == 0) {
        result = 0;
    } else {
        for (int i = 1; i < 35; i++) {
            if (m_items[i] == 0) {
                result = i;
                break;
            }
        }
    }
    return result;
}

} // namespace BBI
