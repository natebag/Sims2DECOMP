// 0x80064538 SAnimator2::clearImpatientIdleAnimation(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 9,3; lwz 0,0x61c(9); andis. 11,0,4; beq 1f; rlwinm 0,0,0,14,12; lwz 3,0x4(9); stw 0,0x61c(9); addi 5,1,8; li 4,65; lis 31,-32693; bl _s80064538_0; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064538_1; cmpwi 3,0; beq 0f; lwz 9,0x8(1); addi 3,31,11064; li 5,1; lwz 4,0x0(9); bl _s80064538_2; b 1f; 0:; lwz 9,0x8(1); addi 3,31,11064; lwz 4,0x0(9); bl _s80064538_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80064538_0();
extern "C" void _s80064538_1();
extern "C" void _s80064538_2();
extern "C" void _s80064538_3();
extern "C" void f_80064538() {}
