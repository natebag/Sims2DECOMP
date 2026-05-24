// 0x8033B724 ENgcRenderer::GetCurrentTexture(int) (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,17976; lwzx 3,3,4"

struct ENgcRenderer {
    void GetCurrentTexture();
};

void ENgcRenderer::GetCurrentTexture() {
}
