// 0x8038BCA8 GXSetTexCopySrc (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); li 9,0; rlwinm 7,5,0,16,31; stw 9,0x1f0(8); rlwinm 5,6,0,16,31; rlwinm 0,3,0,16,31; lwz 3,0x1f0(8); rlwimi 3,0,0,22,31; rlwinm 0,4,0,16,31; stw 3,0x1f0(8); li 6,73; addi 4,7,-1; lwz 7,0x1f0(8); rlwimi 7,0,10,12,21; addi 3,5,-1; stw 7,0x1f0(8); li 0,74; lwz 5,0x1f0(8); rlwimi 5,6,24,0,7; stw 5,0x1f0(8); stw 9,0x1f4(8); lwz 5,0x1f4(8); rlwimi 5,4,0,22,31; stw 5,0x1f4(8); lwz 4,0x1f4(8); rlwimi 4,3,10,12,21; stw 4,0x1f4(8); lwz 3,0x1f4(8); rlwimi 3,0,24,0,7; stw 3,0x1f4(8)"
extern "C" void f_8038BCA8() {}
