// 0x8014674C TileWalls::SegmentToIndex(TileWallsSegment, (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="xori 0,3,1; li 11,0; li 9,255; andi. 10,0,1; beq 1f; 0:; srawi 3,3,1; addi 11,11,1; xori 0,3,1; srawi 9,9,1; andi. 10,0,1; beq 1f; cmpwi 9,0; bne 0b; 1:; cmpwi 4,2; beq 5f; bgt 2f; cmpwi 4,0; beq 5f; cmpwi 4,1; beq 3f; b 5f; 2:; cmpwi 4,3; beq 4f; cmpwi 4,4; bne 5f; 3:; addi 11,11,1; b 5f; 4:; addi 11,11,2; 5:; mr 3,11"
extern "C" int f_8014674C() {}
