// 0x80019DFC ESimsCam::CalcPitch(EVec3 (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f30,0x20(1); stfd f31,0x28(1); stw 31,0x1c(1); stw 0,0x34(1); mr 31,3; bl _s80019DFC_0; lis 9,-32707; fmr f31,f1; lfs f0,-7156(9); fcmpu 0,f31,f0; bge 0f; lis 9,-32707; lfs f1,-7152(9); b 1f; 0:; lfs f12,0x0(31); lis 9,-32707; lfs f13,0x4(31); addi 11,1,8; lfs f0,0x8(31); mr 3,11; stfs f12,0x8(1); lfs f30,-7152(9); stfs f13,0x4(11); stfs f0,0x8(11); stfs f30,0x10(1); bl _s80019DFC_1; fdivs f1,f1,f31; bl _s80019DFC_2; lfs f0,0x8(31); fcmpu 0,f0,f30; ble 1f; lis 9,-32707; lfs f0,-7148(9); fsubs f1,f0,f1; 1:; lwz 0,0x34(1); mtspr 8,0; lwz 31,0x1c(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80019DFC_0();
extern "C" void _s80019DFC_1();
extern "C" void _s80019DFC_2();

struct ESimsCam {
    void CalcPitch();
};

void ESimsCam::CalcPitch() {
}
