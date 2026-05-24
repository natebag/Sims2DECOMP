// 0x8007578C SimsMemCardWrap::PreloadGame(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); lis 29,-32697; mr 28,3; addi 29,29,24012; lwz 3,0x148(29); addi 3,3,160; bl _s8007578C_0; lis 30,-32696; lwz 11,0x148(29); addi 30,30,22744; lwz 0,0x4(30); addi 9,30,16; rlwinm 0,0,2,0,29; stwx 3,9,0; addi 3,11,88; bl _s8007578C_1; lwz 0,0x4(30); mr 4,28; addi 30,30,24; rlwinm 0,0,2,0,29; stwx 3,30,0; lwz 3,-31932(13); bl _s8007578C_2; mr 30,3; mr 4,28; lwz 3,-31932(13); bl _s8007578C_3; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8007578C_0();
extern "C" void _s8007578C_1();
extern "C" void _s8007578C_2();
extern "C" void _s8007578C_3();

struct SimsMemCardWrap {
    void PreloadGame();
};

void SimsMemCardWrap::PreloadGame() {
}
