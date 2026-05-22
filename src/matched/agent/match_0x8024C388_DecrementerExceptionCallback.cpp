// 0x8024C388 DecrementerExceptionCallback (560 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-752(1); stw 31,0x2ec(1); stw 30,0x2e8(1); stw 29,0x2e4(1); mr 29,4; stw 28,0x2e0(1); bl _s8024C388_0; lwz 0,-23688(13); addi 28,4,0; addi 30,3,0; cmplwi 0,0; mr 31,0; bne 0f; mr 3,29; bl _s8024C388_1; 0:; lwz 0,0x8(31); xoris 4,30,32768; lwz 5,0xc(31); xoris 3,0,32768; subfc 0,5,28; subfe 3,3,4; subfe 3,4,4; neg. 3,3; beq 4f; bl _s8024C388_2; lwz 6,0xc(31); li 7,0; lwz 0,0x8(31); xoris 5,7,32768; subfc 8,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 1f; li 3,0; bl _s8024C388_3; b 3f; 1:; lis 4,-32768; xoris 3,7,32768; subfc 0,4,8; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 2f; mr 3,8; bl _s8024C388_4; b 3f; 2:; addi 3,4,-1; bl _s8024C388_5; 3:; mr 3,29; bl _s8024C388_6; 4:; lwz 3,0x14(31); cmplwi 3,0; stw 3,-23688(13); bne 5f; li 0,0; addi 3,13,-23688; stw 0,0x4(3); b 6f; 5:; li 0,0; stw 0,0x10(3); 6:; lwz 30,0x0(31); li 6,0; xoris 4,6,32768; stw 6,0x0(31); lwz 0,0x18(31); lwz 5,0x1c(31); xoris 3,0,32768; subfc 0,5,6; subfe 3,3,4; subfe 3,4,4; neg. 3,3; beq 7f; addi 3,31,0; addi 7,30,0; li 6,0; li 5,0; bl _s8024C388_7; 7:; lwz 28,-23688(13); cmplwi 28,0; beq 10f; bl _s8024C388_8; lwz 6,0xc(28); li 7,0; lwz 0,0x8(28); xoris 5,7,32768; subfc 8,4,6; subfe 0,3,0; xoris 6,0,32768; subfc 0,7,8; subfe 5,5,6; subfe 5,6,6; neg. 5,5; beq 8f; li 3,0; bl _s8024C388_9; b 10f; 8:; lis 4,-32768; xoris 3,7,32768; subfc 0,4,8; subfe 3,3,6; subfe 3,6,6; neg. 3,3; beq 9f; mr 3,8; bl _s8024C388_10; b 10f; 9:; addi 3,4,-1; bl _s8024C388_11; 10:; bl _s8024C388_12; addi 3,1,24; bl _s8024C388_13; addi 3,1,24; bl _s8024C388_14; addi 12,30,0; mtspr 8,12; addi 3,31,0; addi 4,29,0; blrl; addi 3,1,24; bl _s8024C388_15; mr 3,29; bl _s8024C388_16; bl _s8024C388_17; bl _s8024C388_18; mr 3,29; bl _s8024C388_19; lwz 0,0x2f4(1); lwz 31,0x2ec(1); lwz 30,0x2e8(1); lwz 29,0x2e4(1); lwz 28,0x2e0(1); addi 1,1,752; mtspr 8,0"
extern "C" void _s8024C388_0();
extern "C" void _s8024C388_1();
extern "C" void _s8024C388_2();
extern "C" void _s8024C388_3();
extern "C" void _s8024C388_4();
extern "C" void _s8024C388_5();
extern "C" void _s8024C388_6();
extern "C" void _s8024C388_7();
extern "C" void _s8024C388_8();
extern "C" void _s8024C388_9();
extern "C" void _s8024C388_10();
extern "C" void _s8024C388_11();
extern "C" void _s8024C388_12();
extern "C" void _s8024C388_13();
extern "C" void _s8024C388_14();
extern "C" void _s8024C388_15();
extern "C" void _s8024C388_16();
extern "C" void _s8024C388_17();
extern "C" void _s8024C388_18();
extern "C" void _s8024C388_19();
extern "C" void f_8024C388() {}
