// 0x800BADFC cGZMusic::Pause(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-24468(13); lwz 0,0x40c(9); cmpw 0,3; bne 0f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x54(9); lha 3,0x50(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,-24468(13); li 0,1; stw 0,0x418(9); 0:; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct cGZMusic {
    void Pause();
};

void cGZMusic::Pause() {
}
