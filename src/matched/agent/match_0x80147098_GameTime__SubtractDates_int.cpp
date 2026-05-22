// 0x80147098 GameTime::SubtractDates(int, (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,6; mr 29,7; mr 28,8; bl _s80147098_0; mr 30,3; mr 4,29; mr 3,27; mr 5,28; bl _s80147098_1; subf 3,3,30; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80147098_0();
extern "C" void _s80147098_1();
extern "C" void f_80147098() {}
