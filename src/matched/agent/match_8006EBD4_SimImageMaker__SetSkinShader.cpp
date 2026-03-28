typedef unsigned char u8;
class EShader;

class SimImageMaker {
    u8 _pad0[0x8C];
    EShader *m_pSkinShader;
public:
    void SetSkinShader(EShader *);
};

void SimImageMaker::SetSkinShader(EShader *shader) {
    m_pSkinShader = shader;
}
