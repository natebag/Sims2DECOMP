// 0x802D202C operator>>(EStream (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0x18(31); addi 4,1,8; li 5,4; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; lwz 4,0x8(1); cmpwi 4,0; beq 1f; lwz 0,0x0(31); cmpwi 0,0; beq 0f; lwz 0,0x14(31); rlwinm 9,4,2,0,29; add 9,9,0; lwz 11,-4(9); stw 11,0x0(30); b 2f; 0:; mr 3,31; bl _s802D202C_0; stw 3,0x0(30); b 2f; 1:; stw 4,0x0(30); 2:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D202C_0();
extern "C" void f_802D202C() {}
