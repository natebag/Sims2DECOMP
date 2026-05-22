// 0x8024BEC8 InsertAlarm (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 25,0x24(1); li 28,0; mr 29,3; xoris 4,28,32768; addi 25,5,0; addi 30,6,0; addi 31,7,0; lwz 0,0x18(3); lwz 8,0x1c(3); xoris 3,0,32768; subfc 0,8,28; subfe 3,3,4; subfe 3,4,4; neg. 3,3; beq 0f; bl _s8024BEC8_0; lwz 7,0x20(29); xoris 5,3,32768; lwz 8,0x24(29); xoris 6,7,32768; subfc 0,4,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; addi 30,8,0; addi 25,7,0; beq 0f; lwz 27,0x18(29); subfc 4,8,4; lwz 26,0x1c(29); subfe 3,7,3; addi 5,27,0; addi 6,26,0; bl _s8024BEC8_1; li 0,1; addc 5,4,0; mullw 4,27,5; mulhwu 0,26,5; adde 3,3,28; add 4,4,0; mullw 0,26,3; mullw 3,26,5; add 0,4,0; addc 30,30,3; adde 25,25,0; 0:; stw 31,0x0(29); xoris 4,25,32768; stw 30,0xc(29); stw 25,0x8(29); lwz 6,-23688(13); b 6f; 1:; lwz 0,0x8(6); lwz 5,0xc(6); xoris 3,0,32768; subfc 0,5,30; subfe 3,3,4; subfe 3,4,4; neg. 3,3; beq 5f; lwz 0,0x10(6); stw 0,0x10(29); stw 29,0x10(6); stw 6,0x14(29); lwz 3,0x10(29); cmplwi 3,0; beq 2f; stw 29,0x14(3); b 10f; 2:; stw 29,-23688(13); bl _s8024BEC8_2; lwz 6,0xc(29); li 7,0; lwz 0,0x8(29); xoris 5,7,32768; subfc 8,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 3f; li 3,0; bl _s8024BEC8_3; b 10f; 3:; lis 4,-32768; xoris 3,7,32768; subfc 0,4,8; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 4f; mr 3,8; bl _s8024BEC8_4; b 10f; 4:; addi 3,4,-1; bl _s8024BEC8_5; b 10f; 5:; lwz 6,0x14(6); 6:; cmplwi 6,0; bne 1b; li 30,0; stw 30,0x14(29); addi 3,13,-23688; lwz 4,0x4(3); stwu 29,0x4(3); cmplwi 4,0; stw 4,0x10(29); beq 7f; stw 29,0x14(4); b 10f; 7:; stw 29,0x0(3); stw 29,-23688(13); bl _s8024BEC8_6; lwz 6,0xc(29); xoris 5,30,32768; lwz 0,0x8(29); subfc 7,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,30,7; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 8f; li 3,0; bl _s8024BEC8_7; b 10f; 8:; lis 4,-32768; xoris 3,30,32768; subfc 0,4,7; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 9f; mr 3,7; bl _s8024BEC8_8; b 10f; 9:; addi 3,4,-1; bl _s8024BEC8_9; 10:; lmw 25,0x24(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8024BEC8_0();
extern "C" void _s8024BEC8_1();
extern "C" void _s8024BEC8_2();
extern "C" void _s8024BEC8_3();
extern "C" void _s8024BEC8_4();
extern "C" void _s8024BEC8_5();
extern "C" void _s8024BEC8_6();
extern "C" void _s8024BEC8_7();
extern "C" void _s8024BEC8_8();
extern "C" void _s8024BEC8_9();
extern "C" void f_8024BEC8() {}
