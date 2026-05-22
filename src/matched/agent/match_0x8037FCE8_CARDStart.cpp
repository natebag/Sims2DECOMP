// 0x8037FCE8 __CARDStart (548 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 27,0x1c(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; bl _s8037FCE8_0; mulli 5,27,272; lis 4,-32688; addi 0,4,-24000; add 31,0,5; lwz 0,0x0(31); addi 30,3,0; cmpwi 0,0; bne 0f; li 29,-3; b 10f; 0:; cmplwi 28,0; beq 1f; stw 28,0xc8(31); 1:; cmplwi 29,0; beq 2f; stw 29,0xcc(31); 2:; lis 3,-32712; addi 0,3,-1064; lis 3,-32712; stw 0,0xdc(31); addi 5,3,-3584; addi 3,27,0; li 4,0; bl _s8037FCE8_1; cmpwi 3,0; bne 3f; li 29,-1; b 10f; 3:; li 29,0; stw 29,0xdc(31); addi 3,27,0; li 4,0; li 5,4; bl _s8037FCE8_2; cmpwi 3,0; bne 4f; mr 3,27; bl _s8037FCE8_3; li 29,-3; b 10f; 4:; addi 3,31,224; bl _s8037FCE8_4; lbz 0,0x94(31); cmpwi 0,243; beq 9f; bge 5f; cmpwi 0,241; beq 8f; bge 6f; b 9f; 5:; cmpwi 0,245; bge 9f; b 7f; 6:; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32712; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,100; addi 7,3,-2264; addi 3,31,224; li 5,0; bl _s8037FCE8_5; b 9f; 7:; lhz 0,0xa(31); cmplwi 0,128; ble 8f; lis 3,-32768; lhz 4,0x10(31); lwz 3,0xf8(3); li 0,2; srawi 9,4,6; rlwinm 3,3,30,2,31; mullw 8,29,0; mulhwu 6,3,0; add 8,8,6; mullw 5,3,0; addze 9,9; srawi 0,9,31; mullw 6,3,29; mullw 4,0,5; mulhwu 0,9,5; lis 3,-32712; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037FCE8_6; b 9f; 8:; lis 3,-32768; lwz 4,0xc(31); lwz 0,0xf8(3); lis 3,-32712; srawi 9,4,13; rlwinm 7,0,30,2,31; li 0,2; li 4,0; mullw 8,4,0; mulhwu 6,7,0; add 8,8,6; mullw 5,7,0; addze 9,9; mullw 6,7,4; srawi 0,9,31; mullw 4,0,5; mulhwu 0,9,5; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037FCE8_7; 9:; li 29,0; 10:; mr 3,30; bl _s8037FCE8_8; mr 3,29; lmw 27,0x1c(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8037FCE8_0();
extern "C" void _s8037FCE8_1();
extern "C" void _s8037FCE8_2();
extern "C" void _s8037FCE8_3();
extern "C" void _s8037FCE8_4();
extern "C" void _s8037FCE8_5();
extern "C" void _s8037FCE8_6();
extern "C" void _s8037FCE8_7();
extern "C" void _s8037FCE8_8();
extern "C" void f_8037FCE8() {}
