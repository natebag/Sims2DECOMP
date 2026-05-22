// 0x8017F688 UIScreenManager::~UIScreenManager(void) (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 0,0x0(31); addi 9,9,26448; mr 30,4; stw 9,0x80(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s8017F688_0; lwz 3,0x8(31); addi 4,31,56; bl _s8017F688_1; lwz 3,0xc(31); addi 4,31,72; bl _s8017F688_2; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s8017F688_3; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s8017F688_4; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s8017F688_5; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s8017F688_6; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s8017F688_7; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s8017F688_8; 9:; bl _s8017F688_9; bl _s8017F688_10; bl _s8017F688_11; bl _s8017F688_12; bl _s8017F688_13; bl _s8017F688_14; bl _s8017F688_15; bl _s8017F688_16; bl _s8017F688_17; bl _s8017F688_18; bl _s8017F688_19; bl _s8017F688_20; bl _s8017F688_21; bl _s8017F688_22; bl _s8017F688_23; bl _s8017F688_24; bl _s8017F688_25; bl _s8017F688_26; bl _s8017F688_27; bl _s8017F688_28; bl _s8017F688_29; bl _s8017F688_30; bl _s8017F688_31; bl _s8017F688_32; bl _s8017F688_33; bl _s8017F688_34; bl _s8017F688_35; lis 9,-32698; addi 9,9,-12328; andi. 0,30,1; stw 9,0x80(31); beq 10f; mr 3,31; bl _s8017F688_36; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8017F688_0();
extern "C" void _s8017F688_1();
extern "C" void _s8017F688_2();
extern "C" void _s8017F688_3();
extern "C" void _s8017F688_4();
extern "C" void _s8017F688_5();
extern "C" void _s8017F688_6();
extern "C" void _s8017F688_7();
extern "C" void _s8017F688_8();
extern "C" void _s8017F688_9();
extern "C" void _s8017F688_10();
extern "C" void _s8017F688_11();
extern "C" void _s8017F688_12();
extern "C" void _s8017F688_13();
extern "C" void _s8017F688_14();
extern "C" void _s8017F688_15();
extern "C" void _s8017F688_16();
extern "C" void _s8017F688_17();
extern "C" void _s8017F688_18();
extern "C" void _s8017F688_19();
extern "C" void _s8017F688_20();
extern "C" void _s8017F688_21();
extern "C" void _s8017F688_22();
extern "C" void _s8017F688_23();
extern "C" void _s8017F688_24();
extern "C" void _s8017F688_25();
extern "C" void _s8017F688_26();
extern "C" void _s8017F688_27();
extern "C" void _s8017F688_28();
extern "C" void _s8017F688_29();
extern "C" void _s8017F688_30();
extern "C" void _s8017F688_31();
extern "C" void _s8017F688_32();
extern "C" void _s8017F688_33();
extern "C" void _s8017F688_34();
extern "C" void _s8017F688_35();
extern "C" void _s8017F688_36();
extern "C" void f_8017F688() {}
