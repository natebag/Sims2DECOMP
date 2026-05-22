// 0x801E3160 WAFTarget::GetLocalizable(char (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801E3160_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801E3160_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,25596; mr 4,30; li 5,8; bl _s801E3160_2; cmpwi 3,0; bne 3f; lis 4,-32705; mr 3,30; addi 4,4,25608; addi 5,1,8; crxor 6,6,6; bl _s801E3160_3; cmpwi 3,1; bne 1f; lwz 3,0x8(1); cmpwi 3,0; blt 1f; cmpwi 3,7; ble 2f; 1:; mr 3,31; bl _s801E3160_4; li 3,0; b 4f; 2:; mulli 3,3,60; add 3,3,29; addi 3,3,216; bl _s801E3160_5; mr 4,3; mr 3,31; bl _s801E3160_6; 3:; mr 3,31; bl _s801E3160_7; mr 3,31; bl _s801E3160_8; mr 3,31; bl _s801E3160_9; mr 3,31; bl _s801E3160_10; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801E3160_11; mr 30,3; mr 4,31; bl _s801E3160_12; mr 3,31; bl _s801E3160_13; mr 3,30; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s801E3160_0();
extern "C" void _s801E3160_1();
extern "C" void _s801E3160_2();
extern "C" void _s801E3160_3();
extern "C" void _s801E3160_4();
extern "C" void _s801E3160_5();
extern "C" void _s801E3160_6();
extern "C" void _s801E3160_7();
extern "C" void _s801E3160_8();
extern "C" void _s801E3160_9();
extern "C" void _s801E3160_10();
extern "C" void _s801E3160_11();
extern "C" void _s801E3160_12();
extern "C" void _s801E3160_13();
extern "C" void f_801E3160() {}
