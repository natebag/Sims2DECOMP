// 0x80010CF0 AptViewer::UnLoad(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x350(31); cmpwi 0,0; beq 0f; lis 3,-32707; lis 4,-32707; addi 4,4,-9796; addi 3,3,-9800; bl _s80010CF0_0; li 3,500; bl _s80010CF0_1; li 3,500; bl _s80010CF0_2; li 3,500; bl _s80010CF0_3; li 3,500; bl _s80010CF0_4; li 3,500; bl _s80010CF0_5; li 0,0; stw 0,0x350(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80010CF0_0();
extern "C" void _s80010CF0_1();
extern "C" void _s80010CF0_2();
extern "C" void _s80010CF0_3();
extern "C" void _s80010CF0_4();
extern "C" void _s80010CF0_5();
extern "C" void f_80010CF0() {}
