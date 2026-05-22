// 0x8015C06C ObjectDataObjDefinition::operator=(ObjDefinition (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 27,0x54(1); stw 0,0x6c(1); mr 28,3; addi 29,1,8; mr 27,4; bl _s8015C06C_0; stw 27,0x1c(28); lis 30,-32706; addi 30,30,-8144; addi 4,29,8; li 5,64; mr 3,29; bl _s8015C06C_1; li 5,-1; mr 4,30; mr 3,29; bl _s8015C06C_2; mr 4,29; mr 3,28; bl _s8015C06C_3; lha 4,0xbc(27); mr 3,28; bl _s8015C06C_4; mr 3,28; lwz 0,0x6c(1); mtspr 8,0; lmw 27,0x54(1); addi 1,1,104"
extern "C" void _s8015C06C_0();
extern "C" void _s8015C06C_1();
extern "C" void _s8015C06C_2();
extern "C" void _s8015C06C_3();
extern "C" void _s8015C06C_4();
extern "C" void f_8015C06C() {}
