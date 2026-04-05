/* EShader::SetTexture(ETexture *, int) at 0x802FAB18 (16B) */

struct ETexture;

struct ShaderTexSlot {
    ETexture* m_texture;
    char _pad[60];
};

struct EShader {
    char pad[0x64];
    ShaderTexSlot m_texSlots[1];

    void SetTexture(ETexture* tex, int index);
};

void EShader::SetTexture(ETexture* tex, int index) {
    m_texSlots[index].m_texture = tex;
}
