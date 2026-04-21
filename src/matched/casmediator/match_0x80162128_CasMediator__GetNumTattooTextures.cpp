// 0x80162128 CasMediator::GetNumTattooTextures(eTattooTextureTypeS2C) const (52B)

enum eTattooTextureTypeS2C { };

struct CasSimRendererDynamic {
    int GetNumTattooTextures(eTattooTextureTypeS2C type);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRendererDynamic* m_renderer;

    int GetNumTattooTextures(eTattooTextureTypeS2C type) const;
};

int CasMediator::GetNumTattooTextures(eTattooTextureTypeS2C type) const {
    CasSimRendererDynamic* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetNumTattooTextures(type);
}
