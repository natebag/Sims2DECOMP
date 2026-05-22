// 0x801EF770 INVTarget::OnItemSelectedCheatMode(void) (656 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lbz 0,0x3251(31); cmpwi 0,10; beq 11f; bgt 0f; cmpwi 0,0; blt 15f; cmpwi 0,8; ble 1f; b 4f; 0:; cmpwi 0,11; beq 13f; cmpwi 0,13; bgt 15f; 1:; lbz 11,0x189(31); addi 8,13,-28700; lwz 9,0x84(31); addi 7,31,320; mulli 11,11,12; lbz 0,0x3251(31); rlwinm 9,9,2,0,29; lwzx 10,9,8; rlwinm 0,0,2,0,29; lwzx 30,7,0; mr 3,31; add 29,11,10; bl _s801EF770_0; lwz 11,0x0(30); lwz 0,0x4(30); subf 0,11,0; srawi 0,0,2; cmpw 0,29; bgt 2f; li 3,0; b 16f; 2:; cmplw 29,0; blt 3f; lis 3,-32704; addi 3,3,-26048; bl _s801EF770_1; bl _s801EF770_2; 3:; rlwinm 9,29,2,0,29; mr 3,31; lwzx 4,11,9; bl _s801EF770_3; b 15f; 4:; lbz 7,0x189(31); cmpwi 7,0; bne 8f; lwz 0,0x84(31); addi 9,13,-28700; rlwinm 0,0,2,0,29; lwzx 4,9,0; cmpwi 4,0; bne 5f; mr 3,31; li 4,0; b 7f; 5:; lbz 0,0x3251(31); addi 11,31,320; addi 4,4,-1; rlwinm 0,0,2,0,29; lwzx 9,11,0; lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; cmplw 4,0; blt 6f; lis 3,-32704; addi 3,3,-26048; bl _s801EF770_4; bl _s801EF770_5; 6:; rlwinm 4,4,3,0,28; mr 3,31; add 4,11,4; 7:; li 5,0; bl _s801EF770_6; b 10f; 8:; lbz 0,0x3251(31); addi 11,31,320; lwz 9,0x84(31); mulli 7,7,12; rlwinm 0,0,2,0,29; lwzx 10,11,0; rlwinm 9,9,2,0,29; addi 8,13,-28700; lwz 6,0x0(10); lwz 0,0x4(10); lwzx 11,9,8; subf 0,6,0; add 4,7,11; srawi 0,0,3; cmplw 4,0; blt 9f; lis 3,-32704; addi 3,3,-26048; bl _s801EF770_7; bl _s801EF770_8; 9:; rlwinm 4,4,3,0,28; mr 3,31; add 4,6,4; li 5,0; bl _s801EF770_9; 10:; mr 3,31; bl _s801EF770_10; b 15f; 11:; lbz 10,0x189(31); addi 7,13,-28700; lwz 8,0x168(31); lwz 9,0x84(31); mulli 10,10,12; lwz 6,0x0(8); rlwinm 9,9,2,0,29; lwz 0,0x4(8); lwzx 11,9,7; subf 0,6,0; add 4,10,11; srawi 0,0,3; cmplw 4,0; blt 12f; lis 3,-32704; addi 3,3,-26048; bl _s801EF770_11; bl _s801EF770_12; 12:; rlwinm 4,4,3,0,28; mr 3,31; add 4,6,4; li 5,0; bl _s801EF770_13; b 15f; 13:; lbz 10,0x189(31); addi 7,13,-28700; lwz 8,0x16c(31); lwz 9,0x84(31); mulli 10,10,12; lwz 6,0x0(8); rlwinm 9,9,2,0,29; lwz 0,0x4(8); lwzx 11,9,7; subf 0,6,0; add 4,10,11; srawi 0,0,3; cmplw 4,0; blt 14f; lis 3,-32704; addi 3,3,-26048; bl _s801EF770_14; bl _s801EF770_15; 14:; rlwinm 4,4,3,0,28; mr 3,31; add 4,6,4; li 5,0; bl _s801EF770_16; 15:; li 3,1; 16:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801EF770_0();
extern "C" void _s801EF770_1();
extern "C" void _s801EF770_2();
extern "C" void _s801EF770_3();
extern "C" void _s801EF770_4();
extern "C" void _s801EF770_5();
extern "C" void _s801EF770_6();
extern "C" void _s801EF770_7();
extern "C" void _s801EF770_8();
extern "C" void _s801EF770_9();
extern "C" void _s801EF770_10();
extern "C" void _s801EF770_11();
extern "C" void _s801EF770_12();
extern "C" void _s801EF770_13();
extern "C" void _s801EF770_14();
extern "C" void _s801EF770_15();
extern "C" void _s801EF770_16();
extern "C" void f_801EF770() {}
