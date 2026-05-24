// 0x8016F488 CasSimRenderer::SetNextAnimation(unsigned (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lis 29,-32693; addi 3,29,11064; bl _s8016F488_0; cmpwi 3,0; bne 0f; stw 31,0x204(30); addi 3,29,11064; mr 4,31; bl _s8016F488_1; b 1f; 0:; lis 9,-32706; addi 30,30,372; lfs f1,0x174c(9); li 4,1; mr 5,31; mr 3,30; li 6,-1; li 7,0; bl _s8016F488_2; mr 3,30; li 4,1; bl _s8016F488_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s8016F488_0();
extern "C" void _s8016F488_1();
extern "C" void _s8016F488_2();
extern "C" void _s8016F488_3();

struct CasSimRenderer {
    void SetNextAnimation();
};

void CasSimRenderer::SetNextAnimation() {
}
