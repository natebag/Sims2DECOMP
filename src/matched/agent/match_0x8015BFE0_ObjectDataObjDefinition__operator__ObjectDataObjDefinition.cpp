// 0x8015BFE0 ObjectDataObjDefinition::operator=(ObjectDataObjDefinition (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); mr 28,3; addi 30,1,8; mr 29,4; bl _s8015BFE0_0; lwz 0,0x1c(29); li 5,64; addi 4,30,8; mr 3,30; stw 0,0x1c(28); bl _s8015BFE0_1; lwz 9,0x0(29); mr 4,30; lha 3,0x20(9); lwz 0,0x24(9); add 3,29,3; mtspr 8,0; blrl; mr 4,30; mr 3,28; bl _s8015BFE0_2; mr 3,29; bl _s8015BFE0_3; mr 4,3; mr 3,28; bl _s8015BFE0_4; mr 3,28; lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s8015BFE0_0();
extern "C" void _s8015BFE0_1();
extern "C" void _s8015BFE0_2();
extern "C" void _s8015BFE0_3();
extern "C" void _s8015BFE0_4();
extern "C" void f_8015BFE0() {}
