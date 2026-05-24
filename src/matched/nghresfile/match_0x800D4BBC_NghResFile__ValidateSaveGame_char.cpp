// 0x800D4BBC NghResFile::ValidateSaveGame(char (320 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 11,-32696; mr 27,4; lwz 9,0x6330(11); mr 31,6; li 25,0; andi. 0,5,128; addi 9,9,24; lwz 28,0x4(9); lwz 26,0x8(9); beq 0f; oris 0,5,65535; ori 29,0,65280; b 1f; 0:; mr 29,5; 1:; bl _s800D4BBC_0; mr 4,28; li 5,64; li 6,0; li 7,0; bl _s800D4BBC_1; mr 30,3; cmpwi 31,0; beq 2f; lis 0,-8531; ori 0,0,48879; stw 0,0x0(30); b 4f; 2:; stw 31,0x0(30); b 4f; 3:; lwz 3,-26384(13); mr 6,28; mr 7,26; mr 4,27; lwz 9,0x0(3); mr 5,29; mr 8,30; li 25,1; lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; b 5f; 4:; lwz 3,-26384(13); mr 4,27; mr 5,29; lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr 31,3; cmpwi 31,1; beq 3b; 5:; bl _s800D4BBC_2; mr 4,30; bl _s800D4BBC_3; cmpwi 25,0; beq 6f; lwz 3,-26384(13); mr 4,27; mr 5,29; lwz 9,0x0(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; 6:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800D4BBC_0();
extern "C" void _s800D4BBC_1();
extern "C" void _s800D4BBC_2();
extern "C" void _s800D4BBC_3();

struct NghResFile {
    void ValidateSaveGame();
};

void NghResFile::ValidateSaveGame() {
}
