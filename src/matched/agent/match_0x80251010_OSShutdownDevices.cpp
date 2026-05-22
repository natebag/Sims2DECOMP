// 0x80251010 __OSShutdownDevices (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stw 31,0x24(1); stw 30,0x20(1); stw 29,0x1c(1); stw 28,0x18(1); mr 28,3; bl _s80251010_0; cmpwi 28,0; bne 0f; li 3,1; bl _s80251010_1; mr 29,3; 0:; b 1f; 1:; b 2f; 2:; li 3,0; lwz 30,-23632(13); mr 31,3; b 3f; 3:; b 4f; 4:; b 7f; 5:; cmpwi 31,0; beq 6f; lwz 0,0x4(30); cmplw 3,0; bne 8f; 6:; li 3,0; lwz 12,0x0(30); mtspr 8,12; blrl; cntlzw 0,3; lwz 3,0x4(30); rlwinm 0,0,27,5,31; lwz 30,0x8(30); or 31,31,0; 7:; cmplwi 30,0; bne 5b; 8:; bl _s80251010_2; cntlzw 0,3; rlwinm 0,0,27,5,31; or 31,31,0; cmpwi 31,0; beq 9f; li 0,0; b 10f; 9:; li 0,1; 10:; cmpwi 0,0; beq 2b; b 11f; 11:; b 12f; 12:; bl _s80251010_3; cmpwi 3,0; beq 12b; bl _s80251010_4; li 3,0; lwz 31,-23632(13); mr 30,3; b 13f; 13:; b 14f; 14:; b 17f; 15:; cmpwi 30,0; beq 16f; lwz 0,0x4(31); cmplw 3,0; bne 18f; 16:; li 3,1; lwz 12,0x0(31); mtspr 8,12; blrl; cntlzw 0,3; lwz 3,0x4(31); rlwinm 0,0,27,5,31; lwz 31,0x8(31); or 30,30,0; 17:; cmplwi 31,0; bne 15b; 18:; bl _s80251010_5; bl _s80251010_6; cmpwi 28,0; bne 19f; mr 3,29; bl _s80251010_7; 19:; lis 3,-32768; lwz 3,0xdc(3); b 20f; 20:; b 21f; 21:; b 25f; 22:; lhz 0,0x2c8(3); lwz 30,0x2fc(3); cmpwi 0,4; beq 23f; bge 24f; cmpwi 0,1; beq 23f; b 24f; 23:; bl _s80251010_8; 24:; mr 3,30; 25:; cmplwi 3,0; bne 22b; lwz 0,0x2c(1); lwz 31,0x24(1); lwz 30,0x20(1); lwz 29,0x1c(1); lwz 28,0x18(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s80251010_0();
extern "C" void _s80251010_1();
extern "C" void _s80251010_2();
extern "C" void _s80251010_3();
extern "C" void _s80251010_4();
extern "C" void _s80251010_5();
extern "C" void _s80251010_6();
extern "C" void _s80251010_7();
extern "C" void _s80251010_8();
extern "C" void f_80251010() {}
