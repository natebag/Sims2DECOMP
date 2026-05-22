// 0x801109A8 ObjSelector::GetCatalogShortName(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 3,4; bl _s801109A8_0; bl _s801109A8_1; mr 4,3; lwz 9,0x0(4); mr 3,30; lha 0,0x28(9); lwz 9,0x2c(9); add 4,4,0; mtspr 8,9; crxor 6,6,6; blrl; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801109A8_0();
extern "C" void _s801109A8_1();
extern "C" void f_801109A8() {}
