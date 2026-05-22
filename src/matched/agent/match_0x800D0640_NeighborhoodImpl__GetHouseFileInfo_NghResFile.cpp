// 0x800D0640 NeighborhoodImpl::GetHouseFileInfo(NghResFile (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 25,0x14(1); stw 0,0x34(1); li 31,0; mr 26,3; mr 30,4; mr 25,5; mr 28,6; mr 29,7; mr 27,8; stw 31,0x8(1); li 3,0; bl _s800D0640_0; stw 31,0x8(1); bl _s800D0640_1; mr 0,3; lwz 5,-32032(13); lha 6,-32036(13); mr 4,30; stw 0,0x8(1); addi 7,1,12; bl _s800D0640_2; mr. 30,3; beq 0f; lwz 3,0x8(1); bl _s800D0640_3; stw 31,0x8(1); li 3,0; b 4f; 0:; lwz 3,0x8(1); li 4,22; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,1; bne 1f; li 0,0; 1:; stw 0,0x0(29); li 4,26; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,1; bne 2f; li 0,0; 2:; stw 0,0x0(28); cmpwi 0,0; li 0,0; bne 3f; lwz 3,0x8(1); li 4,21; lwz 9,0x0(3); lha 0,0x30(9); lwz 9,0x34(9); add 3,3,0; mtspr 8,9; blrl; subfic 9,3,0; adde 0,9,3; 3:; lwz 4,0x8(1); mr 3,26; stw 0,0x0(27); bl _s800D0640_4; stw 3,0x0(25); lwz 3,0x8(1); bl _s800D0640_5; stw 30,0x8(1); li 3,1; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 25,0x14(1); addi 1,1,48"
extern "C" void _s800D0640_0();
extern "C" void _s800D0640_1();
extern "C" void _s800D0640_2();
extern "C" void _s800D0640_3();
extern "C" void _s800D0640_4();
extern "C" void _s800D0640_5();
extern "C" void f_800D0640() {}
