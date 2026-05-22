// 0x8037EA58 __DSP_exec_task (416 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); addi 31,4,0; stw 30,0x10(1); mr. 30,3; beq 3f; lwz 3,0x18(30); bl _s8037EA58_0; 0:; bl _s8037EA58_1; cmplwi 3,0; bne 0b; lwz 3,0x1c(30); bl _s8037EA58_2; 1:; bl _s8037EA58_3; cmplwi 3,0; bne 1b; lwz 3,0x20(30); bl _s8037EA58_4; 2:; bl _s8037EA58_5; cmplwi 3,0; bne 2b; b 7f; 3:; li 3,0; bl _s8037EA58_6; 4:; bl _s8037EA58_7; cmplwi 3,0; bne 4b; li 3,0; bl _s8037EA58_8; 5:; bl _s8037EA58_9; cmplwi 3,0; bne 5b; li 3,0; bl _s8037EA58_10; 6:; bl _s8037EA58_11; cmplwi 3,0; bne 6b; 7:; lwz 3,0xc(31); bl _s8037EA58_12; 8:; bl _s8037EA58_13; cmplwi 3,0; bne 8b; lwz 3,0x10(31); bl _s8037EA58_14; 9:; bl _s8037EA58_15; cmplwi 3,0; bne 9b; lwz 3,0x14(31); bl _s8037EA58_16; 10:; bl _s8037EA58_17; cmplwi 3,0; bne 10b; lwz 0,0x0(31); cmplwi 0,0; bne 15f; lhz 3,0x24(31); bl _s8037EA58_18; 11:; bl _s8037EA58_19; cmplwi 3,0; bne 11b; li 3,0; bl _s8037EA58_20; 12:; bl _s8037EA58_21; cmplwi 3,0; bne 12b; li 3,0; bl _s8037EA58_22; 13:; bl _s8037EA58_23; cmplwi 3,0; bne 13b; li 3,0; bl _s8037EA58_24; 14:; bl _s8037EA58_25; cmplwi 3,0; bne 14b; b 20f; 15:; lhz 3,0x26(31); bl _s8037EA58_26; 16:; bl _s8037EA58_27; cmplwi 3,0; bne 16b; lwz 3,0x18(31); bl _s8037EA58_28; 17:; bl _s8037EA58_29; cmplwi 3,0; bne 17b; lwz 3,0x1c(31); bl _s8037EA58_30; 18:; bl _s8037EA58_31; cmplwi 3,0; bne 18b; lwz 3,0x20(31); bl _s8037EA58_32; 19:; bl _s8037EA58_33; cmplwi 3,0; bne 19b; 20:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037EA58_0();
extern "C" void _s8037EA58_1();
extern "C" void _s8037EA58_2();
extern "C" void _s8037EA58_3();
extern "C" void _s8037EA58_4();
extern "C" void _s8037EA58_5();
extern "C" void _s8037EA58_6();
extern "C" void _s8037EA58_7();
extern "C" void _s8037EA58_8();
extern "C" void _s8037EA58_9();
extern "C" void _s8037EA58_10();
extern "C" void _s8037EA58_11();
extern "C" void _s8037EA58_12();
extern "C" void _s8037EA58_13();
extern "C" void _s8037EA58_14();
extern "C" void _s8037EA58_15();
extern "C" void _s8037EA58_16();
extern "C" void _s8037EA58_17();
extern "C" void _s8037EA58_18();
extern "C" void _s8037EA58_19();
extern "C" void _s8037EA58_20();
extern "C" void _s8037EA58_21();
extern "C" void _s8037EA58_22();
extern "C" void _s8037EA58_23();
extern "C" void _s8037EA58_24();
extern "C" void _s8037EA58_25();
extern "C" void _s8037EA58_26();
extern "C" void _s8037EA58_27();
extern "C" void _s8037EA58_28();
extern "C" void _s8037EA58_29();
extern "C" void _s8037EA58_30();
extern "C" void _s8037EA58_31();
extern "C" void _s8037EA58_32();
extern "C" void _s8037EA58_33();
extern "C" void f_8037EA58() {}
