// 0x8009BA04 BitArray64::CountBits(void) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; li 30,0; li 31,0; 0:; mr 4,31; mr 3,29; bl _s8009BA04_0; addi 31,31,1; add 30,30,3; cmpwi 31,63; ble 0b; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8009BA04_0();
extern "C" void f_8009BA04() {}
