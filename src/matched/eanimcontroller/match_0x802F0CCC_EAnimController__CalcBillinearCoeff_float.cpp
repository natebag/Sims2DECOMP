// 0x802F0CCC EAnimController::CalcBillinearCoeff(float, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="fmr f12,f1; lis 9,-32702; fmuls f1,f2,f3; lfs f13,-4284(9); stfs f12,0x0(3); fmuls f2,f12,f2; stfs f2,0x0(4); fcmpu 0,f1,f13; bne 0f; lis 9,-32702; lfs f0,-4280(9); b 1f; 0:; fsubs f0,f1,f3; fmuls f0,f12,f0; fsubs f13,f1,f13; fdivs f0,f0,f13; 1:; stfs f0,0x0(5); fmuls f0,f12,f1; stfs f0,0x0(6)"

struct EAnimController {
    void CalcBillinearCoeff();
};

void EAnimController::CalcBillinearCoeff() {
}
