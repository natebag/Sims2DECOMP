// 0x801FAB84 MSGTarget::SetupTitles(int) (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 17,0x34(1); stw 0,0x74(1); addi 26,1,8; lis 24,26214; lis 9,-32700; lis 22,-32704; addi 17,9,-25200; addi 23,22,-30484; mr 29,26; mr 25,3; mr 31,4; li 28,0; lis 18,-32704; lis 19,-32697; ori 24,24,26215; addi 27,1,40; lis 20,-32704; lis 21,-32704; 0:; mulhw 9,31,24; srawi 7,31,31; lwz 11,0x98(25); mr 5,28; lwz 6,-30484(22); addi 4,18,-30472; mulli 11,11,40; lwz 0,0x4(23); srawi 9,9,3; stw 6,0x8(1); subf 9,7,9; stw 0,0x4(29); mulli 9,9,20; lhz 10,0x8(23); lbz 8,0xa(23); mr 3,27; sth 10,0x8(29); addi 28,28,1; stb 8,0xa(29); subf 31,9,31; add 0,31,31; add 0,0,11; addi 31,31,1; lhzx 9,17,0; rlwinm 30,9,0,24,31; crxor 6,6,6; bl _s801FAB84_0; mr 4,27; mr 3,29; bl _s801FAB84_1; lwz 0,0x98(25); addi 4,20,-30464; mr 3,26; cmpwi 0,1; bne 1f; bl _s801FAB84_2; 1:; mr 4,30; addi 3,19,24012; bl _s801FAB84_3; mr. 9,3; addi 4,21,-30460; mr 3,29; li 0,0; beq 3f; lwz 9,0x0(9); cmpwi 9,0; beq 2f; lwz 0,0x0(9); 2:; mr 4,0; bl _s801FAB84_4; b 4f; 3:; mr 3,26; bl _s801FAB84_5; 4:; cmpwi 28,11; ble 0b; lwz 0,0x74(1); mtspr 8,0; lmw 17,0x34(1); addi 1,1,112"
extern "C" void _s801FAB84_0();
extern "C" void _s801FAB84_1();
extern "C" void _s801FAB84_2();
extern "C" void _s801FAB84_3();
extern "C" void _s801FAB84_4();
extern "C" void _s801FAB84_5();
extern "C" void f_801FAB84() {}
