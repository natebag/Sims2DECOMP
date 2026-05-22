// 0x803BE440 PCwriteAsyncInit (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_803BE450" lines="mr 26,3"
extern "C" void f_803BE450();
extern "C" void f_803BE440() {}
