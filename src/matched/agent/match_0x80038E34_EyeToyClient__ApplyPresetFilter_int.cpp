// 0x80038E34 EyeToyClient::ApplyPresetFilter(int) (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-32556(13); cmpw 3,0; beqlr; li 0,1; stw 3,-32556(13); stw 0,-32552(13)"
extern "C" void f_80038E34() {}
