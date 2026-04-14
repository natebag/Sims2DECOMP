// 0x80072D3C SimModel::UpdateReweldCAS(bool) (88B)
// Pattern: RebuildModified + flag-4 check + conditional MorphParts/Dealloc
struct EIStaticModel;
namespace SimRenderer {
    void MorphParts(EIStaticModel** models, bool cas);
}

struct SimModel {
    int m_f0;
    int m_flags;
    char pad[96];
    EIStaticModel* m_models[26];
    void RebuildModified();
    void DeallocateMorphResources();
    void UpdateReweldCAS(bool b);
};

void SimModel::UpdateReweldCAS(bool b) {
    RebuildModified();
    if ((m_flags & 4) == 0 && b) {
        SimRenderer::MorphParts(m_models, true);
        DeallocateMorphResources();
    }
}
