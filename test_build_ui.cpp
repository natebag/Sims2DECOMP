// FLAGS: -fno-schedule-insns

struct TileWalls {
    int flags;
    int HasWall(int segment) const;
};

int TileWalls::HasWall(int segment) const {
    int result = 0;
    if ((this->flags & segment) != segment) result = 1;
    return result;
}
