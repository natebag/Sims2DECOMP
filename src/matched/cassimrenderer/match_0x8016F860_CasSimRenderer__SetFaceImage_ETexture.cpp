// 0x8016F860 CasSimRenderer::SetFaceImage(ETexture (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; lwz 4,0x210(31); cmpw 30,4; beq 2f; cmpwi 4,0; beq 1f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0xc8(9); lwz 9,0xcc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; lwz 3,-26392(13); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 11,-26392(13); lwz 4,0x210(31); lwz 9,0x0(11); lwz 0,0xc4(9); lha 3,0xc0(9); mtspr 8,0; add 3,11,3; blrl; li 0,0; stw 0,0x210(31); 1:; stw 30,0x210(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct CasSimRenderer {
    void SetFaceImage_ETexture();
};

void CasSimRenderer::SetFaceImage_ETexture() {
}
