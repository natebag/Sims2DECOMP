// 0x801C7168 MMUTarget::OnXKeyPressed(char (1636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-376(1); mfspr 0,8; mfcr 12; stmw 28,0x168(1); stw 0,0x17c(1); stw 12,0x164(1); mr 31,3; lwz 0,0x8c(31); cmpwi 0,2; bne 0f; li 4,-1; bl _s801C7168_0; b 33f; 0:; cmpwi 0,1; bne 2f; lis 9,-32697; addi 9,9,23428; lwz 0,0xf0(9); cmpwi 0,0; beq 1f; lwz 0,0xe8(9); cmpwi 0,0; beq 1f; mr 3,31; bl _s801C7168_1; b 33f; 1:; mr 3,31; bl _s801C7168_2; b 33f; 2:; lwz 8,0xb0(31); cmpwi 8,1; bne 13f; lwz 0,0xa4(31); cmpwi 0,2; bne 12f; li 29,0; lis 28,-32697; stw 29,0x110(31); lis 5,-32705; stw 29,0x118(31); addi 4,28,24012; addi 5,5,-1340; stw 0,0x104(31); addi 3,1,280; addi 30,31,308; crxor 6,6,6; bl _s801C7168_3; lwz 9,0x118(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s801C7168_4; addi 30,31,312; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-1344; addi 3,1,284; crxor 6,6,6; bl _s801C7168_5; lwz 9,0x11c(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s801C7168_6; addi 30,31,300; lis 5,-32705; addi 4,28,24012; addi 5,5,11600; addi 3,1,288; crxor 6,6,6; bl _s801C7168_7; lwz 9,0x120(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; cmpwi 4,31,0; bl _s801C7168_8; lis 4,-32705; addi 3,31,304; addi 4,4,-8284; bl _s801C7168_9; lis 9,-32705; stw 29,0x124(31); addi 9,9,11620; lis 10,-32708; lwz 11,0x0(9); lwz 12,0x4(9); addi 4,1,296; addi 30,10,-30820; stw 31,0x10(1); stw 11,0x128(1); stw 12,0x12c(1); beq cr4,6f; addi 3,1,8; li 5,8; bl _s801C7168_10; b 7f; 6:; stw 31,0x8(1); 7:; lis 9,-32705; stw 30,0x14(1); addi 9,9,11628; addi 11,1,8; lwz 4,0x8(1); addi 8,31,340; lwz 6,0x0(9); lwz 7,0x4(9); lis 10,-32708; lwz 5,0x4(11); mr 30,11; lwz 9,0x8(11); addi 29,10,-31060; lwz 0,0xc(11); stw 4,0x154(31); addi 11,1,304; stw 0,0xc(8); stw 5,0x4(8); stw 9,0x8(8); stw 6,0x130(1); stw 7,0x134(1); stw 31,0x10(1); beq cr4,8f; mr 4,11; mr 3,30; li 5,8; bl _s801C7168_11; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,-1960; lwz 5,0x4(30); addi 11,31,356; lwz 4,0x8(30); addi 0,31,260; lwz 10,0xc(30); mr 29,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 6,0x164(31); lis 9,-32709; stw 10,0xc(11); addi 28,9,14552; stw 5,0x4(11); addi 9,1,312; stw 4,0x8(11); stw 7,0x138(1); stw 8,0x13c(1); stw 0,0x10(1); beq 10f; mr 4,9; mr 3,30; li 5,8; bl _s801C7168_12; b 11f; 10:; stw 29,0x8(1); 11:; stw 28,0x14(1); addi 9,31,372; lwz 8,0x8(1); mr 3,29; b 31f; 12:; cmpwi 0,0; bne 33f; lis 9,-32697; stw 0,0x5c08(9); bl _s801C7168_13; lis 3,-32705; li 4,0; addi 3,3,-2032; bl _s801C7168_14; lis 3,-32705; addi 3,3,11588; bl _s801C7168_15; b 33f; 13:; cmpwi 8,0; bne 18f; lwz 10,0xb8(31); cmpwi 10,0; bne 14f; lis 11,-32697; addi 30,1,24; addi 9,11,23428; li 0,3; stw 8,0xe8(9); lis 4,-32705; addi 4,4,-8800; stw 0,0x5b84(11); li 5,1; mr 3,30; crxor 6,6,6; bl _s801C7168_16; lwz 9,0x80(31); lis 4,-32705; addi 4,4,9936; mr 5,30; b 17f; 14:; cmpwi 10,1; bne 15f; lis 11,-32697; li 0,4; addi 9,11,23428; lis 4,-32705; stw 10,0xe8(9); addi 4,4,-8800; stw 0,0x5b84(11); li 5,1; b 16f; 15:; lwz 0,0xac(31); cmpwi 0,0; bne 33f; cmpwi 10,2; bne 33f; lis 4,-32705; li 5,2; addi 4,4,-8800; 16:; addi 3,1,8; crxor 6,6,6; bl _s801C7168_17; lwz 9,0x80(31); lis 4,-32705; addi 4,4,9936; addi 5,1,8; 17:; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; b 33f; 18:; cmpwi 8,4; bne 32f; lwz 4,0xc0(31); cmpwi 4,0; beq 19f; lwz 0,0x100(31); cmpwi 0,1; ble 33f; 19:; lis 3,-32697; xori 4,4,2; subfic 0,4,0; adde 4,0,4; addi 3,3,23428; bl _s801C7168_18; lwz 30,0xc0(31); cmpwi 30,0; bne 21f; lwz 3,-26524(13); li 4,1; bl _s801C7168_19; cmpwi 3,0; beq 20f; lis 9,-32697; lis 11,-32697; stw 30,-6504(9); addi 11,11,24012; lwz 3,-26524(13); li 0,-1; lwz 10,0xb4(11); li 4,1; stw 0,0x3ac(10); lwz 9,0xb4(11); stw 30,0x3a8(9); bl _s801C7168_20; 20:; lwz 0,0xc0(31); cmpwi 0,0; beq 22f; 21:; lwz 3,-26524(13); li 4,1; bl _s801C7168_21; mr. 0,3; beq 23f; 22:; mr 3,31; bl _s801C7168_22; b 33f; 23:; li 29,1; lis 9,-32697; stw 29,-6504(9); lis 4,-32697; stw 29,0x190(31); lis 5,-32705; stw 29,0x110(31); addi 4,4,24012; stw 29,0x120(31); addi 5,5,11636; stw 0,0x104(31); addi 3,1,320; stw 0,0x118(31); addi 30,31,300; crxor 6,6,6; bl _s801C7168_23; lwz 9,0x140(1); li 4,0; cmpwi 9,0; beq 24f; lwz 4,0x0(9); 24:; mr 3,30; cmpwi 4,31,0; bl _s801C7168_24; lis 4,-32705; addi 3,31,304; addi 4,4,-8284; bl _s801C7168_25; lis 9,-32705; stw 29,0x124(31); addi 9,9,11668; lis 10,-32708; lwz 11,0x0(9); lwz 12,0x4(9); addi 4,1,328; addi 30,10,-30820; stw 31,0x10(1); stw 11,0x148(1); stw 12,0x14c(1); beq cr4,25f; addi 3,1,8; li 5,8; bl _s801C7168_26; b 26f; 25:; stw 31,0x8(1); 26:; lis 9,-32705; stw 30,0x14(1); addi 9,9,11676; addi 11,1,8; lwz 4,0x8(1); addi 8,31,340; lwz 6,0x0(9); lwz 7,0x4(9); lis 10,-32708; lwz 5,0x4(11); mr 30,11; lwz 9,0x8(11); addi 29,10,-31060; lwz 0,0xc(11); stw 4,0x154(31); addi 11,1,336; stw 0,0xc(8); stw 5,0x4(8); stw 9,0x8(8); stw 6,0x150(1); stw 7,0x154(1); stw 31,0x10(1); beq cr4,27f; mr 4,11; mr 3,30; li 5,8; bl _s801C7168_27; b 28f; 27:; stw 31,0x8(1); 28:; stw 29,0x14(1); lis 9,-32705; lwz 5,0x8(1); addi 9,9,11684; lwz 6,0x4(30); addi 11,31,356; lwz 10,0x8(30); addi 4,1,344; lwz 0,0xc(30); stw 5,0x164(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 6,0x4(11); addi 29,9,-31060; stw 10,0x8(11); stw 7,0x158(1); stw 8,0x15c(1); stw 31,0x10(1); beq cr4,29f; mr 3,30; li 5,8; bl _s801C7168_28; b 30f; 29:; stw 31,0x8(1); 30:; stw 29,0x14(1); addi 9,31,372; lwz 8,0x8(1); addi 3,31,260; 31:; lwz 0,0xc(30); lwz 11,0x4(30); lwz 10,0x8(30); stw 8,0x174(31); stw 0,0xc(9); stw 11,0x4(9); stw 10,0x8(9); bl _s801C7168_29; b 33f; 32:; lwz 0,0xac(31); cmpwi 0,0; beq 33f; lwz 0,0xb8(31); cmpwi 0,2; bne 33f; mr 3,31; bl _s801C7168_30; 33:; lwz 0,0x17c(1); lwz 12,0x164(1); mtspr 8,0; lmw 28,0x168(1); mtcrf 8,12; addi 1,1,376"
extern "C" void _s801C7168_0();
extern "C" void _s801C7168_1();
extern "C" void _s801C7168_2();
extern "C" void _s801C7168_3();
extern "C" void _s801C7168_4();
extern "C" void _s801C7168_5();
extern "C" void _s801C7168_6();
extern "C" void _s801C7168_7();
extern "C" void _s801C7168_8();
extern "C" void _s801C7168_9();
extern "C" void _s801C7168_10();
extern "C" void _s801C7168_11();
extern "C" void _s801C7168_12();
extern "C" void _s801C7168_13();
extern "C" void _s801C7168_14();
extern "C" void _s801C7168_15();
extern "C" void _s801C7168_16();
extern "C" void _s801C7168_17();
extern "C" void _s801C7168_18();
extern "C" void _s801C7168_19();
extern "C" void _s801C7168_20();
extern "C" void _s801C7168_21();
extern "C" void _s801C7168_22();
extern "C" void _s801C7168_23();
extern "C" void _s801C7168_24();
extern "C" void _s801C7168_25();
extern "C" void _s801C7168_26();
extern "C" void _s801C7168_27();
extern "C" void _s801C7168_28();
extern "C" void _s801C7168_29();
extern "C" void _s801C7168_30();
extern "C" void f_801C7168() {}
