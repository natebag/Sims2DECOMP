/* SplitWallTopRight(TileWalls &, CTilePt &) at 0x80028FA4 (76B) */

struct CTilePt;

struct TileWalls {
    int HasWallNotFence(int) const;
};

int SplitWallTopRight(TileWalls& tw, CTilePt&) {
    tw.HasWallNotFence(2);
    return tw.HasWallNotFence(1) != 0;
}
