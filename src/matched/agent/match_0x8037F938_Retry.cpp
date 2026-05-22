// 0x8037F938 Retry (672 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; li 5,4; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; mulli 4,30,272; lis 3,-32688; addi 0,3,-24000; add 31,0,4; addi 3,30,0; li 4,0; bl _s8037F938_0; cmpwi 3,0; bne 0f; mr 3,30; bl _s8037F938_1; li 3,-3; b 12f; 0:; addi 3,31,224; bl _s8037F938_2; lbz 0,0x94(31); cmpwi 0,243; beq 5f; bge 1f; cmpwi 0,241; beq 4f; bge 2f; b 5f; 1:; cmpwi 0,245; bge 5f; b 3f; 2:; lis 3,-32768; lwz 0,0xf8(3); lis 4,4194; lis 3,-32712; rlwinm 0,0,30,2,31; addi 4,4,19923; mulhwu 0,4,0; rlwinm 0,0,26,6,31; mulli 6,0,100; addi 7,3,-2264; addi 3,31,224; li 5,0; bl _s8037F938_3; b 5f; 3:; lhz 0,0xa(31); cmplwi 0,128; ble 4f; lis 3,-32768; lhz 4,0x10(31); lwz 0,0xf8(3); lis 3,-32712; srawi 9,4,6; rlwinm 7,0,30,2,31; li 0,2; li 4,0; mullw 8,4,0; mulhwu 6,7,0; add 8,8,6; mullw 5,7,0; addze 9,9; mullw 6,7,4; srawi 0,9,31; mullw 4,0,5; mulhwu 0,9,5; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037F938_4; b 5f; 4:; lis 3,-32768; lwz 4,0xc(31); lwz 0,0xf8(3); lis 3,-32712; srawi 9,4,13; rlwinm 7,0,30,2,31; li 0,2; li 4,0; mullw 8,4,0; mulhwu 6,7,0; add 8,8,6; mullw 5,7,0; addze 9,9; mullw 6,7,4; srawi 0,9,31; mullw 4,0,5; mulhwu 0,9,5; addi 7,3,-2264; add 3,8,6; add 4,4,0; mullw 0,9,3; mullw 6,9,5; addi 3,31,224; add 5,4,0; bl _s8037F938_5; 5:; lwz 5,0xa0(31); addi 3,30,0; addi 4,31,148; li 6,1; bl _s8037F938_6; cmpwi 3,0; bne 6f; mr 3,30; bl _s8037F938_7; mr 3,30; bl _s8037F938_8; li 3,-3; b 12f; 6:; lbz 0,0x94(31); cmplwi 0,82; bne 7f; lwz 4,0x80(31); mr 3,30; lwz 5,0x14(31); li 6,1; addi 4,4,512; bl _s8037F938_9; cmpwi 3,0; bne 7f; mr 3,30; bl _s8037F938_10; mr 3,30; bl _s8037F938_11; li 3,-3; b 12f; 7:; lwz 3,0xa4(31); addis 0,3,1; cmplwi 0,65535; bne 8f; mr 3,30; bl _s8037F938_12; mr 3,30; bl _s8037F938_13; li 3,0; b 12f; 8:; lbz 0,0x94(31); cmplwi 0,82; bne 9f; li 5,512; b 10f; 9:; lhz 5,0xa(31); 10:; lis 3,-32712; lwz 4,0xb4(31); addi 7,3,-3752; lwz 6,0xa4(31); mr 3,30; bl _s8037F938_14; cmpwi 3,0; bne 11f; mr 3,30; bl _s8037F938_15; mr 3,30; bl _s8037F938_16; li 3,-3; b 12f; 11:; li 3,0; 12:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037F938_0();
extern "C" void _s8037F938_1();
extern "C" void _s8037F938_2();
extern "C" void _s8037F938_3();
extern "C" void _s8037F938_4();
extern "C" void _s8037F938_5();
extern "C" void _s8037F938_6();
extern "C" void _s8037F938_7();
extern "C" void _s8037F938_8();
extern "C" void _s8037F938_9();
extern "C" void _s8037F938_10();
extern "C" void _s8037F938_11();
extern "C" void _s8037F938_12();
extern "C" void _s8037F938_13();
extern "C" void _s8037F938_14();
extern "C" void _s8037F938_15();
extern "C" void _s8037F938_16();
extern "C" void f_8037F938() {}
