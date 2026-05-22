// 0x8009BE40 BitMatrix64::operator<<=(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; addi 29,30,504; mr 31,30; 0:; mr 3,31; mr 4,28; bl _s8009BE40_0; addi 31,31,8; cmpw 31,29; ble 0b; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8009BE40_0();
extern "C" void f_8009BE40() {}
