// 0x803630A0 EDL::~EDL(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lis 9,-32697; mr 31,3; addi 9,9,-10040; mr 29,4; stw 9,0x64(31); addi 3,31,60; bl _s803630A0_0; addi 30,31,24; addi 3,31,48; bl _s803630A0_1; mr 3,30; bl _s803630A0_2; mr 3,30; bl _s803630A0_3; mr 3,31; bl _s803630A0_4; mr 3,31; bl _s803630A0_5; andi. 0,29,1; beq 0f; mr 3,31; bl _s803630A0_6; 0:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803630A0_0();
extern "C" void _s803630A0_1();
extern "C" void _s803630A0_2();
extern "C" void _s803630A0_3();
extern "C" void _s803630A0_4();
extern "C" void _s803630A0_5();
extern "C" void _s803630A0_6();
extern "C" void f_803630A0() {}
