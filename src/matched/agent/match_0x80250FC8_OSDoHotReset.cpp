// 0x80250FC8 __OSDoHotReset (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s80250FC8_0; lis 3,-13312; addi 3,3,8192; li 0,0; sth 0,0x2(3); bl _s80250FC8_1; rlwinm 3,31,3,0,28; bl _s80250FC8_2; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80250FC8_0();
extern "C" void _s80250FC8_1();
extern "C" void _s80250FC8_2();
extern "C" void f_80250FC8() {}
