// 0x80320220 ERShader::SwapTexture(ERTexture (252 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 30,3; mr 28,4; lwz 0,0x58(30); mr 27,5; andi. 9,0,2; beq 0f; lwz 3,0x18(30); bl _s80320220_0; b 7f; 0:; andi. 9,0,2; li 0,0; bne 3f; lwz 0,0x14(30); cmpwi 0,0; beq 1f; mr 9,0; b 2f; 1:; lwz 11,0x18(30); li 9,0; cmpwi 11,0; beq 2f; lwz 9,0x14(11); 2:; lwz 0,0x4(9); rlwinm 0,0,6,31,31; 3:; cmpwi 0,0; bne 7f; rlwinm 31,27,2,0,29; addi 29,30,32; lwzx 3,29,31; cmpwi 3,0; beq 4f; bl _s80320220_1; 4:; stwx 28,29,31; addi 9,30,40; lwz 0,0x8(28); stwx 0,9,31; lwz 3,0x14(30); cmpwi 3,0; beq 5f; mr 11,3; b 6f; 5:; lwz 3,0x18(30); li 11,0; cmpwi 3,0; beq 6f; lwz 11,0x14(3); 6:; lwz 9,0xf0(11); mr 5,27; lwz 4,0x14(28); lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80320220_0();
extern "C" void _s80320220_1();

struct ERShader {
    void SwapTexture_ERTexture();
};

void ERShader::SwapTexture_ERTexture() {
}
