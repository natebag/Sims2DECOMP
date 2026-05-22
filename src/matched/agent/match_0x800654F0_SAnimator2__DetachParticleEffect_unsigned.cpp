// 0x800654F0 SAnimator2::DetachParticleEffect(unsigned (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; mr. 5,5; beq 3f; stw 4,0x8(1); extsh 30,6; stw 5,0xc(1); sth 6,0x10(1); lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x118(9); lwz 9,0x11c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; 0:; lbz 0,-18451(13); or 0,30,0; b 2f; 1:; mr 0,30; 2:; sth 0,0x10(1); mr 3,31; addi 4,1,8; li 5,0; bl _s800654F0_0; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s800654F0_0();
extern "C" void f_800654F0() {}
