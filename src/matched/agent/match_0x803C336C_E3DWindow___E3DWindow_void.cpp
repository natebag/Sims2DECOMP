// 0x803C336C E3DWindow::~E3DWindow(void) (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,4; mr 31,3; li 4,0; bl _s803C336C_0; andi. 0,30,1; beq 0f; bl _s803C336C_1; mr 4,31; bl _s803C336C_2; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s803C336C_0();
extern "C" void _s803C336C_1();
extern "C" void _s803C336C_2();
extern "C" void f_803C336C() {}
