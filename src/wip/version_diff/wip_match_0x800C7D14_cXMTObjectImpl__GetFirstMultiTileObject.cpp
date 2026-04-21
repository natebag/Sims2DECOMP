// WIP PARTIAL-FAKE / WALL (moved from src/matched/ by S13 pre-session triage, 2026-04-21)
// Diagnostic: MISMATCH 48B: cr7 reuse across linked-list head traversal. Parked by SonnetWorker2 S12.
// Original path: src/matched/cxmtobjectimpl/match_0x800C7D14_cXMTObjectImpl__GetFirstMultiTileObject.cpp
//
// 0x800C7D14 cXMTObjectImpl::GetFirstMultiTileObject (48B)

struct cXObject;

struct cXMTObjectImpl {
    char pad[4];
    cXObject* m_object;
    char pad2[4];
    cXMTObjectImpl* m_field0C;
    cXObject* GetFirstMultiTileObject();
};

cXObject* cXMTObjectImpl::GetFirstMultiTileObject() {
    cXMTObjectImpl* p = this;
    if (m_field0C) {
        p = m_field0C;
    }
    if (p) {
        return p->m_object;
    }
    return 0;
}
