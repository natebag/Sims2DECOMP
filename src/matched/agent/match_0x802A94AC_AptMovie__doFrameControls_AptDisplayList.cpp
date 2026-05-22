// 0x802A94AC AptMovie::doFrameControls(AptDisplayList (536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; mfcr 12; stmw 22,0x18(1); stw 0,0x44(1); stw 12,0x14(1); mr 23,3; mr 26,6; lwz 11,0x4(23); rlwinm 9,26,3,0,28; li 28,0; mr 22,4; lwzx 0,9,11; mr 29,5; cmpw 28,0; bge 4f; lis 24,-32694; cmpwi 4,29,0; li 25,0; 0:; add 9,9,11; lwz 11,0x4(9); lwzx 31,25,11; lwz 0,0x0(31); cmpwi 0,8; bne 3f; lwz 0,0x4(31); cmpwi 0,0; blt 3f; addi 3,24,-16032; addi 4,1,8; bl _s802A94AC_0; addi 27,1,8; mr 30,3; beq cr4,1f; mr 3,29; bl _s802A94AC_1; lwz 7,0x4c(3); b 2f; 1:; li 7,0; 2:; lwz 4,0x8(31); mr 5,29; addi 3,24,-16032; li 6,-1; bl _s802A94AC_2; lwz 0,0x4(31); mr 4,30; mr 5,27; addi 3,24,-16032; neg 0,0; stw 0,0x4(31); bl _s802A94AC_3; 3:; lwz 11,0x4(23); rlwinm 9,26,3,0,28; addi 28,28,1; addi 25,25,4; lwzx 0,9,11; cmpw 28,0; blt 0b; 4:; lwz 11,0x4(23); rlwinm 6,26,3,0,28; li 30,0; mr 26,6; lwzx 0,6,11; cmpw 30,0; bge 10f; lis 9,-32694; li 28,0; addi 27,9,-16288; li 25,1; 5:; add 9,6,11; lwz 11,0x4(9); lwzx 31,28,11; lwz 0,0x0(31); cmpwi 0,4; beq 7f; ble 6f; cmpwi 0,6; beq 8f; bge 9f; lwz 0,-23004(13); cmpwi 0,0; bne 9f; lwz 9,0x10(27); lwz 3,0x4(31); mtspr 8,9; blrl; stw 25,-23004(13); b 9f; 6:; cmpwi 0,1; blt 9f; cmpwi 0,2; ble 9f; lwz 9,0x4c(29); mr 4,29; lwz 5,0xc(31); lwz 11,0x8(9); lwz 3,0x4(11); addi 3,3,8; bl _s802A94AC_4; addi 4,31,4; mr 3,22; mr 5,29; bl _s802A94AC_5; b 9f; 7:; addi 4,31,4; mr 3,22; bl _s802A94AC_6; b 9f; 8:; lwz 9,0x4c(29); li 4,0; lwz 8,0x4(31); lwz 10,0x8(9); rlwinm 8,8,2,0,29; lwz 7,0x5c(27); lwz 9,0x4(10); mtspr 8,7; lwz 11,0x18(9); lwzx 10,8,11; lwz 3,0x8(10); blrl; 9:; lwz 11,0x4(23); mr 6,26; addi 30,30,1; addi 28,28,4; lwzx 0,6,11; cmpw 30,0; blt 5b; 10:; lwz 0,0x44(1); lwz 12,0x14(1); mtspr 8,0; lmw 22,0x18(1); mtcrf 8,12; addi 1,1,64"
extern "C" void _s802A94AC_0();
extern "C" void _s802A94AC_1();
extern "C" void _s802A94AC_2();
extern "C" void _s802A94AC_3();
extern "C" void _s802A94AC_4();
extern "C" void _s802A94AC_5();
extern "C" void _s802A94AC_6();
extern "C" void f_802A94AC() {}
