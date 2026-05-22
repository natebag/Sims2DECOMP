// 0x8025B044 PSVECDistance (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030004; .long 0xE0240004; .long 0x10400828; .long 0xE0030000; .long 0xE0240000; .long 0x104200B2; .long 0x10000828; lfs f3,-18484(13); .long 0x1020103A; fsubs f0,f3,f3; .long 0x10211094; fcmpu 0,f0,f1; beq 0f; lfs f4,-18480(13); .long 0xFC000834; fmuls f2,f0,f0; fmuls f0,f0,f3; fnmsubs f2,f2,f1,f4; fmuls f0,f2,f0; fmuls f1,f1,f0; 0:"
extern "C" float f_8025B044() {}
