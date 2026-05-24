// 0x800BA498 cGZSnd::Stop(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; lwz 4,0x1c(31); cmpwi 4,0; beq 0f; li 30,0; addi 9,1,8; stw 30,0x8(1); mr 5,9; stw 30,0x10(9); lwz 11,-26564(13); lwz 0,0x8(1); ori 0,0,8; stw 0,0x8(1); lwz 9,0x0(11); lwz 0,0xb4(9); lha 3,0xb0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26564(13); lwz 4,0x1c(31); lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-26564(13); lwz 4,0x1c(31); lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x1c(31); 0:; li 0,0; li 3,1; stw 0,0xc(31); lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

struct cGZSnd {
    void Stop();
};

void cGZSnd::Stop() {
}
