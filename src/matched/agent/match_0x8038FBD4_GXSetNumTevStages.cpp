// 0x8038FBD4 GXSetNumTevStages (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 4,-17720(13); rlwinm 3,3,0,24,31; addi 0,3,-1; lwz 3,0x204(4); rlwimi 3,0,10,18,21; stw 3,0x204(4); lwz 0,0x5ac(4); ori 0,0,4; stw 0,0x5ac(4)"
extern "C" void f_8038FBD4() {}
