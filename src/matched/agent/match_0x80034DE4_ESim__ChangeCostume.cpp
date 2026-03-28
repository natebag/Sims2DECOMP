/* ESim::ChangeCostume(void) at 0x80034DE4 (92B) */

struct SimModel {
    void SetAllModels(void);
    void VerifyRequiredModels(void);
    void ApplyAllLatticeMorphing(void);
    void ApplyAllMorphTargets(void);
    void UpdateReweld(int flag);
};

struct ESim {
    char pad[0x63C];
    SimModel *m_simModel;
    void ChangeCostume(void);
    void CompositeSkin(void);
};

void ESim::ChangeCostume(void) {
    m_simModel->SetAllModels();
    m_simModel->VerifyRequiredModels();
    m_simModel->ApplyAllLatticeMorphing();
    m_simModel->ApplyAllMorphTargets();
    m_simModel->UpdateReweld(1);
    CompositeSkin();
}
