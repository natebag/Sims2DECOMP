// 0x8016A09C CasSimDescriptionS2C::SwitchOuterLayerCollarToFirstAvailableStyle(CasSimPartsS2C (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 0,0; mr 30,4; addi 3,1,8; li 5,13; stw 0,0xbc(31); mr 4,31; bl _s8016A09C_0; lbz 5,0xb4(31); mr 3,30; li 4,13; addi 6,1,8; extsb 5,5; bl _s8016A09C_1; cmpwi 3,0; bne 0f; li 0,1; addi 3,1,8; li 5,13; stw 0,0xbc(31); mr 4,31; bl _s8016A09C_2; lbz 5,0xb4(31); mr 3,30; li 4,13; addi 6,1,8; extsb 5,5; bl _s8016A09C_3; cmpwi 3,0; bne 0f; li 0,2; addi 3,1,8; li 5,13; stw 0,0xbc(31); mr 4,31; bl _s8016A09C_4; lbz 5,0xb4(31); mr 3,30; li 4,13; addi 6,1,8; extsb 5,5; bl _s8016A09C_5; cmpwi 3,0; bne 0f; li 0,3; addi 3,1,8; li 5,13; stw 0,0xbc(31); mr 4,31; bl _s8016A09C_6; lbz 5,0xb4(31); mr 3,30; li 4,13; addi 6,1,8; extsb 5,5; bl _s8016A09C_7; mr. 3,3; bne 0f; stw 3,0xbc(31); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8016A09C_0();
extern "C" void _s8016A09C_1();
extern "C" void _s8016A09C_2();
extern "C" void _s8016A09C_3();
extern "C" void _s8016A09C_4();
extern "C" void _s8016A09C_5();
extern "C" void _s8016A09C_6();
extern "C" void _s8016A09C_7();
extern "C" void f_8016A09C() {}
