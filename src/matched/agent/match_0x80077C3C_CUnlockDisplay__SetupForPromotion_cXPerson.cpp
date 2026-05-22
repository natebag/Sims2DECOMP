// 0x80077C3C CUnlockDisplay::SetupForPromotion(cXPerson (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 30,3; li 0,2; stw 0,0x44c(30); mr 28,4; li 4,57; lwz 9,0x4(28); lha 3,0x138(9); lwz 0,0x13c(9); add 3,28,3; mtspr 8,0; blrl; mr 31,3; cmpwi 31,9; ble 0f; li 31,9; 0:; bl _s80077C3C_0; lis 0,-30584; rlwinm 3,3,30,2,31; ori 0,0,34953; cmpwi 31,8; mulhwu 0,3,0; mfcr 31; rlwinm 0,0,27,5,31; mulli 9,0,60; subf 0,9,3; bgt 1f; cmplwi 0,19; bgt 1f; li 0,1; mr 3,30; stw 0,0x494(30); lis 29,26431; stw 0,0x490(30); ori 29,29,49373; bl _s80077C3C_1; lwz 11,0x464(30); lis 10,15871; ori 10,10,19174; lwz 0,0x34(11); stw 10,0x30(11); subfic 9,0,0; adde 0,9,0; stw 0,0x80(11); lwz 9,0x464(30); stw 10,0x2c(9); lwz 11,0x464(30); lwz 0,0x30(11); stw 10,0x34(11); subfic 9,0,0; adde 0,9,0; stw 0,0x80(11); lwz 9,0x464(30); lwz 31,0x0(9); b 3f; 1:; li 0,0; li 9,1; stw 0,0x490(30); mr 3,30; stw 9,0x494(30); bl _s80077C3C_2; bl _s80077C3C_3; rlwinm 3,3,24,31,31; mtcrf 128,31; ble 2f; addi 3,3,2; 2:; lis 9,-32707; addi 11,1,8; lwz 8,0x5f98(9); rlwinm 6,3,2,0,29; addi 9,9,24472; lwz 7,0xc(9); lwz 0,0x4(9); lwz 10,0x8(9); stw 8,0x8(1); stw 0,0x4(11); stw 10,0x8(11); stw 7,0xc(11); lwz 31,0x464(30); lwzx 29,11,6; 3:; mr 4,28; mr 3,31; bl _s80077C3C_4; lwz 0,0x30(31); li 9,0; stw 29,0x34(31); cmpwi 0,0; beq 4f; cmpwi 29,0; bne 5f; 4:; li 9,1; 5:; li 0,80; stw 9,0x80(31); stw 0,0x38(31); lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s80077C3C_0();
extern "C" void _s80077C3C_1();
extern "C" void _s80077C3C_2();
extern "C" void _s80077C3C_3();
extern "C" void _s80077C3C_4();
extern "C" void f_80077C3C() {}
