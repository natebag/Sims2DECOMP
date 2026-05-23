// 0x800667F0 SAnimator2::isAnimationDone(void) (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0xd4(31); li 3,1; cmpwi 0,0; bne 0f; li 3,0; 0:; cmpwi 3,0; beq 8f; lwz 3,0x8(31); li 4,48; li 30,0; addi 3,3,820; bl _s800667F0_0; cmpwi 3,0; bne 3f; lwz 0,0x61c(31); andi. 9,0,1; beq 4f; lwz 9,0x8(31); addi 11,9,820; lwz 9,0x8(11); cmpwi 9,-1; beq 1f; mulli 9,9,176; lwz 0,0x44(11); add 9,9,0; lwz 9,0x30(9); b 2f; 1:; li 9,0; 2:; andi. 0,9,32; beq 4f; lwz 3,0x4(31); li 4,0; lwz 9,0x4(3); lha 0,0xd8(9); lwz 9,0xdc(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; ble 4f; 3:; li 30,1; 4:; cmpwi 30,0; beq 7f; lwz 9,0xd4(31); lis 3,-32693; addi 3,3,11064; li 30,0; lwz 4,0x0(9); bl _s800667F0_1; mr. 3,3; beq 5f; lwz 30,0x14(3); 5:; lwz 5,0xc8(31); cmpw 5,30; bgt 6f; lwz 7,0x61c(31); mr 3,31; lwz 4,0xd4(31); li 6,-1; rlwinm 7,7,24,31,31; li 8,0; bl _s800667F0_2; addi 0,30,1; stw 0,0xc8(31); 6:; lwz 0,0xe0(31); li 9,0; lwz 11,0xdc(31); stw 9,0x5e8(31); subf 0,11,0; rlwinm. 9,0,30,2,31; mfcr 3; rlwinm 3,3,3,31,31; b 8f; 7:; li 3,0; 8:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800667F0_0();
extern "C" void _s800667F0_1();
extern "C" void _s800667F0_2();

struct SAnimator2 {
    void isAnimationDone();
};

void SAnimator2::isAnimationDone() {
}
