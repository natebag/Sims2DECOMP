// 0x80213DE0 InteractorModule::InteractorVisualizer::~InteractorVisualizer(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 28,3; mr 27,4; addi 29,28,8; lwz 31,0x8(28); lwz 30,0x4(29); cmpw 31,30; beq 1f; 0:; addi 3,31,4; li 4,2; bl _s80213DE0_0; addi 31,31,128; cmpw 31,30; bne 0b; 1:; lwz 3,0x0(29); cmpwi 3,0; beq 3f; lwz 0,0xc(29); subf 0,3,0; rlwinm 4,0,0,0,24; cmplwi 4,128; ble 2f; bl _s80213DE0_1; b 3f; 2:; bl _s80213DE0_2; 3:; andi. 0,27,1; beq 4f; mr 3,28; bl _s80213DE0_3; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80213DE0_0();
extern "C" void _s80213DE0_1();
extern "C" void _s80213DE0_2();
extern "C" void _s80213DE0_3();
extern "C" void f_80213DE0() {}
