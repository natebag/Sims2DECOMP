// 0x8026BC9C AptGetMouseOverSpriteName(char (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 9,-32704; lbz 0,0xb78(9); stb 0,0x0(3)"
extern "C" void f_8026BC9C() {}
