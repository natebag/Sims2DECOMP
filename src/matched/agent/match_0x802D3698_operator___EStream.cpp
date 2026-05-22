// 0x802D3698 operator>>(EStream (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-1048(1); mfspr 0,8; stmw 29,0x40c(1); stw 0,0x41c(1); mr 30,3; mr 29,4; lwz 9,0x18(30); addi 4,1,8; li 5,1024; lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr 3,29; addi 4,1,8; bl _s802D3698_0; mr 3,30; lwz 0,0x41c(1); mtspr 8,0; lmw 29,0x40c(1); addi 1,1,1048"
extern "C" void _s802D3698_0();
extern "C" void f_802D3698() {}
