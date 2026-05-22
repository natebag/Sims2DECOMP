// 0x80005448 ESimsApp::UpdateCheats(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,-26524(13); cmpwi 31,0; beq 0f; li 4,0; mr 3,31; bl _s80005448_0; mr 4,3; mr 3,31; bl _s80005448_1; mr. 31,3; beq 0f; mr 3,31; li 4,-1; bl _s80005448_2; cmpwi 3,0; beq 0f; lis 3,-32697; mr 4,31; addi 3,3,-7712; bl _s80005448_3; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80005448_0();
extern "C" void _s80005448_1();
extern "C" void _s80005448_2();
extern "C" void _s80005448_3();
extern "C" void f_80005448() {}
