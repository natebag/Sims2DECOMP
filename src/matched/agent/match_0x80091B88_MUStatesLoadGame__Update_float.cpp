// 0x80091B88 MUStatesLoadGame::Update(float) (1156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 27,0x2c(1); stw 0,0x44(1); mr 31,3; lwz 3,0x8(31); lwz 30,0x90(3); cmpwi 30,0; bne 18f; lwz 0,0x1c(31); cmpwi 0,0; beq 0f; cmpwi 0,12; bne 14f; 0:; lis 28,-32696; stw 30,0x8(1); lwz 3,0x58d8(28); addi 4,1,8; addi 27,28,22744; bl _s80091B88_0; lwz 0,0x8(1); cmpwi 0,0; bne 1f; lwz 11,0x8(31); li 0,6; li 4,6; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_1; mr 3,31; li 4,14; bl _s80091B88_2; li 0,1; stw 0,0x1c(31); b 21f; 1:; lwz 0,0x1c(31); cmpwi 0,12; bne 2f; stw 30,0x1c(31); 2:; lwz 3,0x58d8(28); addi 4,1,12; stw 30,0xc(1); bl _s80091B88_3; lwz 0,0xc(1); cmpwi 0,0; beq 3f; lwz 11,0x8(31); li 0,9; li 4,24; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_4; mr 3,31; li 4,14; bl _s80091B88_5; li 0,10; stw 0,0x1c(31); b 21f; 3:; li 0,1; lwz 3,0x58d8(28); stw 0,0x10(1); addi 4,1,16; bl _s80091B88_6; mr 9,3; cmpwi 9,1; bne 11f; lwz 0,0x10(1); cmpwi 0,0; beq 4f; lwz 11,0x8(31); li 0,6; li 4,1; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_7; mr 3,31; li 4,14; bl _s80091B88_8; li 0,2; stw 0,0x1c(31); b 21f; 4:; lwz 3,0x58d8(28); addi 4,1,20; stw 9,0x14(1); bl _s80091B88_9; cmpwi 3,1; bne 11f; lwz 29,0x14(1); cmpwi 29,0; beq 5f; lwz 11,0x8(31); li 0,6; li 4,2; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_10; mr 3,31; li 4,14; bl _s80091B88_11; li 0,3; stw 0,0x1c(31); b 21f; 5:; lwz 3,0x58d8(28); addi 4,1,24; stw 30,0x18(1); bl _s80091B88_12; cmpwi 3,1; bne 11f; lwz 0,0x18(1); cmpwi 0,0; bne 6f; lwz 11,0x8(31); li 0,6; li 4,5; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_13; mr 3,31; li 4,14; bl _s80091B88_14; li 0,4; stw 0,0x1c(31); b 21f; 6:; lwz 3,0x58d8(28); lis 5,171; stw 29,0x1c(1); addi 4,1,28; ori 5,5,52719; bl _s80091B88_15; mr 9,3; cmpwi 9,1; bne 8f; lwz 0,0x1c(1); cmpwi 0,0; bne 7f; lwz 11,0x8(31); li 0,6; li 4,5; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_16; mr 3,31; li 4,14; bl _s80091B88_17; li 0,5; stw 0,0x1c(31); b 21f; 7:; lwz 3,0x0(27); lis 5,171; stw 9,0x20(1); addi 4,1,32; ori 5,5,52719; bl _s80091B88_18; mr 0,3; cmpwi 0,1; beq 9f; 8:; lwz 9,0x8(31); stw 29,0x1c(31); stw 29,0x90(9); b 21f; 9:; lwz 30,0x20(1); cmpwi 30,0; beq 10f; lwz 11,0x8(31); li 0,6; li 4,5; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_19; mr 3,31; li 4,14; bl _s80091B88_20; li 0,11; stw 0,0x1c(31); b 21f; 10:; lwz 3,0x0(27); addi 4,1,36; stw 0,0x24(1); bl _s80091B88_21; cmpwi 3,1; beq 12f; 11:; lwz 9,0x8(31); stw 30,0x1c(31); stw 30,0x90(9); b 21f; 12:; lwz 0,0x24(1); cmpwi 0,0; beq 13f; lwz 11,0x8(31); li 30,6; li 4,8; lwz 9,0x98(11); stw 30,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_22; mr 3,31; li 4,14; bl _s80091B88_23; stw 30,0x1c(31); b 21f; 13:; lis 9,-32706; li 0,8; lfs f0,-32060(9); stw 0,0x1c(31); stfs f0,0x20(31); b 21f; 14:; cmpwi 0,8; bne 17f; lis 9,-32696; lis 4,171; lwz 3,0x58d8(9); ori 4,4,52719; li 30,1; bl _s80091B88_24; cmpwi 3,1; bne 15f; li 30,0; 15:; cmpwi 30,0; beq 16f; lwz 11,0x8(31); li 0,6; li 4,9; lwz 9,0x98(11); stw 0,0xac(9); lwz 11,0x8(31); lwz 3,0x98(11); bl _s80091B88_25; mr 3,31; li 4,14; bl _s80091B88_26; li 0,7; stw 0,0x1c(31); b 21f; 16:; li 0,13; stw 0,0x1c(31); b 21f; 17:; cmpwi 0,13; bne 21f; lfs f0,0x20(31); lis 9,-32706; lfs f13,-32056(9); fsubs f0,f0,f1; fcmpu 0,f0,f13; stfs f0,0x20(31); bgt 21f; li 4,2; bl _s80091B88_27; b 21f; 18:; cmpwi 30,1; beq 21f; cmpwi 30,2; bne 21f; lwz 9,0x1c(31); addi 0,9,-1; cmplwi 0,5; ble 19f; cmpwi 9,11; beq 19f; cmpwi 9,7; bne 20f; 19:; lwz 3,0x8(31); li 4,1; bl _s80091B88_28; b 21f; 20:; cmpwi 9,10; bne 21f; li 0,0; stw 0,0x1c(31); stw 0,0x90(3); 21:; lwz 0,0x44(1); mtspr 8,0; lmw 27,0x2c(1); addi 1,1,64"
extern "C" void _s80091B88_0();
extern "C" void _s80091B88_1();
extern "C" void _s80091B88_2();
extern "C" void _s80091B88_3();
extern "C" void _s80091B88_4();
extern "C" void _s80091B88_5();
extern "C" void _s80091B88_6();
extern "C" void _s80091B88_7();
extern "C" void _s80091B88_8();
extern "C" void _s80091B88_9();
extern "C" void _s80091B88_10();
extern "C" void _s80091B88_11();
extern "C" void _s80091B88_12();
extern "C" void _s80091B88_13();
extern "C" void _s80091B88_14();
extern "C" void _s80091B88_15();
extern "C" void _s80091B88_16();
extern "C" void _s80091B88_17();
extern "C" void _s80091B88_18();
extern "C" void _s80091B88_19();
extern "C" void _s80091B88_20();
extern "C" void _s80091B88_21();
extern "C" void _s80091B88_22();
extern "C" void _s80091B88_23();
extern "C" void _s80091B88_24();
extern "C" void _s80091B88_25();
extern "C" void _s80091B88_26();
extern "C" void _s80091B88_27();
extern "C" void _s80091B88_28();
extern "C" void f_80091B88() {}
