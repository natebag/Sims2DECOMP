// 0x802C949C EMat4::GetColumn (40b)

struct EVec3 {
    float x, y, z;
};

struct EMat4 {
    float m[4][4];
    void GetColumn(int col, EVec3& out);
};

void EMat4::GetColumn(int col, EVec3& out) {
    out.x = m[0][col];
    out.y = m[1][col];
    out.z = m[2][col];
}
