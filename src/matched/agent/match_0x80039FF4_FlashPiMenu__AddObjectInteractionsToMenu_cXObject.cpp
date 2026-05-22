// 0x80039FF4 FlashPiMenu::AddObjectInteractionsToMenu(cXObject (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; mfcr 12; stmw 28,0x28(1); stw 0,0x3c(1); stw 12,0x24(1); mr 28,3; mr 31,4; addi 3,1,8; mr 30,5; bl _s80039FF4_0; lwz 5,0x8(28); mr 3,31; lwz 6,-21280(13); addi 4,1,8; bl _s80039FF4_1; addi 3,1,8; bl _s80039FF4_2; cmpwi 3,0; beq 2f; li 0,0; mr 3,31; stw 0,0x18(1); addi 4,1,24; bl _s80039FF4_3; cmpwi 4,30,0; mr 29,3; bne cr4,0f; addi 30,1,16; mr 3,31; bl _s80039FF4_4; mr 4,3; mr 3,30; bl _s80039FF4_5; lis 9,-32697; lwz 4,0x8(28); lwz 3,0x5bc8(9); mr 7,29; lwz 8,0x18(1); mr 5,31; mr 6,30; bl _s80039FF4_6; mr 3,30; li 4,2; bl _s80039FF4_7; 0:; lwz 3,0x18(1); cmpwi 3,0; beq 1f; bl _s80039FF4_8; 1:; mr 4,31; mr 3,28; addi 5,1,8; bl _s80039FF4_9; bne cr4,2f; lis 9,-32697; lwz 4,0x8(28); lwz 3,0x5bc8(9); bl _s80039FF4_10; 2:; addi 3,1,8; li 4,2; bl _s80039FF4_11; lwz 0,0x3c(1); lwz 12,0x24(1); mtspr 8,0; lmw 28,0x28(1); mtcrf 8,12; addi 1,1,56"
extern "C" void _s80039FF4_0();
extern "C" void _s80039FF4_1();
extern "C" void _s80039FF4_2();
extern "C" void _s80039FF4_3();
extern "C" void _s80039FF4_4();
extern "C" void _s80039FF4_5();
extern "C" void _s80039FF4_6();
extern "C" void _s80039FF4_7();
extern "C" void _s80039FF4_8();
extern "C" void _s80039FF4_9();
extern "C" void _s80039FF4_10();
extern "C" void _s80039FF4_11();
extern "C" void f_80039FF4() {}
