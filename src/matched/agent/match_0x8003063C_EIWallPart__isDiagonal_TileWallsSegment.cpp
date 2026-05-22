// 0x8003063C EIWallPart::isDiagonal(TileWallsSegment) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,1; andi. 9,3,48; bne 0f; li 0,0; 0:; mr 3,0"
extern "C" int f_8003063C() {}
