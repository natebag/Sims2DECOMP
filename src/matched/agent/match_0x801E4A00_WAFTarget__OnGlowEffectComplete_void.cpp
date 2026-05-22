// 0x801E4A00 WAFTarget::OnGlowEffectComplete(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,0; stw 0,0x270(3)"
extern "C" void f_801E4A00() {}
