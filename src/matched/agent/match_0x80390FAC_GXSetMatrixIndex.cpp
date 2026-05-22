// 0x80390FAC __GXSetMatrixIndex (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,5; bge 0f; li 0,8; lwz 4,-17720(13); lis 5,-13311; stb 0,-32768(5); li 0,48; li 3,16; stb 0,-32768(5); li 0,4120; lwz 4,0x80(4); stw 4,-32768(5); stb 3,-32768(5); stw 0,-32768(5); stw 4,-32768(5); b 1f; 0:; li 0,8; lwz 4,-17720(13); lis 5,-13311; stb 0,-32768(5); li 0,64; li 3,16; stb 0,-32768(5); li 0,4121; lwz 4,0x84(4); stw 4,-32768(5); stb 3,-32768(5); stw 0,-32768(5); stw 4,-32768(5); 1:; lwz 3,-17720(13); li 0,1; sth 0,0x2(3)"
extern "C" void f_80390FAC() {}
