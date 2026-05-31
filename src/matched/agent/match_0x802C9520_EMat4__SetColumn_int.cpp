// 0x802C9520 EMat4::SetColumn(int, const EVec4*) (52 B)

struct EVec4 {
    float x, y, z, w;
};

struct EMat4 {
    float m[4][4];

    void SetColumn(int col, const EVec4* in);
};

void EMat4::SetColumn(int col, const EVec4* in) {
    m[0][col] = in->x;
    m[1][col] = in->y;
    m[2][col] = in->z;
    m[3][col] = in->w;
}
