// 0x800D00AC NeighborhoodImpl::UpdateFamilyFriendsCount(Family (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 27,3; mr 31,4; lwz 9,0x74(27); li 26,0; lwz 0,0x78(27); cmpw 9,0; beq 5f; 0:; lwz 28,0x0(9); addi 24,9,4; addi 25,27,116; cmpwi 28,0; beq 4f; lwz 30,0x0(31); mr 3,28; lha 29,0x58(30); addi 30,30,88; add 29,31,29; bl _s800D00AC_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; cmpwi 3,0; bne 4f; lha 0,0xea(28); cmpwi 0,0; beq 4f; li 30,0; b 3f; 1:; lwz 9,0x0(31); mr 4,30; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(27); lwz 4,0x0(3); lha 3,0xc0(9); lwz 0,0xc4(9); add 3,27,3; mtspr 8,0; blrl; mr. 3,3; beq 2f; mr 4,28; bl _s800D00AC_1; li 4,6; bl _s800D00AC_2; cmpwi 3,0; beq 2f; addi 26,26,1; b 4f; 2:; addi 30,30,1; 3:; lwz 9,0x0(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; cmpw 30,3; blt 1b; 4:; lwz 0,0x4(25); mr 9,24; cmpw 9,0; bne 0b; 5:; lwz 9,0x0(31); mr 4,26; lha 3,0xf8(9); lwz 0,0xfc(9); add 3,31,3; mtspr 8,0; blrl; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s800D00AC_0();
extern "C" void _s800D00AC_1();
extern "C" void _s800D00AC_2();
extern "C" void f_800D00AC() {}
