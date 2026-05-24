// 0x80146C44 TileWalls::GetPattern(TileWallsSegment, (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 31,5; mr 3,30; bl _s80146C44_0; mr 3,29; mr 4,30; bl _s80146C44_1; cmpwi 30,16; bne 0f; cmpwi 31,0; bne 0f; li 31,4; b 1f; 0:; cmpwi 30,32; bne 1f; cmpwi 31,0; bne 1f; li 31,1; 1:; mr 3,30; mr 4,31; bl _s80146C44_2; rlwinm 3,3,1,0,30; addi 9,29,20; lhzx 3,9,3; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s80146C44_0();
extern "C" void _s80146C44_1();
extern "C" void _s80146C44_2();

struct TileWalls {
    void GetPattern_TileWallsSegment();
};

void TileWalls::GetPattern_TileWallsSegment() {
}
