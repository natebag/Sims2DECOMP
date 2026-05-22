// 0x80160974 CasGenetics::ChooseRandomBodyPart(eBodyPartS2C, (1028 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 24,0x20(1); stw 0,0x44(1); stw 12,0x1c(1); mr 29,4; mr 25,3; mr 30,5; mr 31,6; bl _s80160974_0; li 28,0; li 0,100; cmpwi 29,16; divwu 0,3,0; mulli 0,0,100; subf 3,0,3; addi 3,3,1; bgt 1f; cmpwi 4,29,15; bge cr4,8f; cmpwi 29,2; beq 3f; bgt 0f; cmpwi 29,0; beq 7f; b 39f; 0:; cmpwi 29,3; beq 4f; cmpwi 29,7; beq 8f; b 39f; 1:; cmpwi 29,19; beq 5f; bgt 2f; cmpwi 3,29,18; beq cr3,6f; b 39f; 2:; cmpwi 29,24; bgt 39f; b 7f; 3:; lbz 0,0xd5(30); cmpwi 0,0; bne 39f; b 8f; 4:; lbz 0,0xd5(30); cmpwi 0,0; beq 39f; b 8f; 5:; cmpw 3,31; li 28,1; ble 8f; mr 3,30; li 4,19; li 5,0; bl _s80160974_1; mr 3,30; li 4,19; li 5,0; bl _s80160974_2; li 0,0; stw 0,0x94(30); b 39f; 6:; cmpw 3,31; li 28,1; ble 8f; mr 3,30; li 4,18; li 5,0; bl _s80160974_3; b 39f; 7:; cmpw 3,31; li 28,1; ble 8f; mr 3,30; mr 4,29; li 5,0; bl _s80160974_4; mr 3,30; mr 4,29; li 5,0; bl _s80160974_5; b 39f; 8:; cmpwi 28,0; addi 3,1,8; mfcr 24; li 26,0; bl _s80160974_6; li 28,0; lwz 4,0x84(30); addi 3,1,8; cmpwi 2,29,16; bl _s80160974_7; cmpwi 4,29,15; addi 3,1,8; mr 4,29; bl _s80160974_8; cmpwi 3,29,18; mr 27,3; 9:; bl _s80160974_9; mr 0,3; mr 4,29; divwu 9,0,27; addi 3,1,8; mullw 9,9,27; subf 0,9,0; extsb 31,0; mr 5,31; bl _s80160974_10; addi 0,26,1; cmpwi 3,0; extsb 26,0; bne 10f; li 28,1; 10:; beq cr4,14f; bgt cr4,11f; cmpwi 29,7; beq 12f; b 20f; 11:; beq cr2,16f; beq cr3,17f; b 20f; 12:; lwz 0,0x84(30); cmpwi 0,0; beq 13f; cmpwi 31,3; beq 19f; b 20f; 13:; cmpwi 31,4; beq 19f; mr 3,25; mr 4,31; bl _s80160974_11; b 18f; 14:; lwz 0,0x84(30); cmpwi 0,0; beq 15f; cmpwi 31,8; beq 19f; b 20f; 15:; cmpwi 31,7; bne 20f; b 19f; 16:; cmpwi 31,9; bne 20f; b 19f; 17:; lwz 0,0x84(30); cmpwi 0,0; bne 20f; mr 3,25; mr 4,31; bl _s80160974_12; 18:; cmpwi 3,0; beq 20f; 19:; li 28,0; 20:; mtcrf 128,24; beq 21f; cmpwi 31,0; bne 21f; li 28,0; 21:; cmpwi 26,25; mcrf cr7,cr0; ble 22f; li 28,1; 22:; cmpwi 28,0; beq 9b; ble cr7,23f; li 31,0; 23:; mr 3,30; mr 4,29; mr 5,31; bl _s80160974_13; beq cr3,25f; mr 5,31; addi 3,1,8; mr 4,29; bl _s80160974_14; mr. 31,3; li 5,0; beq 24f; bl _s80160974_15; divwu 0,3,31; mullw 0,0,31; subf 3,0,3; extsb 5,3; 24:; mr 3,30; mr 4,29; bl _s80160974_16; 25:; beq cr2,34f; bgt cr2,27f; cmpwi 29,3; beq 30f; bgt 26f; cmpwi 29,2; beq 29f; b 38f; 26:; cmpwi 29,7; beq 31f; beq cr4,32f; b 38f; 27:; cmpwi 29,22; beq 35f; bgt 28f; cmpwi 29,19; beq 33f; b 38f; 28:; cmpwi 29,24; bgt 38f; b 36f; 29:; li 0,0; stw 0,0x94(30); stw 0,0x90(30); b 38f; 30:; li 9,0; li 0,1; stw 0,0x94(30); stw 9,0x90(30); b 38f; 31:; addi 4,1,8; mr 3,30; bl _s80160974_17; addi 4,1,8; mr 3,30; bl _s80160974_18; mr 4,3; mr 3,30; bl _s80160974_19; b 38f; 32:; mr 3,30; addi 4,1,8; bl _s80160974_20; b 38f; 33:; mr 3,30; addi 4,1,8; bl _s80160974_21; li 0,1; stw 0,0x94(30); b 38f; 34:; mr 3,30; addi 4,1,8; bl _s80160974_22; b 38f; 35:; li 0,0; b 37f; 36:; li 0,1; 37:; stw 0,0xe4(30); stw 0,0xe0(30); 38:; addi 3,1,8; li 4,2; bl _s80160974_23; 39:; lwz 0,0x44(1); lwz 12,0x1c(1); mtspr 8,0; lmw 24,0x20(1); mtcrf 56,12; addi 1,1,64"
extern "C" void _s80160974_0();
extern "C" void _s80160974_1();
extern "C" void _s80160974_2();
extern "C" void _s80160974_3();
extern "C" void _s80160974_4();
extern "C" void _s80160974_5();
extern "C" void _s80160974_6();
extern "C" void _s80160974_7();
extern "C" void _s80160974_8();
extern "C" void _s80160974_9();
extern "C" void _s80160974_10();
extern "C" void _s80160974_11();
extern "C" void _s80160974_12();
extern "C" void _s80160974_13();
extern "C" void _s80160974_14();
extern "C" void _s80160974_15();
extern "C" void _s80160974_16();
extern "C" void _s80160974_17();
extern "C" void _s80160974_18();
extern "C" void _s80160974_19();
extern "C" void _s80160974_20();
extern "C" void _s80160974_21();
extern "C" void _s80160974_22();
extern "C" void _s80160974_23();
extern "C" void f_80160974() {}
