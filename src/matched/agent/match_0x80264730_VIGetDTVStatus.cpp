// 0x80264730 VIGetDTVStatus (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80264730_0; lis 4,-13312; lhz 0,0x206e(4); rlwinm 31,0,0,30,31; bl _s80264730_1; rlwinm 3,31,0,31,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80264730_0();
extern "C" void _s80264730_1();
extern "C" void f_80264730() {}
