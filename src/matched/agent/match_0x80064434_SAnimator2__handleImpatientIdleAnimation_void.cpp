// 0x80064434 SAnimator2::handleImpatientIdleAnimation(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; lwz 0,0x61c(31); andis. 9,0,256; bne 2f; lwz 3,0x4(31); li 4,65; addi 5,1,8; bl _s80064434_0; lwz 4,0x8(1); cmpwi 4,0; beq 2f; lwz 4,0x0(4); lis 30,-32693; addi 3,30,11064; bl _s80064434_1; cmpwi 3,0; beq 1f; lwz 0,0x61c(31); andis. 9,0,4; beq 0f; lwz 9,0x8(1); addi 3,30,11064; li 5,1; lwz 4,0x0(9); bl _s80064434_2; 0:; lwz 9,0x8(1); li 4,1; lwz 3,0x8(31); li 6,-1; lwz 5,0x0(9); li 7,0; lfs f1,-32336(13); addi 3,3,820; bl _s80064434_3; lwz 0,0x61c(31); lis 9,-32707; lwz 11,0x8(31); mr 4,3; oris 0,0,256; lfs f1,0x4a28(9); rlwinm 0,0,0,14,12; addi 3,11,820; stw 0,0x61c(31); li 5,1; bl _s80064434_4; b 2f; 1:; lwz 0,0x61c(31); andis. 9,0,4; bne 2f; lwz 9,0x8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s80064434_5; lwz 0,0x61c(31); oris 0,0,4; stw 0,0x61c(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s80064434_0();
extern "C" void _s80064434_1();
extern "C" void _s80064434_2();
extern "C" void _s80064434_3();
extern "C" void _s80064434_4();
extern "C" void _s80064434_5();
extern "C" void f_80064434() {}
