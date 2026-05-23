// 0x80068ECC SAnimator2::IsSimulatorControlled(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,1; lwz 0,0x61c(31); andi. 9,0,1; beq 0f; lwz 0,0x10(31); cmpwi 0,1; beq 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x350(9); lwz 9,0x354(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x228(9); lwz 9,0x22c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0xf0(9); lwz 9,0xf4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x8(31); li 4,16; addi 3,3,820; bl _s80068ECC_0; subfic 0,3,0; adde 30,0,3; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80068ECC_0();

struct SAnimator2 {
    void IsSimulatorControlled();
};

void SAnimator2::IsSimulatorControlled() {
}
