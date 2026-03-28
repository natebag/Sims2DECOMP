/* SplitWallBottomRight(TileWalls &, CTilePt &) at 0x80028EC0 (76B) */

struct CTilePt;

struct TileWalls {
    int HasWallNotFence(int) const;
};

int SplitWallBottomRight(TileWalls& tw, CTilePt&) {
    tw.HasWallNotFence(4);
    return tw.HasWallNotFence(2) != 0;
}
