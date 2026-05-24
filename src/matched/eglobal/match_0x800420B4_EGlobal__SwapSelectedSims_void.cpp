// 0x800420B4 EGlobal::SwapSelectedSims(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 28,-21496(13); mr 31,3; cmpwi 28,0; beq 0f; lwz 0,0xbc(31); cmpwi 0,0; beq 0f; lwz 11,0xc0(31); cmpwi 11,0; beq 0f; stw 0,0xc0(31); stw 11,0xbc(31); lwz 11,0x0(11); lwz 30,0x0(28); lwz 9,0x4(11); lha 29,0x38(30); lwz 0,0x32c(9); addi 30,30,56; lha 3,0x328(9); add 29,28,29; mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 5,3; mr 3,29; li 4,3; mtspr 8,0; blrl; lwz 9,0xc0(31); lwz 30,0x0(28); lwz 11,0x0(9); lha 29,0x38(30); lwz 9,0x4(11); addi 30,30,56; add 29,28,29; lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0x4(30); mr 5,3; mr 3,29; li 4,32; mtspr 8,0; blrl; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

struct EGlobal {
    void SwapSelectedSims();
};

void EGlobal::SwapSelectedSims() {
}
