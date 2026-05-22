// 0x8036F700 OSFatal (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 6,-32690; stw 0,0x4(1); stwu 1,-64(1); stmw 23,0x1c(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; addi 31,6,-3960; lis 30,-32768; bl _s8036F700_0; bl _s8036F700_1; addi 3,31,16; bl _s8036F700_2; addi 3,31,16; bl _s8036F700_3; bl _s8036F700_4; li 3,0; bl _s8036F700_5; li 3,0; bl _s8036F700_6; bl _s8036F700_7; li 3,128; bl _s8036F700_8; li 3,1; bl _s8036F700_9; bl _s8036F700_10; li 3,0; bl _s8036F700_11; li 3,0; bl _s8036F700_12; bl _s8036F700_13; bl _s8036F700_14; mr 23,3; 0:; bl _s8036F700_15; subf 0,23,3; cmpwi 0,1; blt 0b; bl _s8036F700_16; lis 5,-32768; lwz 0,0xf8(5); lis 5,4194; addi 5,5,19923; rlwinm 0,0,30,2,31; mulhwu 0,5,0; rlwinm 0,0,26,6,31; mulli 25,0,1000; addi 23,4,0; addi 24,3,0; li 26,0; 1:; li 3,0; bl _s8036F700_17; cmpwi 3,0; bne 2f; bl _s8036F700_18; subfc 5,23,4; subfe 0,24,3; xoris 4,0,32768; xoris 3,26,32768; subfc 0,25,5; subfe 3,3,4; subfe 3,4,4; neg. 3,3; bne 1b; 2:; bl _s8036F700_19; li 3,1; bl _s8036F700_20; li 3,0; li 4,0; bl _s8036F700_21; li 3,2; li 4,0; bl _s8036F700_22; b 4f; 3:; li 3,0; bl _s8036F700_23; li 3,0; bl _s8036F700_24; li 3,0; bl _s8036F700_25; 4:; li 3,0; li 4,1; li 5,0; bl _s8036F700_26; cmpwi 3,0; beq 3b; li 3,0; bl _s8036F700_27; lis 3,-13312; addi 3,3,26624; 5:; lwz 0,0xc(3); rlwinm 0,0,0,31,31; cmplwi 0,1; beq 5b; lis 3,-32731; addi 4,3,-17508; li 3,8; bl _s8036F700_28; bl _s8036F700_29; lis 3,-32448; bl _s8036F700_30; lwz 3,0x38(30); bl _s8036F700_31; lwz 0,0x0(27); stw 0,0x0(31); lwz 0,0x0(28); stw 0,0x4(31); stw 29,0x8(31); bl _s8036F700_32; lis 5,-32713; addi 4,3,0; addi 3,5,-1832; bl _s8036F700_33; lmw 23,0x1c(1); lwz 0,0x44(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s8036F700_0();
extern "C" void _s8036F700_1();
extern "C" void _s8036F700_2();
extern "C" void _s8036F700_3();
extern "C" void _s8036F700_4();
extern "C" void _s8036F700_5();
extern "C" void _s8036F700_6();
extern "C" void _s8036F700_7();
extern "C" void _s8036F700_8();
extern "C" void _s8036F700_9();
extern "C" void _s8036F700_10();
extern "C" void _s8036F700_11();
extern "C" void _s8036F700_12();
extern "C" void _s8036F700_13();
extern "C" void _s8036F700_14();
extern "C" void _s8036F700_15();
extern "C" void _s8036F700_16();
extern "C" void _s8036F700_17();
extern "C" void _s8036F700_18();
extern "C" void _s8036F700_19();
extern "C" void _s8036F700_20();
extern "C" void _s8036F700_21();
extern "C" void _s8036F700_22();
extern "C" void _s8036F700_23();
extern "C" void _s8036F700_24();
extern "C" void _s8036F700_25();
extern "C" void _s8036F700_26();
extern "C" void _s8036F700_27();
extern "C" void _s8036F700_28();
extern "C" void _s8036F700_29();
extern "C" void _s8036F700_30();
extern "C" void _s8036F700_31();
extern "C" void _s8036F700_32();
extern "C" void _s8036F700_33();
extern "C" void f_8036F700() {}
