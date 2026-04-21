// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 52B: array base-alias r11/r3 swap wall. Parked by SonnetWorker2 S12.
// Original path: src/matched/cxpersonimpl/match_0x8012B5A0_cXPersonImpl__InvalidateRoutes.cpp
//
// 0x8012B5A0 (52B) cXPersonImpl::InvalidateRoutes(void)

struct RouteNode {
    char pad[0x7C];
    int field_7C;   // +0x7C = 124
    char pad2[0x24]; // to 0xA4 = 164
};

struct cXPersonImpl {
    char pad[0x40C];
    RouteNode* m_start;  // +0x40C = 1036
    RouteNode* m_end;    // +0x410 = 1040
    void InvalidateRoutes();
};

void cXPersonImpl::InvalidateRoutes() {
    RouteNode** base = &m_start;
    for (RouteNode* p = *base; (int)p < (int)(*(base + 1)); p++) {
        p->field_7C = 0;
    }
}
