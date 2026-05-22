// 0x8013FAE8 SimLog::EndLogging(void) (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 23,0xc(1); stw 0,0x34(1); mr 29,3; bl _s8013FAE8_0; addi 9,29,4; lwz 31,0x4(29); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 30,9; 0:; mr 3,31; bl _s8013FAE8_1; addi 31,31,32; lwz 0,0x4(30); cmpw 31,0; bne 0b; 1:; mr 24,29; addi 23,29,20; lwzu 25,0x4(24); lwz 26,0x4(24); mr 3,25; cmpw 25,26; beq 7f; lis 28,-4370; ori 28,28,61167; 2:; addi 11,3,16; lwz 9,0x10(3); lwz 0,0x4(11); addi 27,3,32; addi 31,3,12; addi 30,3,8; cmpw 9,0; beq 4f; 3:; addi 9,9,60; cmpw 9,0; bne 3b; 4:; lwz 3,0x0(11); cmpwi 3,0; beq 6f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,28; srawi 0,0,2; mulli 4,0,60; cmplwi 4,128; ble 5f; bl _s8013FAE8_2; b 6f; 5:; bl _s8013FAE8_3; 6:; mr 3,31; li 4,2; bl _s8013FAE8_4; mr 3,30; li 4,2; bl _s8013FAE8_5; mr 3,27; cmpw 3,26; bne 2b; 7:; stw 25,0x4(24); lwz 11,0x14(29); lwz 0,0x4(23); mr 9,11; cmpw 11,0; beq 9f; 8:; addi 9,9,240; cmpw 9,0; bne 8b; 9:; stw 11,0x4(23); li 0,0; stw 0,0x0(29); lwz 0,0x34(1); mtspr 8,0; lmw 23,0xc(1); addi 1,1,48"
extern "C" void _s8013FAE8_0();
extern "C" void _s8013FAE8_1();
extern "C" void _s8013FAE8_2();
extern "C" void _s8013FAE8_3();
extern "C" void _s8013FAE8_4();
extern "C" void _s8013FAE8_5();
extern "C" void f_8013FAE8() {}
