// 0x80064858 SAnimator2::UnloadPendingLongIdleAnim(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; li 9,0; lwz 0,0x61c(31); li 4,-1; stw 9,0x11c(31); andis. 0,0,8; beq 3f; lbz 0,0x5fb(31); cmpwi 0,0; beq 0f; mr 4,0; 0:; cmpwi 4,-1; beq 4f; lwz 3,0x4(31); addi 5,1,8; lis 30,-32693; bl _s80064858_0; lwz 9,0x8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s80064858_1; cmpwi 3,0; beq 1f; lwz 9,0x8(1); addi 3,30,11064; li 5,1; lwz 4,0x0(9); bl _s80064858_2; b 2f; 1:; lwz 9,0x8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s80064858_3; 2:; lwz 0,0x61c(31); li 9,0; stb 9,0x5fb(31); rlwinm 0,0,0,13,11; stw 0,0x61c(31); b 4f; 3:; stb 0,0x5fb(31); 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s80064858_0();
extern "C" void _s80064858_1();
extern "C" void _s80064858_2();
extern "C" void _s80064858_3();

struct SAnimator2 {
    void UnloadPendingLongIdleAnim();
};

void SAnimator2::UnloadPendingLongIdleAnim() {
}
