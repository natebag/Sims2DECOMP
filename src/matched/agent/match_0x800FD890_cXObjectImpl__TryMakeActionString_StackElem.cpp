// 0x800FD890 cXObjectImpl::TryMakeActionString(StackElem (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 23,0x34(1); stw 0,0x5c(1); mr 27,3; mr 31,4; mr 26,5; bl _s800FD890_0; lwz 24,-31656(13); mr. 23,3; bne 0f; cmpwi 24,0; bne 0f; li 3,0; b 10f; 0:; li 30,0; addi 28,1,16; stw 30,0x8(1); li 3,0; bl _s800FD890_1; mr 25,28; stw 30,0x8(1); bl _s800FD890_2; mr 29,3; stw 29,0x8(1); lwz 30,0x0(29); lwz 3,0x10(31); lha 0,0xf0(30); addi 30,30,240; add 29,29,0; bl _s800FD890_3; lwz 0,0x4(30); mr 4,3; lha 5,0x0(26); mr 3,29; mtspr 8,0; blrl; mr 3,28; bl _s800FD890_4; lwz 11,0x8(1); addi 3,1,24; lbz 5,0x4(26); lwz 9,0x0(11); lwz 0,0x8c(9); lha 4,0x88(9); mtspr 8,0; add 4,11,4; crxor 6,6,6; blrl; lwz 9,0x18(1); li 0,0; cmpwi 7,9,0; beq cr7,1f; lwz 0,0x0(9); 1:; cmpwi 0,0; beq 3f; li 4,0; beq cr7,2f; lwz 4,0x0(9); 2:; mr 3,25; bl _s800FD890_5; 3:; li 9,0; lwz 11,0x4(27); li 10,0; addi 6,1,32; stw 9,0x20(1); stw 10,0x24(1); mr 4,25; mr 5,31; addi 7,1,40; lwz 9,0x4(11); li 8,0; mr 29,6; lha 3,0x108(9); lwz 0,0x10c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 23,0; beq 6f; lha 0,0x20(1); cmpwi 0,0; bne 5f; cmpwi 31,0; beq 4f; lhz 0,0x4(31); sth 0,0x20(1); b 5f; 4:; sth 31,0x20(1); 5:; mr 3,25; bl _s800FD890_6; lwz 11,0x4(27); mr 30,3; li 4,50; lwz 9,0x4(11); lha 3,0x260(9); lwz 0,0x264(9); add 3,11,3; mtspr 8,0; blrl; mr 6,3; mr 4,29; mr 3,30; mr 5,31; bl _s800FD890_7; b 9f; 6:; cmpwi 24,0; beq 9f; cmpwi 27,0; beq 7f; lwz 9,0x4(27); li 4,7; lwz 3,0x0(9); bl _s800FD890_8; b 8f; 7:; li 3,0; 8:; cmpwi 3,0; beq 9f; mr 4,25; bl _s800FD890_9; 9:; li 4,2; mr 3,25; bl _s800FD890_10; lwz 3,0x8(1); bl _s800FD890_11; li 0,0; li 3,0; stw 0,0x8(1); 10:; li 4,1; lwz 0,0x5c(1); mtspr 8,0; lmw 23,0x34(1); addi 1,1,88"
extern "C" void _s800FD890_0();
extern "C" void _s800FD890_1();
extern "C" void _s800FD890_2();
extern "C" void _s800FD890_3();
extern "C" void _s800FD890_4();
extern "C" void _s800FD890_5();
extern "C" void _s800FD890_6();
extern "C" void _s800FD890_7();
extern "C" void _s800FD890_8();
extern "C" void _s800FD890_9();
extern "C" void _s800FD890_10();
extern "C" void _s800FD890_11();
extern "C" void f_800FD890() {}
