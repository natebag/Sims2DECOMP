// 0x8005C610 SAnimator2::InitStaticAnimationElements(void) (348 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 28,-32688; li 4,0; li 5,232; addi 3,28,-18288; bl _s8005C610_0; lis 27,-32688; li 4,0; li 5,232; addi 3,27,-19768; lis 29,-32688; bl _s8005C610_1; lis 25,-32688; li 4,0; li 5,232; addi 3,29,-18056; lis 26,-32688; bl _s8005C610_2; lis 30,-32688; li 4,0; li 5,232; addi 3,25,-17824; bl _s8005C610_3; li 4,0; li 5,232; addi 3,26,-17592; bl _s8005C610_4; addi 3,30,-20000; li 4,0; li 5,232; bl _s8005C610_5; lis 9,-32707; addi 28,28,-18288; lfs f0,0x4568(9); addi 27,27,-19768; addi 29,29,-18056; addi 25,25,-17824; stfs f0,0xd8(28); addi 26,26,-17592; stfs f0,0xac(27); addi 30,30,-20000; stfs f0,0xcc(29); stfs f0,0x40(25); stfs f0,0xe4(26); stfs f0,0xbc(28); stfs f0,0xc0(28); stfs f0,0xc4(28); stfs f0,0xc8(28); stfs f0,0xcc(28); stfs f0,0xd0(28); stfs f0,0xd4(28); stfs f0,0x9c(27); stfs f0,0xa0(27); stfs f0,0xa4(27); stfs f0,0xa8(27); stfs f0,0x9c(29); stfs f0,0xa0(29); stfs f0,0xa4(29); stfs f0,0xa8(29); stfs f0,0xac(29); stfs f0,0xbc(29); stfs f0,0xc0(29); stfs f0,0xc4(29); stfs f0,0xc8(29); stfs f0,0x30(30); stfs f0,0x34(30); stfs f0,0x38(30); stfs f0,0x3c(30); stfs f0,0x40(30); stfs f0,0xbc(30); stfs f0,0xc0(30); stfs f0,0xc4(30); stfs f0,0xac(30); stfs f0,0xc8(30); stfs f0,0xcc(30); stfs f0,0x9c(30); stfs f0,0xa0(30); stfs f0,0xa4(30); stfs f0,0xa8(30); lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s8005C610_0();
extern "C" void _s8005C610_1();
extern "C" void _s8005C610_2();
extern "C" void _s8005C610_3();
extern "C" void _s8005C610_4();
extern "C" void _s8005C610_5();

struct SAnimator2 {
    void InitStaticAnimationElements();
};

void SAnimator2::InitStaticAnimationElements() {
}
