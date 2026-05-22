// 0x8037E464 DSPAddTask (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s8037E464_0; addi 31,3,0; addi 3,30,0; bl _s8037E464_1; li 0,0; stw 0,0x0(30); li 0,1; addi 3,31,0; stw 0,0x8(30); bl _s8037E464_2; lwz 0,-22020(13); cmplw 30,0; bne 0f; mr 3,30; bl _s8037E464_3; 0:; mr 3,30; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037E464_0();
extern "C" void _s8037E464_1();
extern "C" void _s8037E464_2();
extern "C" void _s8037E464_3();
extern "C" void f_8037E464() {}
