// 0x8038F7E4 GXSetTevKColorSel (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="srawi 5,3,1; lwz 6,-17720(13); rlwinm. 0,3,0,31,31; rlwinm 3,5,2,0,29; addi 7,3,432; add 7,6,7; beq 0f; lwz 0,0x0(7); rlwimi 0,4,14,13,17; stw 0,0x0(7); b 1f; 0:; lwz 0,0x0(7); rlwimi 0,4,4,23,27; stw 0,0x0(7); 1:; li 0,97; lwz 3,-17720(13); lis 5,-13311; stb 0,-32768(5); li 0,0; lwz 4,0x0(7); stw 4,-32768(5); sth 0,0x2(3)"
extern "C" void f_8038F7E4() {}
