// 0x801350D4 RelMatrixImpl::DoStream(ReconBuffer (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 21,0x2c(1); stw 0,0x5c(1); mr 26,4; li 0,-1; mr 24,3; mr 23,5; stw 0,0x10(1); mr 3,26; addi 4,1,16; li 5,1; bl _s801350D4_0; lwz 0,0xc(26); cmpwi 0,0; beq 0f; cmpwi 23,83; bgt 0f; li 0,0; mr 3,26; stw 0,0x14(1); addi 4,1,20; li 5,1; bl _s801350D4_1; 0:; lwz 0,0x10(1); cmpwi 0,0; bge 2f; lwz 0,0xc(26); cmpwi 0,0; bne 1f; cmpwi 23,78; ble 1f; cmpwi 23,83; bgt 1f; mr 3,26; addi 4,1,24; li 5,1; bl _s801350D4_2; 1:; addi 3,24,4; mr 4,26; mr 5,23; bl _s801350D4_3; b 16f; 2:; lwz 9,0x0(24); li 27,0; lha 3,0x38(9); lwz 0,0x3c(9); add 3,24,3; mtspr 8,0; blrl; lwz 21,0x10(1); cmpw 27,21; bge 16f; li 25,0; addi 29,24,4; addi 22,1,28; 3:; li 3,20; bl _s801350D4_4; mr 9,3; mr 4,26; stw 25,0x0(9); addi 11,9,8; stw 25,0x4(9); stw 25,0x4(11); mr 5,23; stw 25,0x10(9); stw 9,0x1c(1); bl _s801350D4_5; lwz 30,0x4(29); lwz 0,0xc(29); cmpw 30,0; beq 4f; lwz 0,0x1c(1); addi 27,27,1; stw 0,0x0(30); lwz 9,0x4(29); addi 9,9,4; stw 9,0x4(29); b 15f; 4:; lwz 0,0x4(24); li 9,1; stw 9,0x24(1); addi 10,1,36; subf 0,0,30; addi 11,1,32; srawi 9,0,2; stw 9,0x20(1); cmplwi 9,1; bge 5f; mr 11,10; 5:; lwz 0,0x0(11); add. 0,9,0; beq 7f; rlwinm 0,0,2,0,29; mr 28,0; cmplwi 0,128; ble 6f; mr 3,28; bl _s801350D4_6; mr 31,3; b 8f; 6:; mr 3,28; bl _s801350D4_7; mr 31,3; b 8f; 7:; li 31,0; li 28,0; 8:; lwz 4,0x0(29); cmpw 30,4; beq 9f; subf 30,4,30; mr 3,31; mr 5,30; bl _s801350D4_8; add 0,3,30; b 10f; 9:; mr 0,31; 10:; lwz 9,0x24(1); mr 30,0; addi 27,27,1; mtspr 9,9; cmpwi 9,0; beq 12f; 11:; lwz 0,0x0(22); stw 0,0x0(30); addi 30,30,4; bdnz 11b; 12:; lwz 3,0x0(29); lwz 0,0xc(29); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 14f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 13f; bl _s801350D4_9; b 14f; 13:; bl _s801350D4_10; 14:; add 0,28,31; stw 31,0x0(29); stw 30,0x4(29); stw 0,0xc(29); 15:; cmpw 27,21; blt 3b; 16:; lwz 0,0x5c(1); mtspr 8,0; lmw 21,0x2c(1); addi 1,1,88"
extern "C" void _s801350D4_0();
extern "C" void _s801350D4_1();
extern "C" void _s801350D4_2();
extern "C" void _s801350D4_3();
extern "C" void _s801350D4_4();
extern "C" void _s801350D4_5();
extern "C" void _s801350D4_6();
extern "C" void _s801350D4_7();
extern "C" void _s801350D4_8();
extern "C" void _s801350D4_9();
extern "C" void _s801350D4_10();
extern "C" void f_801350D4() {}
