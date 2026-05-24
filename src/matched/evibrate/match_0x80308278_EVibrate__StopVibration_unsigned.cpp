// 0x80308278 EVibrate::StopVibration(unsigned (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 3,-26524(13); bl _s80308278_0; mr. 11,3; bne 0f; li 3,0; b 1f; 0:; lwz 9,0x208(11); lha 3,0x78(9); lwz 0,0x7c(9); add 3,11,3; mtspr 8,0; blrl; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80308278_0();

struct EVibrate {
    void StopVibration();
};

void EVibrate::StopVibration() {
}
