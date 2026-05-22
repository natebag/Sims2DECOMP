// 0x80038E50 EyeToyClient::ApplyFunFrame(int) (20 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-32564(13); cmpw 3,0; beqlr; stw 3,-32564(13)"
extern "C" void f_80038E50() {}
