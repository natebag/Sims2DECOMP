// 0x801843FC ActionMenu::TerminateMenu(void) (292 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; lbz 0,0x9(31); cmpwi 0,9; bne 3f; lwz 9,0xa8(31); addi 8,13,-31480; li 11,0; addi 10,31,112; rlwinm 9,9,2,0,29; mr 29,10; stwx 11,9,8; lbz 0,0xa0(31); rlwinm 0,0,2,0,29; lwzx 3,10,0; bl _s801843FC_0; mr. 30,3; beq 1f; lwz 0,0x5c(30); cmpwi 0,0; bne 1f; bl _s801843FC_1; lwz 4,0xa8(31); li 5,2; bl _s801843FC_2; cmpwi 3,0; li 0,1; bne 0f; li 0,0; 0:; cmpwi 0,0; bne 1f; lwz 11,0xa8(31); lis 9,-32697; addi 9,9,23428; rlwinm 11,11,4,0,27; add 11,11,9; lwz 3,0xfc(11); cmpwi 3,0; beq 1f; addi 5,30,4; li 4,0; li 6,1; bl _s801843FC_3; 1:; addi 30,31,12; mr 3,30; bl _s801843FC_4; li 0,3; li 9,8; stb 0,0x9(31); li 11,0; li 0,7; li 10,0; mtspr 9,0; sth 9,0x4(31); stb 11,0xa0(31); li 7,0; sth 10,0x6(31); addi 8,31,146; stw 30,0x70(31); addi 9,29,4; 2:; stw 7,0x0(9); sth 7,0x0(8); addi 9,9,4; addi 8,8,2; bdnz 2b; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s801843FC_0();
extern "C" void _s801843FC_1();
extern "C" void _s801843FC_2();
extern "C" void _s801843FC_3();
extern "C" void _s801843FC_4();

struct ActionMenu {
    void TerminateMenu();
};

void ActionMenu::TerminateMenu() {
}
