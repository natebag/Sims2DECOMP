// FLAGS: -fno-schedule-insns
// 0x8032075C ERShader::GetRTextureForRenderPass(int) (16B)
// slwi r4,r4,2; addi r3,r3,32; lwzx r3,r3,r4; blr  -- m_textures[pass] (inline array @0x20)
struct ERShader {
    char pad[0x20];
    void* m_textures[8];    // 0x20
    void* GetRTextureForRenderPass(int pass);
};

void* ERShader::GetRTextureForRenderPass(int pass) {
    return m_textures[pass];
}
