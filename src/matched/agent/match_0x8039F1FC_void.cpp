// 0x8039F1FC void (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 28,3; mr 27,4; lwz 9,0x0(28); mr 26,5; lwz 0,0x4(28); addi 4,1,8; li 5,1; mr 3,27; subf 0,9,0; srawi 0,0,2; stw 0,0x8(1); bl _s8039F1FC_0; lwz 4,0x4(28); lwz 0,0x0(28); lwz 5,0x8(1); subf 0,0,4; srawi 9,0,2; cmplw 9,5; bge 0f; li 0,0; subf 5,9,5; stw 0,0xc(1); mr 3,28; addi 6,1,12; bl _s8039F1FC_1; 0:; lwz 0,0x4(28); lwz 9,0x0(28); lwz 11,0x8(1); subf 0,9,0; srawi 0,0,2; cmplw 0,11; ble 5f; 1:; lwz 31,0x4(28); mr 29,31; lwzu 3,-4(29); cmpwi 3,0; beq 2f; li 4,3; bl _s8039F1FC_2; 2:; lwz 30,0x4(28); cmpw 30,31; beq 3f; subf 30,31,30; mr 3,29; mr 4,31; mr 5,30; bl _s8039F1FC_3; add 3,3,30; b 4f; 3:; mr 3,29; 4:; lwz 0,0x0(28); lwz 9,0x8(1); subf 0,0,3; stw 3,0x4(28); srawi 0,0,2; cmplw 0,9; bgt 1b; 5:; lwz 29,0x0(28); lwz 0,0x4(28); cmpw 29,0; beq 12f; li 30,1; 6:; stw 30,0x10(1); lwz 0,0x0(29); cmpwi 0,0; bne 7f; stw 0,0x10(1); 7:; mr 3,27; addi 4,1,16; li 5,1; bl _s8039F1FC_4; lwz 31,0x10(1); cmpwi 31,0; beq 8f; lwz 0,0x0(29); cmpwi 0,0; bne 10f; bl _s8039F1FC_5; li 4,440; li 5,1; li 6,0; bl _s8039F1FC_6; bl _s8039F1FC_7; stw 3,0x0(29); b 9f; 8:; lwz 3,0x0(29); cmpwi 3,0; beq 9f; li 4,3; bl _s8039F1FC_8; stw 31,0x0(29); 9:; lwz 0,0x10(1); cmpwi 0,0; beq 11f; 10:; lwz 3,0x0(29); mr 4,27; mr 5,26; bl _s8039F1FC_9; 11:; lwz 0,0x4(28); addi 29,29,4; cmpw 29,0; bne 6b; 12:; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"
extern "C" void _s8039F1FC_0();
extern "C" void _s8039F1FC_1();
extern "C" void _s8039F1FC_2();
extern "C" void _s8039F1FC_3();
extern "C" void _s8039F1FC_4();
extern "C" void _s8039F1FC_5();
extern "C" void _s8039F1FC_6();
extern "C" void _s8039F1FC_7();
extern "C" void _s8039F1FC_8();
extern "C" void _s8039F1FC_9();
extern "C" void f_8039F1FC() {}
