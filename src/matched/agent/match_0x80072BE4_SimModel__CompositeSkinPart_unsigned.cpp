// 0x80072BE4 SimModel::CompositeSkinPart(unsigned (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 28,0x30(1); stw 0,0x44(1); mr 31,3; mr 28,4; addi 3,1,8; bl _s80072BE4_0; lwz 9,0x13c(31); cmpwi 9,0; beq 0f; lwz 0,0x118(9); rlwinm 30,28,2,0,29; addi 29,31,320; cmpwi 0,0; beq 1f; add 9,30,31; lwz 3,0x158(9); bl _s80072BE4_1; lwz 4,0x150(31); bl _s80072BE4_2; mr 5,3; lwzx 4,29,30; lwz 6,0x150(31); addi 3,1,8; bl _s80072BE4_3; cmpwi 3,0; beq 1f; 0:; addi 3,1,8; li 4,2; bl _s80072BE4_4; b 4f; 1:; lwz 0,0x150(31); cmpwi 0,0; beq 2f; lwzx 4,29,30; mr 5,28; lwz 6,0x13c(31); addi 3,1,8; bl _s80072BE4_5; b 3f; 2:; lwzx 4,29,30; mr 5,28; lwz 6,0x13c(31); addi 3,1,8; bl _s80072BE4_6; 3:; addi 3,1,8; li 4,2; bl _s80072BE4_7; 4:; lwz 0,0x44(1); mtspr 8,0; lmw 28,0x30(1); addi 1,1,64"
extern "C" void _s80072BE4_0();
extern "C" void _s80072BE4_1();
extern "C" void _s80072BE4_2();
extern "C" void _s80072BE4_3();
extern "C" void _s80072BE4_4();
extern "C" void _s80072BE4_5();
extern "C" void _s80072BE4_6();
extern "C" void _s80072BE4_7();
extern "C" void f_80072BE4() {}
