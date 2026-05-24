// 0x800BAC94 cGZMusic::Play(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; li 30,1; stw 30,0x8(31); lwz 9,-24468(13); lwz 0,0x418(9); cmpwi 0,0; beq 0f; lwz 3,0x40c(9); lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 10,-24468(13); lwz 0,0x40c(10); cmpwi 0,0; bne 1f; lis 9,-32697; lwz 11,0x5f14(9); lbz 0,0x1d(11); cmpwi 0,0; beq 1f; lwz 0,0x410(10); cmpwi 0,0; bne 1f; stw 31,0x40c(10); li 5,0; addi 3,1,8; lwz 4,0x10(31); bl _s800BAC94_0; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc(31); lis 11,-32706; lwz 10,-26564(13); stw 0,0x14(1); lfs f1,-25284(11); lwz 9,0x0(10); lwz 0,0x64(9); lha 3,0x60(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,-26564(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x20(31); 1:; li 3,1; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s800BAC94_0();

struct cGZMusic {
    void Play();
};

void cGZMusic::Play() {
}
