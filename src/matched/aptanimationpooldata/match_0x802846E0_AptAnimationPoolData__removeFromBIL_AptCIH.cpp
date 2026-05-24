// 0x802846E0 AptAnimationPoolData::removeFromBIL(AptCIH (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 31,3; mr 28,4; lwz 0,0x10(31); li 30,0; addic. 9,0,-1; blt 2f; lis 25,-32704; lis 26,-32704; li 27,28; li 29,0; 0:; lwz 9,0x14(31); lwzx 0,29,9; cmpw 28,0; bne 1f; lwz 9,0x8(28); addi 5,26,11876; addi 4,25,12292; li 6,1320; lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; lwz 5,0x10(31); lwz 3,0x14(31); subf 5,30,5; mulli 5,5,28; add 4,3,27; add 3,3,29; bl _s802846E0_0; lwz 9,0x10(31); addi 9,9,-1; stw 9,0x10(31); 1:; lwz 9,0x10(31); addi 30,30,1; addi 27,27,28; addi 29,29,28; addi 9,9,-1; cmpw 30,9; ble 0b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s802846E0_0();

struct AptAnimationPoolData {
    void removeFromBIL_AptCIH();
};

void AptAnimationPoolData::removeFromBIL_AptCIH() {
}
