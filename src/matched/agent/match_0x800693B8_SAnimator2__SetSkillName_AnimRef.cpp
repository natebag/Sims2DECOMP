// 0x800693B8 SAnimator2::SetSkillName(AnimRef (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x61c(3); lis 9,-32707; lfs f0,0x4c0c(9); li 11,0; oris 0,0,1; stw 11,0xc8(3); stw 0,0x61c(3); stfs f0,0xd0(3); stw 4,0xd4(3)"
extern "C" void f_800693B8() {}
