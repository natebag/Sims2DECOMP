// 0x8016F7D0 CasSimRenderer::GetNumBodyModels (36B)

int CasSimPartsS2C_GetNumBodyModels(void* parts, int bodyPart);

struct CasSimRenderer {
    char pad[0x140];
    void* m_parts;

    int GetNumBodyModels(int bodyPart);
};

int CasSimRenderer::GetNumBodyModels(int bodyPart) {
    return CasSimPartsS2C_GetNumBodyModels(m_parts, bodyPart);
}
