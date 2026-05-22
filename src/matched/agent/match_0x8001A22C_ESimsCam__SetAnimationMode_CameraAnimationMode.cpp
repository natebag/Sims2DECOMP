// 0x8001A22C ESimsCam::SetAnimationMode(CameraAnimationMode, (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 7,0; stw 4,0x554(3); stw 5,0x558(3); stw 6,0x55c(3); beqlr; li 0,1; stw 0,0x478(3)"
extern "C" void f_8001A22C() {}
