// 0x8037F7CC SetupTimeoutAlarm (364 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,3,0; addi 3,31,224; bl _s8037F7CC_0; lbz 0,0x94(31); cmpwi 0,243; beq 4f; bge 0f; cmpwi 0,241; beq 3f; bge 1f; b 4f; 0:; cmpwi 0,245; bge 4f; b 2f; 1:; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32712; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,100; addi 7,3,-2264; addi 3,31,224; li 5,0; bl _s8037F7CC_1; b 4f; 2:; lhz 0,0xa(31); cmplwi 0,128; ble 3f; lis 3,-32768; lhz 4,0x10(31); lwz 0,0xf8(3); lis 3,-32712; srawi 9,4,6; rlwinm 7,0,30,2,31; li 0,2; li 4,0; mullw 8,4,0; mulhwu 6,7,0; add 8,8,6; mullw 5,7,0; addze 9,9; mullw 6,7,4; srawi 0,9,31; mullw 4,0,5; mulhwu 0,9,5; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037F7CC_2; b 4f; 3:; lis 3,-32768; lwz 4,0xc(31); lwz 0,0xf8(3); lis 3,-32712; srawi 9,4,13; rlwinm 7,0,30,2,31; li 0,2; li 4,0; mullw 8,4,0; mulhwu 6,7,0; add 8,8,6; mullw 5,7,0; addze 9,9; mullw 6,7,4; srawi 0,9,31; mullw 4,0,5; mulhwu 0,9,5; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037F7CC_3; 4:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037F7CC_0();
extern "C" void _s8037F7CC_1();
extern "C" void _s8037F7CC_2();
extern "C" void _s8037F7CC_3();
extern "C" void f_8037F7CC() {}
