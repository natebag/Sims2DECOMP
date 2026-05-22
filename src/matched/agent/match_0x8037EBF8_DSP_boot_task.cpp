// 0x8037EBF8 __DSP_boot_task (396 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 4,-32698; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,-27872; stw 30,0x10(1); addi 30,3,0; 0:; bl _s8037EBF8_0; cmplwi 3,0; beq 0b; bl _s8037EBF8_1; stw 3,0xc(1); lis 3,-32524; addi 3,3,-24575; bl _s8037EBF8_2; 1:; bl _s8037EBF8_3; cmplwi 3,0; bne 1b; lwz 3,0xc(30); bl _s8037EBF8_4; 2:; bl _s8037EBF8_5; cmplwi 3,0; bne 2b; lis 3,-32524; addi 3,3,-16382; bl _s8037EBF8_6; 3:; bl _s8037EBF8_7; cmplwi 3,0; bne 3b; lwz 0,0x14(30); rlwinm 3,0,0,16,31; bl _s8037EBF8_8; 4:; bl _s8037EBF8_9; cmplwi 3,0; bne 4b; lis 3,-32524; addi 3,3,-24574; bl _s8037EBF8_10; 5:; bl _s8037EBF8_11; cmplwi 3,0; bne 5b; lwz 3,0x10(30); bl _s8037EBF8_12; 6:; bl _s8037EBF8_13; cmplwi 3,0; bne 6b; lis 3,-32524; addi 3,3,-20478; bl _s8037EBF8_14; 7:; bl _s8037EBF8_15; cmplwi 3,0; bne 7b; li 3,0; bl _s8037EBF8_16; 8:; bl _s8037EBF8_17; cmplwi 3,0; bne 8b; lis 3,-32524; addi 3,3,-12287; bl _s8037EBF8_18; 9:; bl _s8037EBF8_19; cmplwi 3,0; bne 9b; lhz 3,0x24(30); bl _s8037EBF8_20; 10:; bl _s8037EBF8_21; cmplwi 3,0; bne 10b; addi 3,31,0; crxor 6,6,6; addi 4,30,0; bl _s8037EBF8_22; lwz 4,0xc(30); addi 3,31,32; crxor 6,6,6; bl _s8037EBF8_23; lwz 4,0x14(30); addi 3,31,80; crxor 6,6,6; bl _s8037EBF8_24; lwz 4,0x10(30); addi 3,31,128; crxor 6,6,6; bl _s8037EBF8_25; lwz 4,0x1c(30); addi 3,31,176; crxor 6,6,6; bl _s8037EBF8_26; lhz 4,0x24(30); addi 3,31,224; crxor 6,6,6; bl _s8037EBF8_27; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037EBF8_0();
extern "C" void _s8037EBF8_1();
extern "C" void _s8037EBF8_2();
extern "C" void _s8037EBF8_3();
extern "C" void _s8037EBF8_4();
extern "C" void _s8037EBF8_5();
extern "C" void _s8037EBF8_6();
extern "C" void _s8037EBF8_7();
extern "C" void _s8037EBF8_8();
extern "C" void _s8037EBF8_9();
extern "C" void _s8037EBF8_10();
extern "C" void _s8037EBF8_11();
extern "C" void _s8037EBF8_12();
extern "C" void _s8037EBF8_13();
extern "C" void _s8037EBF8_14();
extern "C" void _s8037EBF8_15();
extern "C" void _s8037EBF8_16();
extern "C" void _s8037EBF8_17();
extern "C" void _s8037EBF8_18();
extern "C" void _s8037EBF8_19();
extern "C" void _s8037EBF8_20();
extern "C" void _s8037EBF8_21();
extern "C" void _s8037EBF8_22();
extern "C" void _s8037EBF8_23();
extern "C" void _s8037EBF8_24();
extern "C" void _s8037EBF8_25();
extern "C" void _s8037EBF8_26();
extern "C" void _s8037EBF8_27();
extern "C" void f_8037EBF8() {}
