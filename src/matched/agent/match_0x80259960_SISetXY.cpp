// 0x80259960 SISetXY (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); rlwinm 0,4,8,0,23; stwu 1,-24(1); stw 31,0x14(1); rlwinm 31,3,16,0,15; or 31,31,0; bl _s80259960_0; lis 4,-32700; addi 4,4,-15972; lwz 0,0x4(4); addi 5,4,4; lis 4,-13312; rlwinm 0,0,0,24,5; stw 0,0x0(5); lwz 0,0x0(5); or 0,0,31; stw 0,0x0(5); lwz 31,0x0(5); stw 31,0x6430(4); bl _s80259960_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80259960_0();
extern "C" void _s80259960_1();
extern "C" void f_80259960() {}
