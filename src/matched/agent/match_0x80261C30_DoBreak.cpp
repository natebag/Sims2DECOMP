// 0x80261C30 DoBreak (28 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-13312; lwz 4,0x6000(3); li 0,1; ori 4,4,65; stw 4,0x6000(3); stw 0,-23328(13)"
extern "C" void f_80261C30() {}
