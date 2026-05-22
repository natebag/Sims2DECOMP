// 0x800D0520 NeighborhoodImpl::GetHouseInfo(NghResFile (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,5; mr 29,3; addi 0,28,-1; mr 31,4; mr 30,6; cmplwi 0,15; li 3,0; bgt 3f; mr 3,31; mr 4,28; bl _s800D0520_0; mr 4,31; mr 3,29; mr 5,30; bl _s800D0520_1; cmpwi 3,0; bne 0f; li 3,0; b 3f; 0:; lwz 9,0x0(29); mr 4,28; lha 3,0x128(9); lwz 0,0x12c(9); add 3,29,3; mtspr 8,0; blrl; mr. 11,3; beq 1f; lwz 9,0x0(11); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; mr 0,3; addi 5,30,20; mr 3,29; mr 4,0; stw 0,0x10(30); bl _s800D0520_2; b 2f; 1:; li 0,-1; stw 0,0x10(30); 2:; stw 28,0x128(30); li 3,1; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800D0520_0();
extern "C" void _s800D0520_1();
extern "C" void _s800D0520_2();
extern "C" void f_800D0520() {}
