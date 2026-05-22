// 0x802C4B5C AptCharacterButtonInst::AptCharacterButtonInst(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32702; mr 30,3; li 0,0; addi 9,9,-13024; li 11,-1; stw 0,0xc(30); stw 11,0x0(30); addi 3,30,28; stw 9,0x14(30); stw 0,0x10(30); stw 0,0x8(30); bl _s802C4B5C_0; lwz 3,-23020(13); li 4,20; bl _s802C4B5C_1; li 4,4; bl _s802C4B5C_2; stw 3,0xc(30); mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C4B5C_0();
extern "C" void _s802C4B5C_1();
extern "C" void _s802C4B5C_2();
extern "C" void f_802C4B5C() {}
