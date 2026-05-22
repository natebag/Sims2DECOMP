// 0x8024BDC8 SetTimer (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); mr 31,3; bl _s8024BDC8_0; lwz 6,0xc(31); li 7,0; lwz 0,0x8(31); xoris 5,7,32768; subfc 8,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 0f; li 3,0; bl _s8024BDC8_1; b 2f; 0:; lis 4,-32768; xoris 3,7,32768; subfc 0,4,8; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 1f; mr 3,8; bl _s8024BDC8_2; b 2f; 1:; addi 3,4,-1; bl _s8024BDC8_3; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8024BDC8_0();
extern "C" void _s8024BDC8_1();
extern "C" void _s8024BDC8_2();
extern "C" void _s8024BDC8_3();
extern "C" void f_8024BDC8() {}
