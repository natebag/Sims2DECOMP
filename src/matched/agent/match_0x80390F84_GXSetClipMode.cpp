// 0x80390F84 GXSetClipMode (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,16; lwz 4,-17720(13); lis 6,-13311; stb 0,-32768(6); li 5,4101; li 0,1; stw 5,-32768(6); stw 3,-32768(6); sth 0,0x2(4)"
extern "C" void f_80390F84() {}
