// 0x802C94C4 EMat4::GetColumn(int, EVec4*) (52 B)

struct EVec4 {
    float x, y, z, w;
};

struct EMat4 {
    float m[4][4];

    void GetColumn(int col, EVec4* out);
};

void EMat4::GetColumn(int col, EVec4* out) {
    out->x = m[0][col];
    out->y = m[1][col];
    out->z = m[2][col];
    out->w = m[3][col];
}
