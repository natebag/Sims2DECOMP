// 0x80312380 EResPrefetch::EResPrefetch(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 30,3; addi 9,9,-19680; addi 3,30,8; stw 9,0x0(30); bl _s80312380_0; lis 9,-32697; lis 11,-32697; addi 9,9,-19760; addi 11,11,-19728; stw 9,0x340(30); addi 3,30,840; stw 11,0x0(30); bl _s80312380_1; addi 3,30,908; bl _s80312380_2; lis 0,-8531; mr 3,30; ori 0,0,48815; stw 0,0x400(30); stw 0,0x3f8(30); stw 0,0x3fc(30); bl _s80312380_3; li 0,0; mr 3,30; stw 0,0x3d8(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80312380_0();
extern "C" void _s80312380_1();
extern "C" void _s80312380_2();
extern "C" void _s80312380_3();
extern "C" void f_80312380() {}
