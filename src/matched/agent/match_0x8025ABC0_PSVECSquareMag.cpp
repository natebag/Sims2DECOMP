// 0x8025ABC0 PSVECSquareMag (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines=".long 0xE0030000; .long 0x10000032; lfs f1,0x8(3); .long 0x1021007A; .long 0x10210014"
extern "C" float f_8025ABC0() {}
