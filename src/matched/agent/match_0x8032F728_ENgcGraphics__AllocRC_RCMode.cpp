// 0x8032F728 ENgcGraphics::AllocRC(RCMode) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); cmpwi 4,1; bne 0f; li 3,116; bl _s8032F728_0; bl _s8032F728_1; b 2f; 0:; lwz 0,-22556(13); cmpwi 0,0; bne 1f; lis 3,-32692; addi 3,3,28320; bl _s8032F728_2; li 0,1; lis 3,-32717; stw 0,-22556(13); addi 3,3,-2308; bl _s8032F728_3; 1:; lis 3,-32692; addi 3,3,28320; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8032F728_0();
extern "C" void _s8032F728_1();
extern "C" void _s8032F728_2();
extern "C" void _s8032F728_3();
extern "C" void f_8032F728() {}
