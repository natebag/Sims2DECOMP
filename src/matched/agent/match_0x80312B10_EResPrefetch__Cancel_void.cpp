// 0x80312B10 EResPrefetch::Cancel(void) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 29,0x3c(1); stw 0,0x4c(1); addi 30,1,8; mr 29,3; mr 3,30; bl _s80312B10_0; li 4,1; li 5,0; mr 3,30; bl _s80312B10_1; li 0,0; li 9,-1; addi 4,1,32; stw 0,0x28(1); stw 9,0x24(1); li 5,1; stw 30,0x30(1); addi 3,29,908; stw 0,0x20(1); stw 0,0x2c(1); bl _s80312B10_2; li 4,-1; mr 3,30; bl _s80312B10_3; mr 3,30; bl _s80312B10_4; mr 3,30; li 4,2; bl _s80312B10_5; lwz 0,0x4c(1); mtspr 8,0; lmw 29,0x3c(1); addi 1,1,72"
extern "C" void _s80312B10_0();
extern "C" void _s80312B10_1();
extern "C" void _s80312B10_2();
extern "C" void _s80312B10_3();
extern "C" void _s80312B10_4();
extern "C" void _s80312B10_5();
extern "C" void f_80312B10() {}
