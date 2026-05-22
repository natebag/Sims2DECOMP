// 0x8015C118 ObjectDataObjDefinition::SetOwnDefinition(ObjDefinition (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 31,3; mr 28,4; bl _s8015C118_0; stw 28,0x1c(31); li 0,1; cmpwi 28,0; bne 0f; li 0,0; 0:; addi 29,1,8; lis 30,-32706; stb 0,0x1a(31); addi 30,30,-8124; addi 4,29,8; li 5,64; mr 3,29; bl _s8015C118_1; mr 4,30; mr 3,29; li 5,-1; bl _s8015C118_2; mr 4,29; mr 3,31; bl _s8015C118_3; lha 4,0xbc(28); mr 3,31; bl _s8015C118_4; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s8015C118_0();
extern "C" void _s8015C118_1();
extern "C" void _s8015C118_2();
extern "C" void _s8015C118_3();
extern "C" void _s8015C118_4();
extern "C" void f_8015C118() {}
