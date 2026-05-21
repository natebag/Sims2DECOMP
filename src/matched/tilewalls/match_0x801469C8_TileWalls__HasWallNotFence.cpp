// 0x801469C8 TileWalls::HasWallNotFence(TileWallsSegment) const (108B)
// TRIAGE
// TWIN of HasFenceNotWall — adds xori 1 inversion at end

class TileWalls {
public:
    unsigned int m_bits;

    int GetStyle(int seg) const;
    int HasWallNotFence(int seg) const;
};

int TileWalls::HasWallNotFence(int seg) const {
    int ret;
    int b = (int)(m_bits & seg);
    if (b != seg) goto fail;
    {
        int style = GetStyle(seg);
        int isFence;
        if (style == 2 || style == 12 || style == 13 || style == 14) {
            isFence = 1;
        } else {
            isFence = 0;
        }
        ret = isFence ^ 1;
        goto end;
    }
fail:
    ret = 0;
end:
    return ret;
}
