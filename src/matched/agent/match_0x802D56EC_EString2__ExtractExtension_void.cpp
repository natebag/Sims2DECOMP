// 0x802D56EC EString2::ExtractExtension(void) (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; li 4,46; mr 3,30; bl _s802D56EC_0; mr 31,3; li 4,92; mr 3,30; bl _s802D56EC_1; cmpwi 31,-1; beq 0f; cmpw 31,3; bge 1f; 0:; lis 4,-32702; mr 3,29; addi 4,4,-6888; bl _s802D56EC_2; b 2f; 1:; mr 4,30; addi 5,31,1; mr 3,29; li 6,-1; bl _s802D56EC_3; 2:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D56EC_0();
extern "C" void _s802D56EC_1();
extern "C" void _s802D56EC_2();
extern "C" void _s802D56EC_3();
extern "C" void f_802D56EC() {}
