// 0x8014BB4C WantFear::Bookmark::DoStream(ReconBuffer (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; mr 30,5; mr 3,29; mr 4,31; li 5,1; bl _s8014BB4C_0; mr 3,29; addi 4,31,2; li 5,1; bl _s8014BB4C_1; cmpwi 30,95; ble 0f; mr 3,29; addi 4,31,8; li 5,1; bl _s8014BB4C_2; b 1f; 0:; li 0,0; sth 0,0x8(31); 1:; lwz 0,0xc(29); cmpwi 0,0; bne 3f; stw 0,0x4(31); mr 3,29; addi 4,1,8; li 5,1; bl _s8014BB4C_3; lha 0,0x8(1); cmpwi 0,-1; beq 2f; lis 9,-32697; lhz 4,0x0(31); lwz 3,0x5eec(9); bl _s8014BB4C_4; mr. 3,3; beq 2f; lha 9,0x8(1); cmpwi 9,0; blt 2f; lha 0,0x24(3); cmpw 9,0; bge 2f; lwz 0,0x28(3); rlwinm 9,9,5,0,26; add 0,0,9; stw 0,0x4(31); 2:; lwz 0,0x4(31); cmpwi 0,0; bne 5f; mr 3,31; bl _s8014BB4C_5; b 5f; 3:; lwz 3,0x4(31); cmpwi 3,0; li 0,-1; beq 4f; lha 0,0x0(3); 4:; sth 0,0xa(1); mr 3,29; addi 4,1,10; li 5,1; bl _s8014BB4C_6; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8014BB4C_0();
extern "C" void _s8014BB4C_1();
extern "C" void _s8014BB4C_2();
extern "C" void _s8014BB4C_3();
extern "C" void _s8014BB4C_4();
extern "C" void _s8014BB4C_5();
extern "C" void _s8014BB4C_6();
extern "C" void f_8014BB4C() {}
