// 0x800756DC SimsMemCardWrap::SaveNewGame(int) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; b 1f; 0:; mr 3,30; bl _s800756DC_0; mr 31,3; b 2f; 1:; lwz 11,-21476(13); li 4,7; li 5,9; lwz 9,0x0(11); lwz 0,0x8c(9); lha 3,0x88(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); lwz 4,-32056(13); lwz 9,0x0(11); lwz 5,-32040(13); lha 3,0x68(9); lwz 0,0x6c(9); add 3,11,3; mtspr 8,0; blrl; lwz 3,-32056(13); rlwinm 5,30,0,24,31; lwz 4,-31932(13); bl _s800756DC_1; mr 31,3; cmpwi 31,1; beq 0b; 2:; lwz 3,-31932(13); mr 4,30; bl _s800756DC_2; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800756DC_0();
extern "C" void _s800756DC_1();
extern "C" void _s800756DC_2();

struct SimsMemCardWrap {
    void SaveNewGame();
};

void SimsMemCardWrap::SaveNewGame() {
}
