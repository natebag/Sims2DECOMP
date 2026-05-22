// 0x803AD1A8 SimLog::~SimLog(void) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 25,3; mr 24,4; addi 11,25,20; lwz 9,0x14(25); lwz 0,0x4(11); cmpw 9,0; beq 1f; 0:; addi 9,9,240; cmpw 9,0; bne 0b; 1:; lwz 3,0x0(11); cmpwi 3,0; beq 3f; lwz 0,0xc(11); lis 9,-4370; ori 9,9,61167; subf 0,3,0; mullw 0,0,9; srawi 0,0,4; mulli 4,0,240; cmplwi 4,128; ble 2f; bl _s803AD1A8_0; b 3f; 2:; bl _s803AD1A8_1; 3:; addi 26,25,4; lwz 3,0x4(25); lwz 27,0x4(26); cmpw 3,27; beq 9f; lis 29,-4370; ori 29,29,61167; 4:; addi 11,3,16; lwz 9,0x10(3); lwz 0,0x4(11); addi 28,3,32; addi 31,3,12; addi 30,3,8; cmpw 9,0; beq 6f; 5:; addi 9,9,60; cmpw 9,0; bne 5b; 6:; lwz 3,0x0(11); cmpwi 3,0; beq 8f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,29; srawi 0,0,2; mulli 4,0,60; cmplwi 4,128; ble 7f; bl _s803AD1A8_2; b 8f; 7:; bl _s803AD1A8_3; 8:; mr 3,31; li 4,2; bl _s803AD1A8_4; mr 3,30; li 4,2; bl _s803AD1A8_5; mr 3,28; cmpw 3,27; bne 4b; 9:; lwz 3,0x0(26); cmpwi 3,0; beq 11f; lwz 0,0xc(26); subf 0,3,0; rlwinm 4,0,0,0,26; cmplwi 4,128; ble 10f; bl _s803AD1A8_6; b 11f; 10:; bl _s803AD1A8_7; 11:; andi. 0,24,1; beq 12f; mr 3,25; bl _s803AD1A8_8; 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"
extern "C" void _s803AD1A8_0();
extern "C" void _s803AD1A8_1();
extern "C" void _s803AD1A8_2();
extern "C" void _s803AD1A8_3();
extern "C" void _s803AD1A8_4();
extern "C" void _s803AD1A8_5();
extern "C" void _s803AD1A8_6();
extern "C" void _s803AD1A8_7();
extern "C" void _s803AD1A8_8();
extern "C" void f_803AD1A8() {}
