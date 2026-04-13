// FLAGS: -fno-elide-constructors
// 0x802C94F8 EMat4::SetColumn (40b)

struct EVec3 {
    float x, y, z;
};

struct EMat4 {
    float m[4][4];
    void SetColumn(int col, EVec3& in);
};

void EMat4::SetColumn(int col, EVec3& in) {
    m[0][col] = in.x;
    m[1][col] = in.y;
    m[2][col] = in.z;
}
