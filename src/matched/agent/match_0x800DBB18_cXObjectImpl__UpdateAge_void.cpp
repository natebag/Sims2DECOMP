// 0x800DBB18 cXObjectImpl::UpdateAge(void) (316 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lwz 11,0x4(3); addi 28,3,40; lwz 9,0x4(11); lwz 0,0x3dc(9); lha 3,0x3d8(9); mtspr 8,0; add 3,11,3; blrl; mr 29,3; li 4,8; lwz 9,0x0(29); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; mr 30,3; li 4,45; mr 3,28; bl _s800DBB18_0; lwz 9,0x0(29); li 4,7; lhz 0,0x0(3); lha 3,0x30(9); lwz 9,0x34(9); subf 30,0,30; add 3,29,3; extsh 31,30; mtspr 8,9; blrl; mr 30,3; li 4,46; mr 3,28; bl _s800DBB18_1; lwz 9,0x0(29); li 4,1; lhz 0,0x0(3); lha 3,0x30(9); lwz 9,0x34(9); subf 30,0,30; add 3,29,3; mtspr 8,9; extsh 29,30; blrl; mr 30,3; li 4,47; mr 3,28; bl _s800DBB18_2; lhz 0,0x0(3); subf 30,0,30; andi. 0,30,32768; beq 0f; addi 0,29,-1; extsh 29,0; 0:; cmpwi 29,0; bge 1f; addi 0,29,12; addi 9,31,-1; extsh 29,0; extsh 31,9; 1:; mr 5,31; li 4,18; mr 3,28; bl _s800DBB18_3; mulli 5,31,12; mr 3,28; li 4,48; add 5,29,5; extsh 5,5; bl _s800DBB18_4; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800DBB18_0();
extern "C" void _s800DBB18_1();
extern "C" void _s800DBB18_2();
extern "C" void _s800DBB18_3();
extern "C" void _s800DBB18_4();
extern "C" void f_800DBB18() {}
