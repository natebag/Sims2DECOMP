// 0x802F24A4 EMirrorPortal::GetCorner (40b)
// FLAGS: -fno-elide-constructors

struct EVec3 {
    float x, y, z;
};

struct EMirrorPortal {
    EVec3* m_corners;
    EVec3 GetCorner(int index);
};

EVec3 EMirrorPortal::GetCorner(int index) {
    EVec3 result;
    EVec3* c = &m_corners[index];
    result.x = c->x;
    result.y = c->y;
    result.z = c->z;
    return result;
}
