// 0x8024C1F0 OSSetPeriodicAlarm (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 26,0x28(1); addi 26,3,0; addi 28,5,0; addi 27,6,0; addi 29,7,0; addi 31,8,0; addi 30,9,0; bl _s8024C1F0_0; stw 31,0x1c(26); mr 31,3; addi 4,27,0; stw 29,0x18(26); addi 3,28,0; bl _s8024C1F0_1; stw 4,0x24(26); addi 7,30,0; li 6,0; stw 3,0x20(26); addi 3,26,0; li 5,0; bl _s8024C1F0_2; mr 3,31; bl _s8024C1F0_3; lmw 26,0x28(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8024C1F0_0();
extern "C" void _s8024C1F0_1();
extern "C" void _s8024C1F0_2();
extern "C" void _s8024C1F0_3();
extern "C" void f_8024C1F0() {}
