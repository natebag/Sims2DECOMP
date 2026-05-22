// 0x8018155C UIButtonImages::AddRefAll(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lis 28,-32692; addi 29,30,52; mr 31,30; 0:; lwz 4,0x0(31); addi 3,28,-17444; addi 31,31,4; bl _s8018155C_0; cmpw 31,29; ble 0b; li 0,1; stw 0,0xa8(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8018155C_0();
extern "C" void f_8018155C() {}
