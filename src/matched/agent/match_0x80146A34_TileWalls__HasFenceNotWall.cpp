// ASMPROC_replace_insn: match="li 3,-1" replacement="li 3,0"
// 0x80146A34 (104B) TileWalls::HasFenceNotWall(TileWallsSegment)
//
// Sentinel -1 at fail-exit prevents GCC merging the two return-0 paths.
// ASMPROC replaces li r3,-1 → li r3,0 to match DOL's dual-block layout.

class TileWalls {
public:
    unsigned int m_bits;
    int GetStyle(int seg) const;
    int HasFenceNotWall(int seg) const;
};

int TileWalls::HasFenceNotWall(int seg) const {
    int ret;
    int b = (int)(m_bits & seg);
    if (b != seg) goto fail;
    {
        int style = GetStyle(seg);
        if (style == 2 || style == 12 || style == 13 || style == 14) {
            ret = 1;
        } else {
            ret = 0;
        }
        goto end;
    }
fail:
    ret = -1;
end:
    return ret;
}
