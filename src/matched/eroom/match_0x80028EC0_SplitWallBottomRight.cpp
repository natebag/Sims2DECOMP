/* SplitWallBottomRight(TileWalls &, CTilePt &) at 0x80028EC0 (76B) */

struct TileWalls {
    int HasWallNotFence(int segment);
};

struct CTilePt;

int SplitWallBottomRight(TileWalls *tw, CTilePt *pt) {
    tw->HasWallNotFence(4);
    int result = tw->HasWallNotFence(2);
    if (result != 0) {
        return 1;
    }
    return 0;
}
