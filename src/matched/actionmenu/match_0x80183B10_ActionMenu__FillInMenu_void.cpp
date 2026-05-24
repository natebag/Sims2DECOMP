// 0x80183B10 ActionMenu::FillInMenu(void) (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lbz 0,0xa0(31); addi 9,31,112; rlwinm 0,0,2,0,29; lwzx 3,9,0; bl _s80183B10_0; mr. 29,3; beq 4f; mr 3,29; bl _s80183B10_1; rlwinm 0,3,0,24,31; stb 3,0xa2(31); cmpwi 0,0; beq 4f; stb 3,0xa1(31); cmplwi 0,5; ble 0f; li 0,5; stb 0,0xa1(31); 0:; lha 0,0x6(31); subfic 4,0,2; cmpwi 4,0; neg 4,4; blt 1f; li 4,0; 1:; mr 3,29; bl _s80183B10_2; mr 30,3; lbz 4,0x7(31); mr 3,29; bl _s80183B10_3; mr 29,3; lwz 4,0x0(30); lwz 3,-21484(13); bl _s80183B10_4; cmpwi 3,0; beq 3f; cmpwi 29,0; beq 2f; lwz 3,0x0(29); cmpwi 3,0; beq 2f; lwz 11,0x0(3); lwz 9,0x18(11); lwz 0,0x9c(9); lha 3,0x98(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xa8(31); addi 9,13,-31480; rlwinm 0,0,2,0,29; stwx 3,9,0; 2:; mr 3,31; bl _s80183B10_5; b 4f; 3:; li 0,9; mr 3,31; stb 0,0x9(31); bl _s80183B10_6; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80183B10_0();
extern "C" void _s80183B10_1();
extern "C" void _s80183B10_2();
extern "C" void _s80183B10_3();
extern "C" void _s80183B10_4();
extern "C" void _s80183B10_5();
extern "C" void _s80183B10_6();

struct ActionMenu {
    void FillInMenu();
};

void ActionMenu::FillInMenu() {
}
