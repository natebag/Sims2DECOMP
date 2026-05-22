// 0x803571C0 MotionBlur::UpdateTargetParameters(float) (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; fmr f31,f1; lwz 0,0xc(31); cmpwi 0,2; bne 0f; lis 30,-32702; lfs f2,0x14(31); lfs f3,0x2adc(30); fmr f5,f31; lfs f4,0x0(31); lfs f1,0x2c(31); bl _s803571C0_0; stfs f1,0x20(31); fmr f5,f31; lfs f3,0x2adc(30); lfs f1,0x30(31); lfs f2,0x18(31); lfs f4,0x0(31); bl _s803571C0_1; lwz 0,0x1c(31); b 1f; 0:; cmpwi 0,8; bne 2f; lis 30,-32702; lfs f4,0x4(31); lfs f2,0x2adc(30); fmr f5,f31; lfs f1,0x2c(31); fmr f3,f2; bl _s803571C0_2; stfs f1,0x20(31); fmr f5,f31; lfs f2,0x2adc(30); lfs f1,0x30(31); lfs f4,0x4(31); fmr f3,f2; bl _s803571C0_3; li 0,0; 1:; stfs f1,0x24(31); stw 0,0x28(31); 2:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"
extern "C" void _s803571C0_0();
extern "C" void _s803571C0_1();
extern "C" void _s803571C0_2();
extern "C" void _s803571C0_3();
extern "C" void f_803571C0() {}
