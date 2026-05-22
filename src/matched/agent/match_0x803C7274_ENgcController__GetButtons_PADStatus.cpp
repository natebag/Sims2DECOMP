// 0x803C7274 ENgcController::GetButtons(PADStatus (508 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,4; mr 29,3; lhz 0,0x0(30); li 31,0; andi. 9,0,256; beq 0f; li 31,64; 0:; andi. 11,0,512; beq 1f; ori 31,31,128; 1:; andi. 9,0,2048; beq 2f; ori 31,31,16; 2:; andi. 11,0,1024; beq 3f; ori 31,31,32; 3:; andi. 9,0,4096; beq 4f; ori 31,31,2048; 4:; andi. 11,0,64; bne 5f; lbz 0,0x6(30); cmplwi 0,10; ble 6f; 5:; ori 31,31,4; 6:; lhz 0,0x0(30); mr 9,0; andi. 11,0,32; bne 7f; lbz 0,0x7(30); cmplwi 0,10; ble 8f; 7:; ori 31,31,8; 8:; mr 0,9; andi. 11,0,16; beq 9f; ori 31,31,2; 9:; andi. 11,0,1; beq 10f; ori 31,31,32768; 10:; andi. 11,0,2; beq 11f; ori 31,31,8192; 11:; andi. 11,0,4; beq 12f; ori 31,31,16384; 12:; andi. 0,9,8; beq 13f; ori 31,31,4096; 13:; mr 3,29; mr 4,30; li 5,0; li 6,0; bl _s803C7274_0; lis 9,-32702; lfs f31,0x15b0(9); fcmpu 0,f1,f31; ble 14f; oris 31,31,2; 14:; mr 3,29; mr 4,30; li 5,0; li 6,0; bl _s803C7274_1; fcmpu 0,f1,f31; bge 15f; oris 31,31,8; 15:; mr 3,29; mr 4,30; li 5,0; li 6,1; bl _s803C7274_2; fcmpu 0,f1,f31; ble 16f; oris 31,31,1; 16:; mr 3,29; mr 4,30; li 5,0; li 6,1; bl _s803C7274_3; fcmpu 0,f1,f31; bge 17f; oris 31,31,4; 17:; mr 3,29; mr 4,30; li 5,1; li 6,0; bl _s803C7274_4; fcmpu 0,f1,f31; ble 18f; oris 31,31,32; 18:; mr 3,29; mr 4,30; li 5,1; li 6,0; bl _s803C7274_5; fcmpu 0,f1,f31; bge 19f; oris 31,31,128; 19:; mr 3,29; mr 4,30; li 5,1; li 6,1; bl _s803C7274_6; fcmpu 0,f1,f31; ble 20f; oris 31,31,16; 20:; mr 3,29; mr 4,30; li 5,1; li 6,1; bl _s803C7274_7; fcmpu 0,f1,f31; bge 21f; oris 31,31,64; 21:; mr 3,31; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s803C7274_0();
extern "C" void _s803C7274_1();
extern "C" void _s803C7274_2();
extern "C" void _s803C7274_3();
extern "C" void _s803C7274_4();
extern "C" void _s803C7274_5();
extern "C" void _s803C7274_6();
extern "C" void _s803C7274_7();
extern "C" void f_803C7274() {}
