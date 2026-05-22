// 0x8023FC40 ReadSyncNext (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32694; lis 29,-32694; lwz 30,-26492(9); 0:; bl _s8023FC40_0; cmpwi 3,0; beq 0b; lis 9,-13312; li 0,4096; ori 9,9,12288; stw 0,0x0(9); bl _s8023FC40_1; lis 9,-32694; lwz 0,-26488(9); cmpwi 0,0; beq 1f; lis 9,-32694; lwz 11,-26488(29); lwz 10,-26492(9); li 31,1024; addi 11,11,-1; addi 10,10,1024; stw 11,-26488(29); stw 10,-26492(9); b 2f; 1:; lis 9,-32694; lwz 31,-26484(9); stw 0,-26484(9); 2:; bl _s8023FC40_2; mr 3,30; mr 4,31; bl _s8023FC40_3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8023FC40_0();
extern "C" void _s8023FC40_1();
extern "C" void _s8023FC40_2();
extern "C" void _s8023FC40_3();
extern "C" void f_8023FC40() {}
