// 0x80201DD8 RGTTarget::~RGTTarget(void) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,31416; lis 11,-32697; stw 9,0x80(31); mr 30,4; lwz 4,0x8c(31); lwz 3,0x5e80(11); lwz 5,0x90(31); bl _s80201DD8_0; lwz 0,0x0(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s80201DD8_1; lwz 3,0x8(31); addi 4,31,56; bl _s80201DD8_2; lwz 3,0xc(31); addi 4,31,72; bl _s80201DD8_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s80201DD8_4; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s80201DD8_5; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s80201DD8_6; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s80201DD8_7; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s80201DD8_8; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s80201DD8_9; 9:; bl _s80201DD8_10; bl _s80201DD8_11; bl _s80201DD8_12; bl _s80201DD8_13; bl _s80201DD8_14; bl _s80201DD8_15; bl _s80201DD8_16; bl _s80201DD8_17; bl _s80201DD8_18; bl _s80201DD8_19; bl _s80201DD8_20; bl _s80201DD8_21; bl _s80201DD8_22; bl _s80201DD8_23; bl _s80201DD8_24; bl _s80201DD8_25; bl _s80201DD8_26; bl _s80201DD8_27; bl _s80201DD8_28; bl _s80201DD8_29; bl _s80201DD8_30; bl _s80201DD8_31; bl _s80201DD8_32; bl _s80201DD8_33; bl _s80201DD8_34; bl _s80201DD8_35; bl _s80201DD8_36; lis 9,-32698; addi 9,9,-12328; andi. 0,30,1; stw 9,0x80(31); beq 10f; mr 3,31; bl _s80201DD8_37; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80201DD8_0();
extern "C" void _s80201DD8_1();
extern "C" void _s80201DD8_2();
extern "C" void _s80201DD8_3();
extern "C" void _s80201DD8_4();
extern "C" void _s80201DD8_5();
extern "C" void _s80201DD8_6();
extern "C" void _s80201DD8_7();
extern "C" void _s80201DD8_8();
extern "C" void _s80201DD8_9();
extern "C" void _s80201DD8_10();
extern "C" void _s80201DD8_11();
extern "C" void _s80201DD8_12();
extern "C" void _s80201DD8_13();
extern "C" void _s80201DD8_14();
extern "C" void _s80201DD8_15();
extern "C" void _s80201DD8_16();
extern "C" void _s80201DD8_17();
extern "C" void _s80201DD8_18();
extern "C" void _s80201DD8_19();
extern "C" void _s80201DD8_20();
extern "C" void _s80201DD8_21();
extern "C" void _s80201DD8_22();
extern "C" void _s80201DD8_23();
extern "C" void _s80201DD8_24();
extern "C" void _s80201DD8_25();
extern "C" void _s80201DD8_26();
extern "C" void _s80201DD8_27();
extern "C" void _s80201DD8_28();
extern "C" void _s80201DD8_29();
extern "C" void _s80201DD8_30();
extern "C" void _s80201DD8_31();
extern "C" void _s80201DD8_32();
extern "C" void _s80201DD8_33();
extern "C" void _s80201DD8_34();
extern "C" void _s80201DD8_35();
extern "C" void _s80201DD8_36();
extern "C" void _s80201DD8_37();
extern "C" void f_80201DD8() {}
