// 0x80169BB4 CasSimDescriptionS2C::SwitchInnerLayerSleeveToFirstAvailableStyle(CasSimPartsS2C (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 0,3; mr 30,4; addi 3,1,8; li 5,8; stw 0,0xa0(31); mr 4,31; bl _s80169BB4_0; lbz 5,0x98(31); mr 3,30; li 4,8; addi 6,1,8; extsb 5,5; bl _s80169BB4_1; cmpwi 3,0; bne 0f; li 0,2; addi 3,1,8; li 5,8; stw 0,0xa0(31); mr 4,31; bl _s80169BB4_2; lbz 5,0x98(31); mr 3,30; li 4,8; addi 6,1,8; extsb 5,5; bl _s80169BB4_3; cmpwi 3,0; bne 0f; li 0,1; addi 3,1,8; li 5,8; stw 0,0xa0(31); mr 4,31; bl _s80169BB4_4; lbz 5,0x98(31); mr 3,30; li 4,8; addi 6,1,8; extsb 5,5; bl _s80169BB4_5; mr. 3,3; bne 0f; stw 3,0xa0(31); li 5,8; addi 3,1,8; mr 4,31; bl _s80169BB4_6; lbz 5,0x98(31); mr 3,30; li 4,8; addi 6,1,8; extsb 5,5; bl _s80169BB4_7; 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80169BB4_0();
extern "C" void _s80169BB4_1();
extern "C" void _s80169BB4_2();
extern "C" void _s80169BB4_3();
extern "C" void _s80169BB4_4();
extern "C" void _s80169BB4_5();
extern "C" void _s80169BB4_6();
extern "C" void _s80169BB4_7();
extern "C" void f_80169BB4() {}
