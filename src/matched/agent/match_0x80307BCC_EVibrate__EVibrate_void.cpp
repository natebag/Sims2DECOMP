// 0x80307BCC EVibrate::EVibrate(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; li 0,0; stw 0,0x4(30); li 4,0; li 5,136; stw 0,0x0(30); addi 3,30,8; bl _s80307BCC_0; addi 3,13,-21312; li 4,0; li 5,6; bl _s80307BCC_1; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80307BCC_0();
extern "C" void _s80307BCC_1();
extern "C" void f_80307BCC() {}
