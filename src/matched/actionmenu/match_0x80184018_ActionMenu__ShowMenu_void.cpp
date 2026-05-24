// 0x80184018 ActionMenu::ShowMenu(void) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lbz 0,0xa0(31); addi 29,31,112; rlwinm 0,0,2,0,29; lwzx 3,29,0; bl _s80184018_0; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; lwz 0,-31536(13); cmpwi 0,0; bne 1f; li 3,120; bl _s80184018_1; bl _s80184018_2; stw 3,-31536(13); 1:; lwz 3,-31536(13); lis 4,-13004; ori 4,4,43996; li 30,0; bl _s80184018_3; li 0,2; lbz 9,0xa0(31); stb 0,0x9(31); sth 30,0x4(31); rlwinm 9,9,2,0,29; lwzx 3,29,9; bl _s80184018_4; bl _s80184018_5; stb 3,0xa2(31); sth 30,0x6(31); mr 3,31; bl _s80184018_6; lwz 4,0xa8(31); lwz 3,-26524(13); bl _s80184018_7; mr 30,3; lis 5,-32705; addi 5,5,-23132; li 4,0; li 6,100; bl _s80184018_8; mr 4,3; lis 5,-32701; mr 3,30; stw 4,0xac(31); addi 5,5,27528; li 6,6; bl _s80184018_9; li 3,1; 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80184018_0();
extern "C" void _s80184018_1();
extern "C" void _s80184018_2();
extern "C" void _s80184018_3();
extern "C" void _s80184018_4();
extern "C" void _s80184018_5();
extern "C" void _s80184018_6();
extern "C" void _s80184018_7();
extern "C" void _s80184018_8();
extern "C" void _s80184018_9();

struct ActionMenu {
    void ShowMenu();
};

void ActionMenu::ShowMenu() {
}
