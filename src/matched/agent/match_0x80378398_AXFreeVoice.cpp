// 0x80378398 AXFreeVoice (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80378398_0; addi 31,3,0; addi 3,30,0; bl _s80378398_1; lhz 0,0x146(30); cmplwi 0,1; bne 0f; li 0,1; stw 0,0x20(30); 0:; mr 3,30; bl _s80378398_2; lis 3,-32690; addi 5,3,-3232; lwz 4,0x0(5); li 0,0; addi 3,31,0; stw 4,0x0(30); stw 30,0x0(5); stw 0,0xc(30); bl _s80378398_3; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80378398_0();
extern "C" void _s80378398_1();
extern "C" void _s80378398_2();
extern "C" void _s80378398_3();
extern "C" void f_80378398() {}
