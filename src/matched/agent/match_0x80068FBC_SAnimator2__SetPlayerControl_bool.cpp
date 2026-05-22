// 0x80068FBC SAnimator2::SetPlayerControl(bool) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,1; bne 0f; lwz 0,0x61c(3); ori 0,0,1; b 1f; 0:; lwz 0,0x61c(3); rlwinm 0,0,0,0,30; 1:; stw 0,0x61c(3); lwz 9,0x8(3); cmpwi 4,0; beq 2f; lwz 0,0x334(9); ori 0,0,1; b 3f; 2:; lwz 0,0x334(9); rlwinm 0,0,0,0,30; 3:; stw 0,0x334(9); addi 3,3,1568; bl _s80068FBC_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80068FBC_0();
extern "C" void f_80068FBC() {}
