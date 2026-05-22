// 0x802D0D78 EAHeap::Free(void (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,3; mr. 30,4; beq 1f; lwz 3,-21324(13); mr 4,30; bl _s802D0D78_0; mr. 31,3; beq 0f; addi 0,31,24; li 4,-1; stw 0,0x8(1); lwz 9,0x18(31); lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; mr 3,31; mr 4,30; bl _s802D0D78_1; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; mr 3,29; mr 4,30; bl _s802D0D78_2; mr. 3,3; beq 1f; mr 4,30; bl _s802D0D78_3; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802D0D78_0();
extern "C" void _s802D0D78_1();
extern "C" void _s802D0D78_2();
extern "C" void _s802D0D78_3();
extern "C" void f_802D0D78() {}
