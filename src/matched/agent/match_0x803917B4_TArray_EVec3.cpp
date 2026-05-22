// 0x803917B4 TArray<EVec3, (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_80391868" lines="lis 4,-13311; stb 0,-32768(4); li 0,32; stb 0,-32768(4); lwz 0,0x5a4(3); stw 0,-32768(4)"
extern "C" void f_80391868();
extern "C" void f_803917B4() {}
