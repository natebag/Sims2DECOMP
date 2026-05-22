// 0x80261034 SetTimeoutAlarm (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 5,-32694; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,5,-16848; stw 30,0x18(1); addi 30,3,0; addi 3,31,0; stw 29,0x14(1); addi 29,4,0; bl _s80261034_0; lis 3,-32730; addi 7,3,4036; addi 3,31,0; addi 6,29,0; addi 5,30,0; bl _s80261034_1; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s80261034_0();
extern "C" void _s80261034_1();
extern "C" void f_80261034() {}
