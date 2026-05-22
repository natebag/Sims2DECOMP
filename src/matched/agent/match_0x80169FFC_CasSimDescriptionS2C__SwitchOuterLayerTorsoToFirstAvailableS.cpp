// 0x80169FFC CasSimDescriptionS2C::SwitchOuterLayerTorsoToFirstAvailableStyle(CasSimPartsS2C (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 31,3; li 0,0; mr 30,4; addi 3,1,8; li 5,12; stw 0,0xb8(31); mr 4,31; bl _s80169FFC_0; lbz 5,0xb4(31); mr 3,30; li 4,12; addi 6,1,8; extsb 5,5; bl _s80169FFC_1; cmpwi 3,0; bne 0f; li 0,1; addi 3,1,8; li 5,12; stw 0,0xb8(31); mr 4,31; bl _s80169FFC_2; lbz 5,0xb4(31); mr 3,30; li 4,12; addi 6,1,8; extsb 5,5; bl _s80169FFC_3; mr. 3,3; bne 0f; stw 3,0xb8(31); 0:; lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s80169FFC_0();
extern "C" void _s80169FFC_1();
extern "C" void _s80169FFC_2();
extern "C" void _s80169FFC_3();
extern "C" void f_80169FFC() {}
