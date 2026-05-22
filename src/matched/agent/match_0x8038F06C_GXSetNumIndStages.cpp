// 0x8038F06C GXSetNumIndStages (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); rlwinm 0,3,0,24,31; lwz 3,0x204(4); rlwimi 3,0,16,13,15; stw 3,0x204(4); lwz 0,0x5ac(4); ori 0,0,6; stw 0,0x5ac(4)"
extern "C" void f_8038F06C() {}
