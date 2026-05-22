// 0x8038BEAC GXSetCopyClamp (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 5,3,0,31,31; lwz 4,-17720(13); addi 0,5,-1; cntlzw 5,0; lwz 0,0x1ec(4); rlwinm 5,5,27,24,31; rlwinm 3,3,0,30,30; rlwimi 0,5,0,31,31; addi 3,3,-2; stw 0,0x1ec(4); cntlzw 0,3; rlwinm 3,0,27,24,31; lwz 0,0x1ec(4); rlwimi 0,3,1,30,30; stw 0,0x1ec(4); lwz 0,0x1fc(4); rlwimi 0,5,0,31,31; stw 0,0x1fc(4); lwz 0,0x1fc(4); rlwimi 0,3,1,30,30; stw 0,0x1fc(4)"
extern "C" void f_8038BEAC() {}
