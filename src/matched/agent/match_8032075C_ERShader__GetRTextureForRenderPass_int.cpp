class ERTexture;
class ERShader { char pad[32]; ERTexture *m_textures[4]; public: ERTexture *GetRTextureForRenderPass(int); };
ERTexture *ERShader::GetRTextureForRenderPass(int pass) { return m_textures[pass]; }
