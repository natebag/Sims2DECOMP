/* EShader::SetMultiTexture(ETexture *, int) at 0x802FAB28 (16B) */

struct ETexture;

struct EShader {
    char pad[0x68];
    ETexture** m_multiTextures;

    void SetMultiTexture(ETexture* tex, int index);
};

void EShader::SetMultiTexture(ETexture* tex, int index) {
    m_multiTextures[index] = tex;
}
