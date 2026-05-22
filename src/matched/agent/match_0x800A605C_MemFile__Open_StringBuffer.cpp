// 0x800A605C MemFile::Open(StringBuffer (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 31,3; mr 29,4; bl _s800A605C_0; mr. 28,3; beq 0f; li 3,-47; b 2f; 0:; lis 9,-32688; mr 3,29; addi 27,9,-1852; bl _s800A605C_1; mr 4,3; li 5,0; mr 3,27; bl _s800A605C_2; mr. 30,3; li 0,1; stw 0,0x10c(31); li 3,-50; stw 28,0x110(31); beq 2f; mr 4,29; mr 3,31; bl _s800A605C_3; lwz 9,0x0(30); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; addi 0,3,4096; stw 28,0x11c(31); rlwinm 0,0,0,0,19; stw 3,0x120(31); stw 0,0x118(31); bl _s800A605C_4; lwz 4,0x118(31); li 5,64; li 6,0; li 7,0; bl _s800A605C_5; stw 3,0x114(31); cmpwi 3,0; beq 1f; lwz 9,0x0(30); mr 4,3; lwz 5,0x120(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr 3,27; mr 4,30; bl _s800A605C_6; li 3,0; b 2f; 1:; mr 3,27; mr 4,30; bl _s800A605C_7; li 3,-50; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s800A605C_0();
extern "C" void _s800A605C_1();
extern "C" void _s800A605C_2();
extern "C" void _s800A605C_3();
extern "C" void _s800A605C_4();
extern "C" void _s800A605C_5();
extern "C" void _s800A605C_6();
extern "C" void _s800A605C_7();
extern "C" void f_800A605C() {}
