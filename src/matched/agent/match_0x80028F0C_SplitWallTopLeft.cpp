/* SplitWallTopLeft(TileWalls &, CTilePt &) at 0x80028F0C (76B) */

struct TileWalls {
    int HasWallNotFence(int segment);
};

struct CTilePt;

int SplitWallTopLeft(TileWalls *tw, CTilePt *pt) {
    tw->HasWallNotFence(1);
    int result = tw->HasWallNotFence(2);
    if (result != 0) {
        return 1;
    }
    return 0;
}
