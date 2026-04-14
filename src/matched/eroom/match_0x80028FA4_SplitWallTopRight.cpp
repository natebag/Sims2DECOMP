/* SplitWallTopRight(TileWalls &, CTilePt &) at 0x80028FA4 (76B) */

struct TileWalls {
    int HasWallNotFence(int segment);
};

struct CTilePt;

int SplitWallTopRight(TileWalls *tw, CTilePt *pt) {
    tw->HasWallNotFence(2);
    int result = tw->HasWallNotFence(1);
    if (result != 0) {
        return 1;
    }
    return 0;
}
