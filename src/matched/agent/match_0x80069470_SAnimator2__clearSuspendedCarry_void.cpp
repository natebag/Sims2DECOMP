// 0x80069470 SAnimator2::clearSuspendedCarry(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x61c(31); andi. 9,0,1024; beq 0f; lwz 3,0x8(31); rlwinm 0,0,0,22,20; li 4,2048; stw 0,0x61c(31); addi 3,3,820; bl _s80069470_0; lwz 3,0x8(31); lis 9,-32707; lis 11,-32707; lfs f1,0x4c24(9); lfs f3,0x4c28(11); addi 3,3,820; lfs f2,-32336(13); li 4,2048; bl _s80069470_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80069470_0();
extern "C" void _s80069470_1();
extern "C" void f_80069470() {}
