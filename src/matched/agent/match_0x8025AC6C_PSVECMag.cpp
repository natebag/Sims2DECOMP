// 0x8025AC6C PSVECMag (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f4,-18484(13); .long 0xE0030000; .long 0x10000032; lfs f1,0x8(3); fsubs f2,f4,f4; .long 0x1021007A; .long 0x10210014; fcmpu 0,f1,f2; beq 0f; .long 0xFC000834; lfs f3,-18480(13); fmuls f2,f0,f0; fmuls f0,f0,f4; fnmsubs f2,f2,f1,f3; fmuls f0,f2,f0; fmuls f1,f1,f0; 0:"
extern "C" float f_8025AC6C() {}
