// 0x803371F8 CreateReadThread(long) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 8,3; lis 4,-32717; lis 3,-32691; lis 6,-32691; addi 3,3,15336; addi 4,4,29460; addi 6,6,20224; li 5,0; li 7,4096; li 9,1; bl _s803371F8_0; cmpwi 3,0; beq 0f; lis 3,-32691; lis 4,-32691; addi 3,3,15120; addi 4,4,15216; li 5,10; bl _s803371F8_1; lis 3,-32691; lis 4,-32691; addi 3,3,15152; addi 4,4,15256; li 5,10; bl _s803371F8_2; lis 3,-32691; lis 4,-32691; addi 3,3,15184; addi 4,4,15296; li 5,10; bl _s803371F8_3; li 0,1; li 3,1; stw 0,-26368(13); b 1f; 0:; li 3,0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s803371F8_0();
extern "C" void _s803371F8_1();
extern "C" void _s803371F8_2();
extern "C" void _s803371F8_3();
extern "C" void f_803371F8() {}
