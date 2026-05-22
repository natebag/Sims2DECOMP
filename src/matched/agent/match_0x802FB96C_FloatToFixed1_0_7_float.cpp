// 0x802FB96C FloatToFixed1_0_7(float) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); lis 9,-32702; lis 11,-32702; lfs f13,-2776(9); lfs f0,-2772(11); fmuls f1,f1,f13; fcmpu 0,f1,f0; bge 0f; li 3,-127; b 2f; 0:; fcmpu 0,f1,f13; ble 1f; li 3,127; b 2f; 1:; fmr f0,f1; fctiwz f13,f0; stfd f13,0x8(1); lwz 9,0xc(1); extsb 3,9; 2:; addi 1,1,16"
extern "C" void f_802FB96C() {}
