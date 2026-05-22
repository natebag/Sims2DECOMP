// 0x80261DE8 __DVDLowSetWAType (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); addi 30,3,0; bl _s80261DE8_0; stw 30,-23324(13); stw 31,-23320(13); bl _s80261DE8_1; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80261DE8_0();
extern "C" void _s80261DE8_1();
extern "C" void f_80261DE8() {}
