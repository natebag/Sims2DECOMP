// 0x80202B90 SKNTarget::~SKNTarget(void) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32698; mr 31,3; addi 9,9,31352; lis 11,-32697; stw 9,0x80(31); mr 30,4; lwz 4,0x90(31); lwz 3,0x5e80(11); lwz 5,0x94(31); bl _s80202B90_0; lwz 0,0x0(31); cmpwi 0,0; beq 9f; lwz 3,0x4(31); addi 4,31,40; bl _s80202B90_1; lwz 3,0x8(31); addi 4,31,56; bl _s80202B90_2; lwz 3,0xc(31); addi 4,31,72; bl _s80202B90_3; addi 9,31,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 0f; lwz 0,0x58(31); cmpwi 0,0; beq 1f; 0:; li 11,1; 1:; cmpwi 11,0; beq 2f; lwz 3,0x10(31); bl _s80202B90_4; 2:; addi 9,31,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 3f; lwz 0,0x68(31); cmpwi 0,0; beq 4f; 3:; li 11,1; 4:; cmpwi 11,0; beq 5f; lwz 3,0x14(31); bl _s80202B90_5; 5:; lwz 3,0x18(31); cmpwi 3,0; beq 6f; lwz 4,0x7c(31); bl _s80202B90_6; 6:; lwz 3,0x1c(31); cmpwi 3,0; beq 7f; lwz 4,0x7c(31); bl _s80202B90_7; 7:; lwz 3,0x20(31); cmpwi 3,0; beq 8f; lwz 4,0x7c(31); bl _s80202B90_8; 8:; lwz 3,0x24(31); cmpwi 3,0; beq 9f; lwz 4,0x7c(31); bl _s80202B90_9; 9:; bl _s80202B90_10; bl _s80202B90_11; bl _s80202B90_12; bl _s80202B90_13; bl _s80202B90_14; bl _s80202B90_15; bl _s80202B90_16; bl _s80202B90_17; bl _s80202B90_18; bl _s80202B90_19; bl _s80202B90_20; bl _s80202B90_21; bl _s80202B90_22; bl _s80202B90_23; bl _s80202B90_24; bl _s80202B90_25; bl _s80202B90_26; bl _s80202B90_27; bl _s80202B90_28; bl _s80202B90_29; bl _s80202B90_30; bl _s80202B90_31; bl _s80202B90_32; bl _s80202B90_33; bl _s80202B90_34; bl _s80202B90_35; bl _s80202B90_36; lis 9,-32698; addi 9,9,-12328; andi. 0,30,1; stw 9,0x80(31); beq 10f; mr 3,31; bl _s80202B90_37; 10:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80202B90_0();
extern "C" void _s80202B90_1();
extern "C" void _s80202B90_2();
extern "C" void _s80202B90_3();
extern "C" void _s80202B90_4();
extern "C" void _s80202B90_5();
extern "C" void _s80202B90_6();
extern "C" void _s80202B90_7();
extern "C" void _s80202B90_8();
extern "C" void _s80202B90_9();
extern "C" void _s80202B90_10();
extern "C" void _s80202B90_11();
extern "C" void _s80202B90_12();
extern "C" void _s80202B90_13();
extern "C" void _s80202B90_14();
extern "C" void _s80202B90_15();
extern "C" void _s80202B90_16();
extern "C" void _s80202B90_17();
extern "C" void _s80202B90_18();
extern "C" void _s80202B90_19();
extern "C" void _s80202B90_20();
extern "C" void _s80202B90_21();
extern "C" void _s80202B90_22();
extern "C" void _s80202B90_23();
extern "C" void _s80202B90_24();
extern "C" void _s80202B90_25();
extern "C" void _s80202B90_26();
extern "C" void _s80202B90_27();
extern "C" void _s80202B90_28();
extern "C" void _s80202B90_29();
extern "C" void _s80202B90_30();
extern "C" void _s80202B90_31();
extern "C" void _s80202B90_32();
extern "C" void _s80202B90_33();
extern "C" void _s80202B90_34();
extern "C" void _s80202B90_35();
extern "C" void _s80202B90_36();
extern "C" void _s80202B90_37();
extern "C" void f_80202B90() {}
