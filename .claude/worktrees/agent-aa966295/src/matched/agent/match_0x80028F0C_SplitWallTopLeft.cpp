/* SplitWallTopLeft(TileWalls &, CTilePt &) at 0x80028F0C (76B) */

struct CTilePt;

struct TileWalls {
    int HasWallNotFence(int) const;
};

int SplitWallTopLeft(TileWalls& tw, CTilePt&) {
    tw.HasWallNotFence(1);
    return tw.HasWallNotFence(2) != 0;
}
