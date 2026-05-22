// 0x80187224 HUDTarget::GetPlayerVariable(int, (1212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; mr 30,5; mr 28,4; li 3,32; bl _s80187224_0; mr 31,3; li 0,0; lis 3,-32705; stb 0,0x0(31); addi 3,3,-19964; mr 4,30; li 5,7; bl _s80187224_1; cmpwi 3,0; bne 0f; lbz 30,0x7(30); mr 4,28; mr 3,29; extsb 30,30; addi 30,30,-48; mr 5,30; bl _s80187224_2; mulli 0,28,6; addi 9,29,164; lis 4,-32705; addi 4,4,-19956; mr 3,31; add 30,30,0; lbzx 5,9,30; crxor 6,6,6; bl _s80187224_3; b 32f; 0:; lis 3,-32705; mr 4,30; addi 3,3,-19952; bl _s80187224_4; cmpwi 3,0; bne 1f; mr 4,28; mr 3,29; bl _s80187224_5; b 25f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-19944; li 5,12; bl _s80187224_6; cmpwi 3,0; bne 2f; lis 4,-32705; lhz 5,0xca(29); b 26f; 2:; lis 3,-32705; mr 4,30; addi 3,3,-19928; li 5,11; bl _s80187224_7; cmpwi 3,0; bne 16f; lhz 3,0xc8(29); cmpwi 3,5; beq 9f; bgt 4f; cmpwi 3,2; beq 6f; bgt 3f; cmpwi 3,1; beq 5f; b 32f; 3:; cmpwi 3,3; beq 7f; cmpwi 3,4; beq 8f; b 32f; 4:; cmpwi 3,7; beq 12f; blt 11f; cmpwi 3,8; beq 13f; cmpwi 3,9; beq 14f; b 32f; 5:; lis 9,-32705; addi 11,9,-19916; lwz 0,-19916(9); lhz 10,0x4(11); stw 0,0x0(31); sth 10,0x4(31); b 32f; 6:; lis 9,-32705; addi 11,9,-19908; lwz 10,-19908(9); b 10f; 7:; lis 9,-32705; addi 11,9,-19896; lwz 10,-19896(9); b 15f; 8:; lis 9,-32705; addi 11,9,-19884; lwz 10,-19884(9); b 10f; 9:; lis 9,-32705; addi 11,9,-19872; lwz 10,-19872(9); 10:; lbz 8,0x8(11); lwz 0,0x4(11); stw 10,0x0(31); stw 0,0x4(31); stb 8,0x8(31); b 32f; 11:; lis 9,-32705; addi 11,9,-19860; lwz 10,-19860(9); b 23f; 12:; lis 9,-32705; addi 11,9,-19852; lwz 0,-19852(9); lwz 10,0x4(11); stw 0,0x0(31); stw 10,0x4(31); b 32f; 13:; lis 9,-32705; addi 11,9,-19844; lwz 10,-19844(9); b 23f; 14:; lis 9,-32705; addi 11,9,-19836; lwz 10,-19836(9); 15:; lhz 8,0x8(11); lwz 0,0x4(11); stw 10,0x0(31); stw 0,0x4(31); sth 8,0x8(31); b 32f; 16:; lis 3,-32705; mr 4,30; addi 3,3,-21520; li 5,12; bl _s80187224_8; cmpwi 3,0; bne 17f; rlwinm 0,28,2,0,29; addi 9,29,236; lis 4,-32705; lwzx 5,9,0; b 26f; 17:; lis 3,-32705; mr 4,30; addi 3,3,-19824; li 5,25; bl _s80187224_9; cmpwi 3,0; bne 18f; lwz 3,0xd0(29); cmpwi 3,0; beq 30f; lwz 0,0x0(3); cmpwi 0,0; beq 30f; lis 9,-32705; lhz 0,-19796(9); b 31f; 18:; lis 3,-32705; mr 4,30; addi 3,3,-21540; li 5,18; bl _s80187224_10; cmpwi 3,0; bne 19f; lbz 0,0x100(29); cmpwi 0,1; bne 30f; lis 9,-32705; lhz 0,-19796(9); b 31f; 19:; lis 3,-32705; mr 4,30; addi 3,3,-19788; bl _s80187224_11; cmpwi 3,0; bne 20f; mr 4,28; mr 3,29; bl _s80187224_12; b 25f; 20:; lis 3,-32705; mr 4,30; addi 3,3,-19768; bl _s80187224_13; cmpwi 3,0; bne 21f; add 0,28,28; addi 9,29,2216; lis 4,-32705; lhax 5,9,0; b 26f; 21:; lis 3,-32705; mr 4,30; addi 3,3,-21152; bl _s80187224_14; cmpwi 3,0; bne 22f; mr 3,29; mr 4,28; bl _s80187224_15; cmpwi 3,0; bne 30f; lis 9,-32705; lhz 0,-19796(9); b 31f; 22:; lis 3,-32705; mr 4,30; addi 3,3,-21552; li 5,10; bl _s80187224_16; cmpwi 3,0; bne 24f; lis 9,-32697; addi 9,9,24012; lwz 0,0x458(9); cmpwi 0,0; bne 32f; lwz 0,0x450(9); cmpwi 0,0; bne 32f; lwz 0,0x454(9); cmpwi 0,0; bne 32f; lbz 0,0x100(29); cmplwi 0,1; bgt 32f; lis 9,-32705; addi 11,9,-19752; lwz 10,-19752(9); 23:; lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(31); sth 0,0x4(31); stb 8,0x6(31); b 32f; 24:; lis 3,-32705; mr 4,30; addi 3,3,-19744; bl _s80187224_17; cmpwi 3,0; bne 27f; mr 3,28; bl _s80187224_18; 25:; mr 5,3; lis 4,-32705; 26:; addi 4,4,-19956; mr 3,31; crxor 6,6,6; bl _s80187224_19; b 32f; 27:; lis 3,-32705; mr 4,30; addi 3,3,-21140; li 5,13; bl _s80187224_20; cmpwi 3,0; bne 28f; lwz 0,0x104(29); cmpwi 0,0; beq 30f; lis 9,-32705; lhz 0,-19796(9); b 31f; 28:; lis 3,-32705; mr 4,30; addi 3,3,-21124; bl _s80187224_21; cmpwi 3,0; bne 29f; lis 9,-32705; lhz 0,-19796(9); b 31f; 29:; lis 3,-32705; mr 4,30; addi 3,3,-21108; bl _s80187224_22; cmpwi 3,0; bne 32f; lis 9,-32697; lwz 0,0x615c(9); cmpwi 0,0; beq 30f; lis 9,-32705; lhz 0,-19796(9); b 31f; 30:; lis 9,-32705; lhz 0,-19792(9); 31:; sth 0,0x0(31); 32:; mr 3,31; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80187224_0();
extern "C" void _s80187224_1();
extern "C" void _s80187224_2();
extern "C" void _s80187224_3();
extern "C" void _s80187224_4();
extern "C" void _s80187224_5();
extern "C" void _s80187224_6();
extern "C" void _s80187224_7();
extern "C" void _s80187224_8();
extern "C" void _s80187224_9();
extern "C" void _s80187224_10();
extern "C" void _s80187224_11();
extern "C" void _s80187224_12();
extern "C" void _s80187224_13();
extern "C" void _s80187224_14();
extern "C" void _s80187224_15();
extern "C" void _s80187224_16();
extern "C" void _s80187224_17();
extern "C" void _s80187224_18();
extern "C" void _s80187224_19();
extern "C" void _s80187224_20();
extern "C" void _s80187224_21();
extern "C" void _s80187224_22();
extern "C" void f_80187224() {}
