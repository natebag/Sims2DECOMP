// 0x8025ABD8 C_VECMag (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lfs f1,0x0(3); lfs f0,0x4(3); fmuls f2,f1,f1; lfs f3,0x8(3); fmuls f1,f0,f0; lfs f0,-18512(13); fmuls f3,f3,f3; fadds f1,f2,f1; fadds f1,f3,f1; fcmpo f0,f1,f0; ble 0f; .long 0xFC400834; lfd f4,-18504(13); lfd f3,-18496(13); fmul f0,f2,f2,f0; fmul f2,f4,f2,f0; fmul f0,f1,f0,f0; fsub f0,f3,f0; fmul f2,f2,f0,f0; fmul f0,f2,f2,f0; fmul f2,f4,f2,f0; fmul f0,f1,f0,f0; fsub f0,f3,f0; fmul f2,f2,f0,f0; fmul f0,f2,f2,f0; fmul f2,f4,f2,f0; fmul f0,f1,f0,f0; fsub f0,f3,f0; fmul f0,f2,f0,f0; fmul f0,f1,f0,f0; frsp f0,f0; stfs f0,0x14(1); lfs f1,0x14(1); b 0f; 0:; addi 1,1,24"
extern "C" void f_8025ABD8() {}
