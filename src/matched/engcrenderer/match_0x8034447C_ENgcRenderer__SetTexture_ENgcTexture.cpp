// 0x8034447C ENgcRenderer::SetTexture(ENgcTexture (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,5; rlwinm 30,27,2,0,29; addi 31,29,17976; lwzx 11,31,30; mr 28,4; cmpwi 11,0; beq 0f; lwz 9,0x24(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; 0:; cmpwi 7,28,0; beq cr7,1f; lwzx 0,31,30; cmpwi 0,0; bne 2f; lbz 9,0x4634(29); addi 9,9,1; stb 9,0x4634(29); b 2f; 1:; lwzx 0,31,30; cmpwi 0,0; beq 2f; lbz 9,0x4634(29); cmpwi 9,0; beq 2f; addi 0,9,-1; stb 0,0x4634(29); 2:; addi 3,29,17976; rlwinm 0,27,2,0,29; stwx 28,3,0; beq cr7,6f; li 29,0; cmpw 29,27; bge 5f; mr 30,3; mr 31,27; 3:; lwz 3,0x0(30); addi 30,30,4; cmpwi 3,0; beq 4f; bl _s8034447C_0; add 29,29,3; 4:; addic. 31,31,-1; bne 3b; 5:; lwz 9,0x24(28); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,28,3; blrl; lwz 9,0x24(28); mr 4,27; mr 5,29; lha 3,0x90(9); lwz 0,0x94(9); add 3,28,3; mtspr 8,0; blrl; 6:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s8034447C_0();

struct ENgcRenderer {
    void SetTexture_ENgcTexture();
};

void ENgcRenderer::SetTexture_ENgcTexture() {
}
