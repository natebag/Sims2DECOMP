// 0x802E0670 operator>>(EStream (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 29,4; lwz 9,0x18(30); addi 4,1,8; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 4,0x8(1); li 5,0; mr 3,29; bl _s802E0670_0; mr 3,29; bl _s802E0670_1; lwz 9,0x18(30); rlwinm 5,3,2,0,29; lwz 4,0x0(29); lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s802E0670_0();
extern "C" void _s802E0670_1();
extern "C" void f_802E0670() {}
