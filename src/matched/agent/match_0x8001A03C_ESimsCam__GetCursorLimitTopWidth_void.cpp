// 0x8001A03C ESimsCam::GetCursorLimitTopWidth(void) (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 11,0x0(3); lis 9,-32697; lfs f13,0x448(3); addi 9,9,13588; lfs f11,0x28(11); lfs f0,0x2c(11); fsubs f13,f13,f11; lfs f12,0x90(9); fsubs f0,f0,f11; lfs f1,0x94(9); fdivs f13,f13,f0; fsubs f1,f1,f12; fmadds f1,f13,f1,f12"
extern "C" float f_8001A03C() {}
