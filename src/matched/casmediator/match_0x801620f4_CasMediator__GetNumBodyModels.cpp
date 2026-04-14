// 0x801620f4 CasMediator::GetNumBodyModels(eBodyPartS2C) const (28B)

enum eBodyPartS2C { };

struct CasSimRenderer {
    int GetNumBodyModels(eBodyPartS2C part);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRenderer* m_renderer;

    int GetNumBodyModels(eBodyPartS2C part) const;
};

int CasMediator::GetNumBodyModels(eBodyPartS2C part) const {
    CasSimRenderer* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetNumBodyModels(part);
}
