// 0x80320C50 ERTexture::Refresh(EFile (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 1f; lwz 0,0x14(31); cmpwi 0,0; bne 0f; lwz 9,0x0(31); mr 4,30; lha 3,0x48(9); lwz 0,0x4c(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; lwz 11,-26392(13); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(31); mr 4,30; lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,31,3; blrl; lwz 11,-26392(13); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct ERTexture {
    void Refresh_EFile();
};

void ERTexture::Refresh_EFile() {
}
