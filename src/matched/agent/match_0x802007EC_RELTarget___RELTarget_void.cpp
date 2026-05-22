// 0x802007EC RELTarget::~RELTarget(void) (572 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; lis 9,-32698; lwz 0,0x84(30); addi 9,9,31480; mr 28,4; stw 9,0x80(30); cmpwi 0,0; beq 3f; 0:; lwz 9,0x84(30); lwz 3,0x10(9); lwz 29,0x4(9); cmpwi 3,0; beq 1f; bl _s802007EC_0; 1:; lwz 31,0x84(30); cmpwi 31,0; beq 2f; addi 3,31,24; li 4,2; bl _s802007EC_1; addi 3,31,20; li 4,2; bl _s802007EC_2; mr 3,31; bl _s802007EC_3; 2:; cmpwi 29,0; stw 29,0x84(30); bne 0b; 3:; lwz 3,0x98(30); cmpwi 3,0; beq 4f; bl _s802007EC_4; 4:; lis 9,-32697; lwz 4,0x9c(30); lwz 3,0x5e80(9); lwz 5,0xa0(30); bl _s802007EC_5; lwz 0,0x0(30); cmpwi 0,0; beq 14f; lwz 3,0x4(30); addi 4,30,40; bl _s802007EC_6; lwz 3,0x8(30); addi 4,30,56; bl _s802007EC_7; lwz 3,0xc(30); addi 4,30,72; bl _s802007EC_8; addi 9,30,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 5f; lwz 0,0x58(30); cmpwi 0,0; beq 6f; 5:; li 11,1; 6:; cmpwi 11,0; beq 7f; lwz 3,0x10(30); bl _s802007EC_9; 7:; addi 9,30,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 8f; lwz 0,0x68(30); cmpwi 0,0; beq 9f; 8:; li 11,1; 9:; cmpwi 11,0; beq 10f; lwz 3,0x14(30); bl _s802007EC_10; 10:; lwz 3,0x18(30); cmpwi 3,0; beq 11f; lwz 4,0x7c(30); bl _s802007EC_11; 11:; lwz 3,0x1c(30); cmpwi 3,0; beq 12f; lwz 4,0x7c(30); bl _s802007EC_12; 12:; lwz 3,0x20(30); cmpwi 3,0; beq 13f; lwz 4,0x7c(30); bl _s802007EC_13; 13:; lwz 3,0x24(30); cmpwi 3,0; beq 14f; lwz 4,0x7c(30); bl _s802007EC_14; 14:; bl _s802007EC_15; bl _s802007EC_16; bl _s802007EC_17; bl _s802007EC_18; bl _s802007EC_19; bl _s802007EC_20; bl _s802007EC_21; bl _s802007EC_22; bl _s802007EC_23; bl _s802007EC_24; bl _s802007EC_25; bl _s802007EC_26; bl _s802007EC_27; bl _s802007EC_28; bl _s802007EC_29; bl _s802007EC_30; bl _s802007EC_31; bl _s802007EC_32; bl _s802007EC_33; bl _s802007EC_34; bl _s802007EC_35; bl _s802007EC_36; bl _s802007EC_37; bl _s802007EC_38; bl _s802007EC_39; bl _s802007EC_40; bl _s802007EC_41; addi 3,30,148; li 4,2; bl _s802007EC_42; lis 9,-32698; andi. 0,28,1; addi 9,9,-12328; stw 9,0x80(30); beq 15f; mr 3,30; bl _s802007EC_43; 15:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802007EC_0();
extern "C" void _s802007EC_1();
extern "C" void _s802007EC_2();
extern "C" void _s802007EC_3();
extern "C" void _s802007EC_4();
extern "C" void _s802007EC_5();
extern "C" void _s802007EC_6();
extern "C" void _s802007EC_7();
extern "C" void _s802007EC_8();
extern "C" void _s802007EC_9();
extern "C" void _s802007EC_10();
extern "C" void _s802007EC_11();
extern "C" void _s802007EC_12();
extern "C" void _s802007EC_13();
extern "C" void _s802007EC_14();
extern "C" void _s802007EC_15();
extern "C" void _s802007EC_16();
extern "C" void _s802007EC_17();
extern "C" void _s802007EC_18();
extern "C" void _s802007EC_19();
extern "C" void _s802007EC_20();
extern "C" void _s802007EC_21();
extern "C" void _s802007EC_22();
extern "C" void _s802007EC_23();
extern "C" void _s802007EC_24();
extern "C" void _s802007EC_25();
extern "C" void _s802007EC_26();
extern "C" void _s802007EC_27();
extern "C" void _s802007EC_28();
extern "C" void _s802007EC_29();
extern "C" void _s802007EC_30();
extern "C" void _s802007EC_31();
extern "C" void _s802007EC_32();
extern "C" void _s802007EC_33();
extern "C" void _s802007EC_34();
extern "C" void _s802007EC_35();
extern "C" void _s802007EC_36();
extern "C" void _s802007EC_37();
extern "C" void _s802007EC_38();
extern "C" void _s802007EC_39();
extern "C" void _s802007EC_40();
extern "C" void _s802007EC_41();
extern "C" void _s802007EC_42();
extern "C" void _s802007EC_43();
extern "C" void f_802007EC() {}
