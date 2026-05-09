// 0x802F24A4 EMirrorPortal::GetCorner (40b)
// FLAGS: -fno-elide-constructors
// EVec3 needs explicit copy ctor; m_corners inline array at offset 4.

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct EMirrorPortal {
    char _pad[4];
    EVec3 m_corners[8];
    EVec3 GetCorner(int index);
};

EVec3 EMirrorPortal::GetCorner(int index) {
    return m_corners[index];
}
