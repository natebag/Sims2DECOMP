// 0x8016F720 CasSimRenderer::CreateFaceImage(unsigned (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-584(1); mfspr 0,8; stmw 25,0x22c(1); stw 0,0x24c(1); mr 30,3; mr 26,7; addi 3,1,8; mr 25,8; mr 28,5; mr 27,6; mr 29,4; mr 31,3; bl _s8016F720_0; lwz 3,0x0(30); bl _s8016F720_1; lwz 4,0x84(3); addi 3,1,8; bl _s8016F720_2; addi 3,1,8; addi 4,30,8; bl _s8016F720_3; mr 4,29; mr 5,28; mr 6,27; addi 3,1,8; bl _s8016F720_4; stw 26,0xc(31); cmpwi 25,0; beq 0f; mr 4,25; mr 3,31; bl _s8016F720_5; 0:; mr 3,31; bl _s8016F720_6; mr 30,3; li 4,2; mr 3,31; bl _s8016F720_7; mr 3,30; lwz 0,0x24c(1); mtspr 8,0; lmw 25,0x22c(1); addi 1,1,584"
extern "C" void _s8016F720_0();
extern "C" void _s8016F720_1();
extern "C" void _s8016F720_2();
extern "C" void _s8016F720_3();
extern "C" void _s8016F720_4();
extern "C" void _s8016F720_5();
extern "C" void _s8016F720_6();
extern "C" void _s8016F720_7();
extern "C" void f_8016F720() {}
