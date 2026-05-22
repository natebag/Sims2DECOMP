// 0x80253534 OSDisableScheduler (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80253534_0; lwz 4,-23576(13); addi 0,4,1; stw 0,-23576(13); mr 31,4; bl _s80253534_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80253534_0();
extern "C" void _s80253534_1();
extern "C" void f_80253534() {}
