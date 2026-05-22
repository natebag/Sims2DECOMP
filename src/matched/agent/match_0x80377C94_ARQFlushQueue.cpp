// 0x80377C94 ARQFlushQueue (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-8(1); bl _s80377C94_0; li 0,0; stw 0,-22336(13); stw 0,-22332(13); stw 0,-22328(13); stw 0,-22324(13); bl _s80377C94_1; lwz 0,0xc(1); addi 1,1,8; mtspr 8,0"
extern "C" void _s80377C94_0();
extern "C" void _s80377C94_1();
extern "C" void f_80377C94() {}
