// 0x80098728 TheSimsMainMenuState::Reset(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 28,-32697; lis 9,-32696; addi 9,9,22744; li 29,0; addi 31,28,23428; li 27,1; stw 27,0x34(9); mr 3,31; stw 29,0x28(9); stw 29,0x2c(9); stw 27,0x30(9); bl _s80098728_0; lwz 3,-26524(13); li 0,-1; stw 0,0xa0(31); li 4,0; stw 29,0xa8(31); stw 29,0xa4(31); bl _s80098728_1; lwz 3,-26524(13); li 4,1; bl _s80098728_2; lis 30,-32697; lwz 3,-25136(13); addi 30,30,24012; li 4,1; lwz 9,0xb4(30); stw 29,0x3a8(9); bl _s80098728_3; lwz 9,0xb4(30); stw 29,0x478(30); stw 29,0x3ac(9); lwz 3,0x110(30); bl _s80098728_4; lwz 3,-32056(13); stw 27,0x5b84(28); cmpwi 3,0; beq 0f; bl _s80098728_5; 0:; lwz 0,0x68(31); cmpwi 0,0; bne 1f; li 3,404; bl _s80098728_6; bl _s80098728_7; stw 3,0x68(31); 1:; lwz 9,-24620(13); cmpwi 9,0; bne 2f; li 3,220; bl _s80098728_8; bl _s80098728_9; stw 3,-24620(13); b 3f; 2:; stw 27,0xd4(9); stw 27,0xd8(9); 3:; li 0,1; stw 0,-28404(13); stw 0,-28408(13); lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"
extern "C" void _s80098728_0();
extern "C" void _s80098728_1();
extern "C" void _s80098728_2();
extern "C" void _s80098728_3();
extern "C" void _s80098728_4();
extern "C" void _s80098728_5();
extern "C" void _s80098728_6();
extern "C" void _s80098728_7();
extern "C" void _s80098728_8();
extern "C" void _s80098728_9();
extern "C" void f_80098728() {}
