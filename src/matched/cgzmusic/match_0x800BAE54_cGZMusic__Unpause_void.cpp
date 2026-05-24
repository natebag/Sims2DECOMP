// 0x800BAE54 cGZMusic::Unpause(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,-24468(13); lwz 0,0x40c(9); cmpw 0,3; bne 0f; lwz 11,-26564(13); lwz 9,0x0(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,-24468(13); li 0,0; stw 0,0x418(9); 0:; li 3,1; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct cGZMusic {
    void Unpause();
};

void cGZMusic::Unpause() {
}
