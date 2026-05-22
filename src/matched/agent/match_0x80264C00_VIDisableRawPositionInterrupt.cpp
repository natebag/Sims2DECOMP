// 0x80264C00 __VIDisableRawPositionInterrupt (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-16(1); stw 31,0xc(1); bl _s80264C00_0; lis 4,-13312; addi 4,4,8192; li 0,0; sth 0,0x38(4); sth 0,0x3c(4); lwz 31,-23260(13); stw 0,-23260(13); bl _s80264C00_1; mr 3,31; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s80264C00_0();
extern "C" void _s80264C00_1();
extern "C" void f_80264C00() {}
