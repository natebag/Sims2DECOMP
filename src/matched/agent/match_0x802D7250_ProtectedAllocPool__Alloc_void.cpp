// 0x802D7250 ProtectedAllocPool::Alloc(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; addi 0,30,24; lwz 9,0x18(30); stw 0,0x8(1); lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; mr 3,30; bl _s802D7250_0; lwz 11,0x8(1); mr 30,3; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s802D7250_0();
extern "C" void f_802D7250() {}
