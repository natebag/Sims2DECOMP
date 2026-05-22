// 0x802E38B8 EEngine::EnableFrameRatePredictiveSmoothing(bool) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 4,0x8(3)"
extern "C" void f_802E38B8() {}
