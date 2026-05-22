// 0x800D03C0 NeighborhoodImpl::GetFamilyInfo(Family (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-808(1); mfspr 0,8; stmw 28,0x318(1); stw 0,0x32c(1); addi 30,1,8; mr 31,4; mr 28,5; mr 29,6; li 5,256; addi 4,30,8; mr 3,30; bl _s800D03C0_0; lwz 9,0x0(31); mr 4,30; lwz 0,0x84(9); lha 3,0x80(9); mtspr 8,0; add 3,31,3; blrl; mr 3,30; bl _s800D03C0_1; mr 30,3; addi 4,1,536; addi 3,1,528; li 5,128; bl _s800D03C0_2; addi 3,1,528; li 5,-1; mr 4,30; bl _s800D03C0_3; addi 4,1,528; mr 3,28; bl _s800D03C0_4; lwz 9,0x0(31); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,31,3; blrl; li 0,0; stw 3,0x108(28); stw 0,0x10c(28); lwz 9,0x0(31); lha 3,0xa8(9); lwz 0,0xac(9); add 3,31,3; mtspr 8,0; blrl; stw 3,0x110(28); cmpwi 29,0; beq 0f; lwz 9,0x0(31); lha 3,0xf0(9); lwz 0,0xf4(9); add 3,31,3; mtspr 8,0; blrl; stw 3,0x10c(28); 0:; li 3,1; lwz 0,0x32c(1); mtspr 8,0; lmw 28,0x318(1); addi 1,1,808"
extern "C" void _s800D03C0_0();
extern "C" void _s800D03C0_1();
extern "C" void _s800D03C0_2();
extern "C" void _s800D03C0_3();
extern "C" void _s800D03C0_4();
extern "C" void f_800D03C0() {}
