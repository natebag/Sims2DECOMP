// 0x80389DCC GXClearVtxDesc (56 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); li 5,0; li 0,1; stw 5,0x14(4); lwz 3,0x14(4); rlwimi 3,0,9,21,22; stw 3,0x14(4); stw 5,0x18(4); stb 5,0x4d4(4); stb 5,0x4d5(4); lwz 0,0x5ac(4); ori 0,0,8; stw 0,0x5ac(4)"
extern "C" void f_80389DCC() {}
