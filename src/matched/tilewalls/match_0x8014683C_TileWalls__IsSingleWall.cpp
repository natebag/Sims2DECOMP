// 0x8014683C TileWalls::IsSingleWall(TileWallsSegment) (68B)

class TileWalls {
public:
    static int IsSingleWall(int seg);
};

int TileWalls::IsSingleWall(int seg) {
    int count = 0;
    int s = seg;
    while (s != 0) {
        count++;
        s &= (s - 1);
    }
    int result = 0;
    if (count == 1) {
        result = (seg <= 32) ? 1 : 0;
    }
    return result;
}
