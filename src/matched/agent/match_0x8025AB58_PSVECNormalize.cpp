// 0x8025AB58 PSVECNormalize (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lfs f0,-18484(13); lfs f1,-18480(13); .long 0xE0430000; .long 0x10A200B2; .long 0xE0638008; .long 0x108328FA; .long 0x108428D4; .long 0xFCA02034; fmuls f6,f5,f5; fmuls f0,f5,f0; fnmsubs f6,f6,f4,f1; fmuls f5,f6,f0; .long 0x10420158; .long 0xF0440000; .long 0x10630158; .long 0xF0648008"
extern "C" float f_8025AB58() {}
