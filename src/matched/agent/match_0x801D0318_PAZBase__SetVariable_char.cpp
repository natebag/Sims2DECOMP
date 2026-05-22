// 0x801D0318 PAZBase::SetVariable(char (1356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; lwz 9,0xb0(31); mr 29,5; lwz 3,0x24(9); bl _s801D0318_0; cmpwi 3,0; bne 0f; lbz 9,0x0(29); lwz 0,0x84(31); extsb 9,9; addi 9,9,-48; cmpw 9,0; bne 35f; lwz 4,0x8c(31); mr 3,31; addi 4,4,-1; bl _s801D0318_1; b 35f; 0:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x28(9); bl _s801D0318_2; cmpwi 3,0; bne 1f; lbz 9,0x0(29); lwz 0,0x84(31); extsb 9,9; addi 9,9,-48; cmpw 9,0; bne 35f; lwz 4,0x8c(31); mr 3,31; addi 4,4,1; bl _s801D0318_3; b 35f; 1:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x1c(9); bl _s801D0318_4; cmpwi 3,0; bne 2f; lbz 9,0x0(29); lwz 0,0x84(31); extsb 9,9; addi 9,9,-48; cmpw 9,0; bne 35f; lwz 0,0x98(31); cmpwi 0,0; beq 35f; lwz 0,0x8c(31); lwz 9,0xa8(31); mulli 0,0,28; add 9,9,0; lwz 11,0xc(9); cmpwi 11,0; beq 35f; li 0,2; stw 3,0xa0(31); stw 0,0x88(31); stw 3,0x98(31); b 35f; 2:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x20(9); bl _s801D0318_5; cmpwi 3,0; bne 3f; lbz 9,0x0(29); lwz 0,0x84(31); extsb 9,9; addi 9,9,-48; cmpw 9,0; bne 35f; lwz 0,0x98(31); cmpwi 0,0; beq 35f; lwz 0,0x8c(31); lwz 9,0xa8(31); mulli 0,0,28; add 9,9,0; lwz 11,0x10(9); cmpwi 11,0; beq 35f; li 9,1; li 0,2; stw 0,0x88(31); stw 3,0x98(31); stw 9,0xa0(31); b 35f; 3:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x30(9); bl _s801D0318_6; cmpwi 3,0; bne 4f; lis 4,-32705; mr 3,29; addi 4,4,-8800; addi 5,31,140; crxor 6,6,6; bl _s801D0318_7; lwz 9,0x8c(31); mr 3,31; lwz 11,0xac(31); divwu 0,9,11; mullw 0,0,11; subf 9,0,9; stw 9,0x8c(31); bl _s801D0318_8; b 35f; 4:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x34(9); bl _s801D0318_9; cmpwi 3,0; bne 25f; lwz 0,0x8c(31); lwz 9,0xa8(31); mulli 0,0,28; add 9,9,0; lwz 0,0xc(9); cmpwi 0,11; beq 16f; bgt 6f; cmpwi 0,6; beq 11f; bgt 5f; cmpwi 0,4; beq 9f; bgt 10f; cmpwi 0,1; beq 8f; b 35f; 5:; cmpwi 0,8; beq 13f; blt 12f; cmpwi 0,9; beq 14f; cmpwi 0,10; beq 15f; b 35f; 6:; cmpwi 0,15; beq 20f; bgt 7f; cmpwi 0,13; beq 18f; bgt 19f; b 17f; 7:; cmpwi 0,17; beq 22f; blt 21f; cmpwi 0,18; beq 23f; cmpwi 0,19; beq 24f; b 35f; 8:; lis 3,-32705; addi 3,3,9192; bl _s801D0318_10; b 35f; 9:; lis 3,-32705; addi 3,3,16228; bl _s801D0318_11; b 35f; 10:; lis 3,-32705; addi 3,3,16248; bl _s801D0318_12; b 35f; 11:; lis 3,-32705; addi 3,3,16260; bl _s801D0318_13; b 35f; 12:; lis 3,-32705; addi 3,3,16272; bl _s801D0318_14; b 35f; 13:; lis 3,-32705; addi 3,3,16288; bl _s801D0318_15; b 35f; 14:; lis 3,-32705; addi 3,3,16312; bl _s801D0318_16; b 35f; 15:; lis 3,-32705; addi 3,3,16328; bl _s801D0318_17; b 35f; 16:; lis 3,-32705; addi 3,3,16344; bl _s801D0318_18; b 35f; 17:; lis 3,-32705; addi 3,3,16364; bl _s801D0318_19; b 35f; 18:; lis 3,-32705; addi 3,3,16376; bl _s801D0318_20; b 35f; 19:; lis 3,-32705; addi 3,3,16396; bl _s801D0318_21; b 35f; 20:; lis 3,-32705; addi 3,3,16408; bl _s801D0318_22; b 35f; 21:; lis 3,-32705; addi 3,3,16420; bl _s801D0318_23; b 35f; 22:; lis 3,-32705; addi 3,3,9292; bl _s801D0318_24; b 35f; 23:; lis 3,-32705; addi 3,3,16436; bl _s801D0318_25; b 35f; 24:; lis 3,-32705; addi 3,3,-2020; bl _s801D0318_26; b 35f; 25:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x38(9); bl _s801D0318_27; cmpwi 3,0; bne 27f; lwz 0,0x8c(31); lwz 9,0xa8(31); mulli 0,0,28; add 9,9,0; lwz 0,0x10(9); cmpwi 0,2; beq 26f; cmpwi 0,3; bne 35f; lis 3,-32705; addi 3,3,-5340; bl _s801D0318_28; b 35f; 26:; lis 3,-32705; addi 3,3,6560; bl _s801D0318_29; b 35f; 27:; lis 3,-32705; mr 4,30; addi 3,3,16452; bl _s801D0318_30; cmpwi 3,0; bne 28f; li 0,1; stw 0,0x98(31); b 35f; 28:; lis 3,-32705; mr 4,30; addi 3,3,16468; bl _s801D0318_31; cmpwi 3,0; bne 31f; lwz 0,0xa0(31); lis 5,-32705; cmpwi 0,0; beq 29f; lwz 9,0x80(31); addi 5,5,6640; lwz 11,0xb0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; lwz 4,0x38(11); b 30f; 29:; lwz 9,0x80(31); addi 5,5,6640; lwz 11,0xb0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; lwz 4,0x34(11); 30:; mtspr 8,0; blrl; b 35f; 31:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x2c(9); bl _s801D0318_32; cmpwi 3,0; bne 35f; li 30,0; li 28,0; li 29,0; 32:; lwz 9,0xb0(31); lwz 0,0xac(31); add 9,29,9; lwz 4,0x40(9); cmplw 30,0; bge 33f; lwz 9,0xa8(31); lwz 0,0x0(31); add 9,28,9; lwz 5,0x8(9); cmpwi 0,0; beq 34f; lwz 3,0x1c(31); cmpwi 3,0; beq 34f; lwz 6,0x7c(31); li 7,0; bl _s801D0318_33; b 34f; 33:; lwz 0,0x0(31); cmpwi 0,0; beq 34f; lwz 3,0x1c(31); cmpwi 3,0; beq 34f; lis 5,-24685; lwz 6,0x7c(31); ori 5,5,65396; li 7,0; bl _s801D0318_34; 34:; addi 30,30,1; addi 28,28,28; addi 29,29,4; cmplwi 30,8; ble 32b; 35:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801D0318_0();
extern "C" void _s801D0318_1();
extern "C" void _s801D0318_2();
extern "C" void _s801D0318_3();
extern "C" void _s801D0318_4();
extern "C" void _s801D0318_5();
extern "C" void _s801D0318_6();
extern "C" void _s801D0318_7();
extern "C" void _s801D0318_8();
extern "C" void _s801D0318_9();
extern "C" void _s801D0318_10();
extern "C" void _s801D0318_11();
extern "C" void _s801D0318_12();
extern "C" void _s801D0318_13();
extern "C" void _s801D0318_14();
extern "C" void _s801D0318_15();
extern "C" void _s801D0318_16();
extern "C" void _s801D0318_17();
extern "C" void _s801D0318_18();
extern "C" void _s801D0318_19();
extern "C" void _s801D0318_20();
extern "C" void _s801D0318_21();
extern "C" void _s801D0318_22();
extern "C" void _s801D0318_23();
extern "C" void _s801D0318_24();
extern "C" void _s801D0318_25();
extern "C" void _s801D0318_26();
extern "C" void _s801D0318_27();
extern "C" void _s801D0318_28();
extern "C" void _s801D0318_29();
extern "C" void _s801D0318_30();
extern "C" void _s801D0318_31();
extern "C" void _s801D0318_32();
extern "C" void _s801D0318_33();
extern "C" void _s801D0318_34();
extern "C" void f_801D0318() {}
