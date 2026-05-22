// 0x8015BF34 ObjectDataObjDefinition::ObjectDataObjDefinition(ObjectDataObjDefinition (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 28,0x50(1); stw 0,0x64(1); lis 9,-32698; mr 30,3; addi 9,9,22840; mr 28,4; stw 9,0x0(30); addi 3,30,4; bl _s8015BF34_0; lwz 0,0x1c(28); addi 29,1,8; li 9,0; li 5,64; addi 4,29,8; stw 0,0x1c(30); stb 9,0x1a(30); mr 3,29; bl _s8015BF34_1; lwz 9,0x0(28); mr 4,29; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,28,3; blrl; mr 4,29; mr 3,30; bl _s8015BF34_2; mr 3,28; bl _s8015BF34_3; mr 4,3; mr 3,30; bl _s8015BF34_4; li 0,0; mr 3,30; stw 0,0x14(30); lwz 0,0x64(1); mtspr 8,0; lmw 28,0x50(1); addi 1,1,96"
extern "C" void _s8015BF34_0();
extern "C" void _s8015BF34_1();
extern "C" void _s8015BF34_2();
extern "C" void _s8015BF34_3();
extern "C" void _s8015BF34_4();
extern "C" void f_8015BF34() {}
