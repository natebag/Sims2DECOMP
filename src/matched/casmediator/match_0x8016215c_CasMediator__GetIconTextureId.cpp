// 0x8016215c CasMediator::GetIconTextureId(eBodyPartS2C, unsigned int) const (28B)

enum eBodyPartS2C { };

struct CasSimRendererDynamic {
    int GetIconTextureId(eBodyPartS2C part, unsigned int index);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRendererDynamic* m_renderer;

    int GetIconTextureId(eBodyPartS2C part, unsigned int index) const;
};

int CasMediator::GetIconTextureId(eBodyPartS2C part, unsigned int index) const {
    CasSimRendererDynamic* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetIconTextureId(part, index);
}
