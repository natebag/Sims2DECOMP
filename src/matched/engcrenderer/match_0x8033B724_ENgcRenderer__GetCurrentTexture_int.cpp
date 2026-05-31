// FLAGS: -fno-schedule-insns
// 0x8033B724 ENgcRenderer::GetCurrentTexture(int) (16B)
// slwi r4,r4,2; addi r3,r3,17976; lwzx r3,r3,r4; blr  -- m_textures[i] (inline array @0x4638)
struct ENgcRenderer {
    char pad[0x4638];
    void* m_textures[8];    // 0x4638
    void* GetCurrentTexture(int i);
};

void* ENgcRenderer::GetCurrentTexture(int i) {
    return m_textures[i];
}
