// 0x8006C320 SAnimator2::stopCarry(void) (368 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 11,-21484(13); lha 4,0x164(31); cmpwi 4,0; beq 1f; lwz 9,0x0(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr. 30,3; beq 0f; lwz 9,0x0(30); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x98(11); lwz 0,0x9c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x0(30); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x9c(11); lha 3,0x98(11); mtspr 8,0; add 3,10,3; blrl; li 0,1; stw 0,0x6c(3); 0:; li 0,0; sth 0,0x164(31); 1:; lwz 0,0x61c(31); andi. 9,0,1024; beq 2f; lwz 3,0x8(31); lis 9,-32707; lfs f1,0x4de0(9); li 4,2048; addi 3,3,820; bl _s8006C320_0; b 3f; 2:; lwz 3,0x8(31); lis 9,-32707; lis 11,-32707; lfs f1,0x4de0(9); lfs f3,0x4de4(11); addi 3,3,820; lfs f2,-32296(13); li 4,2048; bl _s8006C320_1; 3:; lwz 0,0x61c(31); andi. 9,0,1024; beq 4f; lwz 3,0x8(31); rlwinm 0,0,0,22,20; li 4,2048; stw 0,0x61c(31); addi 3,3,820; bl _s8006C320_2; lwz 3,0x8(31); lis 9,-32707; lis 11,-32707; lfs f1,0x4de8(9); lfs f3,0x4de4(11); addi 3,3,820; lfs f2,-32336(13); li 4,2048; bl _s8006C320_3; 4:; lwz 0,0x61c(31); rlwinm 0,0,0,21,19; stw 0,0x61c(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8006C320_0();
extern "C" void _s8006C320_1();
extern "C" void _s8006C320_2();
extern "C" void _s8006C320_3();
extern "C" void f_8006C320() {}
