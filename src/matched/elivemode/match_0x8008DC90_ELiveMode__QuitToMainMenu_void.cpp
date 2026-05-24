// 0x8008DC90 ELiveMode::QuitToMainMenu(void) (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; lis 30,-32697; lwz 11,0x5e80(9); li 0,0; addi 30,30,23428; stw 0,0x90(30); stw 0,0x3a8(11); stw 0,0x24(3); bl _s8008DC90_0; lwz 11,-21484(13); lwz 9,0x0(11); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,11,3; blrl; bl _s8008DC90_1; lwz 11,-21424(13); lwz 9,0x0(11); lwz 0,0x94(9); lha 3,0x90(9); mtspr 8,0; add 3,11,3; blrl; bl _s8008DC90_2; lwz 3,-21492(13); bl _s8008DC90_3; lis 9,-32697; li 0,1; lwz 3,-6528(9); stw 0,0x94(30); bl _s8008DC90_4; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21496(13); lwz 9,0x0(11); lha 3,0x50(9); lwz 0,0x54(9); add 3,11,3; mtspr 8,0; blrl; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8008DC90_0();
extern "C" void _s8008DC90_1();
extern "C" void _s8008DC90_2();
extern "C" void _s8008DC90_3();
extern "C" void _s8008DC90_4();

struct ELiveMode {
    void QuitToMainMenu();
};

void ELiveMode::QuitToMainMenu() {
}
