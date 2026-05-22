// 0x803AD30C LogInteraction::LogInteraction(LogInteraction (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,4; mr 31,3; lwz 0,0x0(30); addi 4,30,8; li 5,0; li 6,-1; stw 0,0x0(31); addi 3,31,8; addi 29,30,16; addi 28,31,16; lwz 0,0x4(30); stw 0,0x4(31); bl _s803AD30C_0; addi 3,31,12; addi 4,30,12; li 5,0; li 6,-1; bl _s803AD30C_1; lwz 8,0x10(30); lis 11,-4370; lwz 0,0x4(29); ori 11,11,61167; li 9,0; addi 10,31,24; subf 0,8,0; stw 9,0x10(31); mullw 0,0,11; stw 9,0x4(28); stw 9,0x4(10); srawi. 0,0,2; beq 1f; mulli 0,0,60; mr 30,0; cmplwi 0,128; ble 0f; mr 3,30; bl _s803AD30C_2; b 2f; 0:; mr 3,30; bl _s803AD30C_3; b 2f; 1:; li 3,0; li 30,0; 2:; add 0,3,30; stw 3,0x0(28); stw 0,0xc(28); mr 10,3; stw 3,0x4(28); lwz 7,0x4(29); lwz 30,0x0(29); cmpw 30,7; beq 5f; 3:; mr 11,10; mr 9,30; addi 30,9,60; addi 8,11,60; li 10,48; 4:; lwz 0,0x0(9); addic. 10,10,-24; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); lwz 0,0xc(9); stw 0,0xc(11); lwz 0,0x10(9); stw 0,0x10(11); lwz 0,0x14(9); addi 9,9,24; stw 0,0x14(11); addi 11,11,24; bne 4b; lwz 0,0x0(9); mr 10,8; cmpw 30,7; stw 0,0x0(11); lwz 0,0x4(9); stw 0,0x4(11); lwz 0,0x8(9); stw 0,0x8(11); bne 3b; 5:; stw 10,0x4(28); mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803AD30C_0();
extern "C" void _s803AD30C_1();
extern "C" void _s803AD30C_2();
extern "C" void _s803AD30C_3();
extern "C" void f_803AD30C() {}
