// 0x80183F84 ActionMenu::AddMenuItem(cXObject (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 29,3; mr 30,5; mr 24,4; mr 28,6; mr 27,7; mr 26,8; mr 25,9; li 3,100; bl _s80183F84_0; bl _s80183F84_1; mr 5,30; mr 4,24; mr 30,3; mr 6,28; mr 7,27; mr 8,26; mr 9,25; bl _s80183F84_2; lbz 0,0xa0(29); mr 4,30; addi 29,29,112; rlwinm 0,0,2,0,29; lwzx 3,29,0; bl _s80183F84_3; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s80183F84_0();
extern "C" void _s80183F84_1();
extern "C" void _s80183F84_2();
extern "C" void _s80183F84_3();

struct ActionMenu {
    void AddMenuItem_cXObject();
};

void ActionMenu::AddMenuItem_cXObject() {
}
