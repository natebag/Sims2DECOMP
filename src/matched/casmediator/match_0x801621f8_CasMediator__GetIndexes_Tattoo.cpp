// 0x801621f8 CasMediator::GetIndexes(eTattooTextureTypeS2C, unsigned char *, unsigned char *) (28B)

enum eTattooTextureTypeS2C { };

struct CasSimRendererDynamic {
    int GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRendererDynamic* m_renderer;

    int GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b);
};

int CasMediator::GetIndexes(eTattooTextureTypeS2C type, unsigned char* a, unsigned char* b) {
    CasSimRendererDynamic* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetIndexes(type, a, b);
}
