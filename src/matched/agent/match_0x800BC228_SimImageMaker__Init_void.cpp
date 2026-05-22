// 0x800BC228 SimImageMaker::Init(void) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 3,31; mr 4,28; li 5,1; bl _s800BC228_0; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800BC228_0();
extern "C" int f_800BC228() {}
