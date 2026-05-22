// 0x80137B58 IsScoredStyle(WallStyle) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 9,0; cmpwi 3,1; beq 0f; cmpwi 3,7; beq 0f; cmpwi 3,8; beq 0f; cmpwi 3,9; bne 1f; 0:; li 0,1; b 2f; 1:; li 0,0; 2:; cmpwi 0,0; bne 6f; cmpwi 3,3; beq 3f; cmpwi 3,5; beq 3f; cmpwi 3,6; beq 3f; cmpwi 3,15; beq 3f; cmpwi 3,23; bne 4f; 3:; li 0,1; b 5f; 4:; li 0,0; 5:; cmpwi 0,0; bne 6f; cmpwi 3,22; bne 7f; 6:; li 9,1; 7:; mr 3,9"
extern "C" int f_80137B58() {}
