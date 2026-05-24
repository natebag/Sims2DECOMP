// 0x8036B3AC RParticle::Deallocate(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 9,0x0(30); lwz 0,0x6c(9); lha 3,0x68(9); mtspr 8,0; add 3,30,3; blrl; lis 3,-32692; lwz 4,0x14(30); addi 3,3,6092; bl _s8036B3AC_0; li 0,0; stw 0,0x14(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8036B3AC_0();

struct RParticle {
    void Deallocate();
};

void RParticle::Deallocate() {
}
