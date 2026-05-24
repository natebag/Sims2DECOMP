// 0x80183EA0 ActionMenu::AddMenu(cXObject (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; mr 27,4; lbz 0,0xa0(29); addi 9,29,112; mr 28,5; mr 25,6; rlwinm 0,0,2,0,29; mr 26,7; lwzx 3,9,0; bl _s80183EA0_0; b 1f; 0:; mr 3,31; bl _s80183EA0_1; 1:; mr 31,3; cmpwi 31,0; beq 2f; addi 3,31,72; mr 4,28; bl _s80183EA0_2; cmpwi 3,0; beq 0b; lwz 0,0x0(31); cmpw 0,27; bne 0b; addi 30,29,112; b 3f; 2:; li 3,100; addi 30,29,112; bl _s80183EA0_3; bl _s80183EA0_4; mr 31,3; mr 4,27; mr 6,28; mr 7,25; mr 8,26; li 5,0; li 9,0; bl _s80183EA0_5; lbz 0,0xa0(29); mr 4,31; rlwinm 0,0,2,0,29; lwzx 3,30,0; bl _s80183EA0_6; 3:; lbz 9,0xa0(29); addi 9,9,1; stb 9,0xa0(29); rlwinm 9,9,2,22,29; stwx 31,30,9; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80183EA0_0();
extern "C" void _s80183EA0_1();
extern "C" void _s80183EA0_2();
extern "C" void _s80183EA0_3();
extern "C" void _s80183EA0_4();
extern "C" void _s80183EA0_5();
extern "C" void _s80183EA0_6();

struct ActionMenu {
    void AddMenu_cXObject();
};

void ActionMenu::AddMenu_cXObject() {
}
