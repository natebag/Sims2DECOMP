// 0x8016A1AC CasSimDescriptionS2C::SwitchOuterLayerSleeveToFirstAvailableStyle(CasSimPartsS2C (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 0,3; mr 30,4; addi 3,1,8; li 5,14; stw 0,0xc0(31); mr 4,31; bl _s8016A1AC_0; lbz 5,0xb4(31); mr 3,30; li 4,14; addi 6,1,8; extsb 5,5; bl _s8016A1AC_1; cmpwi 3,0; bne 0f; li 0,2; addi 3,1,8; li 5,14; stw 0,0xc0(31); mr 4,31; bl _s8016A1AC_2; lbz 5,0xb4(31); mr 3,30; li 4,14; addi 6,1,8; extsb 5,5; bl _s8016A1AC_3; mr. 3,3; bne 0f; stw 3,0xc0(31); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8016A1AC_0();
extern "C" void _s8016A1AC_1();
extern "C" void _s8016A1AC_2();
extern "C" void _s8016A1AC_3();
extern "C" void f_8016A1AC() {}
