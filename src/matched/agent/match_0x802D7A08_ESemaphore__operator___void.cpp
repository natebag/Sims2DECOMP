// 0x802D7A08 ESemaphore::operator++(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 4,-1; lwz 9,0x0(30); lha 3,0x10(9); lwz 0,0x14(9); add 3,30,3; mtspr 8,0; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_802D7A08() {}
