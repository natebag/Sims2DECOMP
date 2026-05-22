// 0x8037163C OSInitMessageQueue (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); addi 31,5,0; stw 30,0x20(1); addi 30,4,0; stw 29,0x1c(1); addi 29,3,0; bl _s8037163C_0; addi 3,29,8; bl _s8037163C_1; stw 30,0x10(29); li 0,0; stw 31,0x14(29); stw 0,0x18(29); stw 0,0x1c(29); lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8037163C_0();
extern "C" void _s8037163C_1();
extern "C" void f_8037163C() {}
