/* SplitWallBottomLeft(TileWalls &, CTilePt &) at 0x80028F58 (76B) */

struct TileWalls {
    int HasWallNotFence(int segment);
};

struct CTilePt;

int SplitWallBottomLeft(TileWalls *tw, CTilePt *pt) {
    tw->HasWallNotFence(8);
    int result = tw->HasWallNotFence(1);
    if (result != 0) {
        return 1;
    }
    return 0;
}
