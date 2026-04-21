// 0x801621c4 CasMediator::GetIndexes(eBodyPartS2C, unsigned char *, unsigned char *) (52B)

enum eBodyPartS2C { };

struct CasSimRendererDynamic {
    int GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b);
};

struct CasMediator {
    char pad[0x10];
    void* m_editSim;
    CasSimRendererDynamic* m_renderer;

    int GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b);
};

int CasMediator::GetIndexes(eBodyPartS2C part, unsigned char* a, unsigned char* b) {
    CasSimRendererDynamic* renderer = m_renderer;
    if (renderer == 0) return 0;
    return renderer->GetIndexes(part, a, b);
}
