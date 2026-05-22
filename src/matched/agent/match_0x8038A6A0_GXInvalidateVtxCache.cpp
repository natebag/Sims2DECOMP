// 0x8038A6A0 GXInvalidateVtxCache (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,72; lis 3,-13311; stb 0,-32768(3)"
extern "C" void f_8038A6A0() {}
