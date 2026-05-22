// 0x8022972C EInstance::ShouldInterestFade(bool) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="xori 4,4,1; subfic 0,4,0; adde 4,0,4; stw 4,0x6c(3)"
extern "C" void f_8022972C() {}
