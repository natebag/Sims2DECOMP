// 0x80292994 AptCIH::jumpToFrame(int) (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; mfcr 12; stmw 25,0xc(1); stw 0,0x2c(1); stw 12,0x8(1); mr 27,3; mr. 31,4; lwz 29,0x4c(27); blt 8f; lwz 3,0x8(29); lwz 0,0x8(3); cmpw 31,0; bge 8f; lwz 9,0x18(29); cmpw 31,9; beq 8f; addi 0,9,1; cmpw 31,0; bne 0f; stw 31,0x18(29); addi 3,3,8; mr 6,31; addi 4,29,36; mr 5,27; bl _s80292994_0; b 7f; 0:; lwz 3,-23020(13); li 4,8; lwz 25,0xc(29); bl _s80292994_1; mr 28,3; li 4,20; lwz 3,-23020(13); bl _s80292994_2; li 4,0; li 5,0; li 6,0; li 7,0; bl _s80292994_3; stw 3,0x0(28); li 9,0; stw 27,0x4(28); lwz 0,0x18(29); cmpw 0,31; mfcr 26; rlwinm 26,26,1,31,31; bge 1f; mr 9,0; 1:; stw 9,0x18(29); cmpw 9,31; addi 30,29,36; cmpwi 4,28,0; b 3f; 2:; lwz 5,0x18(29); addi 3,3,8; mr 4,28; bl _s80292994_4; lwz 9,0x18(29); addi 9,9,1; stw 9,0x18(29); cmpw 9,31; 3:; bgt 4f; lwz 3,0x8(29); lwz 0,0x8(3); cmpw 9,0; blt 2b; 4:; stw 31,0x18(29); mr 3,30; mr 5,25; mr 6,26; mr 4,28; bl _s80292994_5; beq cr4,7f; mr 3,28; bl _s80292994_6; lwz 31,0x0(28); cmpwi 31,0; beq 6f; lwz 9,0x4(31); li 30,0; stw 30,0x0(31); stw 30,0x8(31); cmpwi 9,0; stw 30,0xc(31); beq 5f; mr 3,9; stw 30,0x0(9); stw 30,0x4(9); li 4,28; stw 30,0x8(9); bl _s80292994_7; stw 30,0x4(31); 5:; mr 3,31; li 4,20; bl _s80292994_8; 6:; mr 3,28; li 4,8; bl _s80292994_9; 7:; lwz 0,0x18(29); mr 4,27; lwz 3,0x8(29); mr 5,0; stw 0,0x28(29); addi 3,3,8; bl _s80292994_10; 8:; lwz 0,0x2c(1); lwz 12,0x8(1); mtspr 8,0; lmw 25,0xc(1); mtcrf 8,12; addi 1,1,40"
extern "C" void _s80292994_0();
extern "C" void _s80292994_1();
extern "C" void _s80292994_2();
extern "C" void _s80292994_3();
extern "C" void _s80292994_4();
extern "C" void _s80292994_5();
extern "C" void _s80292994_6();
extern "C" void _s80292994_7();
extern "C" void _s80292994_8();
extern "C" void _s80292994_9();
extern "C" void _s80292994_10();
extern "C" void f_80292994() {}
