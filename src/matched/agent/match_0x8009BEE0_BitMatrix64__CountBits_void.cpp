// 0x8009BEE0 BitMatrix64::CountBits(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; li 30,0; addi 29,31,504; 0:; mr 3,31; bl _s8009BEE0_0; addi 31,31,8; add 30,30,3; cmpw 31,29; ble 0b; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009BEE0_0();
extern "C" void f_8009BEE0() {}
