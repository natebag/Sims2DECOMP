// 0x80169D30 CasSimDescriptionS2C::SwitchMidLayerTorsoToFirstAvailableStyle(CasSimPartsS2C (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; mr 30,4; mr. 5,5; beq 0f; li 0,3; addi 3,1,8; li 5,9; stw 0,0xa8(31); mr 4,31; bl _s80169D30_0; lbz 5,0xa4(31); mr 3,30; li 4,9; addi 6,1,8; extsb 5,5; bl _s80169D30_1; cmpwi 3,0; bne 2f; li 29,4; addi 3,1,8; stw 29,0xa8(31); li 5,9; mr 4,31; bl _s80169D30_2; lbz 5,0xa4(31); mr 3,30; li 4,9; addi 6,1,8; extsb 5,5; bl _s80169D30_3; cmpwi 3,0; bne 2f; li 0,5; b 1f; 0:; stw 5,0xa8(31); addi 3,1,8; li 5,9; mr 4,31; bl _s80169D30_4; lbz 5,0xa4(31); mr 3,30; li 4,9; addi 6,1,8; extsb 5,5; bl _s80169D30_5; cmpwi 3,0; bne 2f; li 29,1; addi 3,1,8; stw 29,0xa8(31); li 5,9; mr 4,31; bl _s80169D30_6; lbz 5,0xa4(31); mr 3,30; li 4,9; addi 6,1,8; extsb 5,5; bl _s80169D30_7; cmpwi 3,0; bne 2f; li 0,2; 1:; addi 3,1,8; li 5,9; stw 0,0xa8(31); mr 4,31; bl _s80169D30_8; lbz 5,0xa4(31); mr 3,30; li 4,9; addi 6,1,8; extsb 5,5; bl _s80169D30_9; cmpwi 3,0; bne 2f; stw 29,0xa8(31); 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s80169D30_0();
extern "C" void _s80169D30_1();
extern "C" void _s80169D30_2();
extern "C" void _s80169D30_3();
extern "C" void _s80169D30_4();
extern "C" void _s80169D30_5();
extern "C" void _s80169D30_6();
extern "C" void _s80169D30_7();
extern "C" void _s80169D30_8();
extern "C" void _s80169D30_9();
extern "C" void f_80169D30() {}
