// 0x80082DBC MUWrapper::SetupQueryType(void) (1404 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 28,0x68(1); stw 0,0x7c(1); mr 31,3; li 30,1; lwz 0,0xb8(31); cmpwi 0,7; beq 16f; bgt 1f; cmpwi 0,3; beq 8f; bgt 0f; cmpwi 0,1; beq 4f; bgt 6f; b 30f; 0:; cmpwi 0,5; beq 12f; bgt 14f; b 10f; 1:; cmpwi 0,11; beq 24f; bgt 2f; cmpwi 0,9; beq 20f; bgt 22f; b 18f; 2:; cmpwi 0,24; bgt 3f; cmpwi 0,21; bge 31f; cmpwi 0,12; beq 26f; b 30f; 3:; cmpwi 0,25; beq 16f; b 30f; 4:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,8; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_0; lis 29,-32707; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_1; addi 4,28,24012; addi 5,29,27740; addi 3,1,12; crxor 6,6,6; bl _s80082DBC_2; lwz 9,0xc(1); b 28f; 6:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,16; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_3; lis 29,-32707; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_4; addi 4,28,24012; addi 5,29,27740; addi 3,1,20; crxor 6,6,6; bl _s80082DBC_5; lwz 9,0x14(1); b 28f; 8:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,24; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_6; lis 29,-32707; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_7; addi 4,28,24012; addi 5,29,27740; addi 3,1,28; crxor 6,6,6; bl _s80082DBC_8; lwz 9,0x1c(1); b 28f; 10:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,32; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_9; lis 29,-32707; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_10; addi 4,28,24012; addi 5,29,27740; addi 3,1,36; crxor 6,6,6; bl _s80082DBC_11; lwz 9,0x24(1); b 28f; 12:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,40; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_12; lis 29,-32707; lwz 9,0x28(1); li 4,0; cmpwi 9,0; beq 13f; lwz 4,0x0(9); 13:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_13; addi 4,28,24012; addi 5,29,27740; addi 3,1,44; crxor 6,6,6; bl _s80082DBC_14; lwz 9,0x2c(1); b 28f; 14:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,48; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_15; lis 29,-32707; lwz 9,0x30(1); li 4,0; cmpwi 9,0; beq 15f; lwz 4,0x0(9); 15:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_16; addi 4,28,24012; addi 5,29,27740; addi 3,1,52; crxor 6,6,6; bl _s80082DBC_17; lwz 9,0x34(1); b 28f; 16:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,56; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_18; lis 29,-32707; lwz 9,0x38(1); li 4,0; cmpwi 9,0; beq 17f; lwz 4,0x0(9); 17:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_19; addi 4,28,24012; addi 5,29,27740; addi 3,1,60; crxor 6,6,6; bl _s80082DBC_20; lwz 9,0x3c(1); b 28f; 18:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,64; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_21; lis 29,-32707; lwz 9,0x40(1); li 4,0; cmpwi 9,0; beq 19f; lwz 4,0x0(9); 19:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_22; addi 4,28,24012; addi 5,29,27740; addi 3,1,68; crxor 6,6,6; bl _s80082DBC_23; lwz 9,0x44(1); b 28f; 20:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,72; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_24; lis 29,-32707; lwz 9,0x48(1); li 4,0; cmpwi 9,0; beq 21f; lwz 4,0x0(9); 21:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_25; addi 4,28,24012; addi 5,29,27740; addi 3,1,76; crxor 6,6,6; bl _s80082DBC_26; lwz 9,0x4c(1); b 28f; 22:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,80; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_27; lis 29,-32707; lwz 9,0x50(1); li 4,0; cmpwi 9,0; beq 23f; lwz 4,0x0(9); 23:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_28; addi 4,28,24012; addi 5,29,27740; addi 3,1,84; crxor 6,6,6; bl _s80082DBC_29; lwz 9,0x54(1); b 28f; 24:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,88; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_30; lis 29,-32707; lwz 9,0x58(1); li 4,0; cmpwi 9,0; beq 25f; lwz 4,0x0(9); 25:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_31; addi 4,28,24012; addi 5,29,27740; addi 3,1,92; crxor 6,6,6; bl _s80082DBC_32; lwz 9,0x5c(1); b 28f; 26:; lis 4,-32697; lis 5,-32707; addi 4,4,24012; addi 5,5,27740; addi 3,1,96; lis 28,-32697; crxor 6,6,6; bl _s80082DBC_33; lis 29,-32707; lwz 9,0x60(1); li 4,0; cmpwi 9,0; beq 27f; lwz 4,0x0(9); 27:; lwz 9,0xa8(31); lwz 3,0x60(9); bl _s80082DBC_34; addi 4,28,24012; addi 5,29,27740; addi 3,1,100; crxor 6,6,6; bl _s80082DBC_35; lwz 9,0x64(1); 28:; li 4,0; cmpwi 9,0; beq 29f; lwz 4,0x0(9); 29:; lwz 9,0xa8(31); lwz 3,0x64(9); bl _s80082DBC_36; b 31f; 30:; li 30,0; 31:; cmpwi 30,0; beq 32f; lwz 9,0xa8(31); lwz 11,0x60(9); lwz 0,0x4(11); ori 0,0,1; stw 0,0x4(11); lwz 9,0xa8(31); lwz 11,0x64(9); lwz 0,0x4(11); ori 0,0,1; stw 0,0x4(11); 32:; lwz 0,0x7c(1); mtspr 8,0; lmw 28,0x68(1); addi 1,1,120"
extern "C" void _s80082DBC_0();
extern "C" void _s80082DBC_1();
extern "C" void _s80082DBC_2();
extern "C" void _s80082DBC_3();
extern "C" void _s80082DBC_4();
extern "C" void _s80082DBC_5();
extern "C" void _s80082DBC_6();
extern "C" void _s80082DBC_7();
extern "C" void _s80082DBC_8();
extern "C" void _s80082DBC_9();
extern "C" void _s80082DBC_10();
extern "C" void _s80082DBC_11();
extern "C" void _s80082DBC_12();
extern "C" void _s80082DBC_13();
extern "C" void _s80082DBC_14();
extern "C" void _s80082DBC_15();
extern "C" void _s80082DBC_16();
extern "C" void _s80082DBC_17();
extern "C" void _s80082DBC_18();
extern "C" void _s80082DBC_19();
extern "C" void _s80082DBC_20();
extern "C" void _s80082DBC_21();
extern "C" void _s80082DBC_22();
extern "C" void _s80082DBC_23();
extern "C" void _s80082DBC_24();
extern "C" void _s80082DBC_25();
extern "C" void _s80082DBC_26();
extern "C" void _s80082DBC_27();
extern "C" void _s80082DBC_28();
extern "C" void _s80082DBC_29();
extern "C" void _s80082DBC_30();
extern "C" void _s80082DBC_31();
extern "C" void _s80082DBC_32();
extern "C" void _s80082DBC_33();
extern "C" void _s80082DBC_34();
extern "C" void _s80082DBC_35();
extern "C" void _s80082DBC_36();
extern "C" void f_80082DBC() {}
