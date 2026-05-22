// 0x803075AC ETweak::~ETweak(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; addi 28,29,12; lwz 9,0x4(28); b 2f; 0:; lwz 0,0x8(28); lwz 31,0x0(9); cmpwi 0,0; lwz 30,0x4(9); beq 1f; cmpwi 31,0; beq 1f; mr 3,31; lwzu 4,0x4(3); bl _s803075AC_0; mr 3,31; bl _s803075AC_1; 1:; mr 9,30; 2:; li 0,1; cmpwi 9,0; bne 3f; li 0,0; 3:; cmpwi 0,0; bne 0b; mr 3,28; bl _s803075AC_2; li 5,0; li 6,0; li 4,1; addi 3,29,28; bl _s803075AC_3; li 4,2; addi 3,29,48; bl _s803075AC_4; addi 3,29,36; bl _s803075AC_5; lwz 4,0x20(29); addi 3,29,32; bl _s803075AC_6; lwz 4,0x18(29); addi 3,29,24; bl _s803075AC_7; addi 3,29,12; bl _s803075AC_8; andi. 0,27,1; beq 4f; mr 3,29; bl _s803075AC_9; 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s803075AC_0();
extern "C" void _s803075AC_1();
extern "C" void _s803075AC_2();
extern "C" void _s803075AC_3();
extern "C" void _s803075AC_4();
extern "C" void _s803075AC_5();
extern "C" void _s803075AC_6();
extern "C" void _s803075AC_7();
extern "C" void _s803075AC_8();
extern "C" void _s803075AC_9();
extern "C" void f_803075AC() {}
