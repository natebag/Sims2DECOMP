// 0x801B0D1C FAMTarget::GetFamilyInFamilyList(int) (64B)
struct FAMTarget;

extern int FAMTarget__ConvertSelectedFamilyIndexToActualGameIndex(FAMTarget* self, int idx);

struct VT {
    char pad[288];
    short m_adj;
    short m_pad;
    int (*m_fn)(void*, int);
};
struct FamilyMgr { VT* m_vt; };

extern FamilyMgr* g_familyMgr;  // SDA

int FAMTarget__GetFamilyInFamilyList(FAMTarget* self, int idx) {
    int actualIdx = FAMTarget__ConvertSelectedFamilyIndexToActualGameIndex(self, idx);
    FamilyMgr* mgr = g_familyMgr;
    VT* vt = mgr->m_vt;
    return vt->m_fn((char*)mgr + vt->m_adj, actualIdx);
}
