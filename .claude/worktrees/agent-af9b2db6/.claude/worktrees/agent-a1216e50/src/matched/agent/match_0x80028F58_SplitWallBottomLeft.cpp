/* SplitWallBottomLeft(TileWalls &, CTilePt &) at 0x80028F58 (76B) */

struct CTilePt;

struct TileWalls {
    int HasWallNotFence(int) const;
};

int SplitWallBottomLeft(TileWalls& tw, CTilePt&) {
    tw.HasWallNotFence(8);
    return tw.HasWallNotFence(1) != 0;
}
