// 0x80193334 CASTarget::GetLocalizable(char (1524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8288(1); mfspr 0,8; stmw 29,0x2054(1); stw 0,0x2064(1); mr 30,4; li 0,0; lbz 9,0x0(30); mr 31,3; sth 0,0x8(1); addi 9,9,-48; cmplwi 9,1; bgt 0f; addi 30,30,1; 0:; lis 3,-32705; mr 4,30; addi 3,3,-16676; bl _s80193334_0; mr 29,3; cmpwi 29,0; bne 28f; lwz 30,0x90(31); cmpwi 30,11; beq 16f; bgt 3f; cmpwi 30,5; beq 8f; bgt 1f; cmpwi 30,3; beq 6f; bgt 7f; cmpwi 30,0; beq 27f; b 45f; 1:; cmpwi 30,8; beq 10f; bgt 2f; cmpwi 30,6; beq 9f; b 45f; 2:; cmpwi 30,9; beq 11f; cmpwi 30,10; beq 12f; b 45f; 3:; cmpwi 30,17; beq 18f; bgt 4f; cmpwi 30,13; beq 13f; blt 14f; cmpwi 30,14; beq 15f; cmpwi 30,16; beq 17f; b 45f; 4:; cmpwi 30,21; beq 20f; bgt 5f; cmpwi 30,20; beq 19f; b 45f; 5:; cmpwi 30,23; beq 21f; cmpwi 30,24; beq 24f; b 45f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15968; addi 3,1,8200; crxor 6,6,6; bl _s80193334_1; lwz 9,0x2008(1); b 22f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15952; addi 3,1,8204; crxor 6,6,6; bl _s80193334_2; lwz 9,0x200c(1); b 22f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15940; addi 3,1,8208; crxor 6,6,6; bl _s80193334_3; lwz 9,0x2010(1); b 22f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15928; addi 3,1,8212; crxor 6,6,6; bl _s80193334_4; lwz 9,0x2014(1); b 22f; 10:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15908; addi 3,1,8216; crxor 6,6,6; bl _s80193334_5; lwz 9,0x2018(1); b 22f; 11:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15888; addi 3,1,8220; crxor 6,6,6; bl _s80193334_6; lwz 9,0x201c(1); b 22f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15864; addi 3,1,8224; crxor 6,6,6; bl _s80193334_7; lwz 9,0x2020(1); b 25f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15844; addi 3,1,8228; crxor 6,6,6; bl _s80193334_8; lwz 9,0x2024(1); b 22f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15824; addi 3,1,8232; crxor 6,6,6; bl _s80193334_9; lwz 9,0x2028(1); b 22f; 15:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15808; addi 3,1,8236; crxor 6,6,6; bl _s80193334_10; lwz 9,0x202c(1); b 22f; 16:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15788; addi 3,1,8240; crxor 6,6,6; bl _s80193334_11; lwz 9,0x2030(1); b 22f; 17:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15764; addi 3,1,8244; crxor 6,6,6; bl _s80193334_12; lwz 9,0x2034(1); b 25f; 18:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15740; addi 3,1,8248; crxor 6,6,6; bl _s80193334_13; lwz 9,0x2038(1); b 22f; 19:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15712; addi 3,1,8252; crxor 6,6,6; bl _s80193334_14; lwz 9,0x203c(1); b 22f; 20:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15688; addi 3,1,8256; crxor 6,6,6; bl _s80193334_15; lwz 9,0x2040(1); b 22f; 21:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15664; addi 3,1,8260; crxor 6,6,6; bl _s80193334_16; lwz 9,0x2044(1); 22:; li 4,0; cmpwi 9,0; beq 23f; lwz 4,0x0(9); 23:; addi 3,1,8; li 5,4096; bl _s80193334_17; sth 29,0x2006(1); b 45f; 24:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15648; addi 3,1,8264; crxor 6,6,6; bl _s80193334_18; lwz 9,0x2048(1); 25:; li 4,0; cmpwi 9,0; beq 26f; lwz 4,0x0(9); 26:; addi 3,1,8; li 5,4096; bl _s80193334_19; li 0,0; sth 0,0x2006(1); b 45f; 27:; lis 4,-32705; addi 3,1,8; addi 4,4,-17308; li 5,4096; bl _s80193334_20; sth 30,0x2006(1); b 45f; 28:; lis 3,-32705; mr 4,30; addi 3,3,-15628; li 5,17; bl _s80193334_21; cmpwi 3,0; bne 42f; addi 3,30,17; bl _s80193334_22; lwz 0,0x90(31); mr 5,3; cmpwi 0,9; beq 38f; bgt 30f; cmpwi 0,4; beq 34f; bgt 29f; cmpwi 0,0; beq 41f; cmpwi 0,3; beq 40f; b 45f; 29:; cmpwi 0,6; beq 36f; blt 33f; cmpwi 0,8; beq 36f; b 45f; 30:; cmpwi 0,14; bgt 31f; cmpwi 0,11; bge 34f; b 35f; 31:; cmpwi 0,20; beq 37f; bgt 32f; cmpwi 0,17; beq 35f; b 45f; 32:; cmpwi 0,24; beq 39f; b 45f; 33:; mr 4,5; lwz 3,0x1378(31); addi 5,1,8; bl _s80193334_23; b 45f; 34:; lwz 4,0x90(31); addi 6,1,8; lwz 3,0x1380(31); bl _s80193334_24; b 45f; 35:; lwz 4,0x90(31); addi 6,1,8; lwz 3,0x1384(31); bl _s80193334_25; b 45f; 36:; lwz 4,0x90(31); addi 6,1,8; lwz 3,0x1374(31); bl _s80193334_26; b 45f; 37:; lwz 3,0x1388(31); li 4,20; addi 6,1,8; bl _s80193334_27; b 45f; 38:; mr 4,5; lwz 3,0x138c(31); addi 5,1,8; bl _s80193334_28; b 45f; 39:; mr 4,5; lwz 3,0x1390(31); addi 5,1,8; bl _s80193334_29; b 45f; 40:; mr 4,5; lwz 3,0x1370(31); addi 5,1,8; bl _s80193334_30; b 45f; 41:; lis 4,-32705; addi 3,1,8; addi 4,4,-17308; li 5,4096; bl _s80193334_31; b 45f; 42:; lis 3,-32705; mr 4,30; addi 3,3,-16500; bl _s80193334_32; mr 31,3; cmpwi 31,0; bne 44f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-15608; addi 3,1,8268; crxor 6,6,6; bl _s80193334_33; lwz 9,0x204c(1); li 4,0; cmpwi 9,0; beq 43f; lwz 4,0x0(9); 43:; addi 3,1,8; li 5,4096; bl _s80193334_34; sth 31,0x2006(1); b 45f; 44:; li 3,0; b 46f; 45:; addi 3,1,8; bl _s80193334_35; addi 3,1,8; bl _s80193334_36; addi 3,1,8; bl _s80193334_37; addi 3,1,8; bl _s80193334_38; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s80193334_39; mr 30,3; addi 3,1,8; bl _s80193334_40; addi 5,3,1; addi 4,1,8; mr 3,30; bl _s80193334_41; mr 3,30; 46:; lwz 0,0x2064(1); mtspr 8,0; lmw 29,0x2054(1); addi 1,1,8288"
extern "C" void _s80193334_0();
extern "C" void _s80193334_1();
extern "C" void _s80193334_2();
extern "C" void _s80193334_3();
extern "C" void _s80193334_4();
extern "C" void _s80193334_5();
extern "C" void _s80193334_6();
extern "C" void _s80193334_7();
extern "C" void _s80193334_8();
extern "C" void _s80193334_9();
extern "C" void _s80193334_10();
extern "C" void _s80193334_11();
extern "C" void _s80193334_12();
extern "C" void _s80193334_13();
extern "C" void _s80193334_14();
extern "C" void _s80193334_15();
extern "C" void _s80193334_16();
extern "C" void _s80193334_17();
extern "C" void _s80193334_18();
extern "C" void _s80193334_19();
extern "C" void _s80193334_20();
extern "C" void _s80193334_21();
extern "C" void _s80193334_22();
extern "C" void _s80193334_23();
extern "C" void _s80193334_24();
extern "C" void _s80193334_25();
extern "C" void _s80193334_26();
extern "C" void _s80193334_27();
extern "C" void _s80193334_28();
extern "C" void _s80193334_29();
extern "C" void _s80193334_30();
extern "C" void _s80193334_31();
extern "C" void _s80193334_32();
extern "C" void _s80193334_33();
extern "C" void _s80193334_34();
extern "C" void _s80193334_35();
extern "C" void _s80193334_36();
extern "C" void _s80193334_37();
extern "C" void _s80193334_38();
extern "C" void _s80193334_39();
extern "C" void _s80193334_40();
extern "C" void _s80193334_41();
extern "C" void f_80193334() {}
