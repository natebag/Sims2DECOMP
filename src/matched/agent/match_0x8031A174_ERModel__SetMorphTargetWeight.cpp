// PRAGMA_STUB: ERModel::SetMorphTargetWeight(int, float)
/* ERModel::SetMorphTargetWeight(int, float) at 0x8031A174 (56B) */

struct ERModel_SMT {
    char pad[0xCC];
    float m_morphWeights[12];
    int m_dirty;
    int SetMorphTargetWeight(int idx, float weight);
};

int ERModel_SMT::SetMorphTargetWeight(int idx, float weight) {
    if ((unsigned)idx > 12) return 0;
    if (m_morphWeights[idx] != weight) {
        m_morphWeights[idx] = weight;
        m_dirty = 1;
    }
    return 1;
}
