// 0x802D2798 operator>>(EStream (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; bl _s802D2798_0; mr 30,3; addi 4,29,12; lwz 9,0x18(30); li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D2798_0();
extern "C" void f_802D2798() {}
