// 0x80388F1C __GXFifoReadDisable (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); li 0,0; lwz 3,0x8(4); rlwimi 3,0,0,31,31; stw 3,0x8(4); lwz 0,0x8(4); lwz 3,-21996(13); sth 0,0x2(3)"
extern "C" void f_80388F1C() {}
