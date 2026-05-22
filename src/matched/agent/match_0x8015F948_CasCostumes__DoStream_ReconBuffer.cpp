// 0x8015F948 CasCostumes::DoStream(ReconBuffer (1244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-120(1); mfspr 0,8; stmw 14,0x30(1); stw 0,0x7c(1); mr 15,4; stw 5,0x28(1); li 0,2; mr 23,3; addi 16,1,12; stw 0,0x8(1); mr 3,15; addi 4,1,8; li 5,1; mr 30,16; bl _s8015F948_0; li 26,0; 0:; rlwinm 9,26,4,0,27; add 8,26,26; add 11,9,23; lwzx 10,9,23; lwz 0,0x4(11); add 4,8,30; mr 3,15; li 5,1; subf 0,10,0; srawi 0,0,2; sthx 0,8,30; bl _s8015F948_1; addi 0,26,1; rlwinm 26,0,0,24,31; cmplwi 26,1; ble 0b; lwz 0,0xc(15); cmpwi 0,0; bne 32f; mr 3,23; li 26,0; bl _s8015F948_2; 1:; rlwinm 0,26,4,0,27; li 4,81; add 30,23,0; mr 18,0; mr 3,30; li 27,0; bl _s8015F948_3; addi 0,26,1; add 9,26,26; stw 0,0x2c(1); mr 25,9; lhax 0,9,16; cmpw 27,0; bge 15f; mr 29,30; addi 24,1,16; 2:; li 3,292; bl _s8015F948_4; bl _s8015F948_5; lwz 30,0x4(29); lwz 0,0xc(29); stw 3,0x10(1); cmpw 30,0; beq 3f; stw 3,0x0(30); addi 27,27,1; lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 14f; 3:; lwzx 0,18,23; li 9,1; stw 9,0x18(1); addi 10,1,24; subf 0,0,30; addi 11,1,20; srawi 9,0,2; stw 9,0x14(1); cmplwi 9,1; bge 4f; mr 11,10; 4:; lwz 0,0x0(11); add. 0,9,0; beq 6f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 5f; mr 3,28; bl _s8015F948_6; mr 31,3; b 7f; 5:; mr 3,28; bl _s8015F948_7; mr 31,3; b 7f; 6:; li 31,0; li 28,0; 7:; lwz 4,0x0(29); cmpw 30,4; beq 8f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8015F948_8; add 0,3,30; b 9f; 8:; mr 0,31; 9:; lwz 9,0x18(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 11f; 10:; lwz 0,0x0(24); stw 0,0x0(30); addi 30,30,4; bdnz 10b; 11:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 13f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 12f; bl _s8015F948_9; b 13f; 12:; bl _s8015F948_10; 13:; add 0,28,31; stw 31,0x0(29); stw 30,0x4(29); stw 0,0xc(29); 14:; lwz 3,0x10(1); mr 4,15; lwz 5,0x28(1); extsh 27,27; bl _s8015F948_11; lhax 0,25,16; cmpw 27,0; blt 2b; 15:; lwz 0,0x8(1); cmpwi 0,1; bne 31f; lhax 29,25,16; subfic 0,26,0; adde 22,0,26; addi 0,29,2; mr 19,29; cmpw 29,0; bge 31f; mr 20,25; add 28,18,23; addi 14,1,28; mr 21,16; 16:; li 3,292; bl _s8015F948_12; bl _s8015F948_13; lwz 30,0x4(28); lwz 0,0xc(28); stw 3,0x1c(1); cmpw 30,0; beq 17f; stw 3,0x0(30); addi 24,29,1; cmpwi 22,0; lis 17,-32702; lwz 9,0x4(28); rlwinm 29,29,2,0,29; mfcr 26; addi 25,19,2; addi 9,9,4; stw 9,0x4(28); b 28f; 17:; lwzx 0,18,23; li 9,1; stw 9,0x24(1); addi 10,1,36; subf 0,0,30; addi 11,1,32; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 18f; mr 11,10; 18:; lwz 0,0x0(11); add. 0,9,0; beq 20f; rlwinm 0,0,2,0,29; mr 27,0; cmplwi 0,128; ble 19f; mr 3,27; bl _s8015F948_14; mr 31,3; b 21f; 19:; mr 3,27; bl _s8015F948_15; mr 31,3; b 21f; 20:; li 31,0; li 27,0; 21:; lwz 4,0x0(28); cmpw 30,4; beq 22f; subf 30,4,30; mr 3,31; mr 5,30; bl _s8015F948_16; add 0,3,30; b 23f; 22:; mr 0,31; 23:; lwz 9,0x24(1); addi 24,29,1; cmpwi 7,22,0; mr 30,0; mtspr 9,9; lis 17,-32702; rlwinm 29,29,2,0,29; mfcr 26; rlwinm 26,26,28,0,3; addi 25,19,2; cmpwi 9,0; beq 25f; 24:; lwz 0,0x0(14); stw 0,0x0(30); addi 30,30,4; bdnz 24b; 25:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 27f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 26f; bl _s8015F948_17; b 27f; 26:; bl _s8015F948_18; 27:; add 0,27,31; stw 31,0x0(28); stw 30,0x4(28); stw 0,0xc(28); 28:; lwz 3,0x1c(1); mr 4,22; bl _s8015F948_19; addi 9,17,17564; lwz 4,0x1c(1); lwzx 3,9,29; li 5,32; addi 4,4,4; bl _s8015F948_20; mtcrf 128,26; beq 29f; lwz 4,0x1c(1); lis 3,-32706; addi 3,3,-4564; li 5,32; addi 4,4,68; bl _s8015F948_21; b 30f; 29:; lwz 4,0x1c(1); lis 3,-32706; addi 3,3,-4556; li 5,32; addi 4,4,68; bl _s8015F948_22; 30:; lhzx 9,20,21; extsh 29,24; cmpw 29,25; addi 9,9,1; sthx 9,20,21; blt 16b; 31:; add 9,18,23; lwz 0,0x2c(1); lwz 4,0x4(9); lis 9,-32746; lwzx 3,18,23; rlwinm 26,0,0,24,31; addi 5,9,-2592; bl _s8015F948_23; cmplwi 26,1; ble 1b; b 36f; 32:; li 26,0; 33:; rlwinm 9,26,4,0,27; addi 26,26,1; add 11,9,23; stw 26,0x2c(1); lwzx 30,9,23; lwz 0,0x4(11); cmpw 30,0; beq 35f; mr 31,11; 34:; lwz 3,0x0(30); mr 4,15; lwz 5,0x28(1); addi 30,30,4; bl _s8015F948_24; lwz 0,0x4(31); cmpw 30,0; bne 34b; 35:; lwz 0,0x2c(1); rlwinm 26,0,0,24,31; cmplwi 26,1; ble 33b; 36:; lwz 0,0x7c(1); mtspr 8,0; lmw 14,0x30(1); addi 1,1,120"
extern "C" void _s8015F948_0();
extern "C" void _s8015F948_1();
extern "C" void _s8015F948_2();
extern "C" void _s8015F948_3();
extern "C" void _s8015F948_4();
extern "C" void _s8015F948_5();
extern "C" void _s8015F948_6();
extern "C" void _s8015F948_7();
extern "C" void _s8015F948_8();
extern "C" void _s8015F948_9();
extern "C" void _s8015F948_10();
extern "C" void _s8015F948_11();
extern "C" void _s8015F948_12();
extern "C" void _s8015F948_13();
extern "C" void _s8015F948_14();
extern "C" void _s8015F948_15();
extern "C" void _s8015F948_16();
extern "C" void _s8015F948_17();
extern "C" void _s8015F948_18();
extern "C" void _s8015F948_19();
extern "C" void _s8015F948_20();
extern "C" void _s8015F948_21();
extern "C" void _s8015F948_22();
extern "C" void _s8015F948_23();
extern "C" void _s8015F948_24();
extern "C" void f_8015F948() {}
