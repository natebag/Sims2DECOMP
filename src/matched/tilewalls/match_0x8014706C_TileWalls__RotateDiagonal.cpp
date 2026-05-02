// 0x8014706C TileWalls::RotateDiagonal(DiagonalSideSelector, int) (28B)

extern int g_RotateDiagonalLookup[][5];

struct TileWalls {
    static int RotateDiagonal(int segment, int rotation);
};

int TileWalls::RotateDiagonal(int segment, int rotation) {
    return g_RotateDiagonalLookup[rotation][segment];
}
