// 0x800101F0 AptViewer::AptViewer(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; bl _s800101F0_0; addi 3,31,856; bl _s800101F0_1; li 8,0; addi 0,31,944; li 10,1; 0:; mr 9,0; addi 0,10,-1; addi 11,9,80; li 10,10; mtspr 9,10; 1:; stw 8,0x0(9); stw 8,0x4(9); addi 9,9,8; bdnz 1b; mr 10,0; mr 0,11; cmpwi 10,-1; bne 0b; lis 9,-32707; li 30,0; lfs f0,-9848(9); li 0,1; stw 30,0x350(31); li 3,16; stw 30,0x354(31); stw 30,0x3a0(31); stfs f0,0x37c(31); stw 10,0x3ac(31); stw 0,0x3a8(31); stfs f0,0x378(31); stw 0,0x3a4(31); bl _s800101F0_2; mr 4,3; lwz 11,-26532(13); stw 4,0x374(31); lwz 9,0x0(11); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-27588(13); mr 3,31; ori 0,0,2; stw 0,-27588(13); stw 30,0x464(31); stw 30,0x458(31); stw 30,0x45c(31); stw 30,0x460(31); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800101F0_0();
extern "C" void _s800101F0_1();
extern "C" void _s800101F0_2();
extern "C" void f_800101F0() {}
