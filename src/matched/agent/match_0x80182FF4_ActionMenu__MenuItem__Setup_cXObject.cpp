// 0x80182FF4 ActionMenu::MenuItem::Setup(cXObject (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; mr 29,6; stw 4,0x0(31); mr 26,7; mr 28,8; mr 27,9; mr. 4,5; beq 0f; addi 3,31,4; bl _s80182FF4_0; 0:; addi 30,31,72; mr 4,29; mr 3,30; bl _s80182FF4_1; mr 3,30; bl _s80182FF4_2; addi 29,3,1; rlwinm 3,29,2,0,29; bl _s80182FF4_3; stw 3,0x4c(31); mr 3,30; bl _s80182FF4_4; lwz 5,0x4c(31); mr 4,29; bl _s80182FF4_5; cmpwi 28,0; beq 1f; mr 3,28; bl _s80182FF4_6; 1:; lwz 3,0x54(31); cmpwi 3,0; beq 2f; bl _s80182FF4_7; 2:; stw 27,0x58(31); stw 26,0x50(31); stw 28,0x54(31); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80182FF4_0();
extern "C" void _s80182FF4_1();
extern "C" void _s80182FF4_2();
extern "C" void _s80182FF4_3();
extern "C" void _s80182FF4_4();
extern "C" void _s80182FF4_5();
extern "C" void _s80182FF4_6();
extern "C" void _s80182FF4_7();
extern "C" void f_80182FF4() {}
