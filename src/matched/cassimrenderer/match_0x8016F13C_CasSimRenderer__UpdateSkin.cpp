// 0x8016F13C CasSimRenderer::UpdateSkin (56B)

struct SimModel {
    void CompositeAllSkin();
    void ApplySkinToModels();
};

struct CasSimRenderer {
    char pad[8];
    SimModel m_model;
    void UpdateSkin();
};

void CasSimRenderer::UpdateSkin() {
    SimModel* model = &m_model;
    model->CompositeAllSkin();
    model->ApplySkinToModels();
}
