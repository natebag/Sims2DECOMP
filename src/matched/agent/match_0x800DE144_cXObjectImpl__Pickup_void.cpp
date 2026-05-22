// 0x800DE144 cXObjectImpl::Pickup(void) (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(31); li 4,10; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 0:; lwz 0,0x6c(31); addi 30,31,40; lwz 9,0x68(31); li 4,1; srawi 26,0,4; mr 3,30; srawi 27,9,4; bl _s800DE144_0; lha 28,0x0(3); li 4,1; addi 3,1,8; bl _s800DE144_1; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x2d4(9); lha 3,0x2d0(9); mtspr 8,0; add 3,11,3; blrl; mr 29,3; addi 4,1,8; li 5,1; mr 3,31; bl _s800DE144_2; li 4,2; li 5,0; mr 3,30; bl _s800DE144_3; li 4,3; li 5,-1; mr 3,30; bl _s800DE144_4; addi 4,1,32; li 0,-16; stw 0,0x4(4); li 5,1; stw 0,0x20(1); lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x334(9); lha 3,0x330(9); mtspr 8,0; add 3,11,3; blrl; li 4,8; mr 3,30; bl _s800DE144_5; lha 5,0x0(3); li 4,8; mr 3,30; rlwinm 5,5,0,24,22; bl _s800DE144_6; lwz 11,0x4(31); lwz 9,0x4(11); lha 3,0x480(9); lwz 0,0x484(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 1f; lis 9,-32702; lis 11,-32702; rlwinm 0,28,2,0,29; addi 9,9,17152; addi 11,11,17188; lwzx 4,9,0; lwzx 5,11,0; lwz 3,0x58(31); add 4,26,4; lwz 6,0x80(31); add 5,27,5; bl _s800DE144_7; 1:; cmpwi 29,0; beq 2f; lwz 9,0x4(29); li 4,9; li 5,0; li 6,0; lha 3,0x100(9); lwz 0,0x104(9); add 3,29,3; mtspr 8,0; blrl; 2:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x400(9); lwz 9,0x404(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; lwz 5,0x80(31); mr 3,26; mr 4,27; li 6,0; bl _s800DE144_8; 3:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s800DE144_0();
extern "C" void _s800DE144_1();
extern "C" void _s800DE144_2();
extern "C" void _s800DE144_3();
extern "C" void _s800DE144_4();
extern "C" void _s800DE144_5();
extern "C" void _s800DE144_6();
extern "C" void _s800DE144_7();
extern "C" void _s800DE144_8();
extern "C" void f_800DE144() {}
