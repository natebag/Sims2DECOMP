// 0x8006BC94 SAnimator2::initWalkRunFadeOut(void) (200 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 30,0; lwz 3,0x4(31); addi 5,1,8; stw 30,0xc(1); li 4,3; bl _s8006BC94_0; lwz 9,0x8(1); lis 11,-32707; lwz 3,0x8(31); li 4,1; lfs f1,0x4db4(11); li 6,4; lwz 5,0x0(9); addi 3,3,820; addi 7,1,12; bl _s8006BC94_1; stw 30,0xc8(31); lis 9,-32707; lwz 0,0x61c(31); lfs f1,0x4db8(9); lwz 9,0xc(1); oris 0,0,1; lwz 11,0x8(1); stw 0,0x61c(31); cmpwi 9,0; stw 11,0xd4(31); stfs f1,0xd0(31); beq 1f; lwz 4,0x668(31); cmpwi 4,0; beq 0f; lwz 3,0x8(31); lis 9,-32707; lfs f3,0x4dbc(9); lfs f2,-32292(13); addi 3,3,820; bl _s8006BC94_2; stw 30,0x668(31); 0:; lwz 0,0xc(1); stw 0,0x668(31); 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8006BC94_0();
extern "C" void _s8006BC94_1();
extern "C" void _s8006BC94_2();
extern "C" void f_8006BC94() {}
