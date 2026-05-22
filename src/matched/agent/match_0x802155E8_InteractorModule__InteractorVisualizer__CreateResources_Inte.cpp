// 0x802155E8 InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::WallManipulator (404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 30,0x40(1); stw 0,0x4c(1); mr 30,4; bl _s802155E8_0; mr. 31,3; li 3,0; beq 1f; lis 4,1287; mr 3,31; ori 4,4,9753; bl _s802155E8_1; lis 4,-15727; mr 3,31; ori 4,4,35298; bl _s802155E8_2; lis 4,5437; mr 3,31; ori 4,4,19514; bl _s802155E8_3; lis 4,-30309; mr 3,31; ori 4,4,41963; bl _s802155E8_4; lis 4,15177; mr 3,31; ori 4,4,19820; bl _s802155E8_5; lis 4,-31611; mr 3,31; ori 4,4,13842; bl _s802155E8_6; lis 4,29114; mr 3,31; ori 4,4,11930; bl _s802155E8_7; lis 4,30212; mr 3,31; ori 4,4,49507; bl _s802155E8_8; lis 9,-32704; li 0,0; lfs f0,-10456(9); addi 4,1,8; stw 0,0x8(1); lis 11,-32735; stw 0,0x4(4); addi 11,11,29436; stw 0,0x8(4); lis 8,-32696; stw 0,0xc(4); stw 0,0x10(4); stw 0,0x14(4); stw 0,0x18(4); stw 0,0x1c(4); stw 0,0x20(4); stw 0,0x24(4); stw 0,0x34(4); stfs f0,0x30(4); stw 0,0x28(4); stfs f0,0x2c(4); lwz 9,-23840(13); lwz 10,0x0(30); stw 0,0x8(1); cmpwi 9,0; stw 0,0x4(4); stw 0,0x8(4); stw 0,0xc(4); stw 0,0x10(4); stw 0,0x14(4); stw 0,0x18(4); stw 0,0x1c(4); stw 0,0x20(4); stw 0,0x24(4); stw 0,0x34(4); stw 0,0x8(1); stw 11,0x1c(1); stw 10,0x20(1); bne 0f; lis 9,-32704; li 0,1; lfs f0,-10452(9); addi 11,8,32248; stw 0,-23840(13); stfs f0,0x7df8(8); stfs f0,0x4(11); stfs f0,0x8(11); 0:; lis 9,-32696; li 0,1; addi 9,9,32248; mr 3,31; stw 9,0x10(1); stw 0,0x24(1); bl _s802155E8_9; li 3,1; 1:; lwz 0,0x4c(1); mtspr 8,0; lmw 30,0x40(1); addi 1,1,72"
extern "C" void _s802155E8_0();
extern "C" void _s802155E8_1();
extern "C" void _s802155E8_2();
extern "C" void _s802155E8_3();
extern "C" void _s802155E8_4();
extern "C" void _s802155E8_5();
extern "C" void _s802155E8_6();
extern "C" void _s802155E8_7();
extern "C" void _s802155E8_8();
extern "C" void _s802155E8_9();
extern "C" void f_802155E8() {}
