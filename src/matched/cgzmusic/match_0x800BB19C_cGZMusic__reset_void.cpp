// 0x800BB19C cGZMusic::reset(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-24468(13); lwz 10,0x40c(9); cmpw 10,3; bne 0f; lwz 11,-26564(13); li 0,0; stw 0,0x8(10); stw 0,0x418(9); stw 0,0x40c(9); lwz 9,0x0(11); lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct cGZMusic {
    void reset();
};

void cGZMusic::reset() {
}
