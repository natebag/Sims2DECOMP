// 0x8015EDCC Neighbor::FindBookmarkToReplace(unsigned (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stb 0,0x0(9); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,6; mr 28,3; mr 31,4; mr 30,5; mr 4,29; bl _s8015EDCC_0; cmpwi 3,0; bne 0f; li 3,0; b 1f; 0:; mulli 9,30,40; rlwinm 0,31,2,0,29; add 0,0,31; rlwinm 0,0,8,0,23; add 9,29,9; add 9,9,0; lbzx 3,28,9; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,6; mr 31,3; mr 28,4; mr 30,5; mr 4,29; bl _s8015EDCC_1; cmpwi 3,0; bne 2f; li 3,0; b 3f; 2:; mulli 0,30,30; addi 11,31,2560; mulli 9,28,240; add 0,29,0; add 0,0,9; lbzx 3,11,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24; blr; stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,6; mr 29,3; mr 31,4; mr 30,5; mr 4,28; bl _s8015EDCC_2; cmpwi 3,0; bne 4f; li 3,0; b 5f; 4:; mulli 9,30,40; rlwinm 0,31,2,0,29; add 0,0,31; rlwinm 0,0,8,0,23; add 0,0,29; add 9,9,0; lbzx 3,9,28; rlwinm 3,3,31,31,31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s8015EDCC_0();
extern "C" void _s8015EDCC_1();
extern "C" void _s8015EDCC_2();

struct Neighbor {
    void FindBookmarkToReplace();
};

void Neighbor::FindBookmarkToReplace() {
}
