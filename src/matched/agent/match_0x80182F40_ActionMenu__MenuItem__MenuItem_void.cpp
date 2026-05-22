// 0x80182F40 ActionMenu::MenuItem::MenuItem(void) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; addi 3,30,4; bl _s80182F40_0; addi 3,30,72; bl _s80182F40_1; li 0,0; mr 3,30; stw 0,0x60(30); stw 0,0x0(30); stw 0,0x4c(30); stw 0,0x50(30); stw 0,0x54(30); stw 0,0x58(30); stw 0,0x5c(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80182F40_0();
extern "C" void _s80182F40_1();
extern "C" void f_80182F40() {}
