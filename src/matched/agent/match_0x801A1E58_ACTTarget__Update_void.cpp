// 0x801A1E58 ACTTarget::Update(void) (916 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 24,0x40(1); stw 0,0x64(1); mr 29,3; lwz 0,0xcc(29); cmpwi 0,0; beq 18f; bl _s801A1E58_0; mr 31,3; bl _s801A1E58_1; cmpwi 3,0; beq 3f; lwz 4,0xdc(29); mr 3,31; li 5,0; lis 30,-32697; bl _s801A1E58_2; li 31,0; mr 28,3; lwz 4,0xdc(29); addi 3,30,24012; bl _s801A1E58_3; cmpwi 3,0; beq 0f; lwz 4,0xdc(29); addi 3,30,24012; bl _s801A1E58_4; lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 0f; li 31,1; 0:; lwz 0,0xd0(29); cmpwi 0,0; beq 2f; cmpwi 28,0; bne 1f; cmpwi 31,0; beq 4f; 1:; mr 3,29; bl _s801A1E58_5; b 4f; 2:; cmpwi 28,0; bne 4f; cmpwi 31,0; bne 4f; mr 3,29; bl _s801A1E58_6; b 4f; 3:; mr 3,29; bl _s801A1E58_7; 4:; lwz 0,0xd8(29); cmpwi 0,0; beq 5f; lis 9,-32697; lwz 4,0xdc(29); lwz 3,0x5bcc(9); bl _s801A1E58_8; cmpwi 3,1; beq 5f; mr 3,29; bl _s801A1E58_9; 5:; lwz 0,0xd4(29); cmpwi 0,0; bne 7f; lwz 0,0xd8(29); cmpwi 0,0; beq 6f; lwz 0,0xd0(29); cmpwi 0,0; bne 7f; addi 3,1,16; lis 30,-32705; bl _s801A1E58_10; lwz 6,0xdc(29); addi 3,1,16; addi 4,30,-8796; li 5,1; bl _s801A1E58_11; lwz 7,-31408(13); addi 3,1,16; lwz 8,0xdc(29); li 5,250; li 6,0; addi 4,30,-8796; bl _s801A1E58_12; lwz 4,0xe0(29); addi 3,1,16; bl _s801A1E58_13; li 4,255; addi 3,1,16; bl _s801A1E58_14; addi 3,1,16; bl _s801A1E58_15; li 0,1; addi 3,1,16; stw 0,0xd4(29); li 4,2; stw 0,0xd0(29); bl _s801A1E58_16; b 7f; 6:; lwz 0,0xd0(29); cmpwi 0,0; beq 7f; addi 3,1,16; bl _s801A1E58_17; lwz 7,-31396(13); lis 4,-32705; lwz 8,0xdc(29); addi 3,1,16; li 5,250; li 6,0; addi 4,4,-8796; bl _s801A1E58_18; lwz 4,0xe0(29); addi 3,1,16; addi 4,4,22; bl _s801A1E58_19; li 4,0; addi 3,1,16; bl _s801A1E58_20; addi 3,1,16; bl _s801A1E58_21; li 0,1; addi 3,1,16; stw 0,0xd4(29); li 4,2; bl _s801A1E58_22; 7:; addi 9,29,1616; addi 8,1,48; lwz 11,0x4(9); li 10,0; lwz 0,0x0(11); stw 11,0x30(1); stw 0,0x34(1); mr 27,9; b 9f; 8:; lwz 0,0x0(9); addi 10,10,1; stw 0,0x34(1); 9:; lwz 9,0x34(1); li 11,1; lwz 0,0x0(8); cmpw 9,0; bne 10f; li 11,0; 10:; cmpwi 11,0; bne 8b; cmpwi 10,0; beq 18f; lis 9,-32697; addi 26,1,56; addi 24,9,24200; mr 25,27; 11:; lwz 9,0x4(27); mr 3,29; lwz 0,0x0(9); stw 0,0x10(1); bl _s801A1E58_23; mr. 28,3; beq 14f; lwz 3,0x10(1); lwz 31,0x8(3); cmpwi 3,0; stw 3,0x28(1); lwz 30,0x0(3); lwz 9,0x4(3); stw 30,0x0(9); stw 9,0x4(30); beq 12f; li 4,12; bl _s801A1E58_24; 12:; lwz 5,0xdc(29); stw 30,0x18(1); rlwinm 0,5,2,0,29; lwzx 8,24,0; lwz 9,0x0(31); cmpw 8,9; bne 13f; lwz 0,0x14(31); mr 3,29; lwz 6,0x4(31); mr 4,28; lwz 7,0x8(31); addi 9,31,12; lwz 10,0x10(31); stw 0,0x8(1); lwz 0,0x18(31); stw 0,0xc(1); bl _s801A1E58_25; 13:; cmpwi 31,0; beq 14f; lwz 9,0x1c(31); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,31,3; mtspr 8,0; blrl; 14:; lwz 9,0x4(25); li 10,0; lwz 0,0x0(9); stw 9,0x38(1); b 16f; 15:; lwz 0,0x0(9); addi 10,10,1; 16:; stw 0,0x3c(1); lwz 9,0x3c(1); li 11,1; lwz 0,0x0(26); cmpw 9,0; bne 17f; li 11,0; 17:; cmpwi 11,0; bne 15b; cmpwi 10,0; beq 18f; cmpwi 28,0; bne 11b; 18:; lwz 0,0x64(1); mtspr 8,0; lmw 24,0x40(1); addi 1,1,96"
extern "C" void _s801A1E58_0();
extern "C" void _s801A1E58_1();
extern "C" void _s801A1E58_2();
extern "C" void _s801A1E58_3();
extern "C" void _s801A1E58_4();
extern "C" void _s801A1E58_5();
extern "C" void _s801A1E58_6();
extern "C" void _s801A1E58_7();
extern "C" void _s801A1E58_8();
extern "C" void _s801A1E58_9();
extern "C" void _s801A1E58_10();
extern "C" void _s801A1E58_11();
extern "C" void _s801A1E58_12();
extern "C" void _s801A1E58_13();
extern "C" void _s801A1E58_14();
extern "C" void _s801A1E58_15();
extern "C" void _s801A1E58_16();
extern "C" void _s801A1E58_17();
extern "C" void _s801A1E58_18();
extern "C" void _s801A1E58_19();
extern "C" void _s801A1E58_20();
extern "C" void _s801A1E58_21();
extern "C" void _s801A1E58_22();
extern "C" void _s801A1E58_23();
extern "C" void _s801A1E58_24();
extern "C" void _s801A1E58_25();
extern "C" void f_801A1E58() {}
