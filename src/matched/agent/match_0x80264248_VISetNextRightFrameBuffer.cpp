// 0x80264248 VISetNextRightFrameBuffer (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32694; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,-16744; stw 30,0x10(1); addi 30,3,0; bl _s80264248_0; stw 30,0x138(31); li 0,1; addi 30,3,0; stw 0,-23200(13); addi 3,31,240; addi 4,31,292; addi 5,31,296; addi 6,31,316; addi 7,31,320; bl _s80264248_1; mr 3,30; bl _s80264248_2; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s80264248_0();
extern "C" void _s80264248_1();
extern "C" void _s80264248_2();
extern "C" void f_80264248() {}
