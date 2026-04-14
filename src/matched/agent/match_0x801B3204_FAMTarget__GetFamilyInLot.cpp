// 0x801B3204 FAMTarget::GetFamilyInLot(int) (64B)
struct FAMTarget;

extern int FAMTarget__ConvertLotIndexToGameIndex(FAMTarget* self, int idx);

struct VT {
    char pad[296];
    short m_adj;
    short m_pad;
    int (*m_fn)(void*, int);
};
struct FamilyMgr { VT* m_vt; };

extern FamilyMgr* g_familyMgr;  // SDA

int FAMTarget__GetFamilyInLot(FAMTarget* self, int idx) {
    int actualIdx = FAMTarget__ConvertLotIndexToGameIndex(self, idx);
    FamilyMgr* mgr = g_familyMgr;
    VT* vt = mgr->m_vt;
    return vt->m_fn((char*)mgr + vt->m_adj, actualIdx);
}
