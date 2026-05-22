// 0x80362134 operator>>(EStream (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 28,4; lwz 9,0x18(29); li 5,2; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x18(29); addi 4,28,2; li 5,2; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; lwz 9,0x18(29); li 5,4; addi 4,28,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,29,3; blrl; addi 4,28,8; mr 3,29; bl _s80362134_0; mr 30,3; addi 4,28,20; lwz 9,0x18(30); li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x18(30); addi 4,28,24; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,30,3; mtspr 8,0; blrl; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80362134_0();
extern "C" void f_80362134() {}
