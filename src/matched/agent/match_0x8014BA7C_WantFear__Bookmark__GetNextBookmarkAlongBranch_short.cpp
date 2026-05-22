// 0x8014BA7C WantFear::Bookmark::GetNextBookmarkAlongBranch(short) (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); lis 9,-32697; mr 31,4; mr 29,3; lhz 4,0x0(31); lwz 3,0x5eec(9); mr 30,5; li 28,0; bl _s8014BA7C_0; lwz 4,0x4(31); mr 5,30; bl _s8014BA7C_1; mr 30,3; lbz 0,0x1d(30); andi. 9,0,2; beq 1f; lha 5,0x2(31); cmpwi 5,0; bne 0f; lwz 9,0x4(31); lha 28,0x6(9); b 1f; 0:; mr 28,5; 1:; mr 3,30; li 27,0; bl _s8014BA7C_2; lbz 0,0xb(3); cmpwi 0,2; bne 2f; lhz 27,0x8(30); 2:; lhz 4,0x0(31); mr 5,28; mr 6,30; mr 7,27; addi 3,1,8; bl _s8014BA7C_3; addi 9,1,8; lwz 11,0x8(1); lwz 10,0x8(9); mr 3,29; lwz 0,0x4(9); stw 11,0x0(29); stw 0,0x4(29); stw 10,0x8(29); lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"
extern "C" void _s8014BA7C_0();
extern "C" void _s8014BA7C_1();
extern "C" void _s8014BA7C_2();
extern "C" void _s8014BA7C_3();
extern "C" void f_8014BA7C() {}
