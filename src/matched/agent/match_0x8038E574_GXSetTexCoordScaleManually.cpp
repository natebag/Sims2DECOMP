// 0x8038E574 GXSetTexCoordScaleManually (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 8,-17720(13); li 0,1; rlwinm 4,4,0,24,31; lwz 7,0x594(8); slw 0,0,3; andc 7,7,0; slw 0,4,3; or 0,7,0; stw 0,0x594(8); beqlr; rlwinm 0,3,2,0,29; add 7,8,0; addi 0,5,-1; lwz 3,0xb8(7); rlwimi 3,0,0,16,31; stw 3,0xb8(7); addi 0,6,-1; li 5,97; lwz 3,0xd8(7); rlwimi 3,0,0,16,31; lis 4,-13311; stw 3,0xd8(7); li 0,0; stb 5,-32768(4); lwz 3,0xb8(7); stw 3,-32768(4); stb 5,-32768(4); lwz 3,0xd8(7); stw 3,-32768(4); sth 0,0x2(8)"
extern "C" void f_8038E574() {}
