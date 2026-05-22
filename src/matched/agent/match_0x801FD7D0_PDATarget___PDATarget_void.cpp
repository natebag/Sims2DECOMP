// 0x801FD7D0 PDATarget::~PDATarget(void) (1172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 19,0x3c(1); stw 0,0x74(1); lis 9,-32697; lis 11,-32697; mr 29,3; addi 9,9,-32720; addi 11,11,-32672; stw 9,0x108(29); stw 11,0x80(29); mr 19,4; li 31,0; li 30,2; 0:; addi 9,29,316; lwzx 11,9,31; cmpwi 11,0; beq 1f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 9,29,308; lwzx 11,9,31; cmpwi 11,0; beq 2f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 2:; addi 9,29,268; lwzx 11,9,31; cmpwi 11,0; beq 3f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 3:; addi 9,29,276; lwzx 11,9,31; cmpwi 11,0; beq 4f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 4:; addi 9,29,284; lwzx 11,9,31; cmpwi 11,0; beq 5f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 5:; addi 9,29,292; lwzx 11,9,31; cmpwi 11,0; beq 6f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 6:; addi 9,29,300; lwzx 11,9,31; cmpwi 11,0; beq 7f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 7:; addi 9,29,324; lwzx 11,9,31; cmpwi 11,0; beq 8f; lwz 9,0x80(11); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,11,3; mtspr 8,0; blrl; 8:; addi 31,31,4; addic. 30,30,-1; bne 0b; lis 9,-32697; li 22,1; lwz 0,0x5c70(9); cmpwi 0,0; bne 9f; li 22,0; 9:; lwz 0,0x0(29); cmpwi 0,0; beq 19f; lwz 3,0x4(29); addi 4,29,40; bl _s801FD7D0_0; lwz 3,0x8(29); addi 4,29,56; bl _s801FD7D0_1; lwz 3,0xc(29); addi 4,29,72; bl _s801FD7D0_2; addi 9,29,88; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 10f; lwz 0,0x58(29); cmpwi 0,0; beq 11f; 10:; li 11,1; 11:; cmpwi 11,0; beq 12f; lwz 3,0x10(29); bl _s801FD7D0_3; 12:; addi 9,29,104; li 11,0; lwz 0,0x8(9); mr 4,9; cmpwi 0,0; bne 13f; lwz 0,0x68(29); cmpwi 0,0; beq 14f; 13:; li 11,1; 14:; cmpwi 11,0; beq 15f; lwz 3,0x14(29); bl _s801FD7D0_4; 15:; lwz 3,0x18(29); cmpwi 3,0; beq 16f; lwz 4,0x7c(29); bl _s801FD7D0_5; 16:; lwz 3,0x1c(29); cmpwi 3,0; beq 17f; lwz 4,0x7c(29); bl _s801FD7D0_6; 17:; lwz 3,0x20(29); cmpwi 3,0; beq 18f; lwz 4,0x7c(29); bl _s801FD7D0_7; 18:; lwz 3,0x24(29); cmpwi 3,0; beq 19f; lwz 4,0x7c(29); bl _s801FD7D0_8; 19:; lwz 0,0x15c(29); cmpwi 0,0; beq 20f; lwz 3,-21496(13); lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; 20:; li 27,0; addi 20,29,132; cmpw 27,22; bgt 23f; lis 9,-32697; lis 11,-32698; addi 21,9,24012; addi 26,11,-10560; addi 28,1,8; li 24,0; li 25,0; addi 23,29,352; 21:; lwzx 5,23,25; mr 4,27; lwz 3,0xb4(21); bl _s801FD7D0_9; stw 26,0x10(28); stw 24,0x8(1); stw 27,0xc(1); stw 24,0x14(1); stw 24,0x10(1); bl _s801FD7D0_10; lwz 31,0x4(28); mr 30,3; mr 4,31; bl _s801FD7D0_11; cmpwi 3,0; beq 22f; li 0,1; lbz 9,0x3c(30); slw 0,0,31; rlwinm 0,0,0,24,31; and. 11,9,0; bne 22f; or 0,0,9; li 3,20; stb 0,0x3c(30); bl _s801FD7D0_12; lwz 11,0x8(28); rlwinm 8,31,3,0,28; lwz 9,0xc(28); lwz 10,0x4(28); lwz 0,0x8(1); stw 11,0x8(3); stw 10,0x4(3); stw 9,0xc(3); stw 0,0x0(3); stw 26,0x10(3); stw 26,0x20(1); lwz 9,0x2c(30); stw 0,0x30(1); stw 3,0x34(1); add 11,9,8; stw 0,0x28(1); stw 3,0x2c(1); stwx 0,9,8; stw 3,0x4(11); 22:; addi 27,27,1; stw 26,0x10(28); addi 25,25,4; cmpw 27,22; ble 21b; 23:; lwz 0,0x16c(29); cmpwi 0,0; beq 24f; bl _s801FD7D0_13; 24:; lwz 9,-26392(13); li 0,1; stw 0,0x320(9); bl _s801FD7D0_14; bl _s801FD7D0_15; bl _s801FD7D0_16; bl _s801FD7D0_17; bl _s801FD7D0_18; bl _s801FD7D0_19; bl _s801FD7D0_20; bl _s801FD7D0_21; bl _s801FD7D0_22; bl _s801FD7D0_23; bl _s801FD7D0_24; bl _s801FD7D0_25; bl _s801FD7D0_26; bl _s801FD7D0_27; bl _s801FD7D0_28; bl _s801FD7D0_29; bl _s801FD7D0_30; bl _s801FD7D0_31; bl _s801FD7D0_32; bl _s801FD7D0_33; bl _s801FD7D0_34; bl _s801FD7D0_35; bl _s801FD7D0_36; bl _s801FD7D0_37; bl _s801FD7D0_38; bl _s801FD7D0_39; bl _s801FD7D0_40; bl _s801FD7D0_41; mr 3,20; li 4,0; bl _s801FD7D0_42; lis 9,-32698; andi. 0,19,1; addi 9,9,-12328; stw 9,0x80(29); beq 25f; mr 3,29; bl _s801FD7D0_43; 25:; lwz 0,0x74(1); mtspr 8,0; lmw 19,0x3c(1); addi 1,1,112"
extern "C" void _s801FD7D0_0();
extern "C" void _s801FD7D0_1();
extern "C" void _s801FD7D0_2();
extern "C" void _s801FD7D0_3();
extern "C" void _s801FD7D0_4();
extern "C" void _s801FD7D0_5();
extern "C" void _s801FD7D0_6();
extern "C" void _s801FD7D0_7();
extern "C" void _s801FD7D0_8();
extern "C" void _s801FD7D0_9();
extern "C" void _s801FD7D0_10();
extern "C" void _s801FD7D0_11();
extern "C" void _s801FD7D0_12();
extern "C" void _s801FD7D0_13();
extern "C" void _s801FD7D0_14();
extern "C" void _s801FD7D0_15();
extern "C" void _s801FD7D0_16();
extern "C" void _s801FD7D0_17();
extern "C" void _s801FD7D0_18();
extern "C" void _s801FD7D0_19();
extern "C" void _s801FD7D0_20();
extern "C" void _s801FD7D0_21();
extern "C" void _s801FD7D0_22();
extern "C" void _s801FD7D0_23();
extern "C" void _s801FD7D0_24();
extern "C" void _s801FD7D0_25();
extern "C" void _s801FD7D0_26();
extern "C" void _s801FD7D0_27();
extern "C" void _s801FD7D0_28();
extern "C" void _s801FD7D0_29();
extern "C" void _s801FD7D0_30();
extern "C" void _s801FD7D0_31();
extern "C" void _s801FD7D0_32();
extern "C" void _s801FD7D0_33();
extern "C" void _s801FD7D0_34();
extern "C" void _s801FD7D0_35();
extern "C" void _s801FD7D0_36();
extern "C" void _s801FD7D0_37();
extern "C" void _s801FD7D0_38();
extern "C" void _s801FD7D0_39();
extern "C" void _s801FD7D0_40();
extern "C" void _s801FD7D0_41();
extern "C" void _s801FD7D0_42();
extern "C" void _s801FD7D0_43();
extern "C" void f_801FD7D0() {}
