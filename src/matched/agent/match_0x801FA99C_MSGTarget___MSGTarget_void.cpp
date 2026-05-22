// 0x801FA99C MSGTarget::~MSGTarget(void) (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,31608; lis 11,-32697; stw 9,0x80(31); mr 30,4; lwz 4,0x98(31); lwz 3,0x5e80(11); lwz 5,0x9c(31); bl _s801FA99C_0; lwz 0,0x0(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s801FA99C_1; lwz 3,0x8(31); addi 4,31,56; bl _s801FA99C_2; lwz 3,0xc(31); addi 4,31,72; bl _s801FA99C_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s801FA99C_4; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s801FA99C_5; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s801FA99C_6; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s801FA99C_7; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s801FA99C_8; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s801FA99C_9; 9:; bl _s801FA99C_10; bl _s801FA99C_11; bl _s801FA99C_12; bl _s801FA99C_13; bl _s801FA99C_14; bl _s801FA99C_15; bl _s801FA99C_16; bl _s801FA99C_17; bl _s801FA99C_18; bl _s801FA99C_19; bl _s801FA99C_20; bl _s801FA99C_21; bl _s801FA99C_22; bl _s801FA99C_23; bl _s801FA99C_24; bl _s801FA99C_25; bl _s801FA99C_26; bl _s801FA99C_27; bl _s801FA99C_28; bl _s801FA99C_29; bl _s801FA99C_30; bl _s801FA99C_31; bl _s801FA99C_32; bl _s801FA99C_33; bl _s801FA99C_34; bl _s801FA99C_35; bl _s801FA99C_36; addi 3,31,148; li 4,2; bl _s801FA99C_37; addi 3,31,144; li 4,2; bl _s801FA99C_38; addi 3,31,140; li 4,2; bl _s801FA99C_39; lis 9,-32698; andi. 0,30,1; addi 9,9,-12328; stw 9,0x80(31); beq 10f; mr 3,31; bl _s801FA99C_40; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801FA99C_0();
extern "C" void _s801FA99C_1();
extern "C" void _s801FA99C_2();
extern "C" void _s801FA99C_3();
extern "C" void _s801FA99C_4();
extern "C" void _s801FA99C_5();
extern "C" void _s801FA99C_6();
extern "C" void _s801FA99C_7();
extern "C" void _s801FA99C_8();
extern "C" void _s801FA99C_9();
extern "C" void _s801FA99C_10();
extern "C" void _s801FA99C_11();
extern "C" void _s801FA99C_12();
extern "C" void _s801FA99C_13();
extern "C" void _s801FA99C_14();
extern "C" void _s801FA99C_15();
extern "C" void _s801FA99C_16();
extern "C" void _s801FA99C_17();
extern "C" void _s801FA99C_18();
extern "C" void _s801FA99C_19();
extern "C" void _s801FA99C_20();
extern "C" void _s801FA99C_21();
extern "C" void _s801FA99C_22();
extern "C" void _s801FA99C_23();
extern "C" void _s801FA99C_24();
extern "C" void _s801FA99C_25();
extern "C" void _s801FA99C_26();
extern "C" void _s801FA99C_27();
extern "C" void _s801FA99C_28();
extern "C" void _s801FA99C_29();
extern "C" void _s801FA99C_30();
extern "C" void _s801FA99C_31();
extern "C" void _s801FA99C_32();
extern "C" void _s801FA99C_33();
extern "C" void _s801FA99C_34();
extern "C" void _s801FA99C_35();
extern "C" void _s801FA99C_36();
extern "C" void _s801FA99C_37();
extern "C" void _s801FA99C_38();
extern "C" void _s801FA99C_39();
extern "C" void _s801FA99C_40();
extern "C" void f_801FA99C() {}
