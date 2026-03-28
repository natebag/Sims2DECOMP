struct ERShader {
    char _p[0x20];
    int m_textures[4];
    int GetRTextureForRenderPass(int i);
};
int ERShader::GetRTextureForRenderPass(int i) { return m_textures[i]; }
