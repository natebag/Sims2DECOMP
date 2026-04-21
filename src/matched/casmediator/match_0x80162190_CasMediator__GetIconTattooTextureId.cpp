// 0x80162190 CasMediator::GetIconTattooTextureId(eTattooTextureTypeS2C, unsigned int) const (52B)

enum eTattooTextureTypeS2C { };

struct CasSimRendererDynamic {
    int GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRendererDynamic* m_renderer;

    int GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index) const;
};

int CasMediator::GetIconTattooTextureId(eTattooTextureTypeS2C type, unsigned int index) const {
    CasSimRendererDynamic* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetIconTattooTextureId(type, index);
}
