// 0x8024C118 OSSetAlarm (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-56(1); stmw 27,0x24(1); addi 27,3,0; addi 29,5,0; addi 28,6,0; addi 30,7,0; bl _s8024C118_0; li 0,0; stw 0,0x1c(27); mr 31,3; stw 0,0x18(27); bl _s8024C118_1; addc 6,28,4; adde 5,29,3; addi 3,27,0; addi 7,30,0; bl _s8024C118_2; mr 3,31; bl _s8024C118_3; lmw 27,0x24(1); lwz 0,0x3c(1); addi 1,1,56; mtspr 8,0"
extern "C" void _s8024C118_0();
extern "C" void _s8024C118_1();
extern "C" void _s8024C118_2();
extern "C" void _s8024C118_3();
extern "C" void f_8024C118() {}
