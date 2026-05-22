// 0x801EA07C FONTarget::~FONTarget(void) (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lis 9,-32698; lwz 3,0x8c(31); addi 9,9,32056; mr 30,4; stw 9,0x80(31); cmpwi 3,0; beq 0f; li 4,3; bl _s801EA07C_0; 0:; lis 9,-32697; lwz 4,0x9c(31); lwz 3,0x5e80(9); lwz 5,0xa0(31); bl _s801EA07C_1; lwz 0,0x0(31); cmpwi 0,0; beq 10f; lwz 3,0x4(31); addi 4,31,40; bl _s801EA07C_2; lwz 3,0x8(31); addi 4,31,56; bl _s801EA07C_3; lwz 3,0xc(31); addi 4,31,72; bl _s801EA07C_4; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 1f; lwz 0,0x58(31); cmpwi 0,0; beq 2f; 1:; li 11,1; 2:; cmpwi 11,0; beq 3f; lwz 3,0x10(31); bl _s801EA07C_5; 3:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 4f; lwz 0,0x68(31); cmpwi 0,0; beq 5f; 4:; li 11,1; 5:; cmpwi 11,0; beq 6f; lwz 3,0x14(31); bl _s801EA07C_6; 6:; lwz 3,0x18(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801EA07C_7; 7:; lwz 3,0x1c(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801EA07C_8; 8:; lwz 3,0x20(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801EA07C_9; 9:; lwz 3,0x24(31); cmpwi 3,0; beq 10f; lwz 4,0x7c(31); bl _s801EA07C_10; 10:; bl _s801EA07C_11; bl _s801EA07C_12; bl _s801EA07C_13; bl _s801EA07C_14; bl _s801EA07C_15; bl _s801EA07C_16; bl _s801EA07C_17; bl _s801EA07C_18; bl _s801EA07C_19; bl _s801EA07C_20; bl _s801EA07C_21; bl _s801EA07C_22; bl _s801EA07C_23; bl _s801EA07C_24; bl _s801EA07C_25; bl _s801EA07C_26; bl _s801EA07C_27; bl _s801EA07C_28; bl _s801EA07C_29; bl _s801EA07C_30; bl _s801EA07C_31; bl _s801EA07C_32; bl _s801EA07C_33; bl _s801EA07C_34; bl _s801EA07C_35; bl _s801EA07C_36; bl _s801EA07C_37; addi 3,31,144; li 4,2; bl _s801EA07C_38; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 11f; mr 3,31; bl _s801EA07C_39; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801EA07C_0();
extern "C" void _s801EA07C_1();
extern "C" void _s801EA07C_2();
extern "C" void _s801EA07C_3();
extern "C" void _s801EA07C_4();
extern "C" void _s801EA07C_5();
extern "C" void _s801EA07C_6();
extern "C" void _s801EA07C_7();
extern "C" void _s801EA07C_8();
extern "C" void _s801EA07C_9();
extern "C" void _s801EA07C_10();
extern "C" void _s801EA07C_11();
extern "C" void _s801EA07C_12();
extern "C" void _s801EA07C_13();
extern "C" void _s801EA07C_14();
extern "C" void _s801EA07C_15();
extern "C" void _s801EA07C_16();
extern "C" void _s801EA07C_17();
extern "C" void _s801EA07C_18();
extern "C" void _s801EA07C_19();
extern "C" void _s801EA07C_20();
extern "C" void _s801EA07C_21();
extern "C" void _s801EA07C_22();
extern "C" void _s801EA07C_23();
extern "C" void _s801EA07C_24();
extern "C" void _s801EA07C_25();
extern "C" void _s801EA07C_26();
extern "C" void _s801EA07C_27();
extern "C" void _s801EA07C_28();
extern "C" void _s801EA07C_29();
extern "C" void _s801EA07C_30();
extern "C" void _s801EA07C_31();
extern "C" void _s801EA07C_32();
extern "C" void _s801EA07C_33();
extern "C" void _s801EA07C_34();
extern "C" void _s801EA07C_35();
extern "C" void _s801EA07C_36();
extern "C" void _s801EA07C_37();
extern "C" void _s801EA07C_38();
extern "C" void _s801EA07C_39();
extern "C" void f_801EA07C() {}
