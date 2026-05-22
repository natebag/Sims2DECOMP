// 0x800E32EC EdithVariableSet::EdithVariableSet(EdithVariableSet (264 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,4; mr 31,3; lwz 0,0x0(29); addi 27,29,12; lwz 9,0x8(29); li 11,0; lwz 10,0x4(29); addi 28,31,12; stw 0,0x0(31); addi 8,31,20; stw 10,0x4(31); stw 9,0x8(31); lwz 0,0x4(27); lwz 9,0xc(29); stw 11,0xc(31); subf 0,9,0; stw 11,0x4(28); srawi. 0,0,1; stw 11,0x4(8); beq 1f; add 0,0,0; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s800E32EC_0; b 2f; 0:; mr 3,30; bl _s800E32EC_1; b 2f; 1:; li 3,0; li 30,0; 2:; add 0,3,30; stw 3,0x0(28); stw 0,0xc(28); stw 3,0x4(28); lwz 30,0x4(27); lwz 4,0x0(27); cmpw 30,4; beq 3f; subf 30,4,30; mr 5,30; bl _s800E32EC_2; add 3,3,30; 3:; stw 3,0x4(28); li 8,8; mtspr 9,8; addi 10,29,30; lbz 0,0x1c(29); addi 11,31,30; li 9,0; stb 0,0x1c(31); 4:; lhzx 0,9,10; sthx 0,9,11; addi 9,9,2; bdnz 4b; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"
extern "C" void _s800E32EC_0();
extern "C" void _s800E32EC_1();
extern "C" void _s800E32EC_2();
extern "C" void f_800E32EC() {}
