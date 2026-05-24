// ASMPROC_replace_insn: match="li 3,-1" replacement="li 3,0"
// 0x80146A34 (104B) TileWalls::HasFenceNotWall(TileWallsSegment)
// ASMPROC replaces li r3,-1 → li r3,0 to match DOL's dual-block layout.

struct TileWalls {
    void HasFenceNotWall();
};

void TileWalls::HasFenceNotWall() {
}
