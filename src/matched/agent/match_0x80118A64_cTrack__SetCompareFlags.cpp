// 0x80118A64 cTrack::SetCompareFlags (44b)

struct cTrack {
    int field_3C;
    int field_40;
    int field_44;

    void SetCompareFlags(int, int);
};

void cTrack::SetCompareFlags(int a, int b) {
    int r0 = (a << 1) & 0xFFFFFFFE;
    int r9 = (b << 1) & 0xFFFFFFFE;
    int r11 = (b >> 8) & 0x7FFFFF;
    field_44 = r0;
    field_3C = r9;
    field_40 = r11;
}
