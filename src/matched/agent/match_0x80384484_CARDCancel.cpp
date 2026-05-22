// 0x80384484 CARDCancel (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s80384484_0; lwz 0,0x0(30); lis 4,-32688; li 31,0; mulli 5,0,272; addi 0,4,-24000; add 4,0,5; lwz 0,0x0(4); cmpwi 0,0; bne 0f; li 31,-3; b 1f; 0:; lwz 0,0x4(4); cmpwi 0,-1; bne 1f; lwz 0,0xc0(4); cmplw 0,30; bne 1f; li 0,-1; stw 0,0xc(30); li 31,-14; 1:; bl _s80384484_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80384484_0();
extern "C" void _s80384484_1();
extern "C" void f_80384484() {}
