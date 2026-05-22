// 0x80214E80 InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::WallPainter (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); bl _s80214E80_0; mr. 31,3; li 3,0; beq 0f; lis 4,-10799; mr 3,31; ori 4,4,32328; bl _s80214E80_1; lis 4,-16025; mr 3,31; ori 4,4,50249; bl _s80214E80_2; lis 4,26001; mr 3,31; ori 4,4,43216; bl _s80214E80_3; lis 4,-31611; mr 3,31; ori 4,4,13842; bl _s80214E80_4; lis 4,15177; mr 3,31; ori 4,4,19820; bl _s80214E80_5; lis 4,-5607; mr 3,31; ori 4,4,1515; bl _s80214E80_6; li 3,1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80214E80_0();
extern "C" void _s80214E80_1();
extern "C" void _s80214E80_2();
extern "C" void _s80214E80_3();
extern "C" void _s80214E80_4();
extern "C" void _s80214E80_5();
extern "C" void _s80214E80_6();
extern "C" void f_80214E80() {}
