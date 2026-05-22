// 0x8038F9AC GXSetZTexture (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,19; li 0,244; li 6,0; rlwimi 6,5,0,8,31; rlwimi 6,0,24,0,7; li 7,0; beq 2f; bge 0f; cmpwi 4,17; beq 1f; b 4f; 0:; cmpwi 4,22; beq 3f; b 4f; 1:; li 8,0; b 5f; 2:; li 8,1; b 5f; 3:; li 8,2; b 5f; 4:; li 8,2; 5:; li 0,97; lwz 4,-17720(13); lis 5,-13311; stb 0,-32768(5); rlwimi 7,8,0,30,31; rlwimi 7,3,2,28,29; stw 6,-32768(5); li 3,245; rlwimi 7,3,24,0,7; stb 0,-32768(5); li 0,0; stw 7,-32768(5); sth 0,0x2(4)"
extern "C" void f_8038F9AC() {}
