// 0x8001DFC8 CameraDirector::LetterBox(bool) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x240(3); xoris 0,0,1; andi. 9,0,1; beqlr; stw 4,0x234(3)"
extern "C" void f_8001DFC8() {}
