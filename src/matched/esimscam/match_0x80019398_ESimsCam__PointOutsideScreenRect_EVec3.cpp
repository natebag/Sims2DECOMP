// 0x80019398 ESimsCam::PointOutsideScreenRect(EVec3 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stfd f28,0x10(1); stfd f29,0x18(1); stfd f30,0x20(1); stfd f31,0x28(1); stw 0,0x34(1); fmr f31,f1; addi 3,3,16; fmr f28,f2; addi 5,1,8; fmr f30,f3; fmr f29,f4; bl _s80019398_0; lfs f0,0x8(1); li 3,0; fcmpu 0,f0,f31; bge 0f; li 3,1; 0:; fcmpu 0,f0,f30; ble 1f; ori 3,3,2; 1:; lfs f0,0xc(1); fcmpu 0,f0,f28; bge 2f; ori 3,3,4; 2:; fcmpu 0,f0,f29; ble 3f; ori 3,3,8; 3:; lwz 0,0x34(1); mtspr 8,0; lfd f28,0x10(1); lfd f29,0x18(1); lfd f30,0x20(1); lfd f31,0x28(1); addi 1,1,48"

extern "C" void _s80019398_0();

struct ESimsCam {
    void PointOutsideScreenRect();
};

void ESimsCam::PointOutsideScreenRect() {
}
